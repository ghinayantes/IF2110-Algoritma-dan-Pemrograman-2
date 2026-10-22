/* File: prefixSum.c */
/* Mengubah list menjadi jumlah kumulatif (prefix sum) */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Dina menabung setiap hari dan mencatat setoran harian dalam sebuah list
 * (nilai negatif berarti penarikan). Ia ingin mengubah catatan tersebut
 * menjadi catatan saldo, yaitu saldo setelah setiap hari.
 *
 * TUGAS
 * Implementasikan prosedur prefixSum yang mengubah setiap elemen l menjadi
 * jumlah dari elemen tersebut dan seluruh elemen sebelumnya (in-place,
 * tanpa alokasi node baru).
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : elemen ke-i menjadi e0 + e1 + ... + ei
 *
 * Contoh:
 * Jika l = [1,2,3,4],  maka setelah prefixSum(&l), l menjadi [1,3,6,10]
 * Jika l = [3,-1,2],   maka l menjadi [3,2,4]
 * Jika l = [5],        maka l tetap [5]
 * Jika l = [],         maka l tetap []
 */
void prefixSum(List *l) {
    /* KAMUS LOKAL
     *
     * curr  : Address {pointer traversal}
     * total : int {akumulasi jumlah sampai node saat ini}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
