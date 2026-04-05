#include "GioPhutGiay.h"
#include <iostream>
#include <limits>
using namespace std;

void GioPhutGiay::Nhap() {
        while (true) {
        cout << "Nhap theo dinh dang <Gio:Phut:Giay>: \n";
        cin >> iGio >> iPhut >> iGiay;

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

        if (iGio < 0 || iGio >= 24 ||
            iPhut < 0 || iPhut >= 60 ||
            iGiay < 0 || iGiay >= 60) {
            cout << "Loi! Thoi gian khong hop le!\n";
            continue;
        }

        // Khi thỏa hết điều kiện
        break;
    }
}

void GioPhutGiay::Xuat() {
    if (iGio < 10) cout << "0";
    cout << iGio << ":";

    if (iPhut < 10) cout << "0";
    cout << iPhut << ":";

    if (iGiay < 10) cout << "0";
    cout << iGiay << endl;
}

void GioPhutGiay::TinhCongThemMotGiay(){
    iGiay += 1; // cộng giây với 1
    // check nếu giây vược quá 60
    if (iGiay >= 60) {
        iGiay = 0;
        iPhut++;
    }

    // check nếu phút vược quá 60
    if (iPhut >= 60) {
        iPhut = 0;
        iGio++;
    }

    // check nếu giờ vược quá 24
    if (iGio >= 24) {
        iGio = 0;
    }
}
