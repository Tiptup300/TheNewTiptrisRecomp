#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lzo_assert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080FE0: beq         $a0, $zero, L_80080FF0
    if (ctx->r4 == 0) {
        // 0x80080FE4: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_80080FF0;
    }
    // 0x80080FE4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80080FE8: b           L_80080FF4
    // 0x80080FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80080FF4;
    // 0x80080FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80080FF0:
    // 0x80080FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80080FF4:
    // 0x80080FF4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80080FF8: jr          $ra
    // 0x80080FFC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080FFC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void lzo_copyright(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081000: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80081004: jr          $ra
    // 0x80081008: addiu       $v0, $v0, -0x15D0
    ctx->r2 = ADD32(ctx->r2, -0X15D0);
    return;
    // 0x80081008: addiu       $v0, $v0, -0x15D0
    ctx->r2 = ADD32(ctx->r2, -0X15D0);
;}

RECOMP_FUNC void lzo_version(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008100C: jr          $ra
    // 0x80081010: addiu       $v0, $zero, 0x1040
    ctx->r2 = ADD32(0, 0X1040);
    return;
    // 0x80081010: addiu       $v0, $zero, 0x1040
    ctx->r2 = ADD32(0, 0X1040);
;}

RECOMP_FUNC void lzo_version_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081014: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80081018: jr          $ra
    // 0x8008101C: addiu       $v0, $v0, -0x15CC
    ctx->r2 = ADD32(ctx->r2, -0X15CC);
    return;
    // 0x8008101C: addiu       $v0, $v0, -0x15CC
    ctx->r2 = ADD32(ctx->r2, -0X15CC);
;}

RECOMP_FUNC void lzo_version_date(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081020: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80081024: jr          $ra
    // 0x80081028: addiu       $v0, $v0, -0x15C4
    ctx->r2 = ADD32(ctx->r2, -0X15C4);
    return;
    // 0x80081028: addiu       $v0, $v0, -0x15C4
    ctx->r2 = ADD32(ctx->r2, -0X15C4);
;}

RECOMP_FUNC void lzo_adler32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081044: srl         $t7, $a0, 16
    ctx->r15 = S32(U32(ctx->r4) >> 16);
    // 0x80081048: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008104C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80081050: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80081054: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80081058: bne         $a1, $zero, L_80081068
    if (ctx->r5 != 0) {
        // 0x8008105C: sw          $t8, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r24;
            goto L_80081068;
    }
    // 0x8008105C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x80081060: b           L_800812BC
    // 0x80081064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800812BC;
    // 0x80081064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081068:
    // 0x80081068: beq         $a2, $zero, L_800812AC
    if (ctx->r6 == 0) {
        // 0x8008106C: sltiu       $at, $a2, 0x15B0
        ctx->r1 = ctx->r6 < 0X15B0 ? 1 : 0;
            goto L_800812AC;
    }
L_8008106C:
    // 0x8008106C: sltiu       $at, $a2, 0x15B0
    ctx->r1 = ctx->r6 < 0X15B0 ? 1 : 0;
    // 0x80081070: beq         $at, $zero, L_80081080
    if (ctx->r1 == 0) {
        // 0x80081074: nop
    
            goto L_80081080;
    }
    // 0x80081074: nop

    // 0x80081078: b           L_80081088
    // 0x8008107C: sw          $a2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r6;
        goto L_80081088;
    // 0x8008107C: sw          $a2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r6;
L_80081080:
    // 0x80081080: addiu       $t9, $zero, 0x15B0
    ctx->r25 = ADD32(0, 0X15B0);
    // 0x80081084: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_80081088:
    // 0x80081088: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008108C: nop

    // 0x80081090: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80081094: bne         $at, $zero, L_8008123C
    if (ctx->r1 != 0) {
        // 0x80081098: subu        $a2, $a2, $t0
        ctx->r6 = SUB32(ctx->r6, ctx->r8);
            goto L_8008123C;
    }
    // 0x80081098: subu        $a2, $a2, $t0
    ctx->r6 = SUB32(ctx->r6, ctx->r8);
