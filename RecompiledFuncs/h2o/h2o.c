#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void h2oRaw16Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D770: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008D774: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8008D778: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8008D77C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008D780: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8008D784: beq         $a0, $zero, L_8008D7A4
    if (ctx->r4 == 0) {
        // 0x8008D788: sw          $t6, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r14;
            goto L_8008D7A4;
    }
    // 0x8008D788: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8008D78C: beq         $a1, $zero, L_8008D7A4
    if (ctx->r5 == 0) {
        // 0x8008D790: nop
    
            goto L_8008D7A4;
    }
    // 0x8008D790: nop

    // 0x8008D794: beq         $a2, $zero, L_8008D7A4
    if (ctx->r6 == 0) {
        // 0x8008D798: nop
    
            goto L_8008D7A4;
    }
    // 0x8008D798: nop

    // 0x8008D79C: bne         $t6, $zero, L_8008D7B0
    if (ctx->r14 != 0) {
        // 0x8008D7A0: nop
    
            goto L_8008D7B0;
    }
    // 0x8008D7A0: nop

L_8008D7A4:
    // 0x8008D7A4: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D7A8: b           L_8008DD10
    // 0x8008D7AC: nop

        goto L_8008DD10;
    // 0x8008D7AC: nop

L_8008D7B0:
    // 0x8008D7B0: bne         $a2, $zero, L_8008D7C4
    if (ctx->r6 != 0) {
        // 0x8008D7B4: nop
    
            goto L_8008D7C4;
    }
    // 0x8008D7B4: nop

    // 0x8008D7B8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D7BC: b           L_8008DD10
    // 0x8008D7C0: nop

        goto L_8008DD10;
    // 0x8008D7C0: nop

L_8008D7C4:
    // 0x8008D7C4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008D7C8: nop

    // 0x8008D7CC: lw          $t8, 0x38($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X38);
    // 0x8008D7D0: lw          $t0, 0x20($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X20);
    // 0x8008D7D4: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8008D7D8: sltu        $at, $t0, $t9
    ctx->r1 = ctx->r8 < ctx->r25 ? 1 : 0;
    // 0x8008D7DC: beq         $at, $zero, L_8008DB20
    if (ctx->r1 == 0) {
        // 0x8008D7E0: nop
    
            goto L_8008DB20;
    }
    // 0x8008D7E0: nop

    // 0x8008D7E4: lw          $t1, 0x24($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X24);
    // 0x8008D7E8: nop

    // 0x8008D7EC: beq         $t1, $zero, L_8008DB20
    if (ctx->r9 == 0) {
        // 0x8008D7F0: nop
    
            goto L_8008DB20;
    }
    // 0x8008D7F0: nop

    // 0x8008D7F4: subu        $t2, $t0, $t8
    ctx->r10 = SUB32(ctx->r8, ctx->r24);
    // 0x8008D7F8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008D7FC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8008D800: blez        $t2, L_8008D8A0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8008D804: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_8008D8A0;
    }
    // 0x8008D804: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8008D808: lw          $t4, 0x44($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X44);
    // 0x8008D80C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D810: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D814: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x8008D818: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8008D81C: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x8008D820: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x8008D824: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8008D828: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8008D82C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8008D830: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8008D834: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8008D838: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8008D83C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8008D840: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8008D844: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x8008D848: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x8008D84C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8008D850: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008D854: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008D858: andi        $t3, $t5, 0x7
    ctx->r11 = ctx->r13 & 0X7;
    // 0x8008D85C: subu        $t6, $t5, $t3
    ctx->r14 = SUB32(ctx->r13, ctx->r11);
    // 0x8008D860: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8008D864: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x8008D868: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x8008D86C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D870: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8008D874: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8008D878: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D87C: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8008D880: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8008D884: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8008D888: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008D88C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008D890: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D894: subu        $t6, $t5, $t3
    ctx->r14 = SUB32(ctx->r13, ctx->r11);
    // 0x8008D898: b           L_8008D8A4
    // 0x8008D89C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
        goto L_8008D8A4;
    // 0x8008D89C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_8008D8A0:
    // 0x8008D8A0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008D8A4:
    // 0x8008D8A4: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x8008D8A8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008D8AC: nop

    // 0x8008D8B0: addu        $t8, $t1, $t0
    ctx->r24 = ADD32(ctx->r9, ctx->r8);
    // 0x8008D8B4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8008D8B8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008D8BC: nop

    // 0x8008D8C0: lw          $t7, 0x28($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X28);
    // 0x8008D8C4: lw          $t5, 0x1C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X1C);
    // 0x8008D8C8: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x8008D8CC: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x8008D8D0: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8008D8D4: sw          $t6, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r14;
    // 0x8008D8D8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008D8DC: nop

    // 0x8008D8E0: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x8008D8E4: nop

    // 0x8008D8E8: sw          $t1, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r9;
    // 0x8008D8EC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008D8F0: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8008D8F4: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008D8F8: beq         $at, $zero, L_8008DAE4
    if (ctx->r1 == 0) {
        // 0x8008D8FC: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_8008DAE4;
    }
    // 0x8008D8FC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_8008D900:
    // 0x8008D900: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8008D904: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D908: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8008D90C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008D910: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x8008D914: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8008D918: lw          $t2, 0x24($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X24);
    // 0x8008D91C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008D920: beq         $t2, $at, L_8008D938
    if (ctx->r10 == ctx->r1) {
        // 0x8008D924: subu        $a2, $a2, $t5
        ctx->r6 = SUB32(ctx->r6, ctx->r13);
            goto L_8008D938;
    }
    // 0x8008D924: subu        $a2, $a2, $t5
    ctx->r6 = SUB32(ctx->r6, ctx->r13);
    // 0x8008D928: beq         $t2, $zero, L_8008D938
    if (ctx->r10 == 0) {
        // 0x8008D92C: nop
    
            goto L_8008D938;
    }
    // 0x8008D92C: nop

    // 0x8008D930: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x8008D934: sw          $t1, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r9;
