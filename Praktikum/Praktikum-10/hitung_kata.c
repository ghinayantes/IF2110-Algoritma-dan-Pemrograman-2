#include "hitung_kata.h"

static boolean isEqual(Word w1, Word w2) {
    if (w1.Length != w2.Length) {
        return false;
    }
    for (int i = 0; i < w1.Length; i++) {
        if (w1.TabWord[i] != w2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

int hitungKemunculan(Word w) {
    int hasil = 0;
    STARTWORD();
    while (!EndWord) {
        if (isEqual(currentWord, w)) {
            hasil++;
        }
        ADVWORD();
    }
    return hasil;
}
