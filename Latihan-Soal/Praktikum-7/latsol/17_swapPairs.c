/* File: swapPairs.c */
/* Menukar setiap pasangan node bersebelahan */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Di kelas tari, penari berbaris sesuai nomor urut yang tercatat dalam
 * sebuah list. Sang pelatih ingin setiap dua penari yang bersebelahan
 * (pasangan 1-2, 3-4, 5-6, ...) bertukar tempat. Jika jumlah penari
 * ganjil, penari terakhir tetap pada tempatnya.
 *
 * TUGAS
 * Implementasikan prosedur swapPairs yang menukar posisi setiap pasangan
 * node bersebelahan. Penukaran harus dilakukan dengan mengubah pointer
 * NEXT (relink), BUKAN dengan menukar nilai INFO. Tidak ada
 * alokasi/dealokasi node.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : setiap pasangan node bersebelahan saling bertukar posisi
 *
 * Contoh:
 * Jika l = [1,2,3,4],   maka setelah swapPairs(&l), l menjadi [2,1,4,3]
 * Jika l = [1,2,3,4,5], maka l menjadi [2,1,4,3,5]
 * Jika l = [1],         maka l tetap [1]
 * Jika l = [],          maka l tetap []
 *
 * Hint: simpan pointer ke node terakhir dari pasangan sebelumnya agar bisa
 *       disambungkan ke pasangan yang baru ditukar; jangan lupa update FIRST(l)
 */
void swapPairs(List *l) {
    /* KAMUS LOKAL
     *
     * prev   : Address {pointer ke node terakhir pada pasangan sebelumnya, NULL di awal}
     * first  : Address {pointer ke node pertama pada pasangan yang sedang diproses}
     * second : Address {pointer ke node kedua pada pasangan yang sedang diproses}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
