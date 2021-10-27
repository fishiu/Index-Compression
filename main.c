#include "util.h"
#include "variable_byte/vb.h"
#include "gamma_code/gamma.h"

void testVbEncode(int testNumber) {
    printf("test encode for %d\n", testNumber);
    PointerSize encodeRes = encode(testNumber);
    const char *encoded = encodeRes.pointer;
    // print encoded bytes in binary format
    for (int i = 0; i < encodeRes.size; i++) {
        printf("%s ", itoa((int) encoded[i]));
    }
}

void testVbDecode(const char *testStream) {
    // string to byteStream
    printf("test decode for %s\n", testStream);
    PointerSize byteStreamRes = str2byteStream(testStream);
    const unsigned char *byteStream = byteStreamRes.pointer;
    PointerSize decodeRes = decode(byteStream, byteStreamRes.size);
    int *decoded = decodeRes.pointer;
    for (int i = 0; i < decodeRes.size; ++i) {
        printf("%d ", decoded[i]);
    }
}

void testGammaEncode(int number) {
    PointerSize encodeRes = gammaEncode(number);
    printf("%d: %s\n", number, (char *) encodeRes.pointer);
}

int main(int argc, char const *argv[]) {
    // testVbEncode(214577);
    // printf("\n");
    // testVbDecode("0000011010111000000011010000110010110001");
    for (int i = 1; i <= 17; ++i) {
        testGammaEncode(i);
    }
    return 0;
}
