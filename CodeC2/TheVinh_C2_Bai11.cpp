#include<iostream>
#include<stdio.h>
using namespace std;

// Khai bo cau truc QUEUE.
struct Node
{
	int info;
	Node *link;
};

Node * front, * rear; // Luu dia chi dau va cuoi cua QUEUE.

// Thuc tuc tao QUEUE rong.
void init()
{
	front = NULL;
	rear = NULL;
}

// Kiem tra xem QUEUE rong.
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}

// Them 1 phan tu vao QUEUE.
void push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(front == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

// Xoa 1 phan tu trong QUEUE.
int pop(int &x)
{
	if(isEmpty() == 1){
        Node *p = front;
        x = p->info;
        front = front->link;
        if(front == NULL)
            rear = NULL;
        delete p;
        return 1;
    }
    return 0;
}

// Xuat ra man hinh cac phan tu trong QUEUE
void process_queue()
{
	Node *p = front;
	while(p!=NULL)
	{
		cout << p->info << "\t";
		p=p->link;
	}
	cout << endl;
}

int main ()
{
	int choice;
    int x, t;
    system("cls");
    cout << "---------- BAI TAP 11 CHUONG 2 (QUEUE - DSLK) -------------" << endl;
    cout    << "1. Khoi tao 1 QUEUE rong.\n"
            << "2. Them phan tu vao QUEUE.\n"
            << "3. Xoa 1 phan tu ra khoi QUEUE.\n"
            << "4. Kiem tra QUEUE xem co rong hay khong.\n"
            << "5. Xuat QUEUE.\n"
            << "6. Thoat" << endl;
    do{
        cout << "\nNhap vao so ban muon thuc hien: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            init();
            cout << "\nBan da tao QUEUE rong thanh cong." << endl;
            break;
        case 2:
            cout << "\nNhap vao phan tu ban muon them vao QUEUE: ";
            cin >> x;
            push(x);
            cout << "\nQUEUE sau khi da duoc them " << x << " vao la\n";
            process_queue();
            break;
        case 3:
            t = pop(x);
            if(t == 1)
                cout << "\nQUEUE hien gio dang rong!" << endl;
            else
                cout << "\nBan da lay phan tu " << x << " ra khoi QUEUE." << endl;
            break;
        case 4:
            t = isEmpty();
            if(t == 0)
                cout << "\nQUEUE hien tai da co phan tu!" << endl;
            else
                cout << "\nQUEUE hien tai dang rong." << endl;
            break;
        case 5:
            cout << "\nQUEUE hien tai la: " << endl;
            process_queue();
            break;
        case 6:
            cout << "\nTAM BIET!" << endl;
            return 1;
            break;
        default:
            break;
        }
    }while(choice != 6);
	return 0;
}