#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType value) {
    Address p = malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = value;
        NEXT(p) = NIL;
    }
    return p;
}

bool isEmpty(List l) {
    return l == NIL;
}

void insertLast(List *l, ElType value) {
    Address p = newNode(value);
    if (p == NIL) {
        return;
    }
    if (isEmpty(*l)) {
        *l = p;
    } else {
        Address last = *l;
        while (NEXT(last) != NIL) {
            last = NEXT(last);
        }
        NEXT(last) = p;
    }
}

void displayList(List l) {
    putchar('[');
    for (Address p = l; p != NIL; p = NEXT(p)) {
        if (p != l) {
            putchar(',');
        }
        printf("%d", INFO(p));
    }
    puts("]");
}

void dealokasiList(List *l) {
    while (*l != NIL) {
        Address p = *l;
        *l = NEXT(p);
        free(p);
    }
}
