#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

int main(){
    GioPhutGiay T;

    T.Nhap();

    cout << "\nThoi gian ban da nhap la: ";
    T.Xuat();

    T.TinhCongThemMotGiay();

    cout << "Thoi gian sau khi cong them 1 giay la: ";
    T.Xuat();
}
