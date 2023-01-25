#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define panjang_nilai 50

struct motor
{
    char jumlah[panjang_nilai], jenis[panjang_nilai], plat[panjang_nilai], stnk[panjang_nilai], waktu[panjang_nilai];
};



void lihat_asc(){
    char dataMotor[500];
    FILE *fptr;
    fptr = fopen("data_motor.txt", "r");
    char *hasil;
    struct motor lihatMotor[100];
    int loop = 0;
    int loop7 = 0;
	int ind[loop7]; /*Untuk Menyimpan Index Sesuai Urutan plat, Yang Akan Digunakan Untuk Print*/
    while (fgets(dataMotor, sizeof(dataMotor), fptr))
    {
        int loop2 = 0;
    	int index[4];

    	hasil = strchr(dataMotor, '|');
    	while(hasil != NULL){
    	  	index[loop2] = hasil - dataMotor;
    	  	hasil = strchr(hasil+1, '|');
    	  	loop2++;
    	}

        for (int j = 0; j < index[0]; j++){
    	  	lihatMotor[loop].jenis[j] = dataMotor[j];
    	}
        for (int j = 0; j < index[1]-index[0]-1; j++){
    	  	lihatMotor[loop].plat[j] = dataMotor[j+index[0]+1];
    	}
    	for (int j = 0; j < index[2]-index[1]-1; j++){
    	  	lihatMotor[loop].stnk[j] = dataMotor[j+index[1]+1];
    	}
    	for (int j = 0; j < strlen(dataMotor)-index[2]-1; j++){
    	  	lihatMotor[loop].waktu[j] = dataMotor[j+index[2]+1];
    	}


		int sort = 0;
		while (strlen(lihatMotor[loop7].jenis) != 0){
		    loop7++;
		}

			int loop8;

			/*Sort plat Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			for (int a = 0; a < loop7; a++)/*Untuk Setiap Data Yang Ada*/
			{
				loop8 = 0;
				for (int i = 0; i < loop7; i++)/*Bandingkan Dengan Semua Data Yang Ada*/
				{
					for (int j = 0; j < sizeof(lihatMotor[i].plat); j++)/*Bandingkan Setiap Huruf Pada plat Dengan Data Lain*/
					{
						if (tolower(lihatMotor[a].plat[j]) > tolower(lihatMotor[i].plat[j]))
						{
							loop8++;/*Tambahkan Index Dan Kemudian Break Jika plat Lebih Besar*/
							break;
						}else if(tolower(lihatMotor[a].plat[j]) < tolower(lihatMotor[i].plat[j])){
							break;/*Break Jika plat Lebih Kecil*/
						}
					}

				}
				ind[loop8] = a;/*Masukkan Index Sekarang Kedalam Ind Yang Berindex Total Dari loop8*/
            }

        loop++;
    }
                for (int i = 0; i < loop7; i++)
				{
    	            printf("\n");
					printf("Jenis = %s", lihatMotor[ind[i]].jenis);
    	            printf("\n");
    	            printf("Plat = %s", lihatMotor[ind[i]].plat);
    	            printf("\n");
    	            printf("STNK = %s", lihatMotor[ind[i]].stnk);
    	            printf("\n");
    	            printf("Waktu = %s", lihatMotor[ind[i]].waktu);
    	            printf("\n");
				}

    fclose(fptr);
}
void lihat_desc(){
    char dataMotor[500];
    FILE *fptr;
    fptr = fopen("data_motor.txt", "r");
    char *hasil;
    struct motor lihatMotor[100];
    int loop = 0;
    int loop7 = 0;
	int ind[loop7]; /*Untuk Menyimpan Index Sesuai Urutan plat, Yang Akan Digunakan Untuk Print*/
    while (fgets(dataMotor, sizeof(dataMotor), fptr))
    {
        int loop2 = 0;
    	int index[4];

    	hasil = strchr(dataMotor, '|');
    	while(hasil != NULL){
    	  	index[loop2] = hasil - dataMotor;
    	  	hasil = strchr(hasil+1, '|');
    	  	loop2++;
    	}

        for (int j = 0; j < index[0]; j++){
    	  	lihatMotor[loop].jenis[j] = dataMotor[j];
    	}
        for (int j = 0; j < index[1]-index[0]-1; j++){
    	  	lihatMotor[loop].plat[j] = dataMotor[j+index[0]+1];
    	}
    	for (int j = 0; j < index[2]-index[1]-1; j++){
    	  	lihatMotor[loop].stnk[j] = dataMotor[j+index[1]+1];
    	}
    	for (int j = 0; j < strlen(dataMotor)-index[2]-1; j++){
    	  	lihatMotor[loop].waktu[j] = dataMotor[j+index[2]+1];
    	}


		int sort = 0;
		while (strlen(lihatMotor[loop7].jenis) != 0){
		    loop7++;
		}

			int loop8;

			/*Sort plat Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			for (int a = 0; a < loop7; a++)/*Untuk Setiap Data Yang Ada*/
			{
				loop8 = 0;
				for (int i = 0; i < loop7; i++)/*Bandingkan Dengan Semua Data Yang Ada*/
				{
					for (int j = 0; j < sizeof(lihatMotor[i].plat); j++)/*Bandingkan Setiap Huruf Pada plat Dengan Data Lain*/
					{
						if (tolower(lihatMotor[a].plat[j]) > tolower(lihatMotor[i].plat[j]))
						{
							loop8++;/*Tambahkan Index Dan Kemudian Break Jika plat Lebih Besar*/
							break;
						}else if(tolower(lihatMotor[a].plat[j]) < tolower(lihatMotor[i].plat[j])){
							break;/*Break Jika plat Lebih Kecil*/
						}
					}

				}
				ind[loop8] = a;/*Masukkan Index Sekarang Kedalam Ind Yang Berindex Total Dari loop8*/
            }

        loop++;
    }
                for (int i = loop7-1; i >= 0; i--)
				{
    	            printf("\n");
					printf("Jenis = %s", lihatMotor[ind[i]].jenis);
    	            printf("\n");
    	            printf("Plat = %s", lihatMotor[ind[i]].plat);
    	            printf("\n");
    	            printf("STNK = %s", lihatMotor[ind[i]].stnk);
    	            printf("\n");
    	            printf("Waktu = %s", lihatMotor[ind[i]].waktu);
    	            printf("\n");
				}

    fclose(fptr);
}
void tambah_motor(){
    FILE *fptr;
    struct motor tambahMotor;
    // printf("Masukkan jumlah : "); /* fflush(stdin);*/
    // scanf(" %[^\n]s", &jumlah);
    printf("Masukkan jenis : ");
    scanf(" %[^\n]s", &tambahMotor.jenis);
    printf("Masukkan plat : ");
    scanf(" %[^\n]s", &tambahMotor.plat);
    printf("Masukkan stnk : ");
    scanf(" %[^\n]s", &tambahMotor.stnk);
    printf("Masukkan waktu per jam: ");
    scanf(" %[^\n]s", &tambahMotor.waktu);

    fptr = fopen("data_motor.txt","a");
    fprintf(fptr, "%s|%s|%s|%s\n", tambahMotor.jenis, tambahMotor.plat, tambahMotor.stnk, tambahMotor.waktu );
    fclose(fptr);
}
void lihat_motor(){
    int pilih_option;
    printf("1. LIHAT ASCENDING\n");
    printf("2. LIHAT DESCENDING\n");
    scanf("%d", &pilih_option);

    switch(pilih_option) {
    case 1:
        lihat_asc();
    break;
    case 2:
        lihat_desc();
    default:
        printf("Maaf pilihan anda tidak tersedia\n");
    break;
    }
}
void hapus_motor(){
    int loop = 0;
  	int loop6 = 0;
  	char dataMotor[500];
  	char hapusData[50];
  	char *hasil;
  	struct motor hapusMotor[100];
  	FILE *fptr;
  	fptr = fopen("data_motor.txt", "r"); /*Buka File dataMotor.txt*/
  	printf("Masukkan Plat Yang Ingin Dihapus : ");
  	scanf("%s", hapusData);

  	memset(hapusMotor, 0, sizeof(hapusMotor));  /*Hapus Data Pada hapusMotor*/

  	while (fgets(dataMotor, sizeof(dataMotor), fptr)){  /*Untuk Setiap Baris Data Pada dataMotor.txt*/
  	  	int loop4 = 0;
  	  	int loop5 = 0;
  	  	int index3[3];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataMotor, '|');
  	  	while(hasil != NULL){
  	  	  	index3[loop4] = hasil - dataMotor;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop4++;
  	  	}
  	  	/*End Mencari Index Dari Char '|'*/

  	  	/*Seleksi PLAT Dengan Input User*/
  	  	for (int j = 0; j < index3[1] - index3[0] - 1; j++){
  	  	  	if (dataMotor[j+index3[0]+1] == hapusData[j] && strlen(hapusData) == index3[1] - index3[0] -1){
  	  	    	loop5++;
  	  	  	}
  	  	}
  	  	/*End Seleksi PLAT Dengan Input User*/

  	  	if (loop5 != index3[1] - index3[0]-1){  /*Jika PLAT Tidak Sama Dengan Input User*/
  	  	  	char str[500] = {""};
  	  	  	strcat(str, dataMotor);

  	  	  	if (loop6 > 0){
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("data_motor.txt", "a");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	}
  	  	  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("data_motor.txt", "w");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	  	loop6++;
  	  	  	}
  	  	}else{  /*Jika PLAT Sama Dengan Input User (Kosongkan File)*/

  	  	}
  	  	loop++;
  	}
  	fclose(fptr); /*Tutup File dataMotor.txt*/
}
void cari_motor(){
int loop = 0;
  	char dataMotor[500];
  	char cariData[50];
  	char *hasil;
  	struct motor cariMotor[100];
  	FILE *fptr;
  	fptr = fopen("data_motor.txt", "r"); /*Buka File dataMotor.txt*/
  	printf("Masukkan Plat Yang Ingin Dicari : ");
  	scanf("%s", cariData);

  	memset(cariMotor, 0, sizeof(cariMotor));  /*Hapus Data Pada cariMotor*/

  	while (fgets(dataMotor, sizeof(dataMotor), fptr)){  /*Untuk Setiap Baris Data Pada dataMotor.txt*/
  	  	int loop4 = 0;
  	  	int loop5 = 0;
  	  	int index3[3];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataMotor, '|');
  	  	while(hasil != NULL){
  	  	  	index3[loop4] = hasil - dataMotor;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop4++;
  	  	}
  	  	/*End Mencari Index Dari Char '|'*/

  	  	/*Seleksi PLAT Dengan Input User*/
  	  	for (int j = 0; j < index3[1] - index3[0] - 1; j++){
  	  	  	if (dataMotor[j+index3[0]+1] == cariData[j] && strlen(cariData) == index3[1] - index3[0] -1){
  	  	    	loop5++;
  	  	  	}
  	  	}

        if (loop5 == index3[1] - index3[0]-1){  /*Jika PLAT Sama Dengan Input User*/

            for (int j = 0; j < index3[0]; j++){
    	  	cariMotor[loop].jenis[j] = dataMotor[j];
            }
            for (int j = 0; j < index3[1]-index3[0]-1; j++){
            cariMotor[loop].plat[j] = dataMotor[j+index3[0]+1];
            }
            for (int j = 0; j < index3[2]-index3[1]-1; j++){
            cariMotor[loop].stnk[j] = dataMotor[j+index3[1]+1];
            }
            for (int j = 0; j < strlen(dataMotor)-index3[2]-1; j++){
            cariMotor[loop].waktu[j] = dataMotor[j+index3[2]+1];
            }

                    printf("\n");
					printf("Jenis = %s", cariMotor[loop].jenis);
    	            printf("\n");
    	            printf("Plat = %s", cariMotor[loop].plat);
    	            printf("\n");
    	            printf("STNK = %s", cariMotor[loop].stnk);
    	            printf("\n");
    	            printf("Waktu = %s", cariMotor[loop].waktu);
    	            printf("\n");

        }
        loop++;

    }
    fclose(fptr);
}


