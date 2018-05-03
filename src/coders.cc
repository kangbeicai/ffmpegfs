/*
 * Encoder and Decoder class source for ffmpegfs
 *
 * Copyright (C) 2013 K. Henriksson
 * Copyright (C) 2017-2018 FFmpeg support by Norbert Schlia (nschlia@oblivion-software.de)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "coders.h"

#include <string.h>

/* Define list of available encoder extensions. */
const char* encoder_list[] =
{
    "mp3",  // TYPE_MP3
    "mp4",  // TYPE_MP4
    "wav",  // TYPE_WAV
    "ogg",  // TYPE_OGG
    NULL
};

/* Define list of available decoder extensions. */
const char* decoder_list[] =
{
    "avi",
    "flac",
    "ogg",
    "oga",
    "ogv",
    "mp4",
    "m4a",
    "m4v",
    "mp3",
    "webm",
    "flv",
    "mpg",
    "ts",
    "mov",
    "m2ts",
    "mkv",
    "vob",
    "wma",
    "wmv",
    "rm",
    NULL
};

/* Use "C" linkage to allow access from C code. */
extern "C" {

/* Check if an encoder is available to encode to the specified type. */
int check_encoder(const char* type)
{
    int found = 0;

    for (int n = 0; encoder_list[n]; n++)
    {
        if (!strcasecmp(type, encoder_list[n]))
        {
            found = -1;
            break;
        }
    }
    return found;
}

/* Check if a decoder is available to decode from the specified type. */
int check_decoder(const char* type)
{
    int found = 0;

    for (int n = 0; decoder_list[n]; n++)
    {
        if (!strcasecmp(type, decoder_list[n]))
        {
            found = -1;
            break;
        }
    }
    return found;
}

}
