#include "CUnit/CUnitCI.h"
#include "bitmap_parser.h"
#include "test_bitmap_parser.h"


void bitmap_parser_nullptr(void)
{
    bitmap_t bitmap;
    uint8_t mem[FH_SIZE + BH_SIZE];
    CU_ASSERT_EQUAL(bitmap_parse_headers(NULL, NULL), BITMAP_NULLPTR);
    CU_ASSERT_EQUAL(bitmap_parse_headers(&bitmap, NULL), BITMAP_NULLPTR);
    CU_ASSERT_EQUAL(bitmap_parse_headers(NULL, &mem[0]), BITMAP_NULLPTR);
}

void bitmap_parser_ret(void)
{
    bitmap_t bitmap;
    uint8_t bitmap_mem[FH_SIZE + BH_SIZE] = 
    {
        0x42, 0x4D,
        0xD6, 0x23, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00,
        0x28, 0x00, 0x00, 0x00,
        0x1d, 0x00, 0x00, 0x00,
        0x2e, 0x00, 0x00, 0x00,
        0x01, 0x00,
        0x20, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0xda, 0x14, 0x00, 0x00,
        0x11, 0x17, 0x00, 0x00,
        0x11, 0x17, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
    };
    int32_t ret_val = bitmap_parse_headers(&bitmap, &bitmap_mem[0]);
    CU_ASSERT_EQUAL(ret_val, BITMAP_OK);
}
