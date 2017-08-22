#include<iostream>
#include<string>
using namespace std;
struct Sach
{
	int maso;
	string tuasach, tacgia,nxb;
};
struct Node
{
	Sach info;
	Node *next;
};
Node *createNode(Sach s)
{
	Node *p = new Node;
	if (p != NULL)
	{
		p->info = s;
		p->next = NULL;
	}
	return p;
}
void ThemCoThuTu(Node *&head, Sach s)
{
	Node *p1, *p2, *p;
	p = createNode(s);
	p1 = head;
	p2 = head->next;
	while (p2 && p2->info.maso < p->info.maso)
	{
		p1 = p2;
		p2 = p2->next;
	}
	p1->next = p;
	p->next = p2;
}
void addTohead(Node *&head,Sach s)
{
	Node *p = new Node;
	if (p == NULL)
	{
		return;
	}
	else
	{
		p = createNode(s);
		if (head != NULL)
		{
			p->next = head;
		}
		head = p;
	}
}
void nhapSach(Sach &s)
{
	fflush(stdin);
	cout << "\nNhap vao tua sach:";
	getline(cin, s.tuasach);
	fflush(stdin);
	cout << "\nNhap vao ten tac gia:";
	getline(cin, s.tacgia);
	fflush(stdin);
	cout << "\Nhap vao nha xuat ban:";
	getline(cin, s.nxb);
}
void xuatsach(Sach s)
{
	cout << "\nMa sach la:" << s.maso;
	cout << "\nTu cuon sach la:" << s.tuasach;
	cout << "\nTac gia cuon sach la:" << s.tacgia;
	cout << "\nNha suat ban cua cuon sach la:" << s.nxb;
	cout << endl;
}
void input(Node *&head,Sach &s)
{
	int n;
	Node *temp;
	temp = new Node;
	if (!temp)
	{
		cout << "\nKhong du bo nho!";
		return;
	}
	temp->next = NULL;

	do
	{
		cout << "\nNhap vao so luong sach can nhap:"; cin >> n;
		if (n <= 0)
		{
			cout << "\nSo luong phai lon hon 0,xin nhap lai!";
		}
	} while (n <= 0);
		
	for (int i = 0; i < n; i++)
	{
			cout << "\n---------Nhap cuon sach thu " << i + 1 << "----------\n";
			int check;
		do
		{
			check = 0;
			cout << "\nNhap vao ma sach:"; cin >> s.maso;
			for (Node *p = head; p != NULL; p=p->next)
			{
				if (p->info.maso == s.maso)
				{
					check = 1;
					break;
				}
			}
			if (check == 1)
			{
				cout << "\nMa sach da bi trung,xin nhap lai!";
			}
		} while (check == 1);
		nhapSach(s);
		addTohead(head, s);
		ThemCoThuTu(temp, s);
	}
	for (Node *p = temp->next; p != NULL; p = p->next)
	{
		xuatsach(p->info);
	}
}
void output(Node *head)
{
	int i = 0;
	for (Node *p = head; p != NULL; p = p->next)
	{
		cout << "\n-------Thong tin cuon sach thu " << ++i << " la--------" << endl;
		xuatsach(p->info);
	}
	cout << endl;
}
void TimTuaSach(Node *head,string TenTuaSach)
{
	for (Node *p = head; p != NULL; p = p->next)
	{
		if (p->info.tuasach == TenTuaSach)
		{
			cout << "\nTen tac gia cua tua sach " << TenTuaSach << " la:" << p->info.tacgia;
		}
	}
}

void InSachCungNXB(Node *head, string TenNXB)
{
	int check = 0;;
	for (Node *p = head; p != NULL; p = p->next)
	{
		if (p->info.nxb == TenNXB)
		{
			xuatsach(p->info);
			check = 1;
		}
		if (check == 0)
		{
			cout << "\nKhong co NXB " << TenNXB << " trong danh sach!";
		}
	}
}
int main()
{
	Node *head;
	head = NULL;
	Sach s;
	input(head,s);
	//output(head);
	//cout << "\n-----------------------\n";
	//TimTuaSach(head, "tai");
	//cout << "\n-----------------------\n";
	//InSachCungNXB(head, "kimdong");
	system("pause");
	return 0;
}
