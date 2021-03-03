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


#define N_COLOR_PLANES      1


static int32_t parse_header_size(bh_handle_t handle, uint8_t *data);
static int32_t parse_n_color_planes(bh_handle_t handle, uint8_t *data);
static int32_t parse_other_data(bh_handle_t handle, uint8_t *data);

int32_t bh_parse(bh_handle_t handle, uint8_t *data)
{
    if (NULL == handle || NULL == data)
    {
        return BH_NULLPTR;
    }
    return parse_header_size(handle, data)
            | parse_n_color_planes(handle, data)
            | parse_other_data(handle, data);
}

static int32_t parse_header_size(bh_handle_t handle, uint8_t *data)
{
    uint32_t header_size = cast_32(&data[0]);
    if (BH_SIZE == header_size)
    {
        handle->header_size = header_size;
        return BH_OK;
    }
    else
    {
        return BH_HSIZE_ERR;
    }
}

static int32_t parse_n_color_planes(bh_handle_t handle, uint8_t *data)
{
    uint16_t n_color_planes = cast_16(&data[12]);
    if (N_COLOR_PLANES == n_color_planes)
    {
        handle->n_color_planes = n_color_planes;
        return BH_OK;
    }
    else
    {
        return BH_NCP_ERR;
    }
}

static int32_t parse_other_data(bh_handle_t handle, uint8_t *data)
{
    handle->img_width = cast_i32(&data[4]);
    handle->img_height = cast_i32(&data[8]);
    handle->n_bits_per_pixel = cast_16(&data[14]);
    handle->compression = cast_32(&data[16]);
    handle->bitmap_size = cast_32(&data[20]);
    handle->ppm_hor = cast_i32(&data[24]);
    handle->ppm_ver = cast_i32(&data[28]);
    handle->n_colors_in_palette = cast_32(&data[32]);
    handle->n_important_colors = cast_32(&data[36]);
    return BH_OK;
}

