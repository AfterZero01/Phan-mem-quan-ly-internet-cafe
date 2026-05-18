#ifndef QUANLY_H
#define QUANLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GIA_GIO_CHOI 10000
#define FILE_DATA "taikhoan.bin" 

//Macro kiểm tra lỗi cấp phát bộ nhớ//
#define CHECK_MEMORY(ptr) if(!ptr) { printf("Loi cap phat bo nho!\n"); exit(1); }

//Cấu trúc tài khoản (Sử dụng Danh sách liên kết đơn)//
typedef struct TaiKhoan {
    char tenDN[30];
    char matKhau[20];
    long long soDu;
    struct TaiKhoan *next;
} TaiKhoan;

//Các hàm chức năng//
void menu();
TaiKhoan* taoNutMoi(char* ten, char* mk, long long du);
void themTaiKhoan(TaiKhoan **head); //Dùng tham biến (con trỏ của con trỏ)//
void xoaTaiKhoan(TaiKhoan **head, char *tenDN); //Xóa tài khoản theo tên đăng nhập//
void timKiemTaiKhoan(TaiKhoan *head);
void hienThiDanhSachTaiKhoan(TaiKhoan *head);
void sapXepTaiKhoan(TaiKhoan **head); //Sắp xếp theo số dư//
void suaTaiKhoan(TaiKhoan *head);
void luuFile(TaiKhoan *head);
TaiKhoan* docFile();
void giaiPhongBoNho(TaiKhoan *head); //Đệ quy ở đây//

#endif