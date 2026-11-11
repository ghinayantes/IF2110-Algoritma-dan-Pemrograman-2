#include "JumlahSinyal.h"

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

static void listPlus(List l1, List l2, List *l3) {
    if (isEmpty(l1)) {
        *l3 = NIL;
    } else {
        List temp;
        listPlus(tail(l1), tail(l2), &temp);
        *l3 = makeCons(head(l1) + head(l2), temp);
    }
}

List jumlahDuaCatatan(void) {
    startWord();
    List a = bacaSampaiSekat(buatKata("SEKAT"));
    advWord();
    List b = bacaSisa();
    List c;
    listPlus(a, b, &c);
    deleteAll(&a);
    deleteAll(&b);
    return c;
}
