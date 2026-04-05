#ifndef SOPHUC_H
#define SOPHUC_H


class SoPhuc
{
    private:
        float iThuc;
        float iAo;
    public:
        void Nhap();
        void Xuat();

        SoPhuc Tong(SoPhuc b);
        SoPhuc Hieu(SoPhuc b);
        SoPhuc Tich(SoPhuc b);
        bool Thuong(SoPhuc b, SoPhuc &kq);
};

#endif // SOPHUC_H
