#ifndef program_H
#define program_H

typedef struct //STRUCT INFORMASI
{

} inf;

typedef struct //STRUCT INFORMASI BARANG
{

} brg;

//PROTOTYPE
void kategoriWilayah(); //PEMILIHAN KODE WILAYAH

int perhitunganBiaya(int plh, int jml_brt); //MEHITUNG BIAYA JASA

void tampilRiwayat(); //MENAMPILKAN SELURUH HISTORY

void updateRiwayat(); //MENGUPDATE DATA

void hasil_input(); //HASIL INPUT

void login(); //PROSEDUR LOGIN

void entryData(); //PROSEDUR MENGENTRYKAN DATA KE FILE RIWAYAT

bool validasiKode(char inputan_kode[7]); //KODE UNIK CEK



#endif
