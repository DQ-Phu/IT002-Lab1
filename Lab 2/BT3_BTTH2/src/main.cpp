#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main() {
    SoPhuc a, b, kq;

    cout << "Nhap so phuc A:\n";
    a.Nhap();

    cout << "Nhap so phuc B:\n";
    b.Nhap();

    cout << "\nHai so phuc da nhap la:";
    cout << "\nSo Phuc A: "; a.Xuat();
    cout << "\nSo Phuc B: "; b.Xuat();

    cout << "\n\nTong: ";
    kq = a.Tong(b);
    kq.Xuat();

    cout << "\nHieu: ";
    kq = a.Hieu(b);
    kq.Xuat();

    cout << "\nTich: ";
    kq = a.Tich(b);
    kq.Xuat();

    cout << "\nThuong: ";
    if (a.Thuong(b, kq)) kq.Xuat();
    else cout << "Khong the chia hai so phuc nay!\n";

    return 0;
}
