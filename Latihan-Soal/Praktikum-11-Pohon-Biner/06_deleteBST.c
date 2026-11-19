/* Nama File: deletebst.c */
/* Kompilasi: gcc 06_deleteBST.c -o deletebst */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Perpustakaan yang tadi mencatat nomor buku pada sebuah pohon pencarian
 * biner (BST) kini harus menghapus nomor buku yang rusak atau hilang.
 * Setelah setiap penghapusan, pohon harus tetap berupa BST yang sah dan
 * memori node yang dihapus harus dikembalikan.
 *
 * TUGAS
 * Implementasikan prosedur rekursif deleteBST(&p, x) yang menghapus node
 * bernilai x dari BST p (jika tidak ada, tidak ada perubahan). Tiga kasus:
 *   1. Node yang dihapus adalah DAUN: lepaskan node tersebut.
 *   2. Node yang dihapus memiliki SATU anak: gantikan node itu dengan anaknya.
 *   3. Node yang dihapus memiliki DUA anak: ganti isi node dengan nilai
 *      TERKECIL pada subpohon KANAN (successor inorder), lalu hapus nilai
 *      tersebut dari subpohon kanan.
 * Node yang dilepas harus di-dealokasi (free). Prosedur insertBST,
 * printInorder, dan printPreorder sudah disediakan.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi. Boleh membuat fungsi bantu (misalnya minValue).
 *
 * I.S.  : p adalah BST (mungkin kosong), nilai di dalamnya unik
 * F.S.  : x tidak ada lagi pada p, p tetap BST yang sah
 *
 * Format Masukan:
 * - Baris 1: n (0 <= n <= 100). Baris 2: n bilangan bulat positif unik yang
 *   dimasukkan berurutan ke BST (tidak ada jika n = 0).
 * - Baris 3: k (0 <= k <= 100). Baris 4: k bilangan bulat positif yang
 *   dihapus berurutan (tidak ada jika k = 0).
 *
 * Format Keluaran:
 * - k baris: isi BST dalam urutan inorder SETELAH setiap penghapusan.
 * - Satu baris terakhir: isi BST akhir dalam urutan preorder
 *   (untuk memeriksa bentuk pohon).
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                 Keluaran
 * 1.  7                       1 4 5 7 8 9     (hapus 3: dua anak, diganti 4)
 *     5 3 8 1 4 7 9           1 4 7 8 9       (hapus 5: akar, diganti 7)
 *     4                       4 7 8 9         (hapus 1: daun)
 *     3 5 1 10                4 7 8 9         (10 tidak ada)
 *                             7 4 8 9         (preorder akhir)
 * 2.  3                       1 3
 *     2 1 3                   3 1
 *     1
 *     2
 * 3.  3                       2 5
 *     5 3 2                   5 2
 *     1
 *     3
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan successor (nilai terkecil pada subpohon kanan), BUKAN
 *   predecessor, agar bentuk pohon akhir (preorder) sama dengan contoh.
 *
 * Hint: seperti pada deleteX list rekursif, parameter berupa alamat penunjuk
 *       (BinTree *p) dan turun dengan &LEFT(*p) atau &RIGHT(*p). Pada kasus satu
 *       anak atau daun, cukup arahkan *p ke anak yang tersisa (atau NIL)
 *       lalu free node lama
 */

/* SUDAH DISEDIAKAN */
void insertBST(BinTree *p, infotype x) {
    if (isTreeEmpty(*p)) {
        *p = newTreeNode(x);
    } else if (x < ROOT(*p)) {
        insertBST(&LEFT(*p), x);
    } else if (x > ROOT(*p)) {
        insertBST(&RIGHT(*p), x);
    }
}

void printInorder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d ", ROOT(p));
        printInorder(RIGHT(p));
    }
}

void printPreorder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printf("%d ", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
}

/* minValue: nilai terkecil pada BST p yang tidak kosong */
infotype minValue(BinTree p) {
    /* ALGORITMA */
    if (isTreeEmpty(LEFT(p))) {
        return ROOT(p);
    }
    return minValue(LEFT(p));
}

void deleteBST(BinTree *p, infotype x) {
    /* KAMUS LOKAL
     *
     * del : Address {node yang akan di-dealokasi}
     */
    Address del;

    /* ALGORITMA */
    if (isTreeEmpty(*p)) {
        return;
    }
    if (x < ROOT(*p)) {
        deleteBST(&LEFT(*p), x);
    } else if (x > ROOT(*p)) {
        deleteBST(&RIGHT(*p), x);
    } else if (!isTreeEmpty(LEFT(*p)) && !isTreeEmpty(RIGHT(*p))) {
        /* dua anak: ganti dengan successor inorder */
        ROOT(*p) = minValue(RIGHT(*p));
        deleteBST(&RIGHT(*p), ROOT(*p));
    } else {
        /* daun atau satu anak */
        del = *p;
        if (isTreeEmpty(LEFT(*p))) {
            *p = RIGHT(*p);
        } else {
            *p = LEFT(*p);
        }
        free(del);
    }
}

int main(void) {
    int n, k, i, v;
    BinTree t = NIL;

    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        insertBST(&t, v);
    }

    if (scanf("%d", &k) != 1) {
        k = 0;
    }
    for (i = 0; i < k; i++) {
        scanf("%d", &v);
        deleteBST(&t, v);
        printInorder(t);
        printf("\n");
    }
    printPreorder(t);
    printf("\n");
    return 0;
}
