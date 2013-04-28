#include "types.hpp"

/*
The table is without KIL/HLT that would crash the emulation.

The following opcodes are to be checked:
8 (0x8) inconsistent mem write
9 (0x9) inconsistent mem read
11 (0xb) inconsistent mem read
16 (0x10) inconsistent number of cycles
32 (0x20) inconsistent mem write
41 (0x29) inconsistent mem read
43 (0x2b) inconsistent mem read
72 (0x48) inconsistent mem write
73 (0x49) inconsistent mem read
75 (0x4b) inconsistent mem read
80 (0x50) inconsistent number of cycles
105 (0x69) inconsistent mem read
107 (0x6b) inconsistent mem read
108 (0x6c) inconsistent mem read
128 (0x80) inconsistent mem read
129 (0x81) inconsistent mem read
130 (0x82) inconsistent mem read
131 (0x83) inconsistent mem read
137 (0x89) inconsistent mem read
139 (0x8b) inconsistent mem read
144 (0x90) inconsistent number of cycles
145 (0x91) inconsistent mem read
147 (0x93) inconsistent mem write
148 (0x94) inconsistent mem read
149 (0x95) inconsistent mem read
150 (0x96) inconsistent mem read
151 (0x97) inconsistent mem read
153 (0x99) inconsistent mem read
155 (0x9b) inconsistent mem read
155 (0x9b) inconsistent mem write
156 (0x9c) inconsistent mem write
157 (0x9d) inconsistent mem read
158 (0x9e) inconsistent mem write
159 (0x9f) inconsistent mem write
160 (0xa0) inconsistent mem read
162 (0xa2) inconsistent mem read
169 (0xa9) inconsistent mem read
171 (0xab) inconsistent mem read
192 (0xc0) inconsistent mem read
194 (0xc2) inconsistent mem read
201 (0xc9) inconsistent mem read
203 (0xcb) inconsistent mem read
208 (0xd0) inconsistent number of cycles
224 (0xe0) inconsistent mem read
226 (0xe2) inconsistent mem read
233 (0xe9) inconsistent mem read
235 (0xeb) inconsistent mem read
*/

