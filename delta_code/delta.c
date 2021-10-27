#include "delta.h"

SizeArray deltaEncode(int number) {
    int N = (int) floor(log2(number)) + 1;
    int NN = floor(log2(N));
    int L = N + 2 * NN;

    char *res = malloc(sizeof(char) * L);

    // NN
    for (int i = 0; i < NN; ++i) {
        res[i] = '0';
    }
    // NN + 1
    for (int i = 0; i <= NN; ++i) {
        int tmp = (N >> (NN - i)) & 1;
        res[i + NN] = (char) ('0' + tmp);
    }
    // N - 1
    for (int i = 0; i < N - 1; ++i) {
        int tmp = (number >> (N - 2 - i)) & 1;
        res[i + 2 * NN + 1] = (char) ('0' + tmp);
    }
    res[L] = 0;
    SizeArray encodeRes = {res, L};
    return encodeRes;
}

SizeArray deltaDecode(const char *byteStream) {
    int streamLen = (int) strlen(byteStream);
    int res[MAX_N] = {0};
    int resCnt = 0;

    for (int i = 0; i < streamLen;) {
        int tmpResNum = 1;  // num
        int tmpLen = 1;  // len
        int tmpLenLen = 0;  // lengthOfLen

        while (byteStream[i++] == '0')
            tmpLenLen++;
        for (int j = 0; j < tmpLenLen; ++j) {
            tmpLen <<= 1;
            if (byteStream[i++] == '1')
                tmpLen |= 1;
        }
        for (int j = 0; j < tmpLen - 1; ++j) {
            tmpResNum <<= 1;
            if (byteStream[i++] == '1')
                tmpResNum |= 1;
        }

        res[resCnt++] = tmpResNum;
        tmpResNum = 0;
    }

    int *pInt = malloc(sizeof(int) * resCnt);
    memcpy(pInt, res, sizeof(int) * resCnt);
    SizeArray decodeRes = {pInt, resCnt};
    return decodeRes;
}
