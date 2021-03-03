#include "parser_fh.h"
#include "stddef.h"
#include "utils.h"

// Structure of proper file header
// [1][0]           -> 0x4D42
// [5][4][3][2]     -> size of array in bytes
// [7][6]           -> Reserved (0)
// [9][8]           -> Reserved (0)
// [13][12][11][10] -> BitmapOffset

#define BITMAP_TYPE         ((uint16_t)(0x4D42))

static int32_t parse_type(fh_handle_t handle, uint8_t *ptr);
static int32_t parse_size(fh_handle_t handle, uint8_t *ptr);
static int32_t parse_reserved(fh_handle_t handle, uint8_t *ptr);
static int32_t parse_offset(fh_handle_t handle, uint8_t *ptr);


int32_t fh_parse(fh_handle_t handle, uint8_t *data)
{
    if (NULL == handle || NULL == data)
    {
        return FH_NULLPTR;
    }
    return parse_type(handle, data)
            | parse_size(handle, data)
            | parse_reserved(handle, data)
            | parse_offset(handle, data);
}

static int32_t parse_type(fh_handle_t handle, uint8_t *ptr)
{
    uint16_t type = cast_16(&ptr[0]);
    if(BITMAP_TYPE == type)
    {
        handle->type = type;
        return 0;
    }
    else
    {
        return FH_TYPE_ERR;
    }
}

static int32_t parse_size(fh_handle_t handle, uint8_t *ptr)
{
    uint32_t size = cast_32(&ptr[2]);

    if (size >= FH_SIZE)
    {
        handle->size_of_file = size;
        return 0;
    }
    else
    {
        return FH_SIZE_ERR;
    }
}

static int32_t parse_reserved(fh_handle_t handle, uint8_t *ptr)
{
    handle->reserved_1 = cast_16(&ptr[6]);
    handle->reserved_2 = cast_16(&ptr[8]);

    return FH_OK;
}

static int32_t parse_offset(fh_handle_t handle, uint8_t *ptr)
{
    uint32_t offset = cast_32(&ptr[10]);

    if (offset >= FH_SIZE)
    {
        handle->bitmap_offset = offset;
        return 0;
    }
    else
    {
        return FH_OFFSET_ERR;
    }
}

