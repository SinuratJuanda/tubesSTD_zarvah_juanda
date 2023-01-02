#include "TUBES.h"

void createlistrelasi(list_Relasi &l) {
    firstRelasi(l) = NULL;
    lastRelasi(l) = NULL;
}

adr_Relasi createlementrelasi(adr_Parent alumni,adr_Child Karir) {
    adr_Relasi p = new elmListRelasi;
    nextRelasi(p) = NULL;
    topRelasi(p)  = alumni;
    botRelasi(p)  = Karir;
}

void insertfirstrelasi(list_Relasi &l,adr_Relasi p) {
   if (firstRelasi(l) == NULL && lastRelasi(l) == NULL){
        firstRelasi(l) = p;
        lastRelasi(l) = p;
    } else {
        nextRelasi(p) = firstRelasi(l);
        firstRelasi(l) = p;
    }
}

void inputrelasi (list_Relasi &lr,list_Parent lp,list_Child lc) {
    adr_Parent p;
    adr_Child q;
    adr_Relasi r;
    int x;
    string Karir;

    tampildataparent(lp);
    cout << endl;

    cout << "-----------------------------------------------------"<< endl;
    cout << "| Submit | Masukan Data Alumni Untuk Di relasikan   |"<< endl;
    cout << "-----------------------------------------------------"<< endl;
    cout << "| Jika Ingin membatalkan ketik '-1' " << endl;
    cout << "| Masukan Data Idalumni : ";
    cin  >> x;
    cout << "-----------------------------------------------------"<< endl;
    if (x != -1){
        p = carielementparent(lp,x);

        if (p != NULL) {
        system("CLS");
        printListchild(lc);
        cout << endl;

        cout << "-----------------------------------------------------"<< endl;
        cout << "| Submit | Masukan Data Karir Untuk Di relasikan  |"<< endl;
        cout << "-----------------------------------------------------"<< endl;
        cout << "| Masukan Data Karir : ";
        cin  >> Karir;
        cout << "-----------------------------------------------------"<< endl;
        q = searchKarir(lc,Karir);

        if (q != NULL) {
            r = createlementrelasi(p,q);
            insertfirstrelasi(lr,r);
            cout << endl;
            cout << "data berhasil di input !!" << endl;

        } else {
            system("CLS");
            cout << "data Karir tidak ada !!" << endl;
        }

        } else {
            system("CLS");
            cout << "data ID alumni tidak ada !!" << endl;
            system("PAUSE");
        }
        system("PAUSE");
    } else {
        cout << "anda memberhentikan menu !! " << endl << endl;
    }

}


void deleteelmtrelasiKarir(list_Relasi &l,list_Child lc,adr_Relasi &p,string Karir){
    adr_Relasi q,r;

    if (firstRelasi(l) == NULL && lastRelasi(l) == NULL) {
        cout << "data kosong" <<endl << endl;
        p = NULL;
    } else {
        if (Karir != "tidak") {
            q = firstRelasi(l);
        while (q != NULL) {
            if (infoChild(botRelasi(q)).Karir == Karir && firstRelasi(l) == q ) {
                p = q;
                q = nextRelasi(q);
                firstRelasi(l) = q;
                nextRelasi(p) = NULL;
                topRelasi(p) = NULL;
                botRelasi(p) = NULL;
            } else if (infoChild(botRelasi(q)).Karir == Karir && lastRelasi(l) == q){
                p = q;
                q = NULL;
                r = firstRelasi(l);
                while (nextRelasi(r) != p) {
                    r = nextRelasi(r);
                }
                lastRelasi(l) = r;
                nextRelasi(r) = NULL;
                topRelasi(p) = NULL;
                botRelasi(p) = NULL;
            } else if (infoChild(botRelasi(q)).Karir == Karir && nextRelasi(firstRelasi(l)) == NULL) {
                p = q;
                q = NULL;
                firstRelasi(l) = NULL;
                lastRelasi(l) = NULL;
                topRelasi(p) = NULL;
                botRelasi(p) = NULL;

            } else if (infoChild(botRelasi(q)).Karir == Karir && nextRelasi(r) == q) {
                p = q;
                q = nextRelasi(q);
                nextRelasi(r) = q;
                topRelasi(p) = NULL;
                nextRelasi(p) = NULL;
                botRelasi(p) = NULL;
            } else {
                r = q;
                q = nextRelasi(q);
            }
        }
        }
    }
}

