/* File: moveMaxToEnd.c */
/* Memindahkan node bernilai maksimum ke akhir list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah kapal kargo memuat kontainer yang beratnya tercatat dalam list
 * dari haluan ke buritan. Demi keseimbangan kapal, kontainer terberat
 * harus dipindahkan ke posisi paling belakang. Jika ada beberapa
 * kontainer dengan berat maksimum yang sama, cukup pindahkan yang paling depan.
 *
 * TUGAS
 * Implementasikan prosedur moveMaxToEnd yang memindahkan node dengan nilai
 * maksimum (kemunculan pertama) ke akhir list, secara in-place tanpa
 * alokasi/dealokasi node. Urutan elemen lainnya tetap.
 *
 * I.S.  : l terdefinisi, tidak kosong
 * F.S.  : node bernilai maksimum (kemunculan pertama) berada di akhir list
 *
 * Contoh:
 * Jika l = [3,9,2,5], maka setelah moveMaxToEnd(&l), l menjadi [3,2,5,9]
 * Jika l = [1,2,3],   maka l tetap [1,2,3]
 * Jika l = [7,1,7],   maka l menjadi [1,7,7]
 * Jika l = [4],       maka l tetap [4]
 *
 * Hint: catat node maksimum beserta node sebelumnya, serta node terakhir list
 */
void moveMaxToEnd(List *l) {
    /* KAMUS LOKAL
     *
     * maxNode : Address {pointer ke node bernilai maksimum (kemunculan pertama)}
     * maxPrev : Address {pointer ke node tepat sebelum maxNode, NULL jika maxNode node pertama}
     * curr    : Address {pointer traversal}
     * prev    : Address {pointer ke node tepat sebelum curr}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
