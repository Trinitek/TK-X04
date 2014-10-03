
#include <stdint.h>
#include <stdbool.h>
#include "registerFile.h"

/*
 * This file declares the global register variables and internal flags.
 * To use these registers, include "registerFile.h" into the source file
 * that needs to access them.
 */

// Internal
uint16_t regPC;

bool flagCarry;
bool flagOverflow;
bool flagZero;

uint8_t getRegFlags(void) {
    uint8_t regFlags = 0;
    regFlags += flagCarry * 0b00000001;
    regFlags += flagOverflow * 0b00000010;
    regFlags += flagZero * 0b00000100;
    return regFlags;
}

// General 8-bit
uint8_t regA;
uint8_t regB;
uint8_t regC;
uint8_t regD;
uint8_t regE;

// Extended 16-bit
uint16_t regAB;
uint16_t regAC;
uint16_t regAD;
uint16_t regAE;
uint16_t regBA;
uint16_t regBC;
uint16_t regBD;
uint16_t regBE;
uint16_t regCA;
uint16_t regCB;
uint16_t regCD;
uint16_t regCE;
uint16_t regDA;
uint16_t regDB;
uint16_t regDC;
uint16_t regDE;
uint16_t regEA;
uint16_t regEB;
uint16_t regEC;
uint16_t regED;

// Pointers
uint8_t regStack;
uint16_t regIX;
uint16_t regIY;
uint16_t regIZ;