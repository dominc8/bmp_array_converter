#include "parser_fh.h"
#include "stddef.h"

// Structure of proper file header
// [1][0]           -> 0x4D42
// [5][4][3][2]     -> size of array in bytes
// [6][7][8][9]     -> Reserved (0)
// [13][12][11][10] -> BitmapOffset

#define FH_ARR_MIN_SIZE         14


static inline int32_t parse_type(uint8_t *ptr);
static inline int32_t parse_size(uint8_t *ptr);

int32_t fh_parse(uint8_t *ptr)
{
    if (NULL == ptr)
    {
        return FH_NULLPTR;
    }
    return parse_type(ptr) | parse_size(ptr);

}

static inline int32_t parse_type(uint8_t *ptr)
{
    if((0x42 == ptr[0]) && (0x4D == ptr[1]))
    {
        return 0;
    }
    else
    {
        return FH_TYPE_ERR;
    }
}

static inline int32_t parse_size(uint8_t *ptr)
{
    uint32_t parsed_size = ptr[2];
    parsed_size += (uint32_t)ptr[3] << 8;
    parsed_size += (uint32_t)ptr[4] << 16;
    parsed_size += (uint32_t)ptr[5] << 24;

    if (parsed_size >= FH_ARR_MIN_SIZE)
    {
        return 0;
    }
    else
    {
        return FH_SIZE_ERR;
    }
}
