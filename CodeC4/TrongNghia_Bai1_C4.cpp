#include <iostream>
using namespace std;

#define COUNT 10
//1.1 Khai bao cau truc
struct Node
{
	int info;
	Node* left, * right;
};
Node* root;
//1.2 Khoi tao cay rong
void empInit()
{
	root = NULL;
}
//1.3 Them mot phan tu vao cay
void insertNode(int x, Node*& p)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else if (x == p->info)
		return;
	else if (x < p->info)
		insertNode(x, p->left);
	else
		insertNode(x, p->right);
}
//1.4 Tim kiem mot phan tu
Node* Search(Node* p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else if (x < p->info)
			return Search(p->left, x);
		else return Search(p->right, x);
	}
	else return NULL;
}
//1.5 Xoa mot phan tu
void searchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p = q;
		q = q->right;
	}
	else searchStandFor(p, q->left);
}
int deleteNode(Node*& q, int x)
{
	if (q == NULL)
		return 0;
	else if (x < q->info)
		return deleteNode(q->left, x);
	else if (x > q->info)
		return deleteNode(q->right, x);
	else
	{
		Node* p = q;
		if (q->left == NULL) // Bac 1
			q = q->right;
		else if (q->right == NULL) // Bac 1
			q = q->left;
		else // Bac 2
			searchStandFor(p, q->right);
		delete p;
		return 1;
	}
}
//1.6 Duyet NLR
void duyetNLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//1.7 Duyet LNR
void duyetLNR(Node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}
//1.8 Duyet LRN
void duyetLRN(Node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
// Xuat cay NPTK
void print2DUlti(Node* p, int space)
{
	//Truong hop co ban
	if (p == NULL)
		return;
	else {
		space += COUNT; // Tang khoang cach cho moi bac
		print2DUlti(p->right, space); // Xuat cay con ben phai truoc
		// Xuat node hien tai
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << p->info << endl;
		print2DUlti(p->left, space); // Xuat cay con ben trai
	}
}
void Process_Tree() {
	print2DUlti(root, 0);
}
// Xuat Menu
void xuatMenu()
{
	cout << "----- Chuong 4 Bai 1 -----\n";
	cout << "1) Khoi tao cay NPTK rong\n";
	cout << "2) Them phan tu vao cay NPTK\n";
	cout << "3) Tim kiem mot phan tu trong cay NPTK\n";
	cout << "4) Xoa mot phan tu trong cay NPTK\n";
	cout << "5) Duyet cay NPTK theo NLR\n";
	cout << "6) Duyet cay NPTK theo LNR\n";
	cout << "7) Duyet cay NPTK theo LRN\n";
	cout << "8) Xuat cay NPTK\n";
	cout << "9) Clear man hinh console\n";
	cout << "10) Thoat\n";
}

int main()
{
	int choice, x, i;
	Node* p;
	xuatMenu();
	do {
		cout << "Lua chon cua ban: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			empInit();
			cout << "Khoi tao thanh cong!!!\n";
			break;
		case 2:
			cout << "Hay nhap gia tri muon them: ";
			cin >> x;
			insertNode(x, root);
			cout << "Them thanh cong phan tu " << x << " vao cay NPTK\n";
			break;
		case 3:
			cout << "Hay nhap gia tri muon tim kiem: ";
			cin >> x;
			p = Search(root, x);
			if (p != NULL)
				cout << "Gia tri " << x << " da duoc tim thay trong cay NPTK\n";
			else cout << "Gia tri " << x << " khong ton tai trong cay NPTK\n";
			break;
		case 4:
			cout << "Hay nhap gi tri muon xoa: ";
			cin >> x;
			i = deleteNode(root, x);
			if (i == 0)
				cout << "Gia tri " << x << " khong ton tai trong cay NPTK\n";
			else
				cout << "Da xoa thanh cong phan tu " << x << " ra khoi cay NPTK\n";
			break;
		case 5:
			cout << "Duyet cay theo NLR: ";
			duyetNLR(root); cout << endl;
			break;
		case 6:
			cout << "Duyet cay theo LNR: ";
			duyetLNR(root); cout << endl;
			break;
		case 7:
			cout << "Duyet cay theo LRN: ";
			duyetLRN(root); cout << endl;
			break;
		case 8:
			cout << "Cay NPTK hien tai la:\n";
			Process_Tree();
			break;
		case 9:
			system("cls");
			xuatMenu();
			break;
		}
	} while (choice != 10);
	return 0;
}