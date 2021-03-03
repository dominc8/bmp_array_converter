#include "bitmap_parser.h"
#include "stddef.h"

int32_t bitmap_parse_headers(bitmap_handle_t handle, uint8_t *data)
{
    if (NULL == handle || NULL == data)
    {
        return BITMAP_NULLPTR;
    }
    int32_t fh_ret_val = fh_parse(&handle->file_header, &data[0]);
    fh_ret_val = (fh_ret_val << BITMAP_FH_SHIFT) & BITMAP_FH_MASK;
    int32_t bh_ret_val = bh_parse(&handle->bitmap_header, &data[FH_SIZE]);
    bh_ret_val = (bh_ret_val << BITMAP_BH_SHIFT) & BITMAP_BH_MASK;
    return fh_ret_val | bh_ret_val;
}

