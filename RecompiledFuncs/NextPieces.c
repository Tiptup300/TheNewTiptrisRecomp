#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void NextPieces_800680a0_sixliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800680A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800680A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800680A8: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800680AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800680B0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800680B4: lw          $t8, 0x530($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X530);
    // 0x800680B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800680BC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800680C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800680C4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800680C8: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x800680CC: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800680D0: lw          $s0, 0x110($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X110);
    // 0x800680D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800680D8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800680DC: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800680E0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800680E4: lbu         $t1, 0x1E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E);
    // 0x800680E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800680EC: sb          $t1, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r9;
    // 0x800680F0: lwl         $t3, 0x28($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X28);
    // 0x800680F4: lwr         $t3, 0x2B($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X2B);
    // 0x800680F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800680FC: swl         $t3, 0x8($sp)
    do_swl(rdram, 0X8, ctx->r29, ctx->r11);
    // 0x80068100: swr         $t3, 0xB($sp)
    do_swr(rdram, 0XB, ctx->r29, ctx->r11);
    // 0x80068104: lwl         $at, 0xA($s0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r16, 0XA);
    // 0x80068108: lwr         $at, 0xD($s0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r16, 0XD);
    // 0x8006810C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80068110: swl         $at, 0xC($sp)
    do_swl(rdram, 0XC, ctx->r29, ctx->r1);
    // 0x80068114: swr         $at, 0xF($sp)
    do_swr(rdram, 0XF, ctx->r29, ctx->r1);
    // 0x80068118: lbu         $t6, 0x1E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E);
    // 0x8006811C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80068120: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80068124: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80068128: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006812C: jal         0x800653E4
    // 0x80068130: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(rdram, ctx);
        goto after_0;
    // 0x80068130: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80068134: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80068138: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006813C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80068140: jal         0x8006531C
    // 0x80068144: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    MobilePiece_8006531c_fourliner_calls_fun_loops_4_times_v1(rdram, ctx);
        goto after_1;
    // 0x80068144: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x80068148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006814C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068150: jr          $ra
    // 0x80068154: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80068154: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void NextPieces_80068158_sevenliner_sets_arg0_struct_to_arg1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068158: lwl         $at, 0x0($a1)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r5, 0X0);
    // 0x8006815C: lwr         $at, 0x3($a1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r5, 0X3);
    // 0x80068160: nop

    // 0x80068164: swl         $at, 0x2($a0)
    do_swl(rdram, 0X2, ctx->r4, ctx->r1);
    // 0x80068168: swr         $at, 0x5($a0)
    do_swr(rdram, 0X5, ctx->r4, ctx->r1);
    // 0x8006816C: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80068170: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x80068174: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80068178: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8006817C: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80068180: mflo        $t2
    ctx->r10 = lo;
    // 0x80068184: sh          $t2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r10;
    // 0x80068188: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8006818C: lh          $t3, 0x6($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X6);
    // 0x80068190: nop

    // 0x80068194: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80068198: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8006819C: mflo        $t7
    ctx->r15 = lo;
    // 0x800681A0: sh          $t7, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r15;
    // 0x800681A4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800681A8: nop

    // 0x800681AC: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800681B0: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x800681B4: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x800681B8: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800681BC: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800681C0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800681C4: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x800681C8: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800681CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800681D0: sh          $t4, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r12;
    // 0x800681D4: lhu         $t5, 0xA($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0XA);
    // 0x800681D8: nop

    // 0x800681DC: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    // 0x800681E0: lhu         $t6, 0xA($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XA);
    // 0x800681E4: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x800681E8: nop

    // 0x800681EC: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800681F0: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800681F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800681F8: sh          $t9, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r25;
    // 0x800681FC: jr          $ra
    // 0x80068200: nop

    return;
    // 0x80068200: nop

;}

