/* File: sumList.c */
/* Menjumlahkan elemen list statik dari startIdx secara rekursif */

#include "listarray.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Dina berbelanja dan mencatat harga tiap barang dalam sebuah list. Di
 * kasir, ia ingin menghitung total belanja mulai dari barang pada indeks
 * tertentu sampai barang terakhir, misalnya untuk menghitung jumlah
 * barang yang dibeli setelah kupon diskon dipakai.
 *
 * TUGAS
 * Implementasikan fungsi sumList yang mengembalikan jumlah elemen l pada
 * indeks startIdx sampai nEff-1. Jika startIdx >= l.nEff, jumlahnya 0.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 * List yang dipakai adalah list statik pada listarray.h
 * (l.contents[i] dan l.nEff).
 *
 * I.S.  : l terdefinisi, mungkin kosong. startIdx >= 0
 * F.S.  : mengembalikan jumlah l.contents[startIdx..l.nEff-1]
 *
 * Contoh:
 * sumList([3,1,4], 0) = 8
 * sumList([3,1,4], 1) = 5
 * sumList([3,1,4], 3) = 0
 * sumList([], 0)      = 0
 *
 * Hint: basis-0 adalah startIdx >= nEff (rentang kosong); rekurensnya
 *       memproses elemen saat ini lalu sisanya mulai dari startIdx+1
 */
int sumList(List l, int startIdx) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return 0;
}
