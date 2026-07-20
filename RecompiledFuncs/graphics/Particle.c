#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Particle_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800749A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800749A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800749A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800749AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800749B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800749B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800749B8: jal         0x80060814
    // 0x800749BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    FUN_026900_PRNG_1(rdram, ctx);
        goto after_0;
    // 0x800749BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800749C0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800749C4: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x800749C8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800749CC: mfhi        $s0
    ctx->r16 = hi;
    // 0x800749D0: addiu       $s0, $s0, 0xF
    ctx->r16 = ADD32(ctx->r16, 0XF);
    // 0x800749D4: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800749D8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800749DC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800749E0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800749E4: sh          $s0, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r16;
    // 0x800749E8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800749EC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800749F0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800749F4: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800749F8: jal         0x80060814
    // 0x800749FC: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    FUN_026900_PRNG_1(rdram, ctx);
        goto after_1;
    // 0x800749FC: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    after_1:
    // 0x80074A00: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80074A04: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80074A08: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80074A0C: divu        $zero, $v0, $t6
    lo = S32(U32(ctx->r2) / U32(ctx->r14)); hi = S32(U32(ctx->r2) % U32(ctx->r14));
    // 0x80074A10: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80074A14: bne         $t6, $zero, L_80074A20
    if (ctx->r14 != 0) {
        // 0x80074A18: nop
    
            goto L_80074A20;
    }
    // 0x80074A18: nop

    // 0x80074A1C: break       7
    do_break(2147961372);
L_80074A20:
    // 0x80074A20: mfhi        $t7
    ctx->r15 = hi;
    // 0x80074A24: subu        $s1, $t4, $t7
    ctx->r17 = SUB32(ctx->r12, ctx->r15);
    // 0x80074A28: negu        $t8, $s1
    ctx->r24 = SUB32(0, ctx->r17);
    // 0x80074A2C: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x80074A30: bne         $s0, $zero, L_80074A3C
    if (ctx->r16 != 0) {
        // 0x80074A34: nop
    
            goto L_80074A3C;
    }
    // 0x80074A34: nop

    // 0x80074A38: break       7
    do_break(2147961400);
L_80074A3C:
    // 0x80074A3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074A40: bne         $s0, $at, L_80074A54
    if (ctx->r16 != ctx->r1) {
        // 0x80074A44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80074A54;
    }
    // 0x80074A44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80074A48: bne         $t8, $at, L_80074A54
    if (ctx->r24 != ctx->r1) {
        // 0x80074A4C: nop
    
            goto L_80074A54;
    }
    // 0x80074A4C: nop

    // 0x80074A50: break       6
    do_break(2147961424);
L_80074A54:
    // 0x80074A54: mflo        $t9
    ctx->r25 = lo;
    // 0x80074A58: sh          $t9, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r25;
    // 0x80074A5C: jal         0x80060814
    // 0x80074A60: nop

    FUN_026900_PRNG_1(rdram, ctx);
        goto after_2;
    // 0x80074A60: nop

    after_2:
    // 0x80074A64: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80074A68: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x80074A6C: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80074A70: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80074A74: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80074A78: nop

    // 0x80074A7C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80074A80: nop

    // 0x80074A84: negu        $t4, $t6
    ctx->r12 = SUB32(0, ctx->r14);
    // 0x80074A88: div         $zero, $t4, $s0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r16)));
    // 0x80074A8C: bne         $s0, $zero, L_80074A98
    if (ctx->r16 != 0) {
        // 0x80074A90: nop
    
            goto L_80074A98;
    }
    // 0x80074A90: nop

    // 0x80074A94: break       7
    do_break(2147961492);
L_80074A98:
    // 0x80074A98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074A9C: bne         $s0, $at, L_80074AB0
    if (ctx->r16 != ctx->r1) {
        // 0x80074AA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80074AB0;
    }
    // 0x80074AA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80074AA4: bne         $t4, $at, L_80074AB0
    if (ctx->r12 != ctx->r1) {
        // 0x80074AA8: nop
    
            goto L_80074AB0;
    }
    // 0x80074AA8: nop

    // 0x80074AAC: break       6
    do_break(2147961516);
