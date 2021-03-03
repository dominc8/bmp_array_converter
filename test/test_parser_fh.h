#ifndef TEST_PARSER_FH_H
#define TEST_PARSER_FH_H

#include "CUnit/CUnitCI.h"

void parser_fh_nullptr(void);
void parser_fh_ret(void);
void parser_fh_wrong_type(void);
void parser_fh_wrong_size(void);

#define CUNIT_CI_PARSER_FH_TESTS            \
    CUNIT_CI_TEST(parser_fh_nullptr),       \
    CUNIT_CI_TEST(parser_fh_ret),           \
    CUNIT_CI_TEST(parser_fh_wrong_type),    \
    CUNIT_CI_TEST(parser_fh_wrong_size)


#endif /* TEST_PARSER_FH_H */

