#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

//khai bao ma tran bang mang hai chieu
# define MAX 20
int a[MAX][MAX];
int n;// so dinh cua do thi
char vertex[MAX];  // ten dinh

void InitGraph()
{
	n=0;
}

void inputGraphFromTxt()
{
	string line;
	ifstream mylife("mtts.txt");
	if(mylife.is_open())
	{
		mylife >>n;
		for(int i=0; i<n;i++)
			mylife>>vertex[i];
		for(int i=0; i<n; i++)
		{
			for (int j=0;j<n; j++)
				mylife>>a[i][j];
		}
	}
}

// nhap ma tran ke cua do thi
void intGraph()
{
	cout<<"Nhap so dinh cua do thi n:";
	cin>>n;
	cout<<"Nhap ten dinh : ";
	for(int i=0; i<n;i++)
		cin>>vertex[i];
	for (int i=0;i<n; i++)
	{
		cout<<"Nhap vao dong thu"<<i+1<<" : ";
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}
}

// xuat ma tran ke cua do thi
void outGraph()
{
	cout<<setw(5)<<left;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<setw(5)<<left;
		cout<<endl;
	}
}

// khoi tao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE=0;  // so phan tu tap E

//khoi bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; // so phan tu tap T

int TonTai(int d, int D[], int nD)
{
	for(int i=0;i<nD; i++)
		if(D[i]==d)
			return 1;
	return 0;
}

void XoaViTriE(int i)
{
	for(int j=i;j<nE; j++)
	{
		E1[j]=E1[j+1];
		E2[j]=E2[j+1];
		wE[j]=wE[j+1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i=0; i<nE;i++)
		if(E1[i]==u&&E2[i]==v)
		{
			XoaViTriE(i);
			break;
		}
}

void Prim(int s) // s la dinh bat dau
{

	int u=s,min, i, d1, d2;
	while(nT<n-1)
	{
		for(int v=0; v<n;v++)
			if(a[u][v]!=0)
				if(TonTai(v,T2,nT)==0)
				{
					E1[nE]=u;
					E2[nE]=v;
					wE[nE]=a[u][v];
					nE++;
				}
			for (int i=0;i<nE; i++)
				if(TonTai(E2[i],T2,nT)==0)
				{
					min=wE[i];
		            d1=E1[i];
			        d2=E2[i];
			        break;
				}
			for (i=0;i<nE;i++)
				if(TonTai(E2[i],T2,nT)==0)
					if(min>wE[i])
					{
						min=wE[i]; 
						d1=E1[i];
						d2=E2[i];
					}
			T1[nT]=d1;
			T2[nT]=d2;
			wT[nT]=a[d1][d2];
			a[d1][d2]=0;
			a[d2][d1]=0;
			nT++;
			XoaCanhE(d1,d2);
			u=d2;
		}
}

void output(bool VertexName)
{
	int tong=0;
	for(int i=0;i<nT;i++)
	{
		if(VertexName)
			cout<<endl<<"("<<vertex[T1[i]]<<","<<vertex[T2[i]]<<")="<<wT[i];
		else
			cout<<endl<<"("<<T1[i]<<","<<T2[i]<<")="<<wT[i];
		tong+=wT[i];
	}
	cout<<"\n Tong="<<tong;
}
int main()
{
	int choice,x,i;
	system("cls");
	cout<<" ---------- BAI 4, CHUONG 6 ----------"<<endl;
	cout<<"1. Khoi tao MA TRAN KE rong "<< endl;
	cout<<"2. Nhap MA TRAN KE tu file text "<< endl;
	cout<<"3. Nhap Ma Tran Ke"<< endl;
	cout<<"4. Xuat Ma Tran Ke"<< endl;
	cout<<"5. Tim Cay Khung Toi Thieu bang PRIM "<<endl;
	cout<<"6. Thoat"<<endl;
	do 
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice; 
		switch(choice)
		{
		case 1:
			InitGraph();
				cout<<"Khoi tao MA TAN KE rong thanh cong!\n";
			break ; 
		case 2:
			inputGraphFromTxt();
			cout<<"Ban vua nhap MA TAN KE tu file: \n";
			outGraph();
			break ; 
		case 3:
			intGraph();
			break ; 
		case 4:
			outGraph();
			break ; 
		case 5:
			cout<<"Vui long nhap dinh xuat phat: ";
			cin>>x;
			Prim(x);
			cout<<" Cay khung toi thieu voi PRIM: "<<endl; 
			output(true );
			break ; 
		case 6: 
			cout<<"Goodbye!" <<endl; 
			break; 
		default:
			break ; 
		}
	} while (choice!=6);
	system("pause");
	return 0;
}