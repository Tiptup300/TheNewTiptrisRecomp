#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void NextPiece_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006832C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80068330: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80068334: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80068338: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006833C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80068340: lw          $t8, 0x534($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X534);
    // 0x80068344: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80068348: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x8006834C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068350: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80068354: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x80068358: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x8006835C: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x80068360: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80068364: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80068368: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8006836C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80068370: lbu         $t1, 0x1E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E);
    // 0x80068374: addiu       $t3, $sp, 0x28
    ctx->r11 = ADD32(ctx->r29, 0X28);
    // 0x80068378: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
    // 0x8006837C: lwl         $at, 0x0($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0X0);
    // 0x80068380: lwr         $at, 0x3($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0X3);
    // 0x80068384: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80068388: swl         $at, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r1);
    // 0x8006838C: swr         $at, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r1);
    // 0x80068390: lwl         $at, 0x0($t3)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r11, 0X0);
    // 0x80068394: lwr         $at, 0x3($t3)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r11, 0X3);
    // 0x80068398: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8006839C: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x800683A0: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x800683A4: lbu         $t8, 0x1E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E);
    // 0x800683A8: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x800683AC: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800683B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800683B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800683B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800683BC: jal         0x800653E4
    // 0x800683C0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    MobilePiece_Init(rdram, ctx);
        goto after_0;
    // 0x800683C0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x800683C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800683C8: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x800683CC: jal         0x800680A0
    // 0x800683D0: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    NextPieceShadow_Setup(rdram, ctx);
        goto after_1;
    // 0x800683D0: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_1:
    // 0x800683D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800683D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800683DC: jr          $ra
    // 0x800683E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800683E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void NextPiece_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800683E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800683E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800683EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800683F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800683F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800683F8: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x800683FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068400: jal         0x80068248
    // 0x80068404: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    NextPieceShadow_Render(rdram, ctx);
        goto after_0;
    // 0x80068404: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_0:
    // 0x80068408: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006840C: nop

    // 0x80068410: lwl         $at, 0x2($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X2);
    // 0x80068414: lwr         $at, 0x5($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X5);
    // 0x80068418: addiu       $s0, $t6, 0x20
    ctx->r16 = ADD32(ctx->r14, 0X20);
    // 0x8006841C: swl         $at, 0xE($s0)
    do_swl(rdram, 0XE, ctx->r16, ctx->r1);
    // 0x80068420: swr         $at, 0x11($s0)
    do_swr(rdram, 0X11, ctx->r16, ctx->r1);
    // 0x80068424: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80068428: nop

    // 0x8006842C: lwl         $at, 0xA($t9)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r25, 0XA);
    // 0x80068430: lwr         $at, 0xD($t9)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r25, 0XD);
    // 0x80068434: nop

    // 0x80068438: swl         $at, 0xA($s0)
    do_swl(rdram, 0XA, ctx->r16, ctx->r1);
    // 0x8006843C: swr         $at, 0xD($s0)
    do_swr(rdram, 0XD, ctx->r16, ctx->r1);
    // 0x80068440: lbu         $t2, 0x2F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2F);
    // 0x80068444: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80068448: bne         $t2, $at, L_8006846C
    if (ctx->r10 != ctx->r1) {
        // 0x8006844C: nop
    
            goto L_8006846C;
    }
    // 0x8006844C: nop

    // 0x80068450: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80068454: nop

    // 0x80068458: lh          $t4, 0x16($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X16);
    // 0x8006845C: nop

    // 0x80068460: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x80068464: b           L_8006848C
    // 0x80068468: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
        goto L_8006848C;
    // 0x80068468: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_8006846C:
    // 0x8006846C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80068470: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80068474: lh          $t6, 0x16($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X16);
    // 0x80068478: nop

    // 0x8006847C: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068480: mflo        $t0
    ctx->r8 = lo;
    // 0x80068484: srl         $t9, $t0, 12
    ctx->r25 = S32(U32(ctx->r8) >> 12);
    // 0x80068488: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8006848C:
    // 0x8006848C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80068490: nop

    // 0x80068494: lhu         $a0, 0x12($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X12);
    // 0x80068498: jal         0x80070D00
    // 0x8006849C: nop

    Minos_SetScale(rdram, ctx);
        goto after_1;
    // 0x8006849C: nop

    after_1:
    // 0x800684A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800684A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800684A8: addiu       $a1, $a1, -0x2AAC
    ctx->r5 = ADD32(ctx->r5, -0X2AAC);
    // 0x800684AC: jal         0x8006CF08
    // 0x800684B0: addiu       $a0, $a0, -0x2AB4
    ctx->r4 = ADD32(ctx->r4, -0X2AB4);
    debug_print2(rdram, ctx);
        goto after_2;
    // 0x800684B0: addiu       $a0, $a0, -0x2AB4
    ctx->r4 = ADD32(ctx->r4, -0X2AB4);
    after_2:
    // 0x800684B4: jal         0x80064FB0
    // 0x800684B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MobilePiece_Render(rdram, ctx);
        goto after_3;
    // 0x800684B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800684BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800684C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800684C4: addiu       $a1, $a1, -0x2A94
    ctx->r5 = ADD32(ctx->r5, -0X2A94);
    // 0x800684C8: jal         0x8006CF08
    // 0x800684CC: addiu       $a0, $a0, -0x2A9C
    ctx->r4 = ADD32(ctx->r4, -0X2A9C);
    debug_print2(rdram, ctx);
        goto after_4;
    // 0x800684CC: addiu       $a0, $a0, -0x2A9C
    ctx->r4 = ADD32(ctx->r4, -0X2A9C);
    after_4:
    // 0x800684D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800684D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800684D8: jr          $ra
    // 0x800684DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800684DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPiece_StepSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800684E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800684E8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800684EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800684F0: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800684F4: lh          $t8, 0x6($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X6);
    // 0x800684F8: nop

    // 0x800684FC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80068500: sh          $t9, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r25;
    // 0x80068504: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80068508: nop

    // 0x8006850C: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80068510: lh          $t2, 0x8($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X8);
    // 0x80068514: nop

    // 0x80068518: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006851C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    // 0x80068520: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80068524: nop

    // 0x80068528: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x8006852C: lh          $t7, 0xE($t4)
    ctx->r15 = MEM_H(ctx->r12, 0XE);
    // 0x80068530: nop

    // 0x80068534: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80068538: sh          $t8, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r24;
    // 0x8006853C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80068540: nop

    // 0x80068544: lh          $t6, 0xC($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XC);
    // 0x80068548: lh          $t1, 0x10($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X10);
    // 0x8006854C: nop

    // 0x80068550: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x80068554: sh          $t2, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r10;
    // 0x80068558: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8006855C: nop

    // 0x80068560: lh          $t0, 0x16($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X16);
    // 0x80068564: lh          $t5, 0x18($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X18);
    // 0x80068568: nop

    // 0x8006856C: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x80068570: sh          $t7, 0x16($t3)
    MEM_H(0X16, ctx->r11) = ctx->r15;
    // 0x80068574: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80068578: nop

    // 0x8006857C: lhu         $t4, 0x12($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X12);
    // 0x80068580: lh          $t6, 0x14($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X14);
    // 0x80068584: nop

    // 0x80068588: addu        $t1, $t4, $t6
    ctx->r9 = ADD32(ctx->r12, ctx->r14);
    // 0x8006858C: sh          $t1, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r9;
    // 0x80068590: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80068594: jal         0x80068204
    // 0x80068598: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    NextPieceShadow_StepSlide(rdram, ctx);
        goto after_0;
    // 0x80068598: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_0:
    // 0x8006859C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800685A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800685A4: jr          $ra
    // 0x800685A8: nop

    return;
    // 0x800685A8: nop

