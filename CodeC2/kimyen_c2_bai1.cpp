//#include <iostream>
//using namespace std;
//const int M=100;
//void input(int a[M] , int n)
//{
//	for(int i=0;i<n;i++)
//			a[i]=rand()%10;
//}
//void output(int a[M] , int n)
//{
//	for(int i=0;i<n;i++)
//	    cout<<a[i]<<" ; ";
//	cout<<endl;
//}
//int search(int a[M] , int n, int x)
//{
//	int i=0;
//	while(x<n&&a[i]!=x)
//		i++;
//	if(i==n)
//		return -1;
//	else
//		return 0;
//}
//void insert_last(int a[M] , int &n, int x)
//{
//		int k=0, i=0;
//	i=n-1;
//	a[i+1]=a[i];
//	a[i+1]=x;
//	n++;
//}
//int delete_last(int a[M] , int &n)
//{
//	n--;
//	return 0;
//}
//int delete_bk(int a[M], int &n, int k)
//{
//	if(k>=0&&k<n)
//	{
//		for(int i=k;i<n-1;i++)
//			a[i]=a[i+1];
//		--n;
//		return 1;
//	}
//	
//	return 0;
//}
//void xoalun(int a[M], int &n, int k)
//{
//	if(search(a,n,k)<0)
//		cout<<"khong tim thay "<<k;
//	else
//	{
//		cout<<"tim thay va da xoa ";
//		int vt=0;
//		for(int i=0;i<n;i++)
//			if(a[i]==k)
//				vt=i;
//		delete_bk(a,n,vt);
//		cout<<"\n danh sach moi: ";
//	    output(a,n);
//	}
//}
//int main()
//{
//	int chon, a[M], n,x;
//	cout<<"------------menu-----------";
//	cout<<"1.khai bao danh sach"<<endl;
//	cout<<"2.nhap danh sach"<<endl;
//	cout<<"3.xuat danh sach"<<endl;
//	cout<<"4.Tim mot phan tu trong danh sach"<<endl;
//	cout<<"5.them mot phan tu vao cuoi danh sach"<<endl;
//	cout<<"6.xoa mot phan tu cuoi danh sach"<<endl;
//	cout<<"7.xoa phan tu bat ki "<<endl;
//	cout<<"8.tim mot phan tu trong danh sach neu co xoa luon"<<endl;
//	cout<<"9.tim va xoa phan tu"<<endl;
//	do
//	{
//		cout<<"\nnhap so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//				cout<<"nhap so luowng phan tu ";
//				cout<<"ban vua tao thanh cong!\n";
//				cin>>n;
//			break;
//		case 2:
//			cout<<"danh sach vua to tu dong\n";
//			    input(a,n);
//			break;
//		case 3:
//			cout<<"danh sach vua to tu dong la: \n";
//			output(a,n);
//			break;
//		case 4:
//			cout<<"nhap mot phan tu muon tim : ";
//			cin>>x;
//			if(search(a,n,x)<0)
//				cout<<"tim khong thay"<<endl;
//			else
//				cout<<"tim thay: "<<endl;
//			break;
//		case 5:
//			cout<<"nhap mot phan tu muon them vao cuoi ds: ";
//			cin>>x;
//			insert_last(a,n,x);
//			cout<<"danh sach vua themla: \n";
//			output(a,n);
//			break;
//		case 6:
//			cout<<"nhap mot phan tu muon xoa vao cuoi ds: ";
//			cin>>x;
//			delete_last(a,n);
//			cout<<"danh sach sau khi xoa";
//			output(a,n);
//			break;
//		case 7:
//			  delete_last(a,n);
//	 		  cout<<"danh sach sau khi xoa";
//			  output(a,n);
//			break;
//		case 8:
//			cout<<"nhap mot phan tu muon tim va xoa : ";
//			cin>>x;
//			xoalun(a,n,x);
//		case 9: 
//			cout<<"----^^bye^^---";
//		default:
//			break;
//		}
//	}while(chon!=9);
//	system("pause");
//	return 0;
//}