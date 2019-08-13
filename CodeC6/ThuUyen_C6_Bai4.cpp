#include<iostream>
#include<stdio.h>
#include <fstream>
#include<iomanip>
using namespace std;

#define max 20
int a[max][max];
int n;
char vertex[max];
void initGraph(){
	n=0;
}
void inputGraphFromText(){
	string line;
	ifstream myfile ("mtts1.txt");
	if (myfile.is_open())
	{
		myfile>>n;
		for(int i=0; i<n; i++)
			myfile>>vertex[i];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				myfile>>a[i][j];
		}
	}
}
void inputGraph()
{
	cout<<"nhap so dinh: "; cin>>n;
	cout<<"nhap ten dinh: ";
	for(int i=0; i<n; i++)
		cin>>vertex[i];
	for(int i=0; i<n; i++)
	{
		cout<<"nhap vao dong thu: "<<i+1<<": ";
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}
}
void outputGraph(){
	cout<<setw(6)<<left;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<a[i][j]<<setw(6)<<left;
		cout<<endl;
	}
}
int e1[max];
int e2[max];
int wE[max];
int nE=0;

int t1[max];
int t2[max];
int wT[max]; 

int nT=0;

int tonTai(int d, int D[], int nD)
{
	for(int i=0; i<nD; i++)
		if(D[i]==d)
			return 1;
	return 0;
}

void xoaVTE(int i)
{
	for(int j=i; j<nE; j++)
	{
		e1[j]=e1[j+1];
		e2[j]=e2[j+1];
		wE[j]=wE[j+1];
	}
	nE--;
}

void xoaCanh(int u, int v)
{
	for(int i=0; i<nE; i++)
		if(e1[i]==u && e2[i]==v)
		{
			xoaVTE(i);
			break;
		}
}
void prim(int s)
{
	int u=s, min, i, d1, d2;
	while(nT<n-1)
	{
		for(int v=0; v<n; v++)
			if(a[u][v]!=0)
				if(tonTai(v, t2, nT)==0)
				{
					e1[nE]=u;
					e2[nE]=v;
					wE[nE]=a[u][v];
					nE++;
				}
		for (i=0; i<nE; i++)
			if(tonTai(e2[i], t2, nT)==0)
			{
				min=wE[i];
				d1=e1[i];
				d2=e2[i];
				break;
			}
		for (i=0; i<nE; i++)
			if(tonTai(e2[i], t2, nT)==0)
				if(min>wE[i])
				{
					min=wE[i];
					d1=e1[i];
					d2=e2[i];
				}
		t1[nT]=d1;
		t2[nT]=d2;
		wT[nT]=a[d1][d2];
		a[d1][d2]=0;
		a[d2][d1]=0;
		nT++;
		xoaCanh(d1, d2);
		u=d2;
	}
}
void output(bool vertexName)
{
	int tong=0;
	for(int i=0; i<nT; i++)
	{
		if(vertexName)
			cout<<endl<<"("<<vertex[t1[i]]<<","<<vertex[t2[i]]<<") ="<<wT[i];
		else
			cout<<endl<<"("<<t1[i]<<","<<t2[i]<<") ="<<wT[i];
		tong+=wT[i];
	}
	cout<<"\n Tong = "<<tong;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout<<"-------------------menu-------------------"<<endl;
	cout<<"1. khoi tao ma tran ke rong"<<endl;
	cout<<"2. nhap ma tran ke tu file"<<endl;
	cout<<"3. nhap ma tran ke"<<endl;
	cout<<"4. xuat ma tran ke"<<endl;
	cout<<"5. tim cay khung toi tieu bang Prim"<<endl;
	cout<<"6. thoat."<<endl;
	do{
		cout<<"\nChon so: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				initGraph();
				cout<<"khoi tao xong";
				break;
			case 2:
				inputGraphFromText();
				cout<<"nhap ma tran thanh cong";
				outputGraph();
				break;
			case 3:
				inputGraph();
				break;
			case 4:
				outputGraph();
				break;
			case 5:
				cout<<"nhap dinh xuat phat: "; cin>>x;
				prim(x);
				cout<<"cay khung toi tieu";
				output(true);
				break;
			case 6:
				cout<<"bye..............";
				break;
			default:
				break;
		}
	}while(choice!=6);

	system("pause");
	return 0;
}