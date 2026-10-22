/* File: powerIter.c */
/* Menghitung pangkat dengan accumulator (parameter input/output) */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang pedagang menaikkan harga barangnya x kali lipat setiap bulan.
 * Ia mencatat hasilnya dengan sebuah akumulator yang dikalikan x setiap
 * bulan, selama n bulan. Catatan akhir akumulator adalah x pangkat n.
 *
 * TUGAS
 * Versi iteratifnya adalah:
 *    accm <- 1
 *    repeat n times: accm <- accm * x
 *    result <- accm
 * Implementasikan prosedur powerIter yang melakukan hal yang sama dengan
 * call rekursif. Hasil sementara disimpan pada parameter input/output accm.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : n >= 0. *accm HARUS diinisialisasi 1 saat pemanggilan pertama. *result sembarang
 * F.S.  : *result = x pangkat n
 *
 * Contoh pemanggilan:
 *    int accm = 1, result;
 *    powerIter(2, 10, &accm, &result);   -> result = 1024
 *    accm = 1;
 *    powerIter(5, 0, &accm, &result);    -> result = 1
 *
 * Hint: tiap call rekursif mengalikan accm dengan x dan mengurangi n sebanyak 1
 */
void powerIter(int x, int n, int *accm, int *result) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 0) *result = *accm;
    else {
        *accm = *accm * x;
        powerIter(x, n-1, accm, result);
    }
}

int main() {
    int accm = 1, result;
    powerIter(5, 0, &accm, &result);
    printf("%d\n", result);
}
