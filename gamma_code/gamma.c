#include "gamma.h"

// PointerSize decode(const char *byteStream) {
//
// }

PointerSize gammaEncode(int number) {
    int N = floor(log2(number));
    int L = 2 * N + 1;
    char *res = malloc(sizeof(char) * L);
    for (int i = 0; i < N; ++i) {
        res[i] = '0';
    }
    for (int i = N; i < L; ++i) {
        int k = L - i - 1;
        res[i] = (char) ('0' + (number >> k & 1));
    }
    PointerSize encodeRes = {res, L};
    return encodeRes;
}
