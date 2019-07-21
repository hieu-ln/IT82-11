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
//node *search(int x)
//{
//	node *p;
//	p=first;
//	while(p!=NULL&&p->info!=x)
//		p=p->link;
//	return  p;
//}
//void add_f(int x)
//{
//	node *p;
//	p=new node;
//	p->info=x;
//	p->link=first;
//	first=p;
//}
//int delete_f()
//{
//	node *p;
//	p=first;
//	first=p->link;
//	delete p;
//	return 0;
//}
//void add_l(int x)
//{
//	node *p;
//	p=new node;
//	p->info=x;
//	p->link=NULL;
//	node *q;
//	q=first;
//	if(first==NULL)
//		first=p;
//	while(q->link!=NULL)
//	{
//		q=q->link;
//	}
//	q->link=p;
//}
//int delete_l()
//{
//	node *p, *pt;
//	p=first;
//	while(p->link!=NULL)
//	{
//		pt=p;
//		p=p->link;
//	}
//	pt->link=NULL;
//	delete p;
//	return 0;
//}
//void delete_bk(int x)
//{
//	node *p, *pt;
//	p=first;
//	pt=first;
//	while(p->info!=x)
//	{
//		pt=p;// gan cho lien ket truoc
//		p=pt->link;
//	}
//	pt->link=p->link;
//	delete p;
//}
//void timvaxoa(int x)
//{
//	if(search(x)==NULL)
//		cout<<"tim khong thay";
//	else
//	{
//		node *p, *pt;
//		p=first;
//		pt=first;
//		while(p->info!=x)
//		{
//			pt=p;// gan cho lien ket truoc
//			p=pt->link;
//		}
//		pt->link=p->link;
//	delete p;
//	}
//}
//void sapxep(int a, int b)
//{
//
//	int tam=a;
//	a=b;
//	b=tam;
//}
//void sapxeptt()
//{
//	node *q;
//	q=first;
//	node *p;
//	while(q->link!=NULL)
//	{
//		p=q->link;
//		while(p!=NULL)
//		{
//			if(q->info>p->info)
//			{
//				sapxep(q->info,p->info);
//			}
//			p=p->link;
//		}
//		q=q->link;
//	}
//}
//int main()
//{
//	int n, y, x, d ,c ,l;
//	cout<<"nhap phan tu muon them: ";
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{  
//		cin>>y;
//	   add_f(y);
//	}
//	cout<<"ds vua nhap";
//	duyetds();
//	/*cout<<"nhap phan tu muon tim : ";
//	cin>>x;
//	if(search(x)==NULL)
//		cout<<"khong tim thay";
//	else
//		cout<<"tim thay";
//	cout<<endl;
//	cout<<"nhap phan tu muon them vao dau ds: ";
//	cin>>d;
//	add_f(d);
//	cout<<"\nds vua nhap";
//	duyetds();
//	delete_f();
//	cout<<"\nds vua nhap da xoa dau";
//	duyetds();
//	cout<<"nhap phan tu muon them vao dau ds: ";
//	cin>>c;
//	add_l(c);
//	cout<<"\nds vua nhap ";
//	duyetds();
//	delete_l();
//	cout<<"\nds vua nhap da xoa cuoi";
//	duyetds();
//	cout<<"nhap phan tu muon tim va xoa: ";
//	cin>>l;
//	timvaxoa(l);
//	duyetds();*/
//	sapxeptt();
//	cout<<"\nds vua xap xep";
//	duyetds();
//	system("pause");
//	return 0;
//}