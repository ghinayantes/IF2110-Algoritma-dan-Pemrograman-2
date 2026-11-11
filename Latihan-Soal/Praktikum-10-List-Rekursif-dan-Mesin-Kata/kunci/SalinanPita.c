#include "SalinanPita.h"

static List bacaSisa(void) {
    if (endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSisa());
}

List bacaPita(void) {
    startWord();
    return bacaSisa();
}
