//#include <iostream>
//#include <stdio.h>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *front, *rear;
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void push(int x)
//{
//	node *p;
//	p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (front == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//
//int pop(int &x)
//{
//	node *p=front;
//	if (front != NULL)
//	{
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
//void list()
//{
//	node *p;
//	cout << " <-- ";
//	p = front;
//	do
//	{
//		cout << p->info << " ";
//		p = p->link;
//	}  while (p != NULL);
//	cout << endl;
//}
//int main()
//{
//	int temp, x, i;
//	do
//	{
//		cout << "==============Menu==============\n";
//		cout << " 1.Khoi tao queue rong\n";
//		cout << " 2.Kiem tra queue rong\n";
//		cout << " 3. Them mot phan tu vao queue\n";
//		cout << " 4. Xoa mot phan tu trong queue\n";
//		cout << " 5. thoat\n";
//
//		do {
//			cout << "Nhap vao lua chon: ";
//			cin >> temp;
//		} while (temp < 1 || temp > 5);
//
//		switch (temp)
//		{
//		case 1:
//		{
//			init();
//			cout << "KHoi tao queue thanh cong\n";
//			break;
//		}
//		case 2:
//		{
//			i = isEmpty();
//			if (i > 0)
//				cout << "Danh sach rong \n";
//			else
//				cout << "Danh sach khong rong\n";
//			break;
//		}
//		case 3:
//		{
//			cout << "Nhap vao phan tu can them";
//			cin >> x;
//			push(x);
//			cout << "Queue sau khi them: ";
//			list();
//		}
//		case 4:
//		{
//			pop(x);
//			cout << "Phan tu lay ra tu queue: ";
//			cout << "Queue sau khi xoa: ";
//			list();
//		}
//		}
//	} while (temp != 5);
//}