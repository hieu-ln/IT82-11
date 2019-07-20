//#include <iostream>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int sp;
//int x;
//void init(int a[], int &sp)
//{
//	sp = -1;
//	cout<<"Da khoi tao Stack rong thanh cong!"<<endl;
//}
//void pop(int a[], int &sp, int &x)
//{
//	if(sp != -1)
//	{
//		x = a[sp--];
//		cout<<"Da lay phan tu ra khoi Stack thanh cong"<<endl;
//	}else
//		cout<<"Stack rong khong the lay!"<<endl;
//}
//void push(int a[], int &sp, int &x)
//{
//	cout<<"Nhap phan tu x = ";
//	cin>>x;
//	if(sp < MAX)
//	{
//		a[++sp] = x;
//		cout<<"Da them phan tu x vao Stack thanh cong!"<<endl;
//	}else
//		cout<<"Stack da day khong the them"<<endl;
//}
//void isEmpty(int a[], int sp)
//{
//	if(sp == -1)
//		cout<<"Stack rong!"<<endl;
//	else
//		cout<<"Stack khong rong!"<<endl;
//}
//void isFull(int a[], int sp)
//{
//	if(sp == MAX -1)
//		cout<<"Stack day!"<<endl;
//	else
//		cout<<"Stack chua day!"<<endl;
//}
//int main(){
//	cout<<"-DANH SACH CAU LENH-"<<endl;
//	cout<<"1. Khoi tao Stack rong"<<endl;
//	cout<<"2. Kiem tra Stack rong"<<endl;
//	cout<<"3. Kiem tra Stack day"<<endl;
//	cout<<"4. Them 1 phan tu vao Stack"<<endl;
//	cout<<"5. Xoa 1 phan tu khoi Stack"<<endl;
//	cout<<"6. Thoat"<<endl;
//	int chon;
//	do{
//		cout<<"Nhap lenh ban can su dung: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init(a,sp);
//			break;
//		case 2:
//			isEmpty(a,sp);
//			break;
//		case 3:
//			isFull(a,sp);
//			break;
//		case 4:
//			push(a,sp,x);
//			break;
//		case 5:
//			pop(a,sp,x);
//			break;
//		}
//	}while(chon != 6);
//	return 0;
//}