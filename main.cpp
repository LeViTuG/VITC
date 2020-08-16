
//De:Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
//tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'.
//Đưa các ma trận ra màn hình theo định dạng hàng, cột.

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n;

    public:
        MaTran();
        MaTran operator+(const MaTran &mt2);

        //Hàm bạn
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream&  operator<<(ostream &cout,const MaTran &mt);
};

//===chương trình chính===
int main()
{
    //Tao 3 doi tuong ma tran
    MaTran A,B,C;

    //Tao 2 doi tuong tep
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc 2 ma tran A va B tu tep vao doi tuong A, B tuong ung
    finA>>A;
    finB>>B;

   //Tinh tong
    C = A + B;

    //Dua ra cac ma tran
    cout<<"Ma trận A:\n"<<A;

    cout<<"\n\nMa trận B:\n"<<B;

    cout<<"\n\nMa trận C = A + B:\n"<<C;

    cout<<endl;
    return 0;
}

//===đinh nghĩa hàm===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(const MaTran &mt2)
{
    MaTran tg;

    if(m != mt2.m || n != mt2.n)
    {
        cout<<"Hai ma trận không cùng kích thước,không cộng được.";
        return tg;
    }

    //Cong 2 ma tran
    tg.m = m; tg.n = n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            tg.a[i][j] = a[i][j] + mt2.a[i][j];

    //Tra ve ma tran tong
    return tg;
}

ifstream& operator>>(ifstream &fin,MaTran &mt)
{
 fin>>mt.m>>mt.n;
    for(int i=0;i<mt.m;i++)
        for(int j=0;j<mt.n;j++)
            fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,const MaTran &mt)
{
    for(int i=0;i<mt.m;i++)
    {
        for(int j=0;j<mt.n;j++)
            printf("%5d",mt.a[i][j]);

        //Xuong dong
        printf("\n");
    }

    return cout;
}

//De: Ung dung ngan xep luu tru phan tan de chuyen so he 10 thanh he 16

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop ngan xep
class Stack
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *T;

    public:
        //Ham tao
        Stack();
        Stack(const Stack &s);

        //Ham huy
        ~Stack();

        //Ham chong toan toan tu gan
        Stack operator=(const Stack &right);

        //Cac ham thanh vien cai dat cac phep toan
        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong ngan xep
    Stack S;
   int n,thuong,du;

    cout<<"Nhập vào một số nguyên dương: "; cin>>n;

    //Chuyen he 10 thanh he 16
    thuong=n;
    while(thuong)
    {
        S.push(thuong%16);
        thuong/=16;
    }

    cout<<"Số hex của "<<n<<" là: ";;
    while(!S.isEmpty())
    {
        du = S.pop();
        if(du<10) cout<<du;
        else printf("%c",du+55);
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(NULL)
{

}

Stack::Stack(const Stack &s):T(NULL)
{
    node *P=s.T,*N,*Bottom;

    //Duyet qua cac nut cua ngan xep s
    while(P)
    {
        //Tao nut moi, copy phan tu tu P sang
        N = new node;
        N->infor = P->infor;
        N->link = NULL;

        //Noi nut moi vao day ngan xep moi tao
        if(T==NULL)
        {
            T = Bottom = N;
        }
        else
        {
            Bottom->link = N;
            Bottom = N;
        }
    }
}

Stack::~Stack()
{
    node *P;

    while(T)
    {
        P = T;
        T = T->link;
        delete P;
    }
}

Stack Stack::operator=(const Stack &right)
{
    //1.Huy cac nut cua doi tuong ben trai
    node *P;

    while(T)
    {
        T=T->link;
        delete P;
    }

    //2.Tao cac nut cua doi tuong ben trai la ban sao cac nut cua doi tuong ben phai (right)
    node *N,*Bottom;

    //Duyet cac nut cua ngan xep right de gan cho doi tuong phai
    P = right.T;
    while(P)
    {
       //Tao nut moi
        N = new node;
        N->infor=P->infor;
        N->link=NULL;

        //Noi nut moi vao doi tuong ben trai
        if(T==NULL)
            T=Bottom=N;
        else
        {
            Bottom->link=N;
            Bottom=N;
        }

        //Cho P tro xuong nut ben duoi
        P=P->link;
    }

    //Tra ve doi tuong ngan xep ben trai
    return *this;
}

void Stack::push(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao tren nut T
    N->link = T;

    //3.Cho T tro sang nut moi
    T = N;
}
int Stack::pop()
{
    //Kiem tra ngan xep rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!!!";
        return 1;
    }

    //Giu lai phan tu dinh
    int tg = T->infor;
    node *P = T;

    //Cho T tro xuong nut ben duoi
    T = T->link;

    //Huy nut va tra ve phan tu dinh
    delete P;
    return tg;
}

