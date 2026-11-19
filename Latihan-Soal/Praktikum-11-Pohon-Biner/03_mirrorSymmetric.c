/* Nama File: mirrorsymmetric.c */
/* Kompilasi: gcc 03_mirrorSymmetric.c -o mirrorsymmetric */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang desainer batik membuat motif berbentuk pohon biner. Ia ingin
 * tahu apakah sebuah motif simetris (sama persis dengan bayangan cerminnya),
 * dan ia juga ingin membuat motif bayangan cermin itu sebagai pohon baru
 * tanpa merusak motif aslinya.
 *
 * TUGAS
 * Implementasikan tiga fungsi rekursif:
 *   isMirror(a, b)   : true jika pohon a adalah bayangan cermin pohon b,
 *                      yaitu keduanya kosong, atau akar keduanya sama dan
 *                      subpohon kiri a adalah cermin subpohon kanan b
 *                      serta subpohon kanan a adalah cermin subpohon kiri b
 *   isSymmetric(p)   : true jika p adalah bayangan cermin dari dirinya sendiri
 *                      (pohon kosong dianggap simetris)
 *   mirrorTree(p)    : mengembalikan pohon BARU hasil cermin p (setiap
 *                      subpohon kiri dan kanan ditukar). p tidak boleh berubah
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi. Boleh memakai makeTree dan newTreeNode dari bintree.h.
 *
 * I.S.  : p, a, b terdefinisi, mungkin kosong
 * F.S.  : sesuai definisi di atas
 *
 * Format Masukan:
 * - Satu baris berisi pohon dalam urutan PREFIX dengan 0 sebagai subpohon
 *   kosong. Banyak node paling banyak 100.
 *
 * Format Keluaran:
 * - Baris 1: "YA" jika pohon simetris, atau "TIDAK" jika tidak.
 * - Baris 2: isi pohon hasil mirrorTree dalam urutan preorder.
 * - Baris 3: isi pohon ASLI dalam urutan preorder (untuk memeriksa bahwa
 *   pohon asli tidak berubah).
 *   Preorder dicetak dengan printPreorder yang sudah disediakan
 *   (setiap elemen diikuti satu spasi).
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                                  Keluaran
 * 1.  1 2 0 0 3 0 0                            TIDAK
 *                                              1 3 2
 *                                              1 2 3
 * 2.  1 2 3 0 0 4 0 0 2 4 0 0 3 0 0            YA
 *                                              1 2 3 4 2 4 3
 *                                              1 2 3 4 2 4 3
 * 3.  0                                        YA
 *                                              (baris kosong)
 *                                              (baris kosong)
 * 4.  5 3 0 0 0                                TIDAK
 *     (akar 5, hanya anak kiri 3)              5 3
 *                                              5 3
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Pada contoh 4, bayangan cerminnya memiliki 3 sebagai anak KANAN,
 *   sehingga bentuknya berbeda dari pohon aslinya. Itulah sebabnya tidak simetris,
 *   walaupun urutan preorder keduanya sama.
 *
 * Hint: isSymmetric(p) cukup memanggil isMirror pada kedua anak p
 */

/* printPreorder: SUDAH DISEDIAKAN. Mencetak elemen p dalam preorder, tiap elemen diikuti spasi */
void printPreorder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printf("%d ", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
}

int isMirror(BinTree a, BinTree b) {
    /* ALGORITMA */
    if (isTreeEmpty(a) && isTreeEmpty(b)) {
        return 1;
    }
    if (isTreeEmpty(a) || isTreeEmpty(b)) {
        return 0;
    }
    return ROOT(a) == ROOT(b) &&
           isMirror(LEFT(a), RIGHT(b)) &&
           isMirror(RIGHT(a), LEFT(b));
}

int isSymmetric(BinTree p) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 1;
    }
    return isMirror(LEFT(p), RIGHT(p));
}

BinTree mirrorTree(BinTree p) {
    /* KAMUS LOKAL
     *
     * l, r : BinTree {hasil cermin subpohon kiri dan kanan}
     */
    BinTree l, r;

    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return NIL;
    }
    l = mirrorTree(RIGHT(p));
    r = mirrorTree(LEFT(p));
    return makeTree(ROOT(p), l, r);
}

int main(void) {
    BinTree t = buildTreePrefix();
    BinTree m;

    if (isSymmetric(t)) {
        printf("YA\n");
    } else {
        printf("TIDAK\n");
    }
    m = mirrorTree(t);
    printPreorder(m);
    printf("\n");
    printPreorder(t);
    printf("\n");
    return 0;
}
