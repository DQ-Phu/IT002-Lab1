#include <iostream>

using namespace std;

struct PhanSo{
    long tu;
    long mau;
};

// Hàm kiểm tra chuỗi có phải số nguyên hợp lệ
bool KT(string s) {
    if (s.empty()) return false; //chuỗi rỗng

    long i = 0;

    //Kiểm tra dấu âm/dương
    if (s[0] == '-' || s[0] == '+') {
        if (s.length() == 1) return false;// Có dẫu âm/dương mà không có số khác đi kèm
        i = 1; //bắt đầu từ số sau dấu -/+
    }

    for (; i < s.length(); i++) {
        if (!isdigit(s[i])) return false; //Kiểm tra chuỗi có phả là số không.
    }

    return true;
}

//Hàm nhập riêng từng phần tử của phân số
int NhapPhanTu(string TB) {
    string input;

    while (true) {
        cout << TB;
        cin >> input;

        if (!KT(input)) cout << "Nhap sai! Chi duoc nhap so nguyen.\n"; // Kiểm tra input đã nhập
        else return stoi(input); //chuyển input từ string sang interger
    }
}

//Hàm chuyển dấu âm ở mẫu lên tử
void PhanSoAm(PhanSo &a){
    if (a.mau < 0) {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
}

//Hàm nhập chung của từng struct phân số
void Nhap(PhanSo &a){
    string tbTu = "Nhap tu so: ", tbMau = "Nhap mau so: ";
    a.tu = NhapPhanTu(tbTu);

    while (true) {
        a.mau = NhapPhanTu(tbMau);
        if (a.mau == 0) cout << "Mau so khong duoc bang 0!\n"; //Kiểm tra mẫu số khác hay bằng 0
        else break;
    }
    PhanSoAm(a);
}

// Hàm xuất nếu có số lớn nhất
void Xuat (PhanSo a) {
    cout << "Phan so lon nhat la: " << a.tu << "/" << a.mau;
}

// Hàm xuất nếu 2 phân số bằng nhau
void Xuat (PhanSo a, PhanSo b){
    cout << "Hai phan so: " << a.tu << "/" << a.mau << " va " << b.tu << "/" << b.mau << " bang nhau";
}

//Hàm so sánh 2 phân số
int SoSanh (PhanSo a, PhanSo b){
    long long tu1 = a.tu * b.mau; // Nhân tử này với mẫu kia để so sánh
    long long tu2 = b.tu * a.mau;
    if (tu1 > tu2) return 1;    //tử phân số 1 > tử phân số 2
    else if (tu1 < tu2) return -1;  //tử phân số 1 < tử phân số 2
    else return 0;  // Trường hợp còn lại aka tử 1 = tử 2
}


int main(){
    PhanSo p, q;
    cout << "--- Phan so thu nhat ---\n";
    Nhap(p);

    cout << "--- Phan so thu hai ---\n";
    Nhap (q);

    int i = SoSanh(p, q);

    /*Dựa vào giá trị từ hàm so sánh
    để chon cách xuất kết quả phù hợp*/
    if (i == 1) Xuat(p);
    else if (i == -1) Xuat(q);
    else Xuat(p, q);
    return 0;
}
