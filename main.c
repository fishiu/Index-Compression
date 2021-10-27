#include "encodecode.h"

void testVbEncode(int testNumber) {
    printf("test encode for %d\n", testNumber);
    SizeArray encodeRes = encode(testNumber);
    const char *encoded = encodeRes.pointer;
    // print encoded bytes in binary format
    for (int i = 0; i < encodeRes.size; i++) {
        printf("%s", myItoa((int) encoded[i]));
    }
    printf("\n");
}

void testVbDecode(const char *testStream) {
    // string to byteStream
    printf("test decode for %s\n", testStream);
    SizeArray byteStreamRes = str2byteStream(testStream);
    const unsigned char *byteStream = byteStreamRes.pointer;
    SizeArray decodeRes = decode(byteStream, byteStreamRes.size);
    int *decoded = decodeRes.pointer;
    for (int i = 0; i < decodeRes.size; ++i) {
        printf("%d ", decoded[i]);
    }
    printf("\n");
}

void testGammaEncode(int number) {
    SizeArray encodeRes = gammaEncode(number);
    printf("%d: %s\n", number, (char *) encodeRes.pointer);
}

void testGammaDecode(const char *byteStream) {
    printf("test gamma decode for %s\n", byteStream);
    SizeArray decodeRes = gammaDecode(byteStream);
    int *res = decodeRes.pointer;
    for (int i = 0; i < decodeRes.size; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

void testDeltaEncode(int number) {
    SizeArray encodeRes = deltaEncode(number);
    printf("%d: %s\n", number, (char *) encodeRes.pointer);
}

void testDeltaDecode(const char *byteStream) {
    printf("test delta decode for %s\n", byteStream);
    SizeArray decodeRes = deltaDecode(byteStream);
    int *res = decodeRes.pointer;
    for (int i = 0; i < decodeRes.size; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[]) {
    printf("\n-----------variable bytes-----------\n");

    printf("\n-----------encode-----------\n");
    testVbEncode(824);
    testVbEncode(214577);

    printf("\n-----------decode-----------\n");
    testVbDecode("0000011010111000000011010000110010110001");
    testVbDecode("0000110100001100101100010000011010111000");



    printf("\n-----------gamma code-----------\n");

    printf("\n-----------encode-----------\n");
    for (int i = 1; i <= 10; ++i) {
        testGammaEncode(i);
    }

    printf("\n-----------decode-----------\n");
    testGammaDecode("001010001010");
    testGammaDecode("10100110010000101");



    printf("\n-----------delta code-----------\n");

    printf("\n-----------encode-----------\n");
    for (int i = 1; i <= 10; ++i) {
        testDeltaEncode(i);
    }

    printf("\n-----------decode-----------\n");
    testDeltaDecode("00101000101111");
    testDeltaDecode("10100010101100");

    printf("\nGoodBye :-)");

    return 0;
}
