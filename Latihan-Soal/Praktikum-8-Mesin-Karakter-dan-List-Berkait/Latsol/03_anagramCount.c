/* Nama File: anagramcount.c */
/* Kompilasi: gcc 03_anagramCount.c mesinkata.c mesinkarakter.c -o ac */

#include "mesinkata.c"
#include "mesinkarakter.c"
#include "listword.h"
#include "boolean.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang guru bahasa membuat permainan menebak anagram. Kata pertama pada
 * sebuah kalimat adalah kata acuan, dan murid-murid harus menemukan berapa
 * banyak kata lain pada kalimat itu yang tersusun dari huruf-huruf yang sama
 * dengan kata acuan (hanya urutan hurufnya yang berbeda).
 *
 * Fungsi isAnagram
 * Dua kata disebut anagram jika panjangnya sama dan setiap huruf muncul
 * dengan jumlah yang sama pada kedua kata. Pengecekan case-sensitive
 * (huruf besar dan kecil dianggap berbeda). Kata yang identik juga anagram.
 * I.S. a dan b terdefinisi
 * F.S. return true jika a dan b anagram, false jika tidak
 *
 * Contoh:
 * - "listen" dan "silent" -> true
 * - "abc" dan "abcd" -> false
 * - "abc" dan "abd" -> false
 * - "Abc" dan "abc" -> false
 * - "aab" dan "aba" -> true
 *
 * Fungsi countAnagrams
 * Membaca kalimat dengan mesin kata. Kata pertama adalah acuan. Hitung banyaknya
 * kata SETELAH kata pertama yang merupakan anagram dari kata pertama.
 * I.S. mesin kata siap digunakan (belum START)
 * F.S. return banyaknya kata (selain kata pertama) yang anagram dengan kata pertama
 *
 * Format Masukan:
 * - Satu baris berisi 1 sampai 1000 kata dipisahkan whitespace(s), diakhiri MARK '.'
 *
 * Format Keluaran:
 * - Satu bilangan bulat, diikuti endline
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                                  Keluaran  Keterangan
 * 1.  listen silent enlist tinsel google listen.   4      silent, enlist, tinsel, listen
 * 2.  abc cba abcd bca xyz.                        2      cba, bca
 * 3.  a.                                           0      tidak ada kata lain
 * 4.  Abc abc cba.                                 0      huruf besar berbeda dengan kecil
 *
 * Hint: gunakan array frekuensi huruf berukuran 128 (indeks = kode karakter).
 *       Tambah untuk kata pertama, kurangi untuk kata kedua, lalu periksa
 *       apakah semuanya kembali nol
 */
boolean isAnagram(Word a, Word b) {
    /* KAMUS LOKAL
     *
     * freq : array [0..127] of int {selisih frekuensi tiap karakter}
     * i    : int
     */
    int freq[128], i;

    if (isWordEqual(a, b)) return true;

    for(i = 0; i < 128; i++) {
        freq[i] = 0;
    }

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    for(i = 0; i < a.Length; i++) {
        freq[(int) a.TabWord[i]]++;
    }

    for(i = 0; i < b.Length; i++) {
        freq[(int) b.TabWord[i]]--;
    }
    
    for(i = 0; i < 128; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int countAnagrams() {
    /* KAMUS LOKAL
     *
     * first : Word {kata acuan (kata pertama)}
     * cnt   : int {banyaknya anagram yang ditemukan}
     */
    Word first;
    int cnt = 0;

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    STARTWORD();
    first = currentWord;
    ADVWORD();
    while (!EndWord) {
        if (isAnagram(first, currentWord)) cnt++;
        ADVWORD();
    }
    return cnt;
}

int main(void) {
    printf("%d\n", countAnagrams());
    return 0;
}
