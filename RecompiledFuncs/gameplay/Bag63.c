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
