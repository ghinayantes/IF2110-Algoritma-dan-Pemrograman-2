/* File: keepFirstK.c */
/* Memotong list agar hanya menyisakan k elemen pertama */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah browser hanya menyimpan k halaman pertama dari riwayat kunjungan
 * agar memori tidak penuh. Riwayat disimpan dalam sebuah list; halaman
 * selebihnya harus dihapus dan memorinya dikembalikan.
 *
 * TUGAS
 * Implementasikan prosedur keepFirstK yang menyisakan hanya k elemen pertama
 * list l. Seluruh node selebihnya harus di-dealokasi (free).
 *
 * I.S.  : l terdefinisi, mungkin kosong. k >= 0
 * F.S.  : l berisi paling banyak k elemen pertama dari l semula
 *
 * Contoh:
 * Jika l = [1,2,3,4,5], k = 2, maka setelah keepFirstK(&l, 2), l menjadi [1,2]
 * Jika l = [1,2,3],     k = 3, maka l tetap [1,2,3]
 * Jika l = [1,2,3],     k = 9, maka l tetap [1,2,3]
 * Jika l = [1,2,3],     k = 0, maka l menjadi []
 *
 * Hint: kasus k = 0 berbeda karena FIRST(l) ikut berubah
 */
void keepFirstK(List *l, int k) {
    /* KAMUS LOKAL
     *
     * curr : Address {pointer ke node terakhir yang dipertahankan}
     * temp : Address {pointer ke node yang akan di-dealokasi}
     * ctr  : int {penghitung langkah}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
