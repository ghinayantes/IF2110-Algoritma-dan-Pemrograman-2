/* Nama File: exprtree.c */
/* Kompilasi: gcc 07_exprTree.c -o exprtree */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang guru matematika mengubah ekspresi aritmetika menjadi pohon
 * ekspresi: setiap operator (+, -, *, /) menjadi akar dengan dua operand
 * sebagai anak kiri dan anak kanan. Operand yang berupa bilangan menjadi
 * daun. Dengan pohon ini, nilai ekspresi dan bentuk berkurungnya dapat
 * dihitung secara rekursif.
 *
 * TUGAS
 * Pohon ekspresi sudah dibangun dari masukan prefix oleh buildExprTree
 * (SUDAH DISEDIAKAN). Isi node: operand disimpan apa adanya (bilangan
 * bulat >= 0), sedangkan operator disimpan sebagai NEGATIF dari kode
 * karakternya (misalnya '+' disimpan sebagai -43). Gunakan isOperatorNode(p)
 * dan opChar(p) untuk membedakannya.
 * Implementasikan dua fungsi rekursif:
 *   evalTree(p)   : nilai ekspresi pada pohon p. Pembagian adalah
 *                   pembagian bilangan bulat C (pemotongan ke arah nol).
 *   printInfix(p) : mencetak ekspresi dalam bentuk infix dengan SETIAP operator
 *                   dibungkus tanda kurung: "(kiri op kanan)". Operand dicetak
 *                   sebagai bilangan saja. Tanpa spasi, tanpa newline.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi.
 *
 * I.S.  : p terdefinisi dan tidak kosong; setiap operator memiliki tepat dua
 *         anak, setiap operand adalah daun. Tidak ada pembagian dengan 0
 * F.S.  : evalTree mengembalikan nilai ekspresi; printInfix mencetak ekspresi
 *
 * Format Masukan:
 * - Satu baris berisi ekspresi dalam notasi PREFIX, token dipisah spasi.
 *   Token berupa operator (+ - * /) atau bilangan bulat 0..1000.
 *   Banyak token paling banyak 99 (ganjil).
 *
 * Format Keluaran:
 * - Baris 1: nilai ekspresi. Baris 2: ekspresi infix berkurung.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                 Keluaran
 * 1.  + 3 * 2 4               11
 *                             (3+(2*4))
 * 2.  * + 1 2 - 7 3           12
 *                             ((1+2)*(7-3))
 * 3.  5                       5
 *                             5
 * 4.  / 9 2                   4
 *                             (9/2)
 * 5.  - 2 5                   -3
 *                             (2-5)
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 *
 * Hint: basis adalah daun (operand). Untuk operator, hitung nilai kiri dan
 *       nilai kanan terlebih dahulu, lalu terapkan operatornya. Pada
 *       printInfix, cetak "(" sebelum anak kiri, operator di antara kedua
 *       anak, dan ")" setelah anak kanan
 */

/* SUDAH DISEDIAKAN */
int isOperatorNode(BinTree p) {
    return ROOT(p) < 0;
}

char opChar(BinTree p) {
    return (char)(-ROOT(p));
}

BinTree buildExprTree(void) {
    char tok[16];
    BinTree t;
    if (scanf("%15s", tok) != 1) {
        return NIL;
    }
    if (tok[1] == '\0' && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/')) {
        t = newTreeNode(-(int)tok[0]);
        LEFT(t) = buildExprTree();
        RIGHT(t) = buildExprTree();
        return t;
    }
    return newTreeNode(atoi(tok));
}

int evalTree(BinTree p) {
    /* KAMUS LOKAL
     *
     * a, b : int {nilai subpohon kiri dan kanan}
     */
    int a, b;

    /* ALGORITMA */
    if (!isOperatorNode(p)) {
        return ROOT(p);
    }
    a = evalTree(LEFT(p));
    b = evalTree(RIGHT(p));
    switch (opChar(p)) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default:  return a / b;
    }
}

void printInfix(BinTree p) {
    /* ALGORITMA */
    if (!isOperatorNode(p)) {
        printf("%d", ROOT(p));
    } else {
        printf("(");
        printInfix(LEFT(p));
        printf("%c", opChar(p));
        printInfix(RIGHT(p));
        printf(")");
    }
}

int main(void) {
    BinTree t = buildExprTree();
    printf("%d\n", evalTree(t));
    printInfix(t);
    printf("\n");
    return 0;
}
