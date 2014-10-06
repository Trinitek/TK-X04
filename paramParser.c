
#include <stdint.h>
#include <stdbool.h>
#include "registerFile.h"
#include "paramParser.h"
#include "memory.h"

paramType_t pTypeA;
paramType_t pTypeB;
paramType_t pTypeC;
paramType_t pTypeD;

uint16_t paramA;
uint16_t paramB;
uint16_t paramC;
uint16_t paramD;

bool parseParam(uint8_t paramCount) {
    uint16_t pointer = regPC + 1;
    uint16_t pointer_temp;
    if (paramCount >= 1) {
        // check for immediate values
        pointer_temp = test_imm(pTypeA, A, pointer);
        
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
    return true;
}

uint16_t test_imm(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    if (pType.imm && getMemByte(pointer) == 0b00000000) {
        pointer++;
        switch (pIdentity) {
            case A:
                paramA = getMemByte(pointer); break;
            case B:
                paramB = getMemByte(pointer); break;
            case C:
                paramC = getMemByte(pointer); break;
            case D:
                paramD = getMemByte(pointer); break;
        }
        pointer++;
        return pointer;
    } else return 0;
}
