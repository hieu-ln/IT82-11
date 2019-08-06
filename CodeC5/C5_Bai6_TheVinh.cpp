#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
using namespace std;

#define MAX 20
int A[MAX][MAX];  // mang 2 chieu.
int n;			  // so dinh cua do thi
char vertex[MAX]; // mang lua ten dinh cua do thi.

int sp = -1; // Dinh cua STACK.
int a[MAX];
queue<int> q;

// STACK
// Khoi tao stack rong.
void InitStack()
{
	sp = -1;
}

// Kiem tra stack rong.
int isEmptyS()
{
	if (sp == -1)
		return 1;
	return 0;
}

// Kiem tra stack co day hay khong.
int isFullS()
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

// Them phan tu vao ngan xep.
int PushS(int a[], int x)
{
	if (isFullS() != 1)
	{
		a[++sp] = x;
		return 1;
	}
	else
		return 0;
}

// Xoa 1 phan tu.
int PopS(int a[], int &x)
{
	if (isEmptyS() != 1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
// end STACK.

// Ham khai bao do thi rong.
void InitGraph()
{
	n = 0;
}

// Cau 4.1: Nhap ma tran ke cua do thi.
// Ham cho nguoi dung nhap vao ma tran ke cua do thi.
void input_graph()
{
	cout << "\nNhap vao so dinh cua do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao so dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

//Cau 5.2: Xuat ma tran ke cua do thi
// Ham xuat ra ma tran ke cua do thi.
void output_graph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
}

// Ham xuat ra mang cac dinh cua do thi.
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "\t";
}

//Cau5.3: Duyet do thi theo chieu rong BFS (Dung QUEUE va DSD)
int C[100]; // luu tru dinh chua xet.
// 1 la chua xet; 0 la da xet.
int bfs[100]; // luu danh sach phan tu da duyet.
int nbfs = 0; // luu chi so dinh da xet.

void InitC()
{
	for (int i = 0; i < n; i++) // Gan tat ca cac gia tri la 1.
		C[i] = 1;
}

void BFS(int v)
{
	int w, p;
	q.push(v);
	C[v] = 0;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				q.push(w);
				C[w] = 0;
			}
		}
	}
}
// Cau 4.4: Duyet do thi theo chieu sau DFS (Dung STACK va DSLK don)
int dfs[100];
int ndfs = 0;

void DFS(int s)
{
	PushS(a, s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(a, u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(a, u);
				PushS(a, v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

//Cau 5.5 dung BFS tim x tren do thi.
void search_by_bfs(int x, int v)
{
	InitC();
	int w, p;
	q.push(v);
	C[v] = 0;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (x == p)
		{
			cout << x << " ton tai" << endl;
			;
			return;
		}
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				q.push(w);
				C[w] = 0;
			}
		}
	}
	cout << x << " khong ton tai" << endl;
}

void input_graph_from_text()
{
	string line;
	ifstream myfile("matranke1.txt");

	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}

int main()
{
	int choice, x;
	system("cls");

	cout << "----------------------BAI 6 CHUONG 5-------------------\n"
		 << "1. Khoi tao MA TRAN KE rong.\n"
		 << "2. Nhap MA TRAN KE.\n"
		 << "3. Xuat MA TRAN KE.\n"
		 << "4. Duyet do thi theo chieu rong BFS - DSD.\n"
		 << "5. Duyet do thi theo chieu sau DFS - DSD\n"
		 << "6. Tim dinh co gia tri x theo BFS.\n"
		 << "7. Thoat." << endl;

	do
	{
		cout << "\nNhap vao so ban muon thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "\nBan  vua khoi tao MA TRAN KE rong thanh cong.\n";
			break;
		case 2:
			/* input_graph();
			break; */
			input_graph_from_text();
			break;
		case 3:
			output_graph();
			break;
		case 4:
			InitC();
			cout << "\nNhap vao dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "\nThu tu dinh sau khi duyet BFS: " << endl;
			output(bfs, n);
			break;
		case 5:
			InitStack();
			InitC();
			cout << "\nNhap vao dinh ban muon bat dau duyet: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "\nThu tu dinh sau khi duyet DFS: ";
			output(dfs, n);
			break;
		case 6:
			cout << "\nVui long nhap vao gia tri x can tim: ";
			cin >> x;
			search_by_bfs(x, 0);
			break;
		case 7:
			cout << "\nTam biet!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);
	return 0;
}