#include "TUBES.h"

void createlistparent(list_Parent &l){
    firstParent(l)=NULL;
    lastParent(l) = NULL;
}

bool isempty(list_Parent l) {
    if (firstParent(l) == NULL && lastParent(l)==NULL) {
        return true;
    } else {
        return false;
    }
}

void createlementparent(adr_Parent &p) {
    int id;
    string nama;
    int tgl_l;
    string tempat_l;
    int tahun_l;
    string alamat;
    string jk;

    p = new elmListParent;
    nextParent(p) = NULL;
    prevParent(p) = NULL;


    cout << "===================================================="<< endl;
    cout << "| insert | Tambah Data Alumni                       |"<< endl;
    cout << "===================================================="<< endl;
    cout << "| Id Alumni                                = ";
    cin >> id;
    infoParent(p).id = id;

    cout << "| Nama Alumni                              = " ;
    cin >> nama;
    infoParent(p).nama = nama;

    cout << "| Tanggal Kelahiran Alumni                     = " ;
    cin >> tgl_l;
    infoParent(p).tgl_l = tgl_l;


    cout << "| Tempat Kelahiran Alumni                      = " ;
    cin >> tempat_l;
    infoParent(p).tempat_l = tempat_l;

    cout << "| Tahun Kelahiran Alumni                       = " ;
    cin >> tahun_l;
    infoParent(p).tahun_l = tahun_l;


    infoParent(p).umur = 2020 - infoParent(p).tahun_l;
    cout << "| Usia Alumni                              = "<< infoParent(p).umur;
    cout << endl;

    cout << "| Alamat Alumni                            = " ;
    cin >> alamat;
    infoParent(p).alamat = alamat;

    cout << "| Jenis Kelamin <L/P>                      = " ;
    cin >> jk;
    if (jk == "L") {
        infoParent(p).jk = jk;
    } else if (jk == "P") {
        infoParent(p).jk = jk;
    } else {
        cout << "Pilihan Tidak tersedia !!!";
    }

    cout << "====================================================="<< endl;
    cout << endl;

    cout << "Data Berhasil di Imput !!!" << endl;

}

void editdatalumni(list_Parent &l,adr_Parent p) {
    int id;
    string nama;
    int tgl_l;
    string tempat_l;
    int tahun_l;
    string alamat;
    string jk;

    if (firstParent(l) == NULL) {
        cout << "Data Tidak Tersedia !!!" << endl;
    } else {
        cout << endl;

        cout << "====================================================="<< endl;
        cout << "| Submit | Edit Data Alumni                         |"<< endl;
        cout << "====================================================="<< endl;
        cout << "| Jika Ingin Membatalkan Ketik '-1'" << endl;
        cout << "| Masukan Data Id Alumni : ";
        cin  >> id;
        cout << "====================================================="<< endl;
        if (id != -1) {
            p = carielementparent(l,id);

            if (p !=NULL) {
                cout << "====================================================="<< endl;
                cout << "| Edit | Edit Data Alumni                           |"<< endl;
                cout << "====================================================="<< endl;

                cout << "| Nama Alumni                              : " ;
                cin >> nama;
                infoParent(p).nama = nama;

                cout << "| tanggal Kelahiran Alumni                     : " ;
                cin >> tgl_l;
                infoParent(p).tgl_l = tgl_l;


                cout << "| Tempat Kelahiran Alumni                      : " ;
                cin >> tempat_l;
                infoParent(p).tempat_l = tempat_l;

                cout << "| Tahun Kelahiran alumni                       : " ;
                cin >> tahun_l;
                infoParent(p).tahun_l = tahun_l;


                infoParent(p).umur = 2020 - infoParent(p).tahun_l;
                cout << "| Usia alumni                              : "<< infoParent(p).umur;
                cout << endl;

                cout << "| Alamat alumni                            : " ;
                cin >> alamat;
                infoParent(p).alamat = alamat;

                cout << "| Jenis kelamin <L/P>                      : " ;
                cin >> jk;
                if (jk == "L") {
                    infoParent(p).jk = jk;
                } else if (jk == "P") {
                    infoParent(p).jk = jk;
                } else {
                    cout << "Pilihan Tidak Tersedia !!!";
                }

                cout << "====================================================="<< endl;
                cout << endl << endl;

                tampildataparent(l);

                cout << endl << "Data Berhasil Ter input !!!" << endl;

            } else {
                cout << "data tidak Tersedia !!!" << endl;
            }
        } else {
            cout << "ANDA BERHASIL MEMBATALKAN MENU !!!" << endl << endl ;
        }

    }
}

