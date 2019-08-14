//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//using namespace std;
//
//#define MAX 20
//int A[MAX][MAX];
//int n;
//char vertex[MAX];
//
////DSLK sd cho STACK va QUEUE
//struct Node
//{
//	int info;
//	Node *link;
//};
//
//Node *sp;
//Node *front, *rear;
//
////STACK
//void InntStack ()
//{
//	sp = NULL;
//}
//int IsEmptyStack ()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void PushStack (int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//int PopStack (int &x)
//{
//	if (sp != NULL)
//	{
//		Node *p = sp; 
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//
////QUEUE
//void InitQueue ()
//{
//	front = NULL;
//	rear = NULL;
//}
//int IsEmptyQueue ()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void PushQueue(int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else 
//		rear->link = p;
//	rear = p;
//}
//int PopQueue (int &x)
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		front = p->link;
//		x = p->info;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//void InitGraph()
//{
//	n = 0;
//}
//
//void InputGraphFromText()
//{
//	string line;
//	ifstream myfile ("matranke1.txt");
//	if (myfile.is_open())
//	{
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile>>vertex[i];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; i < n; i++)
//				myfile>>A[i][j];
//	}
//}
//
////Cau 4.1: Nhap ma tran ke cua do thi
//void inputGraph()
//{
//	cout<<"Nhap so dinh do thi n: ";
//	cin>>n;
//	for (int i=0; i<n; i++)
//	{
//		cout<<"Nhap ten dinh: ";
//		cin>>vertex[i];
//		cout<<"Nhap vao dong thu "<<i+1<<": ";
//		for (int j=0; j<n; j++)
//			cin>>A[i][j];
//	}
//}
//
////Cau 4.2: Xuat ma tran ke cua do thi
//void outputGraph ()
//{
//	for (int i=0; i<n; i++)
//	{
//		for (int j=0; j<n; j++)
//			cout<<A[i][j]<<"  ";
//		cout<<endl;
//	}
//}
//
//void output (int a[], int n)
//{
//	for (int i=0; i<n; i++)
//		cout<<vertex[a[i]]<<"  ";
//}
//
////Cau 4.3: Duyet do thi theo chieu rong BFS (QUEUE va DSLK don)
//int c[100], bfs[100];
//int nbfs=0; 
//void Init_c()
//{
//	for (int i=0; i<n; i++)
//		c[i]=1;
//}
//void BFS (int v)
//{
//	int w, p;
//	PushQueue(v);
//	c[v] = 0;
//	while (front != NULL)
//	{
//		PopQueue (p);
//		bfs[nbfs]=p;
//		nbfs++;
//		for (w=0; w<n; w++)
//			if (c[2] && A[p][w] == 1)
//			{
//				PushQueue(w);
//				c[w]=0;
//			}
//	}
//}
//
////Cau 4.4:  Duyet do thi the chieu sau DFS(STACK va DSLK don)
//int dfs[100];
//int ndfs=0;
//void DFS(int s)
//{
//	PushStack(s);
//	dfs[ndfs]=s;
//	ndfs++;
//	c[s]=0;
//	int v=-1, u=s;
//	while (IsEmptyStack() == 0)
//	{
//		if (v==n)
//			PopStack(u);
//		for (v=0; v<n; v++)
//			if (A[u][v] != 0 && c[v]==1)
//			{
//				PushStack(u);
//				PushStack(v);
//				dfs(ndfs)=v;
//				ndfs++;
//				c[v] = 0;
//				u = v;
//				break;
//
//			}
//	}
//}
//
////Cau 4.5:
//void Search_by_BFS (int x, int v)
//{
//	int w, p;
//	PushQueue(v);
//	c[v]=0;
//	while (front != NULL)
//	{
//		PopQueue(p);
//		if (x==p)
//		{
//			cout<<"tim thay x="<<x<<endl;
//			return;
//		}
//		for (w=0; w<n; w++)
//			if (c[w] && A[p][w]==1)
//			{
//				PushQueue(w);
//				c[w]=0;
//			}
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
//	cout << "2. Nhap MA TRAN KE	tu file text" << endl;
//	cout << "3. Nhap MA TRAN KE" << endl;
//	cout << "4. Xuat MA TRAN KE" << endl;
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
//
