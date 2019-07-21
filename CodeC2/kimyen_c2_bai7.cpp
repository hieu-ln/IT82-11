//#include <iostream>
//using namespace std;
//#define M 100
//void init(int a[], int &front, int &rear)
//{
//	front=-1;
//	rear=-1;
//}
//int isempty(int a[], int &front, int &rear)
//{
//	if(front==rear)
//		return 1;
//	return 0;
//}
//int isfull(int a[], int &front, int &rear)
//{
//	if((front== 0 && rear==M-1) || (front-rear==1))
//		return 1;
//	return 0;
//}
//int push(int a[], int &front, int &rear, int x)
//{
//	if(rear-front==-1)
//		return 0;
//	else
//	{
//		if(front==-1)
//			front=0;
//		if(rear==M-1)
//		{	
//			for(int i=front;i<=rear;i++)
//			{
//				a[i-front]=a[i];
//			}
//			rear=M-1-front;
//			front=0;
//			}
//		a[++rear]=x;
//	}
//	return 0;
//}
//int pop(int a[], int &front, int &rear, int x)
//{
//	if(front==-1)
//		return 0;
//	else
//	{
//		x=a[front++];
//		if(front>rear)
//		{
//			front=-1;
//			rear=-1;
//		}
//		return 1;
//	}
//	return 0;
//}
//void output(int a[M] , int f, int r)
//{ 
//	cout<<"f="<<f<<"\t r="<<r<<endl;
//	if(f<=r &&f!=-1)
//	{
//		cout<<"<-- ";
//		for(int i=f;i<r+1;i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<"<--"<<endl;
//	}
//
//}
//int main()
//{
//	int a[M];
//	int chon, f, x, i, r;
//	cout<<"------------menu-----------";
//	cout<<"1.Khoi tao queue rong"<<endl;
//	cout<<"2.them phan tu vao queue"<<endl;
//	cout<<"3.lay phan tu ra khoi queue"<<endl;
//	cout<<"4.kiem tra queue co day  hay khong"<<endl;
//	cout<<"5.kiem tra queue co rong hay khong"<<endl;
//	cout<<"6.xuat stack"<<endl;
//	cout<<"7.Thoat---"<<endl;
//	do
//	{
//		cout<<"\nnhap so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init(a,f,r);
//			cout<<"ban vua tao thanh cong!\n";
//			break;
//		case 2:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			push(a,f,r,x);
//			cout<<"stack sau khi xep la: ";
//			output(a,f,r);
//			break;
//		case 3:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			i=pop(a,f,r,x);
//			cout<<"phan tu lay ra khoi Queue la x= "<<x<<endl;
//			cout<<"queue sau khi lay ra: ";
//			output(a,f,r);
//			break;
//		case 4:
//			i=isfull(a,f,r);
//			if(i==0)
//				cout<<"queue chua day"<<endl;
//			else
//				cout<<"queue da day"<<endl;
//			break;
//		case 5:
//			i=isempty(a,f,r);
//			if(i==0)
//				cout<<"queue khong rong"<<endl;
//			else
//				cout<<"queue rong"<<endl;
//			break;
//		case 6:
//			cout<<"quque cua hien tai: ";
//			output(a,f,r);
//			break;
//		case 7: 
//			cout<<"----^^bye^^---";
//		default:
//			break;
//		}
//	}while(chon!=7);
//	system("pause");
//	return 0;
//}