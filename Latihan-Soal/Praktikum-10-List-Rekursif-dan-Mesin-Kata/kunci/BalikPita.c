#include "BalikPita.h"

static List bacaAcc(List acc) {
    if (endWord) return acc;
    int x = kataKeInt(currentWord);
    advWord();
    return bacaAcc(makeCons(x, acc));
}

List bacaTerbalik(void) {
    startWord();
    return bacaAcc(NIL);
}
