//#include <iostream>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int front,rear;
//int x;
//void init(int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//	cout<<"Khoi tao Queue rong thanh cong!"<<endl;
//}
//void push(int a[], int &front , int &rear, int x)
//{
//	if((front - rear) == MAX - 1)
//		cout<<"Hang doi day!"<<endl;
//	else{
//		if(front == -1)
//			front = 0;
//		if(rear == MAX - 1)
//		{
//			for(int i = front;i<=rear;i++)
//				a[i-front] = a[i];
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		cout<<"Da them phan tu vao hang doi thanh cong!"<<endl;
//	}
//}
//void pop(int a[], int &front, int &rear, int x)
//{
//	if(front == -1)
//		cout<<"Hang doi rong!"<<endl;
//	else{
//		x = a[front++];
//		if(front > rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		cout<<"Da lay 1 phan tu ra khoi Queue thanh cong!"<<endl;
//	}
//}
//void isEmpty(int a[],int front)
//{
//	if(front == -1)
//		cout<<"Hang doi rong!"<<endl;
//	else
//		cout<<"Hang doi khong rong!"<<endl;
//}
//void isFull(int a[], int front, int rear)
//{
//	if((rear - front) == MAX - 1)
//		cout<<"Hang doi day!"<<endl;
//	else
//		cout<<"Hang doi chua day!"<<endl;
//}
//int main(){
//	cout<<"-DANH SACH CAU LENH-"<<endl;
//	cout<<"1. Khoi tao Queue rong"<<endl;
//	cout<<"2. Kiem tra Queue rong"<<endl;
//	cout<<"3. Kiem tra Queue day"<<endl;
//	cout<<"4. Them 1 phan tu vao Queue"<<endl;
//	cout<<"5. Xoa 1 phan tu khoi Queue"<<endl;
//	cout<<"6. Thoat"<<endl;
//	int chon;
//	do{
//		cout<<"Nhap lenh ban can su dung: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init(a,front,rear);
//			break;
//		case 2:
//			isEmpty(a,front);
//			break;
//		case 3:
//			isFull(a,front,rear);
//			break;
//		case 4:
//			cout<<"Nhap phan tu x can them: ";
//			cin>>x;
//			push(a,front,rear,x);
//			break;
//		case 5:
//			pop(a,front, rear,x);
//			break;
//		}
//	}while(chon != 6);
//	return 0;
//}