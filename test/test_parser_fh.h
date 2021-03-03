#ifndef TEST_PARSER_FH_H
#define TEST_PARSER_FH_H

#include "CUnit/CUnitCI.h"

void parser_fh_nullptr(void);
void parser_fh_ret(void);
void parser_fh_wrong_type(void);
void parser_fh_wrong_size(void);
void parser_fh_wrong_type_and_size(void);
void parser_fh_wrong_bitmap_offset(void);
void parser_fh_data(void);

#define CUNIT_CI_PARSER_FH_TESTS                    \
    CUNIT_CI_TEST(parser_fh_nullptr),               \
    CUNIT_CI_TEST(parser_fh_ret),                   \
    CUNIT_CI_TEST(parser_fh_wrong_type),            \
    CUNIT_CI_TEST(parser_fh_wrong_size),            \
    CUNIT_CI_TEST(parser_fh_wrong_type_and_size),   \
    CUNIT_CI_TEST(parser_fh_wrong_bitmap_offset),   \
    CUNIT_CI_TEST(parser_fh_data)



#endif /* TEST_PARSER_FH_H */

