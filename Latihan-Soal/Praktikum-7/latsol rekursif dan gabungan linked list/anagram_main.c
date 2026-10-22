/* File: anagram_main.c */
/* Program utama untuk soal anagram. Kompilasi bersama anagram.c:
 *    gcc anagram_main.c anagram.c -o anagram && ./anagram
 *
 * FORMAT MASUKAN
 * Satu baris berisi sebuah kata (huruf kecil, semua huruf berbeda, panjang 1..6)
 *
 * FORMAT KELUARAN
 * Semua anagram, satu per baris, dengan urutan huruf dipilih dari kiri
 * ke kanan pada sisa huruf
 *
 * CONTOH MASUKAN
 * abc
 * CONTOH KELUARAN
 * abc
 * acb
 * bac
 * bca
 * cab
 * cba
 */

#include "anagram.h"

int main(void) {
    char kata[MAXLEN + 1];
    scanf("%10s", kata);
    findAnagram(kata);
    return 0;
}
