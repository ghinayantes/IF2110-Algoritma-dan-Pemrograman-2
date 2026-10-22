# Catatan IF2110 — Bagian Prosedural (Diktat Struktur Data)

Oct 19, 2026 · @nayaneysaghinasahla

## Peta materi: slide vs diktat

Sumber: Diktat Struktur Data, Inggriani Liem, edisi 2008 (205 halaman, file lengkap). Gambar dan diagram di diktat tidak ikut terbawa di file teks, jadi catatan ini disusun dari teksnya saja.

| Topik di slide (Prosedural) | Bagian diktat | Halaman | Bagian catatan |
| --- | --- | --- | --- |
| Review Pemrograman Prosedural | Tidak ada bab khusus. Paling dekat: ADT dalam konteks prosedural | 7–17 | 1 |
| Review ADT List | Koleksi Objek, List Linier, Representasi Fisik, Variasi Representasi | 18–21, 62–101 | 2–5, 7 |
| Analisis Rekurens | Studi Rekursif Dalam Konteks Prosedural: Fungsi Faktorial | 102–104 | 8 |
| List Rekursif | Pemrosesan List Linier secara Prosedural dan Rekursif | 105–108 | 8 |
| Pohon | Pohon: istilah, pohon biner, pohon seimbang, BST, membentuk pohon dari pita karakter | 109–127 | 9 |
| Mesin Abstrak | Tidak ada bab khusus. Mesin karakter (`START`, `ADV`, `CC`, `EOP`) hanya dipakai, tidak dijelaskan | 123–127, 156 | 9, 10 |
| Graf | Tidak ada bab khusus. Dipakai di Studi Kasus 6 (Topological Sort) | 202–205 | 10 |
| Studi Kasus | Bagian II: enam studi kasus | 128–205 | 10 |

Diktat juga punya bab **Tabel, Matriks, Stack, dan Queue** (hlm. 22–61) yang ada di file, tapi tidak tercantum di daftar slide. Bab-bab itu tidak saya catat di sini.

Materi Mesin Abstrak dan Graf kemungkinan diambil dari bahan lain (misalnya diktat Algoritma & Pemrograman), karena di diktat ini keduanya hanya dipakai, tidak dibahas.

## 1. ADT dalam konteks prosedural (hlm. 7–17)

**ADT** (*Abstract Data Type*) = definisi sebuah **type** + sekumpulan **primitif** (operasi dasar) atas type itu. ADT yang lengkap juga menyertakan **invarian** (syarat yang selalu berlaku). Idenya sama dengan type bentukan di bagian fungsional; bedanya, di sini primitif ditulis sebagai **fungsi atau prosedur**, dan nilai komponen boleh diubah.

### Kelompok primitif

| Kelompok | Gunanya | Konvensi nama | Contoh di ADT JAM |
| --- | --- | --- | --- |
| Konstruktor | Membentuk nilai type | `Make...` | `MakeJam (HH, MM, SS)` |
| Selektor | Mengambil komponen | `Get...` | `GetHour (J)` |
| Pengubah komponen | Mengubah satu komponen | `Set...` | `SetHour (J, newHH)` |
| Validator | Mengecek apakah nilai bisa membentuk type yang sah | `IsValid...` | `IsJValid (H, M, S)` |
| Destruktor | Menghancurkan objek dan membebaskan memorinya | — | Tidak perlu untuk JAM |
| Baca/tulis | Masukan/keluaran | `Baca...`, `Tulis...` | `BacaJam`, `TulisJam` |
| Relasional | Perbandingan | `EQ`, `NEQ`, `LT`, `GT` | `JEQ`, `JLT` |
| Aritmatika | Operasi hitung atas type | bebas | `JPlus`, `NextDetik` |
| Konversi | Ke/dari type dasar | `...To...` | `JamToDetik`, `DetikToJam` |

Yang baru dibanding bagian fungsional: **Set** (mengubah nilai di tempat), **destruktor**, dan **baca/tulis**. Di dunia fungsional semua itu tidak ada karena nilai tidak pernah diubah.

### Fungsi vs prosedur

- **Fungsi**: ditulis dengan nama, domain, range, dan prekondisi (= prasyarat). Contoh: `function GetHour (J: JAM) → integer`.
- **Prosedur**: ditulis dengan **I.S.** (*Initial State*, keadaan awal), **F.S.** (*Final State*, keadaan akhir), dan prosesnya. Parameter diberi label `input`, `output`, atau `input/output`.

```
procedure SetHour (input/output J : JAM, input newHH : integer)
{ I.S. J terdefinisi }
{ F.S. komponen HH dari J bernilai newHH }
```

### Pembagian modul

ADT diimplementasi sebagai dua modul plus satu program uji:

| Bagian | Isi | Di bahasa C |
| --- | --- | --- |
| Spesifikasi | Type dan header semua primitif | file `.h` |
| Body | Realisasi primitif | file `.c` |
| **Driver** | Program utama khusus untuk menguji semua primitif | file `main` terpisah |

ADT berperan sebagai **supplier** (penyedia type dan primitif). Modul yang memakainya disebut **client**.

### Tiga contoh ADT

- **JAM** `⟨HH, MM, SS⟩`: contoh lengkap semua kelompok primitif. Catatan implementasi C: detik dalam sehari bisa melebihi batas `int`, jadi perlu `long`.
- **POINT** `⟨X, Y⟩`: ADT "standar" yang dipakai sampai pemrograman berorientasi objek. Ada operasi seperti `Kuadran` (prekondisi: bukan di sumbu), `Geser`, `Mirror`, `Putar`.
- **GARIS** `⟨PAw, PAkh⟩`: ADT yang **memakai ADT lain** (`USE POINT`). Punya invarian: titik awal ≠ titik akhir. Di C, `USE` menjadi `#include`, dan invarian diwujudkan sebagai fungsi validasi.

