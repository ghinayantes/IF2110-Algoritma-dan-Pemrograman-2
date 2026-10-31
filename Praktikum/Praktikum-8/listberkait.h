#ifndef LISTBERKAIT_H
#define LISTBERKAIT_H

#include <stddef.h>

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

#endif