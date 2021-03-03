#include "parser_bh.h"
#include "stddef.h"
#include "utils.h"

// Structure of proper bitmap header
// [3][2][1][0]     -> size of header in bytes (40 = 0x00000028)
// [7][6][5][4]     -> image width in pixels
// [11][10][9][8]   -> image height in pixels
// [13][12]         -> number of color planes (1)
// [15][14]         -> number of bits per pixel (1*, 4*, 8*, 16*, 24*, 32)
// [19][18][17][16] -> compression
// [23][22][21][20] -> size of bitmap in bytes (can be 0 for compression 0)
// [27][26][25][24]@-> pixel per metre horizontal, optional
// [31][30][29][28]@-> pixel per metre vertical, optional
// [35][34][33][32]@-> number of colors in palette, (0 for default 2^n)
// [39][38][37][36]@-> number of important colors, (0 for equal importance)
//
// * - for now not supported
// @ - parsed but ignored

int32_t bh_parse(bh_handle_t handle, uint8_t *data)
{
    if (handle == NULL || data == NULL)
    {
        return BH_NULLPTR;
    }
    return BH_OK;
}