Perhatikan perbedaan bentuk: ada fungsi yang **menghasilkan salinan baru** (`MirrorOf (P, ...) → POINT`) dan prosedur yang **mengubah objek itu sendiri** (`Mirror (input/output P, ...)`). Versi pertama bergaya fungsional, versi kedua bergaya prosedural.

## 2. Koleksi objek (hlm. 18–21)

**Koleksi objek** = sekumpulan elemen bertype sama yang dikelola bersama, misalnya list, stack, queue, pohon, graf. Elemennya bisa nol (koleksi kosong) dan jumlahnya bisa bertambah atau berkurang.

Koleksi bisa didefinisikan dua cara:

- **Iteratif**: dengan menyebut setiap elemen satu per satu (cara bagian prosedural).
- **Rekursif**: koleksi bisa memuat koleksi itu sendiri (cara bagian fungsional). Pohon lebih alami didefinisikan secara rekursif.

**Koleksi generik** = koleksi yang type elemennya baru ditentukan saat dipakai (seperti `Element` di bagian fungsional). Bahasa Ada dan C++ mendukungnya; di C kode terpaksa diduplikasi.

### Tiga tingkat mendefinisikan koleksi

Ini ide terpenting bab ini. Satu struktur data dijelaskan bertahap dari yang paling abstrak ke yang paling dekat dengan mesin:

| Tingkat | Isinya | Contoh untuk list |
| --- | --- | --- |
| **Definisi fungsional** | Nama type dan operasinya saja, belum ada representasi | `Insert : ElmtList × L → L` |
| **Representasi lojik** | Spesifikasi type dan operasi sebagai fungsi/prosedur, memakai "alamat" abstrak | `First(L)`, `Next(P)`, `Info(P)` |
| **Representasi fisik** | Wujud di memori, sesuai bahasa yang dipakai | pointer `P↑.Next`, atau tabel `TabElmt[P].Next` |

Struktur yang baru punya definisi fungsional dan lojik (tanpa fisik) disebut **struktur data abstrak**. Analisis dan perancangan algoritma dilakukan di tingkat lojik; setelah itu tinggal diterjemahkan ke representasi fisik yang dipilih.

### Dua macam representasi fisik

|  | **Kontigu** | **Berkait** |
| --- | --- | --- |
| Penempatan di memori | Berurutan, bersebelahan | Boleh tersebar |
| Mencapai elemen berikutnya | Alamat sekarang + 1 | Lewat alamat yang disimpan di elemen |
| Alokasi memori | Sekaligus di awal (**statis**) | Saat dibutuhkan, bisa dikembalikan (**dinamis**) |
| Contoh wujud | Array/tabel | Pointer, atau tabel yang mensimulasikan pointer |

Satu representasi lojik bisa punya banyak representasi fisik. Pemilihan representasi fisik yang menentukan pemakaian memori dan kecepatan program.

## 3. List Linier: definisi, traversal, search (hlm. 62–66)

**List linier** = sekumpulan elemen bertype sama yang berurutan. Setiap elemen terdiri dari dua bagian: isi (**Info**) dan **alamat** elemen berikutnya (**Next**).

```
type ElmtList : < Info : InfoType, Next : address >
```

| Notasi | Artinya |
| --- | --- |
| `First(L)` | Alamat elemen pertama list L |
| `Info(P)` | Isi elemen yang beralamat P |
| `Next(P)` | Alamat elemen sesudah P (**suksesor**) |
| `Nil` | Alamat "kosong", tidak menunjuk ke mana pun |
| List kosong | `First(L) = Nil` |
| Elemen terakhir | Elemen P dengan `Next(P) = Nil` |

Gambarannya: `First → [5|•] → [7|•] → [3|Nil]`. Setiap kotak berisi Info dan panah Next.

Alamat yang sudah dipakai untuk sebuah elemen disebut sudah **dialokasi**.

### Traversal

**Traversal** = mengunjungi setiap elemen dari pertama sampai terakhir untuk diproses. Diktat memberi tiga skema:

```
SKEMAListTraversal1   { list boleh kosong, tanpa penanganan khusus }
  Inisialisasi
  P ← First(L)
  while (P ≠ Nil) do
    Proses(P)
    P ← Next(P)
  Terminasi
```

| Skema | Bentuk loop | Kapan dipakai |
| --- | --- | --- |
| Traversal1 | `while`, berhenti di **mark** `Nil` | List boleh kosong, kosong tidak perlu pesan khusus |
| Traversal2 | `if` kosong → pesan; selain itu `repeat ... until P = Nil` | List kosong perlu ditangani khusus |
| Traversal3 | `iterate ... stop (Next(P) = Nil)` | List pasti tidak kosong |

**Mark** di sini artinya penanda akhir, yaitu `Nil`.

### Sequential search

**Sequential search** = mencari elemen satu per satu dari depan.

```
SKEMAListSearch1 (input L, input X, output P, output Found)
  P ← First(L)
  Found ← false
  while (P ≠ Nil) and (not Found) do
    if (X = Info(P)) then Found ← true
    else P ← Next(P)
  { hasil: Found, dan P = alamat X atau Nil }
```

Variasi search di diktat:

- **Search nilai** (output alamat): versi dengan variabel boolean `Found` (Search1), atau versi yang memeriksa elemen terakhir secara khusus tanpa boolean (Search2).
- **Search alamat**: mengecek apakah alamat P termasuk elemen list (`SearchAdr`/`Search@`).
- **Search kondisi**: mencari elemen yang memenuhi `Kondisi(P)`. Contoh kondisi: `Info(P) = 5`; elemen terakhir `Next(P) = Nil`; elemen sebelum terakhir `Next(Next(P)) = Nil`.

