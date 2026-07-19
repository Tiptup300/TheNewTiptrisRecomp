#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Multisquares_Test4x4byType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A4EC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006A4F0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8006A4F4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006A4F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006A4FC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8006A500: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8006A504: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006A508: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006A50C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A510: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A514: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A518: bltz        $t6, L_8006A540
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006A51C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8006A540;
    }
    // 0x8006A51C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A520: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8006A524: nop

    // 0x8006A528: bltz        $t7, L_8006A540
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006A52C: slti        $at, $t6, 0x7
        ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
            goto L_8006A540;
    }
    // 0x8006A52C: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x8006A530: beq         $at, $zero, L_8006A540
    if (ctx->r1 == 0) {
        // 0x8006A534: slti        $at, $t7, 0x11
        ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
            goto L_8006A540;
    }
    // 0x8006A534: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x8006A538: bne         $at, $zero, L_8006A554
    if (ctx->r1 != 0) {
        // 0x8006A53C: nop
    
            goto L_8006A554;
    }
    // 0x8006A53C: nop

L_8006A540:
    // 0x8006A540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A544: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006A548: addiu       $a1, $a1, -0x2918
    ctx->r5 = ADD32(ctx->r5, -0X2918);
    // 0x8006A54C: jal         0x80083560
    // 0x8006A550: addiu       $a0, $a0, -0x2938
    ctx->r4 = ADD32(ctx->r4, -0X2938);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8006A550: addiu       $a0, $a0, -0x2938
    ctx->r4 = ADD32(ctx->r4, -0X2938);
    after_0:
L_8006A554:
    // 0x8006A554: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x8006A558: blez        $s0, L_8006A570
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006A55C: addiu       $s4, $sp, 0x3C
        ctx->r20 = ADD32(ctx->r29, 0X3C);
            goto L_8006A570;
    }
    // 0x8006A55C: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
L_8006A560:
    // 0x8006A560: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006A564: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x8006A568: bgtz        $s0, L_8006A560
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006A56C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8006A560;
    }
    // 0x8006A56C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8006A570:
    // 0x8006A570: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8006A574: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8006A578: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006A57C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006A580: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006A584: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006A588: lw          $t3, -0x430($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X430);
    // 0x8006A58C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006A590: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006A594: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8006A598: addu        $s1, $t3, $t2
    ctx->r17 = ADD32(ctx->r11, ctx->r10);
    // 0x8006A59C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006A5A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A5A4: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
L_8006A5A8:
    // 0x8006A5A8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8006A5AC: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
L_8006A5B0:
    // 0x8006A5B0: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8006A5B4: nop

    // 0x8006A5B8: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8006A5BC: nop

    // 0x8006A5C0: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8006A5C4: beq         $t7, $zero, L_8006A5D4
    if (ctx->r15 == 0) {
        // 0x8006A5C8: nop
    
            goto L_8006A5D4;
    }
    // 0x8006A5C8: nop

    // 0x8006A5CC: b           L_8006A698
    // 0x8006A5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A698;
    // 0x8006A5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A5D4:
    // 0x8006A5D4: lbu         $t9, 0x3($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X3);
    // 0x8006A5D8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006A5DC: beq         $t9, $at, L_8006A5EC
    if (ctx->r25 == ctx->r1) {
        // 0x8006A5E0: nop
    
            goto L_8006A5EC;
    }
    // 0x8006A5E0: nop

    // 0x8006A5E4: b           L_8006A698
    // 0x8006A5E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A698;
    // 0x8006A5E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A5EC:
    // 0x8006A5EC: lbu         $t8, 0x1($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X1);
    // 0x8006A5F0: lbu         $t0, 0x5B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X5B);
    // 0x8006A5F4: nop

    // 0x8006A5F8: beq         $t8, $t0, L_8006A604
    if (ctx->r24 == ctx->r8) {
        // 0x8006A5FC: nop
    
            goto L_8006A604;
    }
    // 0x8006A5FC: nop

    // 0x8006A600: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8006A604:
    // 0x8006A604: lbu         $s5, 0x2($s2)
    ctx->r21 = MEM_BU(ctx->r18, 0X2);
    // 0x8006A608: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006A60C:
    // 0x8006A60C: addiu       $t1, $sp, 0x3C
    ctx->r9 = ADD32(ctx->r29, 0X3C);
    // 0x8006A610: addu        $t3, $s0, $t1
    ctx->r11 = ADD32(ctx->r16, ctx->r9);
    // 0x8006A614: lbu         $t2, 0x0($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X0);
    // 0x8006A618: nop

    // 0x8006A61C: bne         $t2, $zero, L_8006A630
    if (ctx->r10 != 0) {
        // 0x8006A620: nop
    
            goto L_8006A630;
    }
    // 0x8006A620: nop

    // 0x8006A624: addu        $t4, $s0, $t1
    ctx->r12 = ADD32(ctx->r16, ctx->r9);
    // 0x8006A628: b           L_8006A65C
    // 0x8006A62C: sb          $s5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r21;
        goto L_8006A65C;
    // 0x8006A62C: sb          $s5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r21;
