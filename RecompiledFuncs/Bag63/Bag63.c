#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Bag63_FillBag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800711E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800711E4: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x800711E8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800711EC: beq         $at, $zero, L_80071228
    if (ctx->r1 == 0) {
        // 0x800711F0: addiu       $a3, $a0, 0x76
        ctx->r7 = ADD32(ctx->r4, 0X76);
            goto L_80071228;
    }
    // 0x800711F0: addiu       $a3, $a0, 0x76
    ctx->r7 = ADD32(ctx->r4, 0X76);
L_800711F4:
    // 0x800711F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800711F8: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x800711FC: beq         $at, $zero, L_80071218
    if (ctx->r1 == 0) {
        // 0x80071200: nop
    
            goto L_80071218;
    }
    // 0x80071200: nop

L_80071204:
    // 0x80071204: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80071208: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007120C: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x80071210: bne         $at, $zero, L_80071204
    if (ctx->r1 != 0) {
        // 0x80071214: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80071204;
    }
    // 0x80071214: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80071218:
    // 0x80071218: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007121C: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80071220: bne         $at, $zero, L_800711F4
    if (ctx->r1 != 0) {
        // 0x80071224: nop
    
            goto L_800711F4;
    }
    // 0x80071224: nop

L_80071228:
    // 0x80071228: addiu       $t6, $zero, 0x3F
    ctx->r14 = ADD32(0, 0X3F);
    // 0x8007122C: sh          $t6, 0x74($a0)
    MEM_H(0X74, ctx->r4) = ctx->r14;
    // 0x80071230: jr          $ra
    // 0x80071234: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80071234: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void Bag63_RefillQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071238: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007123C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80071240: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80071244: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071248: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007124C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80071250: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071254: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80071258: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8007125C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80071260: nop

    // 0x80071264: beq         $t7, $t8, L_80071378
    if (ctx->r15 == ctx->r24) {
        // 0x80071268: nop
    
            goto L_80071378;
    }
    // 0x80071268: nop

L_8007126C:
    // 0x8007126C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80071270: nop

    // 0x80071274: lw          $a0, 0xB8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XB8);
    // 0x80071278: jal         0x8006089C
    // 0x8007127C: nop

    FUN_026900_PRNG_2(rdram, ctx);
        goto after_0;
    // 0x8007127C: nop

    after_0:
    // 0x80071280: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80071284: nop

    // 0x80071288: sw          $v0, 0xB8($t0)
    MEM_W(0XB8, ctx->r8) = ctx->r2;
    // 0x8007128C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80071290: nop

    // 0x80071294: lw          $t2, 0xB8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XB8);
    // 0x80071298: lhu         $t3, 0x74($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X74);
    // 0x8007129C: nop

    // 0x800712A0: divu        $zero, $t2, $t3
    lo = S32(U32(ctx->r10) / U32(ctx->r11)); hi = S32(U32(ctx->r10) % U32(ctx->r11));
    // 0x800712A4: bne         $t3, $zero, L_800712B0
    if (ctx->r11 != 0) {
        // 0x800712A8: nop
    
            goto L_800712B0;
    }
    // 0x800712A8: nop

    // 0x800712AC: break       7
    do_break(2147947180);
L_800712B0:
    // 0x800712B0: mfhi        $s3
    ctx->r19 = hi;
    // 0x800712B4: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x800712B8: addu        $t4, $t1, $s3
    ctx->r12 = ADD32(ctx->r9, ctx->r19);
    // 0x800712BC: lbu         $s4, 0x76($t4)
    ctx->r20 = MEM_BU(ctx->r12, 0X76);
    // 0x800712C0: sltiu       $at, $s2, 0x3E
    ctx->r1 = ctx->r18 < 0X3E ? 1 : 0;
    // 0x800712C4: addu        $s1, $t1, $s3
    ctx->r17 = ADD32(ctx->r9, ctx->r19);
    // 0x800712C8: beq         $at, $zero, L_800712E8
    if (ctx->r1 == 0) {
        // 0x800712CC: addiu       $s1, $s1, 0x76
        ctx->r17 = ADD32(ctx->r17, 0X76);
            goto L_800712E8;
    }
    // 0x800712CC: addiu       $s1, $s1, 0x76
    ctx->r17 = ADD32(ctx->r17, 0X76);
L_800712D0:
    // 0x800712D0: lbu         $t5, 0x1($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1);
    // 0x800712D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800712D8: sltiu       $at, $s2, 0x3E
    ctx->r1 = ctx->r18 < 0X3E ? 1 : 0;
    // 0x800712DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800712E0: bne         $at, $zero, L_800712D0
    if (ctx->r1 != 0) {
        // 0x800712E4: sb          $t5, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r13;
            goto L_800712D0;
    }
    // 0x800712E4: sb          $t5, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r13;
L_800712E8:
    // 0x800712E8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800712EC: nop

    // 0x800712F0: lhu         $t7, 0x74($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X74);
    // 0x800712F4: nop

    // 0x800712F8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800712FC: sh          $t8, 0x74($t6)
    MEM_H(0X74, ctx->r14) = ctx->r24;
    // 0x80071300: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80071304: nop

    // 0x80071308: lhu         $t0, 0x74($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X74);
    // 0x8007130C: nop

    // 0x80071310: bne         $t0, $zero, L_80071320
    if (ctx->r8 != 0) {
        // 0x80071314: nop
    
            goto L_80071320;
    }
    // 0x80071314: nop

    // 0x80071318: jal         0x800711E0
    // 0x8007131C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    Bag63_FillBag(rdram, ctx);
        goto after_1;
    // 0x8007131C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
L_80071320:
    // 0x80071320: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80071324: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80071328: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8007132C: nop

    // 0x80071330: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80071334: addu        $t1, $t2, $t4
    ctx->r9 = ADD32(ctx->r10, ctx->r12);
    // 0x80071338: sw          $s4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r20;
    // 0x8007133C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80071340: nop

    // 0x80071344: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80071348: nop

    // 0x8007134C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80071350: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x80071354: mfhi        $t6
    ctx->r14 = hi;
    // 0x80071358: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8007135C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80071360: nop

    // 0x80071364: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80071368: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8007136C: nop

    // 0x80071370: bne         $t9, $t3, L_8007126C
    if (ctx->r25 != ctx->r11) {
        // 0x80071374: nop
    
            goto L_8007126C;
    }
    // 0x80071374: nop

L_80071378:
    // 0x80071378: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007137C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071380: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071384: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071388: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007138C: jr          $ra
    // 0x80071390: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80071390: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

