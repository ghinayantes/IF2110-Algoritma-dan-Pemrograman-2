#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != Nil) {
        INFO(p) = val;
        NEXT(p) = Nil;
    }
    return p;
}

void CreateList(List *l) {
    *l = Nil;
}

bool isEmpty(List l) {
    return l == Nil;
}

Address lepasTerakhir(List *l) {
    if (*l == Nil) {
        return Nil;
    }
    Address terakhir = *l;
    Address sebelum = Nil;
    while (NEXT(terakhir) != Nil) {
        sebelum = terakhir;
        terakhir = NEXT(terakhir);
    }
    if (sebelum == Nil) {
        *l = Nil;
    } else {
        NEXT(sebelum) = Nil;
    }
    return terakhir;
}

void insertLast(List *l, ElType val) {
    Address p = newNode(val);
    if (p == Nil) {
        return;
    }
    if (isEmpty(*l)) {
        *l = p;
    } else {
        Address last = *l;
        while (NEXT(last) != Nil) {
            last = NEXT(last);
        }
        NEXT(last) = p;
    }
}

void displayList(List l) {
    printf("[");
    Address p = l;
    while (p != Nil) {
        printf("%d", INFO(p));
        if (NEXT(p) != Nil) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]\n");
}

void dealokasiList(List *l) {
    Address p = *l;
    while (p != Nil) {
        Address next = NEXT(p);
        free(p);
        p = next;
    }
    *l = Nil;
}