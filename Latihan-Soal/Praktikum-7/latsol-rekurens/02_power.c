/* File: power.c */
/* Menghitung x pangkat n secara rekursif */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah kolonial bakteri membelah menjadi x kali lipat setiap jam.
 * Peneliti memulai dengan 1 sel. Berapa jumlah sel setelah n jam?
 * Jawabannya adalah x pangkat n.
 *
 * TUGAS
 * Implementasikan fungsi power yang mengembalikan x^n untuk n bilangan
 * bulat nonnegatif, dengan definisi rekursif:
 *    x^0 = 1
 *    x^n = x * x^(n-1) untuk n > 0
 *
 * ATURAN: dilarang memakai while, for, do-while, dan dilarang memakai pow().
 *
 * I.S.  : n >= 0
 * F.S.  : mengembalikan x pangkat n (hasil diasumsikan muat dalam int)
 *
 * Contoh:
 * power(2,10) = 1024
 * power(5,0)  = 1
 * power(3,1)  = 3
 * power(7,2)  = 49
 *
 * Hint: tulis basisnya dulu, lalu pastikan parameter n mengecil pada call rekursif
 */
int power(int x, int n) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 0) return 1;
    return x * power(x, n-1);
}

int main() {
    printf("%d\n", power(2,10)); 
}
