#ifndef ANALISIS_CATATAN_H
#define ANALISIS_CATATAN_H

/* DEFINISI KONSTANTA */
#define MAX_KATA 50

/* FUNGSI BANTUAN (SUDAH DIIMPLEMENTASIKAN) */
int isPalindrom(const char *kata, int panjang);
/* Menghasilkan 1 jika kata palindrom dengan panjang >= 2, atau 0 jika tidak.
   I.S. panjang >= 0; kata berisi sedikitnya panjang karakter.
   F.S. Isi kata tidak berubah. Tidak memerlukan penanda akhir '\0'. */

/* DEFINISI DAN SPESIFIKASI */
void analisisCatatan(int *jmlKata, int *terpanjang, int *jmlPalindrom);
/* Membaca seluruh pita karakter dengan mesin karakter dan menganalisis kata-katanya.
   Kata adalah rangkaian huruf kecil 'a'-'z' berurutan yang maksimal;
   karakter lain (spasi, newline) adalah pemisah.
   Palindrom adalah kata dengan panjang >= 2 yang terbaca sama dari depan dan belakang.
   I.S. Pita belum dibaca (START belum dipanggil).
        Pita berisi huruf kecil, spasi, dan newline, diakhiri MARK.
        Panjang setiap kata <= MAX_KATA.
   F.S. Pita sudah dibaca sampai MARK (EOP true).
        *jmlKata      berisi banyaknya kata.
        *terpanjang   berisi panjang kata terpanjang (0 jika tidak ada kata).
        *jmlPalindrom berisi banyaknya kata palindrom.
        Tidak ada keluaran yang dicetak oleh prosedur ini. */

#endif