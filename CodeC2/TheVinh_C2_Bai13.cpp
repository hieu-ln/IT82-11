#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 10


//Cau 13.2: Thu tuc nhap vao mot da thuc.
void input(int P[], int &n) {
	for(int i = 0; i < n + 1; i++) {
		cout<<"Nhap he so thu "<< i <<" = ";
		cin >> P[i];
	}
}

//Cau 13.4: Thu tuc xuat ra mot da thuc.
void output(int P[], int n) {
    for (int i=0; i<n+1; i++) {
        cout << P[i];
        if (i != 0)
    		cout << "x^" << i ;
        if (i != n)
       		cout << " + ";
    }
}

//Cau 13.5: Thuc tuc cong hai da thuc.
int *cong(int P[], int Q[], int n, int m)
{
    int size = max(n, m);
    int *sum = new int[size];
    if(n > m) {
    	for (int i = 0; i<=n; i++)
			sum[i] = P[i];
    	for (int i = 0; i <= m; i++)
    		sum[i] += Q[i];
	}
    else {
		for (int i = 0; i < m+1; i++)
			sum[i] = Q[i];
		for (int i=0; i < n+1; i++)
        	sum[i] += P[i];
   	}
    return sum;
}

//Cau 13.6: Thu tuc tru hai da thuc.
int *tru(int P[], int Q[], int n, int m)
{
    int size = max(m, n);
    int *hieu = new int[size];
    for (int i = 0; i <= n; i++)
    	hieu[i] = P[i];
    for (int i=0; i <= m; i++)
    	hieu[i] -= Q[i];
	return hieu;
}

//Cau 13.7: Thu tuc nhan hai da thuc.
int *nhan(int P[], int Q[], int n, int m)
{
    int *tich = new int[m + n - 1];
    for (int i = 0; i <= m + n - 1; i++)
    	tich[i] = 0;
    for (int i = 0; i <= n; i++) {
     	for (int j = 0; j <= m; j++)
        	tich[i + j] += P[i] * Q[j];
	}
   return tich;
}

//Cau 13.8: Thu tuc chia 2 da thuc.
void chia(int P[], int Q[], int n, int m) {
	int i,j,z,x;
	double r[MAX], du[MAX];
    for(i = 0; i <= n;i++)
		du[i] = P[i];
    if(n < m) {
		cout<< 0 << "\n";
	}
    else
	{
		x = n;
		z = n - m;
		if(n == m) {
			r[z]=P[n] / Q[n];
			z++;
		}
		else {
			while( z >= 0) {
				r[z] = du[x] / Q[m];
				int y = m;
				for(i = x; i >= x - m; i--) {
					du[i] = du[i] - r[z] * Q[y];
					y--;
				}
				x--;
				z--;
			}
		}
	}
	for(i = n - m; i >= 0; i--) {
		if(i == 0)
			cout << r[0] << "\n";
		else
			if(r[i] != 0)
				cout << r[i] << "*x^" << i << "+";
	}
	cout<< "\nDa thuc du: ";
	for(i = x; i >= 0; i--) {
		if(i == 0)
			cout << du[0] << "\n";
		else
			if(du[i] != 0)
				cout << du[i] << "*x^" << i << "+";
	}
}

int max(int m, int n)
{
    if(m>n)
        return m;
    else
        return n;
}

int main()
{
	int choice;
	int P[MAX], Q[MAX], Z[MAX];
	int n, m, size;
	int *i;
	system("cls");

	cout	<< "----------------------BAI 13 CHUONG 2----------------\n"
			<< "1. Nhap vao da thuc P.\n"
			<< "2. Nhap vao da thuc Q.\n"
			<< "3. Xuat da thuc P.\n"
			<< "4. Xuat da thuc Q.\n"
			<< "5. Xuat ra hai da thuc P & Q.\n"
			<< "6. Tong 2 da thuc.\n"
			<< "7. Hieu 2 da thuc.\n"
			<< "8. Tich 2 da thuc.\n"
			<< "9. Chia 2 da thuc.\n"
			<< "10. Thoat." << endl;
	do  {
		cout << "\nNhap vao so ban muon thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			do {
				cout<<"Nhap so mu cao nhat cua da thuc P: ";
				cin >> n;
				if(n  < 0 || n > 10)
					cout<<"Nhap sai. Nhap lai!\n";
			}while(n < 0 || n > 10);
			input(P, n);
			break;

		case 2:
			do {
			cout << "Nhap so mu cao nhat cua da thuc Q: ";
			cin >> m;
			if(m < 0 || m > 10)
				cout << "Nhap sai. Nhap lai\n";
			} while(m < 0 || m > 10);
			input(Q, m);
			break;

		case 3:
			cout << "\nDa thuc P la: ";
			output(P, n);
			break;

		case 4:
			cout << "\nDa thuc Q la: ";
			output(Q, m);
			break;

		case 5:
			cout<<"\nHai da thuc ban vua nhap la\n";
			cout<<"\nDa thuc P la: ";
			output(P, n);
			cout<<"\nDa thuc Q la: ";
			output(Q, m);
			break;

		case 6:
			cout<<"\nTong cua hai da thuc la\n";
			i = cong(P, Q, n, m);
			size = max(n, m);
			output(i, size);
			break;

		case 7:
			//cout<<"\nHieu cua hai da thuc la\n";
			//i = tru(P, Q, n, m);
			//size = max(n, m);
			//output(i, size);
			//break;

		case 8:
			cout<<"\nTich cua hai da thuc la\n";
			i = nhan(P, Q, n, m);
			output(i, n + m - 1);
			break;

		case 9:
			//cout<<"\nThuong 2 da thuc la\n";
			//chia(P,Q,n,m);
			//break;

		case 10:
			cout << "\nTam biet!" << endl;
			break;

		default:
			break;
		}
	} while(choice != 10);
	return 0;
}
