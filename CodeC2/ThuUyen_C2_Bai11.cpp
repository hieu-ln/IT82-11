#include <iostream>
#include <stdio.h>
using namespace std;
struct Queue
{
	int info;
	Queue *link;
};
Queue *first;
void init()
{
	first = NULL;
	cout<<"Da khoi tao Queue rong thanh cong!"<<endl;
}
int isEmpty()
{
	if(first == NULL)
		return 0;
	else
		return 1;
}
void push(int x)
{
	Queue *q = new Queue;
	q->info = x;
	q->link = NULL;
	if(first == NULL)
		first = q;
	else{
		Queue *p = first;
		while(p->link != NULL)
			p = p->link;
		p->link = q;
	}
	cout<<"Da them bien x = "<<x<<" vao Queue thanh cong!"<<endl;
}
void pop()
{
	Queue *p = first;
	if(first != NULL)
	{
		first = p->link;
		delete p;
		cout<<"Da xoa phan tu dau ra khoi Queue!"<<endl;
	}else
		cout<<"Queue rong khong the xoa!"<<endl;
}
void xuat()
{
	Queue *p= first;
	while(p != NULL)
	{
		cout<<p->info<<" <-- ";
		p = p->link;
	}
	cout<<endl;
}
int main()
{
	cout<<" --------- Danh sach cac cau lenh --------- "
		<<"\n1. Khoi tao Queue rong"
		<<"\n2. Kiem tra Queue rong"
		<<"\n3. Them 1 phan tu vao Queue"
		<<"\n4. Xoa 1 phan tu khoi Queue"
		<<"\n5. Thoat"<<endl;
	int choice;
	do
	{
		cout<<"Chon lenh can su dung: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			break;
		case 2:
			if(isEmpty() == 0)
				cout<<"Queue rong!"<<endl;
			else
				cout<<"Queue khong rong!"<<endl;
			break;
		case 3:
			int x;
			cout<<"Nhap phan tu can them vao Queue: ";
			cin>>x;
			push(x);
			xuat();
			break;
		case 4:
			pop();
			xuat();
			break;
		case 5:
			cout<<"\nGoodbye.....!";
			break;
		default:
			break;
		}
	}while(choice !=5);
	return 0;
}