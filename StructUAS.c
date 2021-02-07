#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Tanggungan {
    int jumlah;
};

struct KeluargaDihubungi {
    char Nama[255];
    char NoTelp[255];
    char Hubungan[255];
};

struct DataPribadi {
    char NamaDepan[255];
    char NamaBelakang[255];
    char Alamat[255];
    char Telp[255];
    char TempatL[255];
    int TanggalL;
    char BulanL[255];
    int TahunL;
    int Status;
    struct KeluargaDihubungi Keluarga;
    struct Tanggungan infoT;
};

struct Jakarta {
    struct DataPribadi Data[100];
};

struct Bandung {
    struct DataPribadi Data[100];
};

struct Semarang {
    struct DataPribadi Data[100];
};

struct ABC {
    struct Jakarta J;
    struct Bandung B;
    struct Semarang S;
};

struct Hapus {
    char line[1000];
    char namaD[255];
    char namaB[255];
};

void pendaftaran();
void addjkt();
void addbdg();
void addsmr();
void updatedata();
void updatedatajkt();
void updatedatabdg();
void updatedatasmr();
void menampilkanKeluargaDarurat();
void MenampilkanKaryawanTahunTertentu();
void hapusdata();
void hapuskaryawanjkt();
void hapuskaryawanbdg();
void hapuskaryawansmr();

int main() {
    struct ABC info;
    puts("Pilih Menu");
    printf("1. Pendaftaran Karyawan Perusahaan ABC\n2. Lihat Karyawan Perusahaan ABC Tahun Tertentu\n3. Update Data Karyawan\n4. Hapus Karyawan\n5. Hubungi Darurat Orang Terdekat Karyawan\n>>");
    int option;
    scanf("%d", &option);
    if(option < 1 || option > 5) {
        getchar();
    }
    switch(option) {
        case 1:
            pendaftaran();
            break;
        case 2:
            MenampilkanKaryawanTahunTertentu();
            break;
        case 3:
            updatedata();
            break;
        case 4:
            hapusdata();
            break;
        case 5:
            menampilkanKeluargaDarurat();
            break;
    }
}

void pendaftaran() {
    
    printf("Pilih lokasi karyawan\n1. Jakarta\n2. Bandung\n3. Semarang");
    int option;
    scanf("%d", &option);
    if(option < 1 || option > 3) {
        getchar();
    }
    switch(option) {
        case 1:
            addjkt();
            break;
        case 2:
            addbdg();
            break;
        case 3:
            addsmr();
            break;
    }
}

void addjkt() {
    struct ABC info;
    FILE *file;
    file = fopen("karyawanjkt.txt", "a+");
    int j = 0;
    char valid;
    do {
        puts("Masukan Data Diri Karyawan");
        printf("Nama Depan : "); scanf("%s", &info.J.Data[j].NamaDepan);
        printf("Nama Belakang : "); scanf("%s", &info.J.Data[j].NamaBelakang);
        printf("Alamat : "); scanf(" %[^\n]", &info.J.Data[j].Alamat);
        printf("No. Telepon : "); scanf("%s", &info.J.Data[j].Telp);
        printf("Tempat Lahir : "); scanf("%s", &info.J.Data[j].TempatL);
        printf("Tahun Lahir : "); scanf("%d", &info.J.Data[j].TahunL);
        printf("Bulan Lahir : "); scanf("%s", &info.J.Data[j].BulanL);
        printf("Tanggal Lahir : "); scanf("%d", &info.J.Data[j].TanggalL);
        printf("Status\n1. Single\n2. Berkeluarga\n>>"); scanf("%d", &info.J.Data[j].Status);
        if(info.J.Data[j].Status == 2) {
            printf("Tanggungan Keluarga : "); scanf("%d", &info.J.Data[j].infoT.jumlah);
        } else {
            info.J.Data[j].infoT.jumlah = 0;
        }
        puts("Keluarga yang bisa dihubungi Daruurat"); 
        printf("Nama :"); scanf(" %[^\n]", &info.J.Data[j].Keluarga.Nama);
        printf("Hubungan dengan Karyawan : "); scanf("%s", &info.J.Data[j].Keluarga.Hubungan);
        printf("No. Telepon : "); scanf("%s", &info.J.Data[j].Keluarga.NoTelp);
        fprintf(file,"%s#%s#%s#%s#%s#%d#%s#%d#%d#%s#%s#%s\n",info.J.Data[j].NamaDepan,
                                                             info.J.Data[j].NamaBelakang,
                                                             info.J.Data[j].Alamat,
                                                             info.J.Data[j].Telp,
                                                             info.J.Data[j].TempatL,
                                                             info.J.Data[j].TahunL,
                                                             info.J.Data[j].BulanL,
                                                             info.J.Data[j].TanggalL,
                                                             info.J.Data[j].infoT.jumlah,
                                                             info.J.Data[j].Keluarga.Nama,
                                                             info.J.Data[j].Keluarga.Hubungan,
                                                             info.J.Data[j].Keluarga.NoTelp);
        j++;
        system("cls");
        scanf(" %c", &valid);
    } while(valid == 'y' || valid == 'Y');
    fclose(file);
    main();
}

