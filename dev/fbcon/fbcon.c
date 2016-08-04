/*
 * Copyright (c) 2008, Google Inc.
 * All rights reserved.
 *
 * Copyright (c) 2009-2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the 
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <debug.h>
#include <err.h>
#include <stdlib.h>
#include <dev/fbcon.h>
#include <splash.h>
#include <platform.h>
#include <string.h>

#include <pm8x41_adc.h>

static struct fbcon_config *config = NULL;

#define RGB888_BLACK	0x000000
#define RGB888_WHITE	0xffffff

static uint16_t			BGCOLOR;
static uint16_t			FGCOLOR;
extern bool boot_into_fastboot;

static void fbcon_flush(void)
{
	if (config->update_start)
		config->update_start();
	if (config->update_done)
		while (!config->update_done());
}

/* TODO: take stride into account */
void fbcon_clear(void)
{
	unsigned count = config->width * config->height;
	memset(config->base, BGCOLOR, count * ((config->bpp) / 8));
}

static void fbcon_set_colors(unsigned bg, unsigned fg)
{
	BGCOLOR = bg;
	FGCOLOR = fg;
}

void fbcon_setup(struct fbcon_config *_config)
{
	uint32_t bg;
	uint32_t fg;

	ASSERT(_config);

	config = _config;

	switch (config->format) {
		case FB_FORMAT_RGB888:
			fg = RGB888_WHITE;
			bg = RGB888_BLACK;
			break;
		default:
			dprintf(CRITICAL, "unknown framebuffer pixel format\n");
			ASSERT(0);
			break;
	}

	fbcon_set_colors(bg, fg);

#if !DISPLAY_SPLASH_SCREEN
	fbcon_clear();
#endif
}

struct fbcon_config* fbcon_display(void)
{
    return config;
}

void fbcon_putImage_offset(struct fbimage *fbimg, unsigned int offset);

void display_image_on_screen()
{
	struct fbimage default_fbimg;
	struct fbimage *fbimg;
	bool flag = true;

	uint32_t bat_vol;

	fbcon_clear();
	flag = false;
	fbimg = &default_fbimg;

	bat_vol = pm8x41_get_batt_voltage_fixed();

	if(bat_vol < 3600000)
	{
		fbimg->header.width = SPLASH_IMAGE_BAT_HEIGHT;
		fbimg->header.height = SPLASH_IMAGE_BAT_WIDTH;
		fbimg->image = (unsigned char *)splash_image_bat_buffer;
		fbcon_putImage_offset(fbimg, config->height/2 - SPLASH_IMAGE_BAT_WIDTH/2);

		if(bat_vol < 3600000)
		{
			fbimg->header.width = SPLASH_IMAGE_MSG1_HEIGHT;
			fbimg->header.height = SPLASH_IMAGE_MSG1_WIDTH;
			fbimg->image = (unsigned char *)splash_image_msg1_buffer;
			fbcon_putImage_offset(fbimg, config->height/2 - SPLASH_IMAGE_BAT_WIDTH/2 - 120);

			fbimg->header.width = SPLASH_IMAGE_MSG2_HEIGHT;
			fbimg->header.height = SPLASH_IMAGE_MSG2_WIDTH;
			fbimg->image = (unsigned char *)splash_image_msg2_buffer;
			fbcon_putImage_offset(fbimg, config->height/2 -
					SPLASH_IMAGE_BAT_WIDTH/2 - SPLASH_IMAGE_MSG1_WIDTH - 130);
		}
	}
	else
	{
		fbimg->header.width = SPLASH_IMAGE_LOGO_HEIGHT;
		fbimg->header.height = SPLASH_IMAGE_LOGO_WIDTH;
		fbimg->image = (unsigned char *)splash_image_logo_buffer;
		fbcon_putImage_offset(fbimg, config->height/2 - SPLASH_IMAGE_LOGO_WIDTH/2);
		if (!boot_into_fastboot) 
		{
			fbimg->header.width = SPLASH_IMAGE_ANDROID_HEIGHT;
			fbimg->header.height = SPLASH_IMAGE_ANDROID_WIDTH;
			fbimg->image = (unsigned char *)splash_image_android_buffer;
			fbcon_putImage_offset(fbimg, 80);
		}
	}
}

//DATVTB
void fbcon_putImage_offset(struct fbimage *fbimg, unsigned int offset)
{
    unsigned total_x;
    unsigned total_y;
    bool enable = true;
    unsigned image_base;
    unsigned width, pitch, height;
    unsigned char *logo_base;
    struct logo_img_header *header;

	if (!config) {
		dprintf(CRITICAL,"NULL configuration, image cannot be displayed\n");
		return;
	}

	if(fbimg) {
		header = &fbimg->header;
		width = pitch = header->width;
		height = header->height;
		logo_base = (unsigned char *)fbimg->image;
	}

	total_x = config->width;
	total_y = config->height;

#if DISPLAY_TYPE_MIPI
	if(enable)
	{
		char * d, *s;
		int len, i;

		image_base = (total_y - height - offset) * config->width + total_x/2 - width/2;

		for(i = 0; i < height; i++)
		{
			d = (char *)(config->base + ((image_base + (i * (config->width))) * 3));
			s = (char *)(logo_base + (i * pitch));

			for(len = width; len > 0; len--)
			{
				*d++ = *s;
				*d++ = *s;
				*d++ = *s++;
			}
		}
	}

	fbcon_flush();
#endif
}