L_8008D938:
    // 0x8008D938: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008D93C: nop

    // 0x8008D940: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8008D944: lw          $t8, 0x1C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X1C);
    // 0x8008D948: nop

    // 0x8008D94C: subu        $t7, $t0, $t8
    ctx->r15 = SUB32(ctx->r8, ctx->r24);
    // 0x8008D950: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x8008D954: beq         $at, $zero, L_8008D964
    if (ctx->r1 == 0) {
        // 0x8008D958: nop
    
            goto L_8008D964;
    }
    // 0x8008D958: nop

    // 0x8008D95C: b           L_8008D980
    // 0x8008D960: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
        goto L_8008D980;
    // 0x8008D960: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
L_8008D964:
    // 0x8008D964: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008D968: nop

    // 0x8008D96C: lw          $t3, 0x20($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X20);
    // 0x8008D970: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x8008D974: nop

    // 0x8008D978: subu        $t2, $t3, $t5
    ctx->r10 = SUB32(ctx->r11, ctx->r13);
    // 0x8008D97C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_8008D980:
    // 0x8008D980: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8008D984: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008D988: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x8008D98C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8008D990: lw          $t0, 0x44($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X44);
    // 0x8008D994: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D998: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D99C: addu        $t8, $t0, $at
    ctx->r24 = ADD32(ctx->r8, ctx->r1);
    // 0x8008D9A0: andi        $t7, $t8, 0x7
    ctx->r15 = ctx->r24 & 0X7;
    // 0x8008D9A4: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8008D9A8: andi        $t5, $t3, 0x7
    ctx->r13 = ctx->r11 & 0X7;
    // 0x8008D9AC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008D9B0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8008D9B4: beq         $t5, $zero, L_8008D9CC
    if (ctx->r13 == 0) {
        // 0x8008D9B8: sw          $t4, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r12;
            goto L_8008D9CC;
    }
    // 0x8008D9B8: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8008D9BC: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8008D9C0: subu        $t1, $t2, $t5
    ctx->r9 = SUB32(ctx->r10, ctx->r13);
    // 0x8008D9C4: b           L_8008D9D0
    // 0x8008D9C8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
        goto L_8008D9D0;
    // 0x8008D9C8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_8008D9CC:
    // 0x8008D9CC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_8008D9D0:
    // 0x8008D9D0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D9D4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D9D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008D9DC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008D9E0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8008D9E4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8008D9E8: andi        $t4, $t7, 0xFFFF
    ctx->r12 = ctx->r15 & 0XFFFF;
    // 0x8008D9EC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8008D9F0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8008D9F4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8008D9F8: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x8008D9FC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8008DA00: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008DA04: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008DA08: andi        $t1, $t5, 0x7
    ctx->r9 = ctx->r13 & 0X7;
    // 0x8008DA0C: subu        $t9, $t5, $t1
    ctx->r25 = SUB32(ctx->r13, ctx->r9);
    // 0x8008DA10: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8008DA14: andi        $t8, $t0, 0xFFFF
    ctx->r24 = ctx->r8 & 0XFFFF;
    // 0x8008DA18: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8008DA1C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DA20: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x8008DA24: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8008DA28: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8008DA2C: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8008DA30: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8008DA34: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8008DA38: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008DA3C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008DA40: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8008DA44: subu        $t9, $t5, $t1
    ctx->r25 = SUB32(ctx->r13, ctx->r9);
    // 0x8008DA48: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8008DA4C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008DA50: nop

    // 0x8008DA54: bne         $t8, $zero, L_8008DA6C
    if (ctx->r24 != 0) {
        // 0x8008DA58: nop
    
            goto L_8008DA6C;
    }
    // 0x8008DA58: nop

    // 0x8008DA5C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DA60: nop

    // 0x8008DA64: beq         $t6, $zero, L_8008DAD0
    if (ctx->r14 == 0) {
        // 0x8008DA68: nop
    
            goto L_8008DAD0;
    }
    // 0x8008DA68: nop

L_8008DA6C:
    // 0x8008DA6C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DA70: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008DA74: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DA78: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DA7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008DA80: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x8008DA84: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8008DA88: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x8008DA8C: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8008DA90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008DA94: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8008DA98: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8008DA9C: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8008DAA0: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8008DAA4: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x8008DAA8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8008DAAC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8008DAB0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DAB4: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8008DAB8: andi        $t4, $t7, 0xFFFF
    ctx->r12 = ctx->r15 & 0XFFFF;
    // 0x8008DABC: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x8008DAC0: sll         $t3, $t4, 16
    ctx->r11 = S32(ctx->r12 << 16);
    // 0x8008DAC4: andi        $t1, $t5, 0xFFFF
    ctx->r9 = ctx->r13 & 0XFFFF;
    // 0x8008DAC8: or          $t9, $t3, $t1
    ctx->r25 = ctx->r11 | ctx->r9;
    // 0x8008DACC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_8008DAD0:
    // 0x8008DAD0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008DAD4: nop

    // 0x8008DAD8: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008DADC: bne         $at, $zero, L_8008D900
    if (ctx->r1 != 0) {
        // 0x8008DAE0: nop
    
            goto L_8008D900;
    }
    // 0x8008DAE0: nop