void addbdg() {
    struct ABC info;
    FILE *file;
    file = fopen("karyawanbdg.txt", "a+");
    int b = 0;
    char valid;
    do {
        puts("Masukan Data Diri Karyawan");
        printf("Nama Depan : "); scanf("%s", &info.B.Data[b].NamaDepan);
        printf("Nama Belakang : "); scanf("%s", &info.B.Data[b].NamaBelakang);
        printf("Alamat : "); scanf(" %[^\n]", &info.B.Data[b].Alamat);
        printf("No. Telepon : "); scanf("%s", &info.B.Data[b].Telp);
        printf("Tempat Lahir : "); scanf("%s", &info.B.Data[b].TempatL);
        printf("Tahun Lahir : "); scanf("%d", &info.B.Data[b].TahunL);
        printf("Bulan Lahir : "); scanf("%s", &info.B.Data[b].BulanL);
        printf("Tanggal Lahir : "); scanf("%d", &info.B.Data[b].TanggalL);
        printf("Status\n1. Single\n2. Berkeluarga\n>>"); scanf("%d", &info.B.Data[b].Status);
        if(info.B.Data[b].Status == 2) {
            printf("Tanggungan Keluarga : "); scanf("%d", &info.B.Data[b].infoT.jumlah);
        } else {
            info.B.Data[b].infoT.jumlah = 0;
        }
        puts("Keluarga yang bisa dihubungi Daruurat"); 
        printf("Nama :"); scanf(" %[^\n]", &info.B.Data[b].Keluarga.Nama);
        printf("Hubungan dengan Karyawan : "); scanf("%s", &info.B.Data[b].Keluarga.Hubungan);
        printf("No. Telepon : "); scanf("%s", &info.B.Data[b].Keluarga.NoTelp);
        fprintf(file,"%s#%s#%s#%s#%s#%d#%s#%d#%d#%s#%s#%s\n",info.B.Data[b].NamaDepan,
                                                            info.B.Data[b].NamaBelakang,
                                                            info.B.Data[b].Alamat,
                                                            info.B.Data[b].Telp,
                                                            info.B.Data[b].TempatL,
                                                            info.B.Data[b].TahunL,
                                                            info.B.Data[b].BulanL,
                                                            info.B.Data[b].TanggalL,
                                                            info.B.Data[b].infoT.jumlah,
                                                            info.B.Data[b].Keluarga.Nama,
                                                            info.B.Data[b].Keluarga.Hubungan,
                                                            info.B.Data[b].Keluarga.NoTelp);
        b++;
        system("cls");
        scanf(" %c", &valid);
    } while(valid == 'y' || valid == 'Y');
    fclose(file);
    main();
}

