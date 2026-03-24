#include <iostream>

using namespace std;

struct PhanSo{
    long tu;
    long mau;
};

// Hàm kiểm tra chuỗi có phải số nguyên hợp lệ
bool KT(string s) {
    if (s.empty()) return false; //chuỗi rỗng

    long i = 0;

    //Kiểm tra dấu âm/dương
    if (s[0] == '-' || s[0] == '+') {
        if (s.length() == 1) return false;// Có dẫu âm/dương mà không có số khác đi kèm
        i = 1; //bắt đầu từ số sau dấu -/+
    }

    for (; i < s.length(); i++) {
        if (!isdigit(s[i])) return false; //Kiểm tra chuỗi có phả là số không.
    }

    return true;
}

//Hàm nhập riêng từng phần tử của phân số
int NhapPhanTu(string TB) {
    string input;

    while (true) {
        cout << TB;
        cin >> input;

        if (!KT(input)) cout << "Nhap sai! Chi duoc nhap so nguyen.\n"; // Kiểm tra input đã nhập
        else return stoi(input); //chuyển input từ string sang interger
    }
}

//Hàm chuyển dấu âm ở mẫu lên tử
void PhanSoAm(PhanSo &a){
    if (a.mau < 0) {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
}

//Hàm nhập chung của từng struct phân số
void Nhap(PhanSo &a){
    string tbTu = "Nhap tu so: ", tbMau = "Nhap mau so: ";
    a.tu = NhapPhanTu(tbTu);

    while (true) {
        a.mau = NhapPhanTu(tbMau);
        if (a.mau == 0) cout << "Mau so khong duoc bang 0!\n"; //Kiểm tra mẫu số khác hay bằng 0
        else break;
    }
    PhanSoAm(a);
}

// Hàm tìm UCLN
long gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//Hàm rút gọn phân số
void RutGon (long &tu, long &mau){
    long ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

void Tong(const PhanSo &a, const PhanSo &b){
    long tu1 = a.tu * b.mau;
    long tu2 = b.tu * a.mau;
    long mau = a.mau * b.mau;

    long tu = tu1 + tu2;
    RutGon(tu, mau);
    cout << "\nTong 2 phan so la: " << tu << "/" << mau << endl;
}

void Hieu(const PhanSo &a, const PhanSo &b){
    long tu1 = a.tu * b.mau;
    long tu2 = b.tu * a.mau;
    long mau = a.mau * b.mau;

    long tu = tu1 - tu2;
    RutGon(tu, mau);
    cout << "Hieu 2 phan so la: " << tu << "/" << mau << endl;
}

void Tich(const PhanSo &a, const PhanSo &b){
    long tu = a.tu * b.tu;
    long mau = a.mau * b.mau;
    RutGon(tu, mau);
    cout << "Tich 2 phan so la: " << tu << "/" << mau << endl;
}

void Thuong(const PhanSo &a, const PhanSo &b){
    long tu = a.tu * b.mau;
    long mau = a.mau * b.tu;
    RutGon(tu, mau);
    cout << "Thuong 2 phan so la: " << tu << "/" << mau << endl;
}

int main(){
    PhanSo p, q;
    cout << "--- Phan so thu nhat ---\n";
    Nhap(p);

    cout << "--- Phan so thu hai ---\n";
    Nhap (q);

    Tong(p, q);
    Hieu(p, q);
    Tich(p, q);
    Thuong(p, q);

    return 0;
}
