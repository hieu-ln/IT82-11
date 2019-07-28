#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 100
//Cau 1.1.
int a[MAX];
int n;

//Cau 1.2: Khoi tao ham nhap gia tri ngau nhien cho mang.
void random_input(int a[], int n) {
    cout << "\nNhap vao so luong phan tu trong danh sach: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 10000 + 1;
    }
}

//Cau 1.2: Ham cho nguoi dung nhap vao cac gia tri trong mang.
void input(int a[], int n) {
    cout << "Nhap vao cac phan tu trong mang" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nhap vao gia tri tai vi tri a [" << i << "] : ";
        cin >> a[i];
    }
}

//Cau 1.3: Ham xuat cac phan tu trong mang.
void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

void copy_array(int a[], int b[], int n) {
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

// Ham dung de doi gia tri cua 2 so nguyen.
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//Cau 1.4: Selection Sort.
void selection_sort(int a[], int n) {
    int pos_min;
    for(int i = 0; i < n - 1; i++) {
        pos_min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[pos_min] > a[j]) {
                pos_min = j;
            }
        }
        swap(a[pos_min], a[i]);
    }
}

//Cau 1.5 Insertion Sort
void insertion_sort(int a[], int n) {
    int x, j;
    for(int i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while(j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

//Cau 1.6 Interchage Sort
void interchage_sort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j], a[i]);
                swap(a[i], a[j]);
        }
    }
}

//Cau 1.7: Bubble Sort
void bubble_sort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j] < a[j - 1])
                swap(a[i], a[j]);
        }
    }
}

//Cau 1.8: Quick Sort 
void quick_sort(int a[], int n) { 
    
}

//Cau 1.9: Heap Sort
void heap_sort(int a[], int n) { 
    
}

//Cau 1.10: Tim kiem tuan tu.
int search_sequence(int a[], int n, int x) {
    int i = 0;
    while(i < n && a[i] != x)
        i++;
    if(i < n)  // Dam bao la a[i] nma trong mang.
        return i;
    return -1; // Neu khong tim thay x thi tra ve gia tri la -1.
}

//Cau 1.11: Tim kiem nhi phan.
int search_binary(int a[], int n, int x) {
    int left = 0;
    int right = n -1;
    int mid;
    while(left <= right) { 
        mid = (left + right) /2;
        if(x == a[mid]) { // neu nhung x dung bang vi tri tai mid
            return mid; // Tra ve gia tri x ngay lap tuc.
        }
        else {
            if (x > a[mid]) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
    }
    return -1; // neu nhu khong tim thay x thi tra ve -1.
}

int main() {
    int n, choice;
    int x, t;
    system("cls");
    cout << "\nNhap vao so luong phan tu trong mang: ";
    cin >> n;
    input(a, n);
    cout << "\nMang ban vua nhap la: ";
    output(a, n);
    cout << endl;
    cout    << "--------------DEMO - SORT - SEARCH-------------------\n"
            << "1. Khoi tao mang ngau nhien.\n"
            << "2. Nhap vao mot mang.\n"
            << "3. Xuat mang.\n"
            << "4. Selectionsort.\n"
            << "5. Insertionsort.\n"
            << "6. Bubblesort.\n"
            << "7. Interchangesort.\n"
            << "8. Quicksort.\n"
            << "9. Heapsort.\n"
            << "10. Tim kiem  tuan tu.\n"
            << "11. Tim kiem nhi phan.\n"
            << "12 .. Thoat." << endl;
    do {
        cout << "\nNhap vao so ban muon thuc hien sap xep: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            
        case 4:
            selection_sort(a, n);
            cout << "\nMang cua ban sau khi sap xep Selectionsort." << endl;
            output(a, n);
            break;
        case 5:
            insertion_sort(a, n);
            cout << "\nMang cua ban sau khi sap xep Insertionsort." << endl;
            output(a, n);
            break;
        case 6:
            bubble_sort(a, n);
            cout << "\nMang cua ban sau khi sap xep Bubblesort." << endl;
            output(a, n);
            break;
        case 7:
            interchage_sort(a, n);
            cout << "\nMang cua ban sau khi sap xep Interchangesort" << endl;
            output(a, n);
            break;
        case 8:
            quick_sort(a, n);
            cout << "\nMang cua ban sau khi sap xep Quicksort" << endl;
            output(a,n);
            break;
        case 9:

        case 10:
            cout << "Nhap vao gia tri ban muon tim trong mang: ";
            cin >> x;
        case 11:

        case 12: 
            cout << "Tam biet!";
            break;
        default:
            break;
        }
    }while(choice != 12);
    return 0;
}