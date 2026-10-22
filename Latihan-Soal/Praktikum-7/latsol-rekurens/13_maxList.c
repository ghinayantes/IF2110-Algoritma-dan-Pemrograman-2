/* File: maxList.c */
/* Mencari nilai maksimum list statik dari startIdx secara rekursif */

#include "listarray.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang atlet lompat jauh mencatat jarak setiap lompatan dalam sebuah
 * list. Pelatih ingin mengetahui lompatan terjauh dari lompatan ke-startIdx
 * sampai lompatan terakhir (tidak peduli lompatan sebelumnya).
 *
 * TUGAS
 * Implementasikan fungsi maxList yang mengembalikan nilai terbesar elemen
 * l pada indeks startIdx sampai nEff-1.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * membuat variabel penampung max yang di-update berulang-ulang
 * (gunakan nilai kembalian rekursi).
 *
 * I.S.  : l terdefinisi, 0 <= startIdx <= l.nEff-1 (rentang tidak kosong)
 * F.S.  : mengembalikan nilai maksimum l.contents[startIdx..l.nEff-1]
 *
 * Contoh:
 * maxList([3,9,2,5], 0) = 9
 * maxList([3,9,2,5], 2) = 5
 * maxList([7], 0)       = 7
 *
 * Hint: basis-1 adalah rentang yang hanya berisi satu elemen
 *       (startIdx = nEff-1); rekurensnya membandingkan elemen saat ini
 *       dengan hasil rekursi untuk sisanya
 */
int maxList(List l, int startIdx) {
    /* KAMUS LOKAL
     *
     * restMax : int {nilai maksimum dari elemen sisa setelah startIdx}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return 0;
}
