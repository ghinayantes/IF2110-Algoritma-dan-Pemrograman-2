#include <stdio.h>
#include "listrec.h"

int nodeAktif = 0; /* untuk pemeriksaan kebocoran oleh pengujian */

Address newNode(ElType x) {
    Address p = (Address)malloc(sizeof(Node));
    INFO(p) = x;
    NEXT(p) = NIL;
    nodeAktif++;
    return p;
}

void dealokasi(Address p) {
    nodeAktif--;
    free(p);
}

bool isEmpty(List l) { return l == NIL; }

bool isOneElement(List l) { return l != NIL && NEXT(l) == NIL; }

ElType head(List l) { return INFO(l); }

List tail(List l) { return NEXT(l); }

List makeCons(ElType e, List l) {
    Address p = newNode(e);
    NEXT(p) = l;
    return p;
}

List addLast(List l, ElType e) {
    if (isEmpty(l)) return makeCons(e, NIL);
    return makeCons(head(l), addLast(tail(l), e));
}

void insertLast(List *l, ElType e) {
    if (isEmpty(*l)) *l = newNode(e);
    else insertLast(&NEXT(*l), e);
}

List copy(List l) {
    if (isEmpty(l)) return NIL;
    return makeCons(head(l), copy(tail(l)));
}

void copyList(List l, List *l2) {
    *l2 = copy(l);
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) return copy(l2);
    return makeCons(head(l1), concat(tail(l1), l2));
}

void concatList(List l1, List l2, List *l3) {
    *l3 = concat(l1, l2);
}

static void tampil(List l) {
    if (!isEmpty(l)) {
        printf("%d", head(l));
        if (!isEmpty(tail(l))) printf(",");
        tampil(tail(l));
    }
}

void displayList(List l) {
    printf("[");
    tampil(l);
    printf("]\n");
}

void deleteAll(List *l) {
    if (!isEmpty(*l)) {
        deleteAll(&NEXT(*l));
        dealokasi(*l);
        *l = NIL;
    }
}