L_8008DAE4:
    // 0x8008DAE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008DAE8: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x8008DAEC: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x8008DAF0: nop

    // 0x8008DAF4: addu        $t4, $t7, $a2
    ctx->r12 = ADD32(ctx->r15, ctx->r6);
    // 0x8008DAF8: sw          $t4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r12;
    // 0x8008DAFC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008DB00: nop

    // 0x8008DB04: lw          $t5, 0x44($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X44);
    // 0x8008DB08: nop

    // 0x8008DB0C: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8008DB10: sw          $t1, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r9;
    // 0x8008DB14: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DB18: b           L_8008DD10
    // 0x8008DB1C: nop

        goto L_8008DD10;
    // 0x8008DB1C: nop

L_8008DB20:
    // 0x8008DB20: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x8008DB24: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8008DB28: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8008DB2C: lw          $t6, 0x28($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X28);
    // 0x8008DB30: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8008DB34: lw          $t8, 0x44($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X44);
    // 0x8008DB38: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x8008DB3C: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8008DB40: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x8008DB44: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8008DB48: subu        $t2, $t4, $t1
    ctx->r10 = SUB32(ctx->r12, ctx->r9);
    // 0x8008DB4C: bgez        $t2, L_8008DB58
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8008DB50: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_8008DB58;
    }
    // 0x8008DB50: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8008DB54: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8008DB58:
    // 0x8008DB58: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008DB5C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008DB60: nop

    // 0x8008DB64: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008DB68: beq         $at, $zero, L_8008DB74
    if (ctx->r1 == 0) {
        // 0x8008DB6C: nop
    
            goto L_8008DB74;
    }
    // 0x8008DB6C: nop

    // 0x8008DB70: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_8008DB74:
    // 0x8008DB74: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008DB78: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8008DB7C: nop

    // 0x8008DB80: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008DB84: beq         $at, $zero, L_8008DC84
    if (ctx->r1 == 0) {
        // 0x8008DB88: nop
    
            goto L_8008DC84;
    }
    // 0x8008DB88: nop

    // 0x8008DB8C: blez        $a2, L_8008DC38
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DB90: nop
    
            goto L_8008DC38;
    }
    // 0x8008DB90: nop

    // 0x8008DB94: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8008DB98: subu        $t6, $t0, $t7
    ctx->r14 = SUB32(ctx->r8, ctx->r15);
    // 0x8008DB9C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8008DBA0: lw          $t3, 0x44($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X44);
    // 0x8008DBA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DBA8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DBAC: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x8008DBB0: andi        $t1, $t4, 0x7
    ctx->r9 = ctx->r12 & 0X7;
    // 0x8008DBB4: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x8008DBB8: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8008DBBC: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8008DBC0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8008DBC4: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8008DBC8: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8008DBCC: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8008DBD0: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8008DBD4: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8008DBD8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8008DBDC: andi        $t7, $t0, 0xFFFF
    ctx->r15 = ctx->r8 & 0XFFFF;
    // 0x8008DBE0: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x8008DBE4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8008DBE8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8008DBEC: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008DBF0: andi        $t6, $t4, 0x7
    ctx->r14 = ctx->r12 & 0X7;
    // 0x8008DBF4: subu        $t1, $t4, $t6
    ctx->r9 = SUB32(ctx->r12, ctx->r14);
    // 0x8008DBF8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8008DBFC: andi        $t9, $t2, 0xFFFF
    ctx->r25 = ctx->r10 & 0XFFFF;
    // 0x8008DC00: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8008DC04: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DC08: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8008DC0C: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x8008DC10: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8008DC14: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x8008DC18: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8008DC1C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8008DC20: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008DC24: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8008DC28: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008DC2C: subu        $t1, $t4, $t6
    ctx->r9 = SUB32(ctx->r12, ctx->r14);
    // 0x8008DC30: b           L_8008DC3C
    // 0x8008DC34: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_8008DC3C;
    // 0x8008DC34: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_8008DC38:
    // 0x8008DC38: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008DC3C:
    // 0x8008DC3C: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8008DC40: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008DC44: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x8008DC48: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x8008DC4C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8008DC50: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008DC54: nop

    // 0x8008DC58: lw          $t5, 0x38($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X38);
    // 0x8008DC5C: nop

    // 0x8008DC60: addu        $t3, $t5, $a2
    ctx->r11 = ADD32(ctx->r13, ctx->r6);
    // 0x8008DC64: sw          $t3, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r11;
    // 0x8008DC68: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8008DC6C: nop

    // 0x8008DC70: lw          $t6, 0x44($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X44);
    // 0x8008DC74: nop

    // 0x8008DC78: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x8008DC7C: b           L_8008DC9C
    // 0x8008DC80: sw          $t2, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r10;
        goto L_8008DC9C;
    // 0x8008DC80: sw          $t2, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r10;
L_8008DC84:
    // 0x8008DC84: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008DC88: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x8008DC8C: lw          $t8, 0x44($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X44);
    // 0x8008DC90: nop

    // 0x8008DC94: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x8008DC98: sw          $t5, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r13;
