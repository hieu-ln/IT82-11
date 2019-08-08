//#include<iostream>
//#include<stdio.h>
//#include<fstream>
//#include<iomanip>
//using namespace std;
////khai bao ma tran bang mang hai chieu
//#define MAX 20
//int a[MAX][MAX];
//int n;//so dinh cua do thi
//char vertex[MAX];//ten dinh
//void InitGraph()
//{
//	n=0;
//}
//void InputGraphFromText()
//{
//	string line;
//	ifstream myfile("BT4.txt");
//	if(myfile.is_open())
//	{
//		myfile>>n;
//		for(int i=0;i<n;i++)
//			myfile>>vertex[i];
//		for(int i=0;i<n;i++)
//			for(int j=0;j<n;j++)
//				myfile>>a[i][j];
//	}
//}
////nhap ma tran ke cua do thi
//void inputGraph()
//{
//	cout<<"Nhap so dinh cua do thi n: ";
//	cin>>n;
//	cout<<"\tNhap ten dinh: ";
//	for(int i=0;i<n;i++)
//		cin>>vertex[i];
//	for(int i=0;i<n;i++)
//	{
//		cout<<"\nNhap vaop dong thu "<<i+1<<": ";
//		for(int j=0;j<n;j++)
//			cin>>a[i][j];
//	}
//}
////xuat ma tran ke cua do thi
//void outputGraph()
//{
//	cout<<setw(5)<<left;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			cout<<a[i][j]<<setw(5)<<left;
//		cout<<endl;
//	}
//}
////khai bao tap E
//int E1[MAX];
//int E2[MAX];
//int wE[MAX];
//int nE=0;//so phan tu tap
////khai bao tap T
//int T1[MAX];
//int T2[MAX];
//int wT[MAX];
//int nT=0;//so phan tu tap T
//int TonTai(int d, int D[], int nD)
//{
//	for(int i=0;i<nD;i++)
//		if(D[i]==d)
//			return 1;
//	return 0;
//}
//void XoaViTriE(int i)
//{
//	for(int j=i;j<nE;j++)
//	{
//		E1[j]=E1[j+1];
//		E2[j]=E2[j+1];
//		wE[j]=wE[j+1];
//	}
//	nE--;
//}
//void XoaCanhE(int u, int v)
//{
//	for(int i=0;i<nE;i++)
//		if(E1[i]==u&&E2[i]==v)
//		{
//			XoaViTriE(i);
//			break;
//		}
//}
//void prim(int s)//s la dinh bat dau
//{
//	int u=s, min, i, d1, d2;
//	while(nT<n-1)
//	{
//		for(int v=0;v<n;v++)
//			if(a[u][v]!=0)
//				if(TonTai(v,T2,nT)==0)
//				{
//					E1[nE]=u;
//					E2[nE]=v;
//					wE[nE]=a[u][v];
//					nE++;
//				}
//		for(i=0;i<nE;i++)
//			if(TonTai(E2[i],T2,nT)==0)
//			{
//				min=wE[i];
//				d1=E1[i];
//				d2=E2[i];
//				break;
//			}
//			for(i=0;i<nE;i++)
//				if(TonTai(E2[i],T2,nT)==0)
//					if(min>wE[i])
//					{
//						min=wE[i];
//						d1=E1[i];
//						d2=E2[i];
//					}
//			T1[nT]=d1;
//			T2[nT]=d2;
//			wT[nT]=a[d1][d2];
//			a[d1][d2]=0;
//			a[d2][d1]=0;
//			nT++;
//			XoaCanhE(d1,d2);
//			u=d2;
//	}
//}
//void output(bool VertexName)
//{
//	int tong=0;
//	for(int i=0;i<nT;i++)
//	{
//		if(VertexName)
//			cout<<"\n("<<vertex[T1[i]]<<","<<vertex[T2[i]]<<")= "<<wT[i];
//		else
//			cout<<"\n("<<T1[i]<<","<<T2[i]<<")= "<<wT[i];
//		tong+=wT[i];
//	}
//	cout<<"\nTong= "<<tong;
//}
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout<<" --------- BAI TAP 4, CHUONG 6, TIM KIEM CAY KHUNG TOI TIEU, PRIM --------- "
//		<<"\n1. Khoi tao MA TRAN KE rong"
//		<<"\n2. Nhap MA TRAN KE tu file text"
//		<<"\n3. Nhap MA TRAN KE"
//		<<"\n4. Xuat MA TRAN KE"
//		<<"\n5. Tim CAY KHUNG TOI TIEU bang PRIM"
//		<<"\n6. Thoat\n";
//	do
//	{
//		cout<<"\nVui long nhap so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			InitGraph();
//			cout<<"Ban vua khoi tao MA TRAN KE thanh cong!\n";
//			break;
//		case 2:
//			InputGraphFromText();
//			cout<<"Ban vua nhap MA TRAN KE tu file: \n";
//			outputGraph();
//			break;
//		case 3:
//			inputGraph();
//			break;
//		case 4:
//			outputGraph();
//			break;
//		case 5:
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			prim(x);
//			cout<<"Cay khung toi tieu voi PRIM:\n";
//			output(true);
//			break;
//		case 6:
//			cout<<"\nGoodbye.....!\n";
//			break;
//		default:
//			break;
//		}
//	}while(choice!=6);
//	system("pause");
//	return 0;
//}
