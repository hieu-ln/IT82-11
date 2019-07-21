#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;
int a[MAX];

// Khoi tao QUEUE rong.
void Init(int a[], int &front, int &rear){
    front = -1;
    rear = -1;
}

// Kiem tra QUEUE rong.
int isEmpty(int a[], int &front, int &rear){
    if(front == rear)
        return 1;
    else
        return 0;
}

// Kiem tra QUEUE day.
int isFULL(int a[], int &front, int &rear){
    if((front == 0 && rear == MAX -1) || (front - rear == 1))
        return 1;
    else
        return 0;
}

// Them phan tu vao QUEUE
int push(int a[], int &front, int &rear, int x){
    if(rear - front == MAX - 1)
        return 0; // Luc nay QUEUE da day
    else {
        if(front == -1)
            front = 0;
        if(rear == MAX - 1){
            for (int i = front; i <= rear; i++){
                a[i - front] = a[i];
            }
            rear = MAX - 1 - front;
            front = 0;
        }
        a[++rear] = x;
        return 1;
    }
    return 0;
}

// Lay phan tu ra khoi QUEUE.
int pop(int a[], int &front, int &rear, int &x){
    if(front == -1) // luc nay QUEUE khong co phan tu nao.
        return 0;
    else {
        x = a[front++];
        if(front > rear) {
            front = -1;
            rear = -1;
        }
        return 1;
    }
    return 0;
}
// Xuat ra man hinh QUEUE.
void process_queue(int a[], int front, int rear){
    cout << "Front = " << front << "\t Rear = " << rear << endl;
    if(front <= rear && front != -1){
        cout << "<--  ";
        for(int i = front; i <= rear; i++){
            cout << a[i] << "    ";
        }
        cout << "<--" << endl;
    }
}
int main(){
    int a[MAX];
    int choice, x, t;
    int f, r;
    system("cls");
    cout << "-------------------- QUEUE - HANG DOI - DANH SACH DAC ---------------\n"
         << "1. Khoi tao QUEUE rong.\n"
         << "2. Them phan tu vao QUEUE.\n"
         << "3. Lay phan tu ra khoi QUEUE.\n"
         << "4. Kiem tra xem QUEUE co rong hay khong.\n"
         << "5. Kiem tra xem QUEUE co day hay khong.\n"
         << "6. Xuat QUEUE ra man hinh.\n"
         << "7. Thoat" << endl;
    
    do{
        cout << "\nNhap vao so ban muon thuc hien: "; 
        cin >> choice;
        switch(choice){
            case 1:
                Init(a, f, r);
                cout << "\nBan da khoi tao mot QUEUE rong thanh cong." << endl;
                break;
            case 2:
                cout << "\nNhap vao phan tu ban muon them vao QUEUE: ";
                cin >> x;
                t = push(a, f, r, x);
                if(t == 1){
                    cout << "\nQUEUE sau khi them phan tu " << x << endl;
                    process_queue(a, f, r);
                }
                else
                    cout << "\nQUEUE hien da day!" << endl;
                break;
            case 3:
                t = pop(a, f, r, x);
                if(t == 1)
                    cout << "\nBan vua lay " << x << " ra khoi QUEUE." << endl;
                else 
                    cout << "\nQUEUE hien gio dang rong!" << endl;
                break;
            case 4:
                t = isFULL(a, f, r);
                if(t == 0)
                    cout << "\nQUEUE hien gio chua day!" << endl;
                else
                    cout << "\nQUEUE da day." << endl;
                break;
            case  5:
                t = isEmpty(a, f, r);
                if(t == 0)
                    cout << "\nQUEUE hien gio dan co phan tu!" << endl;
                else
                    cout << "\nQUEUE hien dang trong." << endl;
                break;
            case 6:
                cout << "\nQUEUE hien tai cua ban la: ";
                process_queue(a, f, r);
                break;
            case 7:
                cout << "\nTAM BIET!" << endl;
                break;
            default:
                break;
        }
    }while(choice != 7);
    return 0;
}