---------PHẦN MỀM QUẢN LÝ INTERNET CAFE----------
-Tổng quan: Đây là một phần mềm được thiết kế với mục đích là để dùng trong việc quản lý các tài khoản được đăng ký và sử dung trong internet cafe.


-Hướng dẫn cài đặt:
 + Bước 1: Cài trình biên dịch (MSVC, GCC, Clang,..) để chạy chương trình (Nếu đã cài có thể bỏ qua). Link hướng dẫn cài đặt trình biên dịch GCC qua Cygwin: https://www.youtube.com/watch?v=0rf_Ts2r33I
 + Bước 2: Sau khi có trình biên dịch, để chạy chương trình ta cần tải và đặt 4 file main.c, quanly_account.c, quanly_service.c, quanly.h vào cùng một folder trong một ổ đĩa ví dụ như: D:\code c.
 + Bước 3: Ta chạy Command prompt và đi tới thư mục chứa file chương trình đã tải, khi đã trong thư mục nhập lệnh: gcc main.c quanly.c -o tên file bạn muốn đặt
VÍ DỤ: gcc main.c quanly_account.c quanly_service.c -o app_quanly


-Cấu hình: Chương trình được viết bằng ngôn ngữ C, được kiểm tra kết quả với trình biên dịch gcc.
