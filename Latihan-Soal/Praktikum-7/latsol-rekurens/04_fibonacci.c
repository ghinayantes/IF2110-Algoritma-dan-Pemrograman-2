/* File: fibonacci.c */
/* Menghitung bilangan Fibonacci ke-n secara rekursif */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang peternak mencatat jumlah pasang kelinci dari bulan ke bulan.
 * Pada bulan ke-0 ada 0 pasang, bulan ke-1 ada 1 pasang, dan sejak bulan
 * ke-2 jumlahnya adalah jumlah dua bulan sebelumnya. Peternak ingin
 * mengetahui jumlah pasang kelinci pada bulan ke-n.
 *
 * TUGAS
 * Implementasikan fungsi fibonacci dengan definisi rekursif:
 *    fibonacci(0) = 0
 *    fibonacci(1) = 1
 *    fibonacci(n) = fibonacci(n-1) + fibonacci(n-2) untuk n >= 2
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 * Perhatikan bahwa soal ini memiliki DUA basis.
 *
 * I.S.  : 0 <= n <= 30
 * F.S.  : mengembalikan bilangan Fibonacci ke-n
 *
 * Contoh:
 * fibonacci(0)  = 0
 * fibonacci(1)  = 1
 * fibonacci(6)  = 8
 * fibonacci(10) = 55
 */
int fibonacci(int n) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    printf("%d\n", fibonacci(10)); 
}