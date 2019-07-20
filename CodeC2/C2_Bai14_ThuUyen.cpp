#include<iostream>
using namespace std;
struct DonThuc
{
    float heso,somu;
    struct DonThuc *next,*pre;
};
DonThuc *Tao_donthuc(float heso,float somu)
{
    DonThuc *p=new DonThuc;
    if(p==NULL) 
		exit(1);
    p->heso=heso;
    p->somu=somu;
    p->next=p->pre=NULL;
    return p;
}
struct DaThuc
{
	DonThuc *head, *tail;
};
void Init(DaThuc &L)
{
    L.head=L.tail=NULL;
}
void ThemCuoi(DaThuc &L,DonThuc *p)
{
    if(L.head==NULL)
		L.head=L.tail=p;
    else
    {
        L.tail->next= p;
        p->pre = L.tail;
        L.tail=p;
    }
}
void Nhap(DaThuc &L)
{
    DonThuc *p;
    float heso,somu;
    cout<<"Nhap so da thuc, ket thuc khi nhap he so = 0\n";
    do{
        cout<<"He so = ";cin>>heso;
        if(heso!=0)
        {
            cout<<"So mu = ";cin>>somu;
            p=Tao_donthuc(heso,somu);
            ThemCuoi(L,p);
        }
        cout<<endl;
    }while(heso!=0);
}
void Xuat(DaThuc L)
{
    DonThuc *p=L.head;
    if(p==NULL)
    {
        cout<<0;
        return;
    }
    while(p!=NULL)
    {
        if(p==L.head)
        {
            if(p->somu==0) 
				cout<<p->heso;
            else
				if(abs(p->heso)!=1 && p->somu!=1) 
					cout<<p->heso<<"X^"<<p->somu;
				else 
					if(abs(p->heso)!=1 && p->somu==1) 
						cout<<p->heso<<"X";
					else 
						if(abs(p->heso)==1 && p->somu!=1) 
							if(p->heso==1)
								cout<<"X^"<<p->somu;
							else
								cout<<"- X^"<<p->somu;
						else 
							if(p->heso==1)
								cout<<"X";
							else
								cout<<"- X";
        }
        else
        {
            if(p->somu==0) 
				if(p->heso > 0)
					cout<<" + "<<p->heso;
				else
					cout<<" "<<p->heso;
            else
				if(abs(p->heso)!=1 && p->somu!=1) 
					if(p->heso > 0)
						cout<<" + "<<p->heso<<"X^ "<<p->somu;
					else
						cout<<" "<<p->heso<<"X^ "<<p->somu;
				else 
					if(abs(p->heso)!=1 && p->somu==1) 
						if(p->heso > 0)
							cout<<" + "<<p->heso<<"X";
						else
							cout<<" "<<p->heso<<"X";
					else 
						if(abs(p->heso)==1 && p->somu!=1) 
							cout<<" + X^ "<<p->somu;
						else 
							if(p->heso==1)
								cout<<" + X";
							else
								cout<<" - X";
        }
        p=p->next;
    }
}
void SapXep(DaThuc &L)
{
    DonThuc *p1=L.head,*p2;
    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p2->somu > p1->somu)
				swap(p1,p2);
            p2=p2->next;
        }
        p1=p1->next;
    }
}
void XoaTruocQ(DaThuc &L, DonThuc *Q)
{
    DonThuc *p;
    if(Q==NULL)
    {
        p=L.tail;
        if(L.head==L.tail)
        {
            L.head=L.tail=NULL;
            delete p;
        }
        else if(p!=NULL)
        {
            L.tail=L.tail->pre;
            L.tail->next=NULL;
            delete p;
        }
    }
    else
    {
        p=Q->pre;
        if(p!=NULL)
        {
            if(p==L.head)
            {
                L.head=L.head->next;
                L.head->pre=NULL;
                delete p;
            }
            else
            {
                p->pre->next=Q;
                Q->pre=p->pre;
                delete p;
            }
        }
    }
}
void RutGon(DaThuc &L)
{
    DonThuc *p1=L.head,*p2;
    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p2->somu==p1->somu)
            {
                p1->heso+=p2->heso;
                p2=p2->next;
                XoaTruocQ(L,p2);
            }
            else p2=p2->next;
        }
        p1=p1->next;
    }
}
void ThemTruocQ(DaThuc &L, DonThuc *Q, DonThuc *p)
{
    if(Q==L.head)
    {
        L.head->pre=p;
        p->next=L.head;
        L.head=p;
    }
    else
    {
        p->pre=Q->pre;
        p->next=Q;
        Q->pre->next=p;
        Q->pre=p;
    }
}
void Insert(DaThuc &L,DonThuc *p)
{
    DonThuc *p1=L.head;
    while(p1!=NULL && p1->somu > p->somu) p1=p1->next;
    if(p1!=NULL)
        if(p1->somu == p->somu)
			p1->heso += p->heso;
        else 
			ThemTruocQ(L,p1,p);
    else 
		ThemCuoi(L,p);
}
void XuLy(DaThuc &L)
{
    DonThuc *p=L.head;
    while(p!=NULL)
    {
        if(p->heso==0)
        {
            p=p->next;
            XoaTruocQ(L,p);
        }
        else p=p->next;
    }
}
int Cong(DaThuc L1, DaThuc L2, DaThuc &L)
{
    DonThuc *p=L1.head,*a;
    while(p!=NULL)
    {
        a=Tao_donthuc(p->heso,p->somu);
        ThemCuoi(L,a);
        p=p->next;
    }
    p=L2.head;
    while(p!=NULL)
    {
        a=Tao_donthuc(p->heso,p->somu);
        Insert(L,a);
        XuLy(L);
        p=p->next;
    }
    XuLy(L);
    if(L.head==NULL)
		return 0;
    return 1;
}
int Tru(DaThuc L1, DaThuc L2, DaThuc &L)
{
    DonThuc *p=L2.head;
    while(p!=NULL)
    {
        p->heso=-p->heso;
        p=p->next;
    }
    Cong(L1,L2,L);
    p=L2.head;
    while(p!=NULL)
    {
        p->heso=-p->heso;
        p=p->next;
    }
    if(L.head==NULL) 
		return 0;
    return 1;
}
int Nhan(DaThuc L1, DaThuc L2, DaThuc &L)
{
    DonThuc *p,*p1,*p2;
    p2=L2.head;
    while(p2!=NULL)
    {
        p1=L1.head;
        while(p1!=NULL)
        {
            p=Tao_donthuc(p2->heso*p1->heso,p2->somu+p1->somu);
            Insert(L,p);
            p1=p1->next;
        }
        p2=p2->next;
    }
    XuLy(L);
    if(L.head==NULL)
		return 0;
    return 1;
}
void XoaCuoi(DaThuc &L)
{
    DonThuc *p=L.tail;
    if(p==NULL)
		exit(1);
    if(L.head==L.tail)
    {
        L.head=L.tail=NULL;
        delete p;
    }
    else
    {
        L.tail=p->pre;
        L.tail->next=NULL;
        delete p;
    }
}
void Xoa(DaThuc &L)
{
    while(L.head!=NULL)
		XoaCuoi(L);
}
void Chia(DaThuc L1,DaThuc L2)
{
    DonThuc *p, *p1;
    DaThuc a , b, du;
    Init(a); Init(b); Init(du);
	p1=L1.head;
    while(p1!=NULL)
    {
        p=Tao_donthuc(p1->heso,p1->somu);
        ThemCuoi(du,p);
        p1=p1->next;
    }
    while(du.head!=NULL && du.head->somu >= L2.head->somu)
    {
        p=Tao_donthuc(du.head->heso / L2.head->heso, du.head->somu - L2.head->somu);
        ThemCuoi(a,p);
        Xoa(b);
        if(Nhan(L2,a,b)==0)
			break;
        Xoa(du);
        if(Tru(L1,b,du)==0)
			break;
    }
    Xuat(a);
    if(du.head!=NULL)
    {
        cout<<"\n du ";
        Xuat(du);
    }
}
void main()
{
    DaThuc L1, L2, L;
    Init(L1); Init(L2); Init(L);
	cout<<"\nNhap P(x):\n";
    Nhap(L1); 
	cout<<"\nNhap G(x):\n";
	Nhap(L2);
    RutGon(L1); SapXep(L1);
    cout<<"\nP(x) = "; Xuat(L1); cout<<endl;
    RutGon(L2); SapXep(L2);
    cout<<"\nQ(x) = "; Xuat(L2); cout<<endl;
    int choice;
    system("cls");
	cout<<" --------- DA THUC --------- \n"
		<<"1. Cong hai da thuc\n"
		<<"2. Tru hai da thuc\n"
		<<"3. Nhan hai da thuc\n"
		<<"4. Chia hai da thuc\n"
		<<"5. Thoat\n";
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			Init(L);
			cout<<"\nP(x) + Q(x) = ";
			Cong(L1,L2,L);
			Xuat(L);
			break;
		case 2:
			Init(L);
			cout<<"\nP(x) - Q(x) = ";
			Tru(L1,L2,L);
			Xuat(L);
			break;
		case 3:
			Init(L);
			cout<<"\nP(x) * Q(x) = ";
			Nhan(L1,L2,L);
			Xuat(L);
			break;
		case 4:
			Init(L);
			cout<<"\nP(x) / Q(x) = ";
			Chia(L1,L2);
			break;
		case 5:
			cout<<"Goodbye.....!\n";
		default:
			break;
		}
	}while(choice>0&&choice<6);
    cout<<endl;
    system("pause");
}