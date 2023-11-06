#include <stdio.h>

int main() {
    // 입력값을 16진수로 받아옵니다.
    unsigned int instruction;
    scanf("%x", &instruction);

    // 명령어 필드 추출
    unsigned int opcode = instruction & 0x7F;
    unsigned int rd = (instruction >> 7) & 0x1F;
    unsigned int funct3 = (instruction >> 12) & 0x7;
    unsigned int rs1 = (instruction >> 15) & 0x1F;
    unsigned int rs2 = (instruction >> 20) & 0x1F;
    unsigned int funct7 = (instruction >> 25) & 0x7F;
    int imm = ((instruction >> 7) & 0x1F) | ((instruction >> 25) & 0x7F) << 5;

    // 검사 및 출력
    if (opcode == 0b0000011) {
        // I 형식의 lw 명령어
        if (funct3 == 0b010) {
            printf("lw x%d,%d(x%d)\n", rd, imm, rs1);
        }
    }
    else if (opcode == 0b0010011) {
        // I 형식의 addi 명령어
        if (funct3 == 0b000) {
            printf("addi x%d,x%d,%d\n", rd, rs1, imm);
        }
    }
    else if (opcode == 0b0100011) {
        // S 형식의 sw 명령어
        if (funct3 == 0b010) {
            // Offset 부호 확장
            if (imm & 0x1000) {
                imm |= 0xFFFFE000;
            }
            printf("sw x%d,%d(x%d)\n", rs2, imm, rs1);
        }
    }
    else if (opcode == 0b0110011) {
        // R 형식의 명령어
        if (funct3 == 0b000) {
            if (funct7 == 0b0000000) {
                printf("add x%d,x%d,x%d\n", rd, rs1, rs2);
            }
            else if (funct7 == 0b0100000) {
                printf("sub x%d,x%d,x%d\n", rd, rs1, rs2);
            }
        }
        else if (funct3 == 0b111 && funct7 == 0b0000000) {
            printf("and x%d,x%d,x%d\n", rd, rs1, rs2);
        }
    }
    else if (opcode == 0b1100011) {
        // SB 형식의 beq 명령어
        if (funct3 == 0b000) {
            // Offset 부호 확장
            if (imm & 0x1000) {
                imm |= 0xFFFFE000;
            }
            printf("beq x%d,x%d,%d\n", rs1, rs2, imm);
        }
    }
    else {
        printf("해당 명령어는 지원하지 않습니다.\n");
    }

    return 0;
}