bool Stack::isEmpty()
{
    return T==NULL;
}

Bài 32(lthdtbai32.cpp): Cho tệp văn bản chứa dãy số nguyên "lthdtbai32-daysonguyen.txt",
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản,
lưu dãy số trong danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        }*F;

    public:
        SList();
        ~SList();
        void lastInsert(int x);
        bool search(int x);
        void show();
        bool remove(int x);
};

//===chuong trinh chinh===
int main()
{
    //Tao cac doi tuong
    ifstream fin("lthdtbai32-daysonguyen.txt");
    SList SL;

    //Doc day so tu tep vao DSLKD
    int x;
    while(fin>>x) SL.lastInsert(x);

    //Dua day so trong DSLKD ra man hinh
    cout<<"Dãy số trong DSLKD là:\n";
    SL.show();

    //Tim va xoa x
    cout<<"\nNhập vào x: ";
    cin>>x;

    if(SL.search(x)) cout<<"\n\nĐã tìm thấy "<<x<<" trong DSLKD.";
    else cout<<"\n\nKhông tìm thấy "<<x<<" trong DSLKD.";

    if(SL.remove(x)) cout<<"\n\nĐã loại bỏ "<<x<<" khỏi DSLKD.";
    else cout<<"\n\nKhông xóa được "<<x<<" trong DSLKD vì không thấy.";

    cout<<"\n\nDãy số trong DSLKD sau khi xóa là:\n";
    SL.show();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SList::SList():F(NULL)
{

}

SList::~SList()
{
    while(F)
    {
        node *P=F;
        F=F->link;
        delete P;
    }
}

void SList::lastInsert(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;
    //2.Noi nut moi vao cuoi DSLKD
    if(F==NULL) F = N;
    else
    {
        //Tim den nut cuoi cung
        node *P = F;
        while(P->link) P = P->link;

        //Noi nut moi vao sau nut cuoi
        P->link = N;
    }
}

bool SList::search(int x)
{
    node *M=F;
    while(M)
    {
        if(M->infor==x) return 1;
        else M=M->link;
    }

    //Khong tim thay
    return 0;
}

void SList::show()
{
    node *P=F;
    while(P)
    {
        cout<<P->infor<<"  ";
        P=P->link;
    }
}

bool SList::remove(int x)
{
    //Truong hop DSLKD rong
    if(F==NULL) return 0;

    //Tim nut co phan tu bang x, M, va nut dung truoc M, P
    node *M=F,*P;
    while(M)
        if(M->infor == x) break;
        else
        {
            P=M; M=M->link;
        }

    //Xoa nut M
    if(M)
    {
        //Ngat ket noi voi nut M
        if(M==F) F=F->link;
        else P->link = M->link; //Noi nut truoc M voi nut sau M

        //Xoa nut M
        delete M;

        //Tra 1 de bao da xoa thanh cong
        return 1;
    }

    //Khong co phan tu bang x
    return 0;
}



//De: Ứng dụng ngăn xếp lưu trữ kế tiếp để chuyển số nguyên dương hệ 10 sang hệ 2.

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
        enum {size=32};
        int S[size];
        int T;

    public:
        Stack();//Ham tao khong doi so

        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong ngan xep
    Stack S;

    //Khai bao bien
    int n,thuong;

    cout<<"Nhập vào một số nguyên dương: "; cin>>n;

    //Chuyen he 10 thanh he 2
    thuong=n;
    while(thuong)
    {
        S.push(thuong%2);
        thuong/=2;
	}
    cout<<"Số nhị phân của "<<n<<" là: ";;
    while(!S.isEmpty()) cout<<S.pop();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(-1)
{

}

void Stack::push(int x)
{
    //1.Kiem tra day
    if(T==size-1)
    {
        cout<<"Ngăn xếp đã đầy!";
        return;
    }

    //2.Bổ sung x vào ngăn xếp
    S[++T]=x;
}

int Stack::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
        cout<<"Ngăn xếp đã rỗng!";
        return 1;
    }

    //2.Lay va tra ve phan tu dinh
    return S[T--];
}

