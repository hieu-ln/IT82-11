// Stack danh sach lien ket.
#include<iostream>
#include<stdio.h>
using namespace std;

// Khai bao cau truc danh sach lien ket.
struct Node{
    int info;
    Node *link;
};

Node *sp; // Luu tru dia chi node dau tien trong stack.

// Khoi tao danh sach rong.
void Init(){
    sp = NULL;
}

// KIem tra stack rong.
int isEmpty(){
    if(sp == NULL)
        return 1;
    else
        return 0;
}


// Thu tuc them 1 phan tu vao danh sach.
void push(int x){
    Node *p = new Node;
    p->info = x;
    p->link = sp;
    sp = p;
}

// Thu tuc lay 1 node ra khoi danh sach.
int pop(int x){
    if(sp != NULL){
        Node *p = sp;
        x = p->info;
        sp = p->link;
        delete p;
        return 1;
    }
    else
        return 0;
}

// Xuat Stack.
void process_stack(){
    Node *p = sp;
    while(p != NULL){
        cout << p->info << "\t";
        p = p->link;
    }
    cout << endl;
}

int main(){
    int choice = 0;
    int x, i, t;
    system("cls");
    cout << "-------------- Bai Tap 10 Chuong 2 (STACK - DSLK) ------------------" << endl;
    cout    << "1. Khoi tao STACK rong.\n"
            << "2. Them phan tu vao STACK.\n"
            << "3. Lay phan tu ra khoi STACK.\n"
            << "4. Xuat STACK\n"
            << "5. Thoat" << endl;
    
    do{
        cout << "\nNhap vao so de thuc hien: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                Init();
                cout << "\nKhoi tao STACK rong thanh cong." << endl;
                break;
            case 2:
                cout << "\nNhap vao phan tu ban muon them vao STACK: ";
                cin >> x;
                push(x);
                cout << "\nSTACK sau khi ban da them la: " << endl;
                process_stack();
                break;
            case 3:
                t = pop(x);
                if(t == 0)
                    cout << "\nDanh sach hien dang rong!" << endl;
                else
                    cout << "\nBan vua lay " << x << " ra khoi STACK." << endl;
                break;
            case 4:
                cout << "\nSTACK hien tai cua ban la: " << endl;
                process_stack();
                break;
            case 5:
                cout << "TAM BIET!" << endl;
                return 1;
                break;
            default:
                break;
        }
    }while(choice != 5);

    return 0;
}