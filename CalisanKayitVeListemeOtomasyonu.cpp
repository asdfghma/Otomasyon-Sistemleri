#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char isim[50];
	char soyisim[50];
	char departman[50];
	int maas;
} Calisan;

void dosyaOlustur(const char* dosyaAdi) {
	FILE *dosya = fopen(dosyaAdi, "a");
	if(dosya == NULL) {
		printf("Dosya olusturulamadi \n");
		exit(EXIT_FAILURE);
	}
	fclose(dosya);
}

Calisan* calisanlariOku(const char* dosyaAdi, int* calisanSayisi) {
	FILE* dosya = fopen(dosyaAdi, "r"); 
	if(dosya == NULL) {
		printf("Dosya bulunamadi \n");
		exit(EXIT_FAILURE);
	}
	
	int count = 0;
	 char buffer[256];
	 while(fgets(buffer, sizeof(buffer), dosya) != NULL) {
	 	count++;
	 }
	 rewind(dosya);
	 
	 Calisan* calisanlar = (Calisan*)malloc(count * sizeof(Calisan));
	 if(dosya == NULL) {
		printf("Bellek yetersiz \n");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < count; i++) {
		fscanf(dosya, "%[^,], %[^,], %[^,], %d\n", calisanlar[i].isim, calisanlar[i].soyisim, calisanlar[i].departman, &calisanlar[i].maas);
		
	}
	fclose(dosya);
	*calisanSayisi = count;
	return calisanlar;
}

void calisanEkle(const char* dosyaAdi) {
	FILE* dosya = fopen(dosyaAdi, "a");
	if(dosya == NULL) {
		printf("Dosya acilamadi\n");
		return;
	}
	
	Calisan yeniCalisan;
	
	printf("Calisanin adini giriniz : ");
	scanf("%s", yeniCalisan.isim);
	printf("Calisanin soyismini giriniz : ");
	scanf("%s", yeniCalisan.soyisim);
	printf("Calisanin departmanini giriniz : ");
	scanf("%s", yeniCalisan.departman);
	printf("Calisanin maasini giriniz : ");
	scanf("%d", &yeniCalisan.maas);
	
	fprintf(dosya, "%s, %s, %s, %d\n", yeniCalisan.isim, yeniCalisan.soyisim, yeniCalisan.departman, yeniCalisan.maas);
	
	fclose(dosya);
	
	printf("Yeni calisan basariyla eklendi \n");
}	


void ortalamaMaas(Calisan* calisanlar, int calisanSayisi) {
int toplamMaas = 0;
for (int i = 0; i < calisanSayisi; i++) {
	toplamMaas += calisanlar[i].maas;
}
float ortalama = (float)toplamMaas / calisanSayisi;
printf("Calisanlarin ortalama maasi : %.2f TL\n", ortalama);
}

void departmanaGoreSiralama(Calisan* calisanlar, int calisanSayisi) {
	
	for( int i = 0; i < calisanSayisi - 1; i++) {
		for(int j = 0; j < calisanSayisi- i - 1; j++) {
			if(strcmp(calisanlar[j].departman, calisanlar[j + 1].departman) > 0) {
				Calisan temp = calisanlar[j];
				calisanlar[j] = calisanlar[j + 1];
				calisanlar[j + 1] = temp;
			}
		}
	}
	printf("Departmana gore siralanmis calisan listesi : \n");
	for(int i = 0; i < calisanSayisi; i++) {
		printf("%d. %s %s, %s, %d TL\n", i + 1, calisanlar[i].isim, calisanlar[i].soyisim, calisanlar[i].departman, calisanlar[i].maas);
		
	}
}

void maasaGoreSiralama(Calisan* calisanlar, int calisanSayisi) {
	for(int i = 0 ; i < calisanSayisi - 1; i++) {
		for(int j = 0; j < calisanSayisi - i - 1; j++) {
			if(calisanlar[j].maas > calisanlar[j + 1].maas) {
				Calisan temp = calisanlar[j];
				calisanlar[j] = calisanlar[j + 1];
				calisanlar[j + 1] = temp;
			}
		}
	}
	
	printf("Maas gore siralanmis calisan listesi : \n");
	for(int i = 0; i < calisanSayisi; i++) {
		printf("%d. %s %s, %s, %d TL\n", i + 1, calisanlar[i].isim, calisanlar[i].soyisim, calisanlar[i].departman, calisanlar[i].maas);
	}
}

void calisanAra(Calisan* calisanlar, int calisanSayisi, const char* aranan) {
	int bulundu = 0;
	for(int i = 0; i < calisanSayisi; i++) {
		if(strstr(calisanlar[i].isim, aranan) != NULL || strstr(calisanlar[i].soyisim, aranan) != NULL) {
			printf("Calisan bulundu : %s %s, %s, %d TL\n", calisanlar[i].isim, calisanlar[i].soyisim, calisanlar[i].departman, calisanlar[i].maas);
			bulundu = 1;
			break;
		}
	}
	if(!bulundu) {
		printf("Aradiginiz calisan bulunamadi \n");
	}
}

int main() {
	dosyaOlustur("calisanlar.txt");
	
	int calisanSayisi;
	Calisan* calisanlar = calisanlariOku("calisanlar.txt", &calisanSayisi);
	int secim;
	char aranan[50];
	do{
		printf("\n1. Calisan listesini goruntule\n");
		printf("2. Calisanlarý departmana gore sirala ve goster\n");
		printf("3. Calisanlari maasa gore sirala ve goster\n");
		printf("4. Calisan adi ve soyadina gore arama yapma\n");
		printf("5. Yeni calisan ekle\n");
		printf("6. Calisanlarin ortalama maasini goster\n");
		printf("7. Cikis\n");
		printf("Seciminizi yapiniz lutfen : ");
		scanf("%d", &secim);
		
		switch(secim) {
			case 1:
				for(int i = 0; i < calisanSayisi; i++) {
					printf("%d. %s %s, %s, %d TL \n", i + 1, calisanlar[i].isim, calisanlar[i].soyisim, calisanlar[i].departman, calisanlar[i].maas);
				}
				break;
				case 2:
					departmanaGoreSiralama(calisanlar, calisanSayisi);
					break;
					case 3:
						maasaGoreSiralama(calisanlar, calisanSayisi);
						break;
						case 4:
							printf("Aramak istediginiz calisanin adini ve soyadini giriniz : ");
							scanf("%s", aranan);
							calisanAra(calisanlar, calisanSayisi, aranan);
							break;
							case 5:
								calisanEkle("calisanlar.txt");
								calisanlar = calisanlariOku("calisanlar.txt", &calisanSayisi);
								break;
								case 6:
									ortalamaMaas(calisanlar ,calisanSayisi);
									break;
									case 7:
										printf("Programdan cikis yapiliyor \n");
										break;
									default:
										printf("Gecersiz secim. Lutfen tekrar deneyiniz.\n");
		}
	} while (secim != 7);
	
	free(calisanlar);
	return 0;

}