L_80074AB0:
    // 0x80074AB0: mflo        $t7
    ctx->r15 = lo;
    // 0x80074AB4: sh          $t7, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r15;
    // 0x80074AB8: jal         0x80060814
    // 0x80074ABC: nop

    FUN_026900_PRNG_1(rdram, ctx);
        goto after_3;
    // 0x80074ABC: nop

    after_3:
    // 0x80074AC0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80074AC4: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80074AC8: jal         0x80060814
    // 0x80074ACC: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    FUN_026900_PRNG_1(rdram, ctx);
        goto after_4;
    // 0x80074ACC: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    after_4:
    // 0x80074AD0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80074AD4: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x80074AD8: addiu       $t0, $t3, -0x200
    ctx->r8 = ADD32(ctx->r11, -0X200);
    // 0x80074ADC: jal         0x80060814
    // 0x80074AE0: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    FUN_026900_PRNG_1(rdram, ctx);
        goto after_5;
    // 0x80074AE0: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    after_5:
    // 0x80074AE4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80074AE8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80074AEC: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80074AF0: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x80074AF4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80074AF8: divu        $zero, $v0, $t6
    lo = S32(U32(ctx->r2) / U32(ctx->r14)); hi = S32(U32(ctx->r2) % U32(ctx->r14));
    // 0x80074AFC: bne         $t6, $zero, L_80074B08
    if (ctx->r14 != 0) {
        // 0x80074B00: nop
    
            goto L_80074B08;
    }
    // 0x80074B00: nop

    // 0x80074B04: break       7
    do_break(2147961604);
L_80074B08:
    // 0x80074B08: mfhi        $t4
    ctx->r12 = hi;
    // 0x80074B0C: sh          $t4, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r12;
    // 0x80074B10: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80074B14: nop

    // 0x80074B18: lh          $t8, 0xC($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XC);
    // 0x80074B1C: nop

    // 0x80074B20: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80074B24: div         $zero, $t9, $s0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r16)));
    // 0x80074B28: bne         $s0, $zero, L_80074B34
    if (ctx->r16 != 0) {
        // 0x80074B2C: nop
    
            goto L_80074B34;
    }
    // 0x80074B2C: nop

    // 0x80074B30: break       7
    do_break(2147961648);
L_80074B34:
    // 0x80074B34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074B38: bne         $s0, $at, L_80074B4C
    if (ctx->r16 != ctx->r1) {
        // 0x80074B3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80074B4C;
    }
    // 0x80074B3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80074B40: bne         $t9, $at, L_80074B4C
    if (ctx->r25 != ctx->r1) {
        // 0x80074B44: nop
    
            goto L_80074B4C;
    }
    // 0x80074B44: nop

    // 0x80074B48: break       6
    do_break(2147961672);
L_80074B4C:
    // 0x80074B4C: mflo        $t3
    ctx->r11 = lo;
    // 0x80074B50: sh          $t3, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r11;
    // 0x80074B54: jal         0x80060814
    // 0x80074B58: nop

    FUN_026900_PRNG_1(rdram, ctx);
        goto after_6;
    // 0x80074B58: nop

    after_6:
    // 0x80074B5C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80074B60: andi        $t0, $v0, 0x3F
    ctx->r8 = ctx->r2 & 0X3F;
    // 0x80074B64: addiu       $t1, $t0, -0x1F
    ctx->r9 = ADD32(ctx->r8, -0X1F);
    // 0x80074B68: sh          $t1, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r9;
    // 0x80074B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074B70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074B74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074B78: jr          $ra
    // 0x80074B7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074B7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Particle_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80074B88: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80074B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80074B94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80074B98: beq         $t6, $zero, L_80074C70
    if (ctx->r14 == 0) {
        // 0x80074B9C: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80074C70;
    }
    // 0x80074B9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
L_80074BA0:
    // 0x80074BA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80074BA4: nop

    // 0x80074BA8: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80074BAC: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80074BB0: nop

    // 0x80074BB4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80074BB8: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x80074BBC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80074BC0: nop

    // 0x80074BC4: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x80074BC8: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x80074BCC: nop

    // 0x80074BD0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80074BD4: sh          $t4, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r12;
    // 0x80074BD8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80074BDC: nop

    // 0x80074BE0: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80074BE4: lh          $t8, 0x6($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X6);
    // 0x80074BE8: nop

    // 0x80074BEC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80074BF0: sh          $t9, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r25;
    // 0x80074BF4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80074BF8: nop

    // 0x80074BFC: lhu         $t7, 0x8($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X8);
    // 0x80074C00: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x80074C04: nop

    // 0x80074C08: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80074C0C: sh          $t3, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r11;
    // 0x80074C10: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80074C14: nop

    // 0x80074C18: lhu         $t1, 0x12($t4)
    ctx->r9 = MEM_HU(ctx->r12, 0X12);
    // 0x80074C1C: nop

    // 0x80074C20: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x80074C24: sh          $t6, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r14;
    // 0x80074C28: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80074C2C: nop

    // 0x80074C30: lhu         $t9, 0x12($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X12);
    // 0x80074C34: nop

    // 0x80074C38: bne         $t9, $zero, L_80074C50
    if (ctx->r25 != 0) {
        // 0x80074C3C: nop
    
            goto L_80074C50;
    }
    // 0x80074C3C: nop

    // 0x80074C40: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80074C44: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80074C48: jal         0x800749A0
    // 0x80074C4C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    Particle_Spawn(rdram, ctx);
        goto after_0;
    // 0x80074C4C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
