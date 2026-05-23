#ifndef QUANLY3_H
#define QUANLY3_H
#include <time.h>
#include <stdlib.h>

typedef struct KhachHang {
    char tenKhach[50];
    char matKhau[50];     
    int soMay;
    float soDu;
    float tienDichVu;
    double tongThoiGian;
    int capDoVIP;
    time_t gioBatDau;
    int dangSuDung;
    
    struct KhachHang *next; 
} KhachHang;

void dangKy(KhachHang **head);
KhachHang* dangNhap(KhachHang *head);
void napTien(KhachHang *kh);
void kiemTraVIP(KhachHang *kh);
void batDauChoi(KhachHang *kh);
void goiMon(KhachHang *kh);
void thanhToan(KhachHang *kh);
void xemThongTin(KhachHang *kh);
void hienThiBangGia(); // BỔ SUNG HÀM QUẢNG CÁO

void luuDuLieu(KhachHang *head);
void taiDuLieu(KhachHang **head);
int demSoLuongKhach(KhachHang *node);
void giaiPhongBoNho(KhachHang **head);

#endif