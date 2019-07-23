#include<iostream>
using namespace std;
//Cau 3.1: Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;
//Cau 3.2: Khoi tao danh sach rong
void Init()
{
	first=NULL;
}
//Cau 3.3: Xuat cac phan tu trong danh sach
void Output()
{
	Node *p=first;
	while(p!=NULL)
	{
		cout<<p->info<<"\t";
		p=p->link;
	}
	cout<<endl;
}
//Cau 3.4: Tim mot phan tu trong danh sach
Node *Search(int x)
{
	Node *p=first;
	while((p!=NULL)&&(p->info!=x))
		p=p->link;
	return p;
}
//Cau 3.5: Them phan tu vao dau danh sach
void Insert_first(int x)
{
	Node *p= new Node;
	p->info=x;
	p->link=first;
	first=p;
}
//Cau 3.6: Xoa phan tu dau danh sach
int Delete_first()
{
	if(first!=NULL)
	{
		Node *p=first;
		first=first->link;
		delete p;
		return 1;
	}
	return 0;
}
//Cau 3.7: Them phan tu cuoi danh sach
void Insert_last(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=NULL;
	if(first==NULL)
		first=p;
	else
	{
		Node *q=first;
		while(q->link!=NULL)
			q=q->link;
		q->link=p;
	}
}
//Cau 3.8: Xoa phan tu cuoi danh sach
int Delete_last()
{
	if(first!=NULL)
	{
		Node *p, *q;
		p=first;
		q=first;
		while(p->link!=NULL)
		{
			q=p;
			p=p->link;
		}
		if(p!=first)
			q->link=NULL;
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Cau 3.9: Tim phan tu trong danh sach, roi xoa phan tu nay neu co
int Search_and_Delete(int x)
{
	if(first!=NULL)
	{
		Node *p=first, *q=first;
		while(p->info!=x&&p->link!=NULL)
		{
			q=p;
			p=p->link;
		}
		if(p!=first&&p->link!=NULL)
		{
			if(p->link!=NULL)
				q->link=p->link;
			else
				q->link=NULL;
			delete(p);
			return 1;
		}
		else
			if(p==first)
			{
				first=p->link;
				delete(p);
				return 1;
			}
			else
				if(p->link==NULL&&p->info==x)
				{
					q->link==NULL;
					delete(p);
					return 1;
				}
				else
					return 0;
	}
	return 0;
}
//Hoan doi gia tri cua 2 phan tu
void Swap(Node *a,Node *b)
{
	int t=a->info; 
	a->info=b->info; 
	b->info=t; 
}
//Cau 3.10: Sap xep danh sach theo thu tu tang dan
void Sort()
{
	Node *p, *q, *min;
	p=first;
	while(p!=NULL)
	{
		min=p;
		q=p->link;
		while(q!=NULL)
		{
			if(q->info<min->info)
				min=q;
			q=q->link;
		}
		Swap(min,p);
		p=p->link;
	}
}
//Cau 3.10: Sap xep theo thu tu giam dan
void SortDesc()
{
	Node *p, *q, *min;
	p=first;
	while(p!=NULL)
	{
		min=p;
		q=p->link;
		while(q!=NULL)
		{
			if(q->info>min->info)
				min=q;
			q=q->link;
		}
		Swap(min,p);
		p=p->link;
	}
}
int main()
{
	int x, i, choice=0;
	Node* p;
	system("cls");
	cout<<" --------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON ---------"
	    <<"\n1. Khoi tao DSLK DON rong"
		<<"\n2. Them phan tu vao dau DSLK DON"
		<<"\n3. Them phan tu vao cuoi DSLK DON"
		<<"\n4. Xoa phan tu vao dau DSLK DON"
		<<"\n5. Xoa phan tu vao cuoi DSLK DON"
		<<"\n6. Xuat DSLK DON"
		<<"\n7. Tim mot phan tu co gia tri x trong DSLK DON"
		<<"\n8. Tim phan tu co gia tri x va xoa no neu co"
		<<"\n9. Sap xep DSLK DON tang dan"
		<<"\n10. Sap xep DSLK DON giam dan"
		<<"\n11. Thoat\n";
	do
	{
	    cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
		    Init();
		    cout<<"\nBan vua khoi tao DSLK DON thanh cong!\n";
			break;
		case 2:
			cout<<"Vui long nhap gia tri cua x: ";
			cin>>x;
			Insert_first(x);
			cout<<"\nDanh sach sau khi them la:\n";
			Output();
			break;
		case 3:
			cout<<"Vui long nhap gia tri cua x: ";
			cin>>x;
			Insert_last(x);
			cout<<"\nDanh sach sau khi them la:\n";
			Output();
			break;
		case 4:
			i=Delete_first();
			if(i==0)
				cout<<"\nDanh sach rong, khong the xoa!"<<endl;
			else
			{
				cout<<"\nDa xoa thanh cong phan tu dau cua DSLK DON!\n";
				cout<<"Danh sach sau khi xoa la:\n";
				Output();
			}
			break;
		case 5:
			i=Delete_last();
			if(i==0)
				cout<<"\nDanh sach rong, khong the xoa!"<<endl;
			else
			{
				cout<<"\nDa xoa thanh cong phan tu cuoi cua DSLK DON!\n";
				cout<<"Danh sach sau khi xoa la:\n";
				Output();
			}
			break;
		case 6:
			cout<<"\nDanh sach hien tai la:\n";
			Output();
			break;
		case 7:
			cout<<"\nVui long nhap thanh vien can tim: ";
			cin>>x;
			p=Search(x);
			if(p!=NULL)
				cout<<"\nTim thay phan tu co gia tri x = "<<x<<endl;
			else
				cout<<"\nKhong tim thay hai phan tu co gia tri x = "<<x<<endl;
			break;
		case 8:
			cout<<"\nVui long nhap gia tri x = ";
			cin>>x;
			i= Search_and_Delete(x);
			if(i==1)
			{
				cout<<"\nTim thay x = "<<x<<" va da xoa thanh cong!\n";
				cout<<"Danh sach sau khi xoa la:\n";
				Output();
			}
			break;
		case 9:
			Sort();
			cout<<"\nDanh sach sau khi sap xep tang dan:\n";
			Output();
			break;
		case 10:
			SortDesc();
			cout<<"\nDanh sach sau khi sap xep giam dan:\n";
			Output();
			break;
		case 11:
			cout<<"\nChao tam biet va hen gap lai\n";
			break;
		default:
			break;
		}
	}while(choice!=11);
	cout<<endl;
	system("pause");
	return 0;
}