struct OpcodeDef opcode_def[]={
	{0x00,"BRK",1,7,D_NONE,D_P,MEM_NONE,IMP,LEGAL|UNUSABLE},
	{0x01,"ORA",2,6,D_A,D_P,MEM_R,INX,LEGAL},
	{0x03,"SLO",2,8,D_A,D_P,MEM_R|MEM_W,INX,ILLEGAL},
	{0x04,"NOP",2,3,D_NONE,D_NONE,MEM_R,ZPG,ILLEGAL},
	{0x05,"ORA",2,3,D_A,D_A|D_P,MEM_R,ZPG,LEGAL},
	{0x06,"ASL",2,5,D_NONE,D_P,MEM_R|MEM_W,ZPG,LEGAL},
	{0x07,"SLO",2,5,D_A,D_A|D_P,MEM_R|MEM_W,ZPG,ILLEGAL},
	{0x08,"PHP",1,3,D_S|D_P,D_S,MEM_W,IMP,LEGAL},
	{0x09,"ORA",2,2,D_NONE,D_A|D_P,MEM_NONE,IMM,LEGAL},
	{0x0A,"ASL",1,2,D_A,D_A|D_P,MEM_NONE,ACC,LEGAL},
	{0x0B,"ANC",2,2,D_A,D_P,MEM_NONE,IMM,ILLEGAL},
	{0x0C,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABS,ILLEGAL},
	{0x0D,"ORA",3,4,D_A,D_A|D_P,MEM_R,ABS,LEGAL},
	{0x0E,"ASL",3,6,D_NONE,D_P,MEM_R|MEM_W,ABS,LEGAL},
	{0x0F,"SLO",3,6,D_A,D_A|D_P,MEM_R|MEM_W,ABS,ILLEGAL},
	{0x10,"BPL",2,2,D_P,D_NONE,MEM_NONE,REL,LEGAL},
	{0x11,"ORA",2,5,D_A,D_P,MEM_R,INY,LEGAL},
	{0x13,"SLO",2,8,D_A,D_P,MEM_R|MEM_W,INY,ILLEGAL},
	{0x14,"NOP",2,4,D_NONE,D_NONE,MEM_R,ZPX,ILLEGAL},
	{0x15,"ORA",2,4,D_A,D_A|D_P,MEM_R,ZPX,LEGAL},
	{0x16,"ASL",2,6,D_NONE,D_P,MEM_R|MEM_W,ZPX,LEGAL},
	{0x17,"SLO",2,6,D_A,D_A|D_P,MEM_R|MEM_W,ZPX,ILLEGAL},
	{0x18,"CLC",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0x19,"ORA",3,4,D_A,D_A|D_P,MEM_R,ABY,LEGAL},
	{0x1A,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,ILLEGAL},
	{0x1B,"SLO",3,7,D_A,D_A|D_P,MEM_R|MEM_W,ABY,ILLEGAL},
	{0x1C,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABX,ILLEGAL},
	{0x1D,"ORA",3,4,D_A,D_A|D_P,MEM_R,ABX,LEGAL},
	{0x1E,"ASL",3,7,D_NONE,D_P,MEM_R|MEM_W,ABX,LEGAL},
	{0x1F,"SLO",3,7,D_A,D_A|D_P,MEM_R|MEM_W,ABX,ILLEGAL},
	{0x20,"JSR",3,6,D_S,D_S,MEM_W,ADR,LEGAL},
	{0x21,"AND",2,6,D_NONE,D_A|D_P,MEM_R,INX,LEGAL},
	{0x23,"RLA",2,8,D_P,D_A|D_P,MEM_R|MEM_W,INX,ILLEGAL},
	{0x24,"BIT",2,3,D_A,D_P,MEM_R,ZPG,LEGAL},
	{0x25,"AND",2,3,D_A,D_A|D_P,MEM_R,ZPG,LEGAL},
	{0x26,"ROL",2,5,D_P,D_P,MEM_R|MEM_W,ZPG,LEGAL},
	{0x27,"RLA",2,5,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ZPG,ILLEGAL},
	{0x28,"PLP",1,4,D_S,D_S|D_P,MEM_NONE,IMP,LEGAL},
	{0x29,"AND",2,2,D_A,D_A|D_P,MEM_NONE,IMM,LEGAL},
	{0x2A,"ROL",1,2,D_A|D_P,D_A|D_P,MEM_NONE,ACC,LEGAL},
	{0x2B,"ANC",2,2,D_A,D_P,MEM_NONE,IMM,ILLEGAL},
	{0x2C,"BIT",3,4,D_A,D_P,MEM_R,ABS,LEGAL},
	{0x2D,"AND",3,4,D_A,D_A|D_P,MEM_R,ABS,LEGAL},
	{0x2E,"ROL",3,6,D_P,D_P,MEM_R|MEM_W,ABS,LEGAL},
	{0x2F,"RLA",3,6,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABS,ILLEGAL},
	{0x30,"BMI",2,2,D_NONE,D_NONE,MEM_NONE,REL,LEGAL},
	{0x31,"AND",2,5,D_NONE,D_A|D_P,MEM_R,INY,LEGAL},
	{0x33,"RLA",2,8,D_P,D_A|D_P,MEM_R|MEM_W,INY,ILLEGAL},
	{0x34,"NOP",2,4,D_NONE,D_NONE,MEM_R,ZPX,ILLEGAL},
	{0x35,"AND",2,4,D_A,D_A|D_P,MEM_R,ZPX,LEGAL},
	{0x36,"ROL",2,6,D_P,D_P,MEM_R|MEM_W,ZPX,LEGAL},
	{0x37,"RLA",2,6,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ZPX,ILLEGAL},
	{0x38,"SEC",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0x39,"AND",3,4,D_A,D_A|D_P,MEM_R,ABY,LEGAL},
	{0x3A,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,ILLEGAL},
	{0x3B,"RLA",3,7,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABY,ILLEGAL},
	{0x3C,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABX,ILLEGAL},
	{0x3D,"AND",3,4,D_A,D_A|D_P,MEM_R,ABX,LEGAL},
	{0x3E,"ROL",3,7,D_P,D_P,MEM_R|MEM_W,ABX,LEGAL},
	{0x3F,"RLA",3,7,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABX,ILLEGAL},
	{0x40,"RTI",1,6,D_S,D_S|D_P,MEM_NONE,IMP,LEGAL|UNUSABLE},
	{0x41,"EOR",2,6,D_A,D_P,MEM_R,INX,LEGAL},
	{0x43,"SRE",2,8,D_A,D_P,MEM_R|MEM_W,INX,ILLEGAL},
	{0x44,"NOP",2,3,D_NONE,D_NONE,MEM_R,ZPG,ILLEGAL},
	{0x45,"EOR",2,3,D_A,D_A|D_P,MEM_R,ZPG,LEGAL},
	{0x46,"LSR",2,5,D_NONE,D_P,MEM_R|MEM_W,ZPG,LEGAL},
	{0x47,"SRE",2,5,D_A,D_A|D_P,MEM_R|MEM_W,ZPG,ILLEGAL},
	{0x48,"PHA",1,3,D_A|D_S,D_S,MEM_W,IMP,LEGAL},
	{0x49,"EOR",2,2,D_A,D_A|D_P,MEM_NONE,IMM,LEGAL},
	{0x4A,"LSR",1,2,D_A,D_A|D_P,MEM_NONE,ACC,LEGAL},
	{0x4B,"ALR",2,2,D_A,D_A|D_P,MEM_NONE,IMM,ILLEGAL},
	{0x4C,"JMP",3,3,D_NONE,D_NONE,MEM_NONE,ADR,LEGAL},
	{0x4D,"EOR",3,4,D_A,D_A|D_P,MEM_R,ABS,LEGAL},
	{0x4E,"LSR",3,6,D_NONE,D_P,MEM_R|MEM_W,ABS,LEGAL},
	{0x4F,"SRE",3,6,D_A,D_A|D_P,MEM_R|MEM_W,ABS,ILLEGAL},
	{0x50,"BVC",2,2,D_P,D_NONE,MEM_NONE,REL,LEGAL},
	{0x51,"EOR",2,5,D_A,D_P,MEM_R,INY,LEGAL},
	{0x53,"SRE",2,8,D_A,D_P,MEM_R|MEM_W,INY,ILLEGAL},
	{0x54,"NOP",2,4,D_NONE,D_NONE,MEM_R,ZPX,ILLEGAL},
	{0x55,"EOR",2,4,D_A,D_A|D_P,MEM_R,ZPX,LEGAL},
	{0x56,"LSR",2,6,D_NONE,D_P,MEM_R|MEM_W,ZPX,LEGAL},
	{0x57,"SRE",2,6,D_A,D_A|D_P,MEM_R|MEM_W,ZPX,ILLEGAL},
	{0x58,"CLI",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0x59,"EOR",3,4,D_A,D_A|D_P,MEM_R,ABY,LEGAL},
	{0x5A,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,ILLEGAL},
	{0x5B,"SRE",3,7,D_A,D_A|D_P,MEM_R|MEM_W,ABY,ILLEGAL},
	{0x5C,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABX,ILLEGAL},
	{0x5D,"EOR",3,4,D_A,D_A|D_P,MEM_R,ABX,LEGAL},
	{0x5E,"LSR",3,7,D_NONE,D_P,MEM_R|MEM_W,ABX,LEGAL},
	{0x5F,"SRE",3,7,D_A,D_A|D_P,MEM_R|MEM_W,ABX,ILLEGAL},
	{0x60,"RTS",1,6,D_S,D_S,MEM_NONE,IMP,LEGAL},
	{0x61,"ADC",2,6,D_A|D_P,D_A|D_P,MEM_R,INX,LEGAL},
	{0x63,"RRA",2,8,D_A|D_P,D_A|D_P,MEM_R|MEM_W,INX,ILLEGAL},
	{0x64,"NOP",2,3,D_NONE,D_NONE,MEM_R,ZPG,ILLEGAL},
	{0x65,"ADC",2,3,D_A|D_P,D_A|D_P,MEM_R,ZPG,LEGAL},
	{0x66,"ROR",2,5,D_P,D_P,MEM_R|MEM_W,ZPG,LEGAL},
	{0x67,"RRA",2,5,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ZPG,ILLEGAL},
	{0x68,"PLA",1,4,D_S,D_A|D_S|D_P,MEM_NONE,IMP,LEGAL},
	{0x69,"ADC",2,2,D_A|D_P,D_A|D_P,MEM_NONE,IMM,LEGAL},
	{0x6A,"ROR",1,2,D_A|D_P,D_A|D_P,MEM_NONE,ACC,LEGAL},
	{0x6B,"ARR",2,2,D_A|D_P,D_A|D_P,MEM_NONE,IMM,ILLEGAL},
	{0x6C,"JMP",3,5,D_NONE,D_NONE,MEM_NONE,IND,LEGAL},
	{0x6D,"ADC",3,4,D_A|D_P,D_A|D_P,MEM_R,ABS,LEGAL},
	{0x6E,"ROR",3,6,D_P,D_P,MEM_R|MEM_W,ABS,LEGAL},
	{0x6F,"RRA",3,6,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABS,ILLEGAL},
	{0x70,"BVS",2,2,D_NONE,D_NONE,MEM_NONE,REL,LEGAL},
	{0x71,"ADC",2,5,D_A|D_P,D_A|D_P,MEM_R,INY,LEGAL},
	{0x73,"RRA",2,8,D_A|D_P,D_A|D_P,MEM_R|MEM_W,INY,ILLEGAL},
	{0x74,"NOP",2,4,D_NONE,D_NONE,MEM_R,ZPX,ILLEGAL},
	{0x75,"ADC",2,4,D_A|D_P,D_A|D_P,MEM_R,ZPX,LEGAL},
	{0x76,"ROR",2,6,D_P,D_P,MEM_R|MEM_W,ZPX,LEGAL},
	{0x77,"RRA",2,6,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ZPX,ILLEGAL},
	{0x78,"SEI",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0x79,"ADC",3,4,D_A|D_P,D_A|D_P,MEM_R,ABY,LEGAL},
	{0x7A,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,ILLEGAL},
	{0x7B,"RRA",3,7,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABY,ILLEGAL},
	{0x7C,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABX,ILLEGAL},
	{0x7D,"ADC",3,4,D_A|D_P,D_A|D_P,MEM_R,ABX,LEGAL},
	{0x7E,"ROR",3,7,D_P,D_P,MEM_R|MEM_W,ABX,LEGAL},
	{0x7F,"RRA",3,7,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABX,ILLEGAL},
	{0x80,"NOP",2,2,D_NONE,D_NONE,MEM_NONE,IMM,ILLEGAL},
	{0x81,"STA",2,6,D_A,D_NONE,MEM_R|MEM_W,INX,LEGAL},
	{0x82,"NOP",2,2,D_NONE,D_NONE,MEM_NONE,IMM,ILLEGAL},
	{0x83,"SAX",2,6,D_NONE,D_NONE,MEM_R|MEM_W,INX,ILLEGAL},
	{0x84,"STY",2,3,D_Y,D_NONE,MEM_W,ZPG,LEGAL},
	{0x85,"STA",2,3,D_A,D_NONE,MEM_W,ZPG,LEGAL},
	{0x86,"STX",2,3,D_X,D_NONE,MEM_W,ZPG,LEGAL},
	{0x87,"SAX",2,3,D_NONE,D_NONE,MEM_W,ZPG,ILLEGAL},
	{0x88,"DEY",1,2,D_Y,D_Y|D_P,MEM_NONE,IMP,LEGAL},
	{0x89,"NOP",2,2,D_NONE,D_NONE,MEM_NONE,IMM,ILLEGAL},
	{0x8A,"TXA",1,2,D_X,D_A|D_P,MEM_NONE,IMP,LEGAL},
	{0x8B,"XAA",2,2,D_NONE,D_A|D_P,MEM_NONE,IMM,ILLEGAL},
	{0x8C,"STY",3,4,D_Y,D_NONE,MEM_W,ABS,LEGAL},
	{0x8D,"STA",3,4,D_A,D_NONE,MEM_W,ABS,LEGAL},
	{0x8E,"STX",3,4,D_X,D_NONE,MEM_W,ABS,LEGAL},
	{0x8F,"SAX",3,4,D_NONE,D_NONE,MEM_W,ABS,ILLEGAL},
	{0x90,"BCC",2,2,D_P,D_NONE,MEM_NONE,REL,LEGAL},
	{0x91,"STA",2,6,D_A,D_NONE,MEM_R|MEM_W,INY,LEGAL},
	{0x93,"AHX",2,6,D_NONE,D_NONE,MEM_R|MEM_W,INY,ILLEGAL},
	{0x94,"STY",2,4,D_Y,D_NONE,MEM_R|MEM_W,ZPX,LEGAL},
	{0x95,"STA",2,4,D_A,D_NONE,MEM_R|MEM_W,ZPX,LEGAL},
	{0x96,"STX",2,4,D_X,D_NONE,MEM_R|MEM_W,ZPY,LEGAL},
	{0x97,"SAX",2,4,D_NONE,D_NONE,MEM_R|MEM_W,ZPY,ILLEGAL},
	{0x98,"TYA",1,2,D_Y,D_A|D_P,MEM_NONE,IMP,LEGAL},
	{0x99,"STA",3,5,D_A,D_NONE,MEM_R|MEM_W,ABY,LEGAL},
	{0x9A,"TXS",1,2,D_X,D_S,MEM_NONE,IMP,LEGAL},
	{0x9B,"TAS",3,5,D_Y,D_S,MEM_W,ABY,ILLEGAL},
	{0x9C,"SHY",3,5,D_Y,D_NONE,MEM_R|MEM_W,ABX,ILLEGAL},
	{0x9D,"STA",3,5,D_A,D_NONE,MEM_R|MEM_W,ABX,LEGAL},
	{0x9E,"SHX",3,5,D_X,D_NONE,MEM_R|MEM_W,ABY,ILLEGAL},
	{0x9F,"AHX",3,5,D_NONE,D_NONE,MEM_R|MEM_W,ABY,ILLEGAL},
	{0xA0,"LDY",2,2,D_NONE,D_Y|D_P,MEM_NONE,IMM,LEGAL},
	{0xA1,"LDA",2,6,D_NONE,D_A|D_P,MEM_R,INX,LEGAL},
	{0xA2,"LDX",2,2,D_NONE,D_X|D_P,MEM_NONE,IMM,LEGAL},
	{0xA3,"LAX",2,6,D_NONE,D_A|D_X|D_P,MEM_R,INX,ILLEGAL},
	{0xA4,"LDY",2,3,D_NONE,D_Y|D_P,MEM_R,ZPG,LEGAL},
	{0xA5,"LDA",2,3,D_NONE,D_A|D_P,MEM_R,ZPG,LEGAL},
	{0xA6,"LDX",2,3,D_NONE,D_X|D_P,MEM_R,ZPG,LEGAL},
	{0xA7,"LAX",2,3,D_NONE,D_A|D_X|D_P,MEM_R,ZPG,ILLEGAL},
	{0xA8,"TAY",1,2,D_A,D_Y|D_P,MEM_NONE,IMP,LEGAL},
	{0xA9,"LDA",2,2,D_NONE,D_A|D_P,MEM_NONE,IMM,LEGAL},
	{0xAA,"TAX",1,2,D_A,D_X|D_P,MEM_NONE,IMP,LEGAL},
	{0xAB,"LAX",2,2,D_A,D_A|D_X|D_P,MEM_NONE,IMM,ILLEGAL},
	{0xAC,"LDY",3,4,D_NONE,D_Y|D_P,MEM_R,ABS,LEGAL},
	{0xAD,"LDA",3,4,D_NONE,D_A|D_P,MEM_R,ABS,LEGAL},
	{0xAE,"LDX",3,4,D_NONE,D_X|D_P,MEM_R,ABS,LEGAL},
	{0xAF,"LAX",3,4,D_NONE,D_A|D_X|D_P,MEM_R,ABS,ILLEGAL},
	{0xB0,"BCS",2,2,D_NONE,D_NONE,MEM_NONE,REL,LEGAL},
	{0xB1,"LDA",2,5,D_NONE,D_A|D_P,MEM_R,INY,LEGAL},
	{0xB3,"LAX",2,5,D_NONE,D_A|D_X|D_P,MEM_R,INY,ILLEGAL},
	{0xB4,"LDY",2,4,D_NONE,D_Y|D_P,MEM_R,ZPX,LEGAL},
	{0xB5,"LDA",2,4,D_NONE,D_A|D_P,MEM_R,ZPX,LEGAL},
	{0xB6,"LDX",2,4,D_NONE,D_X|D_P,MEM_R,ZPY,LEGAL},
	{0xB7,"LAX",2,4,D_NONE,D_A|D_X|D_P,MEM_R,ZPY,ILLEGAL},
	{0xB8,"CLV",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0xB9,"LDA",3,4,D_NONE,D_A|D_P,MEM_R,ABY,LEGAL},
	{0xBA,"TSX",1,2,D_S,D_X|D_P,MEM_NONE,IMP,LEGAL},
	{0xBB,"LAS",3,4,D_S,D_A|D_X|D_S|D_P,MEM_R,ABY,ILLEGAL},
	{0xBC,"LDY",3,4,D_NONE,D_Y|D_P,MEM_R,ABX,LEGAL},
	{0xBD,"LDA",3,4,D_NONE,D_A|D_P,MEM_R,ABX,LEGAL},
	{0xBE,"LDX",3,4,D_NONE,D_X|D_P,MEM_R,ABY,LEGAL},
	{0xBF,"LAX",3,4,D_NONE,D_A|D_X|D_P,MEM_R,ABY,ILLEGAL},
	{0xC0,"CPY",2,2,D_Y,D_P,MEM_NONE,IMM,LEGAL},
	{0xC1,"CMP",2,6,D_A,D_P,MEM_R,INX,LEGAL},
	{0xC2,"NOP",2,2,D_NONE,D_NONE,MEM_NONE,IMM,ILLEGAL},
	{0xC3,"DCP",2,8,D_A,D_P,MEM_R|MEM_W,INX,ILLEGAL},
	{0xC4,"CPY",2,3,D_Y,D_P,MEM_R,ZPG,LEGAL},
	{0xC5,"CMP",2,3,D_A,D_P,MEM_R,ZPG,LEGAL},
	{0xC6,"DEC",2,5,D_NONE,D_P,MEM_R|MEM_W,ZPG,LEGAL},
	{0xC7,"DCP",2,5,D_A,D_P,MEM_R|MEM_W,ZPG,ILLEGAL},
	{0xC8,"INY",1,2,D_Y,D_Y|D_P,MEM_NONE,IMP,LEGAL},
	{0xC9,"CMP",2,2,D_A,D_P,MEM_NONE,IMM,LEGAL},
	{0xCA,"DEX",1,2,D_X,D_X|D_P,MEM_NONE,IMP,LEGAL},
	{0xCB,"AXS",2,2,D_NONE,D_X|D_P,MEM_NONE,IMM,ILLEGAL},
	{0xCC,"CPY",3,4,D_Y,D_P,MEM_R,ABS,LEGAL},
	{0xCD,"CMP",3,4,D_A,D_P,MEM_R,ABS,LEGAL},
	{0xCE,"DEC",3,6,D_NONE,D_P,MEM_R|MEM_W,ABS,LEGAL},
	{0xCF,"DCP",3,6,D_A,D_P,MEM_R|MEM_W,ABS,ILLEGAL},
	{0xD0,"BNE",2,2,D_P,D_NONE,MEM_NONE,REL,LEGAL},
	{0xD1,"CMP",2,5,D_A,D_P,MEM_R,INY,LEGAL},
	{0xD3,"DCP",2,8,D_A,D_P,MEM_R|MEM_W,INY,ILLEGAL},
	{0xD4,"NOP",2,4,D_NONE,D_NONE,MEM_R,ZPX,ILLEGAL},
	{0xD5,"CMP",2,4,D_A,D_P,MEM_R,ZPX,LEGAL},
	{0xD6,"DEC",2,6,D_NONE,D_P,MEM_R|MEM_W,ZPX,LEGAL},
	{0xD7,"DCP",2,6,D_A,D_P,MEM_R|MEM_W,ZPX,ILLEGAL},
	{0xD8,"CLD",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0xD9,"CMP",3,4,D_A,D_P,MEM_R,ABY,LEGAL},
	{0xDA,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,ILLEGAL},
	{0xDB,"DCP",3,7,D_A,D_P,MEM_R|MEM_W,ABY,ILLEGAL},
	{0xDC,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABX,ILLEGAL},
	{0xDD,"CMP",3,4,D_A,D_P,MEM_R,ABX,LEGAL},
	{0xDE,"DEC",3,7,D_NONE,D_P,MEM_R|MEM_W,ABX,LEGAL},
	{0xDF,"DCP",3,7,D_A,D_P,MEM_R|MEM_W,ABX,ILLEGAL},
	{0xE0,"CPX",2,2,D_X,D_P,MEM_NONE,IMM,LEGAL},
	{0xE1,"SBC",2,6,D_A|D_P,D_A|D_P,MEM_R,INX,LEGAL},
	{0xE2,"NOP",2,2,D_NONE,D_NONE,MEM_NONE,IMM,ILLEGAL},
	{0xE3,"ISC",2,8,D_A|D_P,D_A|D_P,MEM_R|MEM_W,INX,ILLEGAL},
	{0xE4,"CPX",2,3,D_X,D_P,MEM_R,ZPG,LEGAL},
	{0xE5,"SBC",2,3,D_A|D_P,D_A|D_P,MEM_R,ZPG,LEGAL},
	{0xE6,"INC",2,5,D_NONE,D_P,MEM_R|MEM_W,ZPG,LEGAL},
	{0xE7,"ISC",2,5,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ZPG,ILLEGAL},
	{0xE8,"INX",1,2,D_X,D_X|D_P,MEM_NONE,IMP,LEGAL},
	{0xE9,"SBC",2,2,D_A|D_P,D_A|D_P,MEM_NONE,IMM,LEGAL},
	{0xEA,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,LEGAL},
	{0xEB,"SBC",2,2,D_A|D_P,D_A|D_P,MEM_NONE,IMM,ILLEGAL},
	{0xEC,"CPX",3,4,D_X,D_P,MEM_R,ABS,LEGAL},
	{0xED,"SBC",3,4,D_A|D_P,D_A|D_P,MEM_R,ABS,LEGAL},
	{0xEE,"INC",3,6,D_NONE,D_P,MEM_R|MEM_W,ABS,LEGAL},
	{0xEF,"ISC",3,6,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABS,ILLEGAL},
	{0xF0,"BEQ",2,2,D_NONE,D_NONE,MEM_NONE,REL,LEGAL},
	{0xF1,"SBC",2,5,D_A|D_P,D_A|D_P,MEM_R,INY,LEGAL},
	{0xF3,"ISC",2,8,D_A|D_P,D_A|D_P,MEM_R|MEM_W,INY,ILLEGAL},
	{0xF4,"NOP",2,4,D_NONE,D_NONE,MEM_R,ZPX,ILLEGAL},
	{0xF5,"SBC",2,4,D_A|D_P,D_A|D_P,MEM_R,ZPX,LEGAL},
	{0xF6,"INC",2,6,D_NONE,D_P,MEM_R|MEM_W,ZPX,LEGAL},
	{0xF7,"ISC",2,6,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ZPX,ILLEGAL},
	{0xF8,"SED",1,2,D_NONE,D_P,MEM_NONE,IMP,LEGAL},
	{0xF9,"SBC",3,4,D_A|D_P,D_A|D_P,MEM_R,ABY,LEGAL},
	{0xFA,"NOP",1,2,D_NONE,D_NONE,MEM_NONE,IMP,ILLEGAL},
	{0xFB,"ISC",3,7,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABY,ILLEGAL},
	{0xFC,"NOP",3,4,D_NONE,D_NONE,MEM_R,ABX,ILLEGAL},
	{0xFD,"SBC",3,4,D_A|D_P,D_A|D_P,MEM_R,ABX,LEGAL},
	{0xFE,"INC",3,7,D_NONE,D_P,MEM_R|MEM_W,ABX,LEGAL},
	{0xFF,"ISC",3,7,D_A|D_P,D_A|D_P,MEM_R|MEM_W,ABX,ILLEGAL},
};
