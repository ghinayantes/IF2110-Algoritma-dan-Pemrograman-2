#include "DaftarUnik.h"

static void sisipUnik(List *l, int x) {
    if (isEmpty(*l) || x < INFO(*l)) {
        *l = makeCons(x, *l);
    } else if (x > INFO(*l)) {
        sisipUnik(&NEXT(*l), x);
    }
    /* x == INFO(*l): sudah ada, tidak melakukan apa-apa */
}

static void bacaKe(List *l) {
    if (!endWord) {
        sisipUnik(l, kataKeInt(currentWord));
        advWord();
        bacaKe(l);
    }
}

List daftarUnik(void) {
    List l = NIL;
    startWord();
    bacaKe(&l);
    return l;
}
