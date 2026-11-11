#!/bin/bash
# Mengompilasi kunci tiap soal dan menjalankan kasus uji. Pemakaian: ./uji.sh
cd "$(dirname "$0")"
NAMA=(x SalinanPita BalikPita PosisiApi RentangSinyal DiAtasRataRata KataSeukuran DuaCatatanSama JumlahSinyal BersihkanKembar DaftarUnik)
gagal=0
cek() { # nomor masukan keluaran_diharapkan
  local out
  out=$(printf '%s' "$2" | ./bin/t$1 2>&1)
  if [ "$out" == "$3" ]; then echo "ok   [$1] '$2' -> $out"; else echo "FAIL [$1] '$2' -> '$out' (harap '$3')"; gagal=1; fi
}
mkdir -p bin
for i in 1 2 3 4 5 6 7 8 9 10; do
  n=${NAMA[$i]}
  if grep -nE '\b(for|while|do)\b' kunci/$n.c >/dev/null; then echo "LOOP terdeteksi di $n.c"; gagal=1; fi
  gcc -Wall -Wextra -g -fsanitize=address,undefined -DP=$i -I. test.c kunci/$n.c listrec.c mesinkata.c mesinkarakter.c -o bin/t$i || exit 1
done
cek 1 "." "[]"
cek 1 "   ." "[]"
cek 1 "8 9 2 7 10." "[8,9,2,7,10]"
cek 1 "  -5   0  1000  -1000 ." "[-5,0,1000,-1000]"
cek 2 "." "[]"
cek 2 "1 2 3." "[3,2,1]"
cek 2 "  7 ." "[7]"
cek 3 "." "[]"
cek 3 "API." "[1]"
cek 3 "BUKA API TUTUP api API API2 API." "[2,5,7]"
cek 3 "KUNCI PETA." "[]"
cek 4 "5." "5 5"
cek 4 "3 -2 8 8 0." "-2 8"
cek 4 " -7 -3 -9 ." "-9 -3"
cek 5 "." "0"
cek 5 "4." "0"
cek 5 "2 4 6 8 ." "2"
cek 5 "5 5 5 5." "0"
cek 5 "-3 -1 -2 10." "1"
cek 5 "1 2." "1"
cek 6 "." "TIDAK"
cek 6 "AB." "TIDAK"
cek 6 "AB CD." "YA"
cek 6 "ITB ADA DI SINI AJA." "YA"
cek 6 "SATU DUA TIGA EMPAT LIMA." "TIDAK"
cek 6 "AAA BB CCC DDDD EE." "TIDAK"
cek 7 "SEKAT." "SAMA"
cek 7 "SEKAT 1." "BEDA"
cek 7 "1 SEKAT." "BEDA"
cek 7 "1 2 3 SEKAT 1 2 3." "SAMA"
cek 7 "1 2 3 SEKAT 1 3 2." "BEDA"
cek 7 "1 2 SEKAT 1 2 3." "BEDA"
cek 7 "  4  SEKAT  4 ." "SAMA"
cek 8 "SEKAT." "[]"
cek 8 "1 2 3 SEKAT 10 20 30." "[11,22,33]"
cek 8 "-5 SEKAT 5." "[0]"
cek 9 "." "[]"
cek 9 "1 1 2 2 2 1." "[1,2,1]"
cek 9 "3 3 3 3." "[3]"
cek 9 "1 2 3." "[1,2,3]"
cek 9 "5 5 6 5 5." "[5,6,5]"
cek 10 "." "[]"
cek 10 "5 3 5 1 3 9." "[1,3,5,9]"
cek 10 "-2 -2 -2." "[-2]"
cek 10 "1 2 3." "[1,2,3]"
cek 10 "3 2 1." "[1,2,3]"
exit $gagal