**Petunjuk Latihan 4** (skema search yang "fatal"): skema itu langsung memakai `Next(P)` dan `Info(P)` tanpa mengecek list kosong. Kalau L kosong, P = Nil, dan `Next(Nil)` tidak terdefinisi.

## 4. Operasi primitif list: insert, delete, concat (hlm. 67–77)

Definisi fungsionalnya:

```
IsEmpty     : L → boolean
CreateEmpty : → L
Insert      : ElmtList × L → L
Delete      : L → L × ElmtList
Concat      : L1 × L2 → L
```

`IsEmpty (L)` cukup `First(L) = Nil`. `CreateEmpty (L)` cukup `First(L) ← Nil`.

### Diketahui alamat vs diketahui nilai

Setiap operasi punya dua versi. Ini perbedaan paling penting yang perlu dipahami.

|  | Versi alamat | Versi nilai (ada huruf **V**) |
| --- | --- | --- |
| Contoh | `InsertFirst (L, P)` | `InsVFirst (L, InfoE)` |
| Masukan | Elemen yang sudah dialokasi (alamat P) | Hanya nilainya |
| Yang dilakukan | Langsung menyambungkan P | **Alokasi** dulu, baru sambungkan; kalau alokasi gagal, list tidak berubah |
| Versi delete-nya | `DeleteFirst (L, P)`: alamat dikembalikan, tidak didealokasi | `DelVFirst (L, E)`: nilai dikembalikan, alamat **didealokasi** |

**Alokasi** = meminta memori untuk satu elemen baru. `Alokasi(X)` menghasilkan alamat P dengan `Info(P) = X` dan `Next(P) = Nil`, atau `Nil` kalau memori habis. **Dealokasi** = mengembalikan memori itu.

Kenapa ada dua versi? Versi alamat dipakai kalau elemen akan dipindah ke list lain (tidak perlu dealokasi lalu alokasi ulang). Versi nilai dipakai oleh pengguna yang hanya peduli isi, bukan alamat.

### Insert

| Prosedur | Algoritma inti | Catatan |
| --- | --- | --- |
| `InsertFirst (L, P)` | `Next(P) ← First(L)`; `First(L) ← P` | Tetap benar walau L kosong |
| `InsertAfter (P, Prec)` | `Next(P) ← Next(Prec)`; `Next(Prec) ← P` | Urutan dua baris tidak boleh dibalik |
| `InsertLast (L, P)` | Kalau kosong: `InsertFirst`. Kalau tidak: traversal sampai `Last`, lalu `InsertAfter (P, Last)` | Harus menelusuri seluruh list |

Kenapa urutan di `InsertAfter` penting? Kalau `Next(Prec) ← P` dikerjakan dulu, alamat sisa list setelah Prec hilang dan tidak bisa disambung lagi.

### Delete

| Prosedur | Algoritma inti | Prekondisi |
| --- | --- | --- |
| `DeleteFirst (L, P)` | `P ← First(L)`; `First(L) ← Next(First(L))`; `Next(P) ← Nil` | L tidak kosong |
| `DeleteAfter (Prec, P)` | `P ← Next(Prec)`; `Next(Prec) ← Next(Next(Prec))`; `Next(P) ← Nil` | `Next(Prec) ≠ Nil` |
| `DeleteP (L, P)` | Kalau P elemen pertama: `DeleteFirst`. Kalau tidak: cari **Prec** (elemen sebelum P), lalu `DeleteAfter` | P anggota L |
| `DeleteLast (L, P)` | Traversal sambil mencatat `Last` dan `PrecLast`. Kalau `PrecLast = Nil` (cuma satu elemen), list jadi kosong; kalau tidak, `Next(PrecLast) ← Nil` | L tidak kosong |

Pola umumnya: untuk menghapus sebuah elemen, kita harus tahu elemen **sebelumnya** (**predesesor**). Itulah sebabnya hapus elemen terakhir mahal, karena harus menelusuri dari depan.

### Concat

`CONCAT (L1, L2, L3)`: L3 adalah L1 disambung L2. Caranya: telusuri L1 sampai elemen terakhir (`Last1`), lalu `Next(Last1) ← First(L2)`. Kalau L1 kosong, `First(L3) ← First(L2)`.

Pertanyaan di diktat: "apakah kedua list asal tetap dapat dikenali?" Jawabannya tidak sepenuhnya. Elemen-elemennya tidak disalin, hanya disambung, jadi L1 dan L3 berbagi elemen yang sama. Setelah concat, L1 ikut "memanjang" sampai ke L2. Latihan 6 meminta versi yang **menyalin** elemen supaya list asal tetap utuh.

## 5. Representasi fisik list linier (hlm. 78–80)

Notasi lojik `First(L)`, `Next(P)`, `Info(P)` harus diterjemahkan ke sesuatu yang benar-benar ada di bahasa pemrograman. Representasi **berkait** bisa diwujudkan dengan **pointer** atau dengan **tabel**; representasi **kontigu** hanya dengan tabel.

### Berkait dengan pointer

```
type ElmtList : < Info : InfoType, Next : address >
type address  : pointer to ElmtList
type List     : < First : address >
```

| Notasi lojik | Menjadi |
| --- | --- |
| `First(L)` | `L.First` (atau `L` saja, kalau List didefinisikan langsung sebagai address) |
| `Next(P)` | `P↑.Next` |
| `Info(P)` | `P↑.Info` |

`P↑` dibaca "elemen yang ditunjuk P" (dereferensi). Di C, `P↑.Next` ditulis `P->Next`. Alokasi dan dealokasi dikerjakan oleh sistem (di C: `malloc` dan `free`).

### Berkait dengan tabel

