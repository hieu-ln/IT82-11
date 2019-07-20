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
//int input(int x)
//{
//	Node *q = new Node;
//	q->info = x;
//	q->link = NULL;
//	if(first == NULL){
//		first = q;
//		return 0;
//	}else{
//		if(first->info > q->info){
//			q->link = first;
//			first = q;
//			return 0;
//		}
//		Node *p = first;
//		while(p->link != NULL)
//		{
//			if(p->info < q->info){
//				if((p->link)->info > q->info)
//				{
//					q->link = p->link;
//					p->link = q;
//					return 0;
//				}
//				if((p->link)->info < q->info)
//					p = p->link;
//			}
//		}
//		p->link = q;
//		return 0;
//	}
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
//int search(int x)
//{
//	Node *p = first;
//	while(p->link != NULL){
//		if(p->info == x)
//			return 0;
//		p = p->link;
//	}
//	return 1;
//}
//int searchdelete(int x)
//{
//	if(first == NULL)
//		return 1;
//	Node *p = first;
//	Node *q = new Node;
//	while(p->link != NULL && p->info != x){
//		q = p;
//		p = p->link;
//	}
//	if(p->info != x)
//		return 1;
//	else{
//		if(p == first){
//			if(p->link == NULL){
//				first = NULL;
//			}else{
//				first = p->link;
//				delete p;
//			}
//		}else{
//			q->link = p->link;
//			delete p;
//		}
//	}
//	return 0;
//}
//int main(){
//	cout<<"-DANH SACH CAU LENH-"<<endl;
//	cout<<"1. Khoi tao danh sach rong"<<endl;
//	cout<<"2. Them 1 vao tu vao danh sach"<<endl;
//	cout<<"3. Xuat danh sach"<<endl;
//	cout<<"4. Tim 1 phan tu trong danh sach"<<endl;
//	cout<<"5. Thoat"<<endl;
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
//			int x;
//			cout<<"Nhap phan tu can them: ";
//			cin>>x;
//			if(input(x) == 0)
//				cout<<"Da them phan tu thanh cong!"<<endl;
//			output();
//			break;
//		case 3:
//			output();
//			break;
//		case 4:
//			int y;
//			cout<<"Nhap phan tu can tim: ";
//			cin>>y;
//			if(search(y) == 0)
//				cout<<"Da tim thay phan tu trong mang!"<<endl;
//			else
//				cout<<"Khong tim thay phan tu trong mang!"<<endl;
//			break;
//		case 5:
//			int z;
//			cout<<"Nhap phan tu can tim: ";
//			cin>>z;
//			if(searchdelete(z) == 0)
//				cout<<"Da xoa phan tu vua tim trong mang!"<<endl;
//			else
//				cout<<"Khong tim thay phan tu trong mang de xoa!"<<endl;
//			output();
//			break;
//		}
//	}while(chon != 6);
//	return 0;
//}