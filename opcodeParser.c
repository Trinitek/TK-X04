
#include <stdint.h>
#include <stdbool.h>
#include "registerFile.h"
#include "paramParser.h"

bool parseOpcode(uint8_t opcode) {
    // MISCELLANEOUS BLOCK
    if (opcode <= 0b00001111 && opcode >= 0b00001000) {
        switch(opcode) {
            default: return false;
            case 0b00001000:    // NOP
                break;
            case 0b00001001:    // HLT
                break;
            case 0b00001010:    // CLC
                regFlags.carry = false;
                break;
            case 0b00001011:    // STC
                regFlags.carry = true;
                break;
            case 0b00001100:    // CMP
                paramA.imm = true;
                paramA.immPtr = false;
                paramA.reg = true;
                paramA.regPtr = false;
                paramB = paramA;
                parseParam(2);
                break;
            case 0b00001101:    // REP
                break;
        } return true;
    }

    // DATA MANIPULATION BLOCK
    else if (opcode <= 0b00011111 && opcode >= 0b00010000) {
        switch(opcode) {
            default: return false;
            case 0b00010000:    // MOV
                break;
            case 0b00010001:    // XCHG
                break;
            case 0b00010010:    // LOADP
                break;
            case 0b00010011:    // STOREP
                break;
            case 0b00010100:    // MOVEP
                break;
        } return true;
    }

    // BITWISE MANIPULATION BLOCK
    else if (opcode <= 0b00101111 && opcode >= 0b00100000) {
        switch(opcode) {
            default: return false;
            case 0b00100000:    // SHR
                break;
            case 0b00100001:    // SHL
                break;
            case 0b00100010:    // ROR
                break;
            case 0b00100011:    // ROL
                break;
            case 0b00100100:    // AND
                break;
            case 0b00100101:    // OR
                break;
            case 0b00100110:    // NOT
                break;
            case 0b00100111:    // NAND
                break;
            case 0b00101000:    // NOR
                break;
            case 0b00101001:    // XOR
                break;
            case 0b00101010:    // XNOR
                break;
        } return true;
    }

    // JUMP BLOCK
    else if (opcode <= 0b00111111 && opcode >= 0b00110000) {
        switch(opcode) {
            default: return false;
            case 0b00110000:    // JMP
                break;
            case 0b00110001:    // JC
                break;
            case 0b00110010:    // JNC
                break;
            case 0b00110011:    // JG
                break;
            case 0b00110100:    // JLE
                break;
            case 0b00110101:    // JL
                break;
            case 0b00110110:    // JGE
                break;
            case 0b00110111:    // JE
                break;
            case 0b00111000:    // JNE
                break;
            case 0b00111001:    // LOOP
                break;
            case 0b00111010:    // LOOPE
                break;
            case 0b00111011:    // LOOPNE
                break;
        } return true;
    }

    // MATH BLOCK
    else if (opcode <= 0b01011111 && opcode >= 0b01000000) {
        switch(opcode) {
            default: return false;
            case 0b01000000:    // INC
                break;
            case 0b01000001:    // DEC
                break;
            case 0b01000010:    // ADD
                break;
            case 0b01000011:    // ADC
                break;
            case 0b01000100:    // SUB
                break;
            case 0b01000101:    // SBB
                break;
            case 0b01000110:    // MUL
                break;
            case 0b01000111:    // DIV
                break;
        } return true;
    }

    // STACK BLOCK
    else if (opcode <= 0b01100111 && opcode >= 0b01100000) {
        switch(opcode) {
            default: return false;
            case 0b01100000:    // PUSHA
                break;
            case 0b01100001:    // PUSH
                break;
            case 0b01100010:    // POPA
                break;
            case 0b01100011:    // POP
                break;
            case 0b01100100:    // CALL
                break;
            case 0b01100101:    // RET
                break;
        } return true;
    }

    // PERIPHERIAL I/O BLOCK
    else if (opcode <= 0b01101111 && opcode >= 0b01101000) {
        switch(opcode) {
            default: return false;
            case 0b01101000:    // IN
                break;
            case 0b01101001:    // OUT
                break;
        } return true;
    }

    // INTERRUPT BLOCK
    else if (opcode <= 0b01110111 && opcode >= 0b01110000) {
        switch(opcode) {
            default: return false;
            case 0b01110000:    // STI
                regFlags.intupt = true;
                break;
            case 0b01110001:    // CLI
                regFlags.intupt = false;
                break;
            case 0b01110010:    // IRET
                break;
            case 0b01110011:    // INT
                break;
        } return true;
    }
    
    else return false;
}