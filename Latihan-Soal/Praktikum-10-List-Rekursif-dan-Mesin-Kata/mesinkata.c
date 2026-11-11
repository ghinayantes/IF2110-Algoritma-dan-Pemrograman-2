#include "mesinkata.h"

bool endWord;
Word currentWord;

void ignoreBlanks(void) {
    while (currentChar == BLANK) {
        ADV();
    }
}

void copyWord(void) {
    int i = 0;
    while (!EOP() && currentChar != BLANK) {
        if (i < NMAX) {
            currentWord.buffer[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.length = i;
}

void startWord(void) {
    START();
    ignoreBlanks();
    if (EOP()) {
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
}

void advWord(void) {
    ignoreBlanks();
    if (EOP()) {
        endWord = true;
    } else {
        copyWord();
    }
}

Word buatKata(const char *s) {
    Word w;
    int i = 0;
    while (s[i] != '\0' && i < NMAX) {
        w.buffer[i] = s[i];
        i++;
    }
    w.length = i;
    return w;
}

bool isWordEqual(Word w1, Word w2) {
    int i;
    if (w1.length != w2.length) return false;
    for (i = 0; i < w1.length; i++) {
        if (w1.buffer[i] != w2.buffer[i]) return false;
    }
    return true;
}

int kataKeInt(Word w) {
    int i = 0, hasil = 0, negatif = 0;
    if (w.length > 0 && w.buffer[0] == '-') {
        negatif = 1;
        i = 1;
    }
    for (; i < w.length; i++) {
        hasil = hasil * 10 + (w.buffer[i] - '0');
    }
    return negatif ? -hasil : hasil;
}
