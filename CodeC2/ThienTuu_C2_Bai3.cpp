//#include <iostream>
//using namespace std;
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *first;
//void init()
//{
//	first = NULL;
//	cout<<"Khoi tao mang rong thanh cong!"<<endl;
//}
//void output()
//{
//	Node *p;
//	p = first;
//	cout<<"Mang: ";
//	while(p != NULL){
//		cout<<p->info<<"\t";
//		p = p->link;
//	}
//	cout<<endl;
//}
//Node * search()
//{
//	int x;
//	cout<<"Nhap phan tu can tim: ";
//	cin>>x;
//	Node *p = first;
//	while(p != NULL && p->info != x)
//		p=p->link;
//	return p;
//}
//void themdau()
//{
//	int x;
//	cout<<"Nhap phan tu can them: ";
//	cin>>x;
//	Node * p;
//	p = new Node;
//	p->info = x;
//	p->link = first;
//	first = p;
//}
//void xoadau()
//{
//	if(first != NULL){
//		Node *p = first;
//		first = p->link;
//		delete p;
//		output();
//	}else
//		cout<<"Mang rong khong the xoa!"<<endl;
//}
//void themcuoi()
//{
//	int x;
//	cout<<"Nhap phan tu can them: ";
//	cin>>x;
//	Node * q = new Node;
//	q->info = x;
//	q->link = NULL;
//	if(first == NULL)
//		first = q;
//	else{
//		Node * p = first;
//		while(p->link != NULL)
//			p=p->link;
//		p->link = q;
//	}
//}
//void xoacuoi()
//{
//	Node * p =first, *q = NULL;
//	while(p->link != NULL)
//	{
//		q = p;
//		p = p->link;
//	}
//	if(p != first)
//		q->link = NULL;
//	else
//		first = NULL;
//	delete p;
//}
//void timvaxoa()
//{
//	Node *p = first, *q = NULL;
//	int x;
//	cout<<"Nhap phan tu can xoa: ";
//	cin>>x;
//	if(first != NULL){
//	while(p->link != NULL && p->info != x)
//	{
//		q = p;
//		p= p->link;
//	}
//	if(p->info != x)
//		cout<<"Khong tim thay phan tu de xoa"<<endl;
//	else{
//	if(p == first){
//		if(p->link == NULL)
//			first = NULL;
//		else{
//			first = p->link;
//			delete p;
//		}
//	}else{
//			q->link = p->link;
//			delete p;
//		}
//	}
//	}else cout<<"Mang rong!"<<endl;
//}
//int main(){
//	cout<<"-DANH SACH CAU LENH-"<<endl;
//	cout<<"1. Khoi tao danh sach rong"<<endl;
//	cout<<"2. Xuat danh sach"<<endl;
//	cout<<"3. Tim phan tu trong danh sach"<<endl;
//	cout<<"4. Them 1 vao tu vao dau danh sach"<<endl;
//	cout<<"5. Xoa 1 phan tu o dau danh sach"<<endl;
//	cout<<"6. Them 1 vao tu vao cuoi danh sach"<<endl;
//	cout<<"7. Xoa 1 phan tu o cuoi danh sach"<<endl;
//	cout<<"8. Tim va xoa 1 phan tu trong danh sach"<<endl;
//	cout<<"9. Thoat"<<endl;
//	int chon;
//	do{
//		cout<<"Nhap lenh ban can su dung: ";
//		cin>>chon;
//		switch(chon)
//		{
//		case 1:
//			init();
//			break;
//		case 2:
//			output();
//			break;
//		case 3:
//			if(search() == NULL)
//				cout<<"Khong tim thay phan tu x"<<endl;
//			else
//				cout<<"Tim thay phan tu x = "<<search()<<" trong mang!"<<endl;
//			output();
//			break;
//		case 4:
//			themdau();
//			output();
//			break;
//		case 5:
//			xoadau();
//			output();
//			break;
//		case 6:
//			themcuoi();
//			output();
//			break;
//		case 7:
//			xoacuoi();
//			output();
//			break;
//		case 8:
//			timvaxoa();
//			output();
//			break;
//		}
//	}while(chon != 9);
//	return 0;
//}