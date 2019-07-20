//#include <iostream>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int n;
//void input(int a[], int &n)
//{
//	cout<<"Nhap so luong phan tu cho mang: ";
//	cin>>n;
//	for(int i = 0; i< n; i++)
//	{
//		cout<<"a["<<i<<"] = ";
//		cin>>a[i];
//	}
//}
//void output(int a[], int n)
//{
//	cout<<"Mang: ";
//	for(int i = 0; i<n ;i++)
//		cout<<a[i]<<"\t";
//	cout<<endl;
//}
//void search(int a[], int n)
//{
//	int x;
//	cout<<"Nhap gia tri x can tim: ";
//	cin>>x;
//	int i = 0;
//	while(i<n && a[i] != x)
//		i++;
//	if(i == n)
//		cout<<"Khong tim thay x = "<<x<<" trong mang!"<<endl;
//	else
//		cout<<"Tim thay x = "<<x<<" tai vi tri "<<i<<endl;
//}
//void insert_last(int a[], int &n)
//{
//	int x;
//	cout<<"Nhap phan tu can them: ";
//	cin>>x;
//	a[n] = x;
//	n++;
//	output(a,n);
//}
//void delete_last(int a[], int &n)
//{
//	n--;
//	output(a,n);
//}
//void delete_vitri(int a[], int &n)
//{
//	int x;
//	cout<<"Nhap vi tri ban can xoa: ";
//	cin>>x;
//	for(int i = x; i<n-1;i++)
//	{
//		a[i] = a[i+1];
//	}
//	n--;
//	output(a,n);
//}
//void delete_x(int a[],int &n)
//{
//	int x;
//	cout<<"Nhap phan tu ban can xoa: ";
//	cin>>x;
//	int i = 0;
//	while(i<n && a[i] != x)
//		i++;
//	if(i == n)
//		cout<<"Khong tim thay phan tu x = "<<x<<"trong mang de xoa!"<<endl;
//	else{
//		for(int j = i; j<n-1;j++)
//		{
//			a[j] = a[j+1];
//		}
//		n--;
//		output(a,n);
//	}
//}
//int main(){
//	cout<<"-DANH SACH CAU LENH-"<<endl;
//	cout<<"1. Nhap danh sach"<<endl;
//	cout<<"2. Xuat danh sach"<<endl;
//	cout<<"3. Tim phan tu trong danh sach"<<endl;
//	cout<<"4. Them 1 vao tu vao cuoi danh sach"<<endl;
//	cout<<"5. Xoa 1 phan tu o cuoi danh sach"<<endl;
//	cout<<"6. Xoa 1 phan tu tai vi tri danh sach"<<endl;
//	cout<<"7. Tim va xoa 1 phan tu trong danh sach"<<endl;
//	cout<<"8. Thoat"<<endl;
//	int chon;
//	do{
//		cout<<"Nhap lenh ban can su dung: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			input(a,n);
//			break;
//		case 2:
//			output(a,n);
//			break;
//		case 3:
//			search(a,n);
//			break;
//		case 4:
//			insert_last(a,n);
//			break;
//		case 5:
//			delete_last(a,n);
//			break;
//		case 6:
//			delete_vitri(a,n);
//			break;
//		case 7:
//			delete_x(a,n);
//			break;
//		}
//	}while(chon != 8);
//	return 0;
//}