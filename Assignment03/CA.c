#include <stdio.h>

int main() {
    // �Է°��� 16������ �޾ƿɴϴ�.
    unsigned int instruction;
    scanf("%x", &instruction);

    // ��ɾ� �ʵ� ����
    unsigned int opcode = instruction & 0x7F;
    unsigned int rd = (instruction >> 7) & 0x1F;
    unsigned int funct3 = (instruction >> 12) & 0x7;
    unsigned int rs1 = (instruction >> 15) & 0x1F;
    unsigned int rs2 = (instruction >> 20) & 0x1F;
    unsigned int funct7 = (instruction >> 25) & 0x7F;
    int imm = ((instruction >> 7) & 0x1F) | ((instruction >> 25) & 0x7F) << 5;

    // �˻� �� ���
    if (opcode == 0b0000011) {
        // I ������ lw ��ɾ�
        if (funct3 == 0b010) {
            printf("lw x%d,%d(x%d)\n", rd, imm, rs1);
        }
    }
    else if (opcode == 0b0010011) {
        // I ������ addi ��ɾ�
        if (funct3 == 0b000) {
            printf("addi x%d,x%d,%d\n", rd, rs1, imm);
        }
    }
    else if (opcode == 0b0100011) {
        // S ������ sw ��ɾ�
        if (funct3 == 0b010) {
            // Offset ��ȣ Ȯ��
            if (imm & 0x1000) {
                imm |= 0xFFFFE000;
            }
            printf("sw x%d,%d(x%d)\n", rs2, imm, rs1);
        }
    }
    else if (opcode == 0b0110011) {
        // R ������ ��ɾ�
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
        // SB ������ beq ��ɾ�
        if (funct3 == 0b000) {
            // Offset ��ȣ Ȯ��
            if (imm & 0x1000) {
                imm |= 0xFFFFE000;
            }
            printf("beq x%d,x%d,%d\n", rs1, rs2, imm);
        }
    }
    else {
        printf("�ش� ��ɾ�� �������� �ʽ��ϴ�.\n");
    }

    return 0;
}