void lihat_asc_mbl(){
    char dataMotor[500];
    FILE *fptr;
    fptr = fopen("data_mobil.txt", "r");
    char *hasil;
    struct motor lihatMotor[100];
    int loop = 0;
    int loop7 = 0;
	int ind[loop7]; /*Untuk Menyimpan Index Sesuai Urutan plat, Yang Akan Digunakan Untuk Print*/
    while (fgets(dataMotor, sizeof(dataMotor), fptr))
    {
        int loop2 = 0;
    	int index[4];

    	hasil = strchr(dataMotor, '|');
    	while(hasil != NULL){
    	  	index[loop2] = hasil - dataMotor;
    	  	hasil = strchr(hasil+1, '|');
    	  	loop2++;
    	}

        for (int j = 0; j < index[0]; j++){
    	  	lihatMotor[loop].jenis[j] = dataMotor[j];
    	}
        for (int j = 0; j < index[1]-index[0]-1; j++){
    	  	lihatMotor[loop].plat[j] = dataMotor[j+index[0]+1];
    	}
    	for (int j = 0; j < index[2]-index[1]-1; j++){
    	  	lihatMotor[loop].stnk[j] = dataMotor[j+index[1]+1];
    	}
    	for (int j = 0; j < strlen(dataMotor)-index[2]-1; j++){
    	  	lihatMotor[loop].waktu[j] = dataMotor[j+index[2]+1];
    	}


		int sort = 0;
		while (strlen(lihatMotor[loop7].jenis) != 0){
		    loop7++;
		}

			int loop8;

			/*Sort plat Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			for (int a = 0; a < loop7; a++)/*Untuk Setiap Data Yang Ada*/
			{
				loop8 = 0;
				for (int i = 0; i < loop7; i++)/*Bandingkan Dengan Semua Data Yang Ada*/
				{
					for (int j = 0; j < sizeof(lihatMotor[i].plat); j++)/*Bandingkan Setiap Huruf Pada plat Dengan Data Lain*/
					{
						if (tolower(lihatMotor[a].plat[j]) > tolower(lihatMotor[i].plat[j]))
						{
							loop8++;/*Tambahkan Index Dan Kemudian Break Jika plat Lebih Besar*/
							break;
						}else if(tolower(lihatMotor[a].plat[j]) < tolower(lihatMotor[i].plat[j])){
							break;/*Break Jika plat Lebih Kecil*/
						}
					}

				}
				ind[loop8] = a;/*Masukkan Index Sekarang Kedalam Ind Yang Berindex Total Dari loop8*/
            }

        loop++;
    }
                for (int i = 0; i < loop7; i++)
				{
    	            printf("\n");
					printf("Jenis = %s", lihatMotor[ind[i]].jenis);
    	            printf("\n");
    	            printf("Plat = %s", lihatMotor[ind[i]].plat);
    	            printf("\n");
    	            printf("STNK = %s", lihatMotor[ind[i]].stnk);
    	            printf("\n");
    	            printf("Waktu = %s", lihatMotor[ind[i]].waktu);
    	            printf("\n");
				}

    fclose(fptr);
}
void lihat_desc_mbl(){
    char dataMotor[500];
    FILE *fptr;
    fptr = fopen("data_mobil.txt", "r");
    char *hasil;
    struct motor lihatMotor[100];
    int loop = 0;
    int loop7 = 0;
	int ind[loop7]; /*Untuk Menyimpan Index Sesuai Urutan plat, Yang Akan Digunakan Untuk Print*/
    while (fgets(dataMotor, sizeof(dataMotor), fptr))
    {
        int loop2 = 0;
    	int index[4];

    	hasil = strchr(dataMotor, '|');
    	while(hasil != NULL){
    	  	index[loop2] = hasil - dataMotor;
    	  	hasil = strchr(hasil+1, '|');
    	  	loop2++;
    	}

        for (int j = 0; j < index[0]; j++){
    	  	lihatMotor[loop].jenis[j] = dataMotor[j];
    	}
        for (int j = 0; j < index[1]-index[0]-1; j++){
    	  	lihatMotor[loop].plat[j] = dataMotor[j+index[0]+1];
    	}
    	for (int j = 0; j < index[2]-index[1]-1; j++){
    	  	lihatMotor[loop].stnk[j] = dataMotor[j+index[1]+1];
    	}
    	for (int j = 0; j < strlen(dataMotor)-index[2]-1; j++){
    	  	lihatMotor[loop].waktu[j] = dataMotor[j+index[2]+1];
    	}


		int sort = 0;
		while (strlen(lihatMotor[loop7].jenis) != 0){
		    loop7++;
		}

			int loop8;

			/*Sort plat Dari Yang Terkecil Dan Masukkan Index ke Ind*/
			for (int a = 0; a < loop7; a++)/*Untuk Setiap Data Yang Ada*/
			{
				loop8 = 0;
				for (int i = 0; i < loop7; i++)/*Bandingkan Dengan Semua Data Yang Ada*/
				{
					for (int j = 0; j < sizeof(lihatMotor[i].plat); j++)/*Bandingkan Setiap Huruf Pada plat Dengan Data Lain*/
					{
						if (tolower(lihatMotor[a].plat[j]) > tolower(lihatMotor[i].plat[j]))
						{
							loop8++;/*Tambahkan Index Dan Kemudian Break Jika plat Lebih Besar*/
							break;
						}else if(tolower(lihatMotor[a].plat[j]) < tolower(lihatMotor[i].plat[j])){
							break;/*Break Jika plat Lebih Kecil*/
						}
					}

				}
				ind[loop8] = a;/*Masukkan Index Sekarang Kedalam Ind Yang Berindex Total Dari loop8*/
            }

        loop++;
    }
                for (int i = loop7-1; i >= 0; i--)
				{
    	            printf("\n");
					printf("Jenis = %s", lihatMotor[ind[i]].jenis);
    	            printf("\n");
    	            printf("Plat = %s", lihatMotor[ind[i]].plat);
    	            printf("\n");
    	            printf("STNK = %s", lihatMotor[ind[i]].stnk);
    	            printf("\n");
    	            printf("Waktu = %s", lihatMotor[ind[i]].waktu);
    	            printf("\n");
				}

    fclose(fptr);
}
void tambah_mobil(){
    FILE *fptr;
    struct motor tambahMotor;
    // printf("Masukkan jumlah : "); /* fflush(stdin);*/
    // scanf(" %[^\n]s", &jumlah);
    printf("Masukkan jenis : ");
    scanf(" %[^\n]s", &tambahMotor.jenis);
    printf("Masukkan plat : ");
    scanf(" %[^\n]s", &tambahMotor.plat);
    printf("Masukkan stnk : ");
    scanf(" %[^\n]s", &tambahMotor.stnk);
    printf("Masukkan waktu per jam: ");
    scanf(" %[^\n]s", &tambahMotor.waktu);

    fptr = fopen("data_mobil.txt","a");
    fprintf(fptr, "%s|%s|%s|%s\n", tambahMotor.jenis, tambahMotor.plat, tambahMotor.stnk, tambahMotor.waktu );
    fclose(fptr);
}
void lihat_mobil(){
    int pilih_option;
    printf("1. LIHAT ASCENDING\n");
    printf("2. LIHAT DESCENDING\n");
    scanf("%d", &pilih_option);

    switch(pilih_option) {
    case 1:
        lihat_asc_mbl();
    break;
    case 2:
        lihat_desc_mbl();
    default:
        printf("Maaf pilihan anda tidak tersedia\n");
    break;
    }
}
void hapus_mobil(){
    int loop = 0;
  	int loop6 = 0;
  	char dataMotor[500];
  	char hapusData[50];
  	char *hasil;
  	struct motor hapusMotor[100];
  	FILE *fptr;
  	fptr = fopen("data_mobil.txt", "r"); /*Buka File dataMotor.txt*/
  	printf("Masukkan Plat Yang Ingin Dihapus : ");
  	scanf("%s", hapusData);

  	memset(hapusMotor, 0, sizeof(hapusMotor));  /*Hapus Data Pada hapusMotor*/

  	while (fgets(dataMotor, sizeof(dataMotor), fptr)){  /*Untuk Setiap Baris Data Pada dataMotor.txt*/
  	  	int loop4 = 0;
  	  	int loop5 = 0;
  	  	int index3[3];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataMotor, '|');
  	  	while(hasil != NULL){
  	  	  	index3[loop4] = hasil - dataMotor;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop4++;
  	  	}
  	  	/*End Mencari Index Dari Char '|'*/

  	  	/*Seleksi PLAT Dengan Input User*/
  	  	for (int j = 0; j < index3[1] - index3[0] - 1; j++){
  	  	  	if (dataMotor[j+index3[0]+1] == hapusData[j] && strlen(hapusData) == index3[1] - index3[0] -1){
  	  	    	loop5++;
  	  	  	}
  	  	}
  	  	/*End Seleksi PLAT Dengan Input User*/

  	  	if (loop5 != index3[1] - index3[0]-1){  /*Jika PLAT Tidak Sama Dengan Input User*/
  	  	  	char str[500] = {""};
  	  	  	strcat(str, dataMotor);

  	  	  	if (loop6 > 0){
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("data_motor.txt", "a");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	}
  	  	  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  	  	  	/*Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	  	FILE *fptr;
  	  	  	  	fptr = fopen("data_motor.txt", "w");
  	  	  	  	fprintf(fptr,"%s", str);
  	  	  	  	fclose(fptr);
  	  	  	  	/*End Simpan String Hasil Penggabungan Ke dataMotor.txt*/
  	  	  	  	loop6++;
  	  	  	}
  	  	}else{  /*Jika PLAT Sama Dengan Input User (Kosongkan File)*/

  	  	}
  	  	loop++;
  	}
  	fclose(fptr); /*Tutup File dataMotor.txt*/
}
void cari_mobil(){
    int loop = 0;
  	char dataMotor[500];
  	char cariData[50];
  	char *hasil;
  	struct motor cariMotor[100];
  	FILE *fptr;
  	fptr = fopen("data_mobil.txt", "r"); /*Buka File dataMotor.txt*/
  	printf("Masukkan Plat Yang Ingin Dicari : ");
  	scanf("%s", cariData);

  	memset(cariMotor, 0, sizeof(cariMotor));  /*Hapus Data Pada cariMotor*/

  	while (fgets(dataMotor, sizeof(dataMotor), fptr)){  /*Untuk Setiap Baris Data Pada dataMotor.txt*/
  	  	int loop4 = 0;
  	  	int loop5 = 0;
  	  	int index3[3];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataMotor, '|');
  	  	while(hasil != NULL){
  	  	  	index3[loop4] = hasil - dataMotor;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop4++;
  	  	}
  	  	/*End Mencari Index Dari Char '|'*/

  	  	/*Seleksi PLAT Dengan Input User*/
  	  	for (int j = 0; j < index3[1] - index3[0] - 1; j++){
  	  	  	if (dataMotor[j+index3[0]+1] == cariData[j] && strlen(cariData) == index3[1] - index3[0] -1){
  	  	    	loop5++;
  	  	  	}
  	  	}

        if (loop5 == index3[1] - index3[0]-1){  /*Jika PLAT Sama Dengan Input User*/

            for (int j = 0; j < index3[0]; j++){
    	  	cariMotor[loop].jenis[j] = dataMotor[j];
            }
            for (int j = 0; j < index3[1]-index3[0]-1; j++){
            cariMotor[loop].plat[j] = dataMotor[j+index3[0]+1];
            }
            for (int j = 0; j < index3[2]-index3[1]-1; j++){
            cariMotor[loop].stnk[j] = dataMotor[j+index3[1]+1];
            }
            for (int j = 0; j < strlen(dataMotor)-index3[2]-1; j++){
            cariMotor[loop].waktu[j] = dataMotor[j+index3[2]+1];
            }

                    printf("\n");
					printf("Jenis = %s", cariMotor[loop].jenis);
    	            printf("\n");
    	            printf("Plat = %s", cariMotor[loop].plat);
    	            printf("\n");
    	            printf("STNK = %s", cariMotor[loop].stnk);
    	            printf("\n");
    	            printf("Waktu = %s", cariMotor[loop].waktu);
    	            printf("\n");

        }
        loop++;

    }
    fclose(fptr);
}



