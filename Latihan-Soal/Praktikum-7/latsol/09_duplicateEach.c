/* File: duplicateEach.c */
/* Menggandakan setiap elemen list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Mesin fotokopi di perpustakaan menerima tumpukan lembar dokumen yang
 * kodenya tercatat dalam sebuah list. Setiap lembar harus difotokopi
 * sekali, dan salinannya diletakkan tepat setelah lembar aslinya.
 *
 * TUGAS
 * Implementasikan prosedur duplicateEach yang menyisipkan node baru
 * bernilai sama tepat setelah setiap node pada list l.
 * Jika alokasi suatu node gagal, lewati node tersebut.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : setiap elemen l muncul dua kali berurutan
 *
 * Contoh:
 * Jika l = [1,2,3], maka setelah duplicateEach(&l), l menjadi [1,1,2,2,3,3]
 * Jika l = [9],     maka l menjadi [9,9]
 * Jika l = [],      maka l tetap []
 *
 * Hint: setelah menyisipkan salinan, majulah melewati salinan tersebut
 */
void duplicateEach(List *l) {
    /* KAMUS LOKAL
     *
     * curr : Address {pointer ke node asli yang sedang diproses}
     * dup  : Address {pointer ke node salinan yang baru dialokasi}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
