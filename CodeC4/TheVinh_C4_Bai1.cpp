#include<iostream>
#include<stdio.h>
using namespace std;

#define COUNT 8
//Cau 1.1: Khai bao cau truc cua cay nhi phan tim kiem.
struct Node {
    int info; // luu gia tri cua phan tu.
    Node *left; // luu dia chi phan tu ben trai cua cay.
    Node *right; // luu dia chi phan tu ben phai cua cay.
};
Node *root; // luu dia chi phan tu goc

//Cau 1.2: Khoi tao cay rong.
void Init() {
    root = NULL;
}

//Cau 1.3 Them mot node vao cay dung DE QUY.
// Su dung dia chi con tro.
void insert_node(Node *&p, int x) {
    if(p == NULL) { // chay den khi nao gap node cuoi trong cay
        p = new Node;   
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else {
        if(p->info == x)
            return; // Da co node x trong cay.
        else 
            if(p->info > x)
                return insert_node(p->left, x);
            else
                return insert_node(p->right, x);
    }
}

// Khong su dung dia chi con tro.
int insert_node_recursive(Node *q, int x) {
	if (q->info == x) 
		return 0;
	else if (q->info > x) { 
		if (q->left == NULL) {
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else 
			return insert_node_recursive(q->left, x);
	}
	else {
		if(q->right == NULL) {
			Node *p= new Node;
			p->info = x;
			p->right = NULL;
			p->left = NULL;
			q->right = p;
			return 1;
		}
		else
			return insert_node_recursive(q->right, x);
	}
}

//Cau 1.4: Tim phan tu trong cay dung DE QUY.
Node *search(Node *p, int x) {
    while( p != NULL) { // Kiem tra cay co gia tri.
        if(p->info == x)
            return p;
        else
            if(p->info < x)
                return search(p->right, x);
            else // Nguoc lai neu nhu gia tri tai p lon hon x.
                return search(p->left, x);
    }
    return NULL;    
}

//Cau 1.5: Xoa mot node trong cay dung DE QUY.
void search_stand_for(Node *&p, Node *&q) {
	if (q->left == NULL) {
		p->info = q->info;
		p = q;
		q = p->right;
	}
	else 
		search_stand_for(p, q->left);
}

int Delete(Node *&T, int x) {
	if (T == NULL) return 0; // Dam bao rang cay khong rong.
	if (T->info == x) { 
		Node *p = T;
		if(T->left == NULL) 
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else // Khi node co 2 cay con.
			search_stand_for(p, T->right);
		
		delete p;
		return 1;
	} 
	else if ( T->info < x)
		return Delete(T->right, x);
	else 
		return Delete(T->left, x);
}

//Cau 1.6: Duyet cay theo thu tu NLR dung DE QUY.
void node_left_right(Node *p) {
    if(p != NULL) {
        cout << p->info << "\t";
        node_left_right(p->left);
        node_left_right(p->right);
    }
}

//Cau 1.7: Duyet cay theo thu tu LNR dung DE QUY.
void left_node_right(Node *p) {
    if(p != NULL) {
        left_node_right(p->left);
        cout << p->info << "\t";
        left_node_right(p->right);
    }
}

//Cau 1.8: Duyet cay theo thu tu LRN dung DE QUY.
void left_right_node(Node *p) {
    if(p != NULL) {
        left_right_node(p->left);
        left_right_node(p->right);
        cout << p->info << "\t";
    }
}

// Ham dung de xuat cay nhi phan.
void print2DUtil(Node *p, int space) {
	if (p == NULL) // Base case.
		return;
	// Increase distance between levels.
	space += COUNT;
	// Process right child first.
	print2DUtil(p->right, space);
	// Print current node after space
	// count 
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";

	cout << p->info << "\n";
	// Process left child
	print2DUtil(p->left, space);
}

void process_tree() {
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

int main() {
    int choice = 0;
	int t, x;
    Node *tmp;
    system("cls");
    
    cout    << "-------------BINARY TREE------------------\n"
            << "1. Khoi tao mot Binary Tree.\n"
            << "2. Them Node vao Binary Tree.\n"
            << "3. Tim node trong Binary Tree. \n"
            << "4. Xoa mot node trong Binary Tree\n"
            << "5. Duyet cay theo thu tu NLR.\n"
            << "6. Duyet cay theo thu tu LNR.\n"
            << "7. Duyet cay theo thu tu LRN\n"
            << "8. Xuat cay.\n"
			<< "9. Thoat." << endl;
    do {
        cout << "\nNhap vao so ban muon thuc hien: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Init();
            cout << "\nBan vua tao mot cay rong.\n";
            break;

        case 2:
            cout << "\nNhap vao gia tri ban muon them vao cay: ";
            cin >> x;
            insert_node(root, x);
            cout << "\nCay sau khi ban vua them la: ";
			process_tree();
            break;

        case 3:
            cout << "\nNhap vao gia tri ban muon tim: ";
            cin >> x;
            tmp = search(root, x);
            if(tmp == NULL) 
                cout << "\nKhong tim thay " << x << " trong cay!" << endl;
            else
                cout << "\nTim thay x = " << x << " trong cay!" << endl;
            break;

        case 4:
			cout << "\nNhap vao gia tri ban muon xoa trong cay: ";
			cin >> x;
			t = Delete(root, x);
			if(t == 0)
				cout << "\nKhong tim thay gia tri ban muon xoa trong cay!";
			else {
				cout << "\nDa xoa thanh cong phan tu x = " << x << " trong cay" << endl;
				cout << "\nCay NPTK sau khi xoa la: ";
				process_tree();
			}
			break;

        case 5:
            cout << "\nCay cua ban khi duyet theo thu tu Node Left Right: ";
            node_left_right(root);
            break;

        case 6:
            cout << "\nCay cua ban khi duyet theo thu tu Left Node Right: ";
            left_node_right(root);
            break;

        case 7:     
            cout << "\nCay cua ban khi duyet theo thu tu Left Right Node: ";
            left_right_node(root);
            break;

		case 8:
			cout << "\nCay NPTK cua ban la: ";
			process_tree();
			break;

        case 9:
            cout << "\nTam biet!" << endl;
            break;

        default:
            break;
        }
    } while ( choice != 9);

    return 0;
}