
#include <stdint.h>
#include <stdbool.h>

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
                break;
            case 0b00001011:    // STC
                break;
            case 0b00001100:    // CMP reg, reg
                break;
            case 0b00001101:    // CMP reg, imm
                break;
        } return true;
    }

    // DATA MANIPULATION BLOCK
    else if (opcode <= 0b00011111 && opcode >= 0b00010000) {
        switch(opcode) {
            default: return false;
        } return true;
    }

    // BITWISE MANIPULATION BLOCK
    else if (opcode <= 0b00101111 && opcode >= 0b00100000) {
        switch(opcode) {
            default: return false;
        } return true;
    }

    // JUMP BLOCK
    else if (opcode <= 0b00111111 && opcode >= 0b00110000) {
        switch(opcode) {
            default: return false;
        } return true;
    }

    // MATH BLOCK
    else if (opcode <= 0b01011111 && opcode >= 0b01000000) {
        switch(opcode) {
            default: return false;
        } return true;
    }

    // STACK BLOCK
    else if (opcode <= 0b01100111 && opcode >= 0b01100000) {
        switch(opcode) {
            default: return false;
        } return true;
    }

    // PERIPHERIAL I/O BLOCK
    else if (opcode <= 0b01101111 && opcode >= 0b01101000) {
        switch(opcode) {
            default: return false;
        } return true;
    }

    // INTERRUPT BLOCK
    else if (opcode <= 0b01110111 && opcode >= 0b01110000) {
        switch(opcode) {
            default: return false;
        } return true;
    }
    
    else return false;
}