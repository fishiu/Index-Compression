#ifndef VB_H
#define VB_H

#include "../util.h"


SizeArray encode(int number);

SizeArray decode(const unsigned char *byteStream, int streamSize);


#endif //VB_H
