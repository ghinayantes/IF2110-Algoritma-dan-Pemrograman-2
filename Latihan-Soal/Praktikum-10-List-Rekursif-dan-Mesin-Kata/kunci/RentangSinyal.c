#include "RentangSinyal.h"

static List bacaSisa(void) {
    if (endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSisa());
}

static void extremes(List l, int *mn, int *mx) {
    if (isOneElement(l)) {
        *mn = head(l);
        *mx = head(l);
    } else {
        int mn1, mx1;
        extremes(tail(l), &mn1, &mx1);
        *mn = (head(l) < mn1) ? head(l) : mn1;
        *mx = (head(l) > mx1) ? head(l) : mx1;
    }
}

void rentangSinyal(int *min, int *max) {
    startWord();
    List l = bacaSisa();
    extremes(l, min, max);
    deleteAll(&l);
}