void addsmr() {
    struct ABC info;
    FILE *file;
    file = fopen("karyawansmr.txt", "a+");
    int s = 0;
    char valid;
    do {
        puts("Masukan Data Diri Karyawan");
        printf("Nama Depan : "); scanf("%s", &info.S.Data[s].NamaDepan);
        printf("Nama Belakang : "); scanf("%s", &info.S.Data[s].NamaBelakang);
        printf("Alamat : "); scanf(" %[^\n]", &info.S.Data[s].Alamat);
        printf("No. Telepon : "); scanf("%s", &info.S.Data[s].Telp);
        printf("Tempat Lahir : "); scanf("%s", &info.S.Data[s].TempatL);
        printf("Tahun Lahir : "); scanf("%d", &info.S.Data[s].TahunL);
        printf("Bulan Lahir : "); scanf("%s", &info.S.Data[s].BulanL);
        printf("Tanggal Lahir : "); scanf("%d", &info.S.Data[s].TanggalL);
        printf("Status\n1. Single\n2. Berkeluarga\n>>"); scanf("%d", &info.S.Data[s].Status);
        if(info.S.Data[s].Status == 2) {
            printf("Tanggungan Keluarga : "); scanf("%d", &info.S.Data[s].infoT.jumlah);
        } else {
            info.S.Data[s].infoT.jumlah = 0;
        }
        puts("Keluarga yang bisa dihubungi Daruurat"); 
        printf("Nama :"); scanf(" %[^\n]", &info.S.Data[s].Keluarga.Nama);
        printf("Hubungan dengan Karyawan : "); scanf("%s", &info.S.Data[s].Keluarga.Hubungan);
        printf("No. Telepon : "); scanf("%s", &info.S.Data[s].Keluarga.NoTelp);
        fprintf(file,"%s#%s#%s#%s#%s#%d#%s#%d#%d#%s#%s#%s\n",info.S.Data[s].NamaDepan,
                                                             info.S.Data[s].NamaBelakang,
                                                             info.S.Data[s].Alamat,
                                                             info.S.Data[s].Telp,
                                                             info.S.Data[s].TempatL,
                                                             info.S.Data[s].TahunL,
                                                             info.S.Data[s].BulanL,
                                                             info.S.Data[s].TanggalL,
                                                             info.S.Data[s].infoT.jumlah,
                                                             info.S.Data[s].Keluarga.Nama,
                                                             info.S.Data[s].Keluarga.Hubungan,
                                                             info.S.Data[s].Keluarga.NoTelp);
        s++;
        system("cls");
        scanf(" %c", &valid);
    } while(valid == 'y' || valid == 'Y');
    fclose(file);
    main();
}

void updatedata() {
    puts("Pilih mau update karyawan cabang");
    printf("1. Jakarta\n2. Bandung\n3. Semarang\n");
    int option;
    scanf("%d", &option);
    if(option < 1 || option > 3) {
        getchar();
    }
    switch(option) {
        case 1:
            updatedatajkt();
            break;
        case 2:
            updatedatabdg();
            break;
        case 3:
            updatedatasmr();
            break;
    }
}

