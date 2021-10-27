#ifndef VB_H
#define VB_H

#include "../util.h"


PointerSize encode(int number);

PointerSize decode(const unsigned char *byteStream, int streamSize);


#endif //VB_H
