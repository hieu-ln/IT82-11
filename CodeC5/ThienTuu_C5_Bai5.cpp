#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
struct Node{
	int info;
	Node *link;
};
Node *first[MAX];
int n;
void init(){
	for(int i=0; i<n; i++)
		first[i]=NULL;
}
void insert_first(Node *&f, int x){
	Node *p;
	p = new Node;
	p->info = x;
	p->link = f;
	f = p;
}
void input(){
	int d, x, m;
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout<<"Nhap dinh thu "<<i+1<<": ";
		cin >> d;
		insert_first(first[i], d);
		cout << "Nhap vao so dinh ke cua " <<d<<": ";
		cin >> m;
		for(int j=0;j<m
			;j++)
		{
			cout << "Dinh ke thu " <<j+1<< ": ";
			cin>>x;
			insert_first(first[i], x);
		}
	}
}
void output_list(Node *f){
	if(f!=NULL)
	{
		Node *p=f;
		while(p!=NULL)
		{
			if(p->link == NULL)
				cout << p->info << endl;
			else
				cout << p->info<< " <-- ";
			p=p->link;
		}
	}
}
void output(){
	if(n>0){
		for(int i=0;i<n;i++)
		{
			output_list(first[i]);
		}
	}
	else
		cout << "Rong\n";
}
Node *sp;
Node *front, *rear;
int x;
void initS(){
	sp = NULL;
}
void PushS(int x){
	Node *p = new Node;
	p->info=x;
	p->link = sp;
	sp = p;
}
int PopS(int &x){
	if(sp!=NULL)
	{
		Node *p = sp;
		x = p ->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
int isEmptyS(){
	if(sp == NULL)
		return 1;
	return 0;
}
void initQ(){
	front = NULL;
	rear = NULL;
}
void PushQ(int x){
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x){
	if(front != NULL)
	{
		Node *p = front;
		x=p->info;
		front = front -> link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int isEmptyQ(){
	if(front == NULL)
		return 1;
	return 0;
}
int a[MAX][MAX];
char vertex[MAX];
void outputMaTran(){
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
}
void inputFile(){
	string line;
	ifstream myfile ("matranke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i = 0; i<n; i++)
			myfile>>vertex[i];
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
				myfile>>a[i][j];
		}
	}
}
void outputs(int a[], int n){
	for(int i =0; i<n; i++)
		cout << vertex[a[i]] << "   ";
	cout << endl;
}
int C[100], bfs[100];
int nbfs=0;
void initC(){
	for(int i = 0; i<n; i++)
		C[i] = 1;
}
void BFS(int v){
	int w, p;
	PushQ(v);
	C[v] = 0;
	while(front !=NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0;w<n;w++)
			if(C[w]&&a[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
}
int dfs[100];
int ndfs = 0;
void DFS(int s){
	PushS(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	int v=-1, u=s;
	while(!isEmptyS())
	{
		if(v==n)
			PopS(u);
		for(v=0;v<n;v++)
			if(a[u][v]!=0 && C[v]==1)
			{
				PushS(v);
				dfs[ndfs]=v;
				ndfs++;
				C[v]=0;
				u=v;
				break;
			}
	}
}
void SearchByBFS(int x, int v){
	int w, p;
	PushQ(v);
	C[v]=0;
	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x=" << x << endl;
			return;
		}
		for(w=0;w<n;w++)
			if(C[w]&&a[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
	cout << "Khong tim thay\n";
}
int main(){
	int chon;
	cout <<"MENU:\n";
	cout <<"1. Khoi tao ma tran rong\n";
	cout <<"2. Nhap ma tran ke bang file\n";
	cout <<"3. Nhap danh sach ke\n";
	cout <<"4. Xuat danh sach ke\n";
	cout <<"5. Duyet do thi theo BFS\n";
	cout <<"6. Duyet do thi theo DFS\n";
	cout <<"7. Tim va kiem tra dinh X co ton tai hay khong theo BFS\n";
	cout <<"8. Thoat\n";
	do{
		cout <<"Chon: ";
		cin >> chon;
		switch(chon){
		case 1:
			init();
			cout << "Khoi tao mang MA TRAN KE rong thanh cong\n";
			break;
		case 2:
			inputFile();
			cout << "Ban vua nhap mang MA TRAN KE tu file: \n";
			outputMaTran();
			break;
		case 3:
			input();
			output();
			break;
		case 4:
			output();
			break;
		case 5:
			initQ();
			initC();
			cout << "Chon dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: \n";
			outputs(bfs, n);
			break;
		case 6:
			initS();
			initC();
			cout << "Chon dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: \n";
			outputs(dfs, n);
			break;
		case 7:
			cout << "Nhap gia tri can tim x=";
			cin >> x;
			SearchByBFS(x, 0);
			break;
		}
	}while(chon!=8);
	system("pause");
	return 0;
}