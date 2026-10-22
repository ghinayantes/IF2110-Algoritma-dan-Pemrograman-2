#include <stdio.h>
#include "DaftarTemuan.h"

void cetakTemuan(List l, int startIdx) {
    if (startIdx > l.nEff-1) return;
    printf("%d\n", l.contents[startIdx]);
    cetakTemuan(l, startIdx+1);
}
/* Mencetak elemen list secara rekursif mulai startIdx.
   I.S. 0 <= l.nEff <= CAPACITY dan 0 <= startIdx <= l.nEff.
        contents[0] sampai contents[l.nEff-1] berisi bilangan -1000 sampai 1000.
   F.S. Elemen contents[startIdx] sampai contents[l.nEff-1] tercetak berurutan,
        masing-masing diakhiri satu newline.
        Jika startIdx == l.nEff, tidak ada keluaran. */