void menu_motor(){
    int pilih_menu = 0;

    printf("1. TAMBAH MOTOR\n");
    printf("2. LIHAT MOTOR\n");
    printf("3. HAPUS MOTOR\n");
    printf("4. CARI MOTOR\n");

    printf("Pilih menu : ");
    scanf("%d", &pilih_menu);
    switch(pilih_menu) {
    case 1:
        tambah_motor();
        break;
    case 2:
        lihat_motor();
        break;
    case 3:
        hapus_motor();
        break;
    case 4:
        cari_motor();

    break;
    default:
        printf("Maaf pilihan anda tidak tersedia!\n");
        break;
    }
}

void menu_mobil(){
    int pilih_menu = 0;

    printf("1. TAMBAH MOBIL\n");
    printf("2. LIHAT MOBIL\n");
    printf("3. HAPUS MOBIL\n");
    printf("4. CARI MOBIL\n");

    printf("Pilih menu : ");
    scanf("%d", &pilih_menu);
    switch(pilih_menu) {
    case 1:
        tambah_mobil();
        break;
    case 2:
        lihat_mobil();
        break;
    case 3:
        hapus_mobil();
        break;
    case 4:
        cari_mobil();

    break;
    default:
        printf("Maaf pilihan anda tidak tersedia!\n");
        break;
    }
}




int main(){

   printf("======KELOMPOK KAMI======\n");
   printf("=Yuandytha f.a.p sujiana=\n");
   printf("====Senina G wibianti====\n");
   printf("=====Yulan T. lepur======\n");
   int jenis,platmotor[100],platmobil[100],stnkmotor[100],j,jumlahmotor,jumlahmobil,stnkmobil[100],jammotor[100];
   int jammobil[100];
   char  motor[100],mobil[100],lagi;



   float in,out,jam;

    do{
      printf("========================\n");
      printf("===   PARKIR KAMPUS  ===\n");
      printf("========================\n");
      printf("periksa STNK            \n");
      printf("1. Motor\n");
      printf("2. Mobil\n");
      printf("Pilih :");
      scanf("%i", &jenis);
      printf("========================\n");
      printf("\n");

      if(jenis==1){
        menu_motor();
        // parkirmotor(jumlahmotor,motor,platmotor,stnkmotor,jammotor);
      }
      else if(jenis==2){
        menu_mobil();
       // parkirmobil(jumlahmobil,mobil,platmobil,stnkmobil,jammobil);
       }

      printf("Periksa lagi? y/n : ");
    scanf("%s", &lagi);
    }while (lagi=='y');

    printf("Terima kasih");

}
