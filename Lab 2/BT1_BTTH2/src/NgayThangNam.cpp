#include "NgayThangNam.h"
#include <iostream>
#include <limits>
using namespace std;


/* Đầu vào là một phân số nhập vào
Đầu ra la */

/* Hàm kiểm tra năm nhuận
Đàu vào: Năm
Đầu ra: True nếu là năm nhuận, ngược lại thì False */
bool leapCheck (int Y)
{
    if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
        return true;
    return false;
}

/*Hàm kiểm tra số ngày trong tháng
Đàu vào: Tháng, Năm
Đầu ra: Số ngày trong tháng đó */
int howManyDays(int M, int Y)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (M == 2 && leapCheck(Y)) //Kiểm tra tháng 2 năm nhuận
        return 29;
    return days[M - 1];
}


void NgayThangNam::Nhap(){
    while (true) {
        cout << "Nhap theo dinh dang ngay/thang/nam: \n";
        cin >> D >> M >> Y;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Kiểm tra việc nhập ngày tháng năm có hợp lệ
        if (Y <= 0 || M < 1 || M > 12 || D < 1) {
            cout << "Loi! Ngay thang nam khong hop le!\n";
            continue;
        }

        // Kiểm tra số ngày có nhiều hơn số ngày trong từng tháng
        if (D > howManyDays(M, Y)) {
            cout << "Loi! Ngay vuoc qua so ngay trong thang!\n";
            continue;
        }

        // Khi thỏa hết điều kiện
        break;
    }
}

void NgayThangNam::Xuat(){
    cout << D << "/" << M << "/" << Y << endl;
}

//Hàm tìm ngày kế tiếp
void NgayThangNam::NgayThangNamTiepTheo(){
    D += 1; // cộng ngày với 1 để tìm ngày kế tiếp
    while (D > howManyDays(M, Y)) // check nếu ngày vược quá số ngày trong tháng
    {
        D = 1;
        M++;  // thêm 1 tháng
        if (M > 12) { // check nếu tháng vược quá 12
            M = 1;
            Y++; // thêm 1 năm
        }
    }
}