L_8008109C:
    // 0x8008109C: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800810A0: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x800810A4: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800810A8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800810AC: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800810B0: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x800810B4: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800810B8: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x800810BC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800810C0: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800810C4: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800810C8: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800810CC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800810D0: lbu         $t0, 0x2($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X2);
    // 0x800810D4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800810D8: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x800810DC: addu        $t4, $t2, $t1
    ctx->r12 = ADD32(ctx->r10, ctx->r9);
    // 0x800810E0: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x800810E4: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800810E8: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x800810EC: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800810F0: addu        $t3, $t1, $t5
    ctx->r11 = ADD32(ctx->r9, ctx->r13);
    // 0x800810F4: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x800810F8: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800810FC: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x80081100: lbu         $t9, 0x4($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X4);
    // 0x80081104: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x80081108: addu        $t7, $t3, $t9
    ctx->r15 = ADD32(ctx->r11, ctx->r25);
    // 0x8008110C: addu        $t2, $t0, $t7
    ctx->r10 = ADD32(ctx->r8, ctx->r15);
    // 0x80081110: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x80081114: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x80081118: lbu         $t4, 0x5($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X5);
    // 0x8008111C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x80081120: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x80081124: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x80081128: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8008112C: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x80081130: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x80081134: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80081138: addu        $t3, $t1, $t8
    ctx->r11 = ADD32(ctx->r9, ctx->r24);
    // 0x8008113C: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x80081140: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x80081144: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x80081148: lbu         $t2, 0x7($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X7);
    // 0x8008114C: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x80081150: addu        $t7, $t3, $t2
    ctx->r15 = ADD32(ctx->r11, ctx->r10);
    // 0x80081154: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x80081158: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8008115C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x80081160: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80081164: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80081168: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x8008116C: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x80081170: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80081174: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x80081178: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x8008117C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x80081180: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x80081184: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80081188: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8008118C: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x80081190: lbu         $t5, 0xA($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XA);
    // 0x80081194: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80081198: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8008119C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800811A0: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800811A4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800811A8: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x800811AC: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800811B0: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800811B4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800811B8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800811BC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800811C0: lbu         $t4, 0xC($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XC);
    // 0x800811C4: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800811C8: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800811CC: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x800811D0: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800811D4: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800811D8: lbu         $t8, 0xD($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XD);
    // 0x800811DC: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800811E0: addu        $t7, $t3, $t8
    ctx->r15 = ADD32(ctx->r11, ctx->r24);
    // 0x800811E4: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x800811E8: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x800811EC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800811F0: lbu         $t2, 0xE($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XE);
    // 0x800811F4: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800811F8: addu        $t1, $t7, $t2
    ctx->r9 = ADD32(ctx->r15, ctx->r10);
    // 0x800811FC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80081200: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80081204: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x80081208: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8008120C: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x80081210: addiu       $t7, $t0, -0x10
    ctx->r15 = ADD32(ctx->r8, -0X10);
    // 0x80081214: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80081218: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8008121C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80081220: addu        $t3, $t1, $t6
    ctx->r11 = ADD32(ctx->r9, ctx->r14);
    // 0x80081224: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x80081228: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x8008122C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80081230: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x80081234: beq         $at, $zero, L_8008109C
    if (ctx->r1 == 0) {
        // 0x80081238: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8008109C;
    }
    // 0x80081238: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_8008123C:
    // 0x8008123C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80081240: nop

    // 0x80081244: beq         $t4, $zero, L_8008127C
    if (ctx->r12 == 0) {
        // 0x80081248: nop
    
            goto L_8008127C;
    }
    // 0x80081248: nop

L_8008124C:
    // 0x8008124C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x80081250: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x80081254: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x80081258: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008125C: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x80081260: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x80081264: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80081268: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8008126C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80081270: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80081274: bgtz        $t0, L_8008124C
    if (SIGNED(ctx->r8) > 0) {
        // 0x80081278: sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
            goto L_8008124C;
    }
    // 0x80081278: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_8008127C:
    // 0x8008127C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80081280: ori         $at, $zero, 0xFFF1
    ctx->r1 = 0 | 0XFFF1;
    // 0x80081284: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80081288: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8008128C: mfhi        $t2
    ctx->r10 = hi;
    // 0x80081290: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x80081294: nop

    // 0x80081298: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x8008129C: mfhi        $t5
    ctx->r13 = hi;
    // 0x800812A0: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x800812A4: bne         $a2, $zero, L_8008106C
    if (ctx->r6 != 0) {
        // 0x800812A8: nop
    
            goto L_8008106C;
    }
    // 0x800812A8: nop

