
// ===== INTERNAL =====
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
} regFlags_t;
extern regFlags_t regFlags;

// ===== GENERIC 8-BIT AND EXTENDED 16-BIT =====

typedef union {
    struct {
        uint8_t regA;
        uint8_t regB;
    };
    uint16_t;
} regAB_t;
extern regAB_t regAB;

typedef union {
    struct {
        uint8_t regC;
        uint8_t regD;
    };
    uint16_t;
} regCD_t;
extern regCD_t regCD;

typedef union {
    struct {
        uint8_t regE;
        uint8_t regF;
    };
    uint16_t;
} regEF_t;
extern regEF_t regEF;

// ===== POINTERS =====

extern uint8_t regStack;

typedef union {
    struct {
        uint8_t regIXh;
        uint8_t regIXl;
    };
    uint16_t;
} regIX_t;
extern regIX_t regIX;

typedef union {
    struct {
        uint8_t regIYh;
        uint8_t regIYl;
    };
    uint16_t;
} regIY_t;
extern regIY_t regIY;

typedef union {
    struct {
        uint8_t regIZh;
        uint8_t regIZl;
    };
    uint16_t;
} regIZ_t;
extern regIZ_t regIZ;

