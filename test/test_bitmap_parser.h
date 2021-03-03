#ifndef TEST_BITMAP_PARSER_H
#define TEST_BITMAP_PARSER_H

#include "CUnit/CUnitCI.h"

void bitmap_parser_nullptr(void);
void bitmap_parser_ret(void);
void bitmap_parser_wrong_file_header(void);
void bitmap_parser_wrong_bitmap_header(void);
void bitmap_parser_data(void);

#define CUNIT_CI_BITMAP_PARSER_TESTS                    \
    CUNIT_CI_TEST(bitmap_parser_nullptr),               \
    CUNIT_CI_TEST(bitmap_parser_ret),                   \
    CUNIT_CI_TEST(bitmap_parser_wrong_file_header),     \
    CUNIT_CI_TEST(bitmap_parser_wrong_bitmap_header)

#endif /* TEST_BITMAP_PARSER_H */

