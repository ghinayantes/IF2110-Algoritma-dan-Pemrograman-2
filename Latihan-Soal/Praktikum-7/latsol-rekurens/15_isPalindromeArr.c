/* File: isPalindromeArr.c */
/* Memeriksa palindrom pada list statik dengan dua indeks secara rekursif */

#include "listarray.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah brankas memiliki kata sandi berupa deretan angka. Sandi dianggap
 * "simetris" jika dibaca dari kiri maupun dari kanan hasilnya sama.
 * Sistem keamanan ingin memeriksa apakah rentang sandi dari indeks lo
 * sampai hi bersifat simetris.
 *
 * TUGAS
 * Implementasikan fungsi isPalindromeArr yang bernilai true jika elemen
 * l pada indeks lo sampai hi (inklusif) membentuk palindrom.
 * Rentang kosong atau satu elemen dianggap palindrom.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : l terdefinisi. Untuk memeriksa seluruh list, panggil dengan lo = 0 dan hi = nEff-1
 * F.S.  : mengembalikan true jika l.contents[lo..hi] palindrom, false jika tidak
 *
 * Contoh:
 * isPalindromeArr([1,2,3,2,1], 0, 4) = true
 * isPalindromeArr([1,2,2,1], 0, 3)   = true
 * isPalindromeArr([1,2,3], 0, 2)     = false
 * isPalindromeArr([4], 0, 0)         = true
 * isPalindromeArr([], 0, -1)         = true
 *
 * Hint: basis adalah lo >= hi; rekurens membandingkan elemen paling kiri
 *       dan paling kanan, lalu mengecilkan rentang menjadi lo+1 .. hi-1
 */
boolean isPalindromeArr(List l, int lo, int hi) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return false;
}
