#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Address newNode(ElType x) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

void dealokasi(Address p) {
    free(p);
}

boolean isEmpty(List l) {
    return l == NIL;
}

boolean isOneElmt(List l) {
    return !isEmpty(l) && isEmpty(NEXT(l));
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(ElType e, List l) {
    Address p = newNode(e);
    if (p == NIL) {
        return l;
    }
    NEXT(p) = l;
    return p;
}

List konsdot(List l, ElType e) {
    if (isEmpty(l)) {
        Address p = newNode(e);
        return (p == NIL) ? l : p;
    }
    NEXT(l) = konsdot(tail(l), e);
    return l;
}

void displayList(List l) {
    printf("[");
    Address p = l;
    while (p != NIL) {
        printf("%d", INFO(p));
        if (NEXT(p) != NIL) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]\n");
}

void dealokasiList(List *l) {
    if (!isEmpty(*l)) {
        dealokasiList(&NEXT(*l));
        dealokasi(*l);
        *l = NIL;
    }
}