void updatedatajkt() {
    FILE *file;
    file = fopen("karyawanjkt.txt","r");
    struct ABC info;
    int j=0,i;
    while(!feof(file)) {
        fscanf(file,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.J.Data[j].NamaDepan,
                                                                                    &info.J.Data[j].NamaBelakang,
                                                                                    &info.J.Data[j].Alamat,
                                                                                    &info.J.Data[j].Telp,
                                                                                    &info.J.Data[j].TempatL,
                                                                                    &info.J.Data[j].TahunL,
                                                                                    &info.J.Data[j].BulanL,
                                                                                    &info.J.Data[j].TanggalL,
                                                                                    &info.J.Data[j].infoT.jumlah,
                                                                                    &info.J.Data[j].Keluarga.Nama,
                                                                                    &info.J.Data[j].Keluarga.Hubungan,
                                                                                    &info.J.Data[j].Keluarga.NoTelp);
        j++;
    }
    fclose(file);
    file = fopen("karyawanjkt.txt","w+");
    char namaD[255],namaB[255];
    printf("Pilih nama yang ingin diupdate alamatnya : "); scanf("%s %s", namaD, namaB);
    int index,flag = 0;
    for(i=0; i<j; i++) {
        if(strcmp(namaD,info.J.Data[i].NamaDepan)==0 && strcmp(namaB,info.J.Data[i].NamaBelakang)==0) {
            index = i;
            flag = 1;
            break; 
        }
    }
    char alamat[255];
    if(flag) {
        printf("Rubah update alamat karyawan : "); scanf(" %[^\n]", alamat);
        strcpy(info.J.Data[index].Alamat, alamat);
        for(i=0; i<j; i++) {
            fprintf(file,"%s#%s#%s#%s#%s#%d#%s#%d#%d#%s#%s#%s\n",info.J.Data[i].NamaDepan,
                                                             info.J.Data[i].NamaBelakang,
                                                             info.J.Data[i].Alamat,
                                                             info.J.Data[i].Telp,
                                                             info.J.Data[i].TempatL,
                                                             info.J.Data[i].TahunL,
                                                             info.J.Data[i].BulanL,
                                                             info.J.Data[i].TanggalL,
                                                             info.J.Data[i].infoT.jumlah,
                                                             info.J.Data[i].Keluarga.Nama,
                                                             info.J.Data[i].Keluarga.Hubungan,
                                                             info.J.Data[i].Keluarga.NoTelp);
        }
    }
    fclose(file);
    system("cls");
    main();
}

void updatedatabdg() {
    FILE *file;
    file = fopen("karyawanbdg.txt","r");
    struct ABC info;
    int b=0,i;
    while(!feof(file)) {
        fscanf(file,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.B.Data[b].NamaDepan,
                                                                                    &info.B.Data[b].NamaBelakang,
                                                                                    &info.B.Data[b].Alamat,
                                                                                    &info.B.Data[b].Telp,
                                                                                    &info.B.Data[b].TempatL,
                                                                                    &info.B.Data[b].TahunL,
                                                                                    &info.B.Data[b].BulanL,
                                                                                    &info.B.Data[b].TanggalL,
                                                                                    &info.B.Data[b].infoT.jumlah,
                                                                                    &info.B.Data[b].Keluarga.Nama,
                                                                                    &info.B.Data[b].Keluarga.Hubungan,
                                                                                    &info.B.Data[b].Keluarga.NoTelp);
        b++;
    }
    fclose(file);
    file = fopen("karyawanjkt.txt","w+");
    char namaD[255],namaB[255];
    printf("Pilih nama yang ingin diupdate alamatnya : "); scanf("%s %s", namaD, namaB);
    int index,flag = 0;
    for(i=0; i<b; i++) {
        if(strcmp(namaD,info.B.Data[i].NamaDepan)==0 && strcmp(namaB,info.B.Data[i].NamaBelakang)==0) {
            index = i;
            flag = 1;
            break; 
        }
    }
    char alamat[255];
    if(flag) {
        printf("Rubah update alamat karyawan : "); scanf(" %[^\n]", alamat);
        strcpy(info.B.Data[index].Alamat, alamat);
        for(i=0; i<b; i++) {
            fprintf(file,"%s#%s#%s#%s#%s#%d#%s#%d#%d#%s#%s#%s\n",info.B.Data[i].NamaDepan,
                                                             info.B.Data[i].NamaBelakang,
                                                             info.B.Data[i].Alamat,
                                                             info.B.Data[i].Telp,
                                                             info.B.Data[i].TempatL,
                                                             info.B.Data[i].TahunL,
                                                             info.B.Data[i].BulanL,
                                                             info.B.Data[i].TanggalL,
                                                             info.B.Data[i].infoT.jumlah,
                                                             info.B.Data[i].Keluarga.Nama,
                                                             info.B.Data[i].Keluarga.Hubungan,
                                                             info.B.Data[i].Keluarga.NoTelp);
        }
    }
    fclose(file);
    system("cls");
    main();
}

