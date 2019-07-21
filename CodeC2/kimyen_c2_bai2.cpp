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
//void sapxep(int a[M], int n)
//{
//	int tam;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=i+1;j<n;j++)
//			if(a[i]>a[j])
//			{
//				tam=a[i];
//				a[i]=a[j];
//				a[j]=tam;
//			}
//	}
//}
//void thempt(int a[M], int &n, int x)
//{
//	sapxep(a,n);
//	int vt=0;
//	for(int i=0;i<n;i++)
//		if(x<a[i])
//		{
//			vt=i;
//			break;
//		}
//	if(x>a[n-1])
//			vt=n;
//     for(int i=n;i>=vt;i--)
//	 {
//	 a[i]=a[i-1];
//	 }
//	 a[vt]=x;
//	 n++;
//}
//int search(int a[M], int n, int k)
//{
//	int i=0;
//	while(i<n&&a[i]!=k)
//		i++;
//	if(i==n)
//		return -1;
//	return i;
//}
//int search_np(int a[M], int n, int k)
//{
//	int t=0;
//	int p=n-1;
//	while(t<=p)
//	{
//		int g=(t+p)/2;
//		if(k==a[g])
//			return k;
//		else
//		{
//			if(k<a[g])
//				p=g-1;
//			else
//				t=g+1;
//		}
//		
//	}
//		return -1;
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
//	int a[M], n, x, k,y;
//	cout<<"nhap so luong phan tu ";
//	cin>>n;
//	cout<<"nhap phan tu";
//	input(a,n);
//	cout<<"\n ds phan tu vua nhap";
//	output(a,n);
//	sapxep(a,n);
//	output(a,n);
//	cout<<"nhap so ban muon chen: ";
//	cin>>x;
//	thempt(a,n,x);
//	cout<<"\n ds moi";
//	output(a,n);
//	cout<<"nhap so ban muon tim: ";
//	cin>>k;
//	if(search_np(a,n,k)<0&&search(a,n,k)<0)
//		cout<<"khong tim thay";
//	else
//		cout<<"tim thay";
//	cout<<"\n nhap so ban muon tim va xoa no: ";
//	cin>>y;
//	xoalun(a,n,y);
//	system("pause");
//	return 0;
//}