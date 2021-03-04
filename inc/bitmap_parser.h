#ifndef BITMAP_PARSER_H
#define BITMAP_PARSER_H

#include "stdint.h"
#include "stdio.h"
#include "parser_fh.h"
#include "parser_bh.h"

#define BITMAP_OK               0
#define BITMAP_NULLPTR          1
#define BITMAP_READH_ERR        2
#define BITMAP_READD_ERR        4
#define BITMAP_MEM_ERR          8
#define BITMAP_FH_MASK          0x0000FF00
#define BITMAP_FH_SHIFT         8
#define BITMAP_BH_MASK          0x00FF0000
#define BITMAP_BH_SHIFT         16

typedef struct bitmap_t
{
    fh_data_t file_header;
    bh_data_t bitmap_header;
    uint8_t *bitmap_data;
} bitmap_t;

typedef bitmap_t* bitmap_handle_t;

int32_t bitmap_parse_headers(bitmap_handle_t handle, uint8_t *data);
int32_t bitmap_parse_file(bitmap_handle_t handle, FILE *f_bitmap);
int32_t bitmap_save_as_array(bitmap_handle_t handle, FILE *f_out);

#endif /* BITMAP_PARSER_H */

