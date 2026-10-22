#ifndef DAFTAR_TEMUAN_H
#define DAFTAR_TEMUAN_H

/* DAFTAR TEMUAN */
/* DEFINISI TYPE */
#define CAPACITY 100

typedef struct {
    int contents[CAPACITY];
    int nEff;
} List;

/* DEFINISI DAN SPESIFIKASI */
void cetakTemuan(List l, int startIdx);
/* Mencetak elemen list secara rekursif mulai startIdx.
   I.S. 0 <= l.nEff <= CAPACITY dan 0 <= startIdx <= l.nEff.
        contents[0] sampai contents[l.nEff-1] berisi bilangan -1000 sampai 1000.
   F.S. Elemen contents[startIdx] sampai contents[l.nEff-1] tercetak berurutan,
        masing-masing diakhiri satu newline.
        Jika startIdx == l.nEff, tidak ada keluaran. */

#endif