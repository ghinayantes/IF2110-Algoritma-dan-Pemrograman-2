#include "PosisiApi.h"

static List cari(int pos, Word target) {
    if (endWord) return NIL;
    bool sama = isWordEqual(currentWord, target);
    advWord();
    if (sama) return makeCons(pos, cari(pos + 1, target));
    return cari(pos + 1, target);
}

List posisiApi(void) {
    startWord();
    return cari(1, buatKata("API"));
}