L_8008DC9C:
    // 0x8008DC9C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008DCA0: nop

    // 0x8008DCA4: beq         $t3, $zero, L_8008DD08
    if (ctx->r11 == 0) {
        // 0x8008DCA8: nop
    
            goto L_8008DD08;
    }
    // 0x8008DCA8: nop

    // 0x8008DCAC: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x8008DCB0: subu        $t6, $t7, $t3
    ctx->r14 = SUB32(ctx->r15, ctx->r11);
    // 0x8008DCB4: bgez        $t6, L_8008DCC0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008DCB8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8008DCC0;
    }
    // 0x8008DCB8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8008DCBC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8008DCC0:
    // 0x8008DCC0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DCC4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008DCC8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8008DCCC: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8008DCD0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8008DCD4: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x8008DCD8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008DCDC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8008DCE0: addu        $t0, $t4, $t8
    ctx->r8 = ADD32(ctx->r12, ctx->r24);
    // 0x8008DCE4: and         $t5, $t0, $at
    ctx->r13 = ctx->r8 & ctx->r1;
    // 0x8008DCE8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008DCEC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8008DCF0: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8008DCF4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8008DCF8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008DCFC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008DD00: nop

    // 0x8008DD04: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
L_8008DD08:
    // 0x8008DD08: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DD0C: nop

L_8008DD10:
    // 0x8008DD10: jr          $ra
    // 0x8008DD14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8008DD14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void h2oRaw8Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD18: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8008DD1C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8008DD20: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8008DD24: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8008DD28: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8008DD2C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8008DD30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD34: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8008DD38: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8008DD3C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8008DD40: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8008DD44: bne         $t8, $zero, L_8008DD54
    if (ctx->r24 != 0) {
        // 0x8008DD48: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_8008DD54;
    }
    // 0x8008DD48: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8008DD4C: b           L_8008E358
    // 0x8008DD50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8008E358;
    // 0x8008DD50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8008DD54:
    // 0x8008DD54: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8008DD58: nop

    // 0x8008DD5C: beq         $t9, $zero, L_8008DD94
    if (ctx->r25 == 0) {
        // 0x8008DD60: nop
    
            goto L_8008DD94;
    }
    // 0x8008DD60: nop

    // 0x8008DD64: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8008DD68: nop

    // 0x8008DD6C: beq         $t0, $zero, L_8008DD94
    if (ctx->r8 == 0) {
        // 0x8008DD70: nop
    
            goto L_8008DD94;
    }
    // 0x8008DD70: nop

    // 0x8008DD74: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8008DD78: nop

    // 0x8008DD7C: beq         $t1, $zero, L_8008DD94
    if (ctx->r9 == 0) {
        // 0x8008DD80: nop
    
            goto L_8008DD94;
    }
    // 0x8008DD80: nop

    // 0x8008DD84: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x8008DD88: nop

    // 0x8008DD8C: bne         $t2, $zero, L_8008DDA0
    if (ctx->r10 != 0) {
        // 0x8008DD90: nop
    
            goto L_8008DDA0;
    }
    // 0x8008DD90: nop

L_8008DD94:
    // 0x8008DD94: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8008DD98: b           L_8008E358
    // 0x8008DD9C: nop

        goto L_8008E358;
    // 0x8008DD9C: nop

