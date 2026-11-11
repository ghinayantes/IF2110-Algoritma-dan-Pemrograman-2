#include "DiAtasRataRata.h"

static List bacaSisa(void) {
    if (endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSisa());
}

static int panjang(List l) {
    if (isEmpty(l)) return 0;
    return 1 + panjang(tail(l));
}

static int jumlah(List l) {
    if (isEmpty(l)) return 0;
    return head(l) + jumlah(tail(l));
}

/* x > total/n  <=>  x*n > total  (n > 0) */
static int hitung(List l, int n, int total) {
    if (isEmpty(l)) return 0;
    return ((head(l) * n > total) ? 1 : 0) + hitung(tail(l), n, total);
}

int banyakDiAtasRataRata(void) {
    startWord();
    List l = bacaSisa();
    int hasil = hitung(l, panjang(l), jumlah(l));
    deleteAll(&l);
    return hasil;
}
