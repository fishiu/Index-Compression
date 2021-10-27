#include "gamma.h"

SizeArray gammaEncode(int number) {
    int N = floor(log2(number));
    int L = 2 * N + 1;
    char *res = malloc(sizeof(char) * (L + 1));
    for (int i = 0; i < N; ++i) {
        res[i] = '0';
    }
    for (int i = N; i < L; ++i) {
        int k = L - i - 1;
        res[i] = (char) ('0' + (number >> k & 1));
    }
    res[L] = 0;
    SizeArray encodeRes = {res, L};
    return encodeRes;
}

/**
 * 00101 0001010 -> 5 10
 * @param toDecode 0/1 string
 * @return int array with size
 */
SizeArray gammaDecode(const char* toDecode) {
    int res[MAX_N] = {0};
    int resCnt = 0;

    int zeroFlag = 1;
    int tmpLen = 0;

    int tmpNum = 0;

    for (int i = 0; i < strlen(toDecode); ++i) {
        char tmp = toDecode[i];
        if (zeroFlag) {
            // zero period
            if (tmp == '0') {
                tmpLen++;
            } else {
                zeroFlag = 0;
                tmpNum += 1 << tmpLen;
            }
        } else {
            // not zero period
            int bit = tmp - '0';
            tmpNum += bit << (tmpLen - 1);
            tmpLen--;
        }
        // a number finished
        if (tmpLen == 0) {
            res[resCnt++] = tmpNum;
            tmpNum = 0;
            zeroFlag = 1;
        }
    }

    int *pInt = malloc(sizeof(int) * resCnt);
    memcpy(pInt, res, sizeof(int) * resCnt);
    SizeArray decodeRes = {pInt, resCnt};

    return decodeRes;
}
