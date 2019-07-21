//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//#define MAX 100
//int a[MAX];
//int n;
//void input (int a[],int &n)
//{
//	cout<<"Nhap danh sack ";
//	cin>>n;
//	cout<<"Nhap phan tu ";
//	for (int i=0;i<n;i++)
//	{
//		cout<<"a[ "<<i<<"]";
//		cin>>a[i];
//	}
//}
//void output (int a[], int n)
//{
//	for (int i=0;i<n;i++)
//		cout<<a[i]<<"\t";
//		cout<<endl;
//}
//int search (int a[],int n, int x)
//{
//	int i=0;
//	while ((i<n) && (a[i]=x))
//	{	
//		if(i==n)
//			return -1;
//		i++;
//	}
//	return i;
//}
//int addlast ( int a[], int &n,int x)
//{
//	if(n<MAX)
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	else
//		return 0;
//}
//int deletelast ( int a[], int &n)
//{
//	if(n>0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int xoathu_i( int a[],int &n , int i)
//{
//	if ( i>= 0 && i<n)
//	{
//		for( int j=i;j<n-1;j++)
//		{
//			a[j]=a[j+1];
//		}
//		n--;
//		return 1;
//	}return 0;
//}
//int deleteandsearch (int a[] , int &n, int x)
//{
//	for (int i=0;i<n;i++)
//		if(a[i]==x)
//		{
//			delete (a,n,i);
//			return 1;
//		}
//	return 0;
//}
//int main()
//{
//	int choice =0;
//	int x,i;
//	system("cls");
//	cout<<"............... Bai Tap 1,Chuong 2,Danh Sack Dac ..........................";
//	cout<<"1.Nhap danh sack "<<endl;
//	cout<<"2.Xuat danh sack "<<endl;
//	cout<<"3.Tim mot phan tu x trong danh sack "<<endl;
//	cout<<"4.Them mot phan tu cui danh sack  "<<endl;
//	cout<<"5.Xoa mot phan tu cui danh sack   "<<endl;
//	cout<<"6.Xoa mot phan tu tai vi tri i"<<endl;
//	cout<<"7.Tim mot phan tu tai vi tri x va xoa neu co "<<endl;
//	cout<<"8.Thoat "<<endl;
//	do
//	{
//		cout<<"vui long chon so de thuc hien ";
//		cin>>choice;
//		switch (choice)
//		{
//		case 1:
//			input (a,n);
//			cout<<"Bn vua nhap danh sack thanh cong ";
//			break;
//		case 2:
//			output(a,n);
//			cout<<"xuat danh sack ra man hinh ";
//			break;
//		case 3:
//			int x;
//			cout<<"Nhap phan tu can tim trong danh sack ";
//			cin>>x;
//			if(search(a,n,x)==-1)
//				cout<<"tim khong thay "<<endl;
//			else
//				cout<<"phan tu can tim la :"<<endl;
//			break;
//		case 4:
//			cout<<"vui long nhap x can them vao cuoi ds";
//			cin>>x;
//			i= addlast(a,n,x);
//			if(i==0)
//				cout<<"danh sack da day, k the them";
//			else
//			{
//				cout<<"Da them phan tu x="<<i<<"vao cui danh sack"<<endl;
//				cout<<"danh sack sau khi them la ";
//				output(a,n);
//			}
//			break;
//		case 5:
//			i=deletelast(a,n);
//			if(i>0)
//			{
//				cout<<"xoa thanh cong "<<endl;
//				cout<<"danh sach sau xoa thanh cong la :";
//				output(a,n);
//			}
//			else
//				cout<<"danh sach dang rong, k co phan tu nao "<<endl;
//			break;
//		case 6:
//			cout<<"vui long nhap vi tri can xoa i =";
//			cin>>i;
//			i=xoathu_i(a,n,i);
//			if(i==1)
//			{
//				cout<<"xoa thanh cong !"<<endl;
//				cout<<"danh sach sau khi xoa la :"<<endl;
//				output(a,n);
//			}
//			else
//				cout<<"k co phan tu nao de xoa ";
//			break;
//		case 7:
//			cout<<"ZUi long nhap gia tru can xoa x=";
//			cin>>x;
//			i=deleteandsearch(a,n,x);
//			if(i==1)
//			{
//				cout<<"xoa thanh cong phan tu cos gia tri x="<<x<<endl;
//				cout<<"danh sach sau khi xoa la "<<endl;
//				output(a,n);
//			}
//			else
//				cout<<"khong co phan tu nao de xoa !"<<endl;
//			break;
//		case 8:
//			cout<<"goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}
//	while ( choice !=0);
//	system("pause");
//	return 0;
//
//
//}