#ifndef LISTREC_H
#define LISTREC_H

#include "boolean.h"
#include <stdio.h>

/* LIST REKURSIF (representasi berkait dengan pointer) */
/* Definisi rekursif list:
   Basis    : list kosong adalah list
   Rekurens : list tidak kosong terdiri atas sebuah elemen dan sisanya adalah list */

#define NIL NULL

typedef int ElType;
typedef struct node* Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

/* Definisi list: */
/* List kosong: l = NIL */
typedef Address List;

/* Selektor */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

/* Manajemen Memori */
Address newNode(ElType x);
/* Mengirimkan address hasil alokasi sebuah elemen.
   Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL.
   Jika alokasi gagal, mengirimkan NIL. */

void dealokasi(Address p);
/* I.S. p terdefinisi (hasil alokasi)
   F.S. p dikembalikan ke sistem (di-free) */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l);
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isOneElmt(List l);
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l);
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l);
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(ElType e, List l);
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya.
   e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan l */
List konsdot(List l, ElType e);
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhir.
   e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan l */

/* Fungsi dan Prosedur Lain */
void displayList(List l);
/* I.S. l terdefinisi, mungkin kosong
   F.S. Isi list tercetak dalam format [a,b,c] diikuti newline.
        List kosong tercetak sebagai [] */
void dealokasiList(List *l);
/* I.S. l terdefinisi, mungkin kosong
   F.S. Seluruh node didealokasi, l menjadi list kosong (NIL) */

#endif
