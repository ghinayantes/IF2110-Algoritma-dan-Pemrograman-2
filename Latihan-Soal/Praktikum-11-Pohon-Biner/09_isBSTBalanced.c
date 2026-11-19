/* Nama File: isbstbalanced.c */
/* Kompilasi: gcc 09_isBSTBalanced.c -o isbstbalanced */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang asisten dosen memeriksa tugas mahasiswa yang diminta membuat
 * pohon pencarian biner (BST) yang seimbang. Ia ingin program yang
 * memeriksa dua hal pada pohon yang dikumpulkan: apakah pohonnya benar-benar
 * sebuah BST, dan apakah pohonnya seimbang.
 *
 * TUGAS
 * Implementasikan dua fungsi rekursif:
 *   isBST(p, lo, hi) : bernilai 1 jika pohon p adalah BST dengan SEMUA nilai
 *                      node v memenuhi lo < v < hi. Sebuah pohon adalah BST jika
 *                      setiap node bernilai lebih besar dari semua nilai di
 *                      subpohon kirinya dan lebih kecil dari semua nilai di
 *                      subpohon kanannya (nilai yang sama TIDAK diperbolehkan).
 *                      Pohon kosong adalah BST.
 *   isBalanced(p)    : bernilai 1 jika untuk SETIAP node, selisih mutlak
 *                      tinggi subpohon kiri dan kanannya paling banyak 1.
 *                      Pohon kosong seimbang.
 * Fungsi tinggi(p) sudah disediakan. main memanggil isBST(t, 0, 1001).
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi. Tidak boleh dengan cara mencetak inorder lalu
 * memeriksa keterurutannya pada array.
 *
 * I.S.  : p terdefinisi, mungkin kosong; nilai node bilangan bulat 1..1000
 * F.S.  : sesuai definisi di atas
 *
 * Format Masukan:
 * - Satu baris berisi pohon dalam urutan PREFIX dengan 0 sebagai subpohon
 *   kosong. Banyak node paling banyak 100. Pohon belum tentu BST.
 *
 * Format Keluaran:
 * - Baris 1: "BST" atau "BUKAN BST".
 * - Baris 2: "SEIMBANG" atau "TIDAK SEIMBANG".
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                          Keluaran
 * 1.  5 3 1 0 0 4 0 0 8 0 0            BST
 *                                      SEIMBANG
 * 2.  5 3 0 0 8 4 0 0 0                BUKAN BST       (4 < 5 padahal di kanan)
 *                                      SEIMBANG
 * 3.  4 3 2 1 0 0 0 0 0                BST
 *     (condong kiri)                   TIDAK SEIMBANG
 * 4.  1 2 3 4 0 0 0 0 0                BUKAN BST
 *                                      TIDAK SEIMBANG
 * 5.  3 3 0 0 0                        BUKAN BST       (nilai sama)
 *                                      SEIMBANG
 * 6.  0                                BST
 *                                      SEIMBANG
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Memeriksa hanya "anak kiri < induk < anak kanan" TIDAK cukup. Pada
 *   contoh 2, 4 memang lebih kecil dari induknya (8), tetapi 4 juga lebih
 *   kecil dari akar 5 padahal berada di subpohon KANAN akar.
 *
 * Hint: isBST membawa batas (lo, hi) yang menyempit saat turun: ke kiri,
 *       batas atas menjadi ROOT(p); ke kanan, batas bawah menjadi ROOT(p)
 */

/* SUDAH DISEDIAKAN */
int tinggi(BinTree p) {
    int a, b;
    if (isTreeEmpty(p)) {
        return 0;
    }
    a = tinggi(LEFT(p));
    b = tinggi(RIGHT(p));
    return 1 + (a > b ? a : b);
}

int isBST(BinTree p, int lo, int hi) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 1;
    }
    if (ROOT(p) <= lo || ROOT(p) >= hi) {
        return 0;
    }
    return isBST(LEFT(p), lo, ROOT(p)) && isBST(RIGHT(p), ROOT(p), hi);
}

int isBalanced(BinTree p) {
    /* KAMUS LOKAL
     *
     * d : int {selisih tinggi subpohon kiri dan kanan}
     */
    int d;

    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 1;
    }
    d = tinggi(LEFT(p)) - tinggi(RIGHT(p));
    if (d < -1 || d > 1) {
        return 0;
    }
    return isBalanced(LEFT(p)) && isBalanced(RIGHT(p));
}

int main(void) {
    BinTree t = buildTreePrefix();

    if (isBST(t, 0, 1001)) {
        printf("BST\n");
    } else {
        printf("BUKAN BST\n");
    }
    if (isBalanced(t)) {
        printf("SEIMBANG\n");
    } else {
        printf("TIDAK SEIMBANG\n");
    }
    return 0;
}
