//#include <stdio.h>
//#include <iostream>
//using namespace std;
////Khai bao 
//struct Node
//{
//	int info;
//	Node* link;
//};
//Node* first1;
//Node* first2;
//Node* first3;
//Node* first4;
//Node* first5;
//Node* first6;
////Khoi tao 
//void Init(Node* f)
//{
//	f = NULL;
//}
////Xuat cac phan tu trong ds
//void Process_list(Node* f)
//{
//	Node* p;
//	p = f;
//	while (p != NULL)
//	{
//		cout << p->info << "\t";
//		p = p->link;
//	}
//	cout << endl;
//}
//
//
////Chen mot phan tu vao dau ds
//void Insert_first(Node*& f, int x)
//{
//	Node* p;
//	p = new Node;
//	p->info = x;
//	p->link = f;
//	f = p;
//}
//
////Ham xoa phan tu trong first4
//int SearchAndDelete(int x)
//{
//	if (first4 != NULL)
//	{
//		Node* p, * q;
//		p = first4;
//		q = first4;
//		while (p->info != x && p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first4 && p != NULL)
//		{
//			if (p->link != NULL)
//				q->link = p->link;
//			else
//				q->link = NULL;
//			delete p;
//
//			return 1;
//		}
//		else if (p == first4)
//		{
//			first4 = p->link;
//			delete p;
//			return 1;
//		}
//		else
//			return 0;
//	}
//	return 0;
//}
////tap hop cua hai danh sach
//void PhanTu2DS()
//{
//	Init(first5);
//	for (Node* p = first1; p != NULL; p = p->link)
//		Insert_first(first4, p->info);
//	for (Node* q = first2; q != NULL; q = q->link)
//		Insert_first(first4, q->info);
//	Node* q = new Node;
//	for (Node* p = first4; p != NULL; p = p->link)
//		for (q = p->link; q != NULL; q = q->link)
//			if (p->info == q->info)
//				Insert_first(first5, p->info);
//
//	for (Node* k = first5; k != NULL; k = k->link)
//		SearchAndDelete(k->info);
//}
////Ham giao
//void Giao()
//{
//	Init(first3);
//	for (Node* p = first1; p != NULL; p = p->link)
//		for (Node* q = first2; q != NULL; q = q->link)
//			if (p->info == q->info)
//				Insert_first(first3, p->info);
//}
//
////Ham bu
//void Bu()
//{
//	Init(first6);
//
//	for (Node* p = first4; p != NULL; p = p->link)
//		for (Node* q = first3; q != NULL; q = q->link)
//		{
//			if (p->info == q->info)
//				Insert_first(first6, p->info);
//		}
//	for (Node* k = first6; k != NULL; k = k->link)
//		SearchAndDelete(k->info);
//}
//
//int main()
//{
//	int choice = 0;
//	int x, i;
//	Node* p;
//	system("cls");
//	cout << " -------- BAI TAP 16, CHUONG 2, QUAN LY TAP HOP CAC PHAN TU SO NGUYEN (DSLK)--------" << endl;
//	cout << "1. Khoi tao DSLK DON 1 rong" << endl;
//	cout << "2. Them phan tu vao dau DSLKD 1" << endl;
//	cout << "3. Khoi tao DSLK DON 2 rong" << endl;
//	cout << "4. Them phan tu vao dau DSLKD 2" << endl;
//	cout << "5. Cac phan tu thuoc tap hop cua hai danh sach" << endl;
//	cout << "6. Tap hop GIAO cua hai danh sach" << endl;
//	cout << "7. Danh sach phan BU cua hai danh sach" << endl;
//	cout << "8. Thoat" << endl;
//
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			Init(first1);
//			cout << "Ban vua khoi tao DSLKD 1 thanh cong \n";
//			break;
//
//		case 2:
//			cout << "Vui long nhap x can them: ";
//			cin >> x;
//			Insert_first(first1, x);
//			cout << "Danh sach sau 1 khi them la: ";
//			Process_list(first1);
//			break;
//		case 3:
//			Init(first2);
//			cout << "Ban vua khoi tao DSLKD 2 thanh cong \n";
//			break;
//		case 4:
//			cout << "Vui long nhap x can them: ";
//			cin >> x;
//			Insert_first(first2, x);
//			cout << "Danh sach 2 sau khi them la: ";
//			Process_list(first2);
//			break;
//		case 5:
//			PhanTu2DS();
//			cout << "Cac phan tu thuoc tap hop cua hai danh sach la: " << endl;
//			Process_list(first4);
//			break;
//		case 6:
//			Giao();
//			cout << "Danh sach GIAO: ";
//			Process_list(first3);
//			break;
//		case 7:
//			Bu();
//			cout << "Danh sach BU: ";
//			Process_list(first4);
//			break;
//		case 8:
//			cout << "\nGoodbye!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}