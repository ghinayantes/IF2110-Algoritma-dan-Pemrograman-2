/* Driver pengujian: gcc -DP=<nomor> test.c <Soal>.c listrec.c mesinkata.c mesinkarakter.c */
#include <stdio.h>
#include "listrec.h"
#include "mesinkata.h"

extern int nodeAktif;

#if P == 1
#include "SalinanPita.h"
#elif P == 2
#include "BalikPita.h"
#elif P == 3
#include "PosisiApi.h"
#elif P == 4
#include "RentangSinyal.h"
#elif P == 5
#include "DiAtasRataRata.h"
#elif P == 6
#include "KataSeukuran.h"
#elif P == 7
#include "DuaCatatanSama.h"
#elif P == 8
#include "JumlahSinyal.h"
#elif P == 9
#include "BersihkanKembar.h"
#elif P == 10
#include "DaftarUnik.h"
#endif

int main(void) {
#if P == 1
    List l = bacaPita();
#elif P == 2
    List l = bacaTerbalik();
#elif P == 3
    List l = posisiApi();
#elif P == 8
    List l = jumlahDuaCatatan();
#elif P == 9
    List l = bersihkanKembar();
#elif P == 10
    List l = daftarUnik();
#endif
#if P == 1 || P == 2 || P == 3 || P == 8 || P == 9 || P == 10
    displayList(l);
    deleteAll(&l);
#elif P == 4
    int mn, mx;
    rentangSinyal(&mn, &mx);
    printf("%d %d\n", mn, mx);
#elif P == 5
    printf("%d\n", banyakDiAtasRataRata());
#elif P == 6
    printf("%s\n", adaKataSeukuran() ? "YA" : "TIDAK");
#elif P == 7
    printf("%s\n", duaCatatanSama() ? "SAMA" : "BEDA");
#endif
    if (nodeAktif != 0) fprintf(stderr, "LEAK: %d\n", nodeAktif);
    return 0;
}
