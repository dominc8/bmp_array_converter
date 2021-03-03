#ifndef TEST_PARSER_BH_H
#define TEST_PARSER_BH_H

#include "CUnit/CUnitCI.h"

void parser_bh_nullptr(void);
void parser_bh_wrong_header_size(void);
void parser_bh_wrong_n_color_planes(void);
void parser_bh_data(void);

#define CUNIT_CI_PARSER_BH_TESTS                    \
    CUNIT_CI_TEST(parser_bh_nullptr),               \
    CUNIT_CI_TEST(parser_bh_wrong_header_size),     \
    CUNIT_CI_TEST(parser_bh_wrong_n_color_planes),  \
    CUNIT_CI_TEST(parser_bh_data)


#endif /* TEST_PARSER_BH_H */

