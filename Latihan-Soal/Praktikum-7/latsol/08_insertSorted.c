/* File: insertSorted.c */
/* Menyisipkan elemen ke list terurut agar tetap terurut */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Di IGD sebuah rumah sakit, pasien dilayani berdasarkan tingkat urgensi;
 * semakin kecil angkanya, semakin darurat. Antrean disimpan dalam list
 * yang terurut menaik. Ketika pasien baru datang dengan tingkat urgensi
 * val, ia harus ditempatkan pada posisi yang tepat sehingga antrean tetap terurut.
 *
 * TUGAS
 * Implementasikan prosedur insertSorted yang menyisipkan val ke list l
 * sehingga l tetap terurut menaik. Boleh memakai primitif insertFirst,
 * insertAt, atau insertLast.
 *
 * I.S.  : l terdefinisi, terurut menaik, mungkin kosong
 * F.S.  : l berisi semua elemen semula ditambah val, tetap terurut menaik.
 *         Jika alokasi gagal, I.S. = F.S.
 *
 * Contoh:
 * Jika l = [1,3,5], val = 4, maka setelah insertSorted(&l, 4), l menjadi [1,3,4,5]
 * Jika l = [1,3,5], val = 0, maka l menjadi [0,1,3,5]
 * Jika l = [1,3,5], val = 9, maka l menjadi [1,3,5,9]
 * Jika l = [],      val = 7, maka l menjadi [7]
 *
 * Hint: cari posisi pertama yang nilainya lebih besar dari val
 */
void insertSorted(List *l, ElType val) {
    /* KAMUS LOKAL
     *
     * p   : Address {pointer traversal untuk mencari posisi sisip}
     * idx : int {indeks posisi sisip}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
