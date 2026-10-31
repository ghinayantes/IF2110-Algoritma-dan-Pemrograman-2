#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

/* MESIN KARAKTER */
/* Pita karakter dibaca dari masukan standar dan diakhiri karakter MARK. */
#define MARK '.'

/* State Mesin Karakter */
extern char currentChar;

void START(void);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama pada pita posisinya adalah pada currentChar.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita.
          Jika currentChar == MARK maka EOP bernilai true,
          selain itu EOP bernilai false. */

void ADV(void);
/* Pita dimajukan satu karakter.
   I.S. : currentChar bukan MARK (EOP false)
   F.S. : currentChar adalah karakter berikutnya pada pita.
          Jika currentChar == MARK maka EOP bernilai true,
          selain itu EOP bernilai false.
          Jika masukan habis sebelum MARK, currentChar dianggap MARK. */

int EOP(void);
/* Menghasilkan 1 jika currentChar == MARK, 0 jika tidak */

#endif