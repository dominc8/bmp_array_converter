#ifndef PARSER_FH_H
#define PARSER_FH_H

#include "stdint.h"

#define FH_OK               0
#define FH_NULLPTR          1
#define FH_TYPE_ERR         2
#define FH_SIZE_ERR         4
#define FH_OFFSET_ERR       8

#define FH_SIZE             14

typedef struct fh_data_t
{
    uint16_t type;
    uint32_t size_of_file;
    uint16_t reserved_1;
    uint16_t reserved_2;
    uint32_t bitmap_offset;
} fh_data_t;

typedef fh_data_t* fh_handle_t;

int32_t fh_parse(fh_handle_t handle, uint8_t *data);

#endif /* PARSER_FH_H */

