#ifndef UTILS_H
#define UTILS_H

#include "stdint.h"

static inline uint16_t cast_16(uint8_t *ptr)
{
    return ((uint16_t)ptr[0])
            + ((uint16_t)ptr[1] << 8);
}

static inline uint32_t cast_32(uint8_t *ptr)
{
    return ((uint32_t)ptr[0])
            + ((uint32_t)ptr[1] << 8)
            + ((uint32_t)ptr[2] << 16)
            + ((uint32_t)ptr[3] << 24);
}

static inline int32_t cast_i32(uint8_t *ptr)
{
    return (int32_t)cast_32(ptr);
}

#endif /* UTILS_H */

