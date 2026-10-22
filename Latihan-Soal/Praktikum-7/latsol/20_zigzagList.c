/* File: zigzagList.c */
/* Menyusun ulang list secara bergantian dari depan dan belakang */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah wahana taman hiburan memiliki antrean pengunjung yang tercatat
 * dalam sebuah list. Agar adil, petugas memanggil pengunjung secara
 * bergantian: satu dari paling depan, satu dari paling belakang, lalu
 * satu dari depan lagi yang tersisa, satu dari belakang yang tersisa,
 * dan seterusnya.
 *
 * TUGAS
 * Implementasikan prosedur zigzagList yang menyusun ulang list
 * e0,e1,...,e(n-1) menjadi e0,e(n-1),e1,e(n-2),e2,e(n-3),...
 * Dilakukan secara in-place, tanpa alokasi/dealokasi node dan tanpa
 * array.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : elemen l tersusun secara zigzag seperti di atas
 *
 * Contoh:
 * Jika l = [1,2,3,4,5], maka setelah zigzagList(&l), l menjadi [1,5,2,4,3]
 * Jika l = [1,2,3,4],   maka l menjadi [1,4,2,3]
 * Jika l = [1,2],       maka l tetap [1,2]
 * Jika l = [1],         maka l tetap [1]
 * Jika l = [],          maka l tetap []
 *
 * Hint: (1) cari node tengah dengan slow-fast pointer, (2) putus list
 *       menjadi dua bagian, (3) balik bagian kedua, (4) gabungkan kedua
 *       bagian secara bergantian
 */
void zigzagList(List *l) {
    /* KAMUS LOKAL
     *
     * slow   : Address {pointer ke node tengah}
     * fast   : Address {pointer yang bergerak 2 langkah untuk mencari tengah}
     * second : Address {pointer ke node pertama bagian kedua (yang sudah dibalik)}
     * first  : Address {pointer traversal bagian pertama}
     * prev, curr, next : Address {pointer bantu saat membalik bagian kedua}
     * n1, n2 : Address {penyimpan sementara NEXT saat menyambung bergantian}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