;}

RECOMP_FUNC void NextPiece_InitSlide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800685B0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800685B4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800685B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800685BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800685C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800685C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800685C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800685CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800685D0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800685D4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800685D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800685DC: lbu         $s1, 0x3F($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X3F);
    // 0x800685E0: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x800685E4: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x800685E8: beq         $s1, $zero, L_80068610
    if (ctx->r17 == 0) {
        // 0x800685EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80068610;
    }
    // 0x800685EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800685F0: beq         $s1, $at, L_800686F4
    if (ctx->r17 == ctx->r1) {
        // 0x800685F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800686F4;
    }
    // 0x800685F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800685F8: beq         $s1, $at, L_800686F4
    if (ctx->r17 == ctx->r1) {
        // 0x800685FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800686F4;
    }
    // 0x800685FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80068600: beq         $s1, $at, L_800686F4
    if (ctx->r17 == ctx->r1) {
        // 0x80068604: nop
    
            goto L_800686F4;
    }
    // 0x80068604: nop

    // 0x80068608: b           L_80068788
    // 0x8006860C: nop

        goto L_80068788;
    // 0x8006860C: nop

L_80068610:
    // 0x80068610: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80068614: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80068618: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    // 0x8006861C: jal         0x80066AA8
    // 0x80068620: nop

    getCurPieceSpawnPoint(rdram, ctx);
        goto after_0;
    // 0x80068620: nop

    after_0:
    // 0x80068624: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80068628: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8006862C: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x80068630: jal         0x80066B3C
    // 0x80068634: nop

    getStartingOriginOfRotationPoint(rdram, ctx);
        goto after_1;
    // 0x80068634: nop

    after_1:
    // 0x80068638: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8006863C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80068640: lwl         $at, 0x0($t2)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r10, 0X0);
    // 0x80068644: lwr         $at, 0x3($t2)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r10, 0X3);
    // 0x80068648: nop

    // 0x8006864C: swl         $at, 0x2($t1)
    do_swl(rdram, 0X2, ctx->r9, ctx->r1);
    // 0x80068650: swr         $at, 0x5($t1)
    do_swr(rdram, 0X5, ctx->r9, ctx->r1);
    // 0x80068654: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80068658: lh          $t5, 0x28($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X28);
    // 0x8006865C: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80068660: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80068664: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x80068668: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8006866C: mflo        $t9
    ctx->r25 = lo;
    // 0x80068670: sh          $t9, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r25;
    // 0x80068674: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80068678: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8006867C: lh          $t1, 0x4($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X4);
    // 0x80068680: nop

    // 0x80068684: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80068688: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8006868C: mflo        $t4
    ctx->r12 = lo;
    // 0x80068690: sh          $t4, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r12;
    // 0x80068694: lwl         $at, 0xA($s0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r16, 0XA);
    // 0x80068698: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8006869C: lwr         $at, 0xD($s0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r16, 0XD);
    // 0x800686A0: nop

    // 0x800686A4: swl         $at, 0xA($t5)
    do_swl(rdram, 0XA, ctx->r13, ctx->r1);
    // 0x800686A8: swr         $at, 0xD($t5)
    do_swr(rdram, 0XD, ctx->r13, ctx->r1);
    // 0x800686AC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800686B0: lh          $t9, 0x24($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X24);
    // 0x800686B4: lh          $t0, 0xA($t6)
    ctx->r8 = MEM_H(ctx->r14, 0XA);
    // 0x800686B8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800686BC: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800686C0: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800686C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800686C8: sh          $t2, 0xE($t6)
    MEM_H(0XE, ctx->r14) = ctx->r10;
    // 0x800686CC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800686D0: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x800686D4: lh          $t7, 0xC($t3)
    ctx->r15 = MEM_H(ctx->r11, 0XC);
    // 0x800686D8: nop

    // 0x800686DC: subu        $t5, $t4, $t7
    ctx->r13 = SUB32(ctx->r12, ctx->r15);
    // 0x800686E0: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800686E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800686E8: sh          $t8, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r24;
    // 0x800686EC: b           L_800687A0
    // 0x800686F0: nop

        goto L_800687A0;
    // 0x800686F0: nop

