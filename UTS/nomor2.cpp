#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node {
    string judul;
    int tahun;
    int rating;
    Node *next;
};

// Pointer Head dan Tail
Node *head = NULL;
Node *tail = NULL;

// Struktur Data Input
struct tempData {
    string judul;
    int tahun;
    int rating;
};

// Insert di depan
void insertFirst(string a, int b, int c) {
    Node *newNode = new Node;
    newNode->judul = a; 
    newNode->tahun = b;
    newNode->rating = c;
    newNode->next = NULL; 

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head; 
        head = newNode; 
    }
}


void insertLast(string a, int b, int c) {
    Node *newNode = new Node; 
    newNode->judul = a;
    newNode->tahun = b;
    newNode->rating = c;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode; 
        tail = newNode; 
    }
}


void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    Node *temp = head;  
    head = head->next; 
    if (head == NULL) tail = NULL;
    delete temp;  
}


void deleteByTitle(string a) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }


    if (head->judul == a) {
        deleteFirst();
        return;
    }


    Node *p = head; 
    while (p->next != NULL && p->next->judul != a) {
        p = p->next;
    }


    if (p->next == NULL) {
        cout << "Film tidak ditemukan!\n";
    } else {
        Node *temp = p->next; 
        p->next = temp->next; 
        if (temp == tail) tail = p;
        delete temp;
        cout << "Film berhasil dihapus!\n";
    }
}


void printList() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
    }
}

int main() {
    tempData y;
    int x;
    char agreement;

    cout << "Masukkan jumlah film awal: ";
    cin >> x;

    cin.ignore();

    int totalFilm = x;

 

    while (x > 0) {
        cout << "\nFilm " << totalFilm - x + 1 << ":" << endl;

        cout << "Judul: ";
        getline(cin, y.judul);

        cout << "Tahun: ";
        cin >> y.tahun;

        cout << "Rating: ";
        cin >> y.rating;
        cin.ignore(); 

        insertLast(y.judul, y.tahun, y.rating);
        x--;
    }

    cout << "\nApakah anda ingin menghapus film? (y/n): ";
    cin >> agreement;
    cin.ignore(); 

    if (agreement == 'y') {
        string tempJudulFilm;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, tempJudulFilm);

        deleteByTitle(tempJudulFilm);
        totalFilm--;
    }


    printList();

    cout << "\nTotal film tersisa: " << totalFilm << endl;

    return 0;
}
