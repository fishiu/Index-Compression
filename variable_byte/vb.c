#include "vb.h"

#define MAX_N 10001
#define OFFSET 128

PointerSize encode(int number) {
    int cnt = 0;
    unsigned char res[MAX_N] = {0};
    while (number >= OFFSET) {
        int tmp = number % OFFSET;
        number = number / OFFSET;
        res[cnt++] = tmp;
    }
    // set continuation bit
    res[0] += OFFSET;
    if (number != 0) res[cnt++] = number;

    unsigned char *reversedRes = malloc(sizeof(unsigned char) * cnt);
    // number of bytes is cnt
    for (int i = 0; i < cnt; ++i)
        reversedRes[i] = res[cnt - i - 1];
    PointerSize encodeRes = {reversedRes, cnt};
    return encodeRes;
}


PointerSize decode(const unsigned char *byteStream, int streamSize) {
    int tmpRes[MAX_N] = {0};
    int cnt = 0;
    int tmpNum = 0;
    for (int i = 0; i < streamSize; ++i) {
        if (byteStream[i] < OFFSET) {
            tmpNum = tmpNum * OFFSET + byteStream[i];
        } else {
            tmpNum = tmpNum * OFFSET + (byteStream[i] - OFFSET);
            tmpRes[cnt++] = tmpNum;
            tmpNum = 0;
        }
    }
    int *res = malloc(sizeof(int) * cnt);
    memcpy(res, tmpRes, sizeof(int) * cnt);

    PointerSize decodeRes = {res, cnt};
    return decodeRes;
}
