#include "lowerbound.h"

List lowerBound(List l, int k) {
    if (isEmpty(l)) {
        return NIL;
    }
    List hasil = lowerBound(NEXT(l), k);
    if (INFO(l) > k) {
        Address p = newNode(INFO(l));
        if (p != NIL) {
            NEXT(p) = hasil;
            hasil = p;
        }
    }
    return hasil;
}
