#include <iostream>
#include <fstream>
#include <sstream>
#include "program.h"
#include <windows.h>
#include <conio.h>

using namespace std;

void login()
{

    // USER ACCOUNT
    string username = "admin";
    string password = "admin123";
    // USER LOGIN
    string input_username;
    string input_password;
    char ch; // PASSWORD HIDER
    // LOOP STOPPER
    bool penghenti = true;
    // PROGRAM
    while (penghenti)
    {
        input_password = ""; // RESET INPUT

        cout << "\t\t\t\t\t\tMASUKKAN AKUN\n";
        cout << "\n\t\t\t\tUSERNAME   : ";
        cin >> input_username;
        cout << "\n\t\t\t\tPASSWORD   : ";
        ch = getch();

        // PASSWORD HIDER
        while (ch != 13)
        {
            input_password.push_back(ch);
            if (ch == 8)
            {
                cout << "\b \b";
            }
            else
            {
                cout << '*';
            }
            ch = getch();
        }
        if (input_username == username && input_password == password)
        {
            system("cls");
            cout << "\n\n\t\t\t\t\tLOGIN BERHASIL";
            Sleep(400);
            system("cls");
            penghenti = false;
        }
        else if (input_username != username && input_password != password)
        {
            cout << "\n\t\t\t\t\tAkun Tidak Ada\n";
            Sleep(1200);
            system("cls");
        }
        else
        {
            cout << "\n\t\t\t\t\tUSERNAME/PASSWORD SALAH\n";
            Sleep(1200);
            system("cls");
        }
    }
}

void entryData()
{
    inf dt; // VAR PENAMPUNG STRUCT/RECORD
    char confirm;
    fstream fs;                                                    // VAR PENAMPUNG FILE (KESELURUHAN)
    fs.open("Riwayat_Transaksi.DAT", fstream::out | fstream::app); // OPEN FILE DENGAN MODE APPEND DAN MENULIS KEDALAM FILE
redo_kode: // PENGGUNAAN ADA PADA LINE 89
    cout << "\n\t\t\t\t\tMASUKKAN INFORMASI TRANSAKSI\n";
    // INPUT INFORMASI
    cout << "\n\t\t\t\tID SERVICE                  : ";
    // INPUT ID SERVIS SEKALIGUS PENGECEKAN BILA ADA YANG SAMA
    fflush(stdin);
    cin.getline(dt.kode_jasa, 20);
    if (validasiKode(dt.kode_jasa) == true)
    {
        cout << "\n\t\t\t\tKode Service sudah ada silahkan inputkan kembali!";
        Sleep(1500);
        system("cls");	
        goto redo_kode;
    }
    fflush(stdin);
    cout << "\n\t\t\t\tTANGGAL (dd/mm/yyyy)        : ";
    cin.getline(dt.tgl, 12);
    fflush(stdin);
    cout << "\n\t\t\t\tNAMA PENGIRIM               : ";
    cin.getline(dt.nm_pgrm, 65);
    fflush(stdin);
    cout << "\n\t\t\t\tALAMAT PENGIRIM             : ";
    cin.getline(dt.alamat_pgrm, 120);
    fflush(stdin);
    cout << "\n\t\t\t\tKODE POS PENGIRIM           : ";
    cin.getline(dt.pos_pgrm, 7);
    fflush(stdin);
    cout << "\n\t\t\t\tNAMA PENERIMA               : ";
    cin.getline(dt.nm_pnrm, 65);
    fflush(stdin);
    cout << "\n\t\t\t\tALAMAT PENERIMA             : ";
    cin.getline(dt.alamat_pnrm, 120);
    fflush(stdin);
    cout << "\n\t\t\t\tKODE POS PENERIMA           : ";
    cin.getline(dt.pos_pnrm, 65);
    fflush(stdin);

    // SAVE TO FILE
    fs << dt.kode_jasa << "|";
    fs << "Manifested" << "|";
    fs << dt.tgl << "|";
    fs << dt.nm_pgrm << "|";
    fs << dt.alamat_pgrm << "|";
    fs << dt.pos_pgrm << "|";
    fs << dt.nm_pnrm << "|";
    fs << dt.alamat_pnrm << "|";
    fs << dt.pos_pnrm << "|";
    fs.close();
}

