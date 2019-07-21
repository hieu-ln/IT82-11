//#include <iostream>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *first;
//void tao()
//{
//	first=NULL;
//}
//void add_f(int x)
//{
//	node *p;
//	p=new node;
//	p->info=x;
//	p->link=first;
//	first=p;
//}
//void duyetds()
//{
//	node *p;
//	p=first;
//	while(p!=NULL)
//	{
//		cout<<p->info<<"; ";
//		p=p->link;
//	}
//}
//void sapxeptt()
//{
//	
//	node *p=first,*q;
//	while(p->link !=NULL)
//	{
//		q=p->link;
//		while(q!=NULL)
//		{
//			if(p->info >q->info)
//			{
//				int tam=p->info;
//				p->info=q->info;
//				q->info=tam;
//			}
//			q=q->link;
//		}
//		p=p->link;
//	}
//}
//void themsau(int x, int y)
//{
//  node *p;
//  p=new node;
//  p->info=x;
//  if(first==NULL)
//   {
//	   first=p;
//   }
//   else
//   {
//	   node *q;
//	   q=first;
//	   while(q->info!=y)
//	   {
//		  q=q->link;
//		  
//	   }
//	   p->link=q->link;
//	   q->link=p;
//	 
//   }
// }
//void themtruoc(int x, int y)
//{
//   node *p;
//  p=new node;
//  p->info=x;
//  if(first==NULL)
//   {
//	   first=p;
//   }
//   else
//   {
//	   if(y==first->info)
//		   add_f(x);
//	   else{node *q, *qt;
//	   q=first;
//	   qt=first;
//	   while(q->info!=y)
//	   {
//		  qt=q;
//		  q=qt->link;
//		  
//	   }
//	   p->link=qt->link;
//	   qt->link=p;}
//	 
//   }
// }
//void themtheott(int x)
//{
//	node *p; int y;
//	p=first;
//	while(p->link!=NULL)
//	{
//		if(x<p->info)
//			break;
//		p=p->link;
//	}
//	if(p->link==NULL)
//	{
//		y=p->info;
//		themsau(x,y);
//	}
//	else
//	{
//		y=p->info;
//		themtruoc(x,y);
//	}
//	
//}
//node *search(int x)
//{
//	node *p;
//	p=first;
//	while(p!=NULL&&p->info!=x)
//		p=p->link;
//	return  p;
//}
//void timvaxoa(int x)
//{
//	if(search(x)==NULL)
//		cout<<"tim khong thay";
//	else
//	{
//		if(x==first->info)
//		{
//			node *p;
//			p=first;
//			first=p->link;
//			delete p;
//		}
//		else
//		{
//			node *p, *pt;
//			p=first;
//			pt=first;
//			while(p->info!=x)
//			{
//				pt=p;// gan cho lien ket truoc
//				p=pt->link;
//			}
//			pt->link=p->link;
//		delete p;
//		}
//	}
//}
//int main()
//{
//	int chon, x;
//	cout<<"\n------------menu-----------";
//	cout<<"\n1.khai bao danh sach"<<endl;
//	cout<<"2.khoi tao danh sach voi danh sah rong"<<endl;
//	cout<<"3.them mot so"<<endl;
//	cout<<"4.xuat cac phan tu trong danh dach"<<endl;
//	cout<<"5.tim mot phan tu trong danh sach"<<endl;
//	cout<<"6.tim phan tu trong danh sanh neu thay thi xoa"<<endl;
//	cout<<"7.tthem phan tu: "<<endl;
//	cout<<"8.thoat---";
//	do
//	{
//		cout<<"\nnhap so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			cout<<"tao thanh cong: \n";
//			break;
//		case 2:
//			tao();
//			cout<<"tao thanh cong: \n";
//			break;
//		case 7:
//			cout<<"danh sach: ";
//			duyetds();
//			sapxeptt();
//			cout<<"nhap phan tu muon them: ";
//			cin>>x;
//			themtheott(x);
//			cout<<"danh sach sau khi them: ";
//			duyetds();
//			
//			break;
//		case 4:
//			cout<<"danh sach: ";
//			duyetds();
//			break;
//		case 5:
//			cout<<"nhap phan tu muon tim: ";
//			cin>>x;
//			if(search(x)==NULL)
//				cout<<"khong tim thay";
//			else
//				cout<<"tim thay";
//			break;
//		case 6:
//			cout<<"nhap phan tu muon tim va xoa: ";
//			cin>>x;
//			timvaxoa(x);
//			duyetds();
//			break;
//		case 3: 
//			cout<<"them vai phan tu truoc: ";
//			add_f(5);
//			add_f(8);
//			add_f(7);
//			duyetds();
//			break;
//		case 8:
//			cout<<"bye";
//		default:
//			break;
//		}
//	}while(chon!=8);
//	system("pause");
//	return 0;
//}