void insertfirstparent(list_Parent &l,adr_Parent p) {
    if(isempty(l) == true) {
        firstParent(l) = p;
        lastParent(l) = p;
    } else {
        nextParent(p) = firstParent(l);
        prevParent(firstParent(l)) = p;
        firstParent(l) = p;
    }
}

void deletelastparent(list_Parent &l,adr_Parent &p) {
    if(isempty(l) == true) {
        cout << "Data Kosong" << endl;
        p = NULL;
    } else if (nextParent(firstParent(l)) == NULL){
        p = firstParent(l);
        firstParent(l) = NULL;
        lastParent(l) = NULL;
    } else {
        p = lastParent(l);
        lastParent(l) = prevParent(p);
        prevParent(p) = NULL;
        nextParent(lastParent(l)) = NULL;
    }
}

void deletefirstparent(list_Parent &l,adr_Parent &p) {
    if(isempty(l) == true) {
        cout << "Data Kosong" << endl;
        p = NULL;
    } else if (nextParent(firstParent(l)) == NULL){
        p = firstParent(l);
        firstParent(l) = NULL;
        lastParent(l) = NULL;
    } else {
        p = firstParent(l);
        firstParent(l) = nextParent(p);
        prevParent(firstParent(l)) = NULL;
        nextParent(p) = NULL;
    }
}

adr_Parent carielementparent(list_Parent l,int x) {
    adr_Parent p;
    p = firstParent(l);
    while (nextParent(p) != NULL && infoParent(p).id != x) {
        p = nextParent(p);
    }

    if (infoParent(p).id == x){
        return p;
    } else {
        return NULL;
    }
}

void deleteelmtparent(list_Parent &l,adr_Parent &p,int x){
    adr_Parent prec,q;

    if (isempty(l) == true) {
        cout << "Data Kosong" <<endl << endl;
        p = NULL;
    } else {

        if (x != -1) {
            prec = carielementparent(l,x);

            if (prec == NULL) {
                cout << "Data Tidak Tersedia !!!" << endl;
            } else if (nextParent(prec) == NULL){
                p = prec;
                deletelastparent(l,p);
                cout << "Data dengan ID " << x << "Telah Terhapus !!!" << endl;
            } else if (prevParent(prec) == NULL) {
                p = prec;
                deletefirstparent(l,p);
                cout << "Data dengan ID " << x << "Telah Terhapus !!!" << endl;
            } else {
                p = prec;
                prec = nextParent(p);
                q = prevParent(p);
                nextParent(q) = prec;
                prevParent(prec) = q;
                nextParent(p) = NULL;
                prevParent(p) = NULL;
                cout << "Data dengan ID " << x << "Telah Terhapus !!!" << endl;
            }
        } else {
            cout << endl;
            cout << "Anda Berhasil Keluar dari Menu !!" << endl;
        }

    }
}

void tampildataparent(list_Parent l){
    adr_Parent p;
    p = firstParent(l);
    int i = 0;
    cout << "============================================================="<< endl;
    cout << "| tampil | Tampil Semua data Alumni                         |" << endl ;
    cout << "=============================================================" << endl ;
    while (p != NULL){
        i = i + 1;
        cout << "|        | id alumni           : " << infoParent(p).id << endl;
        cout << "|        | Nama alumni         : " << infoParent(p).nama << endl;
        cout << "|        | TTL Alumni          : " << infoParent(p).tgl_l <<", "<<infoParent(p).tempat_l << " " << infoParent(p).tahun_l<< endl;
        cout << "|   " << i << "    | Umur Alumni         : " << infoParent(p).umur << endl;
        cout << "|        | Alamat alumni       : " << infoParent(p).alamat << endl;
        cout << "|        | JK alumni           : " << infoParent(p).jk << endl;
        p = nextParent(p);
        cout <<"=============================================================" << endl;
    }
}