L_8008DDA0:
    // 0x8008DDA0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008DDA4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8008DDA8: lw          $t4, 0x38($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X38);
    // 0x8008DDAC: lw          $t8, 0x20($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X20);
    // 0x8008DDB0: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8008DDB4: sltu        $at, $t8, $t7
    ctx->r1 = ctx->r24 < ctx->r15 ? 1 : 0;
    // 0x8008DDB8: beq         $at, $zero, L_8008E13C
    if (ctx->r1 == 0) {
        // 0x8008DDBC: nop
    
            goto L_8008E13C;
    }
    // 0x8008DDBC: nop

    // 0x8008DDC0: lw          $t6, 0x24($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X24);
    // 0x8008DDC4: nop

    // 0x8008DDC8: beq         $t6, $zero, L_8008E13C
    if (ctx->r14 == 0) {
        // 0x8008DDCC: nop
    
            goto L_8008E13C;
    }
    // 0x8008DDCC: nop

    // 0x8008DDD0: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x8008DDD4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8008DDD8: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8008DDDC: blez        $t9, L_8008DE90
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008DDE0: sw          $t0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r8;
            goto L_8008DE90;
    }
    // 0x8008DDE0: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8008DDE4: lw          $t9, 0x30($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X30);
    // 0x8008DDE8: lw          $a0, 0x44($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X44);
    // 0x8008DDEC: lw          $a2, 0x34($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X34);
    // 0x8008DDF0: jalr        $t9
    // 0x8008DDF4: sra         $a1, $t0, 1
    ctx->r5 = S32(SIGNED(ctx->r8) >> 1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8008DDF4: sra         $a1, $t0, 1
    ctx->r5 = S32(SIGNED(ctx->r8) >> 1);
    after_0:
    // 0x8008DDF8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8008DDFC: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8008DE00: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8008DE04: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8008DE08: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8008DE0C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8008DE10: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8008DE14: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8008DE18: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8008DE1C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x8008DE20: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8008DE24: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8008DE28: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8008DE2C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008DE30: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8008DE34: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x8008DE38: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8008DE3C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8008DE40: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8008DE44: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008DE48: andi        $t2, $t5, 0x7
    ctx->r10 = ctx->r13 & 0X7;
    // 0x8008DE4C: subu        $t7, $t5, $t2
    ctx->r15 = SUB32(ctx->r13, ctx->r10);
    // 0x8008DE50: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8008DE54: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8008DE58: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8008DE5C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8008DE60: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8008DE64: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8008DE68: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8008DE6C: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x8008DE70: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8008DE74: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8008DE78: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8008DE7C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8008DE80: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8008DE84: subu        $t7, $t5, $t2
    ctx->r15 = SUB32(ctx->r13, ctx->r10);
    // 0x8008DE88: b           L_8008DE94
    // 0x8008DE8C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_8008DE94;
    // 0x8008DE8C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
L_8008DE90:
    // 0x8008DE90: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_8008DE94:
    // 0x8008DE94: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8008DE98: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8008DE9C: lh          $t4, 0x0($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X0);
    // 0x8008DEA0: nop

    // 0x8008DEA4: addu        $t3, $t4, $t0
    ctx->r11 = ADD32(ctx->r12, ctx->r8);
    // 0x8008DEA8: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8008DEAC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008DEB0: nop

    // 0x8008DEB4: lw          $t1, 0x28($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X28);
    // 0x8008DEB8: lw          $t2, 0x1C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C);
    // 0x8008DEBC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8008DEC0: nop

    // 0x8008DEC4: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8008DEC8: sw          $t7, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r15;
    // 0x8008DECC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008DED0: nop

    // 0x8008DED4: lw          $t4, 0x1C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X1C);
    // 0x8008DED8: nop

    // 0x8008DEDC: sw          $t4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r12;
    // 0x8008DEE0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8008DEE4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8008DEE8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8008DEEC: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x8008DEF0: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008DEF4: beq         $at, $zero, L_8008E100
    if (ctx->r1 == 0) {
        // 0x8008DEF8: sw          $t3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r11;
            goto L_8008E100;
    }
    // 0x8008DEF8: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_8008DEFC:
    // 0x8008DEFC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008DF00: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DF04: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8008DF08: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x8008DF0C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008DF10: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8008DF14: subu        $t6, $t4, $t2
    ctx->r14 = SUB32(ctx->r12, ctx->r10);
    // 0x8008DF18: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8008DF1C: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x8008DF20: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x8008DF24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008DF28: beq         $t3, $at, L_8008DF40
    if (ctx->r11 == ctx->r1) {
        // 0x8008DF2C: nop
    
            goto L_8008DF40;
    }
    // 0x8008DF2C: nop

    // 0x8008DF30: beq         $t3, $zero, L_8008DF40
    if (ctx->r11 == 0) {
        // 0x8008DF34: nop
    
            goto L_8008DF40;
    }
    // 0x8008DF34: nop

    // 0x8008DF38: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x8008DF3C: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
L_8008DF40:
    // 0x8008DF40: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008DF44: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8008DF48: lw          $t7, 0x20($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20);
    // 0x8008DF4C: lw          $t9, 0x1C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X1C);
    // 0x8008DF50: nop

    // 0x8008DF54: subu        $t4, $t7, $t9
    ctx->r12 = SUB32(ctx->r15, ctx->r25);
    // 0x8008DF58: sltu        $at, $t1, $t4
    ctx->r1 = ctx->r9 < ctx->r12 ? 1 : 0;
    // 0x8008DF5C: beq         $at, $zero, L_8008DF6C
    if (ctx->r1 == 0) {
        // 0x8008DF60: nop
    
            goto L_8008DF6C;
    }
    // 0x8008DF60: nop

    // 0x8008DF64: b           L_8008DF88
    // 0x8008DF68: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
        goto L_8008DF88;
    // 0x8008DF68: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
L_8008DF6C:
    // 0x8008DF6C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008DF70: nop

    // 0x8008DF74: lw          $t6, 0x20($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X20);
    // 0x8008DF78: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x8008DF7C: nop

    // 0x8008DF80: subu        $t8, $t6, $t3
    ctx->r24 = SUB32(ctx->r14, ctx->r11);
    // 0x8008DF84: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_8008DF88:
    // 0x8008DF88: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008DF8C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008DF90: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x8008DF94: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8008DF98: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x8008DF9C: lw          $a2, 0x34($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X34);
    // 0x8008DFA0: lw          $a0, 0x44($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X44);
    // 0x8008DFA4: jalr        $t9
    // 0x8008DFA8: sra         $a1, $t5, 1
    ctx->r5 = S32(SIGNED(ctx->r13) >> 1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8008DFA8: sra         $a1, $t5, 1
    ctx->r5 = S32(SIGNED(ctx->r13) >> 1);
    after_1:
    // 0x8008DFAC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8008DFB0: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8008DFB4: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8008DFB8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DFBC: andi        $t1, $t4, 0x7
    ctx->r9 = ctx->r12 & 0X7;
    // 0x8008DFC0: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
    // 0x8008DFC4: andi        $t8, $t3, 0x7
    ctx->r24 = ctx->r11 & 0X7;
    // 0x8008DFC8: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x8008DFCC: beq         $t8, $zero, L_8008DFE4
    if (ctx->r24 == 0) {
        // 0x8008DFD0: sw          $t6, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r14;
            goto L_8008DFE4;
    }
    // 0x8008DFD0: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8008DFD4: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8008DFD8: subu        $t5, $t0, $t8
    ctx->r13 = SUB32(ctx->r8, ctx->r24);
    // 0x8008DFDC: b           L_8008DFE8
    // 0x8008DFE0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
        goto L_8008DFE8;
    // 0x8008DFE0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
L_8008DFE4:
    // 0x8008DFE4: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8008DFE8:
    // 0x8008DFE8: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8008DFEC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DFF0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008DFF4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8008DFF8: addu        $t1, $t4, $t2
    ctx->r9 = ADD32(ctx->r12, ctx->r10);
    // 0x8008DFFC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8008E000: andi        $t6, $t1, 0xFFFF
    ctx->r14 = ctx->r9 & 0XFFFF;
    // 0x8008E004: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8008E008: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8008E00C: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x8008E010: or          $t3, $t6, $at
    ctx->r11 = ctx->r14 | ctx->r1;
    // 0x8008E014: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8008E018: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8008E01C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8008E020: andi        $t5, $t8, 0x7
    ctx->r13 = ctx->r24 & 0X7;
    // 0x8008E024: subu        $t7, $t8, $t5
    ctx->r15 = SUB32(ctx->r24, ctx->r13);
    // 0x8008E028: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8008E02C: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x8008E030: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8008E034: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E038: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x8008E03C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8008E040: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008E044: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8008E048: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8008E04C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8008E050: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008E054: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8008E058: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008E05C: subu        $t7, $t8, $t5
    ctx->r15 = SUB32(ctx->r24, ctx->r13);
    // 0x8008E060: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8008E064: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8008E068: nop

    // 0x8008E06C: bne         $t4, $zero, L_8008E084
    if (ctx->r12 != 0) {
        // 0x8008E070: nop
    
            goto L_8008E084;
    }
    // 0x8008E070: nop

    // 0x8008E074: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8008E078: nop

    // 0x8008E07C: beq         $t2, $zero, L_8008E0E8
    if (ctx->r10 == 0) {
        // 0x8008E080: nop
    
            goto L_8008E0E8;
    }
    // 0x8008E080: nop

L_8008E084:
    // 0x8008E084: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8008E088: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8008E08C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8008E090: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E094: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008E098: addu        $t8, $t3, $t0
    ctx->r24 = ADD32(ctx->r11, ctx->r8);
    // 0x8008E09C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8008E0A0: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x8008E0A4: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8008E0A8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8008E0AC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008E0B0: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8008E0B4: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8008E0B8: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8008E0BC: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8008E0C0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8008E0C4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8008E0C8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8008E0CC: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8008E0D0: andi        $t6, $t1, 0xFFFF
    ctx->r14 = ctx->r9 & 0XFFFF;
    // 0x8008E0D4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8008E0D8: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x8008E0DC: andi        $t5, $t8, 0xFFFF
    ctx->r13 = ctx->r24 & 0XFFFF;
    // 0x8008E0E0: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x8008E0E4: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
L_8008E0E8:
    // 0x8008E0E8: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8008E0EC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8008E0F0: nop

    // 0x8008E0F4: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008E0F8: bne         $at, $zero, L_8008DEFC
    if (ctx->r1 != 0) {
        // 0x8008E0FC: nop
    
            goto L_8008DEFC;
    }
    // 0x8008E0FC: nop

L_8008E100:
    // 0x8008E100: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008E104: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8008E108: lw          $t6, 0x38($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X38);
    // 0x8008E10C: nop

    // 0x8008E110: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8008E114: sw          $t8, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->r24;
    // 0x8008E118: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008E11C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8008E120: lw          $t5, 0x44($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X44);
    // 0x8008E124: nop

    // 0x8008E128: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8008E12C: sw          $t9, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->r25;
    // 0x8008E130: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E134: b           L_8008E358
    // 0x8008E138: nop

        goto L_8008E358;
    // 0x8008E138: nop

L_8008E13C:
    // 0x8008E13C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8008E140: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008E144: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8008E148: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8008E14C: lw          $t1, 0x28($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X28);
    // 0x8008E150: lw          $t0, 0x44($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X44);
    // 0x8008E154: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8008E158: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8008E15C: addu        $t8, $t0, $t2
    ctx->r24 = ADD32(ctx->r8, ctx->r10);
    // 0x8008E160: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8008E164: subu        $t3, $t8, $t9
    ctx->r11 = SUB32(ctx->r24, ctx->r25);
    // 0x8008E168: bgez        $t3, L_8008E174
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8008E16C: sw          $t3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r11;
            goto L_8008E174;
    }
    // 0x8008E16C: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x8008E170: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8008E174:
    // 0x8008E174: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8008E178: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8008E17C: nop

    // 0x8008E180: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008E184: beq         $at, $zero, L_8008E190
    if (ctx->r1 == 0) {
        // 0x8008E188: nop
    
            goto L_8008E190;
    }
    // 0x8008E188: nop

    // 0x8008E18C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
L_8008E190:
    // 0x8008E190: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008E194: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8008E198: nop

    // 0x8008E19C: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008E1A0: beq         $at, $zero, L_8008E2C0
    if (ctx->r1 == 0) {
        // 0x8008E1A4: nop
    
            goto L_8008E2C0;
    }
    // 0x8008E1A4: nop

    // 0x8008E1A8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8008E1AC: nop

    // 0x8008E1B0: blez        $t1, L_8008E270
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008E1B4: nop
    
            goto L_8008E270;
    }
    // 0x8008E1B4: nop

    // 0x8008E1B8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008E1BC: subu        $t5, $t6, $t2
    ctx->r13 = SUB32(ctx->r14, ctx->r10);
    // 0x8008E1C0: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8008E1C4: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x8008E1C8: lw          $a2, 0x34($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X34);
    // 0x8008E1CC: lw          $a0, 0x44($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X44);
    // 0x8008E1D0: jalr        $t9
    // 0x8008E1D4: sra         $a1, $t5, 1
    ctx->r5 = S32(SIGNED(ctx->r13) >> 1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8008E1D4: sra         $a1, $t5, 1
    ctx->r5 = S32(SIGNED(ctx->r13) >> 1);
    after_2:
    // 0x8008E1D8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8008E1DC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8008E1E0: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8008E1E4: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E1E8: andi        $t3, $t8, 0x7
    ctx->r11 = ctx->r24 & 0X7;
    // 0x8008E1EC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8008E1F0: addu        $t0, $t4, $t3
    ctx->r8 = ADD32(ctx->r12, ctx->r11);
    // 0x8008E1F4: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8008E1F8: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x8008E1FC: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8008E200: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8008E204: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8008E208: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x8008E20C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008E210: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8008E214: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x8008E218: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8008E21C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8008E220: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8008E224: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8008E228: andi        $t3, $t4, 0x7
    ctx->r11 = ctx->r12 & 0X7;
    // 0x8008E22C: subu        $t0, $t4, $t3
    ctx->r8 = SUB32(ctx->r12, ctx->r11);
    // 0x8008E230: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8008E234: andi        $t6, $t1, 0xFFFF
    ctx->r14 = ctx->r9 & 0XFFFF;
    // 0x8008E238: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8008E23C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E240: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8008E244: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8008E248: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8008E24C: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8008E250: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8008E254: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8008E258: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8008E25C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8008E260: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8008E264: subu        $t0, $t4, $t3
    ctx->r8 = SUB32(ctx->r12, ctx->r11);
    // 0x8008E268: b           L_8008E274
    // 0x8008E26C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
        goto L_8008E274;
    // 0x8008E26C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
L_8008E270:
    // 0x8008E270: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_8008E274:
    // 0x8008E274: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8008E278: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008E27C: lh          $t2, 0x0($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X0);
    // 0x8008E280: nop

    // 0x8008E284: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8008E288: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
    // 0x8008E28C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008E290: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x8008E294: lw          $t8, 0x38($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X38);
    // 0x8008E298: nop

    // 0x8008E29C: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x8008E2A0: sw          $t3, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r11;
    // 0x8008E2A4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008E2A8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8008E2AC: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x8008E2B0: nop

    // 0x8008E2B4: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x8008E2B8: b           L_8008E2D8
    // 0x8008E2BC: sw          $t5, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r13;
        goto L_8008E2D8;
    // 0x8008E2BC: sw          $t5, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r13;
L_8008E2C0:
    // 0x8008E2C0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008E2C4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8008E2C8: lw          $t6, 0x44($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X44);
    // 0x8008E2CC: nop

    // 0x8008E2D0: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8008E2D4: sw          $t4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r12;
L_8008E2D8:
    // 0x8008E2D8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8008E2DC: nop

    // 0x8008E2E0: beq         $t3, $zero, L_8008E350
    if (ctx->r11 == 0) {
        // 0x8008E2E4: nop
    
            goto L_8008E350;
    }
    // 0x8008E2E4: nop

    // 0x8008E2E8: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8008E2EC: nop

    // 0x8008E2F0: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8008E2F4: subu        $t2, $t1, $t3
    ctx->r10 = SUB32(ctx->r9, ctx->r11);
    // 0x8008E2F8: bgez        $t2, L_8008E304
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8008E2FC: sw          $t2, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r10;
            goto L_8008E304;
    }
    // 0x8008E2FC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8008E300: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_8008E304:
    // 0x8008E304: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E308: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8008E30C: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x8008E310: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8008E314: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8008E318: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8008E31C: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8008E320: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008E324: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8008E328: addu        $t7, $t8, $t4
    ctx->r15 = ADD32(ctx->r24, ctx->r12);
    // 0x8008E32C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8008E330: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E334: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8008E338: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8008E33C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8008E340: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E344: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008E348: nop

    // 0x8008E34C: sw          $t2, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r10;
