#include "bitmap_parser.h"
#include "stddef.h"

int32_t bitmap_parse_headers(bitmap_handle_t handle, uint8_t *data)
{
    if (NULL == handle || NULL == data)
    {
        return BITMAP_NULLPTR;
    }
    return BITMAP_OK;
}

