#ifndef BEKAL_PERJALANAN_H
#define BEKAL_PERJALANAN_H

/* BEKAL PERJALANAN */
/* DEFINISI TYPE */
#define CAPACITY 100

typedef struct {
    int contents[CAPACITY];
    int nEff;
} List;

/* DEFINISI DAN SPESIFIKASI */
void tambahBekal(List l, int startIdx, int *saldo);
/* Menambahkan nilai koin ke saldo secara rekursif.
   I.S. 0 <= l.nEff <= CAPACITY dan 0 <= startIdx <= l.nEff.
        contents[0] sampai contents[l.nEff-1] berisi bilangan 0 sampai 1000.
        saldo menunjuk variabel int yang valid dan telah berisi saldo tidak negatif.
        Hasil penjumlahan tetap berada dalam rentang int.
   F.S. *saldo berisi saldo awal ditambah jumlah elemen contents[startIdx]
        sampai contents[l.nEff-1].
        Jika startIdx == l.nEff, saldo tidak berubah. Tidak mencetak keluaran. */

#endif