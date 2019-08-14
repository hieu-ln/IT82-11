//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//#include <sstream>
//using namespace std;
//
//#define MAX 20
//struct Node
//{
//	int info;
//	Node *link;
//};
//
//Node *First[MAX]; 
//int n;
//char vertex[MAX];
//
//Node *sp;
//Node *front, *rear;
//
////STACK
//void Init_Stack()
//{
//	sp = NULL;
//}
//
//int isEmptyS()
//{
//	if(sp == NULL)
//		return 1;
//	return 0;
//}
//
//void PushS(int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//
//int PopS(int &x)
//{
//	if(sp != NULL)
//	{
//		Node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////End STACK
//
////QUEUE
//void Init_Queue()
//{
//	front = NULL;
//	rear = NULL;
//}
//
//int isEmptyQ()
//{
//	if(front == NULL)
//		return 1;
//	return 0;
//}
//
//void PushQ(int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if(rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//
//int PopQ(int &x)
//{
//	if(front != NULL)
//	{
//		Node *p = front;
//		front = p->link;
//		x = p->info;
//		if(front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////End QUEUE
//
//void Init_Graph()
//{
//	n = 0;
//}
//
//void Insert_Last(Node *&first, Node *p)
//{
//	if(first == NULL)
//		first = p;
//	else
//	{
//		Node *q = first;
//		while(q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
//
////Cau 5.1: Nhap ma tran ke
//void Input_Graph_From_Text()
//{
//	string line;
//	ifstream myfile("danhsachke1.txt");
//	if(myfile.is_open())
//	{
//		myfile >> n;
//		for(int i=0; i<n; i++)
//			myfile >> vertex[i];
//		
//		string str;
//		int i=0;
//		while(getline(myfile, str))
//		{
//			istringstream ss(str);
//			int u;
//			while (ss >> u)
//			{
//				Node *p = new Node;
//				p->info = u;
//				p->link = NULL;
//				Insert_Last(First[i-1], p);
//			}
//			i++;
//		}
//		
//	}
//}
//
////Cau 5.2: Xuất ma trận kề của đồ thị
//void Output_Graph()
//{
//	for(int i=0; i<n; i++)
//	{
//		cout << "Dinh "<< i <<" ("<< vertex[i] <<"): ";
//		Node *p = First[i];
//		while(p != NULL)
//		{
//			cout << p->info << " ";
//			p = p->link;
//		}
//		cout << endl;
//	}
//}
//
//void Output(int a[], int n)
//{
//	for(int i=0; i<n; i++)
//		cout << vertex[ a[i] ] << " ";
//}
//
////Cau 5.3: Duyệt đồ thị theo chiều rộng BFS
//int C[100], bfs[100];
//int nbfs = 0;
//void InitC()
//{
//	for(int i=0; i<n; i++) 
//		C[i] = 1;
//}
//void BFS(int v) 
//{
//	int p;
//	Node *w;
//	PushQ(v);
//	C[v] = 0;
//	while(front != NULL)
//	{
//		PopQ(p);
//		bfs[nbfs] = p;
//		nbfs++;
//		while(w != NULL)
//		{
//			if(C[w->info])
//			{
//				PushQ(w->info);
//				C[w->info] = 0;
//			}
//			w = w->link;
//		}
//	}
//}
//
////Cau 5.4: Duyệt đồ thị theo chiều sâu DFS
//int dfs[100];
//int ndfs = 0;
//void DFS(int s)
//{
//	PushS(s);
//	dfs[ndfs] = s;
//	ndfs++;
//	C[s] = 0;
//	int u = s;
//	Node *v = NULL;
//	while(isEmptyS() == 0)
//	{
//		if(v == NULL)
//			PopS(u);
//		v = First[u];
//		while(v != NULL)
//		{
//			if(C[v->info] == 1)
//			{
//				PushS(u);
//				PushS(v->info);
//				dfs[ndfs] = v->info;
//				ndfs++;
//				C[v->info] = 0;
//				u = v->info;
//				break;
//			}
//			v = v->link;
//		}
//	}
//}
//
////Cau 5.5: Dùng BFS tìm x trên đồ thị
//void Search_by_BFS(int x, int v)
//{
//	int p;
//	Node *w;
//	PushQ(v);
//	C[v] = 0;
//	while (front != NULL)
//	{
//		PopQ(p);
//		if(x == p)
//		{
//			cout << "Tim thay x=" << x << endl;
//			return;
//		}
//		w = First[p];
//		while(w != NULL)
//		{
//			if(C[w->info])
//			{
//				PushQ(w->info);
//				C[w->info] = 0;
//			}
//			w = w->link;
//		}
//	}
//}
//
//int main()
//{
//	int a[MAX];
//	int b[MAX];
//	int choice, x, i;
//	system("cls");
//	cout << "------- BAI TAP 4, CHUONG 5, DO THI ---------" << endl;
//	cout << "1. Khoi tao MA TRAN KE rong" << endl;
//	cout << "2. Nhap DANH SACH KE	tu file text" << endl;
//	cout << "3. Nhap DANH SACH KE" << endl;
//	cout << "4. Xuat DANH SACH KE" << endl;
//	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
//	cout << "6. Duyet do thi theo chieu sau DFS - DSLK" << endl;
//	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
//	cout << "8. Thoat" << endl;
//	do{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch(choice)
//		{
//			case 1:
//				Init_Graph();
//				cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
//				break;
//			case 2:
//				Input_Graph_From_Text();
//				cout << "Ban vua nhap MA TRAN KE tu file: \n";
//				Output_Graph();
//				break;
//			case 3:
//				Input_Graph();
//				break;
//			case 4:
//				Output_Graph();
//				break;
//			case 5:
//				Init_Queue();
//				InitC();
//				cout << "Vui long nhap dinh xuat phat: ";
//				cin >> x;
//				nbfs = 0;
//				BFS(x);
//				cout << "Thu tu dinh sau khi duyet BFS: " << endl;
//				Output(bfs, n);
//				break;
//			case 6:
//				Init_Stack();
//				InitC();
//				cout << "Vui long nhap dinh xuat phat: ";
//				cin >> x;
//				ndfs = 0;
//				DFS(x);
//				cout << "Thu tu dinh sau khi duyet DFS: " << endl;
//				Output(dfs, n);
//				break;
//			case 7:
//				Init_Queue();
//				InitC();
//				nbfs = 0;
//				cout << "Vui long nhap gia tri x can tim: ";
//				cin >> x;
//				Search_by_BFS(x, 0);
//				break;
//			case 8:
//				cout << "Goodbye ......!" << endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice != 8);
//	system("pause");
//	return 0;
//}