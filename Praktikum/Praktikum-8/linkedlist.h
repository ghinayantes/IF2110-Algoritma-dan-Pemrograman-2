#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

/* LIST BERKAIT */
/* DEFINISI TYPE */
#define Nil NULL

typedef int ElType;
typedef struct node *Address;
typedef struct node {
    ElType info;
    Address next;
} Node;
typedef Address List;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);
/* Mengembalikan alamat node baru berisi info val dan next Nil.
   Mengembalikan Nil jika alokasi gagal. */

void CreateList(List *l);
/* I.S. sembarang
   F.S. Terbentuk list kosong. */

bool isEmpty(List l);
/* Mengembalikan true jika list kosong. */

Address lepasTerakhir(List *l);
/* Melepas node terakhir dari list dan mengembalikan alamatnya.
   I.S. l menunjuk List valid, mungkin kosong.
   F.S. Node terakhir dilepas dari *l dan NEXT-nya menjadi Nil.
        Jika list kosong, menghasilkan Nil dan list tetap kosong.
        Tidak ada node yang dialokasikan atau didealokasi; INFO tidak diubah. */

void insertLast(List *l, ElType val);
/* I.S. l terdefinisi, mungkin kosong
   F.S. Node baru berisi val menjadi elemen terakhir.
        Jika alokasi gagal, list tidak berubah. */

void displayList(List l);
/* I.S. l terdefinisi, mungkin kosong
   F.S. Isi list tercetak dalam format [a,b,c] diikuti newline.
        List kosong tercetak sebagai []. */

void dealokasiList(List *l);
/* I.S. l terdefinisi, mungkin kosong
   F.S. Seluruh node didealokasi, l menjadi list kosong. */

#endif