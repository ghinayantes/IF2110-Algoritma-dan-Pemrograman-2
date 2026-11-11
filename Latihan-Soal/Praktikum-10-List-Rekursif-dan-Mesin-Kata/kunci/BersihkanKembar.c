#include "BersihkanKembar.h"

static List bacaSisa(void) {
    if (endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSisa());
}

static void bersihkan(List l) {
    if (!isEmpty(l)) {
        bersihkan(NEXT(l));
        if (NEXT(l) != NIL && INFO(l) == INFO(NEXT(l))) {
            Address p = NEXT(l);
            NEXT(l) = NEXT(p);
            dealokasi(p);
        }
    }
}

List bersihkanKembar(void) {
    startWord();
    List l = bacaSisa();
    bersihkan(l);
    return l;
}