L_800686F4:
    // 0x800686F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800686F8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800686FC: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x80068700: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x80068704: nop

    // 0x80068708: swl         $at, 0x2($t9)
    do_swl(rdram, 0X2, ctx->r25, ctx->r1);
    // 0x8006870C: swr         $at, 0x5($t9)
    do_swr(rdram, 0X5, ctx->r25, ctx->r1);
    // 0x80068710: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80068714: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80068718: lh          $t4, 0x4($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X4);
    // 0x8006871C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80068720: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80068724: subu        $t5, $t4, $t7
    ctx->r13 = SUB32(ctx->r12, ctx->r15);
    // 0x80068728: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8006872C: mflo        $t8
    ctx->r24 = lo;
    // 0x80068730: sh          $t8, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r24;
    // 0x80068734: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80068738: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8006873C: lh          $t9, 0x6($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X6);
    // 0x80068740: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x80068744: nop

    // 0x80068748: subu        $t2, $t9, $t0
    ctx->r10 = SUB32(ctx->r25, ctx->r8);
    // 0x8006874C: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80068750: mflo        $t6
    ctx->r14 = lo;
    // 0x80068754: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
    // 0x80068758: lwl         $at, 0xA($s0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r16, 0XA);
    // 0x8006875C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80068760: lwr         $at, 0xD($s0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r16, 0XD);
    // 0x80068764: nop

    // 0x80068768: swl         $at, 0xA($t7)
    do_swl(rdram, 0XA, ctx->r15, ctx->r1);
    // 0x8006876C: swr         $at, 0xD($t7)
    do_swr(rdram, 0XD, ctx->r15, ctx->r1);
    // 0x80068770: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80068774: nop

    // 0x80068778: sh          $zero, 0xE($t3)
    MEM_H(0XE, ctx->r11) = 0;
    // 0x8006877C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80068780: b           L_800687A0
    // 0x80068784: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
        goto L_800687A0;
    // 0x80068784: sh          $zero, 0x10($t1)
    MEM_H(0X10, ctx->r9) = 0;
