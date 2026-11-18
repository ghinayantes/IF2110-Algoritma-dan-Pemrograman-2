#include "mesinkata.h"

boolean EndWord;
Word currentWord;

static boolean isBlank(char c) {
    return c == BLANK || c == '\n' || c == '\r' || c == '\t';
}

void IgnoreBlanks(void) {
    while (isBlank(currentChar)) {
        ADV();
    }
}

void STARTWORD(void) {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(void) {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(void) {
    int i = 0;
    while (currentChar != MARK && !isBlank(currentChar)) {
        if (i < NMax) {
            currentWord.TabWord[i] = currentChar;
        }
        i++;
        ADV();
    }
    currentWord.Length = (i < NMax) ? i : NMax;
}
