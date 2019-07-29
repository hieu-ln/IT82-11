//#include <iostream>
//#include <ctime>
//using namespace std;
//int const maxx = 100001;
//int a[maxx];
//int n;
//void copy(int a[], int b[], int n)
//{
//	for (int i = 0; i < n; i++)
//		b[i] = a[i];
//}
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void input(int a[], int& n)
//{
//	cout << "Nhap so phan tu trong mang :";
//	srand(time(NULL));
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		a[i] = rand() % 10 + 1;
//	cout << "Nhap thanh cong!" << endl;
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//}
//void output(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//}
//void insersort(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int j = i, x = a[j];
//		while (j > 0 && x > a[i])
//		{
//			a[j] = a[i];
//			j--;
//		}
//		a[j] = x;
//	}
//}
//void selecsort(int a[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int tmp = i;
//		for (int j = i; j < n; j++)
//		{
//			if (a[j] < a[tmp])
//				tmp = j;
//		}
//		swap(a[i], a[tmp]);
//	}
//}
//void intersort(int a[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (a[i] > a[j])
//				swap(a[i], a[j]);
//
//}
//void bubblesort(int a[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (a[j] < a[i])
//				swap(a[j], a[i]);
//}
//void quicksort(int a[], int l, int r)
//{
//	int i = l, j = r, tmp = a[(l + r) / 2];
//	while (i < j)
//	{
//		while (a[i] < tmp)
//			i++;
//		while (a[j] > tmp)
//			j--;
//		if (i <= j)
//		{
//			swap(a[i], a[j]);
//			i++;
//			j--;
//		}
//	}
//	if (l < j) quicksort(a, l, j);
//	if (r > i) quicksort(a, i, r);
//}
//void shilf(int a[], int n, int i)
//{
//	int j = i * 2 + 1;
//	if (j >= n) return;
//	if (j + 1 <= n)
//		if (a[j] < a[j + 1])
//			j++;
//	if (a[i] >= a[j])
//		return;
//	else
//	{
//		swap(a[i], a[j]);
//		shilf(a, n, j);
//	}
//}
//void heapsort(int a[], int n)
//{
//	int i = n / 2, tmp = n;
//	while (i >= 0)
//	{
//		shilf(a, n - 1, i);
//		i--;
//	}
//	tmp--;
//	while (tmp > 0)
//	{
//		if (a[tmp] < a[0]) swap(a[tmp], a[0]);
//		tmp--;
//		if (tmp > 0)
//			shilf(a, tmp, 0);
//	}
//}
//int findn(int a[], int n, int x)
//{
//	for (int i = 0; i < n; i++)
//		if (a[i] == x)
//			return i;
//	return -1;
//}
//int findlogn(int a[], int n, int x)
//{
//	int l = 0, r = n - 1, mid;
//	while (l <= r)
//	{
//		mid = (l + r) / 2;
//		if (a[mid] == x) return mid;
//		if (x > a[mid]) l = mid + 1;
//		else r = mid - 1;
//	}
//	return -1;
//}
//int main()
//{
//	int b[maxx];
//	cout << "**********MENU BAI 1 CHUONG 2************ :" << endl;
//	cout << "1 : Nhap danh sach" << endl;
//	cout << "2 : Xuat danh sach" << endl;
//	cout << "3 : Insertion sort" << endl;
//	cout << "4 : Selection sort" << endl;
//	cout << "5 : Interchange sort" << endl;
//	cout << "6 : Bubble sort" << endl;
//	cout << "7 : Quick sort" << endl;
//	cout << "8 : Heap sort" << endl;
//	cout << "9 : Tim tuan tu x" << endl;
//	cout << "10: Tim nhi phan x" << endl;
//	cout << "11: Thoat chuong trinh" << endl;
//	int request = 0;
//	while (request != 11)
//	{
//		cout << "Chon lenh can thuc hien :";
//		cin >> request;
//		switch (request)
//		{
//		case 1:
//		{
//			cout << "Bat dau nhap danh sach" << endl;
//			input(a, n);
//			break;
//		}
//		case 2:
//		{
//			cout << "Xuat danh sach: " << endl;
//			output(b, n);
//			break;
//		}
//		case 3:
//		{
//			copy(a, b, n);
//			clock_t start = clock();
//			intersort(b, n);
//			cout << "Thoi gian thuc hien sap xep : " << (clock() - start) / CLOCKS_PER_SEC << endl;
//			break;
//		}
//		case 4:
//		{
//			copy(a, b, n);
//			clock_t start = clock();
//			selecsort(b, n);
//			cout << "Thoi gian thuc hien sap xep : " << (clock() - start) / CLOCKS_PER_SEC << endl;
//			break;
//		}
//		case 5:
//		{
//			copy(a, b, n);
//			clock_t start = clock();
//			intersort(b, n);
//			cout << "Thoi gian thuc hien sap xep : " << (clock() - start) / CLOCKS_PER_SEC << endl;
//			break;
//		}
//		case 6:
//		{
//			copy(a, b, n);
//			clock_t start = clock();
//			bubblesort(b, n);
//			cout << "Thoi gian thuc hien sap xep : " << (clock() - start) / CLOCKS_PER_SEC << endl;
//			break;
//		}
//		case 7:
//		{
//			copy(a, b, n);
//			clock_t start = clock();
//			quicksort(b, 0, n - 1);
//			cout << "Thoi gian thuc hien sap xep : " << (clock() - start) / CLOCKS_PER_SEC << endl;
//			break;
//		}
//		case 8:
//		{
//			copy(a, b, n);
//			clock_t start = clock();
//			heapsort(b, n);
//			cout << "Thoi gian thuc hien sap xep : " << (clock() - start) / CLOCKS_PER_SEC << endl;
//			break;
//		}
//		case 9:
//		{
//			int x;
//			cout << "Nhap gia tri can tim : "; cin >> x;
//			for (int i = 0; i < n; i++)
//				cout << a[i] << " ";
//			cout << endl;
//			int tmp = findn(a, n, x);
//			if (tmp != -1)
//				cout << "tim duoc x tai vi tri: " << tmp << endl;
//			else
//				cout << "khong tim duoc x" << endl;
//			break;
//		}
//		case 10:
//		{
//			int x;
//			cout << "Nhap gia tri can tim : "; cin >> x;
//			int tmp = findlogn(b, n, x);
//			if (tmp != -1)
//				cout << "tim duoc x tai vi tri: " << tmp << endl;
//			else
//				cout << "khong tim duoc x" << endl;
//			break;
//		}
//		case 11:
//		{
//			cout << "Thoat chuong trinh " << endl;
//			system("pause");
//			break;
//		}
//		default:
//		{
//			cout << "Lenh khong hop le" << endl << "Nhap lai" << endl;
//		}
//		}
//	}
//	return 0;
//}