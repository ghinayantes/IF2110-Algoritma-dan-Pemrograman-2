/* File: indexOfRec.c */
/* Mencari indeks pertama sebuah nilai pada list statik secara rekursif */

#include "listarray.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah gedung memiliki loker bernomor urut yang menyimpan kode barang
 * dalam sebuah list. Petugas mencari loker pertama (mulai dari loker
 * ke-startIdx) yang menyimpan barang berkode x.
 *
 * TUGAS
 * Implementasikan fungsi indexOfRec yang mengembalikan indeks pertama
 * (paling kecil, dimulai dari startIdx) elemen l yang bernilai x.
 * Jika tidak ada, kembalikan IDX_UNDEF.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : l terdefinisi, mungkin kosong. startIdx >= 0
 * F.S.  : mengembalikan indeks pertama >= startIdx yang berisi x, atau IDX_UNDEF
 *
 * Contoh:
 * indexOfRec([5,3,8,3], 0, 3) = 1
 * indexOfRec([5,3,8,3], 2, 3) = 3
 * indexOfRec([5,3,8,3], 0, 9) = IDX_UNDEF
 * indexOfRec([], 0, 1)        = IDX_UNDEF
 *
 * Hint: ada DUA basis: (1) rentang habis (startIdx >= nEff) berarti tidak
 *       ketemu, (2) elemen saat ini bernilai x berarti ketemu
 */
int indexOfRec(List l, int startIdx, ElType x) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return IDX_UNDEF;
}
