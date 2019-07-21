//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define MAX 100
//
//int a[MAX], front, rear;
////Khoi tao danh sach
//void init(int a[], int &front, int &ear)
//{
//	front = -1;
//	rear = -1;
//}
//
//void xuat(int a[], int front, int rear)
//{
//	cout << " <-- ";
//	if (front <= rear && front != -1)
//	{
//		for (int i = front; i < rear +1; i++)
//			cout << a[i] << " ";
//	}
//	cout << " < -- ";
//	cout << endl;
//}
////Kiem tra danh sach day
//int Isfull(int a[], int front, int rear)
//{
//	if (rear - front == MAX - 1)
//		return 1;
//	return 0;
//}
////Kiem tra danh sach rong
//int Isempty(int a[], int front, int rear)
//{
//	if (front == -1)
//		return 1;
//	return 0;
//}
////phuong phap tinh tien
//int push_tt(int a[], int &front, int &rear, int x)
//{
//	if (rear - front == MAX - 1) 
//		return 0;
//	else
//	{
//		if (front == -1) 
//			front = 0;
//		if (rear == MAX - 1) 
//		{
//			for (int i = front ; i <= rear ; i++)
//				a[i - front] = a[front];
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1; 
//	}
//}
//int pop_tt(int a[], int &front, int &rear,int &x)
//{
//	if (front == -1) // trường hợp rỗng
//		return 0;
//	else
//	{
//		x = a[front++];
//		if (front > rear) //trường hợp còn đúng 1 giá trị
//		{
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//		
//	}
//}
//// phuong phap vong
//int push_vong(int a[], int &front, int &rear, int x)
//{
//	if (rear - front == MAX - 1)
//		return 0;
//	else
//	{
//		if (front == -1)
//			front = 0;
//		if (rear == MAX -1)
//		{
//			rear = -1;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//}
//int pop_vong(int a[], int &front, int &rear, int &x)
//{
//	if (front == -1)
//		return 0;
//	else
//	{
//		x = a[front++];
//		if (front == rear)
//		{
//			rear = -1;
//			front = -1;
//		}
//		if (front > MAX - 1)
//			front = 0;
//		return 1;
//	}
//}
//
//int main()
//{
//	int temp, x, i;
//
//
//	do {
//		cout << "=============Menu==============\n";
//		cout << " (1) Khoi tao danh sach\n";
//		cout << " (2) Kiem tra danh sach rong\n";
//		cout << " (3) Kiem tra danh sach day\n";
//		cout << " (4) Them vao danh sach bang phuong phap tinh tien\n";
//		cout << " (5) Them vao danh sach bang phuong phap vong\n";
//		cout << " (6) Xoa phan tu trong danh sach bang phuong phap tinh tien\n";
//		cout << " (7) xoa phan tu trong danh sach bang phuong phap vong\n";
//		cout << " (8) Thoat\n";
//		cout << "======================================================\n";
//		cout << "Vui long chon so de thuc hien : ";
//		cin >> temp;
//
//		switch (temp)
//		{
//		case 1:
//		
//			init(a, front, rear);
//			cout << "Khoi tao thanh cong\n";
//			break;
//		
//		case 2:
//		
//			i = Isempty(a, front, rear);
//			if (i == 1)
//				cout << "Danh sach rong\n";
//			else
//				cout << "Danh sach khong rong\n";
//			break;
//		
//		case 3:
//		
//			i = Isfull(a, front, rear);
//			if (i == 1)
//				cout << "Danh sach day\n";
//			else
//				cout << "Danh sach khong day\n";
//			break;
//		
//		case 4: 
//		
//			cout << "Nhap vao phan tu can them ";
//			cin >> x;
//			i = push_tt(a, front, rear, x);
//			if (i == 1)
//				cout << "Them vao thanh cong\n";
//			else
//				cout << "Them vao khong thanh cong\n";
//			cout << "Danh sach sau khi them\n";
//			xuat(a, front, rear);
//			break;
//		
//		case 5:
//		
//			cout << "Nhap phan tu can them ";
//			cin >> x;
//			i = push_vong(a, front, rear, x);
//			if (i == 1)
//				cout << "Them vao thanh cong\n";
//			else
//				cout << "Them vong khong thanh cong\n";
//			cout << "Danh sach sau khi them\n";
//			xuat(a, front, rear);
//			break;
//		
//		case 6:
//		
//			i = pop_tt(a, front, rear, x);
//			if (i == 1)
//				cout << "Xoa thanh cong\n";
//			else
//				cout << "Xoa khong thanh cong\n";
//			xuat(a, front, rear);
//			break;
//		
//		case 7:
//		
//			i = pop_vong(a, front, rear, x);
//			if (i == 1)
//				cout << "Xoa thanh cong\n";
//			else
//				cout << "Xoa khong thanh cong\n";
//			xuat(a, front, rear);
//			break;
//		
//		default:
//			cout << "Khong tim thay lua chon\n";
//		}	
//	} while (temp != 8);
//	system("pause");
//	return 0;
//}