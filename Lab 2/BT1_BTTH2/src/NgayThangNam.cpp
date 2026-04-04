#include "NgayThangNam.h"
#include <iostream>
#include <limits>
using namespace std;

/* Hàm kiểm tra năm nhuận
Đàu vào: Năm
Đầu ra: True nếu là năm nhuận, ngược lại thì False */
bool leapCheck (int iNam)
{
    if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
        return true;
    return false;
}

/*Hàm kiểm tra số ngày trong tháng
Đàu vào: Tháng, Năm
Đầu ra: Số ngày trong tháng đó */
int howManyDays(int iThang, int iNam)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (iThang == 2 && leapCheck(iNam)) //Kiểm tra tháng 2 năm nhuận
        return 29;
    return days[iThang - 1];
}


void NgayThangNam::Nhap(){
    while (true) {
        cout << "Nhap theo dinh dang ngay/thang/nam: \n";
        cin >> iNgay >> iThang >> iNam;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Kiểm tra việc nhập ngày tháng năm có hợp lệ
        if (iNam <= 0 || iThang < 1 || iThang > 12 || iNgay < 1) {
            cout << "Loi! Ngay thang nam khong hop le!\n";
            continue;
        }

        // Kiểm tra số ngày có nhiều hơn số ngày trong từng tháng
        if (iNgay > howManyDays(iThang, iNam)) {
            cout << "Loi! Ngay vuoc qua so ngay trong thang!\n";
            continue;
        }

        // Khi thỏa hết điều kiện
        break;
    }
}

void NgayThangNam::Xuat(){
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

//Hàm tìm ngày kế tiếp
void NgayThangNam::NgayThangNamTiepTheo(){
    iNgay += 1; // cộng ngày với 1 để tìm ngày kế tiếp
    while (iNgay > howManyDays(iThang, iNam)) // check nếu ngày vược quá số ngày trong tháng
    {
        iNgay = 1;
        iThang++;  // thêm 1 tháng
        if (iThang > 12) { // check nếu tháng vược quá 12
            iThang = 1;
            iNam++; // thêm 1 năm
        }
    }
}