RECOMP_FUNC void Bag63_GetNextPiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071394: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80071398: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007139C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800713A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800713A4: jal         0x80071238
    // 0x800713A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    Bag63_RefillQueue(rdram, ctx);
        goto after_0;
    // 0x800713A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800713AC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800713B0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800713B4: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800713B8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800713BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800713C0: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x800713C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800713C8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800713CC: lw          $s0, 0x8($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X8);
    // 0x800713D0: nop

    // 0x800713D4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800713D8: mfhi        $t2
    ctx->r10 = hi;
    // 0x800713DC: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x800713E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800713E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800713E8: jr          $ra
    // 0x800713EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800713EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void Bag63_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800713F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800713F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800713F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800713FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071400: jal         0x800711E0
    // 0x80071404: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    Bag63_FillBag(rdram, ctx);
        goto after_0;
    // 0x80071404: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80071408: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8007140C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80071410: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80071414: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80071418: sw          $t7, 0xB8($t8)
    MEM_W(0XB8, ctx->r24) = ctx->r15;
    // 0x8007141C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80071420: nop

    // 0x80071424: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x80071428: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8007142C: nop

    // 0x80071430: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80071434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071438: jal         0x80071238
    // 0x8007143C: nop

    Bag63_RefillQueue(rdram, ctx);
        goto after_1;
    // 0x8007143C: nop

    after_1:
    // 0x80071440: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80071444: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80071448: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8007144C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80071450: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80071454: lw          $t5, 0xB8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XB8);
    // 0x80071458: nop

    // 0x8007145C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80071460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071468: jr          $ra
    // 0x8007146C: nop

    return;
    // 0x8007146C: nop

;}

RECOMP_FUNC void Bag63_Deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071470: jr          $ra
    // 0x80071474: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80071474: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80071478: nop

    // 0x8007147C: nop

;}

RECOMP_FUNC void displayTimeFormatted_XY_RGBA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071480: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80071484: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80071488: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8007148C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80071490: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x80071494: lui         $at, 0xFFB0
    ctx->r1 = S32(0XFFB0 << 16);
    // 0x80071498: ori         $at, $at, 0xE600
    ctx->r1 = ctx->r1 | 0XE600;
    // 0x8007149C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800714A0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800714A4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800714A8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800714AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800714B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800714B4: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x800714B8: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800714BC: b           L_800714D4
    // 0x800714C0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
        goto L_800714D4;
    // 0x800714C0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800714C4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800714C8: lui         $t0, 0x4F
    ctx->r8 = S32(0X4F << 16);
    // 0x800714CC: ori         $t0, $t0, 0x1A00
    ctx->r8 = ctx->r8 | 0X1A00;
    // 0x800714D0: subu        $s0, $t0, $t9
    ctx->r16 = SUB32(ctx->r8, ctx->r25);
L_800714D4:
    // 0x800714D4: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x800714D8: ori         $at, $at, 0x4BC0
    ctx->r1 = ctx->r1 | 0X4BC0;
    // 0x800714DC: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x800714E0: beq         $at, $zero, L_800714EC
    if (ctx->r1 == 0) {
        // 0x800714E4: nop
    
            goto L_800714EC;
    }
    // 0x800714E4: nop

    // 0x800714E8: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_800714EC:
    // 0x800714EC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800714F0: ori         $at, $zero, 0x8CA0
    ctx->r1 = 0 | 0X8CA0;
    // 0x800714F4: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x800714F8: bne         $at, $zero, L_80071508
    if (ctx->r1 != 0) {
        // 0x800714FC: nop
    
            goto L_80071508;
    }
    // 0x800714FC: nop

    // 0x80071500: ori         $t2, $zero, 0x8C9F
    ctx->r10 = 0 | 0X8C9F;
    // 0x80071504: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_80071508:
    // 0x80071508: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8007150C: nop

    // 0x80071510: sltiu       $at, $t3, 0x258
    ctx->r1 = ctx->r11 < 0X258 ? 1 : 0;
    // 0x80071514: beq         $at, $zero, L_80071594
    if (ctx->r1 == 0) {
        // 0x80071518: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80071594;
    }
    // 0x80071518: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8007151C: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80071520: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80071524: addiu       $a1, $a1, -0x26C0
    ctx->r5 = ADD32(ctx->r5, -0X26C0);
    // 0x80071528: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8007152C: mflo        $a2
    ctx->r6 = lo;
    // 0x80071530: nop

    // 0x80071534: nop

    // 0x80071538: divu        $zero, $a2, $at
    lo = S32(U32(ctx->r6) / U32(ctx->r1)); hi = S32(U32(ctx->r6) % U32(ctx->r1));
    // 0x8007153C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80071540: mfhi        $t4
    ctx->r12 = hi;
    // 0x80071544: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80071548: nop

    // 0x8007154C: divu        $zero, $a2, $at
    lo = S32(U32(ctx->r6) / U32(ctx->r1)); hi = S32(U32(ctx->r6) % U32(ctx->r1));
    // 0x80071550: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80071554: mfhi        $t5
    ctx->r13 = hi;
    // 0x80071558: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8007155C: nop

    // 0x80071560: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80071564: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80071568: mfhi        $t6
    ctx->r14 = hi;
    // 0x8007156C: nop

    // 0x80071570: nop

    // 0x80071574: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x80071578: mfhi        $t7
    ctx->r15 = hi;
    // 0x8007157C: mflo        $a3
    ctx->r7 = lo;
    // 0x80071580: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80071584: jal         0x800B62D4
    // 0x80071588: nop

    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80071588: nop

    after_0:
    // 0x8007158C: b           L_800716C8
    // 0x80071590: nop

        goto L_800716C8;
    // 0x80071590: nop

L_80071594:
    // 0x80071594: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80071598: nop

    // 0x8007159C: sltiu       $at, $t8, 0xE11
    ctx->r1 = ctx->r24 < 0XE11 ? 1 : 0;
    // 0x800715A0: beq         $at, $zero, L_80071624
    if (ctx->r1 == 0) {
        // 0x800715A4: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80071624;
    }
    // 0x800715A4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800715A8: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800715AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800715B0: addiu       $a1, $a1, -0x26AC
    ctx->r5 = ADD32(ctx->r5, -0X26AC);
    // 0x800715B4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800715B8: mflo        $t0
    ctx->r8 = lo;
    // 0x800715BC: nop

    // 0x800715C0: nop

    // 0x800715C4: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x800715C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800715CC: mfhi        $t9
    ctx->r25 = hi;
    // 0x800715D0: nop

    // 0x800715D4: nop

    // 0x800715D8: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x800715DC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800715E0: mfhi        $a3
    ctx->r7 = hi;
    // 0x800715E4: mflo        $a2
    ctx->r6 = lo;
    // 0x800715E8: nop

    // 0x800715EC: nop

    // 0x800715F0: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800715F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800715F8: mfhi        $t1
    ctx->r9 = hi;
    // 0x800715FC: nop

    // 0x80071600: nop

    // 0x80071604: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x80071608: mfhi        $t4
    ctx->r12 = hi;
    // 0x8007160C: mflo        $t2
    ctx->r10 = lo;
    // 0x80071610: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80071614: jal         0x800B62D4
    // 0x80071618: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80071618: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x8007161C: b           L_800716C8
    // 0x80071620: nop

        goto L_800716C8;
    // 0x80071620: nop