void updatedatasmr() {
    FILE *file;
    file = fopen("karyawansmr.txt","r");
    struct ABC info;
    int s=0,i;
    while(!feof(file)) {
        fscanf(file,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.B.Data[s].NamaDepan,
                                                                                    &info.B.Data[s].NamaBelakang,
                                                                                    &info.B.Data[s].Alamat,
                                                                                    &info.B.Data[s].Telp,
                                                                                    &info.B.Data[s].TempatL,
                                                                                    &info.B.Data[s].TahunL,
                                                                                    &info.B.Data[s].BulanL,
                                                                                    &info.B.Data[s].TanggalL,
                                                                                    &info.B.Data[s].infoT.jumlah,
                                                                                    &info.B.Data[s].Keluarga.Nama,
                                                                                    &info.B.Data[s].Keluarga.Hubungan,
                                                                                    &info.B.Data[s].Keluarga.NoTelp);
        s++;
    }
    fclose(file);
    file = fopen("karyawanjkt.txt","w+");
    char namaD[255],namaB[255];
    printf("Pilih nama yang ingin diupdate alamatnya : "); scanf("%s %s", namaD, namaB);
    int index,flag = 0;
    for(i=0; i<s; i++) {
        if(strcmp(namaD,info.B.Data[i].NamaDepan)==0 && strcmp(namaB,info.B.Data[i].NamaBelakang)==0) {
            index = i;
            flag = 1;
            break; 
        }
    }
    char alamat[255];
    if(flag) {
        printf("Rubah update alamat karyawan : "); scanf(" %[^\n]", alamat);
        strcpy(info.B.Data[index].Alamat, alamat);
        for(i=0; i<s; i++) {
            fprintf(file,"%s#%s#%s#%s#%s#%d#%s#%d#%d#%s#%s#%s\n",info.B.Data[i].NamaDepan,
                                                             info.B.Data[i].NamaBelakang,
                                                             info.B.Data[i].Alamat,
                                                             info.B.Data[i].Telp,
                                                             info.B.Data[i].TempatL,
                                                             info.B.Data[i].TahunL,
                                                             info.B.Data[i].BulanL,
                                                             info.B.Data[i].TanggalL,
                                                             info.B.Data[i].infoT.jumlah,
                                                             info.B.Data[i].Keluarga.Nama,
                                                             info.B.Data[i].Keluarga.Hubungan,
                                                             info.B.Data[i].Keluarga.NoTelp);
        }
    }
    fclose(file);
    system("cls");
    main();
}

