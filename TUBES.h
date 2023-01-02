#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED


#include <iostream>
#include <stdlib.h>
//parent
#define infoParent(A) A->infoParent
#define nextParent(A) A->nextParent
#define prevParent(A) A->prevParent
#define firstParent(A) A.firstParent
#define lastParent(A) A.lastParent

//child
#define infoChild(P) P->infoChild
#define nextChild(P) P -> nextChild
#define firstChild(L) L.firstChild
#define lastChild(L) L.lastChild

//relasi
#define nextRelasi(A) A->nextRelasi
#define topRelasi(A) A->topRelasi
#define botRelasi(A) A->botRelasi
#define firstRelasi(A) A.firstRelasi
#define lastRelasi(A) A.lastRelasi



using namespace std;

typedef struct elmListParent * adr_Parent;
typedef struct elmListChild *adr_Child;
typedef struct elmListRelasi * adr_Relasi;

//parent
const int n = 100;
// tipe bentukan data yang digunakan

struct datadiri {
    int id;
    string nama;
    int tgl_l;
    string tempat_l;
    int tahun_l;
    int umur;
    string alamat;
    string jk;
};

struct user {
    string username;
    string password;
};

// alamat element

struct elmListParent{
    datadiri infoParent;
    adr_Parent nextParent;
    adr_Parent prevParent;
};

//List kotaknya dari parent,relasi dan child

struct list_Parent {
    adr_Parent firstParent;
    adr_Parent lastParent;
};


//Child
struct Karir {
    string Karir;
    int jumlah;
};

struct elmListChild{
    Karir infoChild;
    adr_Child nextChild;
};
struct list_Child{
    adr_Child firstChild;
    adr_Child lastChild;
};


//Relasi
struct elmListRelasi{
    adr_Parent topRelasi;
    adr_Child botRelasi;
    adr_Relasi nextRelasi;
};

struct list_Relasi {
    adr_Relasi firstRelasi;
    adr_Relasi lastRelasi;
};

//Parent
void createlistparent(list_Parent &l);
bool isempty(list_Parent l);
void createlementparent(adr_Parent &p);
void insertfirstparent(list_Parent &l,adr_Parent p);
void deleteelmtparent(list_Parent &l,adr_Parent &p,int x);
void deletelastparent(list_Parent &l,adr_Parent &p);
void editdatalumni(list_Parent &l,adr_Parent p);
void deletefirstparent(list_Parent &l,adr_Parent &p);
adr_Parent carielementparent(list_Parent l,int x);
void tampildataparent(list_Parent l);


//Child
void createListchild(list_Child &L);
void createElmtchild(adr_Child &P);
void insertLastchild(list_Child &L, adr_Child P);
void deletefirstchild(list_Child &L, adr_Child &P);
void deleteLastchild(list_Child &L, adr_Child &P);
void deleteElmtchild(list_Child &L,adr_Child &P, string Karir);
void printListchild(list_Child L);
void editdataKarir(list_Child &L,adr_Child P);
adr_Child searchKarir(list_Child L, string Karir);

//Relasi
void createlistrelasi(list_Relasi &l);
adr_Relasi createlementrelasi(adr_Parent alumni,adr_Child Karir);
void insertfirstrelasi(list_Relasi &l,adr_Relasi p);
void inputrelasi(list_Relasi &lr,list_Parent lp,list_Child lc);
void deleteelmtrelasiId(list_Relasi &l,list_Parent lp,adr_Relasi &p,int idalumni);
void deleteelmtrelasiKarir(list_Relasi &l,list_Child lc,adr_Relasi &p,string Karir);
void tampildataalumniterentu (list_Relasi l,string Karir);
void tampildataKarirtertentu(list_Relasi l,int id);
void printListRelasi(list_Relasi l);
void KarirTerbanyak (list_Relasi l,list_Child lc );

#endif // TUBES_H_INCLUDED