L_80071624:
    // 0x80071624: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80071628: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8007162C: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x80071630: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80071634: addiu       $a1, $a1, -0x2694
    ctx->r5 = ADD32(ctx->r5, -0X2694);
    // 0x80071638: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8007163C: mflo        $t3
    ctx->r11 = lo;
    // 0x80071640: nop

    // 0x80071644: nop

    // 0x80071648: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x8007164C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80071650: mflo        $a2
    ctx->r6 = lo;
    // 0x80071654: nop

    // 0x80071658: nop

    // 0x8007165C: divu        $zero, $a2, $at
    lo = S32(U32(ctx->r6) / U32(ctx->r1)); hi = S32(U32(ctx->r6) % U32(ctx->r1));
    // 0x80071660: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80071664: mfhi        $t6
    ctx->r14 = hi;
    // 0x80071668: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007166C: nop

    // 0x80071670: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80071674: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80071678: mfhi        $t7
    ctx->r15 = hi;
    // 0x8007167C: nop

    // 0x80071680: nop

    // 0x80071684: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80071688: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8007168C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80071690: mflo        $a3
    ctx->r7 = lo;
    // 0x80071694: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80071698: nop

    // 0x8007169C: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x800716A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800716A4: mfhi        $t9
    ctx->r25 = hi;
    // 0x800716A8: nop

    // 0x800716AC: nop

    // 0x800716B0: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x800716B4: mfhi        $t2
    ctx->r10 = hi;
    // 0x800716B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800716BC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800716C0: jal         0x800B62D4
    // 0x800716C4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800716C4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_2:
L_800716C8:
    // 0x800716C8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800716CC: jal         0x80077D88
    // 0x800716D0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    Font_GetTextWidth(rdram, ctx);
        goto after_3;
    // 0x800716D0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x800716D4: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800716D8: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800716DC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800716E0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800716E4: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800716E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800716EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800716F0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800716F4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800716F8: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
    // 0x800716FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80071700: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80071704: subu        $a2, $t1, $s0
    ctx->r6 = SUB32(ctx->r9, ctx->r16);
    // 0x80071708: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007170C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80071710: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80071714: jal         0x80077960
    // 0x80071718: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_4;
    // 0x80071718: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_4:
    // 0x8007171C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80071720: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80071724: jr          $ra
    // 0x80071728: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80071728: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007172C: nop

;}

RECOMP_FUNC void func_80071730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80071734: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80071738: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007173C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80071740: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80071744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80071748: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007174C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80071750: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80071754: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80071758: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
    // 0x8007175C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80071760: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80071764: jal         0x80077D88
    // 0x80071768: nop

    Font_GetTextWidth(rdram, ctx);
        goto after_0;
    // 0x80071768: nop

    after_0:
    // 0x8007176C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80071770: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80071774: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80071778: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8007177C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80071780: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80071784: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80071788: lh          $t4, 0x76($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X76);
    // 0x8007178C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80071790: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x80071794: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80071798: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007179C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800717A0: sb          $t7, 0xB($t8)
    MEM_B(0XB, ctx->r24) = ctx->r15;
    // 0x800717A4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800717A8: nop

    // 0x800717AC: lbu         $s1, 0xB($t9)
    ctx->r17 = MEM_BU(ctx->r25, 0XB);
    // 0x800717B0: nop

    // 0x800717B4: sb          $s1, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r17;
    // 0x800717B8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800717BC: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800717C0: sb          $s0, 0x9($t0)
    MEM_B(0X9, ctx->r8) = ctx->r16;
    // 0x800717C4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800717C8: nop

    // 0x800717CC: sb          $s0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r16;
    // 0x800717D0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800717D4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800717D8: nop

    // 0x800717DC: sw          $t3, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r11;
    // 0x800717E0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800717E4: nop

    // 0x800717E8: sw          $zero, 0x20($t4)
    MEM_W(0X20, ctx->r12) = 0;
    // 0x800717EC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800717F0: nop

    // 0x800717F4: sw          $zero, 0x24($t5)
    MEM_W(0X24, ctx->r13) = 0;
    // 0x800717F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800717FC: nop

    // 0x80071800: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
    // 0x80071804: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80071808: nop

    // 0x8007180C: sw          $zero, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = 0;
    // 0x80071810: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80071814: nop

    // 0x80071818: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
    // 0x8007181C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80071820: nop

    // 0x80071824: sb          $zero, 0x14($t9)
    MEM_B(0X14, ctx->r25) = 0;
    // 0x80071828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007182C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80071830: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80071834: jr          $ra
    // 0x80071838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80071838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_8007183C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007183C: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x80071840: nop

    // 0x80071844: beq         $t6, $zero, L_80071A38
    if (ctx->r14 == 0) {
        // 0x80071848: nop
    
            goto L_80071A38;
    }
    // 0x80071848: nop

    // 0x8007184C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80071850: lw          $t7, 0x9F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X9F4);
    // 0x80071854: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80071858: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8007185C: bgez        $t7, L_80071874
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80071860: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80071874;
    }
    // 0x80071860: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80071864: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80071868: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007186C: nop

    // 0x80071870: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80071874:
    // 0x80071874: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80071878: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8007187C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80071880: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80071884: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80071888: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x8007188C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80071890: nop

    // 0x80071894: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80071898: nop

    // 0x8007189C: bc1f        L_800718C0
    if (!c1cs) {
        // 0x800718A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800718C0;
    }
    // 0x800718A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800718A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800718A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800718AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800718B0: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800718B4: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800718B8: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800718BC: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_800718C0:
    // 0x800718C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800718C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800718C8: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800718CC: nop

    // 0x800718D0: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x800718D4: nop

    // 0x800718D8: bc1f        L_800718FC
    if (!c1cs) {
        // 0x800718DC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800718FC;
    }
    // 0x800718DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800718E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800718E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800718E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800718EC: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800718F0: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800718F4: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800718F8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_800718FC:
    // 0x800718FC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80071900: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80071904: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80071908: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007190C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80071910: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80071914: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80071918: nop

    // 0x8007191C: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80071920: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80071924: nop

    // 0x80071928: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8007192C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80071930: beq         $t9, $zero, L_80071980
    if (ctx->r25 == 0) {
        // 0x80071934: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80071980;
    }
    // 0x80071934: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80071938: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007193C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80071940: sub.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80071944: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80071948: nop

    // 0x8007194C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80071950: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80071954: nop

    // 0x80071958: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8007195C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80071960: bne         $t9, $zero, L_80071978
    if (ctx->r25 != 0) {
        // 0x80071964: nop
    
            goto L_80071978;
    }
    // 0x80071964: nop

    // 0x80071968: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8007196C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80071970: b           L_80071990
    // 0x80071974: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80071990;
    // 0x80071974: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80071978:
    // 0x80071978: b           L_80071990
    // 0x8007197C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80071990;
    // 0x8007197C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80071980:
    // 0x80071980: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80071984: nop

    // 0x80071988: bltz        $t9, L_80071978
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007198C: nop
    
            goto L_80071978;
    }
    // 0x8007198C: nop

