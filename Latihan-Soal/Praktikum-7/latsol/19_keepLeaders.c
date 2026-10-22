/* File: keepLeaders.c */
/* Menghapus node yang terhalang oleh node lebih besar di kanannya */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sepanjang pantai berdiri deretan gedung dari kiri ke kanan; tinggi
 * gedung tercatat dalam sebuah list. Laut berada di sisi KANAN. Sebuah
 * gedung terhalang pemandangannya jika di sebelah kanannya (di mana saja)
 * terdapat gedung yang LEBIH TINGGI. Pemerintah kota ingin merobohkan
 * semua gedung yang terhalang.
 *
 * TUGAS
 * Implementasikan prosedur keepLeaders yang menghapus setiap node yang di
 * sebelah kanannya terdapat node dengan nilai LEBIH BESAR (strictly).
 * Node yang dihapus harus di-dealokasi. Urutan node yang tersisa tidak berubah.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : hanya node yang nilainya >= semua node di kanannya yang tersisa
 *
 * Contoh:
 * Jika l = [5,2,13,3,8], maka setelah keepLeaders(&l), l menjadi [13,8]
 * Jika l = [1,2,3,4],    maka l menjadi [4]
 * Jika l = [4,3,2,1],    maka l tetap [4,3,2,1]
 * Jika l = [3,3,3],      maka l tetap [3,3,3]
 * Jika l = [],           maka l tetap []
 *
 * Hint: akan jauh lebih mudah jika list dibalik terlebih dahulu sehingga
 *       "kanan" menjadi "kiri"; pertahankan nilai maksimum yang telah dilihat,
 *       lalu balik kembali di akhir
 */
void keepLeaders(List *l) {
    /* KAMUS LOKAL
     *
     * prev : Address {pointer bantu saat membalik list}
     * curr : Address {pointer traversal}
     * next : Address {pointer ke node setelah curr, sebelum curr diubah}
     * max  : int {nilai maksimum yang telah dilihat dari sisi kanan}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