L_80074C50:
    // 0x80074C50: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80074C54: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80074C58: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80074C5C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80074C60: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80074C64: addiu       $t7, $t5, 0x14
    ctx->r15 = ADD32(ctx->r13, 0X14);
    // 0x80074C68: bne         $t0, $zero, L_80074BA0
    if (ctx->r8 != 0) {
        // 0x80074C6C: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_80074BA0;
    }
    // 0x80074C6C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_80074C70:
    // 0x80074C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074C78: jr          $ra
    // 0x80074C7C: nop

    return;
    // 0x80074C7C: nop

;}

RECOMP_FUNC void Particle_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074C84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80074C88: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80074C8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074C94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80074C98: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80074C9C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80074CA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074CA4: beq         $t6, $zero, L_80074D68
    if (ctx->r14 == 0) {
        // 0x80074CA8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074D68;
    }
    // 0x80074CA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074CAC:
    // 0x80074CAC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80074CB0: nop

    // 0x80074CB4: lhu         $a0, 0x8($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X8);
    // 0x80074CB8: jal         0x800B8010
    // 0x80074CBC: nop

    sins(rdram, ctx);
        goto after_0;
    // 0x80074CBC: nop

    after_0:
    // 0x80074CC0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80074CC4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80074CC8: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x80074CCC: lh          $s1, 0x4($t8)
    ctx->r17 = MEM_H(ctx->r24, 0X4);
    // 0x80074CD0: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074CD4: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80074CD8: sra         $t3, $s1, 8
    ctx->r11 = S32(SIGNED(ctx->r17) >> 8);
    // 0x80074CDC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80074CE0: mflo        $s0
    ctx->r16 = lo;
    // 0x80074CE4: sra         $t0, $s0, 23
    ctx->r8 = S32(SIGNED(ctx->r16) >> 23);
    // 0x80074CE8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80074CEC: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x80074CF0: bltz        $s0, L_80074D68
    if (SIGNED(ctx->r16) < 0) {
        // 0x80074CF4: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80074D68;
    }
    // 0x80074CF4: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80074CF8: beq         $at, $zero, L_80074D68
    if (ctx->r1 == 0) {
        // 0x80074CFC: nop
    
            goto L_80074D68;
    }
    // 0x80074CFC: nop

    // 0x80074D00: bltz        $s1, L_80074D68
    if (SIGNED(ctx->r17) < 0) {
        // 0x80074D04: nop
    
            goto L_80074D68;
    }
    // 0x80074D04: nop

    // 0x80074D08: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80074D0C: nop

    // 0x80074D10: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80074D14: beq         $at, $zero, L_80074D68
    if (ctx->r1 == 0) {
        // 0x80074D18: nop
    
            goto L_80074D68;
    }
    // 0x80074D18: nop

    // 0x80074D1C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80074D20: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80074D24: multu       $s1, $t0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074D28: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80074D2C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80074D30: nop

    // 0x80074D34: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80074D38: mflo        $t2
    ctx->r10 = lo;
    // 0x80074D3C: addu        $t8, $s0, $t2
    ctx->r24 = ADD32(ctx->r16, ctx->r10);
    // 0x80074D40: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x80074D44: sb          $t7, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r15;
    // 0x80074D48: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80074D4C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80074D50: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80074D54: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80074D58: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80074D5C: addiu       $t4, $t1, 0x14
    ctx->r12 = ADD32(ctx->r9, 0X14);
    // 0x80074D60: bne         $t0, $zero, L_80074CAC
    if (ctx->r8 != 0) {
        // 0x80074D64: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_80074CAC;
    }
    // 0x80074D64: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_80074D68:
    // 0x80074D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074D6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074D70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074D74: jr          $ra
    // 0x80074D78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074D78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
