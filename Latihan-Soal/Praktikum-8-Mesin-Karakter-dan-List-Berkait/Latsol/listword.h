/* File : listword.h */
/* Linked list dengan elemen bertype Word (dari mesinkata.h). Header-only. */
/* Dipakai bersama mesinkata.h dan mesinkarakter.h. Tidak perlu file .c tambahan. */

#ifndef LISTWORD_H
#define LISTWORD_H

#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

typedef struct wnode *WAddress;
typedef struct wnode {
    Word info;
    int cnt;        /* penghitung bebas pakai (nilai awal 1) */
    WAddress next;
} WNode;
typedef WAddress WList;

#define WINFO(p) (p)->info
#define WCNT(p)  (p)->cnt
#define WNEXT(p) (p)->next
#define WFIRST(l) (l)

/* List kosong: WFIRST(l) = NULL. Elemen terakhir: WNEXT(Last) = NULL */

static inline WAddress newWNode(Word w) {
    /* Mengembalikan node baru berisi w (cnt = 1, next = NULL), NULL jika alokasi gagal */
    WAddress p = (WAddress) malloc(sizeof(WNode));
    if (p != NULL) {
        WINFO(p) = w;
        WCNT(p) = 1;
        WNEXT(p) = NULL;
    }
    return p;
}

static inline void CreateWList(WList *l) {
    /* I.S. sembarang; F.S. terbentuk list kosong */
    *l = NULL;
}

static inline boolean isWEmpty(WList l) {
    return (l == NULL);
}

static inline void insertFirstW(WList *l, Word w) {
    /* Menambahkan w sebagai elemen pertama */
    WAddress p = newWNode(w);
    if (p != NULL) {
        WNEXT(p) = *l;
        *l = p;
    }
}

static inline void insertLastW(WList *l, Word w) {
    /* Menambahkan w sebagai elemen terakhir */
    WAddress p = newWNode(w);
    WAddress last;
    if (p != NULL) {
        if (*l == NULL) {
            *l = p;
        } else {
            last = *l;
            while (WNEXT(last) != NULL) {
                last = WNEXT(last);
            }
            WNEXT(last) = p;
        }
    }
}

static inline void printWord(Word w) {
    /* Mencetak karakter-karakter w tanpa spasi/newline tambahan */
    int i;
    for (i = 0; i < w.Length; i++) {
        putchar(w.TabWord[i]);
    }
}

static inline boolean isWordEqual(Word a, Word b) {
    /* Bernilai true jika a dan b sama persis (panjang dan isi, case-sensitive) */
    int i;
    if (a.Length != b.Length) {
        return false;
    }
    for (i = 0; i < a.Length; i++) {
        if (a.TabWord[i] != b.TabWord[i]) {
            return false;
        }
    }
    return true;
}

#endif