L_80068788:
    // 0x80068788: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006878C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068790: addiu       $a1, $a1, -0x2A78
    ctx->r5 = ADD32(ctx->r5, -0X2A78);
    // 0x80068794: addiu       $a0, $a0, -0x2A80
    ctx->r4 = ADD32(ctx->r4, -0X2A80);
    // 0x80068798: jal         0x8004A5A0
    // 0x8006879C: addiu       $a2, $zero, 0xE7
    ctx->r6 = ADD32(0, 0XE7);
    debug_print_reason_routine_linenum(rdram, ctx);
        goto after_2;
    // 0x8006879C: addiu       $a2, $zero, 0xE7
    ctx->r6 = ADD32(0, 0XE7);
    after_2:
L_800687A0:
    // 0x800687A0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800687A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800687A8: lbu         $t0, 0x8($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X8);
    // 0x800687AC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800687B0: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x800687B4: sh          $t2, 0x16($t6)
    MEM_H(0X16, ctx->r14) = ctx->r10;
    // 0x800687B8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800687BC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800687C0: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x800687C4: lbu         $t8, 0x8($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X8);
    // 0x800687C8: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800687CC: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x800687D0: subu        $t1, $t7, $t3
    ctx->r9 = SUB32(ctx->r15, ctx->r11);
    // 0x800687D4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800687D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800687DC: sh          $t9, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r25;
    // 0x800687E0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800687E4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800687E8: lhu         $t6, 0xA($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0XA);
    // 0x800687EC: nop

    // 0x800687F0: sh          $t6, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r14;
    // 0x800687F4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800687F8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800687FC: lhu         $t8, 0xC($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0XC);
    // 0x80068800: lhu         $t7, 0xA($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0XA);
    // 0x80068804: nop

    // 0x80068808: subu        $t3, $t8, $t7
    ctx->r11 = SUB32(ctx->r24, ctx->r15);
    // 0x8006880C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80068810: mflo        $t1
    ctx->r9 = lo;
    // 0x80068814: sh          $t1, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r9;
    // 0x80068818: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8006881C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80068820: jal         0x80068158
    // 0x80068824: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    NextPieceShadow_InitSlide(rdram, ctx);
        goto after_3;
    // 0x80068824: addiu       $a0, $a0, 0x518
    ctx->r4 = ADD32(ctx->r4, 0X518);
    after_3:
    // 0x80068828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006882C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068830: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80068834: jr          $ra
    // 0x80068838: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80068838: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
