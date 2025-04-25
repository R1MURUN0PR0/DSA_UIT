#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &B, double heso, int somu){
    DONTHUC* newDonthuc = new DONTHUC(heso, somu);
    Node* newNode = new Node(newDonthuc);
    if(!B.head) B.head = B.tail = newNode;
    else {
        B.tail->next = newNode;
        B.tail = newNode;
    }
}

void Xuat(DATHUC B){
    if(!B.head)
        cout << 0;
    
    else{
        Node* cur = B.head;
        bool hasOutput = true;
        while(cur){
            double heso = cur->data->heso;
            int somu = cur->data->somu;

            if(heso == 0){
                cur = cur->next;
                continue;
            }
            if(!hasOutput && heso > 0) cout << "+";
            if(somu == 0) cout << heso;
            else{
                if(heso == -1) cout << "-";
                else if(heso != 1) cout << heso;
                cout << "x";
                if(somu != 1) cout << "^" << somu;
            }
            hasOutput = false;
            cur = cur->next;
        }
        if(hasOutput) cout << 0;
    }
}

double TinhDaThuc(DATHUC B, double x){
    if(!B.head)
        return 0;
    
    Node* cur = B.head;
    double sum = 0;
    while(cur){
        const double heso = cur->data->heso;
        int somu = cur->data->somu;
        sum += heso * pow(x, somu);
        cur = cur->next;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
