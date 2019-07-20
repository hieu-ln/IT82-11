#include<iostream>
using namespace std;
//Cau 1.1: Khai bao cau truc danh sach
const int MAX=100;
int A[MAX], n;
//Cau 1.2: Thu tuc nhap danh sach
void Input(int A[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap A["<<i<<"]= ";
		cin>>A[i];
	}
}
//Cau 1.3: Thu tuc xuat danh sach ra man hinh
void Output(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;
}
//Cau 1.4: Thu tuc tim mot phan tu trong danh sach
bool Sequential_Search(int A[],int &n,int x)
{
	for(int i=0;i<n;i++)
		if(A[i]==x)
			return true;
	return false;
}
//Cau 1.5: Thu tuc them vao cuoi danh sach
void Insert_last(int A[], int &n, int x)
{
	n++;
	A[n-1]=x;
	Output(A,n);
}
//Cau 1.6: Thu tuc xoa phan tu cuoi danh sach
void Delete_last(int A[], int &n)
{
	n--;
	Output(A,n);
}
//Cau 1.7: Thu tuc xoa phan tu tai vi tri i
void Delete_i(int A[], int &n, int i)
{
	if(i>=0 && i<n)
	{
		for(int j=i;j<n-1;j++)
			A[j]=A[j+1];
		n--;
		Output(A,n);
	}
	return;
}
//Cau 1.8: Tim mot phan tu trong danh sach. Neu tim thay, xoa phan tu do
void Search_and_Delete(int A[],int &n, int x)
{
	int d=0;
	for(int i=0;i<n;i++)
		if(A[i]==x)
		{
			for(int j=i;j<n-1;j++)
				A[j]=A[j+1];
			n--;
			d++;
		}
	if(d==0)
		cout<<"\n khong tim thay gia tri "<<x<<" trong danh sach!";
	Output(A,n);
}
int main()
{
	int A[MAX], n, x, y, z, vt, choice;
	cout<<" --------- DANH SACH --------- "
		<<"\n1. Nhap danh sach"
		<<"\n2. Xuat danh sach"
		<<"\n3. Tim mot phan tu trong danh sach"
		<<"\n4. Them mot phan tu vao cuoi danh sach"
		<<"\n5. Xoa phan tu cuoi danh sach"
		<<"\n6. Xoa phan tu tai vi tri i"
		<<"\n7. Tim mot phan tu trong danh sach. Neu tim thay, xoa phan tu do"
		<<"\n8. Thoat\n";
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\nNhap so luong phan tu: ";
			cin>>n;
			Input(A,n);
			break;
		case 2:
			cout<<"\nDanh sach:\n";
			Output(A,n);
			break;
		case 3:
			cout<<"\nNhap phan tu can tim: ";
			cin>>x;
			if(Sequential_Search(A,n,x))
				cout<<"\nTim thay!";
			else
				cout<<"Khong tim thay!";
			break;
		case 4:
			cout<<"\nNhap gia tri phan tu can them: ";
			cin>>y;
			Insert_last(A,n,y);
			break;
		case 5:
			cout<<"\nDanh sach sau khi xoa phan tu cuoi:\n";
			Delete_last(A,n);
			break;
		case 6:
			cout<<"\nNhap vi tri can xoa: ";
			cin>>vt;
			Delete_i(A,n,vt);
			break;
		case 7:
			cout<<"\nNhap gia tri can xoa: ";
			cin>>z;
			Search_and_Delete(A,n,z);
			break;
		case 8:
			cout<<"\nGoodbye.....!\n";
			break;
		}
	}while(choice>0&&choice<9);
	cout<<endl;
	system("pause");
	return 0;
}