RECOMP_FUNC void NextPieces_80068204_fourliner_sets_arg0_struct_math(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068204: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80068208: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8006820C: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x80068210: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80068214: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    // 0x80068218: lh          $t2, 0xE($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XE);
    // 0x8006821C: lh          $t3, 0x10($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X10);
    // 0x80068220: lh          $t6, 0xC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC);
    // 0x80068224: lhu         $t5, 0xA($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0XA);
    // 0x80068228: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006822C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80068230: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80068234: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x80068238: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x8006823C: sh          $t4, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r12;
    // 0x80068240: jr          $ra
    // 0x80068244: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    return;
    // 0x80068244: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void NextPieceShadow_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068248: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006824C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80068250: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80068254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068258: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006825C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068260: lwl         $at, 0x2($t6)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r14, 0X2);
    // 0x80068264: lwr         $at, 0x5($t6)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r14, 0X5);
    // 0x80068268: addiu       $s0, $t6, 0x18
    ctx->r16 = ADD32(ctx->r14, 0X18);
    // 0x8006826C: swl         $at, 0xE($s0)
    do_swl(rdram, 0XE, ctx->r16, ctx->r1);
    // 0x80068270: swr         $at, 0x11($s0)
    do_swr(rdram, 0X11, ctx->r16, ctx->r1);
    // 0x80068274: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x80068278: lh          $t1, 0x10($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X10);
    // 0x8006827C: addiu       $t0, $t9, 0x80
    ctx->r8 = ADD32(ctx->r25, 0X80);
    // 0x80068280: addiu       $t2, $t1, 0x80
    ctx->r10 = ADD32(ctx->r9, 0X80);
    // 0x80068284: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x80068288: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
    // 0x8006828C: lbu         $t3, 0x2F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2F);
    // 0x80068290: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80068294: bne         $t3, $at, L_800682B8
    if (ctx->r11 != ctx->r1) {
        // 0x80068298: nop
    
            goto L_800682B8;
    }
    // 0x80068298: nop

    // 0x8006829C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800682A0: nop

    // 0x800682A4: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x800682A8: nop

    // 0x800682AC: sra         $t7, $t5, 4
    ctx->r15 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800682B0: b           L_800682D8
    // 0x800682B4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
        goto L_800682D8;
    // 0x800682B4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
L_800682B8:
    // 0x800682B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800682BC: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x800682C0: lh          $t8, 0xE($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XE);
    // 0x800682C4: nop

    // 0x800682C8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800682CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800682D0: srl         $t1, $t0, 12
    ctx->r9 = S32(U32(ctx->r8) >> 12);
    // 0x800682D4: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_800682D8:
    // 0x800682D8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800682DC: nop

    // 0x800682E0: lhu         $a0, 0xA($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0XA);
    // 0x800682E4: jal         0x80070D00
    // 0x800682E8: nop

    Minos_SetScale(rdram, ctx);
        goto after_0;
    // 0x800682E8: nop

    after_0:
    // 0x800682EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800682F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800682F4: addiu       $a1, $a1, -0x2AF4
    ctx->r5 = ADD32(ctx->r5, -0X2AF4);
    // 0x800682F8: jal         0x8006CF08
    // 0x800682FC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    debug_print2(rdram, ctx);
        goto after_1;
    // 0x800682FC: addiu       $a0, $a0, -0x2B10
    ctx->r4 = ADD32(ctx->r4, -0X2B10);
    after_1:
    // 0x80068300: jal         0x80064FB0
    // 0x80068304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MobilePiece_Render(rdram, ctx);
        goto after_2;
    // 0x80068304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80068308: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006830C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068310: addiu       $a1, $a1, -0x2AC8
    ctx->r5 = ADD32(ctx->r5, -0X2AC8);
    // 0x80068314: jal         0x8006CF08
    // 0x80068318: addiu       $a0, $a0, -0x2AE4
    ctx->r4 = ADD32(ctx->r4, -0X2AE4);
    debug_print2(rdram, ctx);
        goto after_3;
    // 0x80068318: addiu       $a0, $a0, -0x2AE4
    ctx->r4 = ADD32(ctx->r4, -0X2AE4);
    after_3:
    // 0x8006831C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068324: jr          $ra
    // 0x80068328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80068328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_8006832c_sixliner_shift_0xe(uint8_t* rdram, recomp_context* ctx) {
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
    MobilePiece_800653e4_eightliner_sets_arg0_struct_to_other_args_loops_4_times(rdram, ctx);
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
    NextPieces_800680a0_sixliner(rdram, ctx);
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

RECOMP_FUNC void NextPieces_800684e0_sevenliner_sets_arg0_struct_math(uint8_t* rdram, recomp_context* ctx) {
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
    NextPieces_80068204_fourliner_sets_arg0_struct_math(rdram, ctx);
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

RECOMP_FUNC void NextPieces_800685ac_lg_interesting_arg3_is_nextpiecepos(uint8_t* rdram, recomp_context* ctx) {
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
    NextPieces_80068158_sevenliner_sets_arg0_struct_to_arg1(rdram, ctx);
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

RECOMP_FUNC void NextPieces_8006883c_tenliner_loops_4_times_sets_glb_var(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006883C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068840: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068844: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80068848: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006884C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80068850: lw          $s0, -0x480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X480);
    // 0x80068854: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80068858: beq         $at, $zero, L_80068898
    if (ctx->r1 == 0) {
        // 0x8006885C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80068898;
    }
    // 0x8006885C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_80068860:
    // 0x80068860: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80068864: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80068868: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8006886C: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80068870: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80068874: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80068878: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8006887C: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    // 0x80068880: jal         0x800684E0
    // 0x80068884: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    NextPieces_800684e0_sevenliner_sets_arg0_struct_math(rdram, ctx);
        goto after_0;
    // 0x80068884: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    after_0:
    // 0x80068888: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006888C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80068890: bne         $at, $zero, L_80068860
    if (ctx->r1 != 0) {
        // 0x80068894: nop
    
            goto L_80068860;
    }
    // 0x80068894: nop

L_80068898:
    // 0x80068898: lbu         $t7, 0x2919($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2919);
    // 0x8006889C: nop

    // 0x800688A0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800688A4: sb          $t8, 0x2919($s0)
    MEM_B(0X2919, ctx->r16) = ctx->r24;
    // 0x800688A8: lbu         $t9, 0x2919($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2919);
    // 0x800688AC: nop

    // 0x800688B0: bne         $t9, $zero, L_800688C8
    if (ctx->r25 != 0) {
        // 0x800688B4: nop
    
            goto L_800688C8;
    }
    // 0x800688B4: nop

    // 0x800688B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800688BC: sb          $t0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r8;
    // 0x800688C0: b           L_800688CC
    // 0x800688C4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_800688CC;
    // 0x800688C4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800688C8:
    // 0x800688C8: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_800688CC:
    // 0x800688CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800688D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800688D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800688D8: jr          $ra
    // 0x800688DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800688DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_800688e0_sets_global_var_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800688E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800688E4: lw          $a0, -0x480($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X480);
    // 0x800688E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800688EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800688F0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800688F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800688F8: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800688FC: jr          $ra
    // 0x80068900: sb          $t7, 0x2919($a0)
    MEM_B(0X2919, ctx->r4) = ctx->r15;
    return;
    // 0x80068900: sb          $t7, 0x2919($a0)
    MEM_B(0X2919, ctx->r4) = ctx->r15;
;}

RECOMP_FUNC void NextPieces_80068904_twoliner_if_fb80_eq_1_call_fun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068904: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006890C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80068910: lw          $s0, -0x480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X480);
    // 0x80068914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068918: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8006891C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068920: bne         $t6, $at, L_80068930
    if (ctx->r14 != ctx->r1) {
        // 0x80068924: nop
    
            goto L_80068930;
    }
    // 0x80068924: nop

    // 0x80068928: jal         0x8006883C
    // 0x8006892C: nop

    NextPieces_8006883c_tenliner_loops_4_times_sets_glb_var(rdram, ctx);
        goto after_0;
    // 0x8006892C: nop

    after_0:
L_80068930:
    // 0x80068930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068938: jr          $ra
    // 0x8006893C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006893C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_Render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068940: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068944: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068948: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006894C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80068950: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80068954: lw          $s0, -0x480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X480);
    // 0x80068958: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8006895C: beq         $at, $zero, L_800689A0
    if (ctx->r1 == 0) {
        // 0x80068960: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800689A0;
    }
    // 0x80068960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_80068964:
    // 0x80068964: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80068968: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x8006896C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80068970: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80068974: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80068978: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x8006897C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80068980: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    // 0x80068984: lbu         $a1, 0x291A($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X291A);
    // 0x80068988: jal         0x800683E4
    // 0x8006898C: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    NextPiece_Render(rdram, ctx);
        goto after_0;
    // 0x8006898C: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    after_0:
    // 0x80068990: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80068994: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80068998: bne         $at, $zero, L_80068964
    if (ctx->r1 != 0) {
        // 0x8006899C: nop
    
            goto L_80068964;
    }
    // 0x8006899C: nop

L_800689A0:
    // 0x800689A0: jal         0x80070D00
    // 0x800689A4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    Minos_SetScale(rdram, ctx);
        goto after_1;
    // 0x800689A4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_1:
    // 0x800689A8: jal         0x80070D30
    // 0x800689AC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    Minos_SetAlpha(rdram, ctx);
        goto after_2;
    // 0x800689AC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_2:
    // 0x800689B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800689B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800689B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800689BC: jr          $ra
    // 0x800689C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800689C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_800689c4_tenliner_loops_4_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800689C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800689CC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800689D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800689D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800689D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800689DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800689E0: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800689E4: lbu         $s1, 0x2918($t6)
    ctx->r17 = MEM_BU(ctx->r14, 0X2918);
    // 0x800689E8: beq         $at, $zero, L_80068A70
    if (ctx->r1 == 0) {
        // 0x800689EC: nop
    
            goto L_80068A70;
    }
    // 0x800689EC: nop

L_800689F0:
    // 0x800689F0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800689F4: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800689F8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800689FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80068A00: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80068A04: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068A08: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x80068A0C: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x80068A10: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x80068A14: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80068A18: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80068A1C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80068A20: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80068A24: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80068A28: addu        $a2, $t7, $t0
    ctx->r6 = ADD32(ctx->r15, ctx->r8);
    // 0x80068A2C: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x80068A30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80068A34: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    // 0x80068A38: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80068A3C: addiu       $a2, $a2, 0x3A
    ctx->r6 = ADD32(ctx->r6, 0X3A);
    // 0x80068A40: jal         0x800685AC
    // 0x80068A44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    NextPieces_800685ac_lg_interesting_arg3_is_nextpiecepos(rdram, ctx);
        goto after_0;
    // 0x80068A44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x80068A48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80068A4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80068A50: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80068A54: bgez        $s1, L_80068A68
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80068A58: andi        $t1, $s1, 0x3
        ctx->r9 = ctx->r17 & 0X3;
            goto L_80068A68;
    }
    // 0x80068A58: andi        $t1, $s1, 0x3
    ctx->r9 = ctx->r17 & 0X3;
    // 0x80068A5C: beq         $t1, $zero, L_80068A68
    if (ctx->r9 == 0) {
        // 0x80068A60: nop
    
            goto L_80068A68;
    }
    // 0x80068A60: nop

    // 0x80068A64: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_80068A68:
    // 0x80068A68: bne         $at, $zero, L_800689F0
    if (ctx->r1 != 0) {
        // 0x80068A6C: or          $s1, $t1, $zero
        ctx->r17 = ctx->r9 | 0;
            goto L_800689F0;
    }
    // 0x80068A6C: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_80068A70:
    // 0x80068A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068A74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068A78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80068A7C: jr          $ra
    // 0x80068A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80068A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_Advance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068A88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80068A8C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80068A90: lw          $s0, -0x480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X480);
    // 0x80068A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068A98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068A9C: lw          $a0, 0x291C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X291C);
    // 0x80068AA0: jal         0x80071394
    // 0x80068AA4: nop

    Bag63_GetNextPiece(rdram, ctx);
        goto after_0;
    // 0x80068AA4: nop

    after_0:
    // 0x80068AA8: lbu         $t6, 0x2918($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2918);
    // 0x80068AAC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80068AB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068AB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068AB8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80068ABC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068AC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80068AC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068AC8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80068ACC: addu        $a0, $s0, $t7
    ctx->r4 = ADD32(ctx->r16, ctx->r15);
    // 0x80068AD0: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    // 0x80068AD4: jal         0x8006832C
    // 0x80068AD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    NextPieces_8006832c_sixliner_shift_0xe(rdram, ctx);
        goto after_1;
    // 0x80068AD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80068ADC: lbu         $t8, 0x2918($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2918);
    // 0x80068AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068AE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80068AE8: bgez        $t9, L_80068AFC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80068AEC: andi        $t0, $t9, 0x3
        ctx->r8 = ctx->r25 & 0X3;
            goto L_80068AFC;
    }
    // 0x80068AEC: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80068AF0: beq         $t0, $zero, L_80068AFC
    if (ctx->r8 == 0) {
        // 0x80068AF4: nop
    
            goto L_80068AFC;
    }
    // 0x80068AF4: nop

    // 0x80068AF8: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
