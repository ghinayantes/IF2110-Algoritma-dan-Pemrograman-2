#include "timbang_kata.h"

static boolean isAt(Word w) {
    return w.Length == 1 && w.TabWord[0] == '@';
}

void timbang(void) {
    int kiri = 0, kanan = 0;
    STARTWORD();
    while (!EndWord && !isAt(currentWord)) {
        kiri++;
        ADVWORD();
    }
    if (!EndWord) {
        ADVWORD(); 
    }
    while (!EndWord) {
        kanan++;
        ADVWORD();
    }
    if (kiri > kanan) printf("KIRI\n");
    else if (kanan > kiri) printf("KANAN\n");
    else printf("SEIMBANG\n");
}
