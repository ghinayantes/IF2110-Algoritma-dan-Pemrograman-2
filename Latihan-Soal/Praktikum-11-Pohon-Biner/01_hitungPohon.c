/* Nama File: hitungpohon.c */
/* Kompilasi: gcc 01_hitungPohon.c -o hitungpohon */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah perusahaan memiliki struktur organisasi berbentuk pohon biner:
 * setiap pegawai membawahi paling banyak dua bawahan langsung (kiri dan
 * kanan). Direktur HRD ingin mengetahui tiga hal: berapa jumlah seluruh
 * pegawai, berapa pegawai yang tidak punya bawahan sama sekali, dan berapa
 * tingkat hierarki terdalam.
 *
 * TUGAS
 * Implementasikan tiga fungsi rekursif pada pohon biner p:
 *   nbElmt(p) : banyaknya node pada p
 *   nbLeaf(p) : banyaknya daun (node tanpa anak kiri maupun kanan)
 *   tinggi(p) : tinggi pohon, yaitu banyaknya node pada jalur terpanjang
 *               dari akar ke daun. Pohon kosong bertinggi 0, pohon satu
 *               node bertinggi 1.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis (main boleh). Gunakan rekursi.
 *
 * I.S.  : p terdefinisi, mungkin kosong
 * F.S.  : masing-masing fungsi mengembalikan nilai sesuai definisi di atas
 *
 * Format Masukan:
 * - Satu baris berisi pohon dalam urutan PREFIX (akar, subpohon kiri,
 *   subpohon kanan). Bilangan 0 menandakan subpohon kosong; nilai node
 *   selalu bilangan bulat positif. Banyak node paling banyak 100.
 *   (Sudah dibaca oleh buildTreePrefix pada main.)
 *
 * Format Keluaran:
 * - Tiga baris: banyaknya node, banyaknya daun, tinggi pohon.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                      Keluaran
 * 1.  1 2 4 0 0 5 0 0 3 0 0        5
 *                                  3
 *                                  3
 * 2.  7 0 0                        1
 *                                  1
 *                                  1
 * 3.  0                            0
 *                                  0
 *                                  0
 * 4.  1 2 3 0 0 0 0                3
 *     (pohon condong kiri)         1
 *                                  3
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Pohon pada contoh 1: akar 1, anak kiri 2 (anak 4 dan 5), anak kanan 3.
 *
 * Hint: basis adalah pohon kosong. Untuk nbLeaf, node dengan satu anak
 *       BUKAN daun. Untuk tinggi, ambil yang terbesar antara tinggi kiri
 *       dan tinggi kanan, lalu tambah 1 untuk akar
 */
int nbElmt(BinTree p) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    return 1 + nbElmt(LEFT(p)) + nbElmt(RIGHT(p));
}

int nbLeaf(BinTree p) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    if (isLeaf(p)) {
        return 1;
    }
    return nbLeaf(LEFT(p)) + nbLeaf(RIGHT(p));
}

int tinggi(BinTree p) {
    /* KAMUS LOKAL
     *
     * tl, tr : int {tinggi subpohon kiri dan kanan}
     */
    int tl, tr;

    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    tl = tinggi(LEFT(p));
    tr = tinggi(RIGHT(p));
    return 1 + (tl > tr ? tl : tr);
}

int main(void) {
    BinTree t = buildTreePrefix();
    printf("%d\n", nbElmt(t));
    printf("%d\n", nbLeaf(t));
    printf("%d\n", tinggi(t));
    return 0;
}
