/* File: splitEvenOdd.c */
/* Memisahkan list menjadi list genap dan list ganjil */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Kantor pos menerima tumpukan paket dengan kode angka yang tercatat
 * dalam sebuah list. Paket berkode genap dikirim via jalur ekspres,
 * paket berkode ganjil via jalur reguler. Urutan paket pada masing-masing
 * jalur harus sama dengan urutan kedatangannya.
 *
 * TUGAS
 * Implementasikan prosedur splitEvenOdd yang memindahkan seluruh node l ke
 * evenList (nilai genap) dan oddList (nilai ganjil) tanpa menyalin nilai
 * dan tanpa alokasi/dealokasi node (cukup pindahkan/relink node).
 *
 * I.S.  : l terdefinisi, mungkin kosong. evenList dan oddList sembarang
 * F.S.  : evenList berisi semua elemen genap l (urutan sama), oddList berisi
 *         semua elemen ganjil l (urutan sama), l menjadi kosong
 *
 * Contoh:
 * Jika l = [1,2,3,4,5,6,7], setelah splitEvenOdd(&l,&e,&o):
 *     e = [2,4,6], o = [1,3,5,7], l = []
 * Jika l = [2,4],  maka e = [2,4], o = []
 * Jika l = [],     maka e = [],    o = []
 *
 * Hint: pertahankan pointer ekor untuk kedua list hasil; jangan lupa
 *       NEXT node terakhir masing-masing harus NULL
 */
void splitEvenOdd(List *l, List *evenList, List *oddList) {
    /* KAMUS LOKAL
     *
     * curr     : Address {pointer ke node yang sedang dipindahkan}
     * next     : Address {pointer ke node setelah curr, sebelum dipindahkan}
     * evenLast : Address {pointer ke node terakhir evenList}
     * oddLast  : Address {pointer ke node terakhir oddList}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
