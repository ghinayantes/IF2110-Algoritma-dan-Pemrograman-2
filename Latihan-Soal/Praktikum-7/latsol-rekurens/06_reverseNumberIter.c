/* File: reverseNumberIter.c */
/* Membalik digit bilangan dengan accumulator (parameter input/output) */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah mesin sandi kuno membaca nomor kode dari digit paling kanan ke
 * kiri. Teknisi ingin mengubah nomor kode menjadi bentuk terbaliknya,
 * misalnya 1234 menjadi 4321, dengan memproses satu digit setiap kali.
 *
 * TUGAS
 * Versi iteratifnya adalah:
 *    accm <- 0
 *    while n > 0 do accm <- accm*10 + (n mod 10); n <- n/10
 *    result <- accm
 * Implementasikan prosedur reverseNumberIter yang melakukan hal yang sama
 * dengan mekanisme call rekursif (bukan loop). Hasil sementara disimpan
 * pada parameter input/output accm.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : n >= 0. *accm HARUS diinisialisasi 0 saat pemanggilan pertama. *result sembarang
 * F.S.  : *result berisi bilangan n dengan urutan digit dibalik
 *         (nol di depan hasil balikan hilang)
 *
 * Contoh pemanggilan:
 *    int accm = 0, result;
 *    reverseNumberIter(1234, &accm, &result);   -> result = 4321
 *    reverseNumberIter(100, &accm, &result);    -> result = 1   (accm harus di-0 kan lagi!)
 *    reverseNumberIter(0, &accm, &result);      -> result = 0
 *
 * Hint: basis adalah n = 0, ketika itu hasil akhir sudah berada di accm
 */
void reverseNumberIter(int n, int *accm, int *result) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 0) *result = *accm;
    else {
        *accm = (*accm * 10) + (n % 10);
        reverseNumberIter(n/10, accm, result);
    }
}

int main() {
    int accm = 0, result;
    reverseNumberIter(1234, &accm, &result);
    printf("%d\n", result);

    return 0;
}