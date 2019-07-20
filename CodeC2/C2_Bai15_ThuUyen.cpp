#include<iostream>
using namespace std;
const int MAX=100;
void Nhap(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap phan tu thu "<<i+1<<": ";
		cin>>a[i];
	}
}
//Cau 15.1. Xuat cac phan tu thuoc tap hop
void Xuat(int a[], int n)
{
	cout<<" { ";
	for(int i=0;i<n;i++)
		if(i!=n-1)
			cout<<a[i]<<", ";
		else
			cout<<a[i]<<" }";
}
bool Tim(int a[], int n, int x)
{
	int i=0;
	while((i<n)&&(a[i]!=x))
		i++;
	if(i==n)
		return false;
	return true;
}
void Them_pt(int a[], int n, int x)
{
	n++;
	a[n-1]=x;
}
//Cau 15.2: Xuat cac phan tu thuoc tap hop giao
void Giao(int a[], int n1, int b[], int n2, int c[])
{
	int tam=0;
	for(int i=0;i<n1;i++)
		if(Tim(b,n2,a[i])==true)
		{
			Them_pt(c,tam,a[i]);
			tam++;
		}
	if(tam!=0)
	{
		cout<<"\nGiao cua A va B la:\nC = ";
		Xuat(c,tam);
	}
	else
		cout<<"\nA va B khong giao nhau!\n";
}
//Cau 15.3: Xuat danh sach phan bu 
void PhanBu(int a[], int n1, int b[], int n2, int c[])
{
	int tam=0;
	for(int i=0;i<n1;i++)
		if(Tim(b,n2,a[i])==false)
		{
			Them_pt(c,tam,a[i]);
			tam++;
		}
	if(tam!=0)
	{
		cout<<"\nC =";
		Xuat(c,tam);
	}
	else
		cout<<"\nCac phan tu trong A co gia tri bang cac phan tu trong B\n";
}
int main()
{
	int A[MAX], B[MAX], nA, nB, C[MAX], choice;
	cout<<"\nNhap so phan tu cua tap hop A: ";
	cin>>nA;
	Nhap(A,nA);
	cout<<"\nNhap so phan tu cua tap hop B: ";
	cin>>nB;
	Nhap(B,nB);
	system("cls");
	cout<<"\n --------- TAP HOP --------- "
		<<"\n1. Xuat cac phan tu thuoc tap hop A va B"
		<<"\n2. Xuat cac phan tu thuoc tap giao cua A va B"
		<<"\n3. Xuat danh sach phan bù cua A va B"
		<<"\n4. Thoat\n";
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\nA=";
			Xuat(A,nA);
			cout<<"\nB=";
			Xuat(B,nB);
			break;
		case 2:
			Giao(A,nA,B,nB,C);
			break;
		case 3:
			cout<<"\nPhan bu cua A trong B:\n";
			PhanBu(B,nB,A,nA,C);
			cout<<"\nPhan bu cua B trong A:\n";
			PhanBu(A,nA,B,nB,C);
			break;
		case 4:
			cout<<"Goodbye.....!";
			break;
		default:
			break;
		}
	}while(choice>0&&choice<5);
	cout<<endl;
	system("pause");
	return 0;
}