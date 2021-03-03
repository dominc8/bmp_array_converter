#include "CUnit/CUnitCI.h"

void TEST_parser_fh(void);
void TEST_parser_bh(void);


CUNIT_CI_RUN("bmp_array_converter",
        CUNIT_CI_TEST(TEST_parser_fh),
        CUNIT_CI_TEST(TEST_parser_bh)
);
