/* File: gcd.c */
/* Menghitung FPB dua bilangan dengan algoritma Euclid secara rekursif */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang penjahit memiliki selembar kain berukuran a x b cm dan ingin
 * memotongnya menjadi petak persegi berukuran sama tanpa sisa, dengan
 * petak sebesar mungkin. Panjang sisi petak terbesar itu adalah FPB dari a dan b.
 *
 * TUGAS
 * Implementasikan fungsi gcd yang mengembalikan FPB a dan b dengan
 * algoritma Euclid:
 *    gcd(a,b) = a                  jika b = 0
 *    gcd(a,b) = gcd(b, a mod b)    jika b > 0
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : a >= 0, b >= 0, dan a, b tidak keduanya 0
 * F.S.  : mengembalikan FPB dari a dan b
 *
 * Contoh:
 * gcd(12,18) = 6
 * gcd(17,5)  = 1
 * gcd(0,9)   = 9
 * gcd(48,36) = 12
 *
 * Hint: pada call rekursif, parameter kedua (a mod b) selalu lebih kecil dari b
 */
int gcd(int a, int b) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    printf("%d\n", gcd(48,36)); 
}