L_8008E350:
    // 0x8008E350: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8008E354: nop

L_8008E358:
    // 0x8008E358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E35C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8008E360: jr          $ra
    // 0x8008E364: nop

    return;
    // 0x8008E364: nop

;}

RECOMP_FUNC void h2oLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E368: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008E36C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8008E370: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008E374: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x8008E378: beq         $a3, $at, L_8008E558
    if (ctx->r7 == ctx->r1) {
        // 0x8008E37C: sw          $a0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r4;
            goto L_8008E558;
    }
    // 0x8008E37C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8008E380: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008E384: bne         $a3, $at, L_8008E598
    if (ctx->r7 != ctx->r1) {
        // 0x8008E388: nop
    
            goto L_8008E598;
    }
    // 0x8008E388: nop

    // 0x8008E38C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8008E390: nop

    // 0x8008E394: sw          $a2, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r6;
    // 0x8008E398: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8008E39C: nop

    // 0x8008E3A0: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8008E3A4: nop

    // 0x8008E3A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008E3AC: nop

    // 0x8008E3B0: sw          $t9, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r25;
    // 0x8008E3B4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008E3B8: nop

    // 0x8008E3BC: sw          $zero, 0x38($t0)
    MEM_W(0X38, ctx->r8) = 0;
    // 0x8008E3C0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008E3C4: nop

    // 0x8008E3C8: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x8008E3CC: nop

    // 0x8008E3D0: lbu         $a3, 0x8($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X8);
    // 0x8008E3D4: nop

    // 0x8008E3D8: beq         $a3, $zero, L_8008E598
    if (ctx->r7 == 0) {
        // 0x8008E3DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008E598;
    }
    // 0x8008E3DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008E3E0: beq         $a3, $at, L_8008E3F8
    if (ctx->r7 == ctx->r1) {
        // 0x8008E3E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008E3F8;
    }
    // 0x8008E3E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008E3E8: beq         $a3, $at, L_8008E4A8
    if (ctx->r7 == ctx->r1) {
        // 0x8008E3EC: nop
    
            goto L_8008E4A8;
    }
    // 0x8008E3EC: nop

    // 0x8008E3F0: b           L_8008E598
    // 0x8008E3F4: nop

        goto L_8008E598;
    // 0x8008E3F4: nop

