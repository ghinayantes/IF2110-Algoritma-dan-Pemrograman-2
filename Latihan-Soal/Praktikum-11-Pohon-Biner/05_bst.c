/* Nama File: bst.c */
/* Kompilasi: gcc 05_bst.c -o bst */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah perpustakaan mencatat nomor buku yang masuk ke dalam sebuah pohon
 * pencarian biner (Binary Search Tree): nomor yang lebih kecil dari akar
 * disimpan di subpohon kiri, nomor yang lebih besar di subpohon kanan.
 * Setiap nomor hanya dicatat sekali; nomor yang sudah ada diabaikan.
 * Setelah semua buku masuk, petugas ingin memeriksa beberapa nomor.
 *
 * TUGAS
 * Implementasikan dua fungsi rekursif pada BST:
 *   insertBST(&p, x) : menyisipkan x ke BST p. Jika x sudah ada, tidak ada
 *                      perubahan. Gunakan node baru dari newTreeNode.
 *   searchBST(p, x)  : bernilai 1 jika x ada pada BST p, 0 jika tidak
 * Prosedur printInorder (di bawah) sudah disediakan.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi.
 *
 * I.S.  : p adalah BST (mungkin kosong)
 * F.S.  : insertBST: x berada pada BST dan p tetap BST yang sah;
 *         searchBST: mengembalikan 1 atau 0 sesuai keberadaan x
 *
 * Format Masukan:
 * - Baris 1: n, banyaknya nomor yang dimasukkan (0 <= n <= 100).
 * - Baris 2: n bilangan bulat positif, dimasukkan berurutan ke BST
 *   (tidak ada jika n = 0).
 * - Baris 3: m, banyaknya nomor yang diperiksa (0 <= m <= 100).
 * - Baris 4: m bilangan bulat positif yang dicari (tidak ada jika m = 0).
 *
 * Format Keluaran:
 * - Baris pertama: isi BST dalam urutan inorder (dicetak printInorder).
 * - Lalu m baris: "ADA" jika nomor yang dicari ada pada BST, atau "TIDAK" jika tidak.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  5                   1 3 4 5 8
 *     5 3 8 1 4           ADA
 *     3                   TIDAK
 *     4 7 1               ADA
 * 2.  4                   1 2
 *     2 2 1 2             TIDAK
 *     1
 *     9
 * 3.  0                   (baris kosong)
 *     1                   TIDAK
 *     5
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Hasil inorder sebuah BST selalu terurut menaik.
 *
 * Hint: pada insertBST, parameternya berupa alamat penunjuk (BinTree *p).
 *       Untuk turun ke subpohon, kirim alamat penunjuk anak: &LEFT(*p) atau
 *       &RIGHT(*p). Pola ini sama dengan deleteX pada list rekursif. Di
 *       basis (*p kosong), pasang node baru langsung pada *p
 */

/* printInorder: SUDAH DISEDIAKAN. Mencetak elemen p dalam inorder, tiap elemen diikuti spasi */
void printInorder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d ", ROOT(p));
        printInorder(RIGHT(p));
    }
}

void insertBST(BinTree *p, infotype x) {
    /* ALGORITMA */
    if (isTreeEmpty(*p)) {
        *p = newTreeNode(x);
    } else if (x < ROOT(*p)) {
        insertBST(&LEFT(*p), x);
    } else if (x > ROOT(*p)) {
        insertBST(&RIGHT(*p), x);
    }
    /* x == ROOT(*p): sudah ada, diabaikan */
}

int searchBST(BinTree p, infotype x) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    if (x == ROOT(p)) {
        return 1;
    }
    if (x < ROOT(p)) {
        return searchBST(LEFT(p), x);
    }
    return searchBST(RIGHT(p), x);
}

int main(void) {
    int n, m, i, v;
    BinTree t = NIL;

    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        insertBST(&t, v);
    }

    printInorder(t);
    printf("\n");

    if (scanf("%d", &m) != 1) {
        return 0;
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &v);
        if (searchBST(t, v)) {
            printf("ADA\n");
        } else {
            printf("TIDAK\n");
        }
    }
    return 0;
}
