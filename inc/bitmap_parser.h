#ifndef BITMAP_PARSER_H
#define BITMAP_PARSER_H

#include "stdint.h"
#include "parser_fh.h"
#include "parser_bh.h"

#define BITMAP_OK           0
#define BITMAP_NULLPTR      1

typedef struct bitmap_t
{
    fh_data_t file_header;
    bh_data_t bitmap_header;
    uint8_t *bitmap_data;
} bitmap_t;

typedef bitmap_t* bitmap_handle_t;

int32_t bitmap_parse_headers(bitmap_handle_t handle, uint8_t *data);

#endif /* BITMAP_PARSER_H */