void menampilkanKeluargaDarurat() {
    FILE *fj,*fb,*fs;
    fj = fopen("karyawanjkt.txt", "r");
    fb = fopen("karyawanbdg.txt", "r");
    fs = fopen("karyawansmr.txt", "r");
    int j = 0;
    struct ABC info;
    while(!feof(fj)) {
        fscanf(fj,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.J.Data[j].NamaDepan,
                                                                                    &info.J.Data[j].NamaBelakang,
                                                                                    &info.J.Data[j].Alamat,
                                                                                    &info.J.Data[j].Telp,
                                                                                    &info.J.Data[j].TempatL,
                                                                                    &info.J.Data[j].TahunL,
                                                                                    &info.J.Data[j].BulanL,
                                                                                    &info.J.Data[j].TanggalL,
                                                                                    &info.J.Data[j].infoT.jumlah,
                                                                                    &info.J.Data[j].Keluarga.Nama,
                                                                                    &info.J.Data[j].Keluarga.Hubungan,
                                                                                    &info.J.Data[j].Keluarga.NoTelp);
        j++;
    }
    int b = 0;
    while(!feof(fb)) {
        fscanf(fb,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.B.Data[b].NamaDepan,
                                                                                    &info.B.Data[b].NamaBelakang,
                                                                                    &info.B.Data[b].Alamat,
                                                                                    &info.B.Data[b].Telp,
                                                                                    &info.B.Data[b].TempatL,
                                                                                    &info.B.Data[b].TahunL,
                                                                                    &info.B.Data[b].BulanL,
                                                                                    &info.B.Data[b].TanggalL,
                                                                                    &info.B.Data[b].infoT.jumlah,
                                                                                    &info.B.Data[b].Keluarga.Nama,
                                                                                    &info.B.Data[b].Keluarga.Hubungan,
                                                                                    &info.B.Data[b].Keluarga.NoTelp);
        b++;
    }
    int s = 0;
    while(!feof(fs)) {
        fscanf(fs,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.B.Data[s].NamaDepan,
                                                                                    &info.B.Data[s].NamaBelakang,
                                                                                    &info.B.Data[s].Alamat,
                                                                                    &info.B.Data[s].Telp,
                                                                                    &info.B.Data[s].TempatL,
                                                                                    &info.B.Data[s].TahunL,
                                                                                    &info.B.Data[s].BulanL,
                                                                                    &info.B.Data[s].TanggalL,
                                                                                    &info.B.Data[s].infoT.jumlah,
                                                                                    &info.B.Data[s].Keluarga.Nama,
                                                                                    &info.B.Data[s].Keluarga.Hubungan,
                                                                                    &info.B.Data[s].Keluarga.NoTelp);
        s++;
    }
    int i;
    puts("Cabang Jakarta");
    for(i=0; i<j; i++) {
        printf(" %d. %s %s\n    %s\n     %s\n     %s\n", info.J.Data[i].NamaDepan,
                                                         info.J.Data[i].NamaBelakang,
                                                         info.J.Data[i].Keluarga.Nama, 
                                                         info.J.Data[i].Keluarga.Hubungan,
                                                         info.J.Data[i].Keluarga.NoTelp);
    }
    puts("Cabang Bandung");
    for(i=0; i<b; i++) {
        printf(" %d. %s %s\n    %s\n     %s\n     %s\n", info.B.Data[i].NamaDepan,info.B.Data[i].NamaBelakang,
                                                         info.B.Data[i].Keluarga.Nama, info.B.Data[i].Keluarga.Hubungan,
                                                         info.B.Data[i].Keluarga.NoTelp);
    }
    puts("Cabang Semarang");
    for(i=0; i<s; i++) {
        printf(" %d. %s %s\n    %s\n     %s\n     %s\n", info.S.Data[i].NamaDepan,info.S.Data[i].NamaBelakang,
                                                         info.S.Data[i].Keluarga.Nama, info.S.Data[i].Keluarga.Hubungan,
                                                         info.S.Data[i].Keluarga.NoTelp);
    }
    system("pause");
    int option;
    printf("Tekan 1 untuk kembali ke menu"); scanf("%d", &option);
    system("cls");
    if(option == 1) {
        main();
    } else {
        exit(0);
    }
}

