#include "TUBES.h"

void createListchild(list_Child &L){
    firstChild(L)=NULL;
    lastChild(L)=NULL;
}
void createElmtchild(adr_Child &P){
    string Karir;

    P = new elmListChild;
    nextChild(P) = NULL;


    cout << "====================================================="<< endl;
    cout << "| insert | Tambah Data Alumni                       |"<< endl;
    cout << "====================================================="<< endl;
    cout << "| Karir                     = ";
    cin >> Karir;
    infoChild(P).Karir = Karir;
    cout << "====================================================="<< endl;
}

void insertLastchild(list_Child &L, adr_Child P){

    if (firstChild(L) == NULL && lastChild(L) == NULL) {
        firstChild(L) = P;
        lastChild(L) = P;
        nextChild(P) = firstChild(L);
    } else {
        nextChild(P) = firstChild(L);
        firstChild(L) = P ;
        nextChild(lastChild(L)) = firstChild(L);
    }
}

void deletefirstchild(list_Child &L, adr_Child &P){
    P =firstChild(L);
    firstChild(L) = nextChild(P);
    nextChild(lastChild(L))= firstChild(L);
    nextChild(P) = NULL;
}
void deleteLastchild(list_Child &L, adr_Child &P){
    adr_Child q;
    P = lastChild(L);
    q = firstChild(L);

    while (nextChild(q) != P) {
        q = nextChild(q);
    }

    lastChild(L) = q;
    nextChild(q) = firstChild(L);
    nextChild(P) = NULL;

}
void deleteElmtchild(list_Child &L, adr_Child &P,string Karir){
    adr_Child prec;
    if(prec == NULL){
        cout<<"List kosong !!!"<<endl;
        P = NULL;
    }else{

        if (Karir != "tidak") {

            prec = searchKarir(L,Karir);

            if(prec==NULL){
                cout<<"Data Tidak Tersedia"<<endl;
            } else if(nextChild(firstChild(L)) == firstChild(L)){
                    P=firstChild(L);
                    firstChild(L)=NULL;
                    lastChild(L) =NULL;
                    nextChild(P) = NULL;
                    cout << "Data dengan Nama '" << Karir << "' Telah Terhapus !!" << endl;
            }else if(prec==firstChild(L)){
                    P = prec;
                    deletefirstchild(L,P);
                    cout << "Data dengan Nama '" << Karir << "' Telah Terhapus !!" << endl;
            }else if(prec==lastChild(L)){
                    deleteLastchild(L,P);
                    cout << "Data dengan Nama '" << Karir << "' Telah Terhapus !!" << endl;
            }else{
                    P=prec;
                    prec = firstChild(L);
                    while(nextChild(prec)!= P){
                        prec = nextChild(prec);
                    }
                    nextChild(prec)=nextChild(P);
                    nextChild(P)=NULL;
                    cout << "Data dengan Nama '" << Karir << "' Terhapus !!" << endl;
                }
            } else{
                cout << endl;
                cout << "Anda Berhasil Keluar dari Menu !!" << endl;
            }
    }
}
void printListchild(list_Child L){
    adr_Child P;
    int i = 0;
    if (firstChild(L) == NULL) {
        cout << "datakosong !!" << endl;
    } else {
        P = firstChild(L);
        cout << "============================================================"<< endl;
        cout << "|                   Tampil Data Karir                    |" << endl;
        cout << "============================================================" << endl;

        while(nextChild(P)!=firstChild(L)){
            i = i + 1;
        cout << "|       |                                                  |" << endl;
        cout << "|   "<< i <<"   | " << infoChild(P).Karir <<"                                              |" << endl;
        cout << "|       |                                                  |" << endl;
        cout << "============================================================" << endl;
            P = nextChild(P);
        }

        i = i + 1;
        cout << "|       |                                                  |" << endl;
        cout << "|   "<< i <<"   | " << infoChild(P).Karir <<"                                              |" << endl;
        cout << "|       |                                                  |" << endl;

        cout << "============================================================" << endl;
    }
}

void editdataKarir(list_Child &L,adr_Child P) {
    string Karir;

    if (firstChild(L) == NULL ) {
        cout << "data kosong !!!" << endl;
        P = NULL;
    } else {
        cout << endl;
        cout << "====================================================="<< endl;
        cout << "| Submit | Edit Data Karir                         |"<< endl;
        cout << "====================================================="<< endl;
        cout << "| Jika Ingin membatalkan ketik 'tidak'" << endl;
        cout << "| Masukan Data Karir : ";
        cin  >> Karir;
        cout << "====================================================="<< endl;
        if (Karir != "tidak") {
            P = searchKarir(L,Karir);

            if (P != NULL) {
                cout << "====================================================="<< endl;
                cout << "|  Edit  | Edit Data Karir                          |"<< endl;
                cout << "====================================================="<< endl;
                cout << "| Karir                     = ";
                cin >> Karir;
                infoChild(P).Karir = Karir;
                cout << "====================================================="<< endl;
                cout << endl;

                printListchild(L);

                cout << endl << " Data Berhasil di Input !!! " << endl << endl;
            } else {
                cout << "Data Tidak Tersedia !!!" << endl << endl;
            }
        } else {
            cout << "Anda Telah Membatalkan Menu !!!" << endl << endl;
        }

    }
}

adr_Child searchKarir(list_Child L, string Karir){

    adr_Child P;
    if(firstChild(L)!=NULL){
        P = firstChild(L);
        while( nextChild(P) != firstChild(L) && infoChild(P).Karir!=Karir){
            P=nextChild(P);
        }
        if(infoChild(P).Karir==Karir){
            return P;
        }else{
            return NULL;
        }
    }

}

