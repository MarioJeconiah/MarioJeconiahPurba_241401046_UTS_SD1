#include <iostream>
using namespace std;

#define MAX 10 

struct Pasien {
    string nama;
    string jenis;
    string umur;    
    int darurat;
};

Pasien queue[MAX];
int front = -1, rear = -1;

void enqueue(Pasien p) {
    if (rear == MAX - 1) { 
        cout << "Queue penuh!\n";
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = p; 
    }
}


void sort() {
    if (front == -1 || front > rear) return;
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (queue[j].darurat > queue[i].darurat) { 
                Pasien temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong!\n";
    } else {
        cout << "\nIsi antrean saat ini:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i].nama
                 << " (" << queue[i].umur << ")"  
                 << " - Darurat " << queue[i].darurat << endl;
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;
    cin.ignore();

    Pasien p;
    for (int i = 0; i < n; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, p.nama);
        cout << "Jenis hewan: ";
        getline(cin, p.jenis);
        cout << "Umur: ";
        getline(cin, p.umur);  
        cout << "Tingkat darurat (1-5): ";
        cin >> p.darurat;
        cin.ignore(); 

        enqueue(p);
    }

    sort();    
    display();

    return 0;
}