L_80068AFC:
    // 0x80068AFC: jal         0x800689C4
    // 0x80068B00: sb          $t0, 0x2918($s0)
    MEM_B(0X2918, ctx->r16) = ctx->r8;
    NextPieces_800689c4_tenliner_loops_4_times(rdram, ctx);
        goto after_2;
    // 0x80068B00: sb          $t0, 0x2918($s0)
    MEM_B(0X2918, ctx->r16) = ctx->r8;
    after_2:
    // 0x80068B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068B08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068B0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80068B10: jr          $ra
    // 0x80068B14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80068B14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_PopNext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068B1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80068B20: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80068B24: lw          $s0, -0x480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X480);
    // 0x80068B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068B2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068B30: lbu         $t6, 0x2918($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2918);
    // 0x80068B34: nop

    // 0x80068B38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068B3C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068B40: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80068B44: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068B48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80068B4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80068B50: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80068B54: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80068B58: lbu         $s1, 0x78($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X78);
    // 0x80068B5C: jal         0x80068A84
    // 0x80068B60: nop

    NextPieces_Advance(rdram, ctx);
        goto after_0;
    // 0x80068B60: nop

    after_0:
    // 0x80068B64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068B68: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80068B6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80068B70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068B74: jr          $ra
    // 0x80068B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80068B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void NextPieces_80068b7c_largeliner_sets_lots_of_struct_elems(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B7C: lbu         $t6, 0x11($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11);
    // 0x80068B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068B88: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80068B8C: addiu       $t7, $sp, 0xC
    ctx->r15 = ADD32(ctx->r29, 0XC);
    // 0x80068B90: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80068B94: lbu         $t8, 0x10($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X10);
    // 0x80068B98: addiu       $t9, $sp, 0xC
    ctx->r25 = ADD32(ctx->r29, 0XC);
    // 0x80068B9C: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x80068BA0: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x80068BA4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80068BA8: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80068BAC: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80068BB0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80068BB4: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80068BB8: sb          $t4, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r12;
    // 0x80068BBC: lhu         $t5, 0x14($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X14);
    // 0x80068BC0: addiu       $t8, $sp, 0x4
    ctx->r24 = ADD32(ctx->r29, 0X4);
    // 0x80068BC4: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80068BC8: lhu         $t7, 0x12($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X12);
    // 0x80068BCC: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80068BD0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x80068BD4: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x80068BD8: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x80068BDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80068BE0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80068BE4: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80068BE8: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80068BEC: sh          $t4, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r12;
    // 0x80068BF0: beq         $at, $zero, L_80068C30
    if (ctx->r1 == 0) {
        // 0x80068BF4: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80068C30;
    }
    // 0x80068BF4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_80068BF8:
    // 0x80068BF8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80068BFC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80068C00: sll         $t0, $a2, 3
    ctx->r8 = S32(ctx->r6 << 3);
    // 0x80068C04: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x80068C08: lwl         $at, 0x0($t7)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r15, 0X0);
    // 0x80068C0C: lwr         $at, 0x3($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X3);
    // 0x80068C10: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80068C14: addu        $t5, $a1, $t0
    ctx->r13 = ADD32(ctx->r5, ctx->r8);
    // 0x80068C18: swl         $at, 0x0($t5)
    do_swl(rdram, 0X0, ctx->r13, ctx->r1);
    // 0x80068C1C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80068C20: swr         $at, 0x3($t5)
    do_swr(rdram, 0X3, ctx->r13, ctx->r1);
    // 0x80068C24: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80068C28: bne         $at, $zero, L_80068BF8
    if (ctx->r1 != 0) {
        // 0x80068C2C: nop
    
            goto L_80068BF8;
    }
    // 0x80068C2C: nop

