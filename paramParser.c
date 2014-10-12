
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

/**
 * Parse the parameters following an opcode.
 * @param paramCount
 * @return True if successful, false if parameters are invalid or incomplete.
 */
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
        // Select the right parameter blocks to modify for this iteration of the parsing loop
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

        // Test for immediate values
        pointer_imm = test_imm(pTypeX, idX, pointer);
        if (pointer_imm) {
            pointer = pointer_imm;
            break;
        }

        // Test for registers
        pointer_reg = test_reg(pTypeX, idX, pointer);
        if (pointer_reg) {
            pointer = pointer_reg;
            break;
        }

        // Test for immediate 16-bit addresses
        pointer_immPtr = test_immPtr(pTypeX, idX, pointer);
        if (pointer_immPtr) {
            pointer = pointer_immPtr;
            break;
        }
        
        // Test for 16-bit pointer registers
        pointer_regPtr = test_regPtr(pTypeX, idX, pointer);
        if (pointer_regPtr) {
            pointer = pointer_regPtr;
            break;
        }

        // No valid parameters found, so fail.
        return false;
    }

    // All parameters found are valid, so update regPC and pass.
    regPC = pointer;
    return true;
}

/**
 * Test for an immediate 8-bit or 16-bit value as a parameter.
 * @param pType
 * @param pIdentity
 * @param pointer
 * @return Updated pointer if immediate value found, null otherwise.
 */
uint16_t test_imm(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    if (pType.imm && getMemByte(pointer) == 0b00000000) {
        // Test for 8-bit immediate values
        if (getMemByte(pointer) == 0b00000000) {
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
        }
        // Test for 16-bit immediate values
        else if (getMemByte(pointer) == 0b00000011) {
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
        }
        return pointer;
    } else return 0;
}

/**
 * Test for an immediate 16-bit address as a parameter.
 * @param pType
 * @param pIdentity
 * @param pointer
 * @return Updated pointer if immediate value found, null otherwise.
 */
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

/**
 * Test for a register as a parameter.
 * @param pType
 * @param pIdentity
 * @param pointer
 * @return Updated pointer if register found, null otherwise.
 */
uint16_t test_reg(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    uint8_t regCode = getMemByte(pointer);
    if (
            pType.reg &&
            regCode == 0b00001000 ||  // a
            regCode == 0b00001001 ||  // b
            regCode == 0b00001010 ||  // c
            regCode == 0b00001011 ||  // d
            regCode == 0b00001100 ||  // e
            regCode == 0b00001101 ||  // f
            regCode == 0b00100000 ||  // ab
            regCode == 0b00100001 ||  // cd
            regCode == 0b00100010 ||  // ef
            regCode == 0b01000000 ||  // s
            regCode == 0b01000001 ||  // ix
            regCode == 0b01000010 ||  // iy
            regCode == 0b01000011) {  // iz
        switch (pIdentity) {
            case A:
                paramA = regCode; break;
            case B:
                paramB = regCode; break;
            case C:
                paramC = regCode; break;
            case D:
                paramD = regCode; break;
        }
        pointer++;
        return pointer;
    } else return 0;
}

/**
 * Test for a 16-bit register as a parameter, and treat its contents as a 16-bit address.
 * @param pType
 * @param pIdentity
 * @param pointer
 * @return Updated pointer if register found, null otherwise.
 */
uint16_t test_regPtr(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer) {
    uint8_t regCode;
    uint16_t contents;
    if (pType.regPtr && getMemByte(pointer) == 0b00000010) {
        pointer++;
        regCode = getMemByte(pointer);
        switch (regCode) {
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
