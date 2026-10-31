#include "analisis_catatan.h"

int isPalindrom(const char *kata, int panjang) {
    if (panjang < 2) {
        return 0;
    }
    for (int i = 0, j = panjang - 1; i < j; i++, j--) {
        if (kata[i] != kata[j]) {
            return 0;
        }
    }
    return 1;
}