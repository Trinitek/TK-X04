
struct paramType {
    bool reg;
    bool imm;
    bool regPtr;
    bool immPtr;
};

extern struct paramType paramA;
extern struct paramType paramB;
extern struct paramType paramC;
extern struct paramType paramD;

void parseParam(uint8_t paramCount);