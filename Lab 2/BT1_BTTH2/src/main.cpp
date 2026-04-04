#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main(){
    NgayThangNam d;

    d.Nhap();

    cout << "\nNgay ban da nhap la: ";
    d.Xuat();

    d.NgayThangNamTiepTheo();

    cout << "Ngay ke tiep la: ";
    d.Xuat();
}
