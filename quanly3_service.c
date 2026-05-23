#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "quanly3.h"

// 1. NẠP TIỀN
void napTien(KhachHang *kh) {
    float tienNap;
    printf("\033[H\033[J");
    printf("\n\033[1;33m┌──────────────────────────────────────────────────────┐");
    printf("\n│                   NAP TIEN VAO VI                    │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTrang thai    : \033[0;37m%-36.36s \033[1;33m│", "Dang cho nhap so tien...");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[1;32m» Nhap so tien (VND): \033[0m");
    scanf("%f", &tienNap);

    if (tienNap > 0) {
        kh->soDu += tienNap;
        char bufferNap[50];
        char bufferDu[50];
        sprintf(bufferNap, "%.0f VND", tienNap);
        sprintf(bufferDu, "%.0f VND", kh->soDu);

        printf("\033[H\033[J");
        printf("\n\033[1;33m┌──────────────────────────────────────────────────────┐");
        printf("\n│                   NAP TIEN VAO VI                    │");
        printf("\n├──────────────────────────────────────────────────────┤");
        printf("\n│ \033[0;33mSo tien nap   : \033[0;37m%-36.36s \033[1;33m│", bufferNap);
        printf("\n│ \033[1;32mSo du hien tai: \033[1;32m%-36.36s \033[1;33m│", bufferDu);
        printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
        printf("\033[1;32m[Thanh cong] Giao dich hoan tat!\033[0m\n");
    }
    else {
        printf("\n\033[1;31m[Loi] So tien khong hop le!\033[0m\n");
    }
}

// 2. KIỂM TRA VIP
void kiemTraVIP(KhachHang *kh) { 
    if (kh->tongThoiGian >= 120) kh->capDoVIP = 2;
    else if (kh->tongThoiGian >= 60) kh->capDoVIP = 1;
}

// 3. MỞ MÁY
void batDauChoi(KhachHang *kh) {
    if (kh->dangSuDung == 1) {
        printf("\n\033[1;31m[Loi] May nay hoac phien choi cua ban dang hoat dong!\033[0m\n");
        return;
    }
    if (kh->soDu < 5000) {
        printf("\n\033[1;31m[Tu choi] So du (%.0f VND) duoi 5.000 VND. Vui long nap them tien!\033[0m\n", kh->soDu);
        return;
    }
    time(&kh->gioBatDau);
    kh->dangSuDung = 1;
    kh->tienDichVu = 0;
    printf("\n\033[1;32m[Khoi dong] Kich hoat may %d luc: %s\033[0m", kh->soMay, ctime(&kh->gioBatDau));
}
// 4. GỌI MÓN 
void goiMon(KhachHang *kh) {
    if (kh->dangSuDung == 0) {
        printf("\n\033[1;31m[Loi] Ban phai bat dau su dung may moi co the order!\033[0m\n");
        return;
    }

    int chonMon;
    float giaMon = 0;
    char tenMon[50] = "";

    printf("\n\033[1;33m┌──────────────────────────────────────────────────────┐");
    printf("\n│                THUC DON MENU SERVICES                │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;37m%-39s %12s \033[1;33m│", "[1] Mi tom trung dac biet", "15.000 VND");
    printf("\n│ \033[0;37m%-39s %12s \033[1;33m│", "[2] Com rang dua bo sieu cap", "35.000 VND");
    printf("\n│ \033[0;37m%-39s %12s \033[1;33m│", "[3] Nuoc ngot Sting dau lanh", "10.000 VND");
    printf("\n│ \033[0;37m%-39s %12s \033[1;33m│", "[4] Nuoc khoang thien nhien", "5.000 VND");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m");
    printf("\n\033[1;32m» Chon mon ban muon order (1-4): \033[0m");
    scanf("%d", &chonMon);

    switch (chonMon) {
    case 1: giaMon = 15000; strcpy(tenMon, "Mi tom trung"); break;
    case 2: giaMon = 35000; strcpy(tenMon, "Com rang dua bo"); break;
    case 3: giaMon = 10000; strcpy(tenMon, "Nuoc ngot Sting"); break;
    case 4: giaMon = 5000; strcpy(tenMon, "Nuoc loc"); break;
    default: printf("\n\033[1;31m[Loi] Mon ban chon khong co san!\033[0m\n"); return;
    }

    if (kh->soDu < giaMon) {
        printf("\n\033[1;31m[Tu choi] Tai khoan khong du tien de mua '%s'!\033[0m\n", tenMon);
    }
    else {
        kh->soDu -= giaMon;
        kh->tienDichVu += giaMon;
        printf("\n\033[1;32m[Order] Thanh cong! '%s' se duoc phuc vu tai may %d.\033[0m\n", tenMon, kh->soMay);
    }
}

// 5. THANH TOÁN 
void thanhToan(KhachHang *kh) {
    if (kh->dangSuDung == 0) {
        printf("\n\033[1;31m[Loi] May dang o trang thai trong, khong can thanh toan!\033[0m\n");
        return;
    }

    time_t gioKetThuc;
    time(&gioKetThuc);

    double giayChoi = difftime(gioKetThuc, kh->gioBatDau);
    kh->tongThoiGian += giayChoi;
    kiemTraVIP(kh);

    double giaTienGoc = 10000;
    double tienGio = (giayChoi / 3600.0) * giaTienGoc;

    if (kh->capDoVIP == 1) tienGio = tienGio * 0.9;
    else if (kh->capDoVIP == 2) tienGio = tienGio * 0.8;

    kh->soDu -= tienGio;

    printf("\n\033[1;32m┌──────────────────────────────────────────────────────┐");
    printf("\n│                   HOA DON DICH VU                    │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;37mKhach hang: %-40.40s \033[1;32m│", kh->tenKhach);
    printf("\n│ \033[0;37mVi tri may: May so %-33d \033[1;32m│", kh->soMay);
    printf("\n│ \033[0;37mThoi gian choi phien nay: %21.2f giay \033[1;32m│", giayChoi);
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;37mChi phi gio choi (Da tinh VIP): %16.2f VND \033[1;32m│", tienGio);
    printf("\n│ \033[0;37mChi phi dich vu an uong:        %16.0f VND \033[1;32m│", kh->tienDichVu);
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[1;33mTONG TIEN PHIEN NAY:            %16.2f VND \033[1;32m│", tienGio + kh->tienDichVu);
    printf("\n│ \033[1;33mSO DU CON LAI TRONG VI:         %16.0f VND \033[1;32m│", kh->soDu);
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");

    kh->dangSuDung = 0;
    kh->tienDichVu = 0;
}

// 6. XEM THÔNG TIN 
void xemThongTin(KhachHang *kh) {
    char vipStr[50];
    if (kh->capDoVIP == 2) strcpy(vipStr, "Diamond (Giam 20%)");
    else if (kh->capDoVIP == 1) strcpy(vipStr, "Gold (Giam 10%)");
    else strcpy(vipStr, "Thuong");

    printf("\n\033[1;34m┌──────────────────────────────────────────────────────┐");
    printf("\n│                 THONG TIN TAI KHOAN                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;37mChu tai khoan: %-37.37s \033[1;34m│", kh->tenKhach);
    printf("\n│ \033[0;37mSo du vi hien tai: %29.0f VND \033[1;34m│", kh->soDu);
    printf("\n│ \033[0;37mTich luy phien may: %27.0f giay \033[1;34m│", kh->tongThoiGian);
    printf("\n│ \033[0;37mPhan hang thanh vien: %-30.30s \033[1;34m│", vipStr);
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
}

// 7. BẢNG GIÁ & QUẢNG CÁO VIP
void hienThiBangGia() {
    printf("\033[H\033[J");
    printf("\n\033[1;35m┌──────────────────────────────────────────────────────┐");
    printf("\n│\033[1;32m             BANG GIA & UU DAI THANH VIEN             \033[1;35m│");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[1;33m[ GIA GIO CHOI TIEU CHUAN ]\033[0;37m                          \033[1;35m│");
    printf("\n│ \033[0;37m* Dong gia moi may:             10.000 VND / 1 Gio   \033[1;35m│");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[1;33m[ CHINH SACH VIP - TU DONG THANG HANG ]\033[0;37m              \033[1;35m│");
    printf("\n│ \033[0;37m* VIP 0 (Thuong) : Duoi 60s      -> Khong giam gia   \033[1;35m│");
    printf("\n│ \033[0;37m* VIP 1 (Gold)   : Tu 60s - 120s -> Giam 10%% tien    \033[1;35m│");
    printf("\n│ \033[0;37m* VIP 2 (Diamond): Tren 120s     -> Giam 20%% tien    \033[1;35m│");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│\033[1;36m       CHAY BO TUNG BUNG - CHOI GAME CUC SUNG!        \033[1;35m│");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
}