L_8008E3F8:
    // 0x8008E3F8: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8008E3FC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8008E400: addiu       $t3, $t3, -0x2890
    ctx->r11 = ADD32(ctx->r11, -0X2890);
    // 0x8008E404: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8008E408: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8008E40C: nop

    // 0x8008E410: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x8008E414: nop

    // 0x8008E418: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x8008E41C: nop

    // 0x8008E420: beq         $t8, $zero, L_8008E47C
    if (ctx->r24 == 0) {
        // 0x8008E424: nop
    
            goto L_8008E47C;
    }
    // 0x8008E424: nop

    // 0x8008E428: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008E42C: nop

    // 0x8008E430: sw          $t9, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r25;
    // 0x8008E434: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8008E438: nop

    // 0x8008E43C: lw          $t0, 0x28($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X28);
    // 0x8008E440: nop

    // 0x8008E444: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8008E448: nop

    // 0x8008E44C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8008E450: nop

    // 0x8008E454: sw          $t2, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r10;
    // 0x8008E458: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8008E45C: nop

    // 0x8008E460: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x8008E464: nop

    // 0x8008E468: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x8008E46C: nop

    // 0x8008E470: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8008E474: b           L_8008E598
    // 0x8008E478: sw          $t8, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r24;
        goto L_8008E598;
    // 0x8008E478: sw          $t8, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r24;