Dipakai kalau bahasa tidak punya pointer. Kita membuat "memori" sendiri berupa satu tabel global, dan alamat = **indeks** tabel.

```
constant IndexMin : integer = 1
constant IndexMax : integer = 100
constant Nil      : integer = 0          { di luar rentang indeks }
type address : integer [IndexMin..IndexMax, Nil]
TabElmt    : array [IndexMin..IndexMax] of ElmtList
FirstAvail : address                     { elemen kosong pertama }
```

| Notasi lojik | Menjadi |
| --- | --- |
| `Next(P)` | `TabElmt[P].Next` |
| `Info(P)` | `TabElmt[P].Info` |

Karena tidak ada sistem yang mengurus memori, kita mengurusnya sendiri. Semua sel tabel yang belum terpakai dirangkai menjadi satu list cadangan, dengan kepala `FirstAvail` ("alamat pertama yang tersedia").

| Primitif | Algoritma | Gunanya |
| --- | --- | --- |
| `InitTab` | `Next(i) ← i + 1` untuk semua i, `Next(IndexMax) ← Nil`, `FirstAvail ← IndexMin` | Merangkai semua sel menjadi list cadangan |
| `MemFull` | `FirstAvail = Nil` | Cek apakah memori habis |
| `AllocTab (P)` | `P ← FirstAvail`; `FirstAvail ← Next(FirstAvail)` | Ambil sel dari depan list cadangan (= DeleteFirst) |
| `DeAllocTab (P)` | `Next(P) ← FirstAvail`; `FirstAvail ← P` | Kembalikan sel ke depan list cadangan (= InsertFirst) |

Perhatikan: alokasi dan dealokasi di sini sebenarnya hanya `DeleteFirst` dan `InsertFirst` atas list cadangan. Walau terlihat dinamis, ukuran tabel tetap ditentukan di awal, jadi pada dasarnya alokasinya **statis**.

Variasi representasi list (first-last, dummy, sirkuler, pointer ganda) dibahas di bagian 7.

## 6. Jembatan dari versi fungsional

Konsepnya sebagian besar sudah kamu kenal dari bagian fungsional; yang berubah adalah cara menulis dan cara berpikirnya.

| Bagian fungsional | Bagian prosedural | Bedanya |
| --- | --- | --- |
| `head (L)` | `Info(First(L))` | Prosedural memisahkan **alamat** dari **isi** |
| `tail (L)` | `Next(First(L))` (sebuah alamat, bukan list baru) | Sisa list hanyalah alamat elemen kedua |
| `isEmpty (L)` | `First(L) = Nil` | Sama |
| `makeNil` | `CreateEmpty (L)` | Prosedur, bukan fungsi |
| `makeCons (e, L)` | `InsVFirst (L, e)` | Prosedural **mengubah L itu sendiri**; fungsional membuat list baru |
| `addLast (L, e)` | `InsVLast (L, e)` | Sama-sama harus menelusuri sampai ujung |
| `length (L)` rekursif | Traversal dengan `while` dan penghitung | Rekursi diganti loop |
| `isMember (x, L)` | Sequential search dengan `Found` | Berhenti begitu ketemu, mirip `or else` |
| Nilai lama tetap ada (persistensi) | Nilai lama hilang setelah diubah | Konsekuensi mengubah di tempat |
| Tidak ada alokasi | Alokasi/dealokasi wajib dipikirkan | Memori bisa habis |

Dua kebiasaan baru yang paling penting:

1. **Selalu cek Nil sebelum memakai `Next(P)` atau `Info(P)`.** Ini padanan `and then` di bagian fungsional; bedanya, di sini tidak ada yang melindungimu kalau lupa.
2. **Perhatikan urutan assignment pointer.** Di fungsional urutan tidak penting (transparansi referensial). Di prosedural, menukar dua baris di `InsertAfter` bisa membuat sebagian list hilang.

## 7. Variasi representasi list linier (hlm. 92–101)

List linier biasa (First, elemen terakhir `Next = Nil`) punya beberapa kelemahan: menambah di akhir harus traversal, menghapus butuh predesesor, dan list kosong selalu butuh penanganan khusus. Setiap variasi di bawah menambal satu kelemahan dengan harga tertentu.

| Variasi | Ciri | List kosong | Kelebihan | Harga / catatan |
| --- | --- | --- | --- | --- |
| Dicatat **First dan Last** | Alamat elemen terakhir disimpan | `First(L) = Nil` | Insert di akhir tanpa traversal; cocok untuk **queue** (First = Head, Last = Tail) | Setiap operasi yang menyentuh elemen terakhir harus ikut memperbarui Last |
| Elemen terakhir **menunjuk diri sendiri** | `Next(Last) = Last` | `First(L) = Nil` | Traversal berhenti di elemen terakhir, tidak pernah berakhir dengan P = Nil | Kondisi berhenti loop berubah menjadi `Next(P) = P` |
| **Dummy di awal** | Elemen fiktif dialokasi saat CreateEmpty; elemen pertama asli = `Next(First(L))` | `First(L) = dummy` (tidak pernah Nil) | Tes list kosong bisa dihapus dari banyak algoritma | Perlu satu elemen ekstra |
| **Dummy di akhir** (sentinel) | Elemen terakhir asli menunjuk ke dummy | `First(L) = dummy` | Dummy bisa dipakai sebagai **sentinel** untuk search | Perlu satu elemen ekstra |
| Dummy di akhir **+ catat Last** | `Last(L) = dummy` | `First(L) = dummy = Last(L)` | Search dan insert digabung: nilai yang dicari ditaruh dulu di dummy; kalau tidak ketemu, dummy itu langsung jadi elemen baru dan dialokasi dummy baru | Dipakai di Topological Sort |
| **Dummy di awal dan akhir** | Ada dummyFirst dan dummyLast | Hanya dua dummy | Semua insert/delete menjadi operasi "After" (di tengah) | Dua elemen ekstra |
| **Sirkuler** | `Next(Last) = First`; tidak punya awal sejati, First hanya "penunjuk saat ini" | `First(L) = Nil` | Cocok untuk proses berputar terus, misalnya round robin di sistem operasi | Insert/delete di awal harus traversal untuk memperbarui `Next(Last)` |
| **Pointer ganda** (doubly linked) | Setiap elemen punya `Next` dan `Prev` | `First(L) = Nil` | Tidak perlu mencari predesesor | Memori lebih besar, operasi dasar lebih banyak |
| Pointer ganda **+ Last** | Tambah alamat elemen terakhir | `First = Last = Nil` | Bisa jalan maju dan mundur dari kedua ujung | Kalau kontigu, ini sama dengan representasi Queue |
| Pointer ganda **sirkuler** | `Next(Last) = First` dan `Prev(First) = Last` | `First(L) = Nil` | Kedua ujung terhubung | Paling banyak pointer yang harus dijaga |
| Info berupa **alamat** | Info elemen menyimpan alamat ke data lain | `First(L) = Nil` | Elemen bisa menunjuk type apa pun; kalau Info menunjuk list lain, terbentuk list of list atau S-expression | Type tidak lagi dijaga ketat |