L_80071990:
    // 0x80071990: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80071994: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80071998: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007199C: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800719A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800719A4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800719A8: sb          $t9, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r25;
    // 0x800719AC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800719B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800719B4: nop

    // 0x800719B8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800719BC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800719C0: nop

    // 0x800719C4: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800719C8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800719CC: beq         $t1, $zero, L_80071A1C
    if (ctx->r9 == 0) {
        // 0x800719D0: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80071A1C;
    }
    // 0x800719D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800719D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800719D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800719DC: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800719E0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800719E4: nop

    // 0x800719E8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800719EC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800719F0: nop

    // 0x800719F4: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800719F8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800719FC: bne         $t1, $zero, L_80071A14
    if (ctx->r9 != 0) {
        // 0x80071A00: nop
    
            goto L_80071A14;
    }
    // 0x80071A00: nop

    // 0x80071A04: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80071A08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80071A0C: b           L_80071A2C
    // 0x80071A10: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80071A2C;
    // 0x80071A10: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80071A14:
    // 0x80071A14: b           L_80071A2C
    // 0x80071A18: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80071A2C;
    // 0x80071A18: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80071A1C:
    // 0x80071A1C: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80071A20: nop

    // 0x80071A24: bltz        $t1, L_80071A14
    if (SIGNED(ctx->r9) < 0) {
        // 0x80071A28: nop
    
            goto L_80071A14;
    }
    // 0x80071A28: nop

L_80071A2C:
    // 0x80071A2C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80071A30: sb          $t1, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r9;
    // 0x80071A34: nop

L_80071A38:
    // 0x80071A38: jr          $ra
    // 0x80071A3C: nop

    return;
    // 0x80071A3C: nop

;}

RECOMP_FUNC void func_80071A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A40: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80071A44: lw          $t6, 0x20C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X20C0);
    // 0x80071A48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80071A4C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80071A50: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80071A54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80071A58: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80071A5C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071A60: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80071A64: sw          $t7, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r15;
    // 0x80071A68: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80071A6C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80071A70: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80071A74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071A78: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80071A7C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80071A80: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80071A84: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80071A88: lw          $a1, 0x1C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1C);
    // 0x80071A8C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80071A90: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x80071A94: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80071A98: lbu         $t3, 0x8($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X8);
    // 0x80071A9C: nop

    // 0x80071AA0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80071AA4: lbu         $t4, 0x9($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X9);
    // 0x80071AA8: nop

    // 0x80071AAC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80071AB0: lbu         $t5, 0xA($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XA);
    // 0x80071AB4: nop

    // 0x80071AB8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80071ABC: lbu         $t6, 0xB($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XB);
    // 0x80071AC0: jal         0x80077960
    // 0x80071AC4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_0;
    // 0x80071AC4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80071AC8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80071ACC: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80071AD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80071AD4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80071AD8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80071ADC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80071AE0: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80071AE4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80071AE8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80071AEC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80071AF0: nop

    // 0x80071AF4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80071AF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80071AFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80071B00: jr          $ra
    // 0x80071B04: nop

    return;
    // 0x80071B04: nop

;}

RECOMP_FUNC void func_80071B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80071B0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80071B10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80071B14: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80071B18: lwc1        $f6, -0x2650($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2650);
    // 0x80071B1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80071B20: sb          $t6, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r14;
    // 0x80071B24: jr          $ra
    // 0x80071B28: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80071B28: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
;}

RECOMP_FUNC void func_80071B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B2C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80071B30: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80071B34: sb          $t6, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r14;
    // 0x80071B38: sb          $t7, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r15;
    // 0x80071B3C: jr          $ra
    // 0x80071B40: sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    return;
    // 0x80071B40: sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
;}

RECOMP_FUNC void func_80071B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071B4C: jal         0x80084F80
    // 0x80071B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Audio_UnloadSFX(rdram, ctx);
        goto after_0;
    // 0x80071B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071B54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071B58: jal         0x80071DEC
    // 0x80071B5C: nop

    func_80071DEC(rdram, ctx);
        goto after_1;
    // 0x80071B5C: nop

    after_1:
    // 0x80071B60: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80071B64: jal         0x80085030
    // 0x80071B68: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    Audio_LoadSFX(rdram, ctx);
        goto after_2;
    // 0x80071B68: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    after_2:
    // 0x80071B6C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80071B70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80071B74: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x80071B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071B80: jr          $ra
    // 0x80071B84: nop

    return;
    // 0x80071B84: nop

;}

RECOMP_FUNC void func_80071B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071B8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80071B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071B98: jal         0x80071DEC
    // 0x80071B9C: nop

    func_80071DEC(rdram, ctx);
        goto after_0;
    // 0x80071B9C: nop

    after_0:
    // 0x80071BA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80071BA4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80071BA8: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x80071BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071BB4: jr          $ra
    // 0x80071BB8: nop

    return;
    // 0x80071BB8: nop

;}

RECOMP_FUNC void func_80071BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80071BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071BC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071BCC: jal         0x80071DEC
    // 0x80071BD0: nop

    func_80071DEC(rdram, ctx);
        goto after_0;
    // 0x80071BD0: nop

    after_0:
    // 0x80071BD4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80071BD8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80071BDC: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x80071BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071BE8: jr          $ra
    // 0x80071BEC: nop

    return;
    // 0x80071BEC: nop

;}

