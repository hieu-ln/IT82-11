#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
const int MAX=100;
int a[MAX];
int n;
void init(int a[], int &n)
{
	cout<<"Nhap so luong phan tu cua danh sach: ";
	cin>>n;
	for(int i=0;i<n;i++)
		a[i]=rand()%100+1;
	cout<<"Danh sach duoc nhap ngau nhien nhu sau:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
} 
void input(int a[], int &n)
{
	cout<<"Nhap so luong phan tu cua danh sach: ";
	cin>>n;
	cout<<"Nhap cac phan tu cua danh sach:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void output(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void CopyArray(int a[], int b[], int n)
{
	for(int i=0;i<n;i++)
		b[i]=a[i];
}
void insertionSort(int a[], int n)
{
	int i, key, j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
void selectionSort(int a[], int n)
{
	int i, j, min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		swap(a[min],a[i]);
	}
}
void interchangeSort(int a[], int n)
{
	for(int i=0; i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
void bubbleSort(int a[], int n)
{
	int i, j;
	bool haveSwap=false;
	for(i=0;i<n;i++)
	{
		haveSwap=false;
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				haveSwap=true;
			}
			if(haveSwap==false)
				break;
	}
}
void quickSort(int a[], int l, int r)
{
	int x=a[(l+r)/2];
	int i=l, j=r;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]<x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j)
		quickSort(a,l,j);
	if(i<r)
		quickSort(a,i,r);
}
void shift(int a[], int i, int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
}
void heapSort(int a[], int n)
{
	int i=n/2-1;
	while(i>=0)
	{
		shift(a,i,n);
		i--;
	}
	int r=n-1;
	while(r>0)
	{
		swap(a[0],a[r]);
		r--;
		if(r>0)
			shift(a,0,r);
	}
}
int SearchSequence(int a[], int n, int x)
{
	int i=0; 
	while(i<n&&a[i]!=x)
		i++;
	if(i==n)
		return -1;
	else
		return i;
}
int SearchBinary(int a[], int l, int r, int x)
{
	if(r>=l)
	{
		int mid=l+(r-l)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return SearchBinary(a,l,mid-1,x);
		return SearchBinary(a,mid+1,r,x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout<<"--------- BAI TAP 1, CHUONG 3, XEP THU TU va TIM KIEM ---------"<<endl;
	cout<<"0. Khoi tao danh sach ngau nhien"<<endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Xep thu tu danh sach bang SELECTION SORT"<<endl;
	cout<<"4. Xep thu tu danh sach bang INSERTION SORT"<<endl;
	cout<<"5. Xep thu tu danh sach bang BUBBLE SORT"<<endl;
	cout<<"6. Xep thu tu danh sach bang INTERCHANGE SORT"<<endl;
	cout<<"7. Xep thu tu danh sach bang QUICK SORT"<<endl;
	cout<<"8. Xep thu tu danh sach bang HEAP SORT"<<endl;
	cout<<"9. Tim kiem phan tu x bang TIM KIEM TUAN TU"<<endl;
	cout<<"10. Tim kiem phan tu x bang TIM KIEM NHI PHAN"<<endl;
	cout<<"11. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 0:
			init(a,n);
			break;
		case 1:
			input(a,n);
			break;
		case 2:
			cout<<"Danh sach la: "<<endl;
			output(a,n);
			break;
		case 3:
			CopyArray(a,b,n);
			start=clock();
			selectionSort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"DS sau khi xep thu tu voi SELECTION SORT la: "<<endl;
				output(b,n);
			}
			if(duration>0)
				cout<<"Thoi gian SELECTION SORT: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 4:
			CopyArray(a,b,n);
			start=clock();
			insertionSort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"DS sau khi xep thu tu voi INSERTION SORT la: "<<endl;
				output(b,n);
			}
			if(duration>0)
				cout<<"Thoi gian INSERTION SORT: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 5:
			CopyArray(a,b,n);
			start=clock();
			bubbleSort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"DS sau khi xep thu tu voi BUBBLE SORT la: "<<endl;
				output(b,n);
			}
			if(duration>0)
				cout<<"Thoi gian BUBBLE SORT: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 6:
			CopyArray(a,b,n);
			start=clock();
			interchangeSort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"DS sau khi xep thu tu voi INTERCHANGE SORT la: "<<endl;
				output(b,n);
			}
			if(duration>0)
				cout<<"Thoi gian INTERCHANGE SORT: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 7:
			CopyArray(a,b,n);
			start=clock();
			quickSort(b,0,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"DS sau khi xep thu tu voi QUICK SORT la: "<<endl;
				output(b,n);
			}
			if(duration>0)
				cout<<"Thoi gian QUICK SORT: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 8:
			CopyArray(a,b,n);
			start=clock();
			heapSort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"DS sau khi xep thu tu voi HEAP SORT la: "<<endl;
				output(b,n);
			}
			if(duration>0)
				cout<<"Thoi gian HEAP SORT: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 9:
			cout<<"Vui long nhap gia tri x= ";
			cin>>x;
			start=clock();
			i= SearchSequence(a,n,x);
			if(i==-1)
				cout<<"Khong tim thay x="<<x<<" trong mang!"<<endl;
			else
				cout<<"Tim thay x="<<x<<" tai vi tri i="<<i<<endl;
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(duration>0)
				cout<<"\nThoi gian tim kiem TUAN TU la: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 10:
			cout<<"Vui long nhap gia tri x= ";
			cin>>x;
			start=clock();
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			i= SearchBinary(b,0,n,x);
			if(i==-1)
				cout<<"Khong tim thay x="<<x<<" trong mang!"<<endl;
			else
				cout<<"Tim thay x="<<x<<" tai vi tri i="<<i<<endl;
			if(duration>0)
				cout<<"\nThoi gian tim kiem NHI PHAN la: "<<duration*1000000<<" Microseconds"<<endl;
			break;
		case 11:
			cout<<"Goodbye.....!"<<endl;
			break;
		default:
			break;
		}

	}while(choice!=11);
	system("pause");
	return 0;
}