/* Nama File: lca.c */
/* Kompilasi: gcc 10_lca.c -o lca */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Dua orang karyawan pada bagan organisasi (pohon biner) ingin mencari atasan
 * terdekat yang sama-sama membawahi mereka berdua, supaya masalah mereka
 * dapat dilaporkan ke orang yang tepat. Mereka juga ingin tahu pada
 * tingkat berapa masing-masing berada.
 *
 * TUGAS
 * Semua nilai node pada pohon unik. Implementasikan dua fungsi rekursif:
 *   levelOf(p, x)  : level node bernilai x pada pohon p (akar berada di level 1),
 *                    atau 0 jika x tidak ada pada p
 *   lca(p, a, b)   : nilai node paling dalam (paling jauh dari akar) yang
 *                    merupakan leluhur dari a dan b. Sebuah node dianggap
 *                    leluhur dari dirinya sendiri, jadi jika a adalah leluhur
 *                    b maka hasilnya a. Mengembalikan 0 jika tidak ditemukan
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi.
 *
 * I.S.  : p terdefinisi, mungkin kosong; semua nilai node unik dan positif;
 *         a dan b ada pada p
 * F.S.  : sesuai definisi di atas
 *
 * Format Masukan:
 * - Baris 1: pohon dalam urutan PREFIX dengan 0 sebagai subpohon kosong
 *   (banyak node paling banyak 100).
 * - Baris 2: dua bilangan bulat a dan b (dua nilai node yang ada pada pohon).
 *
 * Format Keluaran:
 * - Baris 1: level a. Baris 2: level b. Baris 3: nilai lca(a, b).
 *
 * Contoh Masukan dan Keluaran:
 * Pohon: 1 2 4 0 0 5 0 0 3 0 0  (akar 1; anak 2 dan 3; anak 2 adalah 4 dan 5)
 * No  a b       Keluaran
 * 1.  4 5       3
 *               3
 *               2
 * 2.  4 3       3
 *               2
 *               1
 * 3.  2 5       2
 *               3
 *               2        (2 adalah leluhur 5)
 * 4.  3 3       2
 *               2
 *               3
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 *
 * Hint: lca: jika akar sama dengan a atau b, hasilnya akar itu. Jika tidak,
 *       cari lca di subpohon kiri dan kanan. Jika KEDUANYA menemukan sesuatu,
 *       akar sekarang adalah leluhur bersama; jika hanya satu yang menemukan,
 *       gunakan hasil yang itu
 */
int levelOf(BinTree p, infotype x) {
    /* KAMUS LOKAL
     *
     * l : int {level x pada subpohon kiri (0 jika tidak ada)}
     */
    int l;

    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    if (ROOT(p) == x) {
        return 1;
    }
    l = levelOf(LEFT(p), x);
    if (l == 0) {
        l = levelOf(RIGHT(p), x);
    }
    return (l == 0) ? 0 : l + 1;
}

int lca(BinTree p, infotype a, infotype b) {
    /* KAMUS LOKAL
     *
     * l, r : int {hasil pencarian pada subpohon kiri dan kanan}
     */
    int l, r;

    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    if (ROOT(p) == a || ROOT(p) == b) {
        return ROOT(p);
    }
    l = lca(LEFT(p), a, b);
    r = lca(RIGHT(p), a, b);
    if (l != 0 && r != 0) {
        return ROOT(p);
    }
    return (l != 0) ? l : r;
}

int main(void) {
    int a, b;
    BinTree t = buildTreePrefix();

    if (scanf("%d %d", &a, &b) != 2) {
        return 0;
    }
    printf("%d\n", levelOf(t, a));
    printf("%d\n", levelOf(t, b));
    printf("%d\n", lca(t, a, b));
    return 0;
}
