#include "PhanSo.h"
#include <iostream>
#include <limits>
using namespace std;

/* Hàm tìm UCLN
Đầu vào là tử và mẫu của môt phân số
Đầu ra là ước chung lớn nhất của tử và mẫu */
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void PhanSo::Nhap(){
    while(true){
        cout << "Nhap tu so: "; cin >> iTu;
        cout << "Nhap mau so: "; cin >> iMau;
        cout << "\n";

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra số có phải là số nguyên hay không
        else if (cin.peek() != '\n') { //cin.peek() sẽ dừng khi gặp dấu chấm trong số thực => khác newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            continue;
        }

        //Kiểm tra mẫu bằng 0
        if (iMau == 0){
            cout << "Loi! Mau so phai khac 0!\n";
            continue;
        }
        //Nếu thỏa mãn mọi điều kiện thì break, kết thúc hàm nhập
        break;
    }
}


void PhanSo::Xuat(){
    cout << iTu << "/" << iMau << endl;
}

//Hàm rút gọn phân số
void PhanSo::RutGon(){
    int ucln = UCLN(abs(iTu), abs(iMau));
    iTu /= ucln;
    iMau /= ucln;

    // Đưa dấu về tử
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }

}

/* Hàm tìm tổng 2 phân số
Đầu vào tử và mãu của 2 phân số
Đầu ra là tổng 2 phân só đã rút gọn */
PhanSo PhanSo::Tong(PhanSo b){
    PhanSo kq;
    kq.iTu = iTu * b.iMau + b.iTu * iMau;
    kq.iMau = iMau * b.iMau;
    kq.RutGon();
    return kq;
}

/* Hàm tìm hiệu 2 phân số
Đầu vào tử và mãu của 2 phân số
Đầu ra là hiệu 2 phân só đã rút gọn */
PhanSo PhanSo::Hieu(PhanSo b){
    PhanSo kq;
    kq.iTu = iTu * b.iMau - b.iTu * iMau;
    kq.iMau = iMau * b.iMau;
    kq.RutGon();
    return kq;
}

/* Hàm tìm tích 2 phân số
Đầu vào tử và mãu của 2 phân số
Đầu ra là tích 2 phân só đã rút gọn */
PhanSo PhanSo::Tich(PhanSo b){
    PhanSo kq;
    kq.iTu = iTu * b.iTu;
    kq.iMau = iMau * b.iMau;
    kq.RutGon();
    return kq;
}

/* Hàm tìm thương 2 phân số
Đầu vào tử và mãu của 2 phân số
Đầu ra là thương 2 phân só đã rút gọn */
PhanSo PhanSo::Thuong(PhanSo b){
    PhanSo kq;
    kq.iTu = iTu * b.iMau;
    kq.iMau = iMau * b.iTu;
    kq.RutGon();
    return kq;
}


/* Hàm so sánh phân số
Đầu vào tử và mãu của 2 phân số
Đầu ra là A > B, A = B, A < B tùy theo kết quả */
void PhanSo::SoSanh(PhanSo b){
    int psA = iTu * b.iMau;
    int psB = b.iTu * iMau;

    if (psA > psB) cout << "\nA > B";
    if (psA == psB) cout << "\nA = B";
    if (psA < psB) cout << "\nA < B";
}
