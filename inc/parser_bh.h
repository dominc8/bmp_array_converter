#ifndef PARSER_BH_H
#define PARSER_BH_H

#include "stdint.h"

#define BH_OK               0
#define BH_NULLPTR          1
#define BH_HSIZE_ERR        2
#define BH_NCP_ERR          4

#define BH_SIZE             40

typedef struct bh_data_t
{
    uint32_t header_size;
    int32_t img_width;
    int32_t img_height;
    uint16_t n_color_planes;
    uint16_t n_bits_per_pixel;
    uint32_t compression;
    uint32_t bitmap_size;
    int32_t ppm_hor;
    int32_t ppm_ver;
    uint32_t n_colors_in_palette;
    uint32_t n_important_colors;
} bh_data_t;

typedef bh_data_t* bh_handle_t;

int32_t bh_parse(bh_handle_t handle, uint8_t *data);

#endif /* PARSER_BH_H */