void MenampilkanKaryawanTahunTertentu (){
    FILE *fj,*fb,*fs;
    fj = fopen("karyawanjkt.txt", "r");
    fb = fopen("karyawanbdg.txt", "r");
    fs = fopen("karyawansmr.txt", "r");
    int j = 0;
    struct ABC info;
    while(!feof(fj)) {
        fscanf(fj,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.J.Data[j].NamaDepan,
                                                                                    &info.J.Data[j].NamaBelakang,
                                                                                    &info.J.Data[j].Alamat,
                                                                                    &info.J.Data[j].Telp,
                                                                                    &info.J.Data[j].TempatL,
                                                                                    &info.J.Data[j].TahunL,
                                                                                    &info.J.Data[j].BulanL,
                                                                                    &info.J.Data[j].TanggalL,
                                                                                    &info.J.Data[j].infoT.jumlah,
                                                                                    &info.J.Data[j].Keluarga.Nama,
                                                                                    &info.J.Data[j].Keluarga.Hubungan,
                                                                                    &info.J.Data[j].Keluarga.NoTelp);
        j++;
    }
    int b = 0;
    while(!feof(fb)) {
        fscanf(fb,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.B.Data[b].NamaDepan,
                                                                                    &info.B.Data[b].NamaBelakang,
                                                                                    &info.B.Data[b].Alamat,
                                                                                    &info.B.Data[b].Telp,
                                                                                    &info.B.Data[b].TempatL,
                                                                                    &info.B.Data[b].TahunL,
                                                                                    &info.B.Data[b].BulanL,
                                                                                    &info.B.Data[b].TanggalL,
                                                                                    &info.B.Data[b].infoT.jumlah,
                                                                                    &info.B.Data[b].Keluarga.Nama,
                                                                                    &info.B.Data[b].Keluarga.Hubungan,
                                                                                    &info.B.Data[b].Keluarga.NoTelp);
        b++;
    }
    int s = 0;
    while(!feof(fs)) {
        fscanf(fs,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%d#%[^#]#%[^#]#%[^\n]",&info.B.Data[s].NamaDepan,
                                                                                    &info.B.Data[s].NamaBelakang,
                                                                                    &info.B.Data[s].Alamat,
                                                                                    &info.B.Data[s].Telp,
                                                                                    &info.B.Data[s].TempatL,
                                                                                    &info.B.Data[s].TahunL,
                                                                                    &info.B.Data[s].BulanL,
                                                                                    &info.B.Data[s].TanggalL,
                                                                                    &info.B.Data[s].infoT.jumlah,
                                                                                    &info.B.Data[s].Keluarga.Nama,
                                                                                    &info.B.Data[s].Keluarga.Hubungan,
                                                                                    &info.B.Data[s].Keluarga.NoTelp);
        s++;
    }
    int tahun,i;
    printf("Masukan Tahun Lahir Karyawan : "); scanf("%d", &tahun);
    puts("Cabang Jakarta");
    for(i=0; i<j; i++) {
        if(tahun == info.J.Data[i].TahunL) {
            printf("-%s %s, %d %s,%d\n",info.J.Data[i].NamaDepan,info.J.Data[i].NamaBelakang,
                                      info.J.Data[i].TanggalL,info.J.Data[i].BulanL,
                                      info.J.Data[i].TahunL);
        }
    }
    puts("Cabang Bandung");
    for(i=0; i<b; i++) {
        if(tahun == info.B.Data[i].TahunL) {
            printf("-%s %s, %d %s,%d\n",info.B.Data[i].NamaDepan,info.B.Data[i].NamaBelakang,
                                      info.B.Data[i].TanggalL,info.B.Data[i].BulanL,
                                      info.B.Data[i].TahunL);
        }
    }
    for(i=0; i<s; i++) {
        if(tahun == info.S.Data[i].TahunL) {
            printf("-%s %s, %d %s,%d\n",info.S.Data[i].NamaDepan,info.S.Data[i].NamaBelakang,
                                      info.S.Data[i].TanggalL,info.S.Data[i].BulanL,
                                      info.S.Data[i].TahunL);
        }
    }
    int option;
    printf("Tekan 1 untuk kembali ke menu"); scanf("%d", &option);
    system("cls");
    if(option == 1) {
        main();
    } else {
        exit(0);
    }
}

void hapusdata() {
    printf("Pilih Cabang ABC yang karyawanya sudah tidak bekerja\n");
    printf("1. Jakarta\n2. Bandung\n3. Semarang\n");
    int option;
    scanf("%d", &option);
    switch(option) {
        case 1:
            hapuskaryawanjkt();
            break;
        case 2:
            hapuskaryawanbdg();
            break;
        case 3:
            hapuskaryawansmr();
            break;
    }
}

