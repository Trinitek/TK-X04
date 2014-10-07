
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
    uint16_t pointer_imm;
    uint16_t pointer_reg;
    uint16_t pointer_immPtr;
    uint16_t pointer_regPtr;
    paramType_t pTypeX;
    pIdentity_t idX;
    uint8_t i;

    for (i = 1; i <= paramCount; i++) {
        switch (i) {
            case 1:
                pTypeX = pTypeA;
                idX = A;
                break;
            case 2:
                pTypeX = pTypeB;
                idX = B;
                break;
            case 3:
                pTypeX = pTypeC;
                idX = C;
                break;
            case 4:
                pTypeX = pTypeD;
                idX = D;
                break;
        }
        pointer_imm = test_imm(pTypeX, idX, pointer);
        if (pointer_imm) {
            pointer = pointer_imm;
            break;
        }
        pointer_reg = test_reg(pTypeX, idX, pointer);
        if (pointer_reg) {
            pointer = pointer_reg;
            break;
        }
        pointer_immPtr = test_immPtr(pTypeX, idX, pointer);
        if (pointer_immPtr) {
            pointer = pointer_immPtr;
            break;
        }
        pointer_regPtr = test_regPtr(pTypeX, idX, pointer);
        if (pointer_regPtr) {
            pointer = pointer_regPtr;
            break;
        }
        return false;
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

uint16_t test_immPtr(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    if (pType.immPtr && getMemByte(pointer) == 0b00000001) {
        pointer++;
        switch (pIdentity) {
            case A:
                paramA = getMemWord(pointer); break;
            case B:
                paramB = getMemWord(pointer); break;
            case C:
                paramC = getMemWord(pointer); break;
            case D:
                paramD = getMemWord(pointer); break;
        }
        pointer += 2;
        return pointer;
    } else return 0;
}

uint16_t test_reg(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    uint8_t value = getMemByte(pointer);
    if (
            pType.reg &&
            value == 0b00001000 ||  // a
            value == 0b00001001 ||  // b
            value == 0b00001010 ||  // c
            value == 0b00001011 ||  // d
            value == 0b00001100 ||  // e
            value == 0b00001101 ||  // f
            value == 0b00100000 ||  // ab
            value == 0b00100001 ||  // cd
            value == 0b00100010 ||  // ef
            value == 0b01000000 ||  // s
            value == 0b01000001 ||  // ix
            value == 0b01000010 ||  // iy
            value == 0b01000011) {  // iz
        switch (pIdentity) {
            case A:
                paramA = value; break;
            case B:
                paramB = value; break;
            case C:
                paramC = value; break;
            case D:
                paramD = value; break;
        }
        pointer++;
        return pointer;
    } else return 0;
}

uint16_t test_regPtr(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    uint8_t value;
    uint16_t contents;
    if (pType.regPtr && getMemByte(pointer) == 0b00000010) {
        pointer++;
        value = getMemByte(pointer);
        switch (value) {
            case 0b00100000:    // ab
                contents = regAB.regAB; break;
            case 0b00100001:    // cd
                contents = regCD.regCD; break;
            case 0b00100010:    // ef
                contents = regEF.regEF; break;
            case 0b01000001:    // ix
                contents = regIX.regIX; break;
            case 0b01000010:    // iy
                contents = regIY.regIY; break;
            case 0b01000011:    // iz
                contents = regIZ.regIZ; break;
        }
        switch (pIdentity) {
            case A:
                paramA = contents; break;
            case B:
                paramB = contents; break;
            case C:
                paramC = contents; break;
            case D:
                paramD = contents; break;
        }
        pointer++;
        return pointer;
    } else return 0;
}
