// Danh sach han che, ngan xep, stack
#include<iostream>
#include<stdio.h>
#define MAX 100 // 5.1
using namespace std;

// Khoi tao stack rong.
void Init(int a[], int &sp){
    sp = -1;
}

// Kiem tra stack rong.
int isEmpty(int sp){
    if(sp == -1)
        return 1;
    return 0;
}

// Kiem tra stack co day hay khong.
int isFull(int sp){
    if(sp == MAX - 1)
        return 1;
    return 0;
}

// Them phan tu vao ngan xep.
int push(int a[], int &sp, int x){
    if(isFull(sp) != 1){
        a[++sp] = x;
        return 1;
    }
    else
        return 0;
}

// Xoa 1 phan tu.
int pop(int a[], int &sp, int &x){
    if(isEmpty(sp) != 1){
        x = a[sp--];
        return 1;
    }
    return 0;
}

// Xuat stack ra man hinh.
void process_stack(int a[], int sp){
    for(int i = 0; i < sp + 1; i++)
        cout << a[i] << "\t";
    cout << endl;
}

int main()
{
    int a[MAX];
    int choice, sp, x, t;
    system("cls");

    cout    << "\t\t\t\tBAI TAP 5 CHUONG 2 STACK (NGAN XEP - DS DAC)\n"
            << "1. Khoi tao stack rong.\n"
            << "2. Them phan tu vao stack.\n"
            << "3. Lay phan tu ra khoi stack.\n"
            << "4. Kiem tra stack rong hay khong.\n"
            << "5. Kiem tra stack co day hay khong.\n"
            << "6. xuat ra man hinh cac phan tu trong stack.\n"
            << "7. Thoat." << endl;
    do {
        cout << "\nNhap vao lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Init(a, sp);
            cout << "\nBan da khoi tao stack rong thanh cong." << endl;
            break;
        
        case 2:
            cout << "\nNhap vao phan tu ban muon them vao stack: ";
            cin >> x;
            t = push(a, sp, x);
            if(t == 0)
                cout << "\nKhong the them phan tu vao stack!" << endl;
            else
                cout << "\nThem phan tu vao stack thanh cong." << endl;
            break;
        
        case 3:
            t = pop(a, sp, x);
            if(t == 0)
                cout << "\nStack hien dang rong!" << endl;
            else
                cout <<"\nDa lay phan tu " << x << " ra khoi stack thanh cong!" << endl;
            break;

        case 4:
            t = isEmpty(sp);
            if(t == 0)
                cout << "\nStack hien tai da co phan tu!" << endl;
            else
                cout << "\nStack hien dang rong." << endl;
            break;
        
        case 5:
            t = isFull(sp);
            if(t == 0)
                cout << "\nStack hien gio van chua day!" << endl;
            else
                cout << "\nStack hien tai da day" << endl;
            break;
        
        case 6:
            cout << "\nStack hien tai cua ban la: " << endl;
            process_stack(a, sp);
            break;
        
        case 7:
            cout << "\nGood bye!" << endl;
            return 1;
            break;
            
        default:
            break;
        }

    }  while(choice != 7);
    return 0;
}