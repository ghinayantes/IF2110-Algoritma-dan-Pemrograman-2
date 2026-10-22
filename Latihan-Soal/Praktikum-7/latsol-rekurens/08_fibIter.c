/* File: fibIter.c */
/* Fibonacci iteratif yang dikelola dengan call rekursif */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang pelari mencatat jarak tempuh latihannya dengan pola unik: jarak
 * hari ini adalah jumlah jarak dua hari sebelumnya. Ia hanya mau menyimpan
 * dua nilai terakhir (a dan b) agar catatannya tidak menumpuk.
 *
 * TUGAS
 * Versi iteratifnya adalah:
 *    a <- 0, b <- 1
 *    repeat n times: (a, b) <- (b, a+b)
 *    result <- a
 * Implementasikan prosedur fibIter yang melakukan hal yang sama dengan
 * call rekursif. Nilai a dan b disimpan pada parameter input/output.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : n >= 0. *a HARUS diinisialisasi 0 dan *b HARUS diinisialisasi 1
 *         saat pemanggilan pertama. *result sembarang
 * F.S.  : *result = bilangan Fibonacci ke-n
 *
 * Contoh pemanggilan:
 *    int a = 0, b = 1, result;
 *    fibIter(6, &a, &b, &result);    -> result = 8
 *    a = 0; b = 1;
 *    fibIter(1, &a, &b, &result);    -> result = 1
 *    a = 0; b = 1;
 *    fibIter(0, &a, &b, &result);    -> result = 0
 *
 * Hint: gunakan variabel lokal sementara agar nilai *a tidak tertimpa sebelum dipakai
 */
void fibIter(int n, int *a, int *b, int *result) {
    /* KAMUS LOKAL
     *
     * temp : int {penyimpan sementara jumlah a + b}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 0) *result = *a;
    else {
        int temp = *a + *b;
        *a = *b;
        *b = temp;
        fibIter(n-1, a, b, result);
    }
}

int main() {
    int a = 0, b = 1, result;
    fibIter(0, &a, &b, &result);
    printf("%d\n", result);
}
