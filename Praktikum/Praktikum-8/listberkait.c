#include <stdlib.h>
#include "listberkait.h"

Address newNode(ElType val) {
    Address p = malloc(sizeof(Node));
    if (p != Nil) {
        INFO(p) = val;
        NEXT(p) = Nil;
    }
    return p;
}