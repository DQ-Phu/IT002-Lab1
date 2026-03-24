#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm kiểm tra chuỗi có phải số nguyên hợp lệ
bool KT(string s) {
    if (s.empty()) return false; //chuỗi rỗng

    int i = 0;

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

// Hàm nhập số nguyên
int Nhap(string TB) {
    string input;

    while (true) {
        cout << TB;
        cin >> input;

        if (!KT(input)) cout << "Nhap sai! Chi duoc nhap so nguyen.\n"; // Kiểm tra input đã nhập
        else return stoi(input); //chuyển input từ string sang interger
    }
}

//Hàm xuất
void Xuat(int tu, int mau){
    cout << "Phan so sau khi rut gon: " << tu << "/" << mau << endl;
}

// Hàm tìm UCLN
int gcd(int a, int b) {
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
void RutGon (int &tu, int &mau){
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

int main() {
    string tbTu = "Nhap tu so: ", tbMau = "Nhap mau so: ";
    int tu = Nhap(tbTu);
    int mau;

    while (true) {
        mau = Nhap(tbMau);
        if (mau == 0) cout << "Mau so khong duoc bang 0!\n"; //Kiểm tra mẫu số khác hay bằng 0
        else break;
    }
    RutGon(tu, mau);
    Xuat(tu, mau);
    return 0;
}
