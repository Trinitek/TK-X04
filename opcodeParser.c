
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
            case 0b00010000:    // MOV reg, reg
                break;
            case 0b00010001:    // MOV [reg], reg
                break;
            case 0b00010010:    // MOV reg, [reg]
                break;
            case 0b00010011:    // MOV reg, imm
                break;
            case 0b00010100:    // MOV [imm], reg
                break;
            case 0b00010101:    // MOV reg, [imm]
                break;
            case 0b00010110:    // XCHG reg, reg
                break;
            case 0b00010111:    // LOADX
                break;
            case 0b00011000:    // LOADY
                break;
            case 0b00011001:    // LOADZ
                break;
            case 0b00011010:    // STOX
                break;
            case 0b00011011:    // STOY
                break;
            case 0b00011100:    // STOZ
                break;
            case 0b00011101:    // MOVXY
                break;
            case 0b00011110:    // MOVYX
                break;
        } return true;
    }

    // BITWISE MANIPULATION BLOCK
    else if (opcode <= 0b00101111 && opcode >= 0b00100000) {
        switch(opcode) {
            default: return false;
            case 0b00100000:    // SHR reg, imm
                break;
            case 0b00100001:    // SHL reg, imm
                break;
            case 0b00100010:    // ROR reg, imm
                break;
            case 0b00100011:    // ROL reg, imm
                break;
            case 0b00100100:    // AND reg, reg
                break;
            case 0b00100101:    // OR reg, reg
                break;
            case 0b00100110:    // NOT reg, reg
                break;
            case 0b00100111:    // NAND reg, reg
                break;
            case 0b00101000:    // NOR reg, reg
                break;
            case 0b00101001:    // XOR reg, reg
                break;
            case 0b00101010:    // XNOR reg, reg
                break;
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