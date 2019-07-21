//#include < stdio.h >
//#include < iostream > 
//using namespace std ; 
//// Cau 10 . 1 : Khai bao cau truc 
//struct node{
//	int info;
//	node *link;
//};
//node *sp;
////cau2
//void init()
//{
//	sp=NULL;
//}
//int isempty()
//{
//	if(sp==NULL)
//		return 1;
//	return 0;
//}
//void push(int x)
//{
//	node *p=new node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//int pop(int &x)
//{
//	if(sp!=NULL)
//	{
//		node *p=sp;
//		x=p->info;
//		sp=p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void output()
//{
//	node *p=sp;
//	do
//	{
//		cout<<p->info<<" ";
//		p=p->link;
//	}while(p!=NULL);
//	cout<<endl;
//}
//int main()
//{
//	int chon, x, i;
//	cout<<"------------menu-----------";
//	cout<<"1.Khoi tao STAck rong"<<endl;
//	cout<<"2.them phan tu vao cay"<<endl;
//	cout<<"3.lay phan tu ra khoi stack"<<endl;
//	cout<<"4.xuat stack"<<endl;
//	cout<<"5.Thoat---"<<endl;
//	do
//	{
//		cout<<"\nnhap so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init();
//			cout<<"ban vua tao thanh cong!\n";
//			break;
//		case 2:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			push(x);
//			cout<<"stack sau khi xep la: ";
//			output();
//			break;
//		case 3:
//			cout<<"vui long nhap gia tri x= ";
//			cin>>x;
//			pop(x);
//			cout<<"phan tu lay ra khoi stack la x= "<<x<<endl;
//			cout<<"stack sau khi lay ra: ";
//			output();
//			break;
//		case 4:
//			cout<<"stack cua hien tai: ";
//			output();
//			break;
//		case 5:
//			cout<<"----^^bye^^---";
//			break;
//		default:
//			break;
//		}
//	}while(chon!=5);
//	system("pause");
//	return 0;
//}