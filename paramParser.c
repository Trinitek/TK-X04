
#include <stdint.h>
#include <stdbool.h>
#include "registerFile.h"
#include "paramParser.h"

struct paramType paramA;
struct paramType paramB;
struct paramType paramC;
struct paramType paramD;

void parseParam(uint8_t paramCount) {
    uint16_t paramPtr = regPC + 1;
    if (paramCount >= 1) {
        //
    }
    if (paramCount >= 2) {
        //
    }
    if (paramCount >= 3) {
        //
    }
    if (paramCount >= 4) {
        //
    }
}
