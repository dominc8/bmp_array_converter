#include "CUnit/CUnitCI.h"
#include "test_parser_fh.h"
#include "test_parser_bh.h"
#include "test_bitmap_parser.h"

CUNIT_CI_RUN("bmp_array_converter",
        CUNIT_CI_PARSER_FH_TESTS,
        CUNIT_CI_PARSER_BH_TESTS,
        CUNIT_CI_BITMAP_PARSER_TESTS
);
