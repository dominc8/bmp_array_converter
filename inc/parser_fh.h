#ifndef PARSER_FH_H
#define PARSER_FH_H

#include "stdint.h"

#define FH_OK               0
#define FH_NULLPTR          1
#define FH_TYPE_ERR         2
#define FH_SIZE_ERR         4


int32_t fh_parse(uint8_t *ptr);

#endif /* PARSER_FH_H */

