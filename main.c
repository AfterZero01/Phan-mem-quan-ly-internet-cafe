#include "quanly.h"

int main() {
    TaiKhoan *dsTaiKhoan = docFile(); //Tự động tải dữ liệu//
    int luaChon;

    do {
        //Menu thao tác//
        printf("\n--- Phan mem quan ly internet cafe ---\n");
        printf("1 Dang ky tai khoan\n2 Tim kiem tai khoan\n3 Xoa tai khoan\n4 Sap xep theo so du\n5 Danh sach tai khoan\n6 Sua thong tin tai khoan\n7 Thoat va Luu\n");
        printf("Lua chon: ");
        
        //Xử lý lỗi nhập dữ liệu//
        if(scanf("%d", &luaChon) != 1) {
            printf("Loi, vui long nhap so!\n");
            while(getchar() != '\n'); //Xóa bộ nhớ đệm//
            continue;
        }
        //Thêm các chức năng//
        switch(luaChon) {
            case 1: themTaiKhoan(&dsTaiKhoan); break;
            case 2: timKiemTaiKhoan(dsTaiKhoan); break;
            case 3: {
                char ten[30];
                printf("Nhap ten tai khoan muon xoa: ");
                scanf("%s", ten);
                xoaTaiKhoan(&dsTaiKhoan, ten);
                break;
            }
            case 4: sapXepTaiKhoan(&dsTaiKhoan); break;
            case 5: hienThiDanhSachTaiKhoan(dsTaiKhoan); break;
            case 6: suaTaiKhoan(dsTaiKhoan); break;
            case 7: 
                luuFile(dsTaiKhoan); 
                giaiPhongBoNho(dsTaiKhoan);
                printf("Da luu va thoat chuong trinh.\n");
                break;
        }
    } while(luaChon != 7);

    return 0;
}