void kategoriWilayah()
{

    int pilihan;    // KATEGORI PILIHAN
    int jml_barang; // BANYAK BARANG
    int jml_berat;  // PENAMPUNG BERAT TOTAL BARANG
    float biaya;
    fstream fs;                                                                  // STREAM CLASS UNTUK FILE
    fs.open("Riwayat_Transaksi.DAT", fstream::in | fstream::out | fstream::app); // MEMBACA DAN MENULIS DENGAN MODE MENAMBAHKAN(APPEND)
    brg dt;

label_continue:
    // PILIHAN WILAYAH
    cout << "\t\t\t\t\t\tPILIH KODE WILAYAH : \n";
    cout << "\t\t\t\t[1] JAWA \n";
    cout << "\t\t\t\t[2] SUMATERA \n";
    cout << "\t\t\t\t[3] KALIMANTAN \n";
    cout << "\t\t\t\t[4] SULAWESI \n";
    cout << "\t\t\t\t[5] PAPUA \n";
    cout << "\n\t\t\t\tPilihan : ";
    cin >> pilihan;
    if (pilihan > 5)
    {
        cout << "\n\t\t\t\tPILIHAN TIDAK ADA HARAP MASUKKAN KEMBALI ";
        Sleep(800);
        system("cls");
        goto label_continue;
    }
    cout << "\n\t\t\t\tJUMLAH BARANG DIKIRIM : ";
    cin >> dt.jml_brg;
    fs << dt.jml_brg << "|";

    system("cls");
    cout << "\t\t\t\t\t\tMASUKAN INFORMASI BARANG\n";

    // MENGINPUT INFORMASI BARANG
    for (int i = 1; i <= dt.jml_brg; i++)
    {
        cout << "\n\t\t\t\tBARANG KE              : " << i << "\n";
        cout << "\n\t\t\t\tNAMA BARANG            : ";
        fflush(stdin);
        cin.getline(dt.nm_brg, 60);
        cout << "\n\t\t\t\tBERAT BARANG (DALAM KG) : ";
        cin >> dt.brt_brg;
        jml_berat = jml_berat + dt.brt_brg; // PENJUMLAHAN TOTAL SELURUH BERAT UNTUK DIHITUNG DALAM BIAYA
        fflush(stdin);

        // SAVE TO FILE
        fs << i << "|";
        fs << dt.nm_brg << "|";
        fs << dt.brt_brg << "KG|";
    }
    biaya = perhitunganBiaya(pilihan, jml_berat);
    fs << biaya << "|"; // PERHITUNGAN BIAYA TOTAL SEKALIGUS MENYIMPAN KEDALAM FILE
    fs.close();
}

