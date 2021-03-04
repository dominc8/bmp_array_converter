#ifndef FORMATTER_H
#define FORMATTER_H

#include "bitmap_parser.h"

#define OK                  0
#define NULLPTR_ERR         1

int32_t format_bitmap(bitmap_handle_t handle, FILE *f_out);
int32_t format_fh(fh_handle_t handle, FILE *f_out);
int32_t format_bh(bh_handle_t handle, FILE *f_out);


#endif /* FORMATTER_H */

