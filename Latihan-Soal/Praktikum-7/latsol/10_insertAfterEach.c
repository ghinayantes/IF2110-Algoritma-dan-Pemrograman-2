/* File: insertAfterEach.c */
/* Menyisipkan nilai setelah setiap kemunculan nilai tertentu */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Penerbit buku ingin memberi halaman kosong sebagai pembatas. Isi buku
 * dicatat dalam sebuah list kode halaman; halaman berkode x adalah
 * awal sebuah bab. Setelah setiap halaman berkode x, harus disisipkan
 * sebuah halaman kosong berkode y.
 *
 * TUGAS
 * Implementasikan prosedur insertAfterEach yang menyisipkan node baru
 * bernilai y tepat setelah setiap node bernilai x pada list l.
 * Node yang baru disisipkan tidak boleh diproses ulang (meskipun y = x).
 * Jika alokasi gagal, lewati node tersebut.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : setiap node bernilai x pada l semula diikuti node bernilai y
 *
 * Contoh:
 * Jika l = [1,2,1,3], x = 1, y = 9, maka setelah insertAfterEach(&l,1,9), l menjadi [1,9,2,1,9,3]
 * Jika l = [5,5],     x = 5, y = 0, maka l menjadi [5,0,5,0]
 * Jika l = [1,2,3],   x = 7, y = 0, maka l tetap [1,2,3]
 * Jika l = [],        x = 1, y = 0, maka l tetap []
 *
 * Hint: simpan alamat node berikutnya sebelum menyisipkan
 */
void insertAfterEach(List *l, ElType x, ElType y) {
    /* KAMUS LOKAL
     *
     * curr : Address {pointer ke node yang sedang diperiksa}
     * next : Address {pointer ke node sesudah curr sebelum penyisipan}
     * p    : Address {pointer ke node baru bernilai y}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
