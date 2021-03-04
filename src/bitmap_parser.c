#include "bitmap_parser.h"
#include "stddef.h"
#include "stdlib.h"

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

int32_t bitmap_parse_file(bitmap_handle_t handle, FILE *f_bitmap)
{
    if (NULL == handle || NULL == f_bitmap)
    {
        return BITMAP_NULLPTR;
    }
    const uint32_t headers_size = FH_SIZE + BH_SIZE;
    uint8_t headers[FH_SIZE + BH_SIZE];
    int32_t ret_val;
    uint32_t read_bytes;

    read_bytes = fread(&headers[0], 1, headers_size, f_bitmap);
    if (read_bytes != headers_size)
    {
        return BITMAP_READH_ERR;
    }

    ret_val = bitmap_parse_headers(handle, &headers[0]);
    if (BITMAP_OK != ret_val)
    {
        return ret_val;
    }

    handle->bitmap_data = malloc(handle->bitmap_header.bitmap_size);
    if (NULL == handle->bitmap_data)
    {
        return BITMAP_MEM_ERR;
    }

    read_bytes = fread(handle->bitmap_data, 1, handle->bitmap_header.bitmap_size, f_bitmap);
    if (read_bytes != handle->bitmap_header.bitmap_size)
    {
        free(handle->bitmap_data);
        handle->bitmap_data = NULL;
        return BITMAP_READD_ERR;
    }

    return BITMAP_OK;
}

int32_t bitmap_save_as_array(bitmap_handle_t handle, FILE *f_out)
{
    if (NULL == handle || NULL == f_out)
    {
        return BITMAP_NULLPTR;
    }
    return BITMAP_OK;
}

