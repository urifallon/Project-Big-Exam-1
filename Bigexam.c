//=========================== Nguyen Hoang Duong / 20212358 / DCCNTT12.10.8 ===========================

#include <stdio.h>
#include <string.h>


// Khai báo kiểu tự định nghĩa
struct sinhvien {
    long int msv; 
    float diemtcc, diemth, diemcsltc, diemtb;
    char hovaten[1000], gioitinh[1000], ngaysinh[1000], lop[1000], hocluc[1000];
};

// Nhap dữ liệu của sinh viên
void nhapmang(struct sinhvien sv[], int n){ 
    printf(" ==NHAP THONG TIN SINH VIEN== \n"); 
    for (int i = 0; i < n; i++)
    {
        printf("\nMa Sinh Vien: "); scanf("%ld",&sv[i].msv);
        printf("Ho Ten: "); fflush(stdin); gets(sv[i].hovaten);
        printf("Gioi Tinh: "); fflush(stdin); gets(sv[i].gioitinh);
        printf("Ngay Sinh: "); fflush(stdin); gets(sv[i].ngaysinh);
        printf("Lop: "); fflush(stdin); gets(sv[i].lop);
        printf("Diem toan cao cap: "); scanf("%f",&sv[i].diemtcc);
        printf("Diem triet: "); scanf("%f",&sv[i].diemth);
        printf("Diem lap trinh C: "); scanf("%f",&sv[i].diemcsltc);
    }
}

// Danh sách sinh viên
void list(struct sinhvien sv[], int n){ 
    
    // Tính trung bình điểm sinh viên
    for(int i=0; i < n; i++){
        sv[i].diemtb = (sv[i].diemtcc + sv[i].diemcsltc + sv[i].diemth)/3;
    }

    // Khai báo học lực
    char gioi[20] = "Gioi";
    char kha[20]  = "Kha";
    char tb[20]   = "Trung binh";
    char yeu[20]  = "Yeu";
    
    // Xếp loại học lực
    for(int i=0; i < n; i++){
        if(sv[i].diemtb >= 8) strcpy(sv[i].hocluc,gioi);
        if(sv[i].diemtb >= 6.5 && sv[i].diemtb < 8) strcpy(sv[i].hocluc,kha);
        if(sv[i].diemtb >= 5 && sv[i].diemtb < 6.5) strcpy(sv[i].hocluc,tb);
        if(sv[i].diemtb <5) strcpy(sv[i].hocluc,yeu);
    }
    
    // Xuất tiêu đề bảng
    printf(" ==XUAT DANH SACH SINH VIEN==");
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s| %-25s| %-11s| %-15s| %-17s| %-15s|\n","Masv", "Ho ten", "Gioi tinh", "Ngay sinh","Diem trung binh", "Xep loai");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    
    // Xuất nội dung bảng
    for (int i = 0; i < n; i++){
        printf("| %-15ld| %-25s| %-11s| %-15s| %-17.2f| %-15s|\n",
        sv[i].msv,sv[i].hovaten,sv[i].gioitinh,sv[i].ngaysinh,sv[i].diemtb,sv[i].hocluc);
    }

    printf("---------------------------------------------------------------------------------------------------------------\n");
    

}

// Sắp xếp sinh vien theo điểm trung bình 
void sapxep(struct sinhvien sv[], int n){
    for(int i=0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(sv[i].diemtb < sv[j].diemtb){
                struct sinhvien swap = sv[i];
                sv[i] = sv[j];
                sv[j] = swap;
            }
        }
    }
    
    // Xuất tiêu đề bảng
    printf(" ==XUAT DANH SACH SINH VIEN==");
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s| %-25s| %-11s| %-15s| %-17s| %-15s|\n","Masv", "Ho ten", "Gioi tinh", "Ngay sinh","Diem trung binh", "Xep loai");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    
    // Xuất nội dung bảng đã sắp xếp
    for (int i = 0; i < n; i++){
        printf("| %-15ld| %-25s| %-11s| %-15s| %-17.2f| %-15s|\n",
        sv[i].msv,sv[i].hovaten,sv[i].gioitinh,sv[i].ngaysinh,sv[i].diemtb,sv[i].hocluc);
    }

    printf("---------------------------------------------------------------------------------------------------------------\n");

}

// Nhap file
void nhapfile(struct sinhvien sv[], int n){
    printf("Noi dung da duoc nhap vao: a-test.txt\n");

    // Khai báo con trỏ file + Mở file
    FILE * fptxt = fopen("a-test.txt=","w"); 
    
    // Ghi file 
    for(int i=0; i<n; i++){
        fprintf(fptxt ,"| %-15ld| %-25s| %-11s| %-15s| %-17.2f| %-15s|\n",
        sv[i].msv,sv[i].hovaten,sv[i].gioitinh,sv[i].ngaysinh,sv[i].diemtb,sv[i].hocluc);
    }
 
    // Đóng file
    fclose(fptxt);
}

// xuat file
void xuatfile(struct sinhvien sv[], int n){

    // Khai báo con trỏ file + Mở file
    FILE * fptxt = fopen("a-test.txt","r"); 

    // Xuất file
    for(int i=0; i<n; i++){
        fscanf(fptxt ," %15d %25s %11s %15s %17f %15s",
        &sv[i].msv,sv[i].hovaten,sv[i].gioitinh,sv[i].ngaysinh,&sv[i].diemtb,sv[i].hocluc);
    }
    for(int i=0; i < n; i++){
        printf("| %-15ld| %-25s| %-11s| %-15s| %-17.2f| %-15s|\n",
        sv[i].msv,sv[i].hovaten,sv[i].gioitinh,sv[i].ngaysinh,sv[i].diemtb,sv[i].hocluc);
    }

    // Đóng file
    fclose(fptxt);
}

int main(){
    int n; printf("Nhap so luong sinh vien : "); scanf("%d",&n); struct sinhvien sv[n];
    int chon; 
    
    do
    {
        printf("\nMENU QUAN LY SINH VIEN KHOA CONG NGHE THONG TIN");
        printf("\n================================================================");
        printf("\n1. NHAP THONG TIN SINH VIEN");
        printf("\n2. XUAT DANH SACH SINH VIEN");
        printf("\n3. TINH DIEM TRUNG BINH SINH VIEN");
        printf("\n4. SAP XEP SINH VIEN THEO THU TU TANG DAN CUA DIEM TRUNG BINH");
        printf("\n5. XEP LOAI SINH VIEN");
        printf("\n6. NHAP, XUAT DU LIEU SINH VIEN THEO FILE");
        printf("\n\n0. DE THOAT");
        printf("\n================================================================");

        printf("\n"); printf("Moi ban chon: "); scanf("%d", &chon);

        switch(chon) {
            case 1: nhapmang(sv,n); break;
            case 2: list(sv,n); break; 
            case 4: sapxep(sv,n); break;
            case 6: nhapfile(sv,n); xuatfile(sv,n); break;
        }
    } while (chon !=0 );
}
