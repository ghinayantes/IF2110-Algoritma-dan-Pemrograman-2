#include "analisis_catatan.h"
#include "mesinkarakter.h"

#include <stdio.h>

/* Menghasilkan 1 jika kata palindrom dengan panjang >= 2, atau 0 jika tidak.
   I.S. panjang >= 0; kata berisi sedikitnya panjang karakter.
   F.S. Isi kata tidak berubah. Tidak memerlukan penanda akhir '\0'. */

int max(int a, int b) {
    if(a >= b) return a;
    return b;
}

/* DEFINISI DAN SPESIFIKASI */
void analisisCatatan(int *jmlKata, int *terpanjang, int *jmlPalindrom) {
    int cnt = 0, count = 0, pal = 0, best = 0;
    char kata[50];

    START();
    while (!EOP()) {
        if (currentChar >= 'a' && currentChar <= 'z') {
            kata[count] = currentChar;
            count++;
        } else {                           /* pemisah: kata (kalau ada) selesai */
            if (count > 0) {
                best = max(best, count);
                cnt++;
                if (isPalindrom(kata, count)) pal++;
            }
            count = 0;
        }
        ADV();
    }
    if (count > 0) {                       /* kata terakhir yang langsung disusul MARK */
        best = max(best, count);
        cnt++;
        if (isPalindrom(kata, count)) pal++;
    }

    *jmlKata = cnt;
    *terpanjang = best;
    *jmlPalindrom = pal;
}
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