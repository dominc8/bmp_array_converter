#include "CUnit/CUnitCI.h"
#include "parser_fh.h"
#include "test_parser_fh.h"


void parser_fh_nullptr(void)
{
    fh_data_t fh_data;
    uint8_t mem[FH_SIZE];
    CU_ASSERT_EQUAL(fh_parse(NULL, NULL), FH_NULLPTR);
    CU_ASSERT_EQUAL(fh_parse(&fh_data, NULL), FH_NULLPTR);
    CU_ASSERT_EQUAL(fh_parse(NULL, &mem[0]), FH_NULLPTR);
}

void parser_fh_ret(void)
{
    fh_data_t fh_data;
    uint8_t proper_fh_mem[FH_SIZE] = 
    {
        0x42, 0x4D,
        0xD6, 0x23, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&fh_data, &proper_fh_mem[0]);
    CU_ASSERT_EQUAL(ret_val, FH_OK);
}

void parser_fh_wrong_type(void)
{
    fh_data_t fh_data;
    uint8_t fh_mem[FH_SIZE] = 
    {
        0x42, 0x00,
        0x0E, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&fh_data, &fh_mem[0]);
    CU_ASSERT_EQUAL(ret_val, FH_TYPE_ERR);
}

void parser_fh_wrong_size(void)
{
    fh_data_t fh_data;
    uint8_t fh_mem[FH_SIZE] = 
    {
        0x42, 0x4D,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&fh_data, &fh_mem[0]);
    CU_ASSERT_EQUAL(ret_val, FH_SIZE_ERR);
}

void parser_fh_wrong_type_and_size(void)
{
    fh_data_t fh_data;
    uint8_t fh_mem[FH_SIZE] = 
    {
        0x42, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&fh_data, &fh_mem[0]);
    CU_ASSERT_EQUAL(ret_val, FH_SIZE_ERR | FH_TYPE_ERR);
}

void parser_fh_wrong_bitmap_offset(void)
{
    fh_data_t fh_data;
    uint8_t fh_mem[FH_SIZE] = 
    {
        0x42, 0x4D,
        0x0E, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&fh_data, &fh_mem[0]);
    CU_ASSERT_EQUAL(ret_val, FH_OFFSET_ERR);
}

void parser_fh_data(void)
{
    fh_data_t fh_data;
    uint8_t proper_fh_mem[FH_SIZE] = 
    {
        0x42, 0x4D,
        0xD6, 0x23, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&fh_data, &proper_fh_mem[0]);
    CU_ASSERT_EQUAL(ret_val, FH_OK);
    CU_ASSERT_EQUAL(fh_data.type, (uint16_t)0x4D42);
    CU_ASSERT_EQUAL(fh_data.size_of_file, (uint32_t)0x000023D6);
    CU_ASSERT_EQUAL(fh_data.reserved_1, (uint16_t)0x0000);
    CU_ASSERT_EQUAL(fh_data.reserved_2, (uint16_t)0x0000);
    CU_ASSERT_EQUAL(fh_data.bitmap_offset, (uint32_t)0x00000036);
}

