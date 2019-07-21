#include <iostream>
#include <stdio.h>
using namespace std;
#define max 100

struct node
{
	int info;
	node *link;
};
node *first;
void init()
{
	first = NULL;
}

void list()
{
	node *p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
	cout << endl;
}

int search(int x)
{
	node *p = first; 
	int i = 0;
	while (p != NULL && p->info!=x )
	{
		p = p->link;
		i++;
	}
	if (p != NULL)
		return i;
	else
		return 0;
}

void Add_first(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = first;
	first = p;
}

void Add_last(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = NULL;
	 
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}	
}

int delete_first()
{
	while (first != NULL)
	{
		node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int delete_last()
{
	node *q, *p;
	p = first;
	q = first;
	if (first != NULL)
	{
		while (p != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int Find_delete(int x)
{
	if (first != NULL)
	{
		node *p, *q;
		p = first;
		q = first;
		//chạy p và q;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		//nằm giữa
		if (p != first && p->link != NULL)
		{
			q->link = p->link;
			return 1;
		}
		else
			//đầu
			if (p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				//cuối
				if (p->link == NULL)
				{
					q->link = NULL;
					delete p;
					return 1;
				}
				else
					return 0;
	}
	return 0;
}
void swap(node *a, node *b)
{
	int temp;
	temp = a->info;
	a->info = b->info;
	b->info = temp;
}

//tăng dần
void sortInc()
{
	node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;

		while (q != NULL)
		{
			if (q->info < p->info)
			{
				min = q;
			}
			q = q->link;
		}
		//swap giá trị
		swap(min, p);

		p = p->link;
	}
}

//giảm dần
void sortDec()
{
	node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;

		while (q != NULL)
		{
			if (q->info > p->info)
			{
				min = q;
			}
			q = q->link;
		}
		//swap giá trị
		swap(min, p);

		p = p->link;
	}
}

int main()
{
	node *p;
	int temp,x,i;
	do {
		cout << "===========Menu============\n";
		cout << " 1. Khoi tao danh sach\n";
		cout << " 2. Xuat cac phan tu trong danh sach\n";
		cout << " 3. Tim mot phan tu trong danh sach\n";
		cout << " 4. Them mot phan tu vao dau danh sach\n";
		cout << " 5. Xoa mot phan tu dau danh sach\n";
		cout << " 6. Them mot phan tu vao cuoi danh sach\n";
		cout << " 7. Xoa mot phan tu cuoi danh sach\n";
		cout << " 8. Tim mot phan tu roi xoa phan tu do neu tim duoc \n";
		cout << " 9. Sap xep thu tu danh sach tang dan\n";
		cout << " 10. Sap xep thu tu danh sach giam dan\n";
		cout << " 11.Thoat\n";

		do {
			cout << "Vui long chon so de thuc hien : ";
			cin >> temp;
			if (temp < 1 || temp >11)
				cout << "Nhap sai, nhap lai\n";
		} while (temp < 1 || temp >11);

		switch (temp)
		{
		case 1:
		{
			init();
			cout << "Khoi tao danh sach thanh cong\n";
			break;
		}
		case 2:
		{
			list();
			break;
		}
		case 3:
		{
			cout << "Nhap vao gia tri can tim: ";
			cin >> x;
			i = search(x);
			if (i>0)
				cout << "Tim thay gia tri x\n";
			else
				cout << "Khong tim thay gia tri x\n";
			break;
		}
		case 4:
		{
			cout << "Nhap vao gia tri can them: ";
			cin >> x;
			Add_first(x);
			cout << "Danh sach sau khi them: \n";
			list();
			cout << endl;
			break;
		}
		case 5:
		{
			i = delete_first();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa\n";
			else
			{
				cout << "Xoa thanh cong\n";
				cout << "Danh sach sau khi xoa\n";
				list();
				cout << endl;
			}
			break;
		}
		case 6: 
		{
			cout << "Nhap vao gia tri can them: ";
			cin >> x;
			Add_last(x);
			cout << "Danh sach sau khi them: \n";
			list();
			cout << endl;
			break;
		}
		case 7:
		{
			i = delete_last();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa\n";
			else
			{
				cout << "Xoa thanh cong\n";
				cout << "Danh sach sau khi xoa\n";
				list();
				cout << endl;
			}
			break;
		}
		case 8:
		{
			cout << "Nhap vao gia tri can xoa: ";
			cin >> x;
			i = Find_delete(x);
			if (i == 0)
				cout << "Danh sach rong, khong the xoa\n ";
			else
			{
				cout << "Tim thay va xoa thanh cong\n";
				cout << "Danh sach sau khi xoa\n";
				list();
				cout << endl;
			}
			break;
		}
		case 9:
		{
			sortInc();
			cout << "Danh sach sau khi sap xep: \n";
			list();
			cout << endl;
			break;
		}
		case 10:
		{
			sortDec();
			cout << "Danh sach sau khi sap xep: \n";
			list();
			cout << endl;
			break;
		}
		}
	} while (temp != 11);

	system("pause");
	return 0;
}