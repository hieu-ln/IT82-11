#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;

// Khai bao bao truc cua 1 cai node.
struct Node{
    int info;
    Node *link;
};

// Tao con tro dau danh sach.
Node *p_first;

// Khoi tao 1 danh sach rong.
void Init(){
    p_first = NULL;
}

// Them mot node vao dau danh sach.
void insert_first(int x){
    Node *p = new Node;
    p->link = p_first;
    p->info = x;
    p_first = p;
}

// Them mot node vao cuoi danh sach.
void insert_last(int x){
    Node *p = new Node;
    p->info = x;
    p->link = NULL;
    if (p_first == NULL){
        p_first = p;
    }
    else{
        Node *q = p_first;
        while(q->link != NULL){
            q = q->link;
        }
        q->link = p;
    }
}

// Tim mot phan tu trong danh sach lien ket.
Node *search(int x){
    Node *p = p_first;
    while(p != NULL && p->info != x){
        p = p->link;
    }
    return p;
}

// Ham dung de in ra man hinh cac node trong danh sach.
void out_put(){
    Node *p = p_first;
    while(p != NULL){
        cout << p->info << "\t";
        p = p->link;
    }
    cout << endl;
}

// Ham dung de xoa node dau danh sach.
int delete_first(){
    if(p_first != NULL){ 
        Node *p = p_first;
        p_first = p_first->link;
        delete p;
        return 1;
    }
    return 0;
}

// Ham dung de xoa node cuoi danh sach.
int delete_last(){
    if(p_first != NULL){
        Node *p, *q;
        p = p_first;
        while(p->link != NULL){ // Dieu kien nay la khi gap phan tu cuoi cung or list rong se thoat.
            q = p;
            p = p->link;
        }
        if(p != p_first)// Neu nhu p khong phai la phan tu dau tien.
            q->link = NULL;
        else
            p_first = NULL;
        delete p;
        return 1;
    }
    return 0;
}


// Ham dung de tim phan tu neu thay thi xoa phan tu do.
int find_delete(int x){
    if(p_first != NULL){
        Node *p, *q;
        p = p_first;
        q = p_first;
        while(p->info != x && p->link != NULL){
            q = p;
            p = p->link;
        }
        if( p != p_first && p->link != NULL){
            // Phan tu o giua danh sach.
            if(p->link != NULL)
                q->link = p->link;
            else
                q->link = NULL;
            delete p;
            return 1;
        }
        else if(p == NULL){
            // Phan tu luc nay o cuoi danh sach.
            p->link = NULL;
            delete p;
            return 1;
        }
        else
            return 0;
    }
}

// Ham doi gia tri 2 phan tu.
void swap(Node *a, Node *b){
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

// Sap xep danh sach tang dan(Selection Sort). 
void selection_sort_ascending(){
    Node *p, *q, *min;
    p = p_first;
    while(p != NULL){
        // Tim phan tu nho nhat trong danh sach.
        min = p;
        q = p->link;
        while (q != NULL) // Luc nay duyet q di den cuoi mang de tim co cai nao nho hon khong.
        {   
            if(q->info < min->info){
                min = q;
            }
            q = q->link;
        }
        // Doi cho phan tu nho nhat voi phan tu dau tien.
        swap(min, p);
        p = p->link;
    }
}

//Sap xem danh sach theo thu tu giam dan(Selection Sort).
void selection_sort_decrease(){
    Node *p, *q, *min;
    p = p_first;
    while(p != NULL){
        // Tim phan tu lan nhat trong danh sach.
        min = p;
        q = p->link;
        while(q != NULL) // Luc nay duyet toi cuoi mang de tim cai nao nho nhat se swap voi p
        {
            if(q->info > min->info){
                min = q;
            }
            q = q->link;
        }
        // Doi cho Max tim duoc cho vi tri phan tu dau tien trong moi lan duyet.
        swap(min, p);
        p = p->link;
    }
}

int main()
{
    Node *msg;
    int chon, x, t;
    Init(); // Goi ham khoi tao rong
    system("cls");
    cout << "\n\t\t\t\tHAY LUA CHON TASK MA BAN MUON\n";
    cout    << "1. Them phan tu vao dau danh sach.\n"
            << "2. Them phan tu vao cuoi danh sach.\n"
            << "3. Tim phan tu trong danh sach.\n"
            << "4. Xoa phan tu o dau danh sach.\n"
            << "5. Xoa phan tu o cuoi danh sach.\n"
            << "6. In ra man hinh cac phan tu trong danh sach.\n"
            << "7. Tim phan tu neu co thi xoa phan tu do.\n"
            << "8. Sap xep mang tang dan.\n" 
            << "9. Sap xep mang giam dan.\n"
            << "10. Thoat." << endl;

    do{
        cout << "\nMoi ban chon: ";
        cin >> chon;

        switch(chon){
            case 1:
                cout << "\nNhap vao gia tri ban muon them dau danh sach: "; cin >> x;
                insert_first(x);
                cout << "Mang sau khi them la" << endl;
                out_put();
                break;

            case 2:
                cout << "\nNhap vao gia tri ban muon them vao cuoi danh sach: "; cin >> x;
                insert_last(x);
                cout << "Mang sau khi them la" << endl;
                out_put();
                break;

            case 3:
                cout << "\nNhap vao phan tu ban muon tim trong danh sach: "; cin >> x;
                search(x);
                msg = search(x);
                if(msg != NULL)
                    cout << "Tim thay phan tu " << x << " trong danh sach." << endl;
                else
                    cout << "Khong tim thay trong danh sach. " << endl;
                break;

            case 4:
                t = delete_first();
                if(t == 0)
                    cout << "\nDanh sach khong co phan tu nao!" << endl;
                else
                    cout << "\nDa xoa phan tu dau danh sach thanh cong." << endl;
                    break;

            case 5:
                t = delete_last();
                if(t == 0)
                    cout << "\nKhong co phan tu nao!" << endl;
                else
                    cout << "\nDa xoa phan tu cuoi danh sach thanh cong." << endl;
                    break;

            case 6:
                cout << "\nCac phan tu trong danh sach cua ban la " << endl;
                out_put();
                break;

            case 7:
                cout << "\nNhap vao phan tu ban muon tim va xoa: ";
                cin >> x;
                if(search(x)){
                    find_delete(x);
                    cout << "\nDa xoa phan tu " << x << " thanh cong." << endl;
                }
                else
                    cout << "\nKhong tim thay " << x << " trong mang!" << endl;
                break;

            case 8:
                selection_sort_ascending();
                cout << "\nMang sau khi sap xep tang dan la\n";
                out_put();
                break;

            case 9:
                selection_sort_decrease();
                cout << "\nMang sau khi sap xep giam dan la\n";
                out_put();
                break;

            case 10:
                cout << "\nTam biet!" << endl;
                return 1;

            default:
                break;
        }
    } while(chon != 10);

    return 0;
}
