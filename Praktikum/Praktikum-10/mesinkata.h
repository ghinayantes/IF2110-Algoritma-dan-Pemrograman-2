#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"
#include "mesinkarakter.h"

/* MESIN KATA */
#define NMax 50
#define BLANK ' '

typedef struct {
    char TabWord[NMax]; /* Tidak diakhiri '\0'; gunakan Length untuk panjang kata. */
    int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks(void);
/* Mengabaikan satu atau beberapa BLANK.
   Pada mesin ini, spasi, tab, dan baris baru semuanya dianggap BLANK.
   I.S. : currentChar sembarang
   F.S. : currentChar bukan BLANK atau currentChar = MARK */

void STARTWORD(void);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(void);
/* I.S. : EndWord = false; currentWord adalah kata yang sedang diproses.
   F.S. : Jika masih ada kata berikutnya, EndWord = false dan currentWord
          berisi kata tersebut. currentChar berada di awal kata sesudahnya
          atau pada MARK. Kata yang baru diakuisisi tetap perlu diproses,
          termasuk ketika currentChar sudah MARK.
          Jika tidak ada kata berikutnya, EndWord = true dan currentChar = MARK.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord(void);
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif
