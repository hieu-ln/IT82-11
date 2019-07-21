//#include <iostream>
//#include <stdio.h>
//using namespace std;
//struct node 
//{
//	int info;
//	node *link; 
//};
//node *sp;
////Khoi tao
//void init()
//{
//	sp = NULL;
//}
////Kiem tra stack rong
//int isempty()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//
//void list()
//{
//	node *p = sp;
//	while (p != NULL)
//	{
//		cout << p->info << " ";
//		p = p->link;
//	}
//	cout << endl;
//}
////Them mot phan tu vao stack
//int pop()
//{
//	if (sp == NULL)
//		return 0;
//	else
//	{
//		int x;
//		node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//}
////Xoa mot phan tu trong stack
//void push(int x)
//{
//	node *p;
//	p = new node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
////Doi so thap phan thanh nhi phan
//void Dec_Bin(int &x)
//{
//	int sodu,temp;
//	temp = x;
//	cout << "So nhi phan cua " << x << "la: ";
//	while (temp > 0)
//	{
//		sodu = temp % 2;
//		push(sodu);
//		temp = temp / 2;
//	}
//	while (sp != NULL)
//	{
//		int x;
//		node *p;
//		x = sp->info;
//		p = sp;
//		sp = sp->link;
//		delete p;
//		cout << x;
//	}
//}
//int main()
//{	
//	int temp,x,i;
//	do
//	{
//		cout << "==============Menu==============\n";
//		cout << " 1.Khoi tao stack rong\n";
//		cout << " 2.Kiem tra stack rong\n";
//		cout << " 3. Them mot phan tu vao stack\n";
//		cout << " 4. Xoa mot phan tu trong stack\n";
//		cout << " 5. Doi so thap phan thanh nhi phan\n";
//		cout << " 6. thoat\n";	
//		cout << "Vui long chon so de thuc hien: ";
//		cin >> temp;
//	
//		switch(temp)
//		{
//			case 1:
//			{
//				init();
//				cout << "Khoi tao stack thanh cong\n";
//				break;
//			}
//			case 2:
//			{
//				i = isempty();
//				if (i > 0)
//					cout << "Danh stack rong\n";
//				else
//					cout << "Danh stack khong rong\n";
//				break;
//			}
//			case 3:
//			{
//				cout << "Nhap vao so can them: ";
//				cin >> x;
//				push(x);
//				cout << "Them thanh cong\n";
//				list();
//				break;
//
//			}
//			case 4:
//			{
//				int i = pop();
//				if (i > 0)
//				{
//					cout << "Xoa thanh cong\n";
//					cout << "Danh sach sau khi xoa: ";
//					list();
//				}
//				else
//					cout << "Danh sach rong, khong the xoa\n";
//				break;
//			}
//			case 5:
//			{
//				cout << "Nhap vao so can doi sang nhi phan: ";
//				cin >> x;
//				Dec_Bin(x);
//				cout << endl;
//				break;
//			}
//		}
//	} while (temp != 7);
//	system("pause");
//	return 0;
//}