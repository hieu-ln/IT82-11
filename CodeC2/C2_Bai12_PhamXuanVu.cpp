#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *next,
	*previous;
};Node *first,*last;

void init()
{
	first = NULL;
	last = NULL;
}

void process_list()
{
	Node*p;
	p=first;
	while(p!=NULL)
	{
		cout <<p->info<<" ";
		p = p->next;
	}
	cout << endl;
}

void insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if(first != NULL)
		first->previous = p;
	else
		last = p;
	first = p;
}

void insert_last(int &x)
{
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	if(last != NULL)
		last->next = p;
	else
		first = p;
	last = p;

}

int delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->next ;
		delete p;
		if(first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}

int delete_last()
{
	if(last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if(last != NULL)
			last->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int search_And_Delte(int x)
{
	if(first != NULL)
	{
		Node* p, *q, *e;
		e = first;
		p = first;
		q = first;
		while(p->info != x && p->next != NULL)
		{
			q = p;
			p = p->next ;
		}
		e = p->next ;
		if(p != first && p!= NULL)
		{
			if(p->next != NULL)
			{
				q->next = p->next;
				e->previous = q;
			}
			else
			{
				q->next = NULL;
				last = q;
			}
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				first = p->next;//dc = null
				last = p->next;
				delete p;
				return 1;
			}
			else
				return 0;
	}
	return 0;
}

void insert_before_q(int x, int y)
{
	Node* p, *q, *e;
		e = new Node ;
		p = first;
		q = first;
		e->info = x;
	if(first != NULL)
	{
		while(p->info != y && p->next != NULL)
		{
			q = p;
			p = p->next ;
		}

		if(p != first && p!= NULL)
		{
			
			e->previous = p->previous;
			e->next = q->next;
			q->next = e;
			p->previous = e;
		}
		else
		{
			p->previous = e;
			e->next = p;
			first = e;
		}
	}
	else{
				cout <<"ko ton tai y\n";
	}
}

int main()
{
	int choice = 0;
	int x,y, i;
	Node *p;
	cout << ".............BAI TAP 12, CHUONG 01 - BAI TAP THEM \n" ;
	cout << "1.khoi tao danh sach lien ket doi \n";
	cout << "2.them phan tu vao dau DSLK doi \n";
	cout << "3.them phan tu vao cuoi DSLK doi \n";
	cout << "4.xoa phan tu dau DSLK doi \n" ;
	cout << "5.xoa phan tu cuoi DSLK doi \n" ;
	cout << "6.tim phan tu voi gia tri x va xoa no \n" ;
	cout <<"7.them phan tu dung truoc gia tri x \n";
	cout << "8. Thoat\n";
	do{
		cout <<"chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
			init();
			cout << "khoi tao DSLK doi thanh cong! \n";
			break;
		case 2:
			cout << "nhap gia tri can them dau danh sach: ";cin >> x;
			insert_first( x);
			cout << "danh sach sau khi them la: \n";
			process_list();
			break;
		case 3:
			cout << "nhap gia tri can them cuoi danh sach: ";cin >> x;
			insert_last( x);
			cout << "danh sach sau khi them la: \n";
			process_list();
			break;
		case 4:
			i = delete_first();
			if( i == 0)
				cout << "danh sach rong !\n";
			else
			{
				cout << "da xoa dau thanh cong!\n ";
				cout << "danh sach sau khi xoa la: \n";
				process_list();
			}
			break;
		case 5:
			i = delete_last();
			if( i == 0)
				cout << "danh sach rong !\n";
			else
			{
				cout << "da xoa dau thanh cong!\n ";
				cout << "danh sach sau khi xoa la: \n";
				process_list();
			}
			break;
		case 6:
			cout <<"nhap vao gia tri x can xoa: ";cin>>x;
			if(search_And_Delte( x) == 1)
			{
				cout <<"xoa thanh cong !\n DS sau khi xoa la: \n";
				process_list();
			}
			else
				cout <<"DS ko co gi de xoa ! \n";
			break;
		case 7:
			cout <<"nhap gia tri muon them x= ";cin>> x;
			cout <<"nhap gia tri dung ngay truoc x, y= ";cin>> y;
			insert_before_q( x, y);
			process_list();
			break;
		case 8:
			cout <<"see you again ^-^\n";
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}