void deleteelmtrelasiId(list_Relasi &l, list_Parent lp, adr_Relasi &p,int idalumni){
    adr_Relasi q,r;

    if (firstRelasi(l) == NULL && lastRelasi(l) == NULL) {
        cout << "data kosong" <<endl << endl;
        p = NULL;
    } else {
        if (idalumni != -1) {
            q = firstRelasi(l);
            while (q != NULL) {
                if (infoParent(topRelasi(q)).id == idalumni && firstRelasi(l) == q ) {
                    p = q;
                    q = nextRelasi(q);
                    firstRelasi(l) = q;
                    nextRelasi(p) = NULL;
                    topRelasi(p) = NULL;
                    botRelasi(p) = NULL;
                } else if (infoParent(topRelasi(q)).id  == idalumni  && lastRelasi(l) == q){
                    p = q;
                    q = NULL;
                    r = firstRelasi(l);
                    while (nextRelasi(r) != p) {
                        r = nextRelasi(r);
                    }
                    lastRelasi(l) = r;
                    nextRelasi(r) = NULL;
                    topRelasi(p) = NULL;
                    botRelasi(p) = NULL;
                } else if (infoParent(topRelasi(q)).id == idalumni  && nextRelasi(firstRelasi(l)) == NULL) {
                    p = q;
                    q = NULL;
                    firstRelasi(l) = NULL;
                    lastRelasi(l) = NULL;
                    topRelasi(p) = NULL;
                    botRelasi(p) = NULL;

                } else if (infoParent(topRelasi(q)).id == idalumni  && nextRelasi(r) == q) {
                    p = q;
                    q = nextRelasi(q);
                    nextRelasi(r) = q;
                    topRelasi(p) = NULL;
                    nextRelasi(p) = NULL;
                    botRelasi(p) = NULL;
                } else {
                    r = q;
                    q = nextRelasi(q);
                }
            }
        } else {
            cout << "anda memberhentikan Menu !!" << endl << endl;
        }
    }
}

void tampildataalumniterentu (list_Relasi l,string Karir){
    adr_Relasi p;
    int i = 0;

    if (firstRelasi(l) == NULL) {
        cout << "DATA KOSONG !!" << endl << endl;
    } else {
        if (Karir != "tidak") {
            p = firstRelasi(l);
            cout << "============================================================="<< endl;
            cout << "| tampil | Tampil Semua data Alumni                         |" << endl ;
            cout << "-------------------------------------------------------------" << endl ;
            while (p != NULL) {
                if (infoChild(botRelasi(p)).Karir == Karir) {
                    i = i + 1;
                    cout << "|        | id alumni           : " << infoParent(topRelasi(p)).id << endl;
                    cout << "|        | Nama alumni         : " << infoParent(topRelasi(p)).nama << endl;
                    cout << "|        | TTL Alumni          : " << infoParent(topRelasi(p)).tgl_l <<", "<<infoParent(topRelasi(p)).tempat_l << " " << infoParent(topRelasi(p)).tahun_l<< endl;
                    cout << "|   " << i << "    | Umur Alumni         : " << infoParent(topRelasi(p)).umur << endl;
                    cout << "|        | Alamat alumni       : " << infoParent(topRelasi(p)).alamat << endl;
                    cout << "|        | JK alumni           : " << infoParent(topRelasi(p)).jk << endl;
                    cout <<"-------------------------------------------------------------" << endl;
                }
                p = nextRelasi(p);
                cout << endl;
            }
            cout << endl;
        } else {
            cout << "Anda memberhentikan Menu !!" << endl << endl;
        }

    }
}
void tampildataKarirtertentu(list_Relasi l,int id){
    adr_Relasi p;
    int i = 0;

    if (firstRelasi(l) == NULL) {
        cout << "DATA KOSONG !!" << endl << endl;
    } else {
        if (id != -1) {
            p = firstRelasi(l);
            cout << "============================================================="<< endl;
            cout << "| tampil | Tampil Semua data Karir                        |" << endl ;
            cout << "-------------------------------------------------------------" << endl ;
            while (p != NULL) {
                if (infoParent(topRelasi(p)).id == id) {
                    i = i + 1;
                    cout << "|       |                                                  |" << endl;
                    cout << "|   "<< i <<"   |" << infoChild(botRelasi(p)).Karir <<"                          |" << endl;
                    cout << "|       |                                                  |" << endl;
                    cout << "============================================================" << endl;
                }
                p = nextRelasi(p);
            }
            cout << endl;
        } else {
            cout << "Anda Berhasil Membatalkan Menu !!!" << endl << endl;
        }
    }
}

