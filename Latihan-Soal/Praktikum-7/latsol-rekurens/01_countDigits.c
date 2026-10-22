/* File: countDigits.c */
/* Menghitung banyaknya digit sebuah bilangan secara rekursif */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Loket antrean sebuah bank mencetak nomor antrean berupa bilangan bulat
 * nonnegatif. Petugas printer ingin tahu berapa banyak digit pada sebuah
 * nomor agar kertas struk dipotong dengan lebar yang pas.
 *
 * TUGAS
 * Implementasikan fungsi countDigits yang mengembalikan banyaknya digit
 * bilangan n (dalam basis 10). Bilangan 0 dianggap memiliki 1 digit.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * memakai fungsi pustaka (log10, sprintf, dst). Gunakan rekursi.
 *
 * I.S.  : n >= 0
 * F.S.  : mengembalikan banyaknya digit n
 *
 * Contoh:
 * countDigits(0)     = 1
 * countDigits(7)     = 1
 * countDigits(12345) = 5
 * countDigits(100)   = 3
 *
 * Hint: basis adalah n yang hanya satu digit (n < 10); rekurensnya
 *       membuang satu digit terakhir dengan pembagian 10
 */
int countDigits(int n) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if ((n / 10) == 0) return 1;
    else return 1 + countDigits(n / 10);
    return 0;
}

int main() {
    int n = 12345;
    printf("%d\n", countDigits(n)); 
}