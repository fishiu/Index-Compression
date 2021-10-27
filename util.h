#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct PointerWithSize {
    void *pointer;
    int size;
} PointerSize;

/**
 * convert int to binary string
 * @param num decimal
 * @return
 */
char *itoa(int num);

PointerSize str2byteStream(const char *str);

#endif //UTIL_H
