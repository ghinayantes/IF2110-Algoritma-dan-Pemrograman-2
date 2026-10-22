/* File: insertLastRec.c */
/* Menyisipkan elemen di akhir linked list secara rekursif */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang pelanggan baru datang ke sebuah kedai dan harus berdiri di
 * paling belakang antrean. Antrean disimpan dalam linked list dan nomor
 * pelanggan baru ditambahkan di akhir list.
 *
 * TUGAS
 * Implementasikan prosedur insertLastRec yang menambahkan sebuah node
 * bernilai val di akhir list l, secara rekursif. Gunakan newNode untuk
 * alokasi. Jika alokasi gagal, I.S. = F.S.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * memanggil insertFirst maupun insertLast.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : val menjadi elemen terakhir l
 *
 * Contoh:
 * Jika l = [1,2], maka setelah insertLastRec(&l, 3), l menjadi [1,2,3]
 * Jika l = [],    maka setelah insertLastRec(&l, 7), l menjadi [7]
 *
 * Hint: basis adalah l (yang dipegang pointer) sudah NULL, yaitu tempat
 *       node baru dipasang; pada rekurens, panggil prosedur ini untuk
 *       alamat field next dari node saat ini, yaitu &NEXT(*l)
 */
void insertLastRec(List *l, ElType val) {
    /* KAMUS LOKAL
     *
     * p : Address {pointer ke node baru}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
