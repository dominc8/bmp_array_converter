#ifndef TEST_PARSER_BH_H
#define TEST_PARSER_BH_H

#include "CUnit/CUnitCI.h"

void parser_bh_nullptr(void);
#if 0
void parser_bh_ret(void);
void parser_bh_wrong_type(void);
void parser_bh_wrong_size(void);
void parser_bh_wrong_type_and_size(void);
void parser_bh_wrong_bitmap_offset(void);
void parser_bh_data(void);
#endif

#define CUNIT_CI_PARSER_BH_TESTS                    \
    CUNIT_CI_TEST(parser_bh_nullptr)
#if 0
    CUNIT_CI_TEST(parser_bh_ret),                   \
    CUNIT_CI_TEST(parser_bh_wrong_type),            \
    CUNIT_CI_TEST(parser_bh_wrong_size),            \
    CUNIT_CI_TEST(parser_bh_wrong_type_and_size),   \
    CUNIT_CI_TEST(parser_bh_wrong_bitmap_offset),   \
    CUNIT_CI_TEST(parser_bh_data)
#endif


#endif /* TEST_PARSER_BH_H */

