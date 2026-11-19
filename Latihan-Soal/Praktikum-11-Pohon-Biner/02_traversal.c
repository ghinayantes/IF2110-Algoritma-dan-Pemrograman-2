/* Nama File: traversal.c */
/* Kompilasi: gcc 02_traversal.c -o traversal */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah arsip digital menyimpan folder dalam bentuk pohon biner. Petugas
 * arsip ingin membaca isinya dengan tiga urutan kunjungan berbeda:
 * mengunjungi folder induk dulu, di tengah-tengah, atau paling akhir.
 *
 * TUGAS
 * Implementasikan tiga prosedur rekursif yang mencetak elemen pohon p
 * (setiap elemen dicetak dengan format "%d " yaitu diikuti satu spasi):
 *   preorder(p)  : akar, lalu subpohon kiri, lalu subpohon kanan
 *   inorder(p)   : subpohon kiri, lalu akar, lalu subpohon kanan
 *   postorder(p) : subpohon kiri, lalu subpohon kanan, lalu akar
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi.
 *
 * I.S.  : p terdefinisi, mungkin kosong
 * F.S.  : elemen p tercetak sesuai urutan kunjungan; tidak mencetak newline
 *         (newline dicetak oleh main)
 *
 * Format Masukan:
 * - Satu baris berisi pohon dalam urutan PREFIX dengan 0 sebagai subpohon
 *   kosong (lihat buildTreePrefix pada bintree.h). Banyak node paling banyak 100.
 *
 * Format Keluaran:
 * - Tiga baris: hasil preorder, inorder, dan postorder, dengan elemen
 *   dipisah spasi (ada satu spasi setelah elemen terakhir). Baris kosong
 *   jika pohon kosong.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                      Keluaran
 * 1.  1 2 4 0 0 5 0 0 3 0 0        1 2 4 5 3
 *                                  4 2 5 1 3
 *                                  4 5 2 3 1
 * 2.  5 0 0                        5
 *                                  5
 *                                  5
 * 3.  0                            (baris kosong)
 *                                  (baris kosong)
 *                                  (baris kosong)
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 *
 * Hint: ketiganya hanya berbeda pada posisi pencetakan akar terhadap dua
 *       pemanggilan rekursif
 */
void preorder(BinTree p) {
    /* ALGORITMA */
    if (!isTreeEmpty(p)) {
        printf("%d ", ROOT(p));
        preorder(LEFT(p));
        preorder(RIGHT(p));
    }
}

void inorder(BinTree p) {
    /* ALGORITMA */
    if (!isTreeEmpty(p)) {
        inorder(LEFT(p));
        printf("%d ", ROOT(p));
        inorder(RIGHT(p));
    }
}

void postorder(BinTree p) {
    /* ALGORITMA */
    if (!isTreeEmpty(p)) {
        postorder(LEFT(p));
        postorder(RIGHT(p));
        printf("%d ", ROOT(p));
    }
}

int main(void) {
    BinTree t = buildTreePrefix();
    preorder(t);
    printf("\n");
    inorder(t);
    printf("\n");
    postorder(t);
    printf("\n");
    return 0;
}
