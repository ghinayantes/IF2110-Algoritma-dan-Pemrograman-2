#include "KataSeukuran.h"

static List bacaPanjang(void) {
    if (endWord) return NIL;
    int p = currentWord.length;
    advWord();
    return makeCons(p, bacaPanjang());
}

static int adaKembar(List l) {
    if (isEmpty(l) || isOneElement(l)) return 0;
    return (head(l) == head(tail(l))) || adaKembar(tail(l));
}

int adaKataSeukuran(void) {
    startWord();
    List l = bacaPanjang();
    int hasil = adaKembar(l);
    deleteAll(&l);
    return hasil;
}