int perhitunganBiaya(int plh, int jml_brt)
{
    float harga;
    cout << "\n\t\t\t\t\t\tPERHITUNGAN BIAYA\n";
    if (plh == 1) //JAWA
    {
        harga = 19000 * jml_brt;
        cout << "\n\t\t\t\tTOTAL HARGA         : " << harga << "\n";
        if (jml_brt >= 5)
        {
            harga = harga * (0.95);
            cout << "\n\t\t\t\tPOTONGAN HARGA (5%) : " << harga << "\n";
        }
        harga = harga * (1.1);
        cout << "\n\t\t\t\tPPN 10%             : " << harga << "\n";
        system("pause");
        return harga;
    }
    if (plh == 2)
    {
        harga = 26000 * jml_brt;
        cout << "\n\t\t\t\tTOTAL HARGA         : " << harga << "\n";
        if (jml_brt >= 5)
        {
            harga = harga * (0.95);
            cout << "\n\t\t\t\tPOTONGAN HARGA (5%) : " << harga << "\n";
        }
        harga = harga * (1.1);
        cout << "\n\t\t\t\tPPN 10%             : " << harga << "\n";
        system("pause");
        return harga;
    }
    if (plh == 3)
    {
        harga = 37000 * jml_brt;
        cout << "\n\t\t\t\tTOTAL HARGA         : " << harga << "\n";
        if (jml_brt >= 5)
        {
            harga = harga * (0.95);
            cout << "\n\t\t\t\tPOTONGAN HARGA (5%) : " << harga << "\n";
        }
        harga = harga * (1.1);
        cout << "\n\t\t\t\tPPN 10%             : " << harga << "\n";
        system("pause");
        return harga;
    }
    if (plh == 4)
    {
        harga = 59000 * jml_brt;
        cout << "\n\t\t\t\tTOTAL HARGA         : " << harga << "\n";
        if (jml_brt >= 5)
        {
            harga = harga * (0.95);
            cout << "\n\t\t\t\tPOTONGAN HARGA (5%) : " << harga << "\n";
        }
        harga = harga * (1.1);
        cout << "\n\t\t\t\tPPN 10%             : " << harga << "\n";
        system("pause");
        return harga;
    }
    if (plh == 5)
    {
        harga = 105000 * jml_brt;
        cout << "\n\t\t\t\tTOTAL HARGA         : " << harga << "\n";
        if (jml_brt >= 5)
        {
            harga = harga * (0.95);
            cout << "\n\t\t\t\tPOTONGAN HARGA (5%) : " << harga << "\n";
        }
        harga = harga * (1.1);
        cout << "\n\t\t\t\tPPN 10%             : " << harga;
        system("pause");
        return harga;
    }
}

void tampilRiwayat()
{
    string data; // PENAMPUNG DATA DALAM FILE
    char remover[2];
    fstream fo;
    int converter;                             // PENAMPUNG NILAI CONVERTED DARI FILE
    fo.open("Riwayat_Transaksi.DAT", ios::in); // OPEN FILE IN READ MODE

    if (getline(fo, data, '|') == NULL)
    {
        cout << "\n\t\t\t\tBELUM ADA DATA";
        goto end;
    }else
    {
    	fo.close();
    	fo.open("Riwayat_Transaksi.DAT", ios::in); // OPEN FILE IN READ MODE
	}

    while (getline(fo, data, '|')) // MENAMPULKAN YANG ADA DI DATA
    {
        cout << "\n\t\t\t\t------------------------------------------------------------";
        cout << "\n\t\t\t\tID SERVICE              : " << data;
        cout << "\n\t\t\t\t-------------------------------------";
        getline(fo, data, '|');
        cout << "\n\t\t\t\tSTATUS PENGIRIMAN       : " << data;
        cout << "\n\t\t\t\t-------------------------------------";
        getline(fo, data, '|');
        cout << "\n\t\t\t\tTANGGAL (dd/mm/yyyy)    : " << data;
        getline(fo, data, '|');
        cout << "\n\t\t\t\tNAMA PENGIRIM           : " << data;
        getline(fo, data, '|');
        cout << "\n\t\t\t\tALAMAT PENGIRIM         : " << data;
        getline(fo, data, '|');
        cout << "\n\t\t\t\tKODE POS PENGIRIM       : " << data;
        getline(fo, data, '|');
        cout << "\n\t\t\t\tNAMA PENERIMA           : " << data;
        getline(fo, data, '|');
        cout << "\n\t\t\t\tALAMAT PENERIMA         : " << data;
        getline(fo, data, '|');
        cout << "\n\t\t\t\tKODE POS PENERIMA       : " << data;
        ;
        cout << "\n\t\t\t\t-------------------------------------";

        // CONVERTING CHAR FROM FILE TO INT
        getline(fo, data, '|');
        stringstream conv(data);
        converter;
        conv >> converter;

        for (int i = 1; i <= converter; i++)
        {
            getline(fo, data, '|');
            cout << "\n\t\t\t\tBARANG KE               : " << data;
            getline(fo, data, '|');
            cout << "\n\t\t\t\tNAMA BARANG             : " << data;
            getline(fo, data, '|');
            cout << "\n\t\t\t\tBERAT BARANG (DALAM KG) : " << data;
            cout << "\n\t\t\t\t-------------------------------------";
        }
        getline(fo, data, '|');
        cout << "\n\t\t\t\tTOTAL PEMBAYARAN        : Rp." << data;
        printf("\n");
    }
end:
    fo.close();
}