RECOMP_FUNC void displayPausePopupMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071BF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80071BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80071BFC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80071C00: jal         0x80085030
    // 0x80071C04: addiu       $a0, $a0, 0x3988
    ctx->r4 = ADD32(ctx->r4, 0X3988);
    Audio_LoadSFX(rdram, ctx);
        goto after_0;
    // 0x80071C04: addiu       $a0, $a0, 0x3988
    ctx->r4 = ADD32(ctx->r4, 0X3988);
    after_0:
    // 0x80071C08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80071C0C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80071C10: jal         0x80077408
    // 0x80071C14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Font_Init46Char(rdram, ctx);
        goto after_1;
    // 0x80071C14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80071C18: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80071C1C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80071C20: sb          $t6, 0x7C($t7)
    MEM_B(0X7C, ctx->r15) = ctx->r14;
    // 0x80071C24: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80071C28: nop

    // 0x80071C2C: lbu         $a0, 0x7C($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X7C);
    // 0x80071C30: nop

    // 0x80071C34: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80071C38: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80071C3C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80071C40: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80071C44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80071C48: jal         0x8007E03C
    // 0x80071C4C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80071C4C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x80071C50: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80071C54: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80071C58: sw          $v0, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r2;
    // 0x80071C5C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80071C60: addiu       $t2, $zero, 0x82
    ctx->r10 = ADD32(0, 0X82);
    // 0x80071C64: lw          $a0, 0x80($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X80);
    // 0x80071C68: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80071C6C: addiu       $a2, $a2, -0x2670
    ctx->r6 = ADD32(ctx->r6, -0X2670);
    // 0x80071C70: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80071C74: jal         0x80071730
    // 0x80071C78: addiu       $a1, $t1, 0x4
    ctx->r5 = ADD32(ctx->r9, 0X4);
    func_80071730(rdram, ctx);
        goto after_3;
    // 0x80071C78: addiu       $a1, $t1, 0x4
    ctx->r5 = ADD32(ctx->r9, 0X4);
    after_3:
    // 0x80071C7C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80071C80: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80071C84: lw          $a0, 0x80($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X80);
    // 0x80071C88: addiu       $t4, $zero, 0x96
    ctx->r12 = ADD32(0, 0X96);
    // 0x80071C8C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80071C90: addiu       $a2, $a2, -0x2664
    ctx->r6 = ADD32(ctx->r6, -0X2664);
    // 0x80071C94: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80071C98: addiu       $a1, $t3, 0x4
    ctx->r5 = ADD32(ctx->r11, 0X4);
    // 0x80071C9C: jal         0x80071730
    // 0x80071CA0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_80071730(rdram, ctx);
        goto after_4;
    // 0x80071CA0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_4:
    // 0x80071CA4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80071CA8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80071CAC: lw          $a0, 0x80($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X80);
    // 0x80071CB0: addiu       $t6, $zero, 0xAA
    ctx->r14 = ADD32(0, 0XAA);
    // 0x80071CB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80071CB8: addiu       $a2, $a2, -0x2658
    ctx->r6 = ADD32(ctx->r6, -0X2658);
    // 0x80071CBC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80071CC0: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    // 0x80071CC4: jal         0x80071730
    // 0x80071CC8: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    func_80071730(rdram, ctx);
        goto after_5;
    // 0x80071CC8: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    after_5:
    // 0x80071CCC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80071CD0: nop

    // 0x80071CD4: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x80071CD8: nop

    // 0x80071CDC: addiu       $t9, $t8, 0x34
    ctx->r25 = ADD32(ctx->r24, 0X34);
    // 0x80071CE0: sw          $t9, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r25;
    // 0x80071CE4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80071CE8: nop

    // 0x80071CEC: lw          $t1, 0x80($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X80);
    // 0x80071CF0: nop

    // 0x80071CF4: addiu       $t2, $t1, 0x68
    ctx->r10 = ADD32(ctx->r9, 0X68);
    // 0x80071CF8: sw          $t2, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->r10;
    // 0x80071CFC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80071D00: nop

    // 0x80071D04: lw          $t4, 0x80($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X80);
    // 0x80071D08: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80071D0C: sw          $t4, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->r12;
    // 0x80071D10: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80071D14: addiu       $t3, $t3, 0x1B44
    ctx->r11 = ADD32(ctx->r11, 0X1B44);
    // 0x80071D18: lw          $t6, 0x80($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X80);
    // 0x80071D1C: nop

    // 0x80071D20: addiu       $t7, $t6, 0x68
    ctx->r15 = ADD32(ctx->r14, 0X68);
    // 0x80071D24: sw          $t7, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r15;
    // 0x80071D28: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80071D2C: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80071D30: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x80071D34: addiu       $t7, $t7, 0x1B88
    ctx->r15 = ADD32(ctx->r15, 0X1B88);
    // 0x80071D38: sw          $t8, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r24;
    // 0x80071D3C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80071D40: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80071D44: lw          $t2, 0x80($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X80);
    // 0x80071D48: addiu       $t8, $t8, 0x1BBC
    ctx->r24 = ADD32(ctx->r24, 0X1BBC);
    // 0x80071D4C: addiu       $t1, $t2, 0x34
    ctx->r9 = ADD32(ctx->r10, 0X34);
    // 0x80071D50: sw          $t1, 0x8C($t2)
    MEM_W(0X8C, ctx->r10) = ctx->r9;
    // 0x80071D54: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80071D58: nop

    // 0x80071D5C: lw          $t5, 0x80($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X80);
    // 0x80071D60: nop

    // 0x80071D64: sw          $t3, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r11;
    // 0x80071D68: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80071D6C: nop

    // 0x80071D70: lw          $t9, 0x80($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X80);
    // 0x80071D74: nop

    // 0x80071D78: sw          $t7, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r15;
    // 0x80071D7C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80071D80: nop

    // 0x80071D84: lw          $t1, 0x80($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X80);
    // 0x80071D88: nop

    // 0x80071D8C: sw          $t8, 0x88($t1)
    MEM_W(0X88, ctx->r9) = ctx->r24;
    // 0x80071D90: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80071D94: nop

    // 0x80071D98: lw          $t4, 0x80($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X80);
    // 0x80071D9C: nop

    // 0x80071DA0: sw          $t4, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r12;
    // 0x80071DA4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80071DA8: nop

    // 0x80071DAC: lw          $a0, 0x84($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X84);
    // 0x80071DB0: jal         0x80071B08
    // 0x80071DB4: nop

    func_80071B08(rdram, ctx);
        goto after_6;
    // 0x80071DB4: nop

    after_6:
    // 0x80071DB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80071DBC: jal         0x800535B8
    // 0x80071DC0: addiu       $a0, $a0, -0x10D0
    ctx->r4 = ADD32(ctx->r4, -0X10D0);
    FUN_800535B8_fiveliner(rdram, ctx);
        goto after_7;
    // 0x80071DC0: addiu       $a0, $a0, -0x10D0
    ctx->r4 = ADD32(ctx->r4, -0X10D0);
    after_7:
    // 0x80071DC4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80071DC8: nop

    // 0x80071DCC: sb          $zero, 0x88($t5)
    MEM_B(0X88, ctx->r13) = 0;
    // 0x80071DD0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80071DD4: nop

    // 0x80071DD8: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80071DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80071DE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80071DE4: jr          $ra
    // 0x80071DE8: nop

    return;
    // 0x80071DE8: nop

