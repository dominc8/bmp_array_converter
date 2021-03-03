#ifndef BITMAP_PARSER_H
#define BITMAP_PARSER_H

#include "stdint.h"
#include "parser_fh.h"
#include "parser_bh.h"

#define BITMAP_OK           0
#define BITMAP_NULLPTR      1
#define BITMAP_FH_MASK      0x0000FF00
#define BITMAP_FH_SHIFT     8
#define BITMAP_BH_MASK      0x00FF0000
#define BITMAP_BH_SHIFT     16

typedef struct bitmap_t
{
    fh_data_t file_header;
    bh_data_t bitmap_header;
    uint8_t *bitmap_data;
} bitmap_t;

typedef bitmap_t* bitmap_handle_t;

int32_t bitmap_parse_headers(bitmap_handle_t handle, uint8_t *data);

#endif /* BITMAP_PARSER_H */