void KarirTerbanyak(list_Relasi l,list_Child lc ){
    adr_Relasi p;
    adr_Child q;
    int i,banyak,dikit;

    banyak = 0;
    dikit = 9999;

    if (firstRelasi(l) == NULL && firstChild(lc) == NULL) {
       cout << "Data Kosong !!!" << endl << endl;
    } else {
        q = firstChild(lc);
        while (nextChild(q) != firstChild(lc)) {
            infoChild(q).jumlah = 0;
            q = nextChild(q);
        }
        infoChild(q).jumlah = 0;

        p = firstRelasi(l);
        while (p != NULL) {
            q = botRelasi(p);
            infoChild(q).jumlah = infoChild(q).jumlah + 1;
            p = nextRelasi(p);
        }

        q = firstChild(lc);
        while (nextChild(q) != firstChild(lc)) {
            if (infoChild(q).jumlah < dikit) {
                dikit = infoChild(q).jumlah;
            }
            q = nextChild(q);
        }
        if (infoChild(q).jumlah < dikit) {
                dikit = infoChild(q).jumlah;
        }

        // mencari maks buku yang di pinjam
        q = firstChild(lc);
        while (nextChild(q) != firstChild(lc)) {
            if (infoChild(q).jumlah > banyak) {
                banyak = infoChild(q).jumlah;
            }
            q = nextChild(q);
        }
        if (infoChild(q).jumlah > banyak) {
                banyak = infoChild(q).jumlah;
        }

        q = firstChild(lc);
        i = 0;
        cout << "============================ KARIR TERBANYAK !!! ============================" << endl << endl;
        while (nextChild(q) != firstChild(lc)) {
            if (infoChild(q).jumlah == banyak){
                i = i + 1;
                cout << "| No = " << i << " | Karir = " << infoChild(q).Karir ;
                cout << " | Karir paling banyak = " << infoChild(q).jumlah << " | ";
                cout << endl;
            }
            q = nextChild(q);
        }
        if (infoChild(q).jumlah == banyak){
                i = i + 1;
                cout << "| No = " << i << " | Karir = " << infoChild(q).Karir ;
                cout << " | Karir paling banyak = " << infoChild(q).jumlah << " | ";
                cout << endl;
        }
        cout << endl << endl;


        cout << "============================ KARIR TERENDAH !!! ============================" << endl << endl;
        q = firstChild(lc);
        i = 0;
        while (nextChild(q) != firstChild(lc)) {
            if (infoChild(q).jumlah == dikit){
                i = i + 1;
                cout << "| No = " << i << " | Karir = " << infoChild(q).Karir ;
                cout << " | Karir paling banyak = " << infoChild(q).jumlah << " | ";
                cout << endl;
            }
            q = nextChild(q);
        }
        if (infoChild(q).jumlah == dikit){
                i = i + 1;
                cout << "| No = " << i << " | Karir = " << infoChild(q).Karir ;
                cout << " | Karir paling banyak = " << infoChild(q).jumlah << " | ";
                cout << endl;
        }
        cout << endl;
    }
}

void printListRelasi(list_Relasi l) {
    adr_Relasi p;
    int i = 0;

    if (firstRelasi(l) == NULL) {
        cout << "data kosong !!!" << endl << endl;
    } else {

        p = firstRelasi(l);
        cout << "=============================================================="<< endl;
        cout << "| Tampil | Tampil Data Relasi                                |"<< endl;
        cout << "=============================================================="<< endl;
        while (p != NULL) {
            i = i + 1;
            cout << "|        | ID Alumni                = " << infoParent(topRelasi(p)).id << endl;
            cout << "|        | Nama Alumni              = " << infoParent(topRelasi(p)).nama << endl;
            cout << "|        | Tempat Tanggal Lahir Alumni = " << infoParent(topRelasi(p)).tgl_l<<","<< infoParent(topRelasi(p)).tempat_l << " " << infoParent(topRelasi(p)).tahun_l << endl;
            cout << "|   "<< i  <<"    | Umur alumni              = " << infoParent(topRelasi(p)).umur << " Tahun" << endl;
            cout << "|        | Alamat Alumni            = " << infoParent(topRelasi(p)).alamat << endl;
            cout << "|        | Jenis Kelamin            = " << infoParent(topRelasi(p)).jk << endl;
            cout << "|        | Karir Alumni           = " << infoChild(botRelasi(p)).Karir << endl;
            cout << "--------------------------------------------------------------"<< endl;
            p = nextRelasi(p);
        }
    }
}
