/* Nama File: levelorder.c */
/* Kompilasi: gcc 08_levelOrder.c -o levelorder */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah perusahaan ingin mencetak bagan organisasinya per tingkat:
 * pimpinan puncak di tingkat 1, bawahan langsung mereka di tingkat 2,
 * dan seterusnya, dari kiri ke kanan. Karena bagan disimpan sebagai pohon
 * biner, pencetakan per tingkat harus dilakukan secara rekursif.
 *
 * TUGAS
 * Implementasikan dua fungsi rekursif (akar berada di level 1):
 *   printLevel(p, k) : mencetak semua elemen pohon p yang berada di level k,
 *                      dari kiri ke kanan, masing-masing dengan format "%d "
 *                      (diikuti satu spasi), tanpa newline
 *   nbAtLevel(p, k)  : mengembalikan banyaknya node pohon p di level k
 * Fungsi tinggi(p) sudah disediakan.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi (tanpa antrean). Perulangan pada main boleh.
 *
 * I.S.  : p terdefinisi, mungkin kosong. k >= 1
 * F.S.  : printLevel mencetak elemen level k; nbAtLevel mengembalikan jumlahnya.
 *         Jika level k tidak ada, tidak mencetak apa pun / mengembalikan 0
 *
 * Format Masukan:
 * - Satu baris berisi pohon dalam urutan PREFIX dengan 0 sebagai subpohon
 *   kosong. Banyak node paling banyak 100.
 *
 * Format Keluaran:
 * - Satu baris per level dari level 1 sampai tinggi pohon. Setiap baris
 *   berisi elemen level tersebut dari kiri ke kanan (dari printLevel),
 *   diikuti banyak node level itu dalam kurung. Tidak ada keluaran jika pohon kosong.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                              Keluaran
 * 1.  1 2 4 0 0 5 0 0 3 0 0                1 (1)
 *                                          2 3 (2)
 *                                          4 5 (2)
 * 2.  1 2 0 4 0 0 3 5 0 0 0                1 (1)
 *     (2 punya anak kanan 4,               2 3 (2)
 *      3 punya anak kiri 5)                4 5 (2)
 * 3.  1 2 3 0 0 0 0                        1 (1)
 *                                          2 (1)
 *                                          3 (1)
 * 4.  0                                    (tidak ada keluaran)
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Pada contoh 2, 4 (anak 2) dan 5 (anak 3) berada pada level yang sama
 *   dan dicetak dalam urutan kiri ke kanan: 4 lalu 5.
 *
 * Hint: node di level k pada pohon p adalah node di level k-1 pada subpohon
 *       kiri dan kanan. Basis: pohon kosong, atau k = 1 (akar itu sendiri)
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

void printLevel(BinTree p, int k) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return;
    }
    if (k == 1) {
        printf("%d ", ROOT(p));
    } else {
        printLevel(LEFT(p), k - 1);
        printLevel(RIGHT(p), k - 1);
    }
}

int nbAtLevel(BinTree p, int k) {
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    return nbAtLevel(LEFT(p), k - 1) + nbAtLevel(RIGHT(p), k - 1);
}

int main(void) {
    BinTree t = buildTreePrefix();
    int h = tinggi(t);
    int lv;

    for (lv = 1; lv <= h; lv++) {
        printLevel(t, lv);
        printf("(%d)\n", nbAtLevel(t, lv));
    }
    return 0;
}
