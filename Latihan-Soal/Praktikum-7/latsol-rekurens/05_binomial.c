/* File: binomial.c */
/* Menghitung koefisien binomial C(n,k) secara rekursif */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Panitia lomba ingin membentuk tim beranggotakan k orang dari n peserta
 * yang mendaftar. Mereka ingin tahu ada berapa kemungkinan susunan tim
 * yang berbeda (urutan anggota tidak diperhatikan). Banyaknya kemungkinan
 * itu adalah koefisien binomial C(n,k).
 *
 * TUGAS
 * Implementasikan fungsi binomial dengan identitas Pascal:
 *    C(n,k) = 1                         jika k = 0 atau k = n
 *    C(n,k) = C(n-1,k-1) + C(n-1,k)     untuk 0 < k < n
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * menghitung faktorial.
 *
 * I.S.  : 0 <= k <= n <= 20
 * F.S.  : mengembalikan C(n,k)
 *
 * Contoh:
 * binomial(5,2)  = 10
 * binomial(6,0)  = 1
 * binomial(6,6)  = 1
 * binomial(10,3) = 120
 */
int binomial(int n, int k) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (k == n || k == 0) return 1;
    return binomial(n-1, k-1) + binomial(n-1, k);
}

int main() {
    printf("%d\n", binomial(10,3)); 
}