L_800812AC:
    // 0x800812AC: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800812B0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800812B4: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x800812B8: or          $v0, $t8, $t6
    ctx->r2 = ctx->r24 | ctx->r14;
L_800812BC:
    // 0x800812BC: jr          $ra
    // 0x800812C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800812C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void lzo_memcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800812C4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800812C8: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800812CC: beq         $a2, $zero, L_8008131C
    if (ctx->r6 == 0) {
        // 0x800812D0: sw          $a1, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r5;
            goto L_8008131C;
    }
    // 0x800812D0: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
L_800812D4:
    // 0x800812D4: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800812D8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800812DC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800812E0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800812E4: nop

    // 0x800812E8: subu        $t0, $t7, $t9
    ctx->r8 = SUB32(ctx->r15, ctx->r25);
    // 0x800812EC: beq         $t0, $zero, L_800812FC
    if (ctx->r8 == 0) {
        // 0x800812F0: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800812FC;
    }
    // 0x800812F0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800812F4: b           L_80081320
    // 0x800812F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80081320;
    // 0x800812F8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800812FC:
    // 0x800812FC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80081300: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80081304: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80081308: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008130C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80081310: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x80081314: bne         $a2, $zero, L_800812D4
    if (ctx->r6 != 0) {
        // 0x80081318: sw          $t4, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r12;
            goto L_800812D4;
    }
    // 0x80081318: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
L_8008131C:
    // 0x8008131C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081320:
    // 0x80081320: jr          $ra
    // 0x80081324: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80081324: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}

RECOMP_FUNC void lzo_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081328: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008132C: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80081330: beq         $a2, $zero, L_8008134C
    if (ctx->r6 == 0) {
        // 0x80081334: sw          $a1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r5;
            goto L_8008134C;
    }
    // 0x80081334: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // 0x80081338: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008133C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80081340: nop

    // 0x80081344: bne         $t6, $t7, L_80081354
    if (ctx->r14 != ctx->r15) {
        // 0x80081348: nop
    
            goto L_80081354;
    }
    // 0x80081348: nop

L_8008134C:
    // 0x8008134C: b           L_80081388
    // 0x80081350: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80081388;
    // 0x80081350: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80081354:
    // 0x80081354: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80081358: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008135C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80081360: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80081364: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x80081368: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8008136C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80081370: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80081374: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80081378: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8008137C: bne         $a2, $zero, L_80081354
    if (ctx->r6 != 0) {
        // 0x80081380: sw          $t4, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r12;
            goto L_80081354;
    }
    // 0x80081380: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x80081384: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80081388:
    // 0x80081388: jr          $ra
    // 0x8008138C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008138C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void lzo_memmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081390: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081394: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80081398: beq         $a2, $zero, L_800813B4
    if (ctx->r6 == 0) {
        // 0x8008139C: sw          $a1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r5;
            goto L_800813B4;
    }
    // 0x8008139C: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // 0x800813A0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800813A4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800813A8: nop

    // 0x800813AC: bne         $t6, $t7, L_800813BC
    if (ctx->r14 != ctx->r15) {
        // 0x800813B0: nop
    
            goto L_800813BC;
    }
    // 0x800813B0: nop

L_800813B4:
    // 0x800813B4: b           L_80081450
    // 0x800813B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80081450;
    // 0x800813B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800813BC:
    // 0x800813BC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800813C0: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800813C4: nop

    // 0x800813C8: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x800813CC: beq         $at, $zero, L_8008140C
    if (ctx->r1 == 0) {
        // 0x800813D0: nop
    
            goto L_8008140C;
    }
    // 0x800813D0: nop

L_800813D4:
    // 0x800813D4: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800813D8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800813DC: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800813E0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800813E4: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x800813E8: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800813EC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800813F0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800813F4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800813F8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800813FC: bne         $a2, $zero, L_800813D4
    if (ctx->r6 != 0) {
        // 0x80081400: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800813D4;
    }
    // 0x80081400: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80081404: b           L_8008144C
    // 0x80081408: nop

        goto L_8008144C;
    // 0x80081408: nop

L_8008140C:
    // 0x8008140C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80081410: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80081414: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80081418: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x8008141C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80081420: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_80081424:
    // 0x80081424: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80081428: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8008142C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80081430: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80081434: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x80081438: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8008143C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80081440: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80081444: bne         $a2, $zero, L_80081424
    if (ctx->r6 != 0) {
        // 0x80081448: sb          $t5, 0x0($t2)
        MEM_B(0X0, ctx->r10) = ctx->r13;
            goto L_80081424;
    }
    // 0x80081448: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
L_8008144C:
    // 0x8008144C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80081450:
    // 0x80081450: jr          $ra
    // 0x80081454: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80081454: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void lzo_memset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081458: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008145C: beq         $a2, $zero, L_80081484
    if (ctx->r6 == 0) {
        // 0x80081460: sw          $a0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r4;
            goto L_80081484;
    }
    // 0x80081460: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
L_80081464:
    // 0x80081464: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80081468: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008146C: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x80081470: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80081474: nop

    // 0x80081478: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008147C: bne         $a2, $zero, L_80081464
    if (ctx->r6 != 0) {
        // 0x80081480: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_80081464;
    }
    // 0x80081480: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_80081484:
    // 0x80081484: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80081488: jr          $ra
    // 0x8008148C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008148C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void basic_integral_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081490: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081494: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081498: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008149C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800814A0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800814A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800814A8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800814AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800814B0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800814B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800814B8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800814BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800814C0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800814C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800814C8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800814CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800814D0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800814D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800814D8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800814DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800814E0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800814E4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800814E8: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800814EC: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800814F0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800814F4: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800814F8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800814FC: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80081500: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80081504: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80081508: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008150C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80081510: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80081514: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80081518: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008151C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80081520: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x80081524: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80081528: jr          $ra
    // 0x8008152C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008152C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void basic_ptr_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081530: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80081534: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081538: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008153C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80081540: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80081544: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80081548: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8008154C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80081550: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80081554: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80081558: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008155C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80081560: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80081564: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80081568: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8008156C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80081570: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80081574: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80081578: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008157C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80081580: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80081584: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80081588: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8008158C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80081590: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80081594: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80081598: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8008159C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800815A0: jr          $ra
    // 0x800815A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800815A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

