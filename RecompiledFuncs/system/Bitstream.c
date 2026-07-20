#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Bitstream_WriteBits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B8A8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8007B8AC: nop

    // 0x8007B8B0: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B8B4: bne         $at, $zero, L_8007B938
    if (ctx->r1 != 0) {
        // 0x8007B8B8: nop
    
            goto L_8007B938;
    }
    // 0x8007B8B8: nop

L_8007B8BC:
    // 0x8007B8BC: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8007B8C0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8007B8C4: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8007B8C8: subu        $t1, $a2, $t0
    ctx->r9 = SUB32(ctx->r6, ctx->r8);
    // 0x8007B8CC: srav        $t2, $a1, $t1
    ctx->r10 = S32(SIGNED(ctx->r5) >> (ctx->r9 & 31));
    // 0x8007B8D0: sllv        $t9, $t7, $t8
    ctx->r25 = S32(ctx->r15 << (ctx->r24 & 31));
    // 0x8007B8D4: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8007B8D8: lw          $t5, 0xC($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XC);
    // 0x8007B8DC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8007B8E0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007B8E4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8007B8E8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8007B8EC: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
    // 0x8007B8F0: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8007B8F4: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8007B8F8: subu        $t9, $a2, $t1
    ctx->r25 = SUB32(ctx->r6, ctx->r9);
    // 0x8007B8FC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8007B900: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007B904: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8007B908: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8007B90C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007B910: lw          $t3, 0x2F40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2F40);
    // 0x8007B914: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007B918: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8007B91C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007B920: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x8007B924: subu        $a2, $a2, $t5
    ctx->r6 = SUB32(ctx->r6, ctx->r13);
    // 0x8007B928: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007B92C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8007B930: beq         $at, $zero, L_8007B8BC
    if (ctx->r1 == 0) {
        // 0x8007B934: and         $a1, $a1, $t3
        ctx->r5 = ctx->r5 & ctx->r11;
            goto L_8007B8BC;
    }
    // 0x8007B934: and         $a1, $a1, $t3
    ctx->r5 = ctx->r5 & ctx->r11;
L_8007B938:
    // 0x8007B938: blez        $a2, L_8007B95C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007B93C: nop
    
            goto L_8007B95C;
    }
    // 0x8007B93C: nop

    // 0x8007B940: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8007B944: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8007B948: sllv        $t8, $t7, $a2
    ctx->r24 = S32(ctx->r15 << (ctx->r6 & 31));
    // 0x8007B94C: or          $t0, $t8, $a1
    ctx->r8 = ctx->r24 | ctx->r5;
    // 0x8007B950: subu        $t9, $t1, $a2
    ctx->r25 = SUB32(ctx->r9, ctx->r6);
    // 0x8007B954: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8007B958: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_8007B95C:
    // 0x8007B95C: jr          $ra
    // 0x8007B960: nop

    return;
    // 0x8007B960: nop

;}

RECOMP_FUNC void Bitstream_ReadBits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B964: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007B968: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8007B96C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8007B970: nop

    // 0x8007B974: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007B978: beq         $at, $zero, L_8007B9D8
    if (ctx->r1 == 0) {
        // 0x8007B97C: nop
    
            goto L_8007B9D8;
    }
    // 0x8007B97C: nop

L_8007B980:
    // 0x8007B980: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8007B984: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8007B988: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8007B98C: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x8007B990: sllv        $t0, $t7, $t9
    ctx->r8 = S32(ctx->r15 << (ctx->r25 & 31));
    // 0x8007B994: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x8007B998: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8007B99C: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
    // 0x8007B9A0: lw          $t5, 0xC($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XC);
    // 0x8007B9A4: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8007B9A8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007B9AC: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8007B9B0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8007B9B4: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x8007B9B8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8007B9BC: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8007B9C0: subu        $a1, $a1, $t3
    ctx->r5 = SUB32(ctx->r5, ctx->r11);
    // 0x8007B9C4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8007B9C8: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007B9CC: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007B9D0: bne         $at, $zero, L_8007B980
    if (ctx->r1 != 0) {
        // 0x8007B9D4: sw          $t8, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r24;
            goto L_8007B980;
    }
    // 0x8007B9D4: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
L_8007B9D8:
    // 0x8007B9D8: blez        $a1, L_8007BA2C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007B9DC: nop
    
            goto L_8007BA2C;
    }
    // 0x8007B9DC: nop

    // 0x8007B9E0: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8007B9E4: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x8007B9E8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007B9EC: subu        $t4, $t3, $a1
    ctx->r12 = SUB32(ctx->r11, ctx->r5);
    // 0x8007B9F0: srav        $t5, $t2, $t4
    ctx->r13 = S32(SIGNED(ctx->r10) >> (ctx->r12 & 31));
    // 0x8007B9F4: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x8007B9F8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8007B9FC: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x8007BA00: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007BA04: subu        $t1, $t9, $a1
    ctx->r9 = SUB32(ctx->r25, ctx->r5);
    // 0x8007BA08: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8007BA0C: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8007BA10: lw          $t3, 0x2F40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2F40);
    // 0x8007BA14: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8007BA18: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x8007BA1C: and         $t2, $t7, $t3
    ctx->r10 = ctx->r15 & ctx->r11;
    // 0x8007BA20: subu        $t6, $t4, $a1
    ctx->r14 = SUB32(ctx->r12, ctx->r5);
    // 0x8007BA24: sw          $t2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r10;
    // 0x8007BA28: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
L_8007BA2C:
    // 0x8007BA2C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8007BA30: jr          $ra
    // 0x8007BA34: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8007BA34: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void Bitstream_Flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BA38: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8007BA3C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007BA40: beq         $t6, $at, L_8007BA7C
    if (ctx->r14 == ctx->r1) {
        // 0x8007BA44: nop
    
            goto L_8007BA7C;
    }
    // 0x8007BA44: nop

    // 0x8007BA48: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8007BA4C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8007BA50: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x8007BA54: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8007BA58: sllv        $t9, $t7, $t8
    ctx->r25 = S32(ctx->r15 << (ctx->r24 & 31));
    // 0x8007BA5C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007BA60: sb          $t9, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r25;
    // 0x8007BA64: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8007BA68: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8007BA6C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007BA70: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x8007BA74: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8007BA78: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_8007BA7C:
    // 0x8007BA7C: jr          $ra
    // 0x8007BA80: nop

    return;
    // 0x8007BA80: nop

;}