void updateRiwayat()
{
    string data;
    string kode;
    int converter;
    fstream lama, baru;
    lama.open("Riwayat_Transaksi.DAT", ios::in);
    baru.open("baru.DAT", ios::out); // OPEN FILE
    // FILE CHECKING
    if (getline(lama, data, '|') == NULL)
    {
        cout << "\n\t\t\t\tBELUM ADA DATA";
        goto end;
    } else
    {
		tampil_id(); //PROSEDUR MEMBACA ID DAN STATUS
		lama.close();
    	lama.open("Riwayat_Transaksi.DAT", ios::in);
	}
    cout << "\n\t\t\t\tMASUKKAN ID STATUS YANG MAU DI UPDATE : ";
    cin >> kode; // BACA KODE YANG MAU DI UPDATE
    system("cls");
    while (getline(lama, data, '|'))
    {
		if (kode == data)
        {
            baru << data << "|";
            cout << "\n\t\t\t\t\t\tPANDUAN\n";
            cout << "\n\t\t\t\tManifested   : Barang sedang disiapkan untuk dikirim\n";
            cout << "\n\t\t\t\tTransit      : Barang sedang transit di kota lain\n";
            cout << "\n\t\t\t\tProcess      : Barang dalam proses pengiriman\n";
            cout << "\n\t\t\t\tDelivered    : Barang sudah diterima oleh alamat tujuan\n";
            cout << "\n\t\t\t\tProblem      : Barang bermasalah\n";
            cout << "\n\t\t\t\t----------------------------------------------------------";
            getline(lama, data, '|');
            cout << "\n\t\t\t\tSTATUS   : " << data << "\n";
            cout << "\n\t\t\t\tRUBAH STATUS : ";
            cin >> data;
        }
        baru << data << "|";
    }
end:
    lama.close(); baru.close(); // CLOSE FILE
    remove("Riwayat_Transaksi.DAT");
    rename("baru.DAT", "Riwayat_Transaksi.DAT");
}

bool validasiKode(char inputan_kode[7])
{
    string data;                               // SEBAGAI VAR PENAMPUNG DATA YANG DIBACA
    fstream fo;                                // VAR PENAMPUNG FILE
    fo.open("Riwayat_Transaksi.DAT", ios::in); // OPEN FILE DENGAN MODE MEMBACA
    bool status = false;

    string conv(inputan_kode);

    while (getline(fo, data, '|'))
    {
        if (conv == data)
        {
            status = true;
            break;
        }
    }
    fo.close();
    return status;
}

void tampil_id()
{
    fstream fo; //PENGOPERASIAN
    string data; // PENAMPUNG DATA YANG DIBACA DARI FILE
    int converter; // VARIABEL HASIL CONVERTAN
	fo.open("Riwayat_Transaksi.DAT", ios::in); // MEMBUKA FILE DENGAN MODE MEMBACA
    while (getline(fo, data, '|')) //PERULANGAN DENGAN KONDISI AKAN MELAKUKAN SAMPAI DATA HABIS DIBACA
    {
    	cout << "\n\t\t\t\tID : " << data;
		getline(fo, data, '|'); 
		cout << "\t\tSTATUS : " << data << endl;
		for(int i = 0; i<7 ; i++)
		{
			getline(fo, data, '|');
		}
		getline(fo, data, '|');
        stringstream conv(data);
        conv >> converter;

        for (int i = 1; i <= converter; i++)
        {
        getline(fo, data, '|');
        getline(fo, data, '|');
        getline(fo, data, '|');
        }
		getline(fo, data, '|');			
	}
	fo.close();
}

