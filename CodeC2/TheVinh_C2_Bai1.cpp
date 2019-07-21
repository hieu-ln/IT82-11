#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;


// Thu tuc nhap vao danh sach.
void input(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << "\nNhap vao a[" << i << "] : ";
        cin >> a[i];
    }
}

// Thu tuc xuat ra danh sach vua nhap.
void output(int a[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// Ham tim phan tu trong danh sach.
int find(int a[], int n, int x){
    int i = 0;
    while(i < n && a[i] != x) i++;
    if(i >= n){
        return -1;
    }
    else{
        return i;
    }
}

// Them phan tu o cuoi danh sach.
int them_cuoi(int a[], int &n, int x){
    if(n < MAX){ // Dam bao danh sach van con cho.
        a[n++] = x;
        return 1;
    }
    return 0;
}

// Xoa phan tu o cuoi danh sach.
int xoa_cuoi(int a[], int &n){
    if(n >= 1){ // Dam bao trong danh sach co phan tu.
        n--;
        return 1;
    }
    return 0;
}

// Them gia tri tai vi tri vt
int them_vi_tri(int a[], int &n, int vt, int gt){
    if(vt > 0 && vt <= n){ // Dam bao them vao vi tri trong mang
        for(int i = n - 1; i >= vt - 1; i--){
            a[i] = a[i - 1];
        }
        a[vt - 1] = gt;
        n++;
        return 1;
    }
    return 0;
}

// Xoa gia tri tai vi tri vt
int xoa_vi_tri(int a[], int &n, int vt){
    if(vt > 0 && vt <= n){ // Dam bao xoa vi tri co trong mang
        for(int i = vt; i < n; i++){
            a[i - 1] = a[i];
        }
        n--;
        return 1;
    }
    return 0;
}

// Tim neu thay thi xoa phan tu do.
int tim_xoa(int a[], int &n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            for(int j = i; j < n; j++){
                a[j] = a[j + 1];
            }
            n--;
            return 1;
        }
    }
    return 0;
}

// Sap xep mang tang dan.
void interchange_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j  = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]); // Doi cho a[i] vs a[j].
            }
        }
    }
}

int main()
{
    int a[MAX];
    int n, x, chon, t, gt_them;
    system("cls");

    cout << "Nhap vao so phan tu trong danh sach: "; 
    cin >> n;
    input(a, n);
    cout << "Danh sach hien tai cua ban la: "; 
    output(a , n);
    cout    << "\n\t\t\t\tHAY CHON TASK BAN MUON THUC HIEN\n"
            << "1. Tim phan tu trong danh sach.\n"
            << "2. Them o cuoi danh sach.\n"
            << "3. Xoa phan tu o cuoi danh sach.\n"
            << "4. Them phan tu tai vi tri.\n"
            << "5. Xoa gia tri tai vi tri.\n"
            << "6. Tim neu thay phan tu do thi xoa.\n"
            << "7. Sap xep mang tang dang.\n"
            << "8. Xuat ra mang.\n"
            << "9. Thoat." << endl;
        
    do{
        cout << "Nhap vao lua chon cua ban: ";
        cin >> chon;
        switch(chon){
            case 1:
                cout << "\nNhap vao gia tri muon tim trong danh sach: "; 
                cin >> x;
                t = find(a, n, x);
                if(t == 0){
                    cout << "\nKhong tim thay " << x << " trong danh sach!" << endl;
                    break;
                }
                else{
                    cout << "\nTim thay gia tri " << x << " trong mang va nam tai vi tri thu " << t + 1 << endl;
                    break;
                }

            case 2:
                cout << "\nNhap vao gia tri muon them cuoi danh sach: "; 
                cin >> x;
                t = them_cuoi(a, n, x);
                if(t == 0){
                    cout << "\nKhong the them vao trong danh sach!" << endl;
                    break;
                }
                else{
                    cout <<"\nThem thanh cong vao cuoi danh sach!" << endl;
                    break;
                }

            case 3:
                t = xoa_cuoi(a, n);
                if(t == 0){
                    cout << "\nXoa phan tu o cuoi danh sach khong thanh cong!" << endl;
                    break;
                }
                else{
                    cout << "\nXoa thanh cong phan tu o cuoi danh sach." << endl;
                    break;
                }
            
            case 4:
                cout << "\nNhap vao vi tri ban muon them: "; 
                cin >> x;
                cout << "\nNhap vao gia tri muon them: "; 
                cin >> gt_them;

                t = them_vi_tri(a, n, x, gt_them);
                if(t == 0){
                    cout << "\nKhong the them vao danh sach!" << endl;
                    break;
                }
                else{
                    cout << "\nThem vao danh sach thanh cong." << endl;
                    break;
                }
            case 5:
                cout << "\nNhap vao vi tri ban muon xoa: "; 
                cin >> x;
                t = xoa_vi_tri(a, n, x);
                if(t == -1){
                    cout << "\nKhong the xoa phan tu trong danh sach!" << endl;
                    break;
                }
                else{
                    cout << "\nXoa vi tri thanh cong." << endl;
                    break;
                }
            case 6:
                cout << "\nNhap vao gia tri ban muon tim va xoa: "; cin >> x;
                t  = tim_xoa(a, n, x);
                if(t == -1){
                    cout << "\nKhong tim thay gia tri de xoa!" << endl;
                    break;
                } 
                else{
                    cout << "\nTim va xoa gia tri thanh cong." << endl;
                    break;
                }
            case 7:
                interchange_sort(a, n);
                cout << "\nMang sau khi sap xep la: \n";
                output(a, n);
                break;

            case 8:
                cout << "\nMang cua ban hien tai la: \n";
                output(a, n);
                break;
            case 9:
                cout << "\nTam biet!";
                return 1;
        }
    }while(chon != 9);
    
    return 0;
}