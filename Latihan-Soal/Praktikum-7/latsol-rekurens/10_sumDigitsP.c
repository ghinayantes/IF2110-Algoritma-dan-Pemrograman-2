/* File: sumDigitsP.c */
/* Jumlah digit dengan prosedur rekursif memakai variabel lokal temp (alt-1) */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah sistem verifikasi menjumlahkan semua digit nomor antrean untuk
 * membentuk kode cek. Pak Anto ingin menghitungnya dengan prosedur yang
 * menyimpan hasil jumlah digit sisa (selain digit terakhir) pada sebuah
 * variabel lokal sementara.
 *
 * TUGAS
 * Implementasikan prosedur sumDigitsP dengan gaya "prosedur alt-1" pada
 * materi (seperti factorialP1): pada kasus rekurens, panggil prosedur
 * itu sendiri untuk bilangan n/10 dengan hasil ditampung pada variabel
 * lokal temp, lalu hitung *result dari temp dan digit terakhir.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : n >= 0. *result sembarang
 * F.S.  : *result = jumlah semua digit n
 *
 * Contoh:
 * sumDigitsP(1234, &r) -> r = 10
 * sumDigitsP(9, &r)    -> r = 9
 * sumDigitsP(0, &r)    -> r = 0
 * sumDigitsP(1000, &r) -> r = 1
 *
 * Hint: basis adalah n = 0; digit terakhir n adalah n mod 10
 */
void sumDigitsP(int n, int *result) {
    /* KAMUS LOKAL
     *
     * temp : int {menampung jumlah digit dari n/10}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
