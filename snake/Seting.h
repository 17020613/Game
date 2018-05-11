#ifndef SETING_H_INCLUDED
#define SETING_H_INCLUDED

enum TrangThai {UP,DOWN,RIGHT,LEFT};

struct ToaDo{
    int x, y;
};
struct Snake{
    int dodai;
    ToaDo Dot[50];
    TrangThai tt;
    int diem;
    int level;
};
struct HoaQua{
    ToaDo td;
};

void KhoiTao(Snake &S, HoaQua &HQ);
void HienThi(Snake S, HoaQua HQ);
void DieuKhien(Snake &S);
int XuLy(Snake &S, HoaQua &HQ, int thoigianSleep);

#endif // SETING_H_INCLUDED