L_8008E47C:
    // 0x8008E47C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008E480: nop

    // 0x8008E484: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    // 0x8008E488: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8008E48C: nop

    // 0x8008E490: lw          $a3, 0x24($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X24);
    // 0x8008E494: nop

    // 0x8008E498: sw          $a3, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r7;
    // 0x8008E49C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008E4A0: b           L_8008E598
    // 0x8008E4A4: sw          $a3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r7;
        goto L_8008E598;
    // 0x8008E4A4: sw          $a3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r7;
L_8008E4A8:
    // 0x8008E4A8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008E4AC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8008E4B0: addiu       $t1, $t1, -0x22E8
    ctx->r9 = ADD32(ctx->r9, -0X22E8);
    // 0x8008E4B4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8008E4B8: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8008E4BC: nop

    // 0x8008E4C0: lw          $t4, 0x28($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X28);
    // 0x8008E4C4: nop

    // 0x8008E4C8: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x8008E4CC: nop

    // 0x8008E4D0: beq         $t6, $zero, L_8008E52C
    if (ctx->r14 == 0) {
        // 0x8008E4D4: nop
    
            goto L_8008E52C;
    }
    // 0x8008E4D4: nop

    // 0x8008E4D8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8008E4DC: nop

    // 0x8008E4E0: sw          $t8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r24;
    // 0x8008E4E4: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8008E4E8: nop

    // 0x8008E4EC: lw          $t9, 0x28($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X28);
    // 0x8008E4F0: nop

    // 0x8008E4F4: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x8008E4F8: nop

    // 0x8008E4FC: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x8008E500: nop

    // 0x8008E504: sw          $t0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->r8;
    // 0x8008E508: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008E50C: nop

    // 0x8008E510: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x8008E514: nop

    // 0x8008E518: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x8008E51C: nop

    // 0x8008E520: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8008E524: b           L_8008E598
    // 0x8008E528: sw          $t6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r14;
        goto L_8008E598;
    // 0x8008E528: sw          $t6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r14;
L_8008E52C:
    // 0x8008E52C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008E530: nop

    // 0x8008E534: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x8008E538: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8008E53C: nop

    // 0x8008E540: lw          $a3, 0x24($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X24);
    // 0x8008E544: nop

    // 0x8008E548: sw          $a3, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r7;
    // 0x8008E54C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008E550: b           L_8008E598
    // 0x8008E554: sw          $a3, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r7;
        goto L_8008E598;
    // 0x8008E554: sw          $a3, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r7;
L_8008E558:
    // 0x8008E558: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8008E55C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E560: lw          $t0, 0x28($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X28);
    // 0x8008E564: nop

    // 0x8008E568: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8008E56C: nop

    // 0x8008E570: sw          $t3, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->r11;
    // 0x8008E574: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8008E578: nop

    // 0x8008E57C: sw          $zero, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = 0;
    // 0x8008E580: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8008E584: nop

    // 0x8008E588: sw          $t4, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r12;
    // 0x8008E58C: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008E590: nop

    // 0x8008E594: sw          $zero, 0x38($t1)
    MEM_W(0X38, ctx->r9) = 0;
L_8008E598:
    // 0x8008E598: jr          $ra
    // 0x8008E59C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008E59C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
