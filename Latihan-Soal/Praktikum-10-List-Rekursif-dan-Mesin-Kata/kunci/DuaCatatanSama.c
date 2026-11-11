#include "DuaCatatanSama.h"

static List bacaSampaiSekat(Word sekat) {
    if (isWordEqual(currentWord, sekat)) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSampaiSekat(sekat));
}

static List bacaSisa(void) {
    if (endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSisa());
}

static int isEqual(List l1, List l2) {
    if (isEmpty(l1) && isEmpty(l2)) return 1;
    if (isEmpty(l1) || isEmpty(l2)) return 0;
    return (head(l1) == head(l2)) && isEqual(tail(l1), tail(l2));
}

int duaCatatanSama(void) {
    startWord();
    List a = bacaSampaiSekat(buatKata("SEKAT"));
    advWord();
    List b = bacaSisa();
    int hasil = isEqual(a, b);
    deleteAll(&a);
    deleteAll(&b);
    return hasil;
}