L_8006A630:
    // 0x8006A630: addu        $t5, $sp, $s0
    ctx->r13 = ADD32(ctx->r29, ctx->r16);
    // 0x8006A634: lbu         $t5, 0x3C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3C);
    // 0x8006A638: nop

    // 0x8006A63C: beq         $t5, $s5, L_8006A65C
    if (ctx->r13 == ctx->r21) {
        // 0x8006A640: nop
    
            goto L_8006A65C;
    }
    // 0x8006A640: nop

    // 0x8006A644: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006A648: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006A64C: bne         $s0, $at, L_8006A60C
    if (ctx->r16 != ctx->r1) {
        // 0x8006A650: nop
    
            goto L_8006A60C;
    }
    // 0x8006A650: nop

    // 0x8006A654: b           L_8006A698
    // 0x8006A658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A698;
    // 0x8006A658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A65C:
    // 0x8006A65C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006A660: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A664: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006A668: bgtz        $t7, L_8006A5B0
    if (SIGNED(ctx->r15) > 0) {
        // 0x8006A66C: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_8006A5B0;
    }
    // 0x8006A66C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8006A670: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8006A674: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8006A678: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8006A67C: bgtz        $t8, L_8006A5A8
    if (SIGNED(ctx->r24) > 0) {
        // 0x8006A680: sw          $t8, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r24;
            goto L_8006A5A8;
    }
    // 0x8006A680: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8006A684: beq         $s3, $zero, L_8006A694
    if (ctx->r19 == 0) {
        // 0x8006A688: nop
    
            goto L_8006A694;
    }
    // 0x8006A688: nop

    // 0x8006A68C: b           L_8006A698
    // 0x8006A690: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8006A698;
    // 0x8006A690: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006A694:
    // 0x8006A694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A698:
    // 0x8006A698: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A69C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A6A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A6A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A6A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006A6AC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006A6B0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006A6B4: jr          $ra
    // 0x8006A6B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006A6B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}

RECOMP_FUNC void Multisquares_UpdateGlows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006ADF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006ADF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006ADF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006ADFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006AE00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006AE04: sltiu       $at, $s1, 0x2C
    ctx->r1 = ctx->r17 < 0X2C ? 1 : 0;
    // 0x8006AE08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006AE0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006AE10: beq         $at, $zero, L_8006AE44
    if (ctx->r1 == 0) {
        // 0x8006AE14: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006AE44;
    }
    // 0x8006AE14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006AE18:
    // 0x8006AE18: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8006AE1C: nop

    // 0x8006AE20: beq         $t6, $zero, L_8006AE34
    if (ctx->r14 == 0) {
        // 0x8006AE24: nop
    
            goto L_8006AE34;
    }
    // 0x8006AE24: nop

    // 0x8006AE28: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AE2C: jal         0x8006AF00
    // 0x8006AE30: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    MultisquareGlow_8006af00_eightliner(rdram, ctx);
        goto after_0;
    // 0x8006AE30: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_0:
L_8006AE34:
    // 0x8006AE34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AE38: sltiu       $at, $s1, 0x2C
    ctx->r1 = ctx->r17 < 0X2C ? 1 : 0;
    // 0x8006AE3C: bne         $at, $zero, L_8006AE18
    if (ctx->r1 != 0) {
        // 0x8006AE40: addiu       $s0, $s0, 0x12
        ctx->r16 = ADD32(ctx->r16, 0X12);
            goto L_8006AE18;
    }
    // 0x8006AE40: addiu       $s0, $s0, 0x12
    ctx->r16 = ADD32(ctx->r16, 0X12);
L_8006AE44:
    // 0x8006AE44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AE48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006AE4C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006AE50: jr          $ra
    // 0x8006AE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006AE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Multisquares_RenderGlows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006AE5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006AE60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006AE64: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006AE68: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006AE6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006AE70: sltiu       $at, $s1, 0x2C
    ctx->r1 = ctx->r17 < 0X2C ? 1 : 0;
    // 0x8006AE74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006AE78: beq         $at, $zero, L_8006AEA8
    if (ctx->r1 == 0) {
        // 0x8006AE7C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8006AEA8;
    }
    // 0x8006AE7C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8006AE80:
    // 0x8006AE80: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8006AE84: nop

    // 0x8006AE88: beq         $t6, $zero, L_8006AE98
    if (ctx->r14 == 0) {
        // 0x8006AE8C: nop
    
            goto L_8006AE98;
    }
    // 0x8006AE8C: nop

    // 0x8006AE90: jal         0x8006AF70
    // 0x8006AE94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    MultisquareGlow_8006af70_nineliner(rdram, ctx);
        goto after_0;
    // 0x8006AE94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_0:
L_8006AE98:
    // 0x8006AE98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AE9C: sltiu       $at, $s1, 0x2C
    ctx->r1 = ctx->r17 < 0X2C ? 1 : 0;
    // 0x8006AEA0: bne         $at, $zero, L_8006AE80
    if (ctx->r1 != 0) {
        // 0x8006AEA4: addiu       $s0, $s0, 0x12
        ctx->r16 = ADD32(ctx->r16, 0X12);
            goto L_8006AE80;
    }
    // 0x8006AEA4: addiu       $s0, $s0, 0x12
    ctx->r16 = ADD32(ctx->r16, 0X12);
L_8006AEA8:
    // 0x8006AEA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AEAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006AEB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006AEB4: jr          $ra
    // 0x8006AEB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006AEB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