RECOMP_FUNC void ptr_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800815A8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800815AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800815B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800815B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800815B8: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x800815BC: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_800815C0:
    // 0x800815C0: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800815C4: nop

    // 0x800815C8: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x800815CC: sb          $t7, 0x44($t8)
    MEM_B(0X44, ctx->r24) = ctx->r15;
    // 0x800815D0: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800815D4: nop

    // 0x800815D8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800815DC: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800815E0: bne         $at, $zero, L_800815C0
    if (ctx->r1 != 0) {
        // 0x800815E4: sw          $t0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r8;
            goto L_800815C0;
    }
    // 0x800815E4: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x800815E8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800815EC: jal         0x80080F74
    // 0x800815F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    __lzo_align_gap(rdram, ctx);
        goto after_0;
    // 0x800815F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800815F4: addiu       $t1, $sp, 0x5C
    ctx->r9 = ADD32(ctx->r29, 0X5C);
    // 0x800815F8: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x800815FC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x80081600: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80081604: nop

    // 0x80081608: subu        $t4, $t3, $t1
    ctx->r12 = SUB32(ctx->r11, ctx->r9);
    // 0x8008160C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80081610: bltz        $t4, L_80081620
    if (SIGNED(ctx->r12) < 0) {
        // 0x80081614: sw          $t3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r11;
            goto L_80081620;
    }
    // 0x80081614: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80081618: b           L_80081624
    // 0x8008161C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081624;
    // 0x8008161C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081620:
    // 0x80081620: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081624:
    // 0x80081624: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80081628: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008162C: and         $t6, $t5, $s0
    ctx->r14 = ctx->r13 & ctx->r16;
    // 0x80081630: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80081634: beq         $at, $zero, L_80081644
    if (ctx->r1 == 0) {
        // 0x80081638: sw          $t6, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r14;
            goto L_80081644;
    }
    // 0x80081638: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x8008163C: b           L_80081648
    // 0x80081640: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081648;
    // 0x80081640: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081644:
    // 0x80081644: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081648:
    // 0x80081648: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8008164C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80081650: and         $t9, $t8, $s0
    ctx->r25 = ctx->r24 & ctx->r16;
    // 0x80081654: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x80081658: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008165C: jal         0x80081458
    // 0x80081660: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    lzo_memset(rdram, ctx);
        goto after_1;
    // 0x80081660: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80081664: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
    // 0x80081668: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8008166C: bne         $t0, $at, L_8008167C
    if (ctx->r8 != ctx->r1) {
        // 0x80081670: nop
    
            goto L_8008167C;
    }
    // 0x80081670: nop

    // 0x80081674: b           L_80081680
    // 0x80081678: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081680;
    // 0x80081678: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008167C:
    // 0x8008167C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081680:
    // 0x80081680: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80081684: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80081688: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008168C: and         $t3, $t2, $s0
    ctx->r11 = ctx->r10 & ctx->r16;
    // 0x80081690: bne         $t1, $at, L_800816A0
    if (ctx->r9 != ctx->r1) {
        // 0x80081694: sw          $t3, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r11;
            goto L_800816A0;
    }
    // 0x80081694: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x80081698: b           L_800816A4
    // 0x8008169C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800816A4;
    // 0x8008169C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800816A0:
    // 0x800816A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800816A4:
    // 0x800816A4: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800816A8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800816AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800816B0: and         $t5, $t4, $s0
    ctx->r13 = ctx->r12 & ctx->r16;
    // 0x800816B4: bne         $t6, $at, L_800816C4
    if (ctx->r14 != ctx->r1) {
        // 0x800816B8: sw          $t5, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r13;
            goto L_800816C4;
    }
    // 0x800816B8: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
    // 0x800816BC: b           L_800816C8
    // 0x800816C0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800816C8;
    // 0x800816C0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800816C4:
    // 0x800816C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800816C8:
    // 0x800816C8: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800816CC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800816D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800816D4: and         $t8, $t7, $s0
    ctx->r24 = ctx->r15 & ctx->r16;
    // 0x800816D8: bne         $t9, $at, L_800816E8
    if (ctx->r25 != ctx->r1) {
        // 0x800816DC: sw          $t8, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r24;
            goto L_800816E8;
    }
    // 0x800816DC: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x800816E0: b           L_800816EC
    // 0x800816E4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800816EC;
    // 0x800816E4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800816E8:
    // 0x800816E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800816EC:
    // 0x800816EC: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x800816F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800816F4: and         $t2, $t0, $s0
    ctx->r10 = ctx->r8 & ctx->r16;
    // 0x800816F8: bne         $t2, $at, L_80081754
    if (ctx->r10 != ctx->r1) {
        // 0x800816FC: sw          $t2, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r10;
            goto L_80081754;
    }
    // 0x800816FC: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x80081700: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_80081704:
    // 0x80081704: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x80081708: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8008170C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80081710: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80081714: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80081718: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8008171C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80081720: bne         $t5, $t8, L_80081730
    if (ctx->r13 != ctx->r24) {
        // 0x80081724: nop
    
            goto L_80081730;
    }
    // 0x80081724: nop

    // 0x80081728: b           L_80081734
    // 0x8008172C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081734;
    // 0x8008172C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081730:
    // 0x80081730: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081734:
    // 0x80081734: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x80081738: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8008173C: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80081740: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80081744: and         $t0, $t9, $s0
    ctx->r8 = ctx->r25 & ctx->r16;
    // 0x80081748: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8008174C: bne         $at, $zero, L_80081704
    if (ctx->r1 != 0) {
        // 0x80081750: sw          $t0, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r8;
            goto L_80081704;
    }
    // 0x80081750: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
