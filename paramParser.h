
typedef struct {
    bool reg;
    bool imm;
    bool regPtr;
    bool immPtr;
} paramType_t;

extern paramType_t pTypeA;
extern paramType_t pTypeB;
extern paramType_t pTypeC;
extern paramType_t pTypeD;

typedef enum {
    A, B, C, D
} pIdentity_t;

extern uint16_t paramA;
extern uint16_t paramB;
extern uint16_t paramC;
extern uint16_t paramD;

bool parseParam(uint8_t paramCount);
uint16_t test_imm(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer);
uint16_t test_immPtr(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer);
uint16_t test_reg(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer);
uint16_t test_regPtr(paramType_t pType, pIdentity_t pIdentity, uint16_t pointer);
