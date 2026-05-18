#include "quanly.h"

//Hàm trả về giá trị (Tạo node mới)//
TaiKhoan* taoNutMoi(char* ten, char* mk, long long du) {
    TaiKhoan *moi = (TaiKhoan*)malloc(sizeof(TaiKhoan));
    CHECK_MEMORY(moi);
    strcpy(moi->tenDN, ten);
    strcpy(moi->matKhau, mk);
    moi->soDu = du;
    moi->next = NULL;
    return moi;
}

//Hàm dùng tham biến//
void themTaiKhoan(TaiKhoan **head) {
    char ten[30], mk[20];
    long long du;
    printf("Nhap ten DN: "); scanf("%s", ten);
    printf("Nhap mat khau: "); scanf("%s", mk);
    printf("Nap tien ban dau: "); scanf("%lld", &du);

    TaiKhoan *moi = taoNutMoi(ten, mk, du);
    moi->next = *head;
    *head = moi;
    printf("Da them thanh cong!\n");
}
//Xóa tài khoản theo tên đăng nhập//
void xoaTaiKhoan(TaiKhoan **head, char *tenDN) {
    if (*head == NULL) {
        printf("Danh sach tai khoan trong!\n");
        return;
    }

    TaiKhoan *tam = *head;
    TaiKhoan *truoc = NULL;

    //TH1: Tài khoản xóa nằm ở vị trí đầu//
    if (tam != NULL && strcmp(tam->tenDN, tenDN) == 0) {
        *head = tam->next; //Cho head trỏ đến node tiếp theo//
        free(tam);         //Giải phóng bộ nhớ của node đầu//
        printf("Da xoa tai khoan %s thanh cong!\n", tenDN);
        return;
    }

    //TH2: Tìm tài khoản ở các vị trí tiếp theo//
    while (tam != NULL && strcmp(tam->tenDN, tenDN) != 0) {
        truoc = tam;
        tam = tam->next;
    }

    //TH3: Không tìm thấy tài khoản cần xóa//
    if (tam == NULL) {
        printf("Khong tim thay tai khoan %s de xoa!\n", tenDN);
        return;
    }

    //TH4: Tài khoản cần xóa nằm ở vị trí giữa hoặc cuối//
    truoc->next = tam->next;
    free(tam);
    printf("Da xoa tai khoan %s thanh cong!\n", tenDN);
}

//Tìm kiếm tài khoản//
void timKiemTaiKhoan(TaiKhoan *head) {
    char ten[30];
    printf("Nhap ten can tim: "); scanf("%s", ten);
    TaiKhoan *curr = head;
    while(curr) {
        if(strcmp(curr->tenDN, ten) == 0) {
            printf("Tim thay! So du: %lld VND\n", curr->soDu);
            return;
        }
        curr = curr->next;
    }
    printf("Khong tim thay!\n");
}

//Sắp xếp danh sách theo số dư giảm dần//
void sapXepTaiKhoan(TaiKhoan **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    for (TaiKhoan *i = *head; i->next != NULL; i = i->next) {
        for (TaiKhoan *j = i->next; j != NULL; j = j->next) {
            if (i->soDu < j->soDu) { //Sắp xếp giảm dần//
                //Lưu tạm dữ liệu của nút i (không lưu con trỏ next)//
                char tempTen[30]; strcpy(tempTen, i->tenDN);
                char tempMK[20];  strcpy(tempMK, i->matKhau);
                long long tempDu = i->soDu;

                //Gán dữ liệu từ j sang i//
                strcpy(i->tenDN, j->tenDN);
                strcpy(i->matKhau, j->matKhau);
                i->soDu = j->soDu;

                //Gán dữ liệu tạm vào j//
                strcpy(j->tenDN, tempTen);
                strcpy(j->matKhau, tempMK);
                j->soDu = tempDu;
            }
        }
    }
    printf("Da sap xep tai khoan theo so du giam dan.\n");
}
void hienThiDanhSachTaiKhoan(TaiKhoan *head) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
    printf("\n--- DANH SACH TAI KHOAN ---\n");
    printf("%-20s | %-15s\n", "Ten Dang Nhap", "So Du");
    printf("-----------------------------------\n");
    TaiKhoan *curr = head;
    while (curr != NULL) {
        printf("%-20s | %-15lld VND\n", curr->tenDN, curr->soDu);
        curr = curr->next;
    }
}
//Sửa thông tin tài khoản//
void suaTaiKhoan(TaiKhoan *head) {
    char tenCu[30];
    printf("Nhap ten tai khoan muon sua: ");
    scanf("%s", tenCu);

    TaiKhoan *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->tenDN, tenCu) == 0) {
            printf("Tim thay tai khoan!\n");
            printf("Nhap ten moi: ");
            scanf("%s", curr->tenDN);
            printf("Nhap mat khau moi: ");
            scanf("%s", curr->matKhau);
            
            printf("Cap nhat thong tin thanh cong!\n");
            return;
        }
        curr = curr->next;
    }
    printf("Khong tim thay tai khoan %s!\n", tenCu);
}
//Thao tác tệp tin//
void luuFile(TaiKhoan *head) {
    FILE *f = fopen(FILE_DATA, "wb");
    if(!f) return;
    TaiKhoan *curr = head;
    while(curr) {
        fwrite(curr, sizeof(TaiKhoan) - sizeof(struct TaiKhoan*), 1, f);
        curr = curr->next;
    }
    fclose(f);
}

//Tự động tải dữ liệu khi khởi động//
TaiKhoan* docFile() {
    FILE *f = fopen(FILE_DATA, "rb");
    if(!f) return NULL;
    TaiKhoan *head = NULL, *tam = NULL;
    TaiKhoan doc;
    while(fread(&doc, sizeof(TaiKhoan) - sizeof(struct TaiKhoan*), 1, f)) {
        TaiKhoan *moi = taoNutMoi(doc.tenDN, doc.matKhau, doc.soDu);
        if(!head) head = moi;
        else tam->next = moi;
        tam = moi;
    }
    fclose(f);
    return head;
}

//Hàm đệ quy giải phóng bộ nhớ//
void giaiPhongBoNho(TaiKhoan *head) {
    if (head == NULL) return;
    giaiPhongBoNho(head->next);
    free(head);
}