L_80081754:
    // 0x80081754: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80081758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008175C: jal         0x80081458
    // 0x80081760: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    lzo_memset(rdram, ctx);
        goto after_2;
    // 0x80081760: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80081764: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80081768: nop

    // 0x8008176C: bne         $t4, $zero, L_8008177C
    if (ctx->r12 != 0) {
        // 0x80081770: nop
    
            goto L_8008177C;
    }
    // 0x80081770: nop

    // 0x80081774: b           L_80081780
    // 0x80081778: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081780;
    // 0x80081778: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008177C:
    // 0x8008177C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081780:
    // 0x80081780: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x80081784: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80081788: and         $t6, $t3, $s0
    ctx->r14 = ctx->r11 & ctx->r16;
    // 0x8008178C: bne         $t7, $zero, L_8008179C
    if (ctx->r15 != 0) {
        // 0x80081790: sw          $t6, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r14;
            goto L_8008179C;
    }
    // 0x80081790: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x80081794: b           L_800817A0
    // 0x80081798: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800817A0;
    // 0x80081798: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008179C:
    // 0x8008179C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800817A0:
    // 0x800817A0: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x800817A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800817A8: and         $t8, $t5, $s0
    ctx->r24 = ctx->r13 & ctx->r16;
    // 0x800817AC: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x800817B0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800817B4: bne         $t9, $at, L_800818BC
    if (ctx->r25 != ctx->r1) {
        // 0x800817B8: sw          $t9, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r25;
            goto L_800818BC;
    }
    // 0x800817B8: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x800817BC: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_800817C0:
    // 0x800817C0: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800817C4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800817C8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800817CC: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800817D0: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x800817D4: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800817D8: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800817DC: nop

    // 0x800817E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800817E4: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x800817E8: bne         $at, $zero, L_800817C0
    if (ctx->r1 != 0) {
        // 0x800817EC: sw          $t7, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r15;
            goto L_800817C0;
    }
    // 0x800817EC: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x800817F0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800817F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800817F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800817FC: jal         0x80081458
    // 0x80081800: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    lzo_memset(rdram, ctx);
        goto after_3;
    // 0x80081800: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80081804: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80081808: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8008180C: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80081810: nop

    // 0x80081814: bne         $t8, $t9, L_80081824
    if (ctx->r24 != ctx->r25) {
        // 0x80081818: nop
    
            goto L_80081824;
    }
    // 0x80081818: nop

    // 0x8008181C: b           L_80081828
    // 0x80081820: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081828;
    // 0x80081820: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081824:
    // 0x80081824: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081828:
    // 0x80081828: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8008182C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80081830: and         $t2, $t1, $s0
    ctx->r10 = ctx->r9 & ctx->r16;
    // 0x80081834: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x80081838: sw          $t4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r12;
L_8008183C:
    // 0x8008183C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x80081840: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80081844: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80081848: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8008184C: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x80081850: nop

    // 0x80081854: bne         $t5, $zero, L_80081864
    if (ctx->r13 != 0) {
        // 0x80081858: nop
    
            goto L_80081864;
    }
    // 0x80081858: nop

    // 0x8008185C: b           L_80081868
    // 0x80081860: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081868;
    // 0x80081860: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081864:
    // 0x80081864: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081868:
    // 0x80081868: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8008186C: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80081870: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80081874: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x80081878: and         $t9, $t8, $s0
    ctx->r25 = ctx->r24 & ctx->r16;
    // 0x8008187C: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x80081880: bne         $at, $zero, L_8008183C
    if (ctx->r1 != 0) {
        // 0x80081884: sw          $t9, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r25;
            goto L_8008183C;
    }
    // 0x80081884: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x80081888: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8008188C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80081890: lw          $t3, 0x24($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X24);
    // 0x80081894: nop

    // 0x80081898: bne         $t3, $t0, L_800818A8
    if (ctx->r11 != ctx->r8) {
        // 0x8008189C: nop
    
            goto L_800818A8;
    }
    // 0x8008189C: nop

    // 0x800818A0: b           L_800818AC
    // 0x800818A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800818AC;
    // 0x800818A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800818A8:
    // 0x800818A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800818AC:
    // 0x800818AC: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800818B0: nop

    // 0x800818B4: and         $t7, $t6, $s0
    ctx->r15 = ctx->r14 & ctx->r16;
    // 0x800818B8: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