L_80068C30:
    // 0x80068C30: lwl         $at, 0x0($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X0);
    // 0x80068C34: lwr         $at, 0x3($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0X3);
    // 0x80068C38: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x80068C3C: swl         $at, 0x12($a1)
    do_swl(rdram, 0X12, ctx->r5, ctx->r1);
    // 0x80068C40: swr         $at, 0x15($a1)
    do_swr(rdram, 0X15, ctx->r5, ctx->r1);
    // 0x80068C44: lwl         $at, 0x4($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X4);
    // 0x80068C48: lwr         $at, 0x7($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0X7);
    // 0x80068C4C: addiu       $t7, $sp, 0xC
    ctx->r15 = ADD32(ctx->r29, 0XC);
    // 0x80068C50: swl         $at, 0x20($a1)
    do_swl(rdram, 0X20, ctx->r5, ctx->r1);
    // 0x80068C54: swr         $at, 0x23($a1)
    do_swr(rdram, 0X23, ctx->r5, ctx->r1);
    // 0x80068C58: lwl         $at, 0x8($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X8);
    // 0x80068C5C: lwr         $at, 0xB($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0XB);
    // 0x80068C60: sb          $zero, 0x32($a1)
    MEM_B(0X32, ctx->r5) = 0;
    // 0x80068C64: swl         $at, 0x2E($a1)
    do_swl(rdram, 0X2E, ctx->r5, ctx->r1);
    // 0x80068C68: swr         $at, 0x31($a1)
    do_swr(rdram, 0X31, ctx->r5, ctx->r1);
    // 0x80068C6C: lbu         $t5, 0x2($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X2);
    // 0x80068C70: addiu       $t2, $sp, 0xC
    ctx->r10 = ADD32(ctx->r29, 0XC);
    // 0x80068C74: sb          $t5, 0x33($a1)
    MEM_B(0X33, ctx->r5) = ctx->r13;
    // 0x80068C78: lbu         $t1, 0x2($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X2);
    // 0x80068C7C: addiu       $t4, $sp, 0xC
    ctx->r12 = ADD32(ctx->r29, 0XC);
    // 0x80068C80: sb          $t1, 0x24($a1)
    MEM_B(0X24, ctx->r5) = ctx->r9;
    // 0x80068C84: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80068C88: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x80068C8C: sb          $t3, 0x25($a1)
    MEM_B(0X25, ctx->r5) = ctx->r11;
    // 0x80068C90: lbu         $t9, 0x1($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X1);
    // 0x80068C94: addiu       $t8, $sp, 0xC
    ctx->r24 = ADD32(ctx->r29, 0XC);
    // 0x80068C98: sb          $t9, 0x16($a1)
    MEM_B(0X16, ctx->r5) = ctx->r25;
    // 0x80068C9C: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80068CA0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80068CA4: sb          $t6, 0x17($a1)
    MEM_B(0X17, ctx->r5) = ctx->r14;
    // 0x80068CA8: lbu         $t5, 0x0($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X0);
    // 0x80068CAC: sb          $t7, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r15;
    // 0x80068CB0: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x80068CB4: sb          $t5, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r13;
    // 0x80068CB8: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x80068CBC: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80068CC0: sh          $t2, 0x34($a1)
    MEM_H(0X34, ctx->r5) = ctx->r10;
    // 0x80068CC4: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x80068CC8: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80068CCC: sh          $t4, 0x36($a1)
    MEM_H(0X36, ctx->r5) = ctx->r12;
    // 0x80068CD0: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80068CD4: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80068CD8: sh          $t0, 0x26($a1)
    MEM_H(0X26, ctx->r5) = ctx->r8;
    // 0x80068CDC: lhu         $t8, 0x2($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X2);
    // 0x80068CE0: addiu       $t5, $sp, 0x4
    ctx->r13 = ADD32(ctx->r29, 0X4);
    // 0x80068CE4: sh          $t8, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r24;
    // 0x80068CE8: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x80068CEC: addiu       $t1, $sp, 0x4
    ctx->r9 = ADD32(ctx->r29, 0X4);
    // 0x80068CF0: sh          $t7, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r15;
    // 0x80068CF4: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80068CF8: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80068CFC: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x80068D00: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80068D04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80068D08: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80068D0C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80068D10: sh          $t9, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r25;
    // 0x80068D14: beq         $at, $zero, L_80068D54
    if (ctx->r1 == 0) {
        // 0x80068D18: sh          $t4, 0xA($a1)
        MEM_H(0XA, ctx->r5) = ctx->r12;
            goto L_80068D54;
    }
    // 0x80068D18: sh          $t4, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r12;
