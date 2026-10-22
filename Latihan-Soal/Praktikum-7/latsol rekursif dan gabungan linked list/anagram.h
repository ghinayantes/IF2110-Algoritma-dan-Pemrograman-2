#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stdio.h>
#include <string.h>

#define MAXLEN 10

/**
 * CERITA
 * Seorang penulis teka-teki kata ingin mendaftar semua susunan huruf
 * (anagram) dari sebuah kata yang semua hurufnya berbeda.
 *
 * Fungsi rekursif untuk mendapatkan panjang string s TANPA strlen
 *
 * Contoh:
 * panjang("abcd") -> 4
 * panjang("")     -> 0
 *
 * Hint: basis adalah string kosong (karakter pertama adalah '\0')
 */
int panjang(char *s);

/**
 * Prosedur untuk menyalin string s ke hasil, kecuali karakter pada indeks idx
 * (indeks dihitung dari kiri, mulai dari 0)
 *
 * Contoh:
 * s = "abcd", idx = 2 -> hasil = "abd"
 * s = "abcd", idx = 0 -> hasil = "bcd"
 * s = "abcd", idx = 3 -> hasil = "abc"
 *
 * Jika idx < 0 atau idx >= panjang(s), hasil adalah salinan s
 * hasil harus sudah berukuran cukup (minimal panjang(s) + 1 karakter)
 */
void hapusChar(char *s, int idx, char *hasil);

/**
 * Prosedur rekursif untuk mencetak semua anagram
 *
 * sisa        : huruf-huruf yang belum dipakai
 * current     : susunan yang sedang dibangun (panjangnya bertambah tiap rekursi)
 * panjangAwal : panjang kata awal
 *
 * Basis: panjang(current) == panjangAwal -> cetak current (diikuti newline)
 *
 * Hint:
 * - gunakan loop untuk iterasi seluruh huruf pada sisa (dari kiri ke kanan)
 * - gunakan huruf terpilih sebagai tambahan di akhir current untuk membentuk newCurrent
 * - gunakan hapusChar untuk membentuk newSisa (sisa tanpa huruf terpilih)
 * - panggil kembali cariAnagram dengan newSisa dan newCurrent
 * - siapkan array char lokal (ukuran MAXLEN + 1) untuk newCurrent dan newSisa
 */
void cariAnagram(char *sisa, char *current, int panjangAwal);

/**
 * Prosedur untuk menginisialisasi pemanggilan cariAnagram
 *
 * Contoh keluaran untuk kata = "abc":
 * abc
 * acb
 * bac
 * bca
 * cab
 * cba
 */
void findAnagram(char *kata);

#endif
