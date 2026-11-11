#ifndef LISTREC_H
#define LISTREC_H

#include <stdbool.h>
#include <stddef.h>

/* LIST BERKAIT REKURSIF */
/* DEFINISI TYPE */
#define NIL NULL

typedef int ElType;
typedef struct node *Address;
typedef struct node {
    ElType info;
    Address next;
} Node;
typedef Address List;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType value);
/* Mengembalikan alamat node baru berisi info value dan next NIL.
   Mengembalikan NIL jika alokasi gagal. */

bool isEmpty(List l);
/* Mengembalikan true jika list kosong. */

void insertLast(List *l, ElType value);
/* I.S. l menunjuk List valid, mungkin kosong.
   F.S. Node baru berisi value menjadi elemen terakhir.
        Jika alokasi gagal, list tidak berubah. */

void displayList(List l);
/* I.S. l terdefinisi, mungkin kosong.
   F.S. Isi list tercetak dalam format [a,b,c] diikuti newline.
        List kosong tercetak sebagai []. */

void dealokasiList(List *l);
/* I.S. l menunjuk List valid, mungkin kosong.
   F.S. Seluruh node didealokasi, *l menjadi list kosong. */

#endif
