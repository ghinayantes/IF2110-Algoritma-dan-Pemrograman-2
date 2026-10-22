/* File: mergeSorted.c */
/* Menggabungkan dua list terurut menjadi satu list terurut */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah bank memiliki dua loket yang masing-masing menyimpan nomor
 * antrean nasabah dalam list terurut menaik. Karena salah satu loket
 * ditutup, kedua antrean harus digabung menjadi satu antrean terurut
 * menaik agar nasabah tetap dilayani sesuai nomor antrean.
 *
 * TUGAS
 * Implementasikan fungsi mergeSorted yang menggabungkan l1 dan l2 menjadi
 * satu list terurut menaik dengan cara memindahkan node (relink), tanpa
 * alokasi/dealokasi node baru. Jika ada nilai yang sama, node dari l1
 * didahulukan.
 *
 * I.S.  : l1 dan l2 terdefinisi, masing-masing terurut menaik, mungkin kosong
 * F.S.  : mengembalikan list terurut menaik berisi semua node l1 dan l2.
 *         l1 dan l2 menjadi kosong
 *
 * Contoh:
 * mergeSorted([1,4,7], [2,4,9]) = [1,2,4,4,7,9]
 * mergeSorted([], [3,5])        = [3,5]
 * mergeSorted([1,2], [])        = [1,2]
 * mergeSorted([], [])           = []
 *
 * Hint: pertahankan pointer ekor list hasil; ketika salah satu list habis,
 *       sambungkan sisa list yang lain sekaligus
 */
List mergeSorted(List *l1, List *l2) {
    /* KAMUS LOKAL
     *
     * result : List {pointer ke node pertama list hasil}
     * tail   : Address {pointer ke node terakhir list hasil}
     * p1     : Address {pointer ke node terdepan l1 yang belum dipindahkan}
     * p2     : Address {pointer ke node terdepan l2 yang belum dipindahkan}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NULL;
}
