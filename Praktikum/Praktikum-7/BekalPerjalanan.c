#include <stdio.h>
#include "BekalPerjalanan.h"

void tambahBekal(List l, int startIdx, int *saldo) {
    if (startIdx == l.nEff) return;
    *saldo += l.contents[startIdx];
    tambahBekal(l, startIdx+1, saldo);
}
/* Menambahkan nilai koin ke saldo secara rekursif.
   I.S. 0 <= l.nEff <= CAPACITY dan 0 <= startIdx <= l.nEff.
        contents[0] sampai contents[l.nEff-1] berisi bilangan 0 sampai 1000.
        saldo menunjuk variabel int yang valid dan telah berisi saldo tidak negatif.
        Hasil penjumlahan tetap berada dalam rentang int.
   F.S. *saldo berisi saldo awal ditambah jumlah elemen contents[startIdx]
        sampai contents[l.nEff-1].
        Jika startIdx == l.nEff, saldo tidak berubah. Tidak mencetak keluaran. */