L_800818BC:
    // 0x800818BC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x800818C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800818C4: bne         $t5, $at, L_80081A54
    if (ctx->r13 != ctx->r1) {
        // 0x800818C8: nop
    
            goto L_80081A54;
    }
    // 0x800818C8: nop

    // 0x800818CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800818D0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800818D4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800818D8: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800818DC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800818E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800818E4: jal         0x80080F74
    // 0x800818E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    __lzo_align_gap(rdram, ctx);
        goto after_4;
    // 0x800818E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x800818EC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800818F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800818F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800818F8: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
    // 0x800818FC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80081900: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80081904: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x80081908: and         $t7, $t3, $t6
    ctx->r15 = ctx->r11 & ctx->r14;
    // 0x8008190C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80081910: bne         $t7, $zero, L_80081920
    if (ctx->r15 != 0) {
        // 0x80081914: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80081920;
    }
    // 0x80081914: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80081918: b           L_80081924
    // 0x8008191C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081924;
    // 0x8008191C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081920:
    // 0x80081920: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081924:
    // 0x80081924: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80081928: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008192C: and         $t8, $t5, $s0
    ctx->r24 = ctx->r13 & ctx->r16;
    // 0x80081930: beq         $t9, $zero, L_80081940
    if (ctx->r25 == 0) {
        // 0x80081934: sw          $t8, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r24;
            goto L_80081940;
    }
    // 0x80081934: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x80081938: b           L_80081944
    // 0x8008193C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081944;
    // 0x8008193C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081940:
    // 0x80081940: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081944:
    // 0x80081944: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80081948: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008194C: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
    // 0x80081950: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80081954: and         $t2, $t1, $s0
    ctx->r10 = ctx->r9 & ctx->r16;
    // 0x80081958: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x8008195C: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x80081960: bne         $at, $zero, L_80081970
    if (ctx->r1 != 0) {
        // 0x80081964: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_80081970;
    }
    // 0x80081964: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80081968: b           L_80081974
    // 0x8008196C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081974;
    // 0x8008196C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081970:
    // 0x80081970: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081974:
    // 0x80081974: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80081978: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8008197C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80081980: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80081984: and         $t7, $t6, $s0
    ctx->r15 = ctx->r14 & ctx->r16;
    // 0x80081988: sltu        $at, $t5, $t9
    ctx->r1 = ctx->r13 < ctx->r25 ? 1 : 0;
    // 0x8008198C: beq         $at, $zero, L_8008199C
    if (ctx->r1 == 0) {
        // 0x80081990: sw          $t7, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r15;
            goto L_8008199C;
    }
    // 0x80081990: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
    // 0x80081994: b           L_800819A0
    // 0x80081998: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800819A0;
    // 0x80081998: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008199C:
    // 0x8008199C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800819A0:
    // 0x800819A0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800819A4: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800819A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800819AC: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x800819B0: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800819B4: addu        $t6, $t3, $t0
    ctx->r14 = ADD32(ctx->r11, ctx->r8);
    // 0x800819B8: and         $t2, $t1, $s0
    ctx->r10 = ctx->r9 & ctx->r16;
    // 0x800819BC: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x800819C0: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x800819C4: beq         $at, $zero, L_800819D4
    if (ctx->r1 == 0) {
        // 0x800819C8: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800819D4;
    }
    // 0x800819C8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800819CC: b           L_800819D8
    // 0x800819D0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800819D8;
    // 0x800819D0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800819D4:
    // 0x800819D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800819D8:
    // 0x800819D8: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800819DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800819E0: and         $t5, $t8, $s0
    ctx->r13 = ctx->r24 & ctx->r16;
    // 0x800819E4: bne         $t5, $at, L_80081A54
    if (ctx->r13 != ctx->r1) {
        // 0x800819E8: sw          $t5, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r13;
            goto L_80081A54;
    }
    // 0x800819E8: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
    // 0x800819EC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800819F0: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x800819F4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800819F8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800819FC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80081A00: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x80081A04: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x80081A08: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80081A0C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80081A10: beq         $t4, $zero, L_80081A20
    if (ctx->r12 == 0) {
        // 0x80081A14: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80081A20;
    }
    // 0x80081A14: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80081A18: b           L_80081A24
    // 0x80081A1C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081A24;
    // 0x80081A1C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081A20:
    // 0x80081A20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081A24:
    // 0x80081A24: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80081A28: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80081A2C: and         $t5, $t8, $s0
    ctx->r13 = ctx->r24 & ctx->r16;
    // 0x80081A30: beq         $t2, $zero, L_80081A40
    if (ctx->r10 == 0) {
        // 0x80081A34: sw          $t5, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r13;
            goto L_80081A40;
    }
    // 0x80081A34: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
    // 0x80081A38: b           L_80081A44
    // 0x80081A3C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80081A44;
    // 0x80081A3C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80081A40:
    // 0x80081A40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80081A44:
    // 0x80081A44: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80081A48: nop

    // 0x80081A4C: and         $t3, $t9, $s0
    ctx->r11 = ctx->r25 & ctx->r16;
    // 0x80081A50: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
L_80081A54:
    // 0x80081A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081A58: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x80081A5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081A60: jr          $ra
    // 0x80081A64: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80081A64: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
