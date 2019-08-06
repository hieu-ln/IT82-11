//#include <iostream>
//using namespace std;
//#define COUNT 10
////cau1 khaibao
//struct node{
//	int info;
//	node*left;
//	node *right;
//};
//node *root;
////cau2 taocayrong  
//void init()
//{
//	root=NULL;
//}
////cau3 themmot phan tu
//void insertnode(node *&p, int x)
//{
//	if(p==NULL)
//	{
//		p=new node;
//		p->info=x;
//		p->left=NULL;
//		p->right=NULL;
//	}
//	else
//	{
//		if(p->info==x)
//			return;
//		else
//			if(p->info>x)
//				return insertnode(p->left,x);
//			else
//				return insertnode(p->right,x);
//	}
//} 
////cau4 timmot node
//node *search(node *p, int x)
//{
//	while(p!=NULL)
//	{
//		if(p->info==x)
//			return p;
//		else
//			if(p->info>x)
//				p=p->left;
//			else
//				p=p->right;
//	}
//	return NULL;
//}
////cau5 xoa pahntu trencay
//void searchstandfor(node *&p, node *&q)
//{
//	if(q->left==NULL)
//	{
//		p->info=q->info;
//		p=q;
//		q=q->right;
//	}
//	else
//		searchstandfor(p,q->left);
//}
//int Delete(node *&T,int x)
//{
//	if(T==NULL)
//		return 0;
//	if(T->info==x)
//	{
//		node *p=T;
//		if(T->left==NULL)
//			T=T->right;
//		else
//			if(T->right==NULL)
//				T=T->left;
//			else
//				searchstandfor(p,T->right);
//		delete p;
//		return 1;
//	}
//	if(T->info<x)
//		return Delete(T->right,x);
//	if(T->info>x)
//		return Delete(T->left,x);
//}
////cau  6 duyet NLR
//void duyetnlr(node *p)
//{
//	if(p!=NULL)
//	{
//		cout<<p->info<<" ";
//		duyetnlr(p->left);
//		duyetnlr(p->right);
//	}
//}
////cau7 duyet LNR
//void duyetlnr(node *p)
//{
//	if(p!=NULL)
//	{
//		duyetlnr(p->left);
//		cout<<p->info<<" ";
//		duyetlnr(p->right);
//	}
//}
////cau8 duyet LRN
//void duyetlrn(node *p)
//{
//	if(p!=NULL)
//	{
//		duyetlrn(p->left);
//		duyetlrn(p->right);
//		cout<<p->info<<" ";
//	}
//}
////in cay nhi phan
//void print(node *p,int space)
//{
//	if(p==NULL)
//		return;
//	space+= COUNT;
//	print(p->right, space);
//	cout<<endl;
//	for (int i=COUNT;i<space;i++)
//		cout<<" ";
//	cout<<p->info<<"\n";
//	print(p->left,space);
//}
//void process_tree()
//{
//	print(root,0);
//}
//int main()
//{
//	int chon=0,x,i;
//	node *p;
//	system("cls");
//	cout<<"-------------meun------------";
//	cout<<"\n1. khoi tao cay rong"<<endl;
//	cout<<"2. Them phan tu vao cay"<<endl;
//	cout<<"3. tim phan tu co gia tri x trong cay"<<endl;
//	cout<<"4. xoa phan tu co gia tri x trong cay"<<endl;
//	cout<<"5. duyet cay theo NLR"<<endl;
//	cout<<"6. duyet cay theo LNR"<<endl;
//	cout<<"7. duyet cay theo LRN"<<endl;
//	cout<<"8. xuat cay"<<endl;
//	cout<<"9. Thoat"<<endl;
//	do
//	{
//		cout<<"chon so de thuc hien: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init();
//			cout<<"ban vua tao cay thanh cong!"<<endl;
//			break;
//		case 2:
//			cout<<"nhap gia tri x can them: ";
//			cin>>x;
//			insertnode(root,x);
//			cout<<"cay sau khi them la: ";
//			process_tree();
//			break;
//		case 3:
//			cout<<"nhap gia tri x can tim: ";
//			cin>>x;
//			p=search(root,x);
//			if(p!=NULL)
//				cout<<"tim thay"<<x;
//			else
//				cout<<"khong tim thay";
//			cout<<endl;
//		case 4:
//			cout<<"nhap gia tri x can xoa: ";
//			cin>>x;
//			i=Delete(root,x);
//			if(i==0)
//				cout<<"khong tim thay x";
//			else
//			{
//				cout<<"da xoa thanh cong "<<x;
//				cout<<"\n cay sau khi xoa: ";
//				process_tree();
//			}
//			cout<<endl;
//			break;
//		case 5:
//			cout<<"cay duyen theo NLR la: ";
//			duyetnlr(root);
//			break;
//		case 6:
//			cout<<"cay duyen theo LNR la: ";
//			duyetlnr(root);
//			break;
//
//		case 7:
//			cout<<"cay duyen theo LRN la: ";
//			duyetlnr(root);
//			break;
//		case 8:
//			cout<<"cay nhi phan nhu sau: ";
//			process_tree();
//			break;
//		case 9:
//			cout<<"^^bye...!"<<endl;
//			break;
//		default: 
//			break;
//		}
//	}while(chon!=9);
//	system("pause");
//	return 0;
//}