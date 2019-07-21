//#include <iostream>
//using namespace std;
//const int M=100;
//int a[M];
//int sp;
//void init(int a[], int &sp)
//{
//	sp=-1;
//}
//int isempty(int a[], int sp)
//{
//	if(sp==-1)
//		return -1;
//	return 0;
//}
//int isfull(int a[], int sp)
//{
//	if(sp==M-1)
//		return -1;
//	return 0;
//}
//int push(int a[], int &sp, int x)
//{
//	if(sp<M-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
//int pop(int a[], int &sp, int &x)
//{
//	if(sp!=-1)
//	{
//		x=a[sp--];
//		return x;
//	}
//	return -1;
//}
//void output(int a[M] , int sp)
//{
//	for(int i=0;i<sp+1;i++)
//	    cout<<a[i]<<"\t";
//	cout<<endl;
//}
//void chuyenso (int a[], int &sp)
//{
//    init(a,sp);
//    int m,k;
//	 do
//    {
//        cout << "Nhap so thap phan can chuyen: ";
//        cin >> m ;
//    }
//    while (m<=0);
//    while (m!=0)
//    {
//        k=m%2;
//        push(a,sp,k);
//        m=m/2;
//    }
//    cout << " chuyen sang he s o "<<x<<" la: ";
//    while (isempty(a,sp)==0)
//        cout<<pop(a,sp,k);
//	cout<<endl;
//}
//int main()
//{
//	int a[M];
//	int chon, sp, x, i;
//	cout<<"------------menu-----------";
//	cout<<"1.Khoi tao STAck rong"<<endl;
//	cout<<"2.them phan tu vao cay"<<endl;
//	cout<<"3.lay phan tu ra khoi stack"<<endl;
//	cout<<"4.kiem tra stack co rong hay khong"<<endl;
//	cout<<"5.kiem tra stack co day hay khong"<<endl;
//	cout<<"6.xuat stack"<<endl;
//	cout<<"7.doi so he thap than sang he bat ki "<<endl;
//	cout<<"8.Thoat---"<<endl;
//	do
//	{
//		cout<<"\nnhap so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init(a,sp);
//			cout<<"ban vua tao thanh cong!\n";
//			break;
//		case 2:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			push(a,sp,x);
//			cout<<"stack sau khi xep la: ";
//			output(a,sp);
//			break;
//		case 3:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			i=pop(a,sp,x);
//			cout<<"phan tu lay ra khoi stack la x= "<<x<<endl;
//			cout<<"stack sau khi lay ra: ";
//			output(a,sp);
//			break;
//		case 4:
//			i=isfull(a,sp);
//			if(i==0)
//				cout<<"stack chua day"<<endl;
//			else
//				cout<<"stack da day"<<endl;
//			break;
//		case 5:
//			i=isempty(a,sp);
//			if(i==0)
//				cout<<"stack khong rong"<<endl;
//			else
//				cout<<"stack rong"<<endl;
//			break;
//		case 6:
//			cout<<"stack cua hien tai: ";
//			output(a,sp);
//			break;
//		case 7:
//			 cout<<"nhap co so can doi 2 ";
//			 cin>>x;
//			 chuyenso(a,sp);
//			break;
//		case 8: 
//			cout<<"----^^bye^^---";
//		default:
//			break;
//		}
//	}while(chon!=8);
//	system("pause");
//	return 0;
//}