#ifndef LISTREC_H
#define LISTREC_H

#include <stdbool.h>
#include <stdlib.h>

/* LIST REKURSIF (representasi implisit) */
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

/* Manajemen Memori: memori dianggap selalu cukup */
Address newNode(ElType x);
/* Mengembalikan address node baru dengan INFO = x dan NEXT = NIL. */

void dealokasi(Address p);
/* I.S. p hasil newNode. F.S. p dikembalikan ke sistem. */

/* Pemeriksaan Kondisi List */
bool isEmpty(List l);
bool isOneElement(List l);

/* Selektor dan Konstruktor */
ElType head(List l);
/* l tidak kosong. */
List tail(List l);
/* l tidak kosong; hasil mungkin list kosong. */
List makeCons(ElType e, List l);
/* Mengembalikan list l dengan e sebagai elemen pertama (1 simpul baru). */

/* Primitif lain */
List addLast(List l, ElType e);
void insertLast(List *l, ElType e);
List copy(List l);
void copyList(List l, List *l2);
List concat(List l1, List l2);
void concatList(List l1, List l2, List *l3);

void displayList(List l);
/* Mencetak isi list dalam format [a,b,c] diikuti newline; kosong: [] */

void deleteAll(List *l);
/* I.S. l terdefinisi. F.S. l = NIL dan semua node didealokasi. */

#endif
