
#include <stdint.h>
#include <stdbool.h>
#include "registerFile.h"

/*
 * This file declares the global register variables and internal flags.
 * To use these registers, include "registerFile.h" into the source file
 * that needs to access them.
 */

// ===== INTERNAL =====
uint16_t regPC;
regFlags_t regFlags;

// ===== GENERIC 8-BIT AND EXTENDED 16-BIT =====
regAB_t regAB;
regCD_t regCD;
regEF_t regEF;

// ===== POINTERS =====
uint8_t regStack;
regIX_t regIX;
regIY_t regIY;
regIZ_t regIZ;
