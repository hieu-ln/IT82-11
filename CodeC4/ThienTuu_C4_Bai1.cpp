#include <stdio.h>
#include <iostream>
#define MAX 10
using namespace std;
int COUNT = 5;
int x;
int y;
struct Node{
	   int info;
	   Node *left;
	   Node *right;
};
Node *root;
void init(){
	root = NULL;
	cout << "Da khoi tao cay rong\n";
}
void them(Node *&p, int x){
	if(p == NULL)
	{

		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else{
		if(p->info == x)
			return;
		else if(p->info > x)
				return them(p->left, x);
			else
				return them(p->right, x);
	}
}
Node *search(Node *&p, int x){
	cout << "Nhap gia tri can tim x=";
	cin >> x;
	if(p!=NULL)
	{
		if(p->info == x)
			return p;
		else
			if(x>p->info)
				p = p->right;
			else
				p = p->left;
	}
	return NULL;
}
void SearchForDelete(Node *&p, Node *&q){
	if(q->left == NULL)
	{
		p->info = q->info;
		p=q;
		q=q->right;
	}
	else
		SearchForDelete(p, q->left);
}
void Xoa(Node *&T, int x){
	if(T == NULL)
	{
		cout << "Khong tim thay phan tu x="<<x<<" trong cay\n";
		return;
	}
	if(T->info==x)
	{
		Node *p = T;
		if(T->left == NULL)
			T=T->right;
		else if(T->right ==NULL)
				T = T->left;
			else
				SearchForDelete(p, T->right);
		delete p;
		cout << "Da xoa phan tu x="<<x<<" trong cay\n";
		return;
	}
	if(T->info>x)
		return Xoa(T->left, x);
	if(T->info<x)
		return Xoa(T->right, x);
}
void DuyetLNR(Node *p){
	if(p!=NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << "\t";
		DuyetLNR(p->right);
	}
}
void DuyetNLR(Node *p){
	if(p!=NULL)
	{
		cout << p->info << "\t";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
void DuyetLRN(Node *p){
	if(p!=NULL){
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << "\t";
	}
}
void Print(Node *p, int space){
	if(p==NULL)
		return;
	space += COUNT;
	Print(p->right, space);
	cout << endl;
	for(int i = COUNT; i<space; i++)
		cout << " ";
	cout <<p->info<<endl;
	Print(p->left, space);
}
int main(){
	Node *p = root;
	int chon;
	cout<<"MENU\n";
	cout<<"1. Khoi tao cay rong\n";
	cout<<"2. Them 1 phan tu vao cay\n";
	cout<<"3. Tim 1 phan tu trong cay\n";
	cout<<"4. Xoa 1 nut trong cay\n";
	cout<<"5. Duyet cay theo thu tu NLR\n";
	cout<<"6. Duyet cay theo thu tu LNR\n";
	cout<<"7. Duyet cay theo thu tu LRN\n";
	cout<<"8. In Cay\n";
	cout<<"9. Thoat\n";
	do{
		cout << "Chon: ";
		cin>>chon;
		switch(chon){
		case 1:
			init();
			break;
		case 2:
			cout << "Nhap gia tri can them x=";
			cin >> x;
			them(p, x);
			Print(p, 0);
			break;
		case 3:
			search(p, x);
			break;
		case 4:
			cout << "Nhap gia tri can xoa x=";
			cin >> y;
			Xoa(p, y);
			Print(p, 0);
			break;
		case 5:
			DuyetNLR(p);
			cout << endl;
			break;
		case 6:
			DuyetLNR(p);
			cout << endl;
			break;
		case 7:
			DuyetLRN(p);
			cout << endl;
			break;
		case 8:
			Print(p, 0);
			break;
		default:
			break;
		}
	}while(chon!=9);
	system("pause");
	return 0;
}