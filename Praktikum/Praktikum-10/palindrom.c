#include "palindrom.h"

static boolean cekPalindrom(Word w) {
    int kiri = 0;
    int kanan = w.Length - 1;
    while (kiri < kanan) {
        if (w.TabWord[kiri] != w.TabWord[kanan]) {
            return false;
        }
        kiri++;
        kanan--;
    }
    return true;
}

void palindromTerpanjang(void) {
    int jumlahPalindrom = 0;
    Word maxPal;
    maxPal.Length = 0;

    STARTWORD();
    while (!EndWord) {
        if (cekPalindrom(currentWord)) {
            jumlahPalindrom++;
            if (currentWord.Length > maxPal.Length) {
                maxPal = currentWord;
            }
        }
        ADVWORD();
    }

    if (jumlahPalindrom > 0) {
        printf("%d ", jumlahPalindrom);
        for (int i = 0; i < maxPal.Length; i++) {
            printf("%c", maxPal.TabWord[i]);
        }
        printf("\n");
    } else {
        printf("0\n");
    }
}
