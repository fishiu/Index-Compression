#include "util.h"

char *itoa(int num) {
    char *res = malloc(sizeof(char) * 8);
    for (int i = 0; i < 8; ++i) {
        res[7 - i] = (num >> i) & 1 ? '1' : '0';
    }
    return res;
}

PointerSize str2byteStream(const char *str) {
    int n = (int) strlen(str) / 8;
    unsigned char *byteStream = malloc(sizeof(char) * n);
    for (int i = 0; i < n; ++i) {
        byteStream[i] = 0;
        for (int j = 0; j < 8; ++j) {
            int v = str[8 * i + j] == '1' ? 1 : 0;
            byteStream[i] += v << (7 - j);
        }
    }
    PointerSize res = {byteStream, n};
    return res;
}