;}

RECOMP_FUNC void func_80071DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071DF4: jal         0x8004A34C
    // 0x80071DF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x80071DF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071DFC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80071E00: nop

    // 0x80071E04: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    // 0x80071E08: jal         0x8007E328
    // 0x80071E0C: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80071E0C: nop

    after_1:
    // 0x80071E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071E14: jal         0x800773D0
    // 0x80071E18: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Font_Deinit(rdram, ctx);
        goto after_2;
    // 0x80071E18: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80071E1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80071E20: jal         0x800535B8
    // 0x80071E24: addiu       $a0, $a0, -0x10D0
    ctx->r4 = ADD32(ctx->r4, -0X10D0);
    FUN_800535B8_fiveliner(rdram, ctx);
        goto after_3;
    // 0x80071E24: addiu       $a0, $a0, -0x10D0
    ctx->r4 = ADD32(ctx->r4, -0X10D0);
    after_3:
    // 0x80071E28: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80071E2C: nop

    // 0x80071E30: sb          $zero, 0x88($t7)
    MEM_B(0X88, ctx->r15) = 0;
    // 0x80071E34: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80071E38: jal         0x8004A34C
    // 0x80071E3C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_4;
    // 0x80071E3C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    after_4:
    // 0x80071E40: jal         0x8004A34C
    // 0x80071E44: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_5;
    // 0x80071E44: nop

    after_5:
    // 0x80071E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071E50: jr          $ra
    // 0x80071E54: nop

    return;
    // 0x80071E54: nop

;}

RECOMP_FUNC void func_80071E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071E58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80071E5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80071E60: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80071E64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80071E68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071E6C: lbu         $t7, 0x89($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X89);
    // 0x80071E70: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80071E74: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80071E78: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80071E7C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80071E80: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80071E84: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80071E88: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80071E8C: lw          $s0, -0x10AC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X10AC);
    // 0x80071E90: nop

    // 0x80071E94: andi        $t9, $s0, 0x800
    ctx->r25 = ctx->r16 & 0X800;
    // 0x80071E98: beq         $t9, $zero, L_80071F08
    if (ctx->r25 == 0) {
        // 0x80071E9C: nop
    
            goto L_80071F08;
    }
    // 0x80071E9C: nop

    // 0x80071EA0: lw          $t0, 0x84($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X84);
    // 0x80071EA4: nop

    // 0x80071EA8: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80071EAC: nop

    // 0x80071EB0: beq         $t1, $zero, L_80071F08
    if (ctx->r9 == 0) {
        // 0x80071EB4: nop
    
            goto L_80071F08;
    }
    // 0x80071EB4: nop

    // 0x80071EB8: jal         0x80071B2C
    // 0x80071EBC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80071B2C(rdram, ctx);
        goto after_0;
    // 0x80071EBC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
    // 0x80071EC0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80071EC4: nop

    // 0x80071EC8: lw          $t3, 0x84($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X84);
    // 0x80071ECC: nop

    // 0x80071ED0: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80071ED4: nop

    // 0x80071ED8: sw          $t4, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r12;
    // 0x80071EDC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80071EE0: nop

    // 0x80071EE4: lw          $a0, 0x84($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X84);
    // 0x80071EE8: jal         0x80071B08
    // 0x80071EEC: nop

    func_80071B08(rdram, ctx);
        goto after_1;
    // 0x80071EEC: nop

    after_1:
    // 0x80071EF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80071EF4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80071EF8: addiu       $a1, $a1, 0x3988
    ctx->r5 = ADD32(ctx->r5, 0X3988);
    // 0x80071EFC: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80071F00: jal         0x8008A5C8
    // 0x80071F04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Audio2_Play_SFX(rdram, ctx);
        goto after_2;
    // 0x80071F04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80071F08:
    // 0x80071F08: andi        $t7, $s0, 0x400
    ctx->r15 = ctx->r16 & 0X400;
    // 0x80071F0C: beq         $t7, $zero, L_80071F84
    if (ctx->r15 == 0) {
        // 0x80071F10: nop
    
            goto L_80071F84;
    }
    // 0x80071F10: nop

    // 0x80071F14: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80071F18: nop

    // 0x80071F1C: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x80071F20: nop

    // 0x80071F24: lw          $t6, 0x28($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X28);
    // 0x80071F28: nop

    // 0x80071F2C: beq         $t6, $zero, L_80071F84
    if (ctx->r14 == 0) {
        // 0x80071F30: nop
    
            goto L_80071F84;
    }
    // 0x80071F30: nop

    // 0x80071F34: jal         0x80071B2C
    // 0x80071F38: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80071B2C(rdram, ctx);
        goto after_3;
    // 0x80071F38: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x80071F3C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80071F40: nop

    // 0x80071F44: lw          $t0, 0x84($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X84);
    // 0x80071F48: nop

    // 0x80071F4C: lw          $t3, 0x28($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X28);
    // 0x80071F50: nop

    // 0x80071F54: sw          $t3, 0x84($t1)
    MEM_W(0X84, ctx->r9) = ctx->r11;
    // 0x80071F58: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80071F5C: nop

    // 0x80071F60: lw          $a0, 0x84($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X84);
    // 0x80071F64: jal         0x80071B08
    // 0x80071F68: nop

    func_80071B08(rdram, ctx);
        goto after_4;
    // 0x80071F68: nop

    after_4:
    // 0x80071F6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80071F70: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80071F74: addiu       $a1, $a1, 0x3988
    ctx->r5 = ADD32(ctx->r5, 0X3988);
    // 0x80071F78: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80071F7C: jal         0x8008A5C8
    // 0x80071F80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Audio2_Play_SFX(rdram, ctx);
        goto after_5;
    // 0x80071F80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80071F84:
    // 0x80071F84: andi        $t2, $s0, 0x100
    ctx->r10 = ctx->r16 & 0X100;
    // 0x80071F88: beq         $t2, $zero, L_80071FE8
    if (ctx->r10 == 0) {
        // 0x80071F8C: nop
    
            goto L_80071FE8;
    }
    // 0x80071F8C: nop

    // 0x80071F90: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80071F94: nop

    // 0x80071F98: lw          $t7, 0x84($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X84);
    // 0x80071F9C: nop

    // 0x80071FA0: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80071FA4: nop

    // 0x80071FA8: beq         $t8, $zero, L_80071FE8
    if (ctx->r24 == 0) {
        // 0x80071FAC: nop
    
            goto L_80071FE8;
    }
    // 0x80071FAC: nop

    // 0x80071FB0: jal         0x80071B2C
    // 0x80071FB4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80071B2C(rdram, ctx);
        goto after_6;
    // 0x80071FB4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_6:
    // 0x80071FB8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80071FBC: nop

    // 0x80071FC0: lw          $t9, 0x84($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X84);
    // 0x80071FC4: nop

    // 0x80071FC8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x80071FCC: nop

    // 0x80071FD0: sw          $t0, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->r8;
    // 0x80071FD4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80071FD8: nop

    // 0x80071FDC: lw          $a0, 0x84($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X84);
    // 0x80071FE0: jal         0x80071B08
    // 0x80071FE4: nop

    func_80071B08(rdram, ctx);
        goto after_7;
    // 0x80071FE4: nop

    after_7:
