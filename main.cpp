#include "TUBES.h"

int main()
{
    list_Parent l;
    list_Child lc;
    list_Relasi lr;
    adr_Parent p;
    adr_Child q;
    adr_Relasi r;
    int i,j,x,pilihan;
    user datauser[n];
    string Karir,username,password,kode;
    i = 0;
    cout << "===========================================================" << endl;
    cout << "| Selamat datang Di program penginputan data alumni       |" << endl;
    cout << "| Silahkan  Login terlebih dahulu !!                      |" << endl;
    cout << "===========================================================" << endl;

    cout << "===========================================================" << endl;
    cout << "| Login | [1] Login                                       |" << endl;
    cout << "| data  | [2] Registrasi (hanya admin)                    |" << endl;
    cout << "===========================================================" << endl;

    cout << endl << "Pilih Menu = " ;
    cin >> pilihan ;

    while (pilihan != 0){
        if (pilihan == 1 ) {
            system("CLS");
            cout << "===========================================================" << endl;
            cout << "| Selamat datang Di program penginputan data alumni       |" << endl;
            cout << "| Silahkan  Login terlebih dahulu !!!                      |" << endl;
            cout << "===========================================================" << endl;

            cout << "| Username = ";
            cin  >> username;

            cout << "| password = ";
            cin  >> password;
            cout << "============================================================" << endl;


            j = -1;
            bool kondisi = true;
            while (kondisi != false) {
                j = j + 1;
                if (username == datauser[j].username && password == datauser[j].password) {
                    kondisi = false;
                } else if (j > i){
                    kondisi = false;
                } else {
                    kondisi = true;
                }
            }
            if ( username == datauser[j].username && password == datauser[j].password) {
                    createlistparent(l);
                    createListchild(lc);
                    createlistrelasi(lr);
                    system("CLS");
                    cout <<endl << "Hello!! selamat datang " << username << "<3" << endl;
                    cout << "disini kamu bisa menginputkan data alumni" << endl << endl;
                    cout << "Pilih Menu yang ingin di inputkan" << endl;
                    cout << "============================================================" << endl ;
                    cout << "|                     Insert Menu                          |" << endl ;
                    cout << "============================================================" << endl ;
                    cout << "[1] | Insert Data Alumni                                   |" << endl;
                    cout << "[2] | Insert Data Karir                                    |" << endl;
                    cout << "[3] | Insert Alumni Beserta Karir pendidikan               |" << endl;
                    cout << "============================================================" << endl ;
                    cout << "|                      Edit Menu                           |"<< endl;
                    cout << "============================================================" << endl ;
                    cout << "[4] | Edit Data Alumni                                     |" << endl;
                    cout << "[5] | Edit Data Karir                                      |" << endl;

                    cout << "============================================================" << endl ;
                    cout << "|                      Hapus Menu                          |" << endl;
                    cout << "============================================================" << endl ;
                    cout << "[6] | Hapus Data Alumni                                    |" << endl;
                    cout << "[7] | Hapus Data Karir                                     |" << endl;
                    cout << "============================================================" << endl ;
                    cout << "|                      Cari Menu                           |" << endl;
                    cout << "============================================================" << endl ;
                    cout << "[8] | Cari Data Alumni berdasarkan Data Karir            |" << endl ;
                    cout << "[9] | Cari Data Karir Berdasarkan Alumni                 |" << endl ;
                    cout << "============================================================" << endl ;
                    cout << "|                     Tampil Menu                          |" << endl;
                    cout << "============================================================" << endl ;
                    cout << "[10]| Tampil Data Alumni                                   |" << endl;
                    cout << "[11]| Tampil Data Karir                                    |" << endl;
                    cout << "[12]| Tampil Data Alumni Beserta Karir pendidikan          |" << endl;
                    cout << "[13]| Tampilkan Karir yang terbanyak Dimiliki alumni       |" << endl;
                    cout << "[0] | keluar                                               |" << endl;
                    cout << "============================================================" << endl;
                    cout << endl;
                    cout << "pilihan = ";
                    cin  >> pilihan;

                    while (pilihan != 0) {
                        if (pilihan == 1) {
                            system("CLS");
                            cout << endl;
                            createlementparent(p);
                            insertfirstparent(l,p);
                            cout << endl;
                            tampildataparent(l);
                            system("PAUSE");
                        } else if (pilihan == 2) {
                            system("CLS");
                            cout << endl;
                            createElmtchild(q);
                            insertLastchild(lc,q);
                            cout << endl;
                            printListchild(lc);
                            system("PAUSE");
                        } else if (pilihan == 3) {
                            system("CLS");
                            inputrelasi(lr,l,lc);
                            cout << endl;
                            system("CLS");
                            printListRelasi(lr);
                            system("PAUSE");
                        } else if (pilihan == 4) {
                            system("CLS");
                            tampildataparent(l);
                            cout << endl;
                            editdatalumni(l,p);
                            cout << endl;
                            system("PAUSE");
                        } else if (pilihan == 5) {
                            system("CLS");
                            printListchild(lc);
                            cout << endl;
                            editdataKarir(lc,q);
                            cout << endl;
                            system("PAUSE");

                        } else if (pilihan == 6) {
                            system("CLS");
                            tampildataparent(l);
                            cout << "-----------------------------------------------------"<< endl;
                            cout << "| Delete | Delete Data Alumni                       |"<< endl;
                            cout << "-----------------------------------------------------"<< endl;
                            cout << "| jika ingin membatalkan ketik -1                    " << endl ;
                            cout << "| data di hapus berdasarkan id alumni : ";
                            cin  >> x;
                            cout << "-----------------------------------------------------"<< endl;
                            cout << endl;
                            deleteelmtrelasiId(lr,l,r,x);
                            deleteelmtparent(l,p,x);
                            system("PAUSE");
                        } else if (pilihan == 7) {
                            system("CLS");
                            printListchild(lc);
                            cout << "--------------------------------------------------------------------------" << endl;
                            cout << "| delete   | jika ingin membatalkan ketik 'tidak' " << endl;
                            cout << "|  data    | Masukan Data yang Ingin di hapus berdasarkan Karir   : ";
                            cin>>Karir;
                            cout << "--------------------------------------------------------------------------" << endl;
                            cout << endl;
                            deleteelmtrelasiKarir(lr,lc,r,Karir);
                            deleteElmtchild(lc,q,Karir);
                            system("PAUSE");
                        } else if (pilihan == 8) {
                            system("CLS");
                            printListchild(lc);
                            cout << endl;
                            cout << "jika ingin membatalkan ketik 'tidak'" << endl << endl;
                            cout << "--------------------------------------------------------------------------" << endl;
                            cout << "|  Cari  | Cari Data Alumni Berdasarkan " << endl;
                            cout << "|  data  | Karir   Sekolah               : ";
                            cin>>Karir;
                            cout << "--------------------------------------------------------------------------" << endl;
                            cout << endl;
                            tampildataalumniterentu(lr,Karir);
                            cout << endl;
                            system("PAUSE");
                        } else if (pilihan == 9) {
                            system("CLS");
                            tampildataparent(l);
                            cout << endl;
                            cout << "jika ingin membatalkan ketik '-1'" << endl << endl;
                            cout << "--------------------------------------------------------------------------" << endl;
                            cout << "|  Cari  | Cari Data Karir   Berdasarkan " << endl;
                            cout << "|  data  | Id Alumni                     : ";
                            cin>>x;
                            cout << "--------------------------------------------------------------------------" << endl;
                            cout << endl;
                            tampildataKarirtertentu(lr,x);
                            cout << endl;
                            system("PAUSE");
                        } else if (pilihan == 10) {
                            system("CLS");
                            tampildataparent(l);
                            system("PAUSE");
                        } else if (pilihan == 11) {
                            system("CLS");
                            printListchild(lc);
                            system("PAUSE");
                        } else if (pilihan == 12) {
                            system("CLS");
                            printListRelasi(lr);
                            system("PAUSE");
                        } else if (pilihan == 13) {
                            system("CLS");
                            KarirTerbanyak(lr,lc);
                            system("PAUSE");
                        } else if (pilihan > 13) {
                            system("CLS");
                            cout << "tidak ada pilihan selain 11 ke atas !!" << endl;
                            system("PAUSE");
                        }

                        system("CLS");
                        cout <<endl << "Hello!! selamat datang " << username << ":D" << endl;
                        cout << "disini kamu bisa menginputkan data alumni" << endl << endl;
                        cout << "Pilih Menu yang ingin di inputkan" << endl;
                        cout << "============================================================" << endl ;
                        cout << "|                     Insert Menu                          |" << endl ;
                        cout << "============================================================" << endl ;
                        cout << "[1] | Insert Data Alumni                                   |" << endl;
                        cout << "[2] | Insert Data Karir                                    |" << endl;
                        cout << "[3] | Insert Alumni Beserta Karir   pendidikan             |" << endl;
                        cout << "============================================================" << endl ;
                        cout << "|                      Edit Menu                           |"<< endl;
                        cout << "============================================================" << endl ;
                        cout << "[4] | Edit Data Alumni                                     |" << endl;
                        cout << "[5] | Edit Data Karir                                      |" << endl;

                        cout << "============================================================" << endl ;
                        cout << "|                      Hapus Menu                          |" << endl;
                        cout << "============================================================" << endl ;
                        cout << "[6] | Hapus Data Alumni                                    |" << endl;
                        cout << "[7] | Hapus Data Karir                                     |" << endl;
                        cout << "============================================================" << endl ;
                        cout << "|                      Cari Menu                           |" << endl;
                        cout << "============================================================" << endl ;
                        cout << "[8] | Cari Data Alumni berdasarkan Data Karir              |" << endl ;
                        cout << "[9] | Cari Data Karir   Berdasarkan Alumni                 |" << endl ;
                        cout << "============================================================" << endl ;
                        cout << "|                     Tampil Menu                          |" << endl;
                        cout << "============================================================" << endl ;
                        cout << "[10]| Tampil Data Alumni                                   |" << endl;
                        cout << "[11]| Tampil Data Karir                                    |" << endl;
                        cout << "[12]| Tampil Data Alumni Beserta Karir   pendidikan        |" << endl;
                        cout << "[13]| Tampilkan Karir   yang terbanyak Dimiliki alumni     |" << endl;
                        cout << "[0] | keluar                                               |" << endl;
                        cout << "============================================================" << endl;
                        cout << endl;
                        cout << "pilihan = ";
                        cin  >> pilihan;
                    }
                } else {
                    cout << "Data tidak Tersedia pada Database!!!" << endl <<endl;
                    system("PAUSE");
                }

        } else {
            system("CLS");
            cout << endl;
            cout << "========================================================================="<< endl;
            cout << "|  Registrasi  | Selamat Datang di menu registrasi !!                   |"<< endl;
            cout << "|     akun     | masukan kode untuk memvertifikasi bahwa kamu admin !!  |" << endl;
            cout << "========================================================================="<< endl;
            cout << "| masukan kode registrasi = " ;
            cin >> kode ;
            cout << "========================================================================="<< endl;
            system("PAUSE");

            if (kode == "12345"){
                system("CLS");
                cout << "==========================================" << endl;
                cout << "| masukan admin baru !!                  |" << endl;
                cout << "==========================================" << endl;
                cout << "| Username = " ;
                cin >> username;
                datauser[i].username = username;

                cout << "| password = " ;
                cin >> password;
                datauser[i].password = password;
                cout << "==========================================" << endl;
                cout << "|   Data    | Username = "<< datauser[i].username << endl;
                cout << "|  Terbaru  | Password = "<< datauser[i].password << endl;
                cout << "==========================================" << endl;
                i = i + 1;

                cout << "Data Berhasil di Input !!!" << endl << endl;
                system("PAUSE");
            } else {
                system("CLS");
                cout << "kode salah !!!";
                cout << endl;
                system("PAUSE");
            }
        }
        system("CLS");
        cout << "===========================================================" << endl;
        cout << "| Selamat datang Di program penginputan data alumni       |" << endl;
        cout << "| Silahkan  Login terlebih dahulu !!                      |" << endl;

        cout << "===========================================================" << endl;
        cout << "| Login | [1] Login                                       |" << endl;
        cout << "| data  | [2] Registrasi (hanya admin)                    |" << endl;
        cout << "===========================================================" << endl;


        cout << endl << "pilih Menu = " ;
        cin >> pilihan ;
    }
}
