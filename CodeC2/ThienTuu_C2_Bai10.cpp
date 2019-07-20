//#include <iostream>
//#include <stdio.h>
//using namespace std;
//struct Stack
//{
//	int info;
//	Stack *link;
//};
//Stack *sp;
//void init()
//{
//	sp = NULL;
//	cout<<"Da khoi tao Stack rong thanh cong!"<<endl;
//}
//int isEmpty()
//{
//	if(sp == NULL)
//		return 0;
//	else return 1;
//}
//void push(int x)
//{
//	Stack *q = new Stack;
//	q->info = x;
//	q->link = NULL;
//	if(sp == NULL)
//		sp = q;
//	else{
//		Stack *p = sp;
//		while(p->link != NULL)
//			p = p->link;
//		p->link = q;
//	}
//	cout<<"Da them phan tu x = "<<x<<" vao Stack thanh cong!"<<endl;
//}
//void pop()
//{
//	Stack *p = sp;
//	Stack *q = new Stack;
//	while(p->link != NULL)
//	{
//		q = p;
//		p = p->link;
//	}
//	if(p != sp)
//		q->link = NULL;
//	else
//		sp = NULL;
//	delete p;
//	cout<<"Da lay phan tu cuoi ra khoi Stack thanh cong!"<<endl;
//}
//void xuat()
//{
//	Stack *p = sp;
//	while(p != NULL)
//	{
//		cout<<p->info<<" <-- ";
//		p = p->link;
//	}
//	cout<<endl;
//}
//void chuyendoi(int n)
//{
//	Stack *p = new Stack;
//	int du;
//	while(n != 0)
//	{
//		du = n%2;
//		push(du);
//		n/=2;
//	}
//	xuat();
//}
//int main()
//{
//	cout<<"-Danh sach cau lenh-"<<endl;
//	cout<<"1. Khoi tao Stack rong"<<endl;
//	cout<<"2. Kiem tra Stack rong"<<endl;
//	cout<<"3. Them 1 phan tu vao Stack"<<endl;
//	cout<<"4. Lay 1 phan tu ra khoi Stack"<<endl;
//	cout<<"5. Chuyen doi he nhi phan Stack"<<endl;
//	cout<<"6. Thoat"<<endl;
//	int chon;
//	do
//	{
//		cout<<"Chon cau lenh: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init();
//			break;
//		case 2:
//			if(isEmpty() == 0)
//				cout<<"Stack rong!"<<endl;
//			else
//				cout<<"Stack khong rong!"<<endl;
//			break;
//		case 3:
//			int x;
//			cout<<"Nhap phan tu can them vao Stack: ";
//			cin>>x;
//			push(x);
//			xuat();
//			break;
//		case 4:
//			pop();
//			xuat();
//			break;
//		case 5:
//			int n;
//			cout<<"Nhap phan tu can doi: ";
//			cin>>n;
//			chuyendoi(n);
//			break;
//		}
//	}while(chon != 6);
//	return 0;
//}