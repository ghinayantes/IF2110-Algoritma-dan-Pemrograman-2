/* File: countInRange.c */
/* Menghitung elemen list yang berada dalam suatu rentang */

#include "../listlinier.h"
#include "../listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Bu Sari adalah kasir kantin sekolah. Setiap transaksi hari ini dicatat
 * nominalnya dalam sebuah list. Menjelang tutup, Bu Sari ingin tahu ada
 * berapa transaksi yang nominalnya berada dalam rentang [lo, hi]
 * (termasuk lo dan hi) untuk laporan harian.
 *
 * TUGAS
 * Implementasikan fungsi countInRange yang mengembalikan banyaknya elemen
 * l yang nilainya x memenuhi lo <= x <= hi.
 *
 * I.S.  : l terdefinisi, mungkin kosong. lo <= hi
 * F.S.  : mengembalikan banyaknya elemen l pada rentang [lo, hi]. l tidak berubah
 *
 * Contoh:
 * countInRange([10,25,30,5,50], 10, 30) = 3   (10, 25, 30)
 * countInRange([1,2,3], 5, 9)           = 0
 * countInRange([], 1, 10)               = 0
 *
 * Hint: satu kali traversal dengan sebuah penghitung
 */
int countInRange(List l, int lo, int hi) {
    /* KAMUS LOKAL
     *
     * p   : Address {pointer traversal}
     * cnt : int {penghitung elemen yang memenuhi}
     */
    Address p = FIRST(l);
    int cnt = 0; 

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    while (p != NULL) {

        if (INFO(p) >= lo && INFO(p) <= hi) {
            cnt++;
            p = NEXT(p);
        }

        else p = NEXT(p);
    }
    return cnt;
}

int main () {
    List l;
    CreateList(&l);
    insertLast(&l, 10);
    insertLast(&l, 25);
    insertLast(&l, 30);
    insertLast(&l, 5);
    insertLast(&l, 50);

    printf("%d\n", countInRange(l, 10, 30)); /* harusnya 3 */

    return 0;
}
