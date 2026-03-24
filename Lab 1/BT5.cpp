#include <iostream>
#include <iomanip>
using namespace std;

struct HocSinh{
   string HoTen;
   float Toan;
   float Van;
};

bool KTHoTen(string a){
    if (a.empty()) return false;

    for (int i = 0; i < a.length(); i++) {
        if (!isalpha(a[i]) && a[i] != ' ') return false;
    }
    return true;
}

// Hàm kiểm tra chuỗi có phải số thực hợp lệ
bool KT(string s) {
    if (s.empty()) return false;

    bool hasDecimal = false;
    bool hasDigit = false;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) hasDigit = true;

        else if (s[i] == '.') { //KT kí tự lạ có phải là dấu chấm
            if (hasDecimal) return false; // Tối đa một dấu chấm
            hasDecimal = true;
        }
        else return false;
    }
    return hasDigit;
}

float NhapPhanTu(string TB) {
    string input;

    while (true) {
        cout << TB;
        cin >> input;

        if (!KT(input)) cout << "Nhap sai! Chi duoc nhap so thuc.\n"; // Kiểm tra input đã nhập
        else return stof(input); //chuyển input từ string sang float
    }
}

//Hàm nhập chung của từng struct phân số
void Nhap(HocSinh &a){
    string tbToan = "Nhap diem Toan: ", tbVan = "Nhap diem Van: ";

    while (true){
        cout << "Nhap ho ten: ";
        getline(cin, a.HoTen);
        if (KTHoTen(a.HoTen)) break;    //Kiểm tra họ tên
        else cout << "Ho ten khong hop le!\n";
    }

    while (true) {
        a.Toan = NhapPhanTu(tbToan);
        if (0 > a.Toan || a.Toan > 10) cout << "Diem Toan khong hop le!\n"; //Kiểm tra input diem
        else break;
    }

    while (true) {
        a.Van = NhapPhanTu(tbVan);
        if (0 > a.Van || a.Van > 10) cout << "Diem Van khong hop le!\n"; //Kiểm tra input diem
        else break;
    }
}

double DiemTB (const HocSinh &a){
    return (a.Toan + a.Van)/2.0; //Tính điểm tb
}

void Xuat(const HocSinh &a){
    cout << a.HoTen << "\tDTB: "
         << fixed << setprecision(2) << DiemTB(a); //làm tròn đến 2 chữ số thâp phân
}

int main(){
    HocSinh a;
    Nhap(a);
    Xuat(a);
    return 0;ư
}