**Sentinel** = elemen penjaga di ujung list. Caranya: taruh nilai yang dicari di sentinel, lalu cari tanpa perlu mengecek `P ≠ Nil` di setiap langkah, karena pencarian pasti berhenti paling lambat di sentinel.

Saran diktat untuk latihan: ambil algoritma list sederhana, lalu ubah secara sistematis sesuai representasi baru. Diktat menghitung ada 42 algoritma × 9 variasi list untuk dilatih.

## 8. Rekursif dalam konteks prosedural (hlm. 102–108)

Bab ini menerjemahkan fungsi rekursif dari bagian fungsional ke notasi prosedural. Konsep basis dan rekurens sama persis; yang baru adalah **prosedur rekursif** yang hasilnya dikirim lewat parameter `output`.

### Faktorial dalam berbagai bentuk

| Versi | Bentuk | Catatan |
| --- | --- | --- |
| Fungsi rekursif | `if N = 0 then → 1 else → N * factorial (N-1)` | Terjemahan langsung dari versi fungsional. Di file, basisnya tertulis `→ 0`; itu salah ketik, seharusnya 1 |
| Loop dengan pencacah | `F ← 1; Count ← 1; while Count ≤ N: F ← F * Count; Count ← Count + 1` | Rekursi diubah menjadi deret kali 1 × 2 × … × N. Di file tertulis `F * i`, maksudnya `F * Count` |
| Loop mengubah N | `while N > 0: F ← F * N; N ← N - 1` | Diktat menyebut "kurang baik" karena mengubah parameter input |
| Prosedur dengan **akumulator** | `factIter2 (N-1, Akumulator * N, F)`, dipanggil dengan akumulator 1 | "Iteratif dengan mekanisme rekursif". Sama dengan `fibFrom` di bagian fungsional. Di file, I.S. menulis akumulator = 0; seharusnya 1 |

### Tiga prosedur "salah, mengapa?"

Ini latihan penting tentang parameter `output` pada prosedur rekursif:

```
factorialSalah1 (N, F):  if N = 0 then F ← 1
                         else factorialSalah1 (N-1, F)
```

Hasil rekursi langsung jadi F, tapi tidak pernah dikalikan N. Jadi F selalu 1.

```
factorialSalah2 (N, F):  if N = 0 then F ← 1
                         else factorialSalah2 (N-1, Ftemp); F ← Ftemp
```

Sama masalahnya: hasil sementara disalin tanpa dikalikan N. F selalu 1.

```
factorialX (N, F):       if N = 0 then F ← 1
                         else factorialX (N-1, Ftemp); F ← Ftemp * N
```

Versi ini sebenarnya **benar**: (N-1)! dihitung ke Ftemp, lalu dikalikan N. Diktat memberinya label "salah, mengapa??" sebagai pancingan. Bandingkan dengan dua versi sebelumnya untuk melihat apa yang kurang di sana.

Polanya: dalam prosedur rekursif, simpan hasil panggilan rekursif ke **variabel lokal**, lalu olah variabel itu sebelum menulis ke parameter output.

### List linier sebagai struktur rekursif

List dipandang seperti di bagian fungsional: list kosong adalah list; list tidak kosong = satu elemen + sisa yang juga list. Di sini `L` adalah alamat elemen pertama, jadi `Next(L)` adalah "tail".

| Fungsi diktat | Padanan fungsional | Isi |
| --- | --- | --- |
| `FirstElmt (L)` | `head (L)` | `→ Info(L)` |
| `Tail (L)` | `tail (L)` | `→ Next(L)` |
| `Konso (L, e)` | `makeCons (e, L)` | Alokasi e, `Next(P) ← L`, kirim P (insert first) |
| `Kons (L, e)` | `addLast (L, e)` | Rekursif: `Next(L) ← Kons (Tail(L), e)` |
| `NBElmtList (L)` | `length (L)` | Basis 0 → 0; rekurens `1 + NBElmtList (Next(L))` |
| `Search (L, X)` | `isMember (X, L)` | Basis 0 → false; rekurens cek `Info(L) = X`, lalu `Search (Next(L), X)` |
| `Copy (L)` | (tidak ada; fungsional tak perlu menyalin) | `Konso (FirstElmt(L), Copy (Tail(L)))` |
| `Concat (L1, L2)` | `append (L1, L2)` | `Konso (FirstElmt(L1), Concat (Tail(L1), L2))`; hasilnya **salinan** |