void hapuskaryawanjkt() {
    FILE *file;
    file = fopen("karyawanjkt.txt", "r");
    struct Hapus data[100];
    int n = 0;
    while(!feof(file)) {
         fscanf(file,"\n%[^\n]", data[n].line);
         char *token = strtok(data[n].line,"#");
         strcpy(data[n].namaD, token);
         token = strtok(NULL,"#");
         strcpy(data[n].namaB, token);
         n++;
    }
    fclose(file);
    char namaD[255], namaB[255];
    printf("Masukan Nama Karyawan Yang sudah tidak bekerja : "); scanf("%s %s", namaD, namaB);
    int i,index,flag = 0;
    for(i=0; i<n; i++) {
        if(strcmp(namaD, data[i].namaD)==0 && strcmp(namaB,data[i].namaB)==0) {
            file = fopen("karyawanjkt.txt", "w+");
            index = i;
            flag = 1;
            break;
        }
    }
    if(flag) {
        for(i = index; i<n; i++) {
           strcpy(data[i].line,data[i+1].line);
        }
        n--;
        for(i=0; i<n; i++) {
            fprintf(file,"%s\n", data[i].line);
        }
        fclose(file);
    } else {
        printf("Karyawan tidak ditemukan coba ulangi");
    }
    system("pause");
    main();
}

void hapuskaryawanbdg() {
    FILE *file;
    file = fopen("karyawanbdg.txt", "r");
    struct Hapus data[100];
    int n = 0;
    while(!feof(file)) {
         fscanf(file,"\n%[^\n]", data[n].line);
         char *token = strtok(data[n].line,"#");
         strcpy(data[n].namaD, token);
         token = strtok(NULL,"#");
         strcpy(data[n].namaB, token);
         n++;
    }
    fclose(file);
    char namaD[255], namaB[255];
    ulangi:
    printf("Masukan Nama Karyawan Yang sudah tidak bekerja : "); scanf("%s %s", namaD, namaB);
    int i,index,flag = 0;
    for(i=0; i<n; i++) {
        if(strcmp(namaD, data[i].namaD)==0 && strcmp(namaB,data[i].namaB)==0) {
            file = fopen("karyawanbdg.txt", "w+");
            index = i;
            flag = 1;
            break;
        }
    }
    if(flag) {
        for(i = index; i<n; i++) {
           strcpy(data[i].line,data[i+1].line);
        }
        n--;
        for(i=0; i<n; i++) {
            fprintf(file,"%s\n", data[i].line);
        }
        fclose(file);
    } else {
        printf("Karyawan tidak ditemukan coba ulangi");
        goto ulangi;
    }
    system("pause");
    main();
}

void hapuskaryawansmr() {
    FILE *file;
    file = fopen("karyawansmr.txt", "r");
    struct Hapus data[100];
    int n = 0;
    while(!feof(file)) {
         fscanf(file,"\n%[^\n]", data[n].line);
         char *token = strtok(data[n].line,"#");
         strcpy(data[n].namaD, token);
         token = strtok(NULL,"#");
         strcpy(data[n].namaB, token);
         n++;
    }
    fclose(file);
    char namaD[255], namaB[255];
    ulangi:
    printf("Masukan Nama Karyawan Yang sudah tidak bekerja : "); scanf("%s %s", namaD, namaB);
    int i,index,flag = 0;
    for(i=0; i<n; i++) {
        if(strcmp(namaD, data[i].namaD)==0 && strcmp(namaB,data[i].namaB)==0) {
            file = fopen("karyawansmr.txt", "w+");
            index = i;
            flag = 1;
            break;
        }
    }
    if(flag) {
        for(i = index; i<n; i++) {
           strcpy(data[i].line,data[i+1].line);
        }
        n--;
        for(i=0; i<n; i++) {
            fprintf(file,"%s\n", data[i].line);
        }
        fclose(file);
    } else {
        printf("Karyawan tidak ditemukan coba ulangi");
        goto ulangi;
    }
    system("pause");
    main();
}