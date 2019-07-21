//#include <iostream>
//using namespace std;
//const int M=100;
//int a[M];
//int sp;
//void init(int a[], int &sp)
//{
//	sp=-1;
//}
//int isempty(int a[], int sp)
//{
//	if(sp==-1)
//		return -1;
//	return 0;
//}
//int isfull(int a[], int sp)
//{
//	if(sp==M-1)
//		return -1;
//	return 0;
//}
//int push(int a[], int sp, int x)
//{
//	if(sp<M-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
//int pop(int a[], int &sp, int &x)
//{
//	if(sp!=-1)
//	{
//		x=a[sp--];
//		return x;
//	}
//	return -1;
//}
//void output(int a[M] , int n)
//{
//	for(int i=0;i<n;i++)
//	    cout<<a[i]<<" ; ";
//	cout<<endl;
//}
//int main()
//{
//	int a[M];
//	int chon, sp, x, i;
//	cout<<"------------menu-----------";
//	cout<<"1.Khoi tao STAck rong"<<endl;
//	cout<<"2.them phan tu vao cay"<<endl;
//	cout<<"3.lay phan tu ra khoi stack"<<endl;
//	cout<<"4.kiem tra stack co rong hay khong"<<endl;
//	cout<<"5.kiem tra stack co day hay khong"<<endl;
//	cout<<"6.xuat stack"<<endl;
//	cout<<"7.Thoat---"<<endl;
//	do
//	{
//		cout<<"\nnhap so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init(a,sp);
//			cout<<"ban vua tao thanh cong!\n";
//			break;
//		case 2:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			push(a,sp,x);
//			cout<<"stack sau khi xep la: ";
//			output(a,sp);
//			break;
//		case 3:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			i=pop(a,sp,x);
//			cout<<"phan tu lay ra khoi stack la x= "<<x<<endl;
//			cout<<"stack sau khi lay ra: ";
//			output(a,sp);
//			break;
//		case 4:
//			i=isfull(a,sp);
//			if(i==0)
//				cout<<"stack chua day"<<endl;
//			else
//				cout<<"stack da day"<<endl;
//			break;
//		case 5:
//			i=isempty(a,sp);
//			if(i==0)
//				cout<<"stack khong rong"<<endl;
//			else
//				cout<<"stack rong"<<endl;
//			break;
//		case 6:
//			cout<<"stack cua hien tai: ";
//			output(a,sp);
//			break;
//		case 7:
//			cout<<"----^^bye^^---";
//			break;
//			default:
//			break;
//		}
//	}while(chon!=7);
//	system("pause");
//	return 0;
//}