bool Stack::isEmpty()
{
    return T==-1;
}



//De: Ung dung ngan xep luu tru phan tan de chuyen so he 10 thanh he 2

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop ngan xep
class Stack
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *T;

    public:
        //Ham tao
        Stack();
        Stack(const Stack &s);

        //Ham huy
        ~Stack();

        //Ham chong toan toan tu gan
        Stack operator=(const Stack &right);

        //Cac ham thanh vien cai dat cac phep toan
        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(NULL)
{

}

Stack::Stack(const Stack &s):T(NULL)
{
    node *P=s.T,*N,*Bottom;

    //Duyet qua cac nut cua ngan xep s
    while(P)
    {
        //Tao nut moi, copy phan tu tu P sang
        N = new node;
        N->infor = P->infor;
        N->link = NULL;

        //Noi nut moi vao day ngan xep moi tao
        if(T==NULL)
        {
            T = Bottom = N;
        }
        else
        {
            Bottom->link = N;
            Bottom = N;
        }
    }
}

Stack::~Stack()
{
    node *P;

    while(T)
    {
        P = T;
        T = T->link;
        delete P;
    }
}
Stack Stack::operator=(const Stack &right)
{
    //1.Huy cac nut cua doi tuong ben trai

    //2.Tao cac nut cua doi tuong ben trai la ban sao cac nut cua doi tuong ben phai (right)
}

void Stack::push(int x)
{

}

int Stack::pop()
{

}

bool Stack::isEmpty()
{

}


      //De: Tạo mẫu lớp ngăn xếp lưu trữ kế tiếp. 
Ứng dụng ngăn xếp để chuyển số nguyên dương hệ 10 sang hệ 2 và hệ 16.

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
template <class Type>
class Stack
{
    private:
        enum {size=32};
        Type S[size];
        int T;

    public:
        Stack();//Ham tao khong doi so

        void push(Type x);
        Type pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

    //Tao doi tuong ngan xep S1 co kieu phan tu la so nguyen
    Stack<int> S1;

    //Tao doi tuong ngan xep S2 co kieu phan tu la ky tu
    Stack<char> S2;

    //Khai bao bien
    int n,thuong,du;

    cout<<"Nhập vào một số nguyên dương: "; cin>>n;

    //Chuyen he 10 thanh he 2
    thuong=n;
    while(thuong)
    {
        S1.push(thuong%2);
        thuong/=2;
    }

    cout<<"Số nhị phân của "<<n<<" là: ";;
    while(!S1.isEmpty()) cout<<S1.pop();

    //Chuyen he 10 thanh he 16
    thuong=n;
    while(thuong)
    {
        du=thuong%16;

        if(du<10) S2.push(du+48); //chuyen so thanh chu so roi day vao ngan xep
        else S2.push(du+55); //chuyen so thanh chu cai roi day vao ngan xep

        thuong/=16;
    }