L_80071FE8:
    // 0x80071FE8: andi        $t1, $s0, 0x200
    ctx->r9 = ctx->r16 & 0X200;
    // 0x80071FEC: beq         $t1, $zero, L_8007204C
    if (ctx->r9 == 0) {
        // 0x80071FF0: nop
    
            goto L_8007204C;
    }
    // 0x80071FF0: nop

    // 0x80071FF4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80071FF8: nop

    // 0x80071FFC: lw          $t2, 0x84($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X84);
    // 0x80072000: nop

    // 0x80072004: lw          $t5, 0x2C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X2C);
    // 0x80072008: nop

    // 0x8007200C: beq         $t5, $zero, L_8007204C
    if (ctx->r13 == 0) {
        // 0x80072010: nop
    
            goto L_8007204C;
    }
    // 0x80072010: nop

    // 0x80072014: jal         0x80071B2C
    // 0x80072018: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_80071B2C(rdram, ctx);
        goto after_8;
    // 0x80072018: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_8:
    // 0x8007201C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80072020: nop

    // 0x80072024: lw          $t7, 0x84($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X84);
    // 0x80072028: nop

    // 0x8007202C: lw          $t9, 0x2C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X2C);
    // 0x80072030: nop

    // 0x80072034: sw          $t9, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->r25;
    // 0x80072038: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007203C: nop

    // 0x80072040: lw          $a0, 0x84($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X84);
    // 0x80072044: jal         0x80071B08
    // 0x80072048: nop

    func_80071B08(rdram, ctx);
        goto after_9;
    // 0x80072048: nop

    after_9:
L_8007204C:
    // 0x8007204C: andi        $t6, $s0, 0x8000
    ctx->r14 = ctx->r16 & 0X8000;
    // 0x80072050: beq         $t6, $zero, L_800720B0
    if (ctx->r14 == 0) {
        // 0x80072054: nop
    
            goto L_800720B0;
    }
    // 0x80072054: nop

    // 0x80072058: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8007205C: nop

    // 0x80072060: lw          $t1, 0x84($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X84);
    // 0x80072064: nop

    // 0x80072068: lw          $t4, 0x20($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X20);
    // 0x8007206C: nop

    // 0x80072070: beq         $t4, $zero, L_800720B0
    if (ctx->r12 == 0) {
        // 0x80072074: nop
    
            goto L_800720B0;
    }
    // 0x80072074: nop

    // 0x80072078: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007207C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80072080: addiu       $a1, $a1, 0x3988
    ctx->r5 = ADD32(ctx->r5, 0X3988);
    // 0x80072084: addiu       $a0, $a0, 0x35B0
    ctx->r4 = ADD32(ctx->r4, 0X35B0);
    // 0x80072088: jal         0x8008A5C8
    // 0x8007208C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio2_Play_SFX(rdram, ctx);
        goto after_10;
    // 0x8007208C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x80072090: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80072094: nop

    // 0x80072098: lw          $t2, 0x84($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X84);
    // 0x8007209C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800720A0: lw          $t9, 0x20($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X20);
    // 0x800720A4: nop

    // 0x800720A8: jalr        $t9
    // 0x800720AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800720AC: nop

    after_11:
L_800720B0:
    // 0x800720B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800720B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800720B8: jr          $ra
    // 0x800720BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800720BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800720C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800720C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800720C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800720C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800720CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800720D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800720D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800720D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800720DC: sb          $t6, 0x88($t7)
    MEM_B(0X88, ctx->r15) = ctx->r14;
    // 0x800720E0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800720E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800720E8: lbu         $t9, 0x7C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7C);
    // 0x800720EC: lw          $s0, 0x80($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X80);
    // 0x800720F0: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800720F4: beq         $at, $zero, L_80072120
    if (ctx->r1 == 0) {
        // 0x800720F8: nop
    
            goto L_80072120;
    }
    // 0x800720F8: nop

L_800720FC:
    // 0x800720FC: jal         0x8007183C
    // 0x80072100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007183C(rdram, ctx);
        goto after_0;
    // 0x80072100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80072104: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80072108: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007210C: lbu         $t1, 0x7C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X7C);
    // 0x80072110: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x80072114: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80072118: bne         $at, $zero, L_800720FC
    if (ctx->r1 != 0) {
        // 0x8007211C: nop
    
            goto L_800720FC;
    }
    // 0x8007211C: nop

L_80072120:
    // 0x80072120: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80072124: jal         0x80071E58
    // 0x80072128: nop

    func_80071E58(rdram, ctx);
        goto after_1;
    // 0x80072128: nop

    after_1:
    // 0x8007212C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072130: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80072134: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80072138: jr          $ra
    // 0x8007213C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007213C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_80072140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072148: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007214C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072150: jal         0x8007E03C
    // 0x80072154: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    n64HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80072154: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80072158: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007215C: sw          $v0, 0x5C0($at)
    MEM_W(0X5C0, ctx->r1) = ctx->r2;
    // 0x80072160: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80072164: lw          $s0, 0x5C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5C0);
    // 0x80072168: nop

    // 0x8007216C: bne         $s0, $zero, L_8007217C
    if (ctx->r16 != 0) {
        // 0x80072170: nop
    
            goto L_8007217C;
    }
    // 0x80072170: nop

    // 0x80072174: b           L_80072194
    // 0x80072178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80072194;
    // 0x80072178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007217C:
    // 0x8007217C: sb          $zero, 0x88($s0)
    MEM_B(0X88, ctx->r16) = 0;
    // 0x80072180: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80072184: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072188: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8007218C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80072190: sb          $t6, 0x89($s0)
    MEM_B(0X89, ctx->r16) = ctx->r14;
