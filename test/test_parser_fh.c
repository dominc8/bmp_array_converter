#include "CUnit/CUnitCI.h"
#include "parser_fh.h"
#include "test_parser_fh.h"

void parser_fh_init(void)
{
    fh_parse_init();
}

void parser_fh_nullfptr(void)
{
    FILE *f_in = NULL;
    int32_t ret_val =  fh_parse(f_in);
    CU_ASSERT_NOT_EQUAL(ret_val, 0);
}

