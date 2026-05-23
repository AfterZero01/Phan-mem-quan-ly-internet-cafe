# Phan-mem-quan-ly-internet-cafe
## Tổng quan
Đây là một phần mềm được thiết kế với mục đích là để dùng trong việc quản lý các tài khoản được đăng ký và sử dụng trong internet cafe.

## Cấu hình
* **Ngôn ngữ:** C
* **Trình biên dịch:** gcc

## Hướng dẫn cài đặt và chạy chương trình

### Bước 1: Cài đặt trình biên dịch
Bạn cần cài trình biên dịch (MSVC, GCC, Clang,...) để chạy chương trình.
* Hướng dẫn cài đặt GCC qua Cygwin: [Xem tại đây](https://www.youtube.com/watch?v=0rf_Ts2r33I)

### Bước 2: Chuẩn bị file
Tải và đặt 4 file `main3.c`, `quanly3_account.c`,`quanly3_service.c` `quanly3.h` vào cùng một thư mục (ví dụ: `D:\code c`).

### Bước 3: Biên dịch và thực thi
1. Mở **Command Prompt** và di chuyển tới thư mục chứa file chương trình.(ví dụ: cd "D:\code c" ).
2. Nhập lệnh sau để biên dịch:
```bash
gcc main3.c quanly3_account.c quanly3_service.c -o app_quanly
