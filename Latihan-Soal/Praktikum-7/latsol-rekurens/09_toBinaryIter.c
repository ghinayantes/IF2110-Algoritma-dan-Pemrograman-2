/* File: toBinaryIter.c */
/* Konversi desimal ke biner dengan dua parameter input/output */

#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Seorang teknisi lampu lalu lintas menerima kode warna dalam bilangan
 * desimal n, tetapi panel kendali hanya membaca bilangan biner. Ia
 * mengubah n dengan membagi dua berulang-ulang, dan menulis sisa baginya
 * dari digit paling kanan ke kiri.
 *
 * TUGAS
 * Versi iteratifnya adalah:
 *    place <- 1, accm <- 0
 *    while n > 0 do
 *        accm <- accm + (n mod 2) * place
 *        place <- place * 10
 *        n <- n / 2
 * Implementasikan prosedur toBinaryIter yang melakukan hal yang sama
 * dengan call rekursif. Hasil berupa bilangan desimal yang digit-digitnya
 * adalah bit biner (misalnya 10 menjadi 1010), dan disimpan pada accm.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : 0 <= n <= 1023. *place HARUS diinisialisasi 1 dan *accm HARUS
 *         diinisialisasi 0 saat pemanggilan pertama
 * F.S.  : *accm berisi representasi biner n
 *
 * Contoh pemanggilan:
 *    int place = 1, accm = 0;
 *    toBinaryIter(10, &place, &accm);   -> accm = 1010
 *    place = 1; accm = 0;
 *    toBinaryIter(5, &place, &accm);    -> accm = 101
 *    place = 1; accm = 0;
 *    toBinaryIter(0, &place, &accm);    -> accm = 0
 *
 * Hint: pada basis (n = 0) tidak ada yang perlu dilakukan, sebab hasil
 *       sudah berada di accm
 */
void toBinaryIter(int n, int *place, int *accm) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
