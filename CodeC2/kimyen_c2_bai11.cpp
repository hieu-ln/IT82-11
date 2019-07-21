//#include < stdio.h >
//#include < iostream > 
//using namespace std ; 
//// Cau 10 . 1 : Khai bao cau truc 
//struct node{
//	int info;
//	node *link;
//};
//node *front, *rear;
////cau2
//void init()
//{
//	front=NULL;
//	rear=NULL;
//}
//int isempty()
//{
//	if(front==NULL)
//		return 1;
//	return 0;
//}
//void push(int x)
//{
//	node *p=new node;
//	p->info=x;
//	p->link=NULL;
//	if(rear==NULL)
//		front=p;
//	else
//		rear->link=p;
//	rear=p;
//}
//int pop(int &x)
//{
//	if(front!=NULL)
//	{
//		node *p=front;
//		front=p->link;
//		x=p->info;
//		if(front==NULL)
//			rear=NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void output()
//{
//	if(front!=NULL)
//	{
//		node *p=front;
//		cout<<"<-- ";
//		do
//		{
//			cout<<p->info<<" ";
//			p=p->link;
//
//		}while(p!=NULL);
//		cout<<"<--"<<endl;
//	}
//}
//int main()
//{
//	int chon, x, i;
//	cout<<"------------menu-----------";
//	cout<<"1.Khoi tao quue rong"<<endl;
//	cout<<"2.them phan tu vao queue"<<endl;
//	cout<<"3.lay phan tu ra khoi queue"<<endl;
//	cout<<"4.kiem tra queue co rong hay khong"<<endl;
//	cout<<"5.xuat stack"<<endl;
//	cout<<"6.Thoat---"<<endl;
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
//			pop(x);
//			cout<<"phan tu lay ra khoi stack la x= "<<x<<endl;
//			cout<<"queue sau khi lay ra: ";
//			output();
//			break;
//		case 4:
//			i=isempty();
//			if(i==0)
//				cout<<"khong rong";
//			else
//				cout<<"rong";
//			cout<<endl;
//			break;
//		case 5:
//			cout<<"stack cua hien tai: ";
//			output();
//			break;
//		case 6:
//			cout<<"----^^bye^^---";
//			break;
//		default:
//			break;
//		}
//	}while(chon!=6);
//	system("pause");
//	return 0;
//}