Catatan:

- Ada tiga cara menulis `NBElmtList`: fungsi rekursif, prosedur dengan variabel lokal (`NBElmtList1 (Next(L), N1); N ← 1 + N1`), dan prosedur dengan akumulator (`NBElmtListAcc (L, 0, N)`).
- `Kons` mengubah `Next` elemen list yang sudah ada, jadi berbeda dengan `addLast` fungsional yang membangun list baru.
- Versi kedua `Concat` memakai `Head (L2)` dan `LastElmt (L2)`. Di sini **Head berarti list tanpa elemen terakhir**, arti lama yang diperingatkan di slide List (bagian fungsional). Jangan tertukar dengan `head` yang berarti elemen pertama.

## 9. Pohon (hlm. 109–127)

Isinya banyak yang sama dengan bab Pohon di bagian fungsional. Bedanya, di sini pohon diwakili **alamat akarnya**, pohon kosong = `Nil`, dan ada operasi yang mengubah pohon di tempat.

### Definisi dan istilah

**Pohon** = himpunan berhingga dan **tidak kosong**. Satu elemen menjadi **akar**; sisanya dibagi menjadi beberapa himpunan disjoint yang masing-masing juga pohon (**sub pohon**). Contoh: buku (judul = akar, bab = sub pohon, subbab = sub-sub pohon). **Hutan** = kumpulan pohon yang disjoint. Hutan + akar fiktif = pohon; pohon tanpa akar = hutan.

Cara menulis pohon: himpunan bersarang, graf (gambar), indentasi (seperti daftar isi), atau bentuk linier prefix `A (B (D, E, F), C (G, H (I)))`.

| Istilah diktat | Inggris | Arti |
| --- | --- | --- |
| Simpul | node | Elemen pohon |
| Cabang / jalan | edge / path | Garis penghubung simpul |
| Ayah | parent | Akar dari sebuah sub pohon |
| Anak | child | Sub pohon dari sebuah akar |
| Saudara | sibling | Simpul-simpul dengan ayah yang sama |
| Sepupu | — | Simpul pada tingkat yang sama |
| Derajat | degree | Banyaknya sub pohon sebuah simpul |
| Daun | leaf | Simpul berderajat 0 |
| Tingkat | level | Banyaknya simpul dari akar sampai simpul itu; akar = tingkat 1 |
| Tinggi / kedalaman | height / depth | Panjang jalan terpanjang dari akar ke daun |
| Lebar | breadth | Banyak simpul terbanyak pada satu tingkat |

Sifat pohon biner: kalau b = simpul berderajat 2, u = simpul berderajat 1, d = daun, maka selalu **b = d − 1**. Pohon n-aire direpresentasi dengan list of list.

### Pohon biner

Pohon biner **boleh kosong** (berbeda dengan pohon n-aire yang tidak boleh kosong). Kiri dan kanan punya arti, jadi pohon **condong kiri** dan **condong kanan** (*skewed tree*) dianggap berbeda.

```
type node    : < Info : infotype, Left : address, Right : address >
type BinTree : address
```

Primitif utama ADT pohon biner:

| Kelompok | Primitif |
| --- | --- |
| Selektor | `Akar (P)` / `GetAkar`, `Left (P)`, `Right (P)` |
| Konstruktor | `Tree (Akar, L, R) → BinTree` (fungsi), `MakeTree (Akar, L, R, P)` (prosedur); hasil Nil kalau alokasi gagal |
| Predikat | `IsTreeEmpty`, `IsOneElmt`, `IsUnerLeft` (hanya punya kiri), `IsUnerRight`, `IsBiner` (punya keduanya) |
| Traversal | `PreOrder`, `InOrder`, `PostOrder`, `PrintTree (P, h)` dengan indentasi |
| Lain-lain | `Search`, `nbElmt`, `nbDaun`, `Tinggi`, `Level`, `IsSkewLeft/Right`, `AddDaun`, `DelDaun`, `MakeListDaun`, `MakeListPreorder`, `MakeListLevel` |

```
procedure PreOrder (input P : BinTree)
  if (P = Nil) then { basis: tidak ada yang diproses }
  else
    Proses(P)
    PreOrder(Left(P))
    PreOrder(Right(P))

function Tinggi (R : BinTree) → integer
  if (R = Nil) then → 0
  else → 1 + max (Tinggi(Left(R)), Tinggi(Right(R)))
```

InOrder dan PostOrder sama, hanya letak `Proses(P)` yang berpindah. `NBDaun` memakai **basis-1** (pohon satu simpul → 1), sehingga prekondisinya pohon tidak kosong; rekurensnya punya tiga kasus (hanya kiri, hanya kanan, keduanya), persis seperti predikat `IsUnerLeft/IsUnerRight/IsBiner`.

### Pohon seimbang

Dua definisi: seimbang **tinggi** (beda tinggi kiri-kanan paling banyak 1) atau seimbang **banyak simpul** (beda banyak simpul kiri-kanan paling banyak 1). Diktat memberi algoritma untuk jenis kedua:

```
BuildBalancedTree (n):
  if n = 0 then → Nil
  else baca X, P ← Alokasi(X)
       nL ← n div 2;  nR ← n − nL − 1
       Left(P) ← BuildBalancedTree(nL);  Right(P) ← BuildBalancedTree(nR)
       → P
```

### Pohon biner terurut (BST)

Untuk setiap simpul P: semua nilai di sub pohon kiri < `Info(P)`, semua di sub pohon kanan > `Info(P)`. (Di file, baris kedua tertulis "subpohon kiri" lagi; seharusnya kanan.) Nilai kembar tidak disimpan dua kali; sebagai gantinya setiap simpul punya field **Count** = berapa kali nilai itu muncul.

- `InsSearchTree (X, P)`: kalau P kosong, buat simpul baru. Kalau X = akar, `Count + 1`. Kalau lebih kecil, sisipkan ke kiri; kalau lebih besar, ke kanan. Simpul baru selalu menjadi daun.
- `DelBTree (P, X)`: cari simpulnya. Kalau simpul itu daun, cukup dihapus. Kalau hanya punya satu anak, simpul diganti anaknya. Kalau punya dua anak, nilainya diganti dengan **nilai terbesar di sub pohon kiri** (daun terkanan dari anak kiri, dicari oleh `DelNode`), lalu simpul daun itu yang dihapus. (Di file, kasus `isUnerLeft` tertulis dua kali; yang kedua seharusnya `isUnerRight`.)

Bedanya dengan versi fungsional: di sini pohon diubah di tempat (parameter `input/output P`), bukan menghasilkan pohon baru.

### Membangun pohon dari pita karakter

Pohon bisa ditulis sebagai teks prefix, dengan `()` sebagai pohon kosong. Contoh: `(A(B()())(C()()))` = akar A, anak kiri B, anak kanan C.

Diktat memberi dua cara:

1. **Iteratif** (`MakeTree`, kode C oleh Riza Satria Perdana): setiap simpul punya pointer tambahan ke **Parent**. Program membaca karakter satu per satu memakai mesin karakter "couple" (`CC` = karakter sekarang, `C1` = karakter sebelumnya), karena keputusan bergantung pada karakter sebelumnya: huruf setelah `(` dipasang sebagai anak kiri, huruf setelah `)` sebagai anak kanan, dan `)` berarti naik kembali ke Parent.
2. **Rekursif** (`BuildTree`): jauh lebih pendek dan tidak perlu pointer Parent.

```
BuildTree (T):
  ADV                         { lewati '(' }
  if CC = ')' then T ← Nil    { pohon kosong "()" }
  else
    Alokasi(T, CC); ADV
    BuildTree(Left(T))
    BuildTree(Right(T))
  ADV                         { lewati ')' }
```

Ini contoh bagus bahwa struktur yang definisinya rekursif paling mudah diproses secara rekursif juga. Versi `BuildTreeFromString` sama persis, hanya membaca dari string dengan indeks, bukan dari pita.

## 10. Studi kasus (hlm. 128–205)

Pesan utama Bagian II: **tidak ada struktur data "terbaik"**. Pilihan struktur data baru bisa dinilai setelah operasi yang dibutuhkan diketahui. Setiap studi kasus membandingkan dua atau lebih representasi untuk persoalan yang sama.

| Studi kasus | Persoalan | Pilihan struktur data | Pelajaran utama |
| --- | --- | --- | --- |
| 1. Polinom | Membaca, menulis, menjumlah, mengurangi, dan menurunkan polinom | **Kontigu**: tabel koefisien, indeks = derajat. **Berkait**: list suku `<Degree, Coefficient>` terurut menurun | Kontigu boros kalau banyak suku nol (misalnya x¹⁰⁰⁰); berkait boros kalau hampir semua suku ada, karena derajat disimpan eksplisit |
| 2. Kemunculan huruf | Dari pita karakter, tulis tiap huruf (urut abjad), posisinya, dan berapa kali muncul | Solusi 1: baca pita 26 kali, tanpa penyimpanan. Solusi 2: matriks boolean huruf × posisi. Solusi 3: tabel 26 huruf (kontigu), masing-masing punya list posisi berkait | Struktur data sederhana bisa membuat algoritma lambat; memori dan waktu saling tukar |
| 3. Pengelolaan memori | Mengelola blok memori: alokasi X blok kontigu, dealokasi, garbage collection | **Kontigu**: tabel status per blok (isi/kosong). **Berkait**: list zone kosong `<awal, ukuran>` terurut menurut awal | Strategi alokasi First Fit vs Best Fit; kompleksitas algoritma bergantung pada representasi |
| 4. Multi-list | Data pegawai dan anak-anaknya | Alt. I: setiap pegawai punya list anak sendiri. Alt. II: list pegawai dan list anak terpisah, setiap anak menyimpan alamat ayahnya | Relasi 1-N; mana yang lebih baik bergantung pada query yang sering dipakai |
| 5. Relasi N-M | Dosen mengajar banyak mata kuliah, mata kuliah diajar banyak dosen | Alt. 1: tiap dosen punya list MK ("Mengajar"). Alt. 2: tiap MK punya list dosen ("Diajar Oleh"). Alt. 3: list relasi terpisah berisi pasangan `<Dosen, MK>` | Bandingkan dari segi memori dan kemudahan query |
| 6. Topological sort | Dari urutan parsial (X sebelum Y), hasilkan satu urutan linier | Solusi I (Wirth): multilist **Leader** (setiap item + jumlah predesesornya) dan **Trailer** (list suksesor). Solusi II: satu list pasangan `<Precc, Succ>` | Contoh nyata graf, sentinel, dan list First-Last dengan dummy |

### Catatan per studi kasus

**Polinom.** Polinom kosong di representasi kontigu harus didefinisikan khusus (`Degree = −999`), karena derajat 0 berarti polinom konstanta. Di representasi berkait, polinom kosong cukup list kosong. Setelah pengurangan, derajat hasil bisa turun, sehingga perlu `AdjustDegree`. Ada juga varian `P1 = P1 + P2` (hasil ditimpa ke operan): di representasi berkait, suku P2 bisa dipindahkan langsung ke list P1 tanpa alokasi baru.

