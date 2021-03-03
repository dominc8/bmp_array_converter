#ifndef PARSER_BH_H
#define PARSER_BH_H

#include "stdint.h"

#define BH_OK               0
#define BH_NULLPTR          1

#define BH_SIZE             40

typedef struct bh_data_t
{
    uint16_t type;
} bh_data_t;

typedef bh_data_t* bh_handle_t;

int32_t bh_parse(bh_handle_t handle, uint8_t *data);

#endif /* PARSER_BH_H */

