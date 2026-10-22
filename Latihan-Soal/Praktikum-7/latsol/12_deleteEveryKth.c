/* File: deleteEveryKth.c */
/* Menghapus setiap elemen ke-k pada list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Dalam sebuah lomba lari, peserta berbaris sesuai nomor dada yang
 * tercatat dalam sebuah list. Panitia mendiskualifikasi setiap peserta
 * pada urutan ke-k, ke-2k, ke-3k, dan seterusnya (urutan dihitung mulai
 * dari 1 pada barisan semula).
 *
 * TUGAS
 * Implementasikan prosedur deleteEveryKth yang menghapus node pada posisi
 * k, 2k, 3k, ... (1-based, menurut list semula). Node yang dihapus
 * harus di-dealokasi.
 *
 * I.S.  : l terdefinisi, mungkin kosong. k >= 1
 * F.S.  : node pada posisi kelipatan k dihapus
 *
 * Contoh:
 * Jika l = [1,2,3,4,5,6,7], k = 3, maka setelah deleteEveryKth(&l, 3), l menjadi [1,2,4,5,7]
 * Jika l = [10,20,30,40],   k = 2, maka l menjadi [10,30]
 * Jika l = [1,2,3],         k = 1, maka l menjadi []
 * Jika l = [1,2,3],         k = 10, maka l tetap [1,2,3]
 *
 * Hint: gunakan penghitung posisi; ingat posisi dihitung pada list semula,
 *       bukan pada list yang sedang menyusut
 */
void deleteEveryKth(List *l, int k) {
    /* KAMUS LOKAL
     *
     * curr : Address {pointer ke node yang sedang diperiksa}
     * prev : Address {pointer ke node tepat sebelum curr, NULL jika curr node pertama}
     * del  : Address {pointer ke node yang akan di-dealokasi}
     * pos  : int {posisi (1-based) node curr pada list semula}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
