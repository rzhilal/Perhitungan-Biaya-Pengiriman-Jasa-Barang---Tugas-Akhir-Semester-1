#ifndef program_H
#define program_H

typedef struct //STRUCT INFORMASI
{
    char kode_jasa[20];
    char tgl[12];
    char nm_pgrm[65];
    char alamat_pgrm[120];
    char pos_pgrm[7];
    char nm_pnrm[65];
    char alamat_pnrm[120];
    char pos_pnrm[7];
} inf;

typedef struct //STRUCT INFORMASI BARANG
{
	char nm_brg[60];
	int jml_brg;
	int brt_brg;
} brg;

void kategoriWilayah(); //PENGINPUTAN INFORMASI BARANG DAN SEKALIGUS PERHITUNGANNYA	

//PROTOTYPE
void kategoriWilayah(); //PEMILIHAN KODE WILAYAH

int perhitunganBiaya(int plh, int jml_brt); //MEHITUNG BIAYA JASA

void tampilRiwayat(); //MENAMPILKAN SELURUH HISTORY

void updateRiwayat(); //MENGUPDATE DATA

void hasil_input(); //HASIL INPUT

void login(); //PROSEDUR LOGIN

void entryData(); //PROSEDUR MENGENTRYKAN DATA KE FILE RIWAYAT

bool validasiKode(char inputan_kode[7]); //KODE UNIK CEK

void tampil_id(); //PROSEDUR MENAMPILKAN STATUS DAN ID SAJA


#endif