L_80072194:
    // 0x80072194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007219C: jr          $ra
    // 0x800721A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800721A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_800721A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800721A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800721A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800721AC: jal         0x8004A34C
    // 0x800721B0: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x800721B0: nop

    after_0:
    // 0x800721B4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800721B8: lw          $a0, 0x5C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5C0);
    // 0x800721BC: jal         0x8007E328
    // 0x800721C0: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x800721C0: nop

    after_1:
    // 0x800721C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800721C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800721CC: sw          $zero, 0x5C0($at)
    MEM_W(0X5C0, ctx->r1) = 0;
    // 0x800721D0: jr          $ra
    // 0x800721D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800721D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}

RECOMP_FUNC void func_800721D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800721D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800721DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800721E0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800721E4: lw          $s0, 0x5C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5C0);
    // 0x800721E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800721EC: bne         $s0, $zero, L_800721FC
    if (ctx->r16 != 0) {
        // 0x800721F0: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_800721FC;
    }
    // 0x800721F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800721F4: b           L_80072234
    // 0x800721F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80072234;
    // 0x800721F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800721FC:
    // 0x800721FC: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x80072200: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80072204: beq         $s1, $zero, L_80072224
    if (ctx->r17 == 0) {
        // 0x80072208: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80072224;
    }
    // 0x80072208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007220C: bne         $s1, $at, L_8007222C
    if (ctx->r17 != ctx->r1) {
        // 0x80072210: nop
    
            goto L_8007222C;
    }
    // 0x80072210: nop

    // 0x80072214: jal         0x80071BF0
    // 0x80072218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    displayPausePopupMenu(rdram, ctx);
        goto after_0;
    // 0x80072218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007221C: b           L_8007222C
    // 0x80072220: nop

        goto L_8007222C;
    // 0x80072220: nop

L_80072224:
    // 0x80072224: jal         0x800720C0
    // 0x80072228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800720C0(rdram, ctx);
        goto after_1;
    // 0x80072228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8007222C:
    // 0x8007222C: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80072230: nop

L_80072234:
    // 0x80072234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072238: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007223C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80072240: jr          $ra
    // 0x80072244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

RECOMP_FUNC void func_80072248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072248: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007224C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072250: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80072254: lw          $s0, 0x5C0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5C0);
    // 0x80072258: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007225C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80072260: beq         $s0, $zero, L_800722C4
    if (ctx->r16 == 0) {
        // 0x80072264: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_800722C4;
    }
    // 0x80072264: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80072268: lbu         $t6, 0x88($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X88);
    // 0x8007226C: nop

    // 0x80072270: beq         $t6, $zero, L_800722C4
    if (ctx->r14 == 0) {
        // 0x80072274: nop
    
            goto L_800722C4;
    }
    // 0x80072274: nop

    // 0x80072278: lw          $s1, 0x80($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X80);
    // 0x8007227C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072280: jal         0x8005BBFC
    // 0x80072284: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_8005BBFC(rdram, ctx);
        goto after_0;
    // 0x80072284: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_0:
    // 0x80072288: lbu         $t7, 0x7C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7C);
    // 0x8007228C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80072290: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80072294: beq         $at, $zero, L_800722B8
    if (ctx->r1 == 0) {
        // 0x80072298: nop
    
            goto L_800722B8;
    }
    // 0x80072298: nop

L_8007229C:
    // 0x8007229C: jal         0x80071A40
    // 0x800722A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80071A40(rdram, ctx);
        goto after_1;
    // 0x800722A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800722A4: lbu         $t8, 0x7C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7C);
    // 0x800722A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800722AC: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800722B0: bne         $at, $zero, L_8007229C
    if (ctx->r1 != 0) {
        // 0x800722B4: addiu       $s1, $s1, 0x34
        ctx->r17 = ADD32(ctx->r17, 0X34);
            goto L_8007229C;
    }
    // 0x800722B4: addiu       $s1, $s1, 0x34
    ctx->r17 = ADD32(ctx->r17, 0X34);
L_800722B8:
    // 0x800722B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800722BC: jal         0x8005BE40
    // 0x800722C0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_8005BE40(rdram, ctx);
        goto after_2;
    // 0x800722C0: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_2:
L_800722C4:
    // 0x800722C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800722C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800722CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800722D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800722D4: jr          $ra
    // 0x800722D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800722D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800722DC: nop

;}

RECOMP_FUNC void func_800722E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800722E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800722E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800722E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800722EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800722F0: jr          $ra
    // 0x800722F4: nop

    return;
    // 0x800722F4: nop

    // 0x800722F8: nop

    // 0x800722FC: nop

;}

RECOMP_FUNC void func_80072300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072300: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80072304: lw          $a1, -0x390($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X390);
    // 0x80072308: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8007230C: lbu         $t6, 0x30($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X30);
    // 0x80072310: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80072314: bne         $t6, $a0, L_80072324
    if (ctx->r14 != ctx->r4) {
        // 0x80072318: nop
    
            goto L_80072324;
    }
    // 0x80072318: nop

    // 0x8007231C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072320: sb          $t7, 0x31($a1)
    MEM_B(0X31, ctx->r5) = ctx->r15;
L_80072324:
    // 0x80072324: jr          $ra
    // 0x80072328: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80072328: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void func_8007232C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007232C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072330: lbu         $t6, -0x10E0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X10E0);
    // 0x80072334: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007233C: lw          $a0, -0x390($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X390);
    // 0x80072340: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80072344: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80072348: beq         $at, $zero, L_80072398
    if (ctx->r1 == 0) {
        // 0x8007234C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80072398;
    }
    // 0x8007234C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80072350:
    // 0x80072350: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80072354: lw          $t7, -0x390($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X390);
    // 0x80072358: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8007235C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80072360: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80072364: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80072368: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007236C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80072370: nop

    // 0x80072374: beq         $t1, $zero, L_80072380
    if (ctx->r9 == 0) {
        // 0x80072378: nop
    
            goto L_80072380;
    }
    // 0x80072378: nop

    // 0x8007237C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80072380:
    // 0x80072380: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072384: lbu         $t2, -0x10E0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X10E0);
    // 0x80072388: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007238C: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80072390: bne         $at, $zero, L_80072350
    if (ctx->r1 != 0) {
        // 0x80072394: nop
    
            goto L_80072350;
    }
    // 0x80072394: nop

L_80072398:
    // 0x80072398: jr          $ra
    // 0x8007239C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007239C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
