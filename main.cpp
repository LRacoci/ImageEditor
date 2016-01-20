/*
LodePNG Examples

Copyright (c) 2005-2010 Lode Vandevenne

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.
*/

/*
LodePNG decode-encode: decodes the image, then encodes it again, with all the
same information, chunks, color types, etc... as the original image had.
This sample shows how LodePNG can be used for a conforming PNG editor.
*/

// g++ lodepng.cpp example_reencode.cpp -ansi -pedantic -Wall -Wextra -lSDL -O3
// -o reencode

#include "lodepng.h"
#include "RGBA.h"
#include <iostream>

using namespace std;
vector<RGBA> read_raw(
        vector<unsigned char> raw_image,
        unsigned w,
        unsigned h
) {
    unsigned x;
    vector<RGBA> image = vector<RGBA>(w*h) ;
    for (x = 0; x < h * w; x += 4) {
        image[x] = RGBA(
            raw_image[x],
            raw_image[x + 1],
            raw_image[x + 2],
            raw_image[x + 3]
        );
    }
    return image;
}
vector<unsigned char> write_raw(
        vector<RGBA> image,
        unsigned w,
        unsigned h
) {
    unsigned x;
    vector<unsigned char> raw_image;
    for (x = 0; x < h * w; x += 4) {
        raw_image[  x  ] = image[x].red;
        raw_image[x + 1] = image[x].green;
        raw_image[x + 2] = image[x].blue;
        raw_image[x + 3] = image[x].alpha;
    }
    return raw_image;
}

void modify_image(
        vector<unsigned char> raw_image,
        unsigned &w,
        unsigned &h
) {
    vector<RGBA> image = read_raw(raw_image, w, h);
    raw_image = write_raw(image, w, h);
}

int main(int argc, char *argv[]) {
    vector<unsigned char> image;
    unsigned w, h;
    vector<unsigned char> buffer;
    lodepng::State state;
    unsigned error;

    // check if user gave a filename
    if (argc < 3) {
        cout << "please provide in and out filename" << endl;
        return 0;
    }

    state.decoder.color_convert = 0;
    // make it reproduce even unknown chunks in the saved image
    state.decoder.remember_unknown_chunks = 1;
    lodepng::load_file(buffer, argv[1]);
    error = lodepng::decode(image, w, h, state, buffer);
    if (error) {
        cout << "decoder error " << error << ": " << lodepng_error_text(error) << endl;
        return 0;
    }

    modify_image(image, w, h);

    buffer.clear();

    state.encoder.text_compression = 1;

    error = lodepng::encode(buffer, image, w, h, state);
    if (error) {
        cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;
        return 0;
    }

    lodepng::save_file(buffer, argv[2]);
}
