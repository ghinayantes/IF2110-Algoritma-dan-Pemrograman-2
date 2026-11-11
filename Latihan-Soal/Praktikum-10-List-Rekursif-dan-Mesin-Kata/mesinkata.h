#ifndef MESINKATA_H
#define MESINKATA_H

#include <stdbool.h>
#include "mesinkarakter.h"

/* MESIN KATA */
/* Dibangun di atas mesin karakter. Pita diakhiri MARK. */
#define NMAX 50
#define BLANK ' '

typedef struct {
    char buffer[NMAX];
    int length;
} Word;

/* State Mesin Kata */
extern bool endWord;
extern Word currentWord;

void ignoreBlanks(void);
/* I.S. : currentChar sembarang
   F.S. : currentChar != BLANK atau currentChar == MARK */

void startWord(void);
/* I.S. : sembarang
   F.S. : endWord == true dan currentChar == MARK; atau
          endWord == false, currentWord adalah kata pertama pada pita,
          currentChar adalah karakter sesudah karakter terakhir kata. */

void advWord(void);
/* I.S. : currentChar == BLANK atau currentChar == MARK
   F.S. : endWord == true dan currentChar == MARK; atau
          currentWord adalah kata berikutnya,
          currentChar adalah karakter sesudah karakter terakhir kata. */

void copyWord(void);
/* I.S. : currentChar adalah karakter pertama sebuah kata
   F.S. : currentWord berisi paling banyak NMAX karakter pertama kata;
          currentChar == BLANK atau currentChar == MARK. */

/* ---- Tambahan untuk praktikum ---- */
Word buatKata(const char *s);
/* Membuat Word dari string s (panjang s <= NMAX). */

bool isWordEqual(Word w1, Word w2);
/* Mengembalikan true jika w1 dan w2 sama (panjang dan isi). */

int kataKeInt(Word w);
/* Mengubah kata berisi bilangan bulat (boleh diawali '-') menjadi int.
   I.S. w adalah representasi bilangan bulat yang valid. */

#endif