L_80068D1C:
    // 0x80068D1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80068D20: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x80068D24: sll         $t0, $a2, 3
    ctx->r8 = S32(ctx->r6 << 3);
    // 0x80068D28: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x80068D2C: lwl         $at, 0x0($t5)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r13, 0X0);
    // 0x80068D30: lwr         $at, 0x3($t5)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r13, 0X3);
    // 0x80068D34: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80068D38: addu        $t6, $a1, $t0
    ctx->r14 = ADD32(ctx->r5, ctx->r8);
    // 0x80068D3C: swl         $at, 0x38($t6)
    do_swl(rdram, 0X38, ctx->r14, ctx->r1);
    // 0x80068D40: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80068D44: swr         $at, 0x3B($t6)
    do_swr(rdram, 0X3B, ctx->r14, ctx->r1);
    // 0x80068D48: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80068D4C: bne         $at, $zero, L_80068D1C
    if (ctx->r1 != 0) {
        // 0x80068D50: nop
    
            goto L_80068D1C;
    }
    // 0x80068D50: nop

L_80068D54:
    // 0x80068D54: lwl         $at, 0x8($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X8);
    // 0x80068D58: lwr         $at, 0xB($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0XB);
    // 0x80068D5C: addiu       $t5, $sp, 0xC
    ctx->r13 = ADD32(ctx->r29, 0XC);
    // 0x80068D60: swl         $at, 0x66($a1)
    do_swl(rdram, 0X66, ctx->r5, ctx->r1);
    // 0x80068D64: swr         $at, 0x69($a1)
    do_swr(rdram, 0X69, ctx->r5, ctx->r1);
    // 0x80068D68: lwl         $at, 0x4($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X4);
    // 0x80068D6C: lwr         $at, 0x7($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0X7);
    // 0x80068D70: addiu       $t4, $sp, 0xC
    ctx->r12 = ADD32(ctx->r29, 0XC);
    // 0x80068D74: swl         $at, 0x58($a1)
    do_swl(rdram, 0X58, ctx->r5, ctx->r1);
    // 0x80068D78: swr         $at, 0x5B($a1)
    do_swr(rdram, 0X5B, ctx->r5, ctx->r1);
    // 0x80068D7C: lwl         $at, 0x0($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X0);
    // 0x80068D80: lwr         $at, 0x3($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0X3);
    // 0x80068D84: addiu       $t7, $sp, 0xC
    ctx->r15 = ADD32(ctx->r29, 0XC);
    // 0x80068D88: swl         $at, 0x4A($a1)
    do_swl(rdram, 0X4A, ctx->r5, ctx->r1);
    // 0x80068D8C: swr         $at, 0x4D($a1)
    do_swr(rdram, 0X4D, ctx->r5, ctx->r1);
    // 0x80068D90: lwl         $at, 0x0($a0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r4, 0X0);
    // 0x80068D94: lwr         $at, 0x3($a0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r4, 0X3);
    // 0x80068D98: sb          $zero, 0x6A($a1)
    MEM_B(0X6A, ctx->r5) = 0;
    // 0x80068D9C: swl         $at, 0x3C($a1)
    do_swl(rdram, 0X3C, ctx->r5, ctx->r1);
    // 0x80068DA0: swr         $at, 0x3F($a1)
    do_swr(rdram, 0X3F, ctx->r5, ctx->r1);
    // 0x80068DA4: lbu         $t1, 0x2($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X2);
    // 0x80068DA8: nop

    // 0x80068DAC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80068DB0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068DB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068DB8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068DBC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068DC0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068DC4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80068DC8: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x80068DCC: sb          $t3, 0x6B($a1)
    MEM_B(0X6B, ctx->r5) = ctx->r11;
    // 0x80068DD0: lbu         $t9, 0x2($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X2);
    // 0x80068DD4: addiu       $t2, $sp, 0xC
    ctx->r10 = ADD32(ctx->r29, 0XC);
    // 0x80068DD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80068DDC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80068DE0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80068DE4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80068DE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80068DEC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80068DF0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80068DF4: sra         $t8, $t0, 8
    ctx->r24 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80068DF8: sb          $t8, 0x5C($a1)
    MEM_B(0X5C, ctx->r5) = ctx->r24;
    // 0x80068DFC: lbu         $t6, 0x1($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X1);
    // 0x80068E00: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x80068E04: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80068E08: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80068E0C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068E10: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80068E14: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068E18: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80068E1C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80068E20: sra         $t1, $t5, 8
    ctx->r9 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80068E24: sb          $t1, 0x5D($a1)
    MEM_B(0X5D, ctx->r5) = ctx->r9;
    // 0x80068E28: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80068E2C: addiu       $t5, $sp, 0xC
    ctx->r13 = ADD32(ctx->r29, 0XC);
    // 0x80068E30: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80068E34: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80068E38: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80068E3C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80068E40: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80068E44: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80068E48: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80068E4C: sra         $t9, $t4, 8
    ctx->r25 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80068E50: sb          $t9, 0x4E($a1)
    MEM_B(0X4E, ctx->r5) = ctx->r25;
    // 0x80068E54: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x80068E58: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x80068E5C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80068E60: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80068E64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80068E68: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80068E6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80068E70: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80068E74: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80068E78: sra         $t6, $t7, 8
    ctx->r14 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80068E7C: sb          $t6, 0x4F($a1)
    MEM_B(0X4F, ctx->r5) = ctx->r14;
    // 0x80068E80: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x80068E84: sb          $zero, 0x41($a1)
    MEM_B(0X41, ctx->r5) = 0;
    // 0x80068E88: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80068E8C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068E90: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068E94: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068E98: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068E9C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80068EA0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80068EA4: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x80068EA8: sb          $t3, 0x40($a1)
    MEM_B(0X40, ctx->r5) = ctx->r11;
    // 0x80068EAC: lhu         $t9, 0x4($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X4);
    // 0x80068EB0: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x80068EB4: sh          $t9, 0x6C($a1)
    MEM_H(0X6C, ctx->r5) = ctx->r25;
    // 0x80068EB8: lhu         $t8, 0x4($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X4);
    // 0x80068EBC: addiu       $t7, $sp, 0x4
    ctx->r15 = ADD32(ctx->r29, 0X4);
    // 0x80068EC0: sh          $t8, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r24;
    // 0x80068EC4: lhu         $t6, 0x4($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X4);
    // 0x80068EC8: addiu       $t5, $sp, 0x4
    ctx->r13 = ADD32(ctx->r29, 0X4);
    // 0x80068ECC: sh          $t6, 0x5E($a1)
    MEM_H(0X5E, ctx->r5) = ctx->r14;
    // 0x80068ED0: lhu         $t1, 0x2($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X2);
    // 0x80068ED4: addiu       $t2, $sp, 0x4
    ctx->r10 = ADD32(ctx->r29, 0X4);
    // 0x80068ED8: sh          $t1, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r9;
    // 0x80068EDC: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x80068EE0: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x80068EE4: sh          $t3, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r11;
    // 0x80068EE8: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80068EEC: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x80068EF0: sh          $t9, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r25;
    // 0x80068EF4: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x80068EF8: addiu       $t7, $sp, 0x4
    ctx->r15 = ADD32(ctx->r29, 0X4);
    // 0x80068EFC: sh          $t8, 0x42($a1)
    MEM_H(0X42, ctx->r5) = ctx->r24;
    // 0x80068F00: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x80068F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068F08: jr          $ra
    // 0x80068F0C: sh          $t6, 0x44($a1)
    MEM_H(0X44, ctx->r5) = ctx->r14;
    return;
    // 0x80068F0C: sh          $t6, 0x44($a1)
    MEM_H(0X44, ctx->r5) = ctx->r14;
