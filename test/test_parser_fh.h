#ifndef TEST_PARSER_FH_H
#define TEST_PARSER_FH_H

#include "CUnit/CUnitCI.h"

void parser_fh_nullfptr(void);
void parser_fh_init(void);

#define CUNIT_CI_PARSER_FH_TESTS        \
    CUNIT_CI_TEST(parser_fh_nullfptr),  \
    CUNIT_CI_TEST(parser_fh_init)

#endif /* TEST_PARSER_FH_H */

