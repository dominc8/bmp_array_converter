#include "CUnit/CUnitCI.h"
#include "parser_fh.h"
#include "test_parser_fh.h"

#define FH_SIZE         14

void parser_fh_nullptr(void)
{
    uint8_t* ptr = NULL;
    int32_t ret_val =  fh_parse(ptr);
    CU_ASSERT_EQUAL(ret_val, FH_NULLPTR);
}

void parser_fh_ret(void)
{
    uint8_t proper_fh[FH_SIZE] = 
    {
        0x42, 0x4D,
        0x0E, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&proper_fh[0]);
    CU_ASSERT_EQUAL(ret_val, FH_OK);
}

void parser_fh_wrong_type(void)
{
    uint8_t proper_fh[FH_SIZE] = 
    {
        0x42, 0x00,
        0x0E, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&proper_fh[0]);
    CU_ASSERT_EQUAL(ret_val, FH_TYPE_ERR);
}

void parser_fh_wrong_size(void)
{
    uint8_t proper_fh[FH_SIZE] = 
    {
        0x42, 0x4D,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00
    };
    int32_t ret_val =  fh_parse(&proper_fh[0]);
    CU_ASSERT_EQUAL(ret_val, FH_SIZE_ERR);
}