**Kemunculan huruf.** Masalahnya ada dua: setiap huruf bisa muncul 0 sampai banyak kali (jadi butuh list posisi), dan output harus urut abjad (berbeda dengan urutan kemunculan). Matriks boolean 26 × 100 boros dan menuntut panjang pita maksimum diketahui. Versi berkait hanya menyimpan posisi yang benar-benar muncul.

**Pengelolaan memori.**

- **First Fit**: ambil zone kosong pertama yang cukup besar. **Best Fit**: ambil zone kosong paling kecil yang masih cukup, supaya zone besar tidak terpecah-pecah.
- Contoh: zone kosong `<1,1> <4,4> <11,2> <14,4> <22,2>` dan diminta 2 blok. First Fit memakai blok 4–5; Best Fit memakai blok 11–12.
- Saat dealokasi di representasi berkait, zone kosong yang bersebelahan harus **digabung** (contoh: `<4,5>` lalu dealokasi 3 blok mulai blok 1 menjadi `<1,8>`).
- **Garbage collection** = memampatkan semua blok isi ke satu sisi supaya semua blok kosong menyatu.

**Topological sort.** Contoh nyata: urutan prasyarat mata kuliah, urutan pekerjaan proyek, urutan deklarasi tabel basis data. Algoritmanya: berulang kali ambil item yang **tidak punya predesesor**, keluarkan ke hasil, lalu hapus hubungannya. Satu urutan parsial bisa punya banyak urutan linier yang sah. Di Solusi I, setiap item Leader menyimpan `Count` = banyak predesesor; item dengan `Count = 0` siap dikeluarkan. Sentinel dipakai untuk menggabungkan search dan insert saat membangun list Leader.

## Kamus istilah

| Istilah di diktat | Istilah umum | Artinya |
| --- | --- | --- |
| ADT | abstract data type | Type + operasi dasarnya |
| Primitif | primitive operation | Operasi dasar sebuah ADT |
| Selektor (Get) | getter | Mengambil komponen |
| Pengubah (Set) | setter, mutator | Mengubah komponen di tempat |
| Destruktor / Dealokator | destructor | Menghancurkan objek dan membebaskan memorinya |
| Prekondisi | precondition | Syarat sebelum fungsi/prosedur dipanggil |
| I.S. / F.S. | initial state / final state | Keadaan sebelum dan sesudah prosedur dijalankan |
| Driver | test driver | Program utama khusus untuk menguji ADT |
| Supplier / Client | provider / user module | Modul penyedia ADT / modul pemakai ADT |
| Koleksi objek | collection, container | Sekumpulan elemen bertype sama |
| Generik | generic | Type elemen ditentukan saat dipakai |
| Representasi lojik | logical representation | Spesifikasi dengan alamat abstrak |
| Representasi fisik | physical implementation | Wujud nyata di memori |
| Kontigu | contiguous | Bersebelahan di memori (array) |
| Berkait | linked | Disambung lewat alamat (linked list) |
| Address / alamat | address, pointer | Lokasi sebuah elemen |
| Nil | null | Alamat kosong |
| Suksesor / predesesor | successor / predecessor | Elemen sesudah / sebelum |
| Alokasi / dealokasi | allocate / free | Meminta / mengembalikan memori |
| Traversal | traversal | Mengunjungi semua elemen berurutan |
| Mark | sentinel, end marker | Penanda akhir (di sini: Nil) |
| Sequential search | linear search | Mencari dari depan satu per satu |
| Konkatenasi | concatenation | Menyambung dua list |
| FirstAvail | free list head | Kepala daftar sel memori yang belum terpakai |

Istilah tambahan dari bagian 7–10:

| Istilah di diktat | Istilah umum | Artinya |
| --- | --- | --- |
| Elemen fiktif / dummy | dummy node | Elemen palsu yang sengaja dialokasi supaya list kosong tidak perlu ditangani khusus |
| Sentinel | sentinel | Elemen penjaga di ujung list untuk mempercepat search |
| List sirkuler | circular list | Elemen terakhir menunjuk kembali ke elemen pertama |
| Pointer ganda | doubly linked list | Setiap elemen punya Next dan Prev |
| Akumulator | accumulator | Parameter pembawa hasil sementara |
| Konso / Kons | cons / snoc | Tambah elemen di awal / di akhir list |
| Hutan | forest | Kumpulan pohon yang disjoint |
| Ayah / anak / saudara | parent / child / sibling | Hubungan antar simpul pohon |
| Derajat | degree | Banyaknya anak sebuah simpul |
| Uner / biner (simpul) | unary / binary node | Simpul dengan satu / dua anak |
| Pohon condong | skewed tree | Pohon yang semua simpulnya hanya punya anak di satu sisi |
| Pohon seimbang | balanced tree | Beda tinggi (atau banyak simpul) kiri-kanan paling banyak 1 |
| Pohon biner terurut | binary search tree (BST) | Kiri lebih kecil, kanan lebih besar |
| Pita karakter | input tape / stream | Masukan yang dibaca karakter demi karakter |
| Mesin karakter (CC, ADV, START, EOP) | character reader | "Mesin abstrak" pembaca pita: CC = karakter sekarang, ADV = maju satu karakter, EOP = akhir pita |
| Zone | memory block range | Sekumpulan blok memori yang bersebelahan |
| First Fit / Best Fit | first fit / best fit | Strategi memilih zone kosong saat alokasi |
| Garbage collection | compaction | Memampatkan memori supaya blok kosong menyatu |
| Multilist | multilist | List yang elemennya punya list lain |
| Relasi 1-N / N-M | one-to-many / many-to-many | Jenis hubungan antar data |
| Urutan parsial / linier | partial / total order | Urutan sebagian (hanya sebagian pasangan diketahui) / urutan penuh |
| Topological sort | topological sort | Mengubah urutan parsial menjadi urutan linier |
