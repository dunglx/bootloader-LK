/* Copyright (c) 2011, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <certificate.h>

const char certBuffer[CERTIFICATE_SIZE] = {
0x30,0x82,0x03,0x86,0x30,0x82,0x02,0x6E,0x02,0x09,0x00,0xB4,0x32,0x7B,0x03,0x0E,
0xA1,0x42,0x09,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,
0x05,0x00,0x30,0x81,0x84,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,
0x56,0x4E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x08,0x0C,0x02,0x48,0x4E,0x31,
0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x07,0x0C,0x02,0x48,0x4E,0x31,0x19,0x30,0x17,
0x06,0x03,0x55,0x04,0x0A,0x0C,0x10,0x42,0x6B,0x61,0x76,0x20,0x43,0x6F,0x72,0x70,
0x6F,0x72,0x61,0x74,0x69,0x6F,0x6E,0x31,0x0F,0x30,0x0D,0x06,0x03,0x55,0x04,0x0B,
0x0C,0x06,0x4D,0x6F,0x62,0x69,0x6C,0x65,0x31,0x0F,0x30,0x0D,0x06,0x03,0x55,0x04,
0x03,0x0C,0x06,0x42,0x70,0x68,0x6F,0x6E,0x65,0x31,0x1E,0x30,0x1C,0x06,0x09,0x2A,
0x86,0x48,0x86,0xF7,0x0D,0x01,0x09,0x01,0x16,0x0F,0x62,0x70,0x68,0x6F,0x6E,0x65,
0x40,0x62,0x6B,0x61,0x76,0x2E,0x63,0x6F,0x6D,0x30,0x1E,0x17,0x0D,0x31,0x35,0x30,
0x36,0x32,0x36,0x31,0x37,0x33,0x30,0x34,0x34,0x5A,0x17,0x0D,0x31,0x36,0x30,0x36,
0x32,0x35,0x31,0x37,0x33,0x30,0x34,0x34,0x5A,0x30,0x81,0x84,0x31,0x0B,0x30,0x09,
0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x56,0x4E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,
0x04,0x08,0x0C,0x02,0x48,0x4E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x07,0x0C,
0x02,0x48,0x4E,0x31,0x19,0x30,0x17,0x06,0x03,0x55,0x04,0x0A,0x0C,0x10,0x42,0x6B,
0x61,0x76,0x20,0x43,0x6F,0x72,0x70,0x6F,0x72,0x61,0x74,0x69,0x6F,0x6E,0x31,0x0F,
0x30,0x0D,0x06,0x03,0x55,0x04,0x0B,0x0C,0x06,0x4D,0x6F,0x62,0x69,0x6C,0x65,0x31,
0x0F,0x30,0x0D,0x06,0x03,0x55,0x04,0x03,0x0C,0x06,0x42,0x70,0x68,0x6F,0x6E,0x65,
0x31,0x1E,0x30,0x1C,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x09,0x01,0x16,
0x0F,0x62,0x70,0x68,0x6F,0x6E,0x65,0x40,0x62,0x6B,0x61,0x76,0x2E,0x63,0x6F,0x6D,
0x30,0x82,0x01,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,
0x01,0x05,0x00,0x03,0x82,0x01,0x0F,0x00,0x30,0x82,0x01,0x0A,0x02,0x82,0x01,0x01,
0x00,0xCF,0x5B,0x2C,0xBA,0x8C,0x03,0xEB,0xA1,0x00,0x6C,0x2B,0x2D,0xB4,0x63,0x9B,
0x44,0xE2,0xED,0x0C,0xB0,0xC7,0x15,0x09,0x5E,0x7A,0x89,0x7A,0xFE,0x13,0x8C,0xF8,
0x58,0x92,0x24,0x79,0x0F,0x86,0x97,0xE6,0x5E,0x85,0xEC,0x0D,0x22,0x12,0x22,0x40,
0xB2,0x08,0x51,0x53,0x3C,0x25,0xA1,0x18,0x22,0xB9,0xA7,0xEF,0x28,0xAC,0x25,0x3C,
0xB3,0xE5,0x70,0xCF,0xE4,0x3F,0x95,0xD6,0xC2,0x3C,0x53,0x56,0x50,0xCA,0x03,0xC3,
0xDA,0xAE,0xCE,0x3C,0x8D,0x42,0x55,0xEB,0xB3,0x04,0x9C,0x81,0xD5,0x5C,0x13,0x73,
0xEC,0xCC,0xE2,0x4F,0xF9,0xE9,0xB7,0x07,0x19,0x08,0x93,0xDD,0x44,0x11,0x90,0xDD,
0xC1,0x81,0x25,0x52,0x71,0x4B,0xB1,0xF4,0x15,0x9B,0x87,0xFB,0x03,0xE8,0x88,0x38,
0x5D,0x6D,0x4F,0x54,0x22,0x6D,0x6B,0xBB,0x08,0xB9,0xE0,0x77,0xCD,0xEB,0x6E,0x6C,
0x96,0x65,0x1C,0xBA,0x90,0x50,0xA3,0x52,0xD0,0x9C,0x3F,0xFB,0x42,0xC5,0xBE,0x2A,
0xCD,0x12,0x0E,0x24,0x23,0x9D,0x35,0xBD,0xA9,0xD3,0xEA,0x83,0x43,0x6A,0x4D,0x1C,
0xCB,0x66,0x39,0x9D,0xF4,0x61,0xF9,0x27,0x9A,0xD4,0x41,0x57,0x66,0x6B,0x47,0x15,
0xE2,0x5E,0xAB,0x22,0x27,0x9D,0x2D,0xC8,0x29,0x49,0x5B,0xF2,0xEB,0x1C,0x89,0x0D,
0x79,0x06,0xE8,0xB4,0xD2,0xBD,0xC9,0xF2,0x27,0xCD,0x4A,0x2A,0x42,0x59,0x2D,0x34,
0x28,0x90,0xFF,0xA0,0x5C,0x95,0x7D,0xA6,0x28,0xC7,0x67,0x20,0x54,0x3D,0xA6,0x25,
0xD3,0xCB,0xFB,0xD0,0x14,0x45,0x51,0xCF,0x62,0x4D,0xA0,0xF4,0x5A,0xFB,0xC4,0x22,
0xBB,0x02,0x03,0x01,0x00,0x01,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,
0x01,0x01,0x0B,0x05,0x00,0x03,0x82,0x01,0x01,0x00,0xB3,0xCA,0xB6,0x0D,0xC8,0x3E,
0x3D,0x66,0x4B,0x24,0xA4,0x75,0xF0,0x63,0x20,0xE3,0x7E,0x74,0xCE,0xDA,0x8B,0x35,
0x33,0x7D,0x1E,0x92,0x79,0x46,0x51,0xB9,0x11,0x01,0x35,0x16,0x3B,0xBD,0xA8,0xBE,
0x75,0x15,0xCA,0xA9,0x9E,0x27,0xFF,0x89,0x7A,0xAE,0xC8,0x4A,0x16,0x95,0xEF,0xB6,
0x9D,0x47,0xF7,0x2F,0x2E,0xAC,0x50,0xB4,0x83,0x7F,0x2A,0xA1,0xF6,0xBD,0x68,0x55,
0xE6,0x6C,0x0B,0x83,0x74,0x5E,0xAC,0xDB,0x19,0x9D,0x16,0x15,0xCA,0x3A,0x09,0x2C,
0x6E,0x37,0x97,0xDC,0x33,0xB4,0x61,0xAC,0x54,0xF4,0x2D,0x78,0xD9,0xD4,0xB3,0xD9,
0x76,0x55,0x24,0x4B,0x47,0x67,0x4F,0x68,0x46,0x55,0xD7,0x27,0xF8,0x39,0xCF,0x32,
0x9B,0x45,0xE3,0x27,0x1C,0x15,0x35,0xDC,0x10,0x91,0x69,0x02,0xE8,0x35,0xF1,0x1B,
0x35,0x08,0x96,0xE1,0xE1,0x70,0x52,0x38,0x20,0xD7,0x16,0xB9,0x02,0xDE,0x7B,0xF3,
0xBD,0xE7,0x79,0xF5,0xD6,0xF1,0x67,0x77,0x5C,0xF1,0xFD,0x00,0xE9,0x6B,0x59,0xE0,
0x0B,0x41,0x1D,0x4B,0x8E,0x87,0x78,0xE3,0x15,0xCC,0x78,0x3F,0xFB,0xE6,0x96,0x2B,
0x6A,0x3D,0x02,0x8C,0x2C,0x1D,0x71,0x1B,0x32,0x3E,0xBA,0x1D,0xDD,0xC7,0x16,0xD2,
0x30,0xA6,0x34,0x54,0x61,0xD1,0x50,0x13,0x3F,0x98,0x27,0x08,0xC7,0x88,0x31,0xE4,
0xDC,0x93,0xFF,0xF4,0x0D,0x38,0x8D,0x9E,0x6F,0x20,0x63,0xD7,0xF1,0xD7,0x94,0x8B,
0xA5,0xF7,0x16,0xAE,0x72,0xCE,0xDE,0xE9,0x02,0xCF,0xA0,0x0F,0x9D,0xBE,0xE3,0xA2,
0xA8,0x2F,0xCE,0x13,0xDB,0x6E,0xB5,0xDC,0xA2,0x06,
};