    cout<<"\nSố hex của "<<n<<" là: ";;
    while(!S2.isEmpty()) cout<<S2.pop();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
template <class Type>
Stack<Type>::Stack():T(-1)
{

}

template <class Type>
void Stack<Type>::push(Type x)
{
    //1.Kiem tra day
    if(T==size-1)
    {
        cout<<"Ngăn xếp đã đầy!";
        return;
    }

    //2.Bổ sung x vào ngăn xếp
    S[++T]=x;
}

template <class Type>
Type Stack<Type>::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
        cout<<"Ngăn xếp đã rỗng!";
        Type tg;
        return tg;
    }

    //2.Lay va tra ve phan tu dinh
    return S[T--];
}

template <class Type>
bool Stack<Type>::isEmpty()
{
    return T==-1;
}


/*42(lthdtbai42.cpp): Tính diện tích và chu vi các hình: Hình chữ nhật biết 2 cạnh,
hình tam giác biết 3 cạnh, hình đtròn biết bán kính. Nhập vào một số hình trong đó
có cả hình chữ nhật, hình tam giác và hình tròn. Đưa ra diện tích
và chu vi các hình đã nhập. Y/c cài ặt đa hình động và lớp trừu tượng; viết 1 hàm
lựa chọn hình, nhập kích thước cho hình và trả về hình đã nhập; viết 1 hàm đưa ra
diện tích và chu vi của một hình truyền vào qua đối số.
*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
        virtual float tinhCV()=0;
};

class hinhCN:public hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

class hinhTG:public hinh
{
    private:
        float a,b,c;
    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

class hinhTR:public hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao ham thong thuong
hinh* nhapDL();
void hienTT(hinh *h);

//===chuong trinh chinh===
int main()
{
    hinh *dsHinh[50];
    int n=0,i;
    char traLoi;

    do
    {
        dsHinh[n++] = nhapDL();
        cout<<"\nCó nhập tiếp không(c/k)? ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra
    cout<<"\n\nDiện tích và chu vi các hình đã nhập là:";
    for(i=0;i<n;i++)
    {
        cout<<"\nHình thứ "<<i+1<<":\n";
        hienTT(dsHinh[i]);
        cout<<endl;
    }

    cout<<endl;
    return 0;
};
//===dinh nghia ham===
//ham lop HCN
void hinhCN::nhap()
{
    cout<<"Nhập vào 2 cạnh của hình chữ nhật: ";
    cin>>a>>b;
}

float hinhCN::tinhDT()
{
    return a*b;
}

float hinhCN::tinhCV()
{
    return (a+b)*2;
}

//ham lop hinh tam giac
void hinhTG::nhap()
{
    do
    {
        cout<<"Nhập vào 3 cạnh tam giác: ";
        cin>>a>>b>>c;
        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 số đã nhập không phải 3 cạnh tam giác. Nhập lại!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

float hinhTG::tinhDT()
{
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float hinhTG::tinhCV()
{
    return a+b+c;
}

//ham lop hinh tron
void hinhTR::nhap()
{
    cout<<"Nhập vào bán kính hình tròn: ";
    cin>>r;
}

float hinhTR::tinhDT()
{
    return 3.14*r*r;
}

float hinhTR::tinhCV()
{
    return 2*3.14*r;
}

//Ham thong thuong
hinh* nhapDL()
{
    hinh *h;
    char chon;

    cout<<"Bạn nhập kích thước hình nào(1-CN,2-TG,3-TR): ";
    cin>>chon;

    //Tao doi hinh tuong ung voi lua chon cua nguoi dung
    switch(chon)
    {
        case '1':
            h = new hinhCN;
            break;

        case '2':
            h = new hinhTG;
            break;

        case '3':
            h = new hinhTR;
            break;

        default:
            h = new hinhCN;
    }

    //Nhap kich thuoc hinh da chon
    h->nhap(); //Da hinh dong

    //Tra ve hinh da nhap
    return h;
}

void hienTT(hinh *h)
{
    printf("Diện tích là: %0.1f",h->tinhDT());
    printf("\nChu vi là: %0.1f",h->tinhCV());
}



