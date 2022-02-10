#include <iostream>
#include "program.h"
#include <stdio.h>
#include <windows.h>

using namespace std;

int main()
{

    login(); // Login Akun

    int hasil_perhitungan;
    inf dt;
    int pil;
    int kode;
    for (;;)
    {
        system("cls");
        // TAMPILAN MENU
        cout << "\t\t\t\t\t\tM E N U : \n";
        cout << "\n\t\t\t\t [1] BUAT TRANSAKSI \n";
        cout << "\t\t\t\t [2] RIWAYAT TRANSAKSI \n";
        cout << "\t\t\t\t [3] S E L E S A I \n";
        cout << "\n\t\t\t\t Pilihan : ";
        cin >> pil; // KATEGORI PILIHAN

        switch (pil)
        {
        case 1: // BUAT TRANSAKSI
        {
            system("cls");
            entryData(); // PROSEDUR MENGINPUT INFORMASI PENGIRIM
            system("cls");
            kategoriWilayah(); // PROSEDUR MENGINPUT INFORMASI BARANG
            break;
        }
        case 2: // READ DAN UPDATE
        {
        redo:
            system("cls");
            cout << "\t\t\t\t\t\tM E N U : \n";
            cout << "\n\t\t\t\t [1] TAMPIL RIWAYAT \n";
            cout << "\t\t\t\t [2] UPDATE STATUS \n";
            cout << "\t\t\t\t [3] KEMBALI KE MENU \n";

            cout << "\n\t\t\t\t Pilihan : ";
            cin >> pil;
            switch (pil)
            {
            case 1:
                system("cls");
                tampilRiwayat();
                cout << "\n\t\t\t\t";
                system("pause");
                break;
            case 2:
                system("cls");
                updateRiwayat();
                cout << "\n\t\t\t\t";
                system("pause");
                break;
            case 3:
                break;
            default:
                system("cls");
                cout << "\n\n\t\t\t\t\tPILIHAN TIDAK ADA";
                Sleep(400);
                break;
            }
            break;
        }
        case 3: // SELESAI/EXIT
        {
            return (0);
        }
        default: //INPUTAN LAINNYA
        {
            system("cls");
            cout << "\n\n\t\t\t\t\tPILIHAN TIDAK ADA";
            Sleep(400);
            break;
        }
        }
    }
    return 0;
}
