#include <stdio.h>
#include <stdlib.h>
#include "quanly3.h"

// Hàm xóa màn hình dùng mã ANSI
void xoaManHinh() {
    printf("\033[H\033[J");
}

// Hàm tạm dừng màn hình chuẩn C
void dungManHinh() {
    printf("\n\033[0;37m[Nhan Enter de tiep tuc...]\033[0m\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

int main() {
    KhachHang *danhSach = NULL;       
    KhachHang *taiKhoanHienTai = NULL; 
    int luaChon;

    taiDuLieu(&danhSach);

    while (1) {
        xoaManHinh();

        if (taiKhoanHienTai == NULL) {
            printf("\033[1;36m"); 
            printf("\n┌──────────────────────────────────────────────────────┐");
            printf("\n│           HE THONG QUAN LY PHONG MAY CYBER           │");
            printf("\n├──────────────────────────────────────────────────────┤");
            printf("\n│ \033[0;33mSo tai khoan hien co tren he thong: %-16d\033[1;36m │", demSoLuongKhach(danhSach));
            printf("\n├──────────────────────────────────────────────────────┤");
            printf("\n│ \033[0;37m[1] Dang nhap tai khoan                              \033[1;36m│");
            printf("\n│ \033[0;37m[2] Dang ky thanh vien moi                           \033[1;36m│");
            printf("\n│ \033[1;33m[3] Xem Bang gia & Khuyen mai VIP                    \033[1;36m│");
            printf("\n│ \033[0;31m[4] Thoat & Luu du lieu                              \033[1;36m│");
            printf("\n└──────────────────────────────────────────────────────┘\033[0m");
            printf("\n\033[1;32m» Chon chuc nang (1-4): \033[0m");
            scanf("%d", &luaChon);

            switch (luaChon) {
                case 1: taiKhoanHienTai = dangNhap(danhSach); break;
                case 2: dangKy(&danhSach); break;
                case 3: hienThiBangGia(); break;
                case 4: 
                    luuDuLieu(danhSach);
                    giaiPhongBoNho(&danhSach);
                    printf("\n\033[1;33m[He thong] Dang dong ung dung. Tam biet!\033[0m\n"); 
                    exit(0);
                default: printf("\n\033[1;31m[!] Lua chon khong hop le!\033[0m\n");
            }
        } else {
            printf("\033[1;35m"); 
            printf("\n┌──────────────────────────────────────────────────────┐");
            printf("\n│ \033[1;32mTAI KHOAN: %-41.41s\033[1;35m │", taiKhoanHienTai->tenKhach);
            printf("\n├──────────────────────────────────────────────────────┤");
            printf("\n│ \033[0;37m[1] Dat may & Bat dau choi                           \033[1;35m│");
            printf("\n│ \033[0;37m[2] Tinh tien & Tra may                              \033[1;35m│");
            printf("\n│ \033[0;37m[3] Nap tien vao tai khoan                           \033[1;35m│");
            printf("\n│ \033[0;37m[4] Xem chi tiet thong tin VIP                       \033[1;35m│");
            printf("\n│ \033[0;37m[5] Order dich vu (Do an / Nuoc uong)                \033[1;35m│");
            printf("\n│ \033[1;33m[6] Xem Bang gia & Khuyen mai VIP                    \033[1;35m│");
            printf("\n│ \033[0;31m[7] Dang xuat tai khoan                              \033[1;35m│");
            printf("\n└──────────────────────────────────────────────────────┘\033[0m");
            printf("\n\033[1;32m» Chon chuc nang (1-7): \033[0m");
            scanf("%d", &luaChon);

            switch (luaChon) {
                case 1:
                    printf("\033[0;36mNhap so may ban muon ngoi: \033[0m");
                    scanf("%d", &taiKhoanHienTai->soMay);
                    batDauChoi(taiKhoanHienTai);
                    break;
                case 2: thanhToan(taiKhoanHienTai); break;
                case 3: napTien(taiKhoanHienTai); break;
                case 4: xemThongTin(taiKhoanHienTai); break;
                case 5: goiMon(taiKhoanHienTai); break;
                case 6: hienThiBangGia(); break;
                case 7:
                    taiKhoanHienTai = NULL; 
                    printf("\n\033[1;32m[OK] Da dang xuat khoi phien lam viec.\033[0m\n");
                    break;
                default: printf("\n\033[1;31m[!] Lua chon khong hop le!\033[0m\n");
            }
        }
        
        dungManHinh();
    }
    return 0;
}