;}

RECOMP_FUNC void NextPieces_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80068F14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068F18: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80068F1C: lw          $s0, -0x480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X480);
    // 0x80068F20: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80068F24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80068F28: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80068F2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80068F30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80068F34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068F38: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80068F3C: sb          $zero, 0x2918($s0)
    MEM_B(0X2918, ctx->r16) = 0;
    // 0x80068F40: beq         $at, $zero, L_80068FB4
    if (ctx->r1 == 0) {
        // 0x80068F44: sw          $t6, 0x291C($s0)
        MEM_W(0X291C, ctx->r16) = ctx->r14;
            goto L_80068FB4;
    }
    // 0x80068F44: sw          $t6, 0x291C($s0)
    MEM_W(0X291C, ctx->r16) = ctx->r14;
L_80068F48:
    // 0x80068F48: lw          $a0, 0x291C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X291C);
    // 0x80068F4C: jal         0x80071394
    // 0x80068F50: nop

    Bag63_GetNextPiece(rdram, ctx);
        goto after_0;
    // 0x80068F50: nop

    after_0:
    // 0x80068F54: lbu         $t7, 0x2918($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2918);
    // 0x80068F58: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80068F5C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068F60: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80068F64: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80068F68: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80068F6C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068F70: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80068F74: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80068F78: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    // 0x80068F7C: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    // 0x80068F80: jal         0x8006832C
    // 0x80068F84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    NextPieces_8006832c_sixliner_shift_0xe(rdram, ctx);
        goto after_1;
    // 0x80068F84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80068F88: lbu         $t9, 0x2918($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2918);
    // 0x80068F8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80068F90: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80068F94: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80068F98: bgez        $t0, L_80068FAC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80068F9C: andi        $t1, $t0, 0x3
        ctx->r9 = ctx->r8 & 0X3;
            goto L_80068FAC;
    }
    // 0x80068F9C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80068FA0: beq         $t1, $zero, L_80068FAC
    if (ctx->r9 == 0) {
        // 0x80068FA4: nop
    
            goto L_80068FAC;
    }
    // 0x80068FA4: nop

    // 0x80068FA8: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_80068FAC:
    // 0x80068FAC: bne         $at, $zero, L_80068F48
    if (ctx->r1 != 0) {
        // 0x80068FB0: sb          $t1, 0x2918($s0)
        MEM_B(0X2918, ctx->r16) = ctx->r9;
            goto L_80068F48;
    }
    // 0x80068FB0: sb          $t1, 0x2918($s0)
    MEM_B(0X2918, ctx->r16) = ctx->r9;
L_80068FB4:
    // 0x80068FB4: jal         0x800689C4
    // 0x80068FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    NextPieces_800689c4_tenliner_loops_4_times(rdram, ctx);
        goto after_2;
    // 0x80068FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80068FBC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80068FC0: sb          $t2, 0x291A($s0)
    MEM_B(0X291A, ctx->r16) = ctx->r10;
    // 0x80068FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80068FC8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80068FCC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068FD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068FD4: jr          $ra
    // 0x80068FD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80068FD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void NextPieces_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FDC: jr          $ra
    // 0x80068FE0: nop

    return;
    // 0x80068FE0: nop

    // 0x80068FE4: nop

    // 0x80068FE8: nop

    // 0x80068FEC: nop

;}
