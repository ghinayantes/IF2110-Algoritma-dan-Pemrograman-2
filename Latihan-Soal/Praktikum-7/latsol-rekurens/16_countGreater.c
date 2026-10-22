/* File: countGreater.c */
/* Menghitung node yang nilainya melebihi batas pada linked list secara rekursif */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah wahana taman hiburan mensyaratkan tinggi pengunjung tidak boleh
 * lebih dari batas x cm. Tinggi para pengantre disimpan dalam sebuah
 * linked list. Petugas ingin tahu berapa pengantre yang tingginya
 * MELEBIHI x.
 *
 * TUGAS
 * Implementasikan fungsi countGreater yang mengembalikan banyaknya node
 * l yang nilainya lebih besar dari x (strictly).
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * memanggil length. List diproses lewat call rekursif pada NEXT.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan banyaknya node bernilai > x. l tidak berubah
 *
 * Contoh:
 * countGreater([5,1,8,3], 3) = 2    (5 dan 8)
 * countGreater([5,1,8,3], 0) = 4
 * countGreater([5,1,8,3], 10) = 0
 * countGreater([], 3)        = 0
 *
 * Hint: basis adalah list kosong (l = NULL)
 */
int countGreater(List l, ElType x) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return 0;
}
