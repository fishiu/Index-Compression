#ifndef DELTA_H
#define DELTA_H

#include "../util.h"

SizeArray deltaEncode(int number);

SizeArray deltaDecode(const char *byteStream);


#endif //DELTA_H
