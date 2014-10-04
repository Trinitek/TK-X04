
// Internal
extern uint16_t regPC;

typedef union {
    struct {
        bool carry  : 1;
        bool over   : 1;
        bool zero   : 1;
        bool intupt : 1;
        bool        : 4;
    };
    struct {
        uint8_t     : 8;
    };
} regFlags;

// General 8-bit
extern uint8_t regA;
extern uint8_t regB;
extern uint8_t regC;
extern uint8_t regD;
extern uint8_t regE;

// Extended 16-bit
extern uint16_t regAB;
extern uint16_t regAC;
extern uint16_t regAD;
extern uint16_t regAE;
extern uint16_t regBA;
extern uint16_t regBC;
extern uint16_t regBD;
extern uint16_t regBE;
extern uint16_t regCA;
extern uint16_t regCB;
extern uint16_t regCD;
extern uint16_t regCE;
extern uint16_t regDA;
extern uint16_t regDB;
extern uint16_t regDC;
extern uint16_t regDE;
extern uint16_t regEA;
extern uint16_t regEB;
extern uint16_t regEC;
extern uint16_t regED;

// Pointers
extern uint8_t regStack;
extern uint16_t regIX;
extern uint16_t regIY;
extern uint16_t regIZ;