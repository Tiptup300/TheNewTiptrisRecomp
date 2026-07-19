#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void FallingCubes_Drop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006EF44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006EF48: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006EF4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EF50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EF54: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8006EF58: nop

    // 0x8006EF5C: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x8006EF60: nop

    // 0x8006EF64: addiu       $t8, $t7, 0x80
    ctx->r24 = ADD32(ctx->r15, 0X80);
    // 0x8006EF68: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
    // 0x8006EF6C: lwl         $at, 0x8($s0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r16, 0X8);
    // 0x8006EF70: lwr         $at, 0xB($s0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r16, 0XB);
    // 0x8006EF74: lh          $t1, 0xA($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XA);
    // 0x8006EF78: swl         $at, 0x1A($s0)
    do_swl(rdram, 0X1A, ctx->r16, ctx->r1);
    // 0x8006EF7C: swr         $at, 0x1D($s0)
    do_swr(rdram, 0X1D, ctx->r16, ctx->r1);
    // 0x8006EF80: lhu         $at, 0xC($s0)
    ctx->r1 = MEM_HU(ctx->r16, 0XC);
    // 0x8006EF84: nop

    // 0x8006EF88: sh          $at, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r1;
    // 0x8006EF8C: slti        $at, $t1, 0x1601
    ctx->r1 = SIGNED(ctx->r9) < 0X1601 ? 1 : 0;
    // 0x8006EF90: bne         $at, $zero, L_8006EFDC
    if (ctx->r1 != 0) {
        // 0x8006EF94: nop
    
            goto L_8006EFDC;
    }
    // 0x8006EF94: nop

    // 0x8006EF98: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8006EF9C: nop

    // 0x8006EFA0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8006EFA4: jal         0x8006EE10
    // 0x8006EFA8: nop

    MobileCubes_Unalloc(rdram, ctx);
        goto after_0;
    // 0x8006EFA8: nop

    after_0:
    // 0x8006EFAC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8006EFB0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006EFB4: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8006EFB8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8006EFBC: nop

    // 0x8006EFC0: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8006EFC4: lw          $t5, -0x400($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X400);
    // 0x8006EFC8: nop

    // 0x8006EFCC: lbu         $t6, 0x5($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5);
    // 0x8006EFD0: nop

    // 0x8006EFD4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006EFD8: sb          $t7, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r15;
L_8006EFDC:
    // 0x8006EFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EFE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006EFE4: jr          $ra
    // 0x8006EFE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006EFE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FallingCubes_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006EFF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EFF4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006EFF8: lw          $s0, -0x400($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X400);
    // 0x8006EFFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F000: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F004: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F008: lbu         $s2, 0x5($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X5);
    // 0x8006F00C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006F010: beq         $s2, $zero, L_8006F04C
    if (ctx->r18 == 0) {
        // 0x8006F014: nop
    
            goto L_8006F04C;
    }
    // 0x8006F014: nop

L_8006F018:
    // 0x8006F018: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006F01C: nop

    // 0x8006F020: beq         $t6, $zero, L_8006F044
    if (ctx->r14 == 0) {
        // 0x8006F024: nop
    
            goto L_8006F044;
    }
    // 0x8006F024: nop

    // 0x8006F028: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F02C: lbu         $a1, 0x6($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X6);
    // 0x8006F030: jal         0x800709D8
    // 0x8006F034: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_SetBrightness(rdram, ctx);
        goto after_0;
    // 0x8006F034: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8006F038: jal         0x8006EF40
    // 0x8006F03C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    FallingCubes_Drop(rdram, ctx);
        goto after_1;
    // 0x8006F03C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8006F040: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8006F044:
    // 0x8006F044: bne         $s2, $zero, L_8006F018
    if (ctx->r18 != 0) {
        // 0x8006F048: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006F018;
    }
    // 0x8006F048: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8006F04C:
    // 0x8006F04C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F054: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F058: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F05C: jr          $ra
    // 0x8006F060: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006F060: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void FallingCubes_SetAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F064: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F068: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006F06C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006F070: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x8006F074: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8006F078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F07C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006F080: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006F084: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
    // 0x8006F088: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006F08C: nop

    // 0x8006F090: lbu         $s0, 0x5($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X5);
    // 0x8006F094: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8006F098: blez        $s0, L_8006F0CC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006F09C: nop
    
            goto L_8006F0CC;
    }
    // 0x8006F09C: nop

