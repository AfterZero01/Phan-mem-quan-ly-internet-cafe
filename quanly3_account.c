#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quanly3.h"
// 1. ĐĂNG KÝ TÀI KHOẢN
void dangKy(KhachHang **head) { 
    char tenMoi[50];
    char matKhauMoi[50];

    printf("\033[H\033[J");
    printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
    printf("\n│                  DANG KY THANH VIEN                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTrang thai: \033[0;37m%-40.40s \033[1;36m│", "Dang cho nhap Tai khoan...");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[1;32m» Nhap ten tai khoan moi: \033[0m");
    scanf("%49s", tenMoi);

    KhachHang* current = *head;
    while (current != NULL) {
        if (strcmp(current->tenKhach, tenMoi) == 0) {
            printf("\n\033[1;31m[Loi] Tai khoan '%s' da ton tai tren he thong!\033[0m\n", tenMoi);
            return;
        }
        current = current->next;
    }

    printf("\033[H\033[J");
    printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
    printf("\n│                  DANG KY THANH VIEN                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTai khoan : \033[0;37m%-40.40s \033[1;36m│", tenMoi);
    printf("\n│ \033[0;33mTrang thai: \033[0;37m%-40.40s \033[1;36m│", "Dang cho nhap Mat khau...");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[1;32m» Nhap mat khau bao mat: \033[0m");
    scanf("%49s", matKhauMoi);

    printf("\033[H\033[J");
    printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
    printf("\n│                  DANG KY THANH VIEN                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTai khoan : \033[0;37m%-40.40s \033[1;36m│", tenMoi);
    printf("\n│ \033[0;33mMat khau  : \033[0;37m%-40.40s \033[1;36m│", matKhauMoi);
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");

    KhachHang* nodeMoi = (KhachHang*)malloc(sizeof(KhachHang));
    if (nodeMoi == NULL) {
        printf("\033[1;31m[Loi] Khong the cap phat bo nho RAM!\033[0m\n");
        return;
    }

    strcpy(nodeMoi->tenKhach, tenMoi);
    strcpy(nodeMoi->matKhau, matKhauMoi);
    nodeMoi->soMay = 0;
    nodeMoi->soDu = 0;
    nodeMoi->tienDichVu = 0;
    nodeMoi->tongThoiGian = 0;
    nodeMoi->capDoVIP = 0;
    nodeMoi->dangSuDung = 0;

    nodeMoi->next = *head;
    *head = nodeMoi;

    printf("\033[1;32m[Thanh cong] Chuc mung '%s' da tro thanh hoi vien!\033[0m\n", tenMoi);

}
// 2. ĐĂNG NHẬP THÀNH VIÊN
KhachHang* dangNhap(KhachHang *head) { 
    char tenDN[50];
    char mkDN[50];

    printf("\033[H\033[J");
    printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
    printf("\n│                  DANG NHAP HE THONG                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTrang thai: \033[0;37m%-40.40s \033[1;36m│", "Dang cho nhap Tai khoan...");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[1;32m» Ten tai khoan: \033[0m");
    scanf("%49s", tenDN);

    KhachHang* current = head;
    KhachHang* found = NULL;
    while (current != NULL) {
        if (strcmp(current->tenKhach, tenDN) == 0) {
            found = current;
            break;
        }
        current = current->next;
    }

    if (found == NULL) {
        printf("\033[H\033[J");
        printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
        printf("\n│                  DANG NHAP HE THONG                  │");
        printf("\n├──────────────────────────────────────────────────────┤");
        printf("\n│ \033[0;33mTai khoan : \033[0;31m%-40.40s \033[1;36m│", tenDN);
        printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
        printf("\033[1;31m[Loi] Tai khoan '%s' khong ton tai!\033[0m\n", tenDN);
        return NULL;
    }

    printf("\033[H\033[J");
    printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
    printf("\n│                  DANG NHAP HE THONG                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTai khoan : \033[0;37m%-40.40s \033[1;36m│", tenDN);
    printf("\n│ \033[0;33mTrang thai: \033[0;37m%-40.40s \033[1;36m│", "Dang cho nhap Mat khau...");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");
    printf("\033[1;32m» Mat khau: \033[0m");
    scanf("%49s", mkDN);

    printf("\033[H\033[J");
    printf("\n\033[1;36m┌──────────────────────────────────────────────────────┐");
    printf("\n│                  DANG NHAP HE THONG                  │");
    printf("\n├──────────────────────────────────────────────────────┤");
    printf("\n│ \033[0;33mTai khoan : \033[0;37m%-40.40s \033[1;36m│", tenDN);
    printf("\n│ \033[0;33mMat khau  : \033[0;37m%-40.40s \033[1;36m│", "********");
    printf("\n└──────────────────────────────────────────────────────┘\033[0m\n");

    if (strcmp(found->matKhau, mkDN) == 0) {
        printf("\033[1;32m[Thanh cong] Dang nhap thanh cong! Xin chao %s.\033[0m\n", tenDN);
        return found;
    }
    else {
        printf("\033[1;31m[Loi] Sai mat khau bao mat!\033[0m\n");
        return NULL;
    }
    
}
// 3. GHI DỮ LIỆU
void luuDuLieu(KhachHang *head) { 
    FILE* f = fopen("database.txt", "w");
    if (f == NULL) {
        printf("\n\033[1;31m[Loi] Khong the luu file du lieu!\033[0m\n");
        return;
    }

    KhachHang* current = head;
    while (current != NULL) {
        fprintf(f, "%s %s %d %.0f %.0f %.0f %d %ld %d\n",
            current->tenKhach, current->matKhau, current->soMay, current->soDu,
            current->tienDichVu, current->tongThoiGian, current->capDoVIP,
            current->gioBatDau, current->dangSuDung);
        current = current->next;
    }
    fclose(f);
    printf("\n\033[1;32m[Backup] Dong bo du lieu vao database.txt thanh cong!\033[0m\n");
}

// 4. ĐỌC DỮ LIỆU
void taiDuLieu(KhachHang **head) { 
    FILE* f = fopen("database.txt", "r");
    if (f == NULL) {
        return;
    }

    char ten[50], mk[50];
    int may, vip, dung;
    float du, dichVu;
    double tongTg;
    time_t gio;

    while (fscanf(f, "%s %s %d %f %f %lf %d %ld %d", ten, mk, &may, &du, &dichVu, &tongTg, &vip, &gio, &dung) == 9) {
        KhachHang* nodeMoi = (KhachHang*)malloc(sizeof(KhachHang));
        strcpy(nodeMoi->tenKhach, ten);
        strcpy(nodeMoi->matKhau, mk);
        nodeMoi->soMay = may;
        nodeMoi->soDu = du;
        nodeMoi->tienDichVu = dichVu;
        nodeMoi->tongThoiGian = tongTg;
        nodeMoi->capDoVIP = vip;
        nodeMoi->gioBatDau = gio;
        nodeMoi->dangSuDung = dung;

        nodeMoi->next = *head;
        *head = nodeMoi;
    }
    fclose(f);
}
// 5. GIẢI PHÓNG RAM

void giaiPhongBoNho(KhachHang **head) { 
    KhachHang* current = *head;
    KhachHang* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
    printf("\033[1;32m[RAM] Da don sach bo nho vung dem.\033[0m\n");
}
// 6. ĐỆ QUY
int demSoLuongKhach(KhachHang *node) { 
    return (node == NULL) ? 0 : 1 + demSoLuongKhach(node->next); 
}