#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 10001

typedef struct ArrayPointerWithSize {
    void *pointer;
    int size;
} SizeArray;

/**
 * convert int to binary string
 * @param num decimal
 * @return
 */
char *myItoa(int num);

SizeArray str2byteStream(const char *str);

#endif //UTIL_H
