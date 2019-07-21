#include<iostream>
using namespace std;
#define MAX 100

// Ham cho nguoi dung nhap vao danh sach.
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri tai vi tri a[" << i + 1 << "] = ";
        cin >> a[i]; 
    }
}

//Cau 2.2: Ham them phan tu vao vi tri trong danh sach co thu tu.
void insert_aray(int a[], int &n, int x) {
    if(x < a[0]) { // Neu x nho hon gia tri dau tien trong mang.
        for(int i = n; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = x; // Gan x o vi tri dau tien.
        n++;
    }
    else if(x > a[n - 1]) { // Neu x lon hon gia tri cuoi cung trong mang.
        a[n] = x;
        n++;
    }
    else { // Con lai
            for(int i = 1; i < n - 1; i++) {
                if(x > a[i] && x < a[i + 1]) { // Dieu kien x nam trong khoang giua 2 phan tu.
                    for(int j = n; j > i + 1; j--) // Cho vong lap chay tu cuoi mang toi vị tri ke, lon hon x.
                        a[j] = a[j - 1]; // Gan gia tri 
                    a[i + 1] = x; // Gan gia tri x.
                    n++;
                }
        }
    }
}
// Ham dung de xep thu tu cac phan tu trong danh sach.
void swap(int &x, int &y) {
    int temp; 
    temp = x;
    x = y;
    y = temp;
}

void sort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int pos_min = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[pos_min]) 
                pos_min = j;
        }
        swap(a[i], a[pos_min]);
    }
}

//Cau 2.3: Xuat phan tu trong danh sach da co thu tu.
void output(int a[], int &n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

//Cau 2.4: Tim phan tu trong danh sach bang phuong phap tim kiem tuan tu.
int search(int a[], int n, int x) {
    int i = 0;
    while(i < n && a[i] != x) {
        i++;
    }
    if(i == n) 
        return -1;
    else 
        return i;
}

//Cau 2.5: Tim phan tu trong mang bang phuong phap cay nhi phan tim kiem.
int binary_search(int a[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if(x == a[mid])
            return mid; // Tra ve vi tri cua x dang tim.
        else
            if(x > a[mid])
                left = mid + 1;
            else 
                right = mid - 1;
    }
    return -1;
}

//Cau 2.6: Tim phan tu neu thay xoa phan tu do.
int search_delete(int a[], int &n, int x){
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

int main() { 
    int n, x, t;
    int choice = 0;
    int a[MAX];
    system("cls");

    cout    << "-------------------------BAI 2 CHUONG 2-------------------------\n"
            << "1. Nhap phan tu vao trong danh sach.\n"
            << "2. Them phan tu vao trong danh sach.\n"
            << "3. Tim tuan tu 1 phan tu trong danh sach.\n"
            << "4. Tim kiem nhi phan 1 phan tu trong danh sach.\n"
            << "5. Tim phan tu neu co thi xoa phan tu do.\n"
            << "6. Xuat danh sach.\n"
            << "7. Thoat." << endl;

    do {
        cout << "\nNhap vao so ban muon thuc hien: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "\nNhap vao so phan tu trong mang: ";
            cin >> n;
            input(a, n);
            sort(a, n);
            cout << "\nMang ban vua nhap la\n";
            output(a, n);
            break;

        case 2:
            cout << "\nNhap vao phan tu ban muon them vao trong danh sach: ";
            cin >> x;
            insert_aray(a, n , x);
            cout << "\nDanh sach cua ban sau khi them x = " << x << " la\n";
            output(a, n);
            break;

        case 3:
            cout << "\nNhap vao phan tu ban muon tim trong danh sach: ";
            cin >> x;
            t = search(a, n, x);
            if(t == -1) 
                cout << "\nKhong tim thay x = " << x << " trong mang!" << endl;
            else
                cout << "\nTim thay x = " << x << " tai vi tri " << t + 1 << endl;
            break;

        case 4:
            cout << "\nNhap vao phan tu ban muon tim trong mang bang phuong phap tim kiem tuan tu: ";
            cin >> x;
            t = binary_search(a, n, x);
            if(t == -1)
                cout << "\nKhong tim thay x = " << x << " trong danh sach!" << endl;
            else
                cout <<  "\nTim thay  x = " << x << " tai vi tri " << t + 1 << endl;
            break;
    
        case 5:
            cout << "\nNhap vao phan tu ban muon tim neu thay thi xoa: ";
            cin >> x;
            t = search_delete(a, n, x);
            if(t == 0) {
                cout << "\nKhong tim thay x = " << x << " trong mang!" << endl;
                break;
            }
            else {
                cout << "\nDa tim thay x = " << x << " va xoa phan tu do thanh cong." << endl;
                cout << "\nMang cua ban sau khi xoa la" << endl;
                output(a, n);
                break;
            }
            

        case 6:
            cout << "\nDanh sach phan tu hien tai cua ban la\n";
            output(a, n);
            break;
        case 7:
            cout <<"\nTam biet!" << endl;
            break;

        default:
            break;
        }
    } while(choice != 7);

    return 0;
}