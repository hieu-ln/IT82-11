//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//#include <iomanip>
//using namespace std;
//
//#define MAX 20
//int A[MAX][MAX];
//int n;	//so dinh cua do thi
//char vertex[MAX];	// ten dinh
//
//// dslk dung STACK va QUEUE
//struct node {
//	int info;
//	node *link;
//};
//node *sp;
//node *front, *rear;
//
////STACK
//void Init_stack() {
//	sp = NULL;
//}
//int isEmpty_stack() {
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void Push_stack(int x) {
//	node *p = new node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//int Pop_stack(int &x) {
//	if (sp != NULL) {
//		node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//// QUEUE
//void Init_queue() {
//	front = NULL;
//	rear = NULL;
//}
//int isEmpty_queue() {
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void Push_queue(int x) {
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int Pop_queue(int &x) {
//	if (front != NULL) {
//		node *p = front;
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
//// GRAPH
//void Init_Graph() {
//	n = 0;
//}
//void input_Grap_front_text() {
//	string line;
//	ifstream myfile ("matranke1.txt");
//	if (myfile.is_open()) {
//		myfile >> n;
//			for (int i=0; i<n; i++)
//				myfile >> vertex[i];
//			for (int i=0; i<n; i++)
//				for (int j=0; j<n; j++)
//					myfile>>A[i][j];
//	}
//}
//void input_Graph_by_hand() {
//	cout<<"Nhap so dinh cua do thi: ";
//	cin>>n;
//	for (int i=0; i<n; i++) {
//		cout<<"Nhap ten dinh: ";
//		cin>>vertex[i];
//		cout<<"Nhap vo dong thu "<<i+1<<": ";
//		for (int j=0; j<n; j++)
//			cin>>A[i][j];
//	}
//}
//void output_Graph() {
//	for (int i=0; i<n; i++) {
//		for (int j=0; j<n; j++)
//			cout<<setw(3)<<A[i][j];
//		cout<<endl;
//	}
//}
//void output(int a[], int n) {
//	for (int i=0; i<n; i++)
//		cout<<setw(4)<<vertex[a[i]];
//	cout<<endl;
//}
//
//// Duyet Graph theo BFS - queue - dslk
//int C[100], bfs[100];
//int nbfs = 0;
//void InitC() {
//	for (int i = 0; i < n; i++)
//		C[i] = 1;
//}
//void BFS(int v) {
//	int w, p;
//	Push_queue(v);
//	C[v] = 0;
//	while (front != NULL) {
//		Pop_queue(p);
//		bfs[nbfs] = p;
//		nbfs++;
//		for (w = 0; w < n; w++)
//			if (C[w] && A[p][w] == 1) {
//				Push_queue(w);
//				C[w] = 0;
//			}
//	}
//}
//
//// Duyet Grap theo DFS - stack - dslk
//int dfs[100];
//int ndfs = 0;
//void DFS(int s) {
//	Push_stack(s);
//	dfs[ndfs] = s;
//	ndfs++;
//	C[s] = 0;
//	int v = -1, u = s;
//	while (isEmpty_stack() == 0) {
//		if (v == n)
//			Pop_stack(u);
//		for (v = 0; v < n; v++)
//			if (A[u][v] != 0 && C[v] == 1) {
//				Push_stack(u);
//				Push_stack(v);
//				dfs[ndfs] = v;
//				ndfs++;
//				C[v] = 0;
//				u=v;
//				break;
//			}
//	}
//}
//void Search_by_bfs(int x, int v) // v la dinh bat dau
//{
//	int w, p;
//	Push_queue(v);
//	C[v] = 0;
//	while(front != NULL) {
//		Pop_queue(p);
//		if (x == p) {
//			cout<<"Tim thay!"<<endl;
//			return;
//		}
//		for (w=0; w<n; w++)
//			if (C[w] && A[p][w] == 1) {
//				Push_queue(w);
//				C[w] = 0;
//			}
//	}
//}
//int main()
//{
//	int a[MAX], b[MAX];
//	int choice, sp, sp_b, x, i;
//	system("cls");
//	cout<<"---------- BAT TAP 4, CHUONG 5, DO THI ----------"<<endl;
//	cout<<"1. Khoi tao ma tran ke rong."<<endl;
//	cout<<"2. Nhap ma tran ke tu file text."<<endl;
//	cout<<"3. Nhap ma tran ke bang tay."<<endl;
//	cout<<"4. Xuat ma tran ke."<<endl;
//	cout<<"5. Duyet do thi theo BFS."<<endl;
//	cout<<"6. Duyet do thi theo DFS."<<endl;
//	cout<<"7. Tim dinh co gia tri x."<<endl;
//	cout<<"8. Thoat."<<endl;
//	do {
//		cout<<"Nhap muc: ";
//		cin>>choice;
//		switch(choice){
//		case 1:
//			Init_Graph();
//			cout<<"Khoi tao MA TRAN KE thanh cong!"<<endl;
//			break;
//		case 2:
//			input_Grap_front_text();
//			cout<<"Da nhap ma tran ke tu file: "<<endl;;
//			output_Graph();
//			break;
//		case 3:
//			input_Graph_by_hand();
//			break;
//		case 4:
//			output_Graph();
//			break;
//		case 5:
//			Init_queue();
//			InitC();
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			nbfs=0;
//			BFS(x);
//			cout<<"Thu tu danh sach sau khi duyet BFS: "<<endl;
//			output(bfs,n);
//			break;
//		case 6:
//			Init_stack();
//			InitC();
//			cout<<"Nhap dinh xuat phat: ";
//			cin>>x;
//			ndfs=0;
//			DFS(x);
//			cout<<"Thu tu danh sach sau khi duyet DFS: "<<endl;
//			output(dfs,n);
//			break;
//		case 7:
//			cout<<"Nhap gia tri x can tim: ";
//			cin>>x;
//			Search_by_bfs(x,0);
//			break;
//		case 8:
//			cout<<"Goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}