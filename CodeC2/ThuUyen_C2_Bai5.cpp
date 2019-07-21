#include <iostream>
using namespace std;
const int MAX=100;
int a[MAX];
int sp;
int x;
void init(int a[], int &sp)
{
	sp = -1;
	cout<<"\nDa khoi tao Stack rong thanh cong!"<<endl;
}
void pop(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		cout<<"\nDa lay phan tu ra khoi Stack thanh cong"<<endl;
	}else
		cout<<"\nStack rong khong the lay!"<<endl;
}
void push(int a[], int &sp, int &x)
{
	cout<<"Nhap phan tu x = ";
	cin>>x;
	if(sp < MAX)
	{
		a[++sp] = x;
		cout<<"\nDa them phan tu x vao Stack thanh cong!"<<endl;
	}else
		cout<<"\nStack da day khong the them"<<endl;
}
void isEmpty(int a[], int sp)
{
	if(sp == -1)
		cout<<"\nStack rong!"<<endl;
	else
		cout<<"\nStack khong rong!"<<endl;
}
void isFull(int a[], int sp)
{
	if(sp == MAX -1)
		cout<<"\nStack day!"<<endl;
	else
		cout<<"\nStack chua day!"<<endl;
}
int main(){
	cout<<" --------- DANH SACH CAU LENH --------- "
		<<"\n1. Khoi tao Stack rong"
		<<"\n2. Kiem tra Stack rong"
		<<"\n3. Kiem tra Stack day"
		<<"\n4. Them 1 phan tu vao Stack"
		<<"\n5. Xoa 1 phan tu khoi Stack"
		<<"\n6. Thoat"<<endl;
	int choice;
	do{
		cout<<"\nVui long nhap so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init(a,sp);
			break;
		case 2:
			isEmpty(a,sp);
			break;
		case 3:
			isFull(a,sp);
			break;
		case 4:
			push(a,sp,x);
			break;
		case 5:
			pop(a,sp,x);
			break;
		case 6:
			cout<<"\nGoodbye.....!\n";
			break;
		default:
			break;
		}
	}while(choice != 6);
	return 0;
}