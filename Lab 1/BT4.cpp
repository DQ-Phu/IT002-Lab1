#include <iostream>
using namespace std;

struct Date{
   int day;
   int month;
   int year;
};


bool leapCheck (int year) // Hàm kiểm tra năm nhuận
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}

int howManyDays(int month, int year) //Hàm kiểm tra số ngày trong tháng
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && leapCheck(year))
        return 29;
    return days[month - 1];
}

// Hàm kiểm tra chuỗi có phải số nguyên hợp lệ
bool KT(string s) {
    if (s.empty()) return false; //chuỗi rỗng

    long i = 0;

    for (; i < s.length(); i++) {
        if (!isdigit(s[i])) return false; //Kiểm tra chuỗi có phải là số không.
    }

    return true;
}

int NhapPhanTu(string TB) {
    string input;

    while (true) {
        cout << TB;
        cin >> input;

        if (!KT(input)) cout << "Nhap sai! Chi duoc nhap so nguyen.\n"; // Kiểm tra input đã nhập
        else return stoi(input); //chuyển input từ string sang interger
    }
}

void Nhap(Date &d){
    while(true){
        string tbDay = "Nhap ngay: ", tbMonth = "Nhap thang: ", tbYear = "Nhap nam: ";
        d.day = NhapPhanTu(tbDay);
        d.month = NhapPhanTu(tbMonth);
        d.year = NhapPhanTu(tbYear);
        if (howManyDays(d.month, d.year) < d.day || d.month > 12) cout << "\nNgay vua nhap khong hop le!\n\n";
        else break;
    }
}

Date addDate(Date d) //Hàm tìm ngày kế tiếp
{
    d.day += 1;
    while (d.day > howManyDays(d.month, d.year)) // nếu ngày vược quá số ngày trong tháng
    {
        d.day -= howManyDays(d.month, d.year); //Số ngày vược quá - số ngày trong tháng = 1
        d.month++;  // thêm 1 tháng
        if (d.month > 12) { //nếu tháng vược quá 12
            d.month = 1;
            d.year++; //thêm 1 năm
        }
    }
    return d;
}

void newDate (Date d)
{
    cout << "Ngay ke tiep la: " << endl;
    cout << d.day << "/"
         << d.month << "/"
         << d.year;
}

int main()
{
    Date d;
    Nhap(d);
    int numDays;
    d = addDate(d);
    newDate (d);
    return 0;
}
