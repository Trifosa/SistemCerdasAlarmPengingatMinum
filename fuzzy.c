#include <stdio.h>
#include <string.h>

float kebawah(float atas, float bawah, float lama){
	float hasil;
	hasil = (lama - bawah)/(atas - bawah);
	// atas adalah batas jangkauan tertinggi
	// bawah adalah batas jangkauan terendah
	
	return hasil;
}

float keatas(float atas, float bawah, float lama){
	float hasil;
	hasil = (atas - lama)/(atas - bawah);
	// atas adalah batas jangkauan tertinggi
	// bawah adalah batas jangkauan terendah
	
	return hasil;
}

int main(){
	// Variabel yang akan dipakai
	float t_minum, t_now, t_lama;	// Vsriabel untuk menyimpan waktu terakhir kali minum, waktu sekarang, dan lama waktu berjalan
	float suhu;
	float cek1, cek2;
	float dk_time, dk_suhu;			// Variabel untuk menyimpan derajat keanggotaan
	
	int ubah;
	char status_time[50];
	char status_suhu[50];
	
	// Meminta inputan
	printf("Jam terakhir kali minum: ");
	scanf("%f", &t_minum);
	
	printf("Sekarang jam: ");
	scanf("%f", &t_now);
	
	printf("Suhu sekarang: ");
	scanf("%f", &suhu);
	
	if(t_minum > t_now){			// Jika waktu terakhir kali minum lebih besar dari waktu sekarang (ganti hari)
		t_lama = 24 - t_minum + t_now;
	}else{
		t_lama = t_now - t_minum;	// Jika masih dalam hari yang sama
	}
	
	// Mengolah menit ke jam
	ubah = t_lama;
	cek1 = t_lama - ubah;
	cek1 = cek1 / 0.06 * 0.1;
	t_lama = ubah + cek1;	
	
	// Menghitung derajat keanggotaan dan status waktu
	if(t_lama <= 1){
		dk_time = 1;
		strcpy(status_time, "Belum_Lama");
	}
	else if((t_lama > 1)&&(t_lama <= 2)){
		cek1 = keatas(2, 1, t_lama);	// Mengecek derajat keanggotaan Belum Lama
		cek2 = kebawah(2, 1, t_lama);	// Mengecek derajat keanggotaan Agak Lama
		
		if(cek1 > cek2){
			dk_time = cek1;
			strcpy(status_time, "Belum_Lama");
		}else{
			dk_time = cek2;
			strcpy(status_time, "Agak_Lama");
		}
	}
	else if((t_lama > 2)&&(t_lama <= 3)){
		cek1 = keatas(3, 2, t_lama);	// Mengecek derajat keanggotaan Agak Lama
		cek2 = kebawah(3, 2, t_lama);	// Mengecek derajat keanggotaan Lama
		
		if(cek1 > cek2){
			dk_time = cek1;
			strcpy(status_time, "Agak_Lama");
		}else{
			dk_time = cek2;
			strcpy(status_time, "Lama");
		}
	}
	else if((t_lama > 3)&&(t_lama < 4)){
		cek1 = keatas(4, 3, t_lama);	// Mengecek derajat keanggotaan Lama
		cek2 = kebawah(4, 3, t_lama);	// Mengecek derajat keanggotaan Sangat Lama
		
		if(cek1 > cek2){
			dk_time = cek1;
			strcpy(status_time, "Lama");
		}else{
			dk_time = cek2;
			strcpy(status_time, "Sangat_Lama");
		}
	}
	else if(t_lama >= 4){
		dk_time = 1;
		strcpy(status_time, "Sangat_Lama");
	}
	
	// Menghitung derajat keanggotaan dan status suhu
	if(suhu <= 20){
		dk_suhu = 1;
		strcpy(status_suhu, "Sejuk");
	}
	else if((suhu > 20)&&(suhu <= 25)){
		cek1 = keatas(25, 20, suhu);	// Mengecek derajat keanggotaan Sejuk
		cek2 = kebawah(25, 20, suhu);	// Mengecek derajat keanggotaan Normal
		
		if(cek1 > cek2){
			dk_suhu = cek1;
			strcpy(status_suhu, "Sejuk");
		}else{
			dk_suhu = cek2;
			strcpy(status_suhu, "Normal");
		}
	}
	else if((suhu > 25)&&(suhu <= 30)){
		cek1 = keatas(30, 25, suhu);	// Mengecek derajat keanggotaan Normal
		cek2 = kebawah(30, 25, suhu);	// Mengecek derajat keanggotaan Panas
		
		if(cek1 > cek2){
			dk_suhu = cek1;
			strcpy(status_suhu, "Normal");
		}else{
			dk_suhu = cek2;
			strcpy(status_suhu, "Panas");
		}
	}else if((suhu > 30)&&(suhu < 35)){
		cek1 = keatas(35, 30, suhu);	// Mengecek derajat keanggotaan Panas
		cek2 = kebawah(35, 30, suhu);	// Mengecek derajat keanggotaan Sangat Panas
		
		if(cek1 > cek2){
			dk_suhu = cek1;
			strcpy(status_suhu, "Panas");
		}else{
			dk_suhu = cek2;
			strcpy(status_suhu, "Sangat_Panas");
		}
	}
	else if(suhu >= 35){
		dk_suhu = 1;
		strcpy(status_suhu, "Sangat_Panas");
	}
	
	printf("\nWaktu masuk dalam kategori %s\nDerajat keanggotaan = %.2f\n", status_time, dk_time);
	printf("\nSuhu masuk dalam kategori %s\nDerajat keanggotaan = %.2f\n\n", status_suhu, dk_suhu);
	
	if(strcmp(status_time, "Belum_Lama") == 0){
		printf("Pengguna belum butuh minum\n");
	}
	else if(strcmp(status_time, "Agak_Lama") == 0){
		if((strcmp(status_suhu, "Sejuk") == 0) || (strcmp(status_suhu, "Normal") == 0)){
			printf("Pengguna belum butuh minum\n");
		}
		else if((strcmp(status_suhu, "Panas") == 0) || (strcmp(status_suhu, "Sangat_Panas") == 0)){
			printf("Pengguna butuh minum\n");
		}
	}
	else if(strcmp(status_time, "Lama") == 0){
		if((strcmp(status_suhu, "Sejuk") == 0) || (strcmp(status_suhu, "Normal") == 0)){
			printf("Pengguna butuh minum\n");
		}
		else if((strcmp(status_suhu, "Panas") == 0) || (strcmp(status_suhu, "Sangat_Panas") == 0)){
			printf("Pengguna sangat butuh minum\n");
		}
	}
	else if(strcmp(status_time, "Sangat_Lama") == 0){
		printf("Pengguna sangat butuh minum\n");
	}
	
	return 0;
}

/*
Misael Trifosa	1805100
M. Rheza A.		1805427
*/