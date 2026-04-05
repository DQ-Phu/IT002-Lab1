#include "SoPhuc.h"
#include <iostream>
#include <limits>
using namespace std;

void SoPhuc::Nhap() {
    while(true){
        cout << "Nhap phan thuc: ";
        cin >> iThuc;
        cout << "Nhap phan ao: ";
        cin >> iAo;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so thuc!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}

void SoPhuc::Xuat() {
    cout << iThuc;
    if (iAo >= 0)
        cout << " + " << iAo << "i";
    else
        cout << " - " << -iAo << "i";
}

/* Hàm tìm tổng 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là tổng 2 số phức */
SoPhuc SoPhuc::Tong(SoPhuc b) {
    SoPhuc kq;
    kq.iThuc = iThuc + b.iThuc;
    kq.iAo = iAo + b.iAo;
    return kq;
}

/* Hàm tìm hiệu 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là hiệu 2 số phức */
SoPhuc SoPhuc::Hieu(SoPhuc b) {
    SoPhuc kq;
    kq.iThuc = iThuc - b.iThuc;
    kq.iAo = iAo - b.iAo;
    return kq;
}

/* Hàm tìm tích 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là tích 2 số phức */
SoPhuc SoPhuc::Tich(SoPhuc b) {
    SoPhuc kq;
    kq.iThuc = iThuc * b.iThuc - iAo * b.iAo;
    kq.iAo = iThuc * b.iAo + iAo * b.iThuc;
    return kq;
}

/* Hàm tìm thương 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là thương 2 số phức */
bool SoPhuc::Thuong(SoPhuc b, SoPhuc &kq) {
    float mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    if (mau == 0) {
        return false;
    }
    kq.iThuc = (iThuc * b.iThuc + iAo * b.iAo) / mau;
    kq.iAo = (iAo * b.iThuc - iThuc * b.iAo) / mau;
    return true;
}