L_8006F0A0:
    // 0x8006F0A0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006F0A4: nop

    // 0x8006F0A8: beq         $t9, $zero, L_8006F0C4
    if (ctx->r25 == 0) {
        // 0x8006F0AC: nop
    
            goto L_8006F0C4;
    }
    // 0x8006F0AC: nop

    // 0x8006F0B0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F0B4: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x8006F0B8: jal         0x800709D8
    // 0x8006F0BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    Minos_Mino_SetBrightness(rdram, ctx);
        goto after_0;
    // 0x8006F0BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8006F0C0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8006F0C4:
    // 0x8006F0C4: bgtz        $s0, L_8006F0A0
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006F0C8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006F0A0;
    }
    // 0x8006F0C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8006F0CC:
    // 0x8006F0CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F0D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006F0D8: jr          $ra
    // 0x8006F0DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F0DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void FallingCubes_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006F0E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F0E8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006F0EC: lw          $s0, -0x400($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X400);
    // 0x8006F0F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F0F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F0F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F0FC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006F100: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006F104: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006F108: nop

    // 0x8006F10C: beq         $t6, $zero, L_8006F14C
    if (ctx->r14 == 0) {
        // 0x8006F110: nop
    
            goto L_8006F14C;
    }
    // 0x8006F110: nop

    // 0x8006F114: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x8006F118: nop

    // 0x8006F11C: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006F120: beq         $at, $zero, L_8006F14C
    if (ctx->r1 == 0) {
        // 0x8006F124: nop
    
            goto L_8006F14C;
    }
    // 0x8006F124: nop

L_8006F128:
    // 0x8006F128: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8006F12C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006F130: beq         $t8, $zero, L_8006F14C
    if (ctx->r24 == 0) {
        // 0x8006F134: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006F14C;
    }
    // 0x8006F134: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006F138: lbu         $t9, 0x4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4);
    // 0x8006F13C: nop

    // 0x8006F140: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8006F144: bne         $at, $zero, L_8006F128
    if (ctx->r1 != 0) {
        // 0x8006F148: nop
    
            goto L_8006F128;
    }
    // 0x8006F148: nop

L_8006F14C:
    // 0x8006F14C: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
    // 0x8006F150: nop

    // 0x8006F154: bne         $t0, $s2, L_8006F170
    if (ctx->r8 != ctx->r18) {
        // 0x8006F158: nop
    
            goto L_8006F170;
    }
    // 0x8006F158: nop

    // 0x8006F15C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F160: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006F164: addiu       $a1, $a1, -0x26E8
    ctx->r5 = ADD32(ctx->r5, -0X26E8);
    // 0x8006F168: jal         0x80083560
    // 0x8006F16C: addiu       $a0, $a0, -0x2700
    ctx->r4 = ADD32(ctx->r4, -0X2700);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006F16C: addiu       $a0, $a0, -0x2700
    ctx->r4 = ADD32(ctx->r4, -0X2700);
    after_0:
L_8006F170:
    // 0x8006F170: lbu         $t1, 0x5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X5);
    // 0x8006F174: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8006F178: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8006F17C: sb          $t2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r10;
    // 0x8006F180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F184: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F188: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F18C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F190: jr          $ra
    // 0x8006F194: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006F194: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void FallingCubes_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F198: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006F19C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F1A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006F1A4: lw          $s0, -0x400($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X400);
    // 0x8006F1A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F1AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006F1B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F1B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F1B8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8006F1BC: sb          $t6, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r14;
    // 0x8006F1C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006F1C4: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8006F1C8: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
    // 0x8006F1CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8006F1D0: nop

    // 0x8006F1D4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006F1D8: jal         0x8007E03C
    // 0x8006F1DC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8006F1DC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8006F1E0: lbu         $s1, 0x4($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X4);
    // 0x8006F1E4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006F1E8: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x8006F1EC: blez        $s1, L_8006F204
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006F1F0: nop
    
            goto L_8006F204;
    }
    // 0x8006F1F0: nop

L_8006F1F4:
    // 0x8006F1F4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006F1F8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006F1FC: bgtz        $s1, L_8006F1F4
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006F200: sw          $zero, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = 0;
            goto L_8006F1F4;
    }
    // 0x8006F200: sw          $zero, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = 0;
L_8006F204:
    // 0x8006F204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F20C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F210: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F214: jr          $ra
    // 0x8006F218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006F218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void FallingCubes_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F21C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F224: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006F228: lw          $s0, -0x400($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X400);
    // 0x8006F22C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F230: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006F234: jal         0x8007E328
    // 0x8006F238: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x8006F238: nop

    after_0:
    // 0x8006F23C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8006F240: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x8006F244: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8006F248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F24C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F250: jr          $ra
    // 0x8006F254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006F258: nop

    // 0x8006F25C: nop

;}
