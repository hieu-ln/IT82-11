#include <iostream>
using namespace std;
// Bai 1.1
#define MAX 100
int a[MAX];
int n;
// Bai 1.2
void Nhap(int a[], int &n)
{
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
// Bai 1.3
void Xuat(int a[], int n)
{
	cout<<"Mang: ";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}
// Bai 1.4
void InsertionSort(int a[], int n)
{
	int x,j;
	for(int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0<=j && x<a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
// Bai 1.5
void SelectionSort(int a[], int n)
{
	int min_pos,i,j;
	for(i = 0; i<n;i++)
	{
		min_pos=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min_pos])
				min_pos=j;
		swap(a[min_pos],a[i]);
	}
}
// Bai 1.6
void InterchangeSort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j = i+1; j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
// Bai 1.7
void BubbleSort(int a[], int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = n-1;j>i;j--)
			if(a[j-1]>a[j])
				swap(a[j],a[j-1]);
}
// Bai 1.8
void QuickSort(int a[], int left,int right)
{
	int x = a[(left+right)/2];
	int i = left;
	int j = right;
	while(i<j)
	{
		while(a[i]<x)i++;
		while(a[j]>x)j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(left<j)
		QuickSort(a,left,j);
	if(i<right)
		QuickSort(a,i,right);
}
// Bai 1.9
void shift(int a[], int i, int n)
{
	int j = 2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j] < a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a,j,n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n/2;
	while(i>=0)
	{
		shift(a,i,n-1);
		i--;
	}
	int right=n-1;
	while(right>0)
	{
		swap(a[0],a[right]);
		right--;
		if(right>0)
			shift(a,0,right);
	}
}
// Bai 1.10 TIM KIEM TUAN TU
int Search(int a[], int n, int x)
{
	int i =0;
	while(i<n && a[i] != x)
		i++;
	if(i<n)
		return i;
	return -1;
}
// Bai 1.11 TIM KIEM NHI PHAN
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right=n-1,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)return mid;
		if(x>a[mid])left=mid+1;
		else right = mid-1;
	}
	return -1;
}
int main()
{
	int chon,x;
	cout<<"-DANH SACH CAC CAU LENH-"<<endl;
	cout<<"1. Nhap danh sach phan tu"<<endl;
	cout<<"2. Xuat danh sach phan tu"<<endl;
	cout<<"3. InsertionSort"<<endl;
	cout<<"4. SelectionSort"<<endl;
	cout<<"5. InterchangeSort"<<endl;
	cout<<"6. BubbleSort"<<endl;
	cout<<"7. QuickSort"<<endl;
	cout<<"8. HeapSort"<<endl;
	cout<<"9. Tim kiem tuan tu"<<endl;
	cout<<"10. Tim kiem nhi phan"<<endl;
	cout<<"11. Thoat"<<endl;
	do
	{
		cout<<"Chon cau lenh can su dung: ";
		cin>>chon;
		switch(chon)
		{
		case 1:
			Nhap(a,n);
			Xuat(a,n);
			break;
		case 2:
			Xuat(a,n);
			break;
		case 3:
			InsertionSort(a,n);
			Xuat(a,n);
			break;
		case 4:
			SelectionSort(a,n);
			Xuat(a,n);
			break;
		case 5:
			InterchangeSort(a,n);
			Xuat(a,n);
			break;
		case 6:
			BubbleSort(a,n);
			Xuat(a,n);
			break;
		case 7:
			QuickSort(a,0,n-1);
			Xuat(a,n);
			break;
		case 8:
			HeapSort(a,n);
			Xuat(a,n);
			break;
		case 9:
			cout<<"Nhap phan tu can tim: ";
			cin>>x;
			if(Search(a,n,x) != -1)
				cout<<"Tim thay phan tu x = "<<x<<" tai vi tri "<<Search(a,n,x)<<endl;
			else
				cout<<"Khong tim thay phan tu x = "<<x<<endl;
			break;
		case 10:
			cout<<"Nhap phan tu can tim: ";
			cin>>x;
			if(BinarySearch(a,n,x) != -1)
				cout<<"Tim thay phan tu x = "<<x<<" tai vi tri "<<BinarySearch(a,n,x)<<endl;
			else
				cout<<"Khong tim thay phan tu x = "<<x<<endl;
			break;
		}
	}while(chon!=11);
	return 0;
}