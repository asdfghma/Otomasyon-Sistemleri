#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// K�T�PHANE PROGRAMI

typedef struct Kitap {
	int barkod;
	char kitapAdi[30];
	char yazarAdi[30];
	char yayinEvi[30];
	char kitapTuru[30];
	char teminTuru[30];
	char teminTarihi[30];
	int stokSayisi;
	
} kitap;

typedef struct Uye {
 char TC[12];
    char adSoyad[30];
    char cinsiyet;
    char dogumTarihi[11];
    char telefon[15];
    char eposta[30];
    char uyelikTarihi[11];
    char adres[50];
	int durum;
} uye;

typedef struct Emanet {
	char uyeTC[20];
	int kitapBarkod;
	time_t teslimTarihi;
	int kullanacagiGunSayisi;
	int kullandigiGunSayisi;
	time_t iadeTarihi;
	int gecikmeGunSayisi;
	int durum;

} emanet;

void kitapEkle()
{
    system("cls");
    printf("Kitap ekleme ekrani \n\n");

    kitap k1;

    printf("Barkod      :");
    scanf(" %d", &k1.barkod);
    printf("Kitap adi   :");
    scanf(" %[^\n]s", k1.kitapAdi);
    printf("Yazar adi   :");
    scanf(" %[^\n]s", k1.yazarAdi);
    printf("Yayin evi   :");
    scanf(" %[^\n]s", k1.yayinEvi);
    printf("Kitap turu  :");
    scanf(" %[^\n]s", k1.kitapTuru);
    printf("Temin turu  :");
    scanf(" %[^\n]s", k1.teminTuru);
    printf("Temin tarihi:");
    scanf(" %[^\n]s", k1.teminTarihi);
    printf("Stok        :");
    scanf(" %d", &k1.stokSayisi);

    FILE *ptr = fopen("kitaplar.dat", "a+b");
    fwrite(&k1, sizeof(kitap), 1, ptr);
    fclose(ptr);
    printf("Kitap kaydi tamamlandi\n");
    
}

void kitapSil()
{
	system("cls");
	printf("Kitap silme ekrani \n\n");
	
	kitap k1;
	int barkod, sonuc = 0;
	
	printf("Barkod : ");
	scanf(" %d", &barkod);
	
	FILE * ptr = fopen("kitaplar.dat", "r+b");
	FILE * yptr = fopen("yedek.dat", "w+b");

	while(	fread( &k1, sizeof(kitap), 1, ptr) != NULL )
	{
		if( barkod != k1.barkod)
		fwrite( &k1, sizeof(kitap), 1, yptr);
		else
		sonuc = 1;
		
	}
	
	fclose(ptr);
	fclose(yptr);
	if(sonuc == 0)
	{
		printf("%d barkod numarali kitap bulunamadi\n", barkod);
	}
	else
	{
		remove("kitaplar.dat");
		rename("yedek.dat", "kitaplar.dat");
		printf("%d barkod numarali kitap silindi", barkod);
	}
}

void kitapListele()
{
    system("cls");
    printf("Kitap listeleme ekrani \n\n");

    kitap k1;
    int kitapSayisi = 0;

    FILE *ptr = fopen("kitaplar.dat", "r+b");

	printf("%-10s%-30s%-30s%-30s%-20s%-20s%-20s%-10s\n", "BARKOD", "KITAP-ADI", "YAZAR-ADI", "YAYIN-EVI", "KITAP-TURU", "TEMIN-TURU", "TEMIN-TARIHI", "STOK");

    while (fread(&k1, sizeof(kitap), 1, ptr) == 1)
    {
        printf("%-10d%-30s%-30s%-30s%-20s%-20s%-20s%-10d\n", k1.barkod, k1.kitapAdi, k1.yazarAdi, k1.yayinEvi, k1.kitapTuru, k1.teminTuru, k1.teminTarihi, k1.stokSayisi);
        kitapSayisi++;
    }

    fclose(ptr);
    printf("Toplam kitap sayisi : %d\n", kitapSayisi);
}


void kitapIslemleri()
{
	int secim;
	system("cls");
	printf("Kitap islemleri ekrani \n\n");
	
	printf("1- Kitap ekle \n");
	printf("2- Kitap sil \n");
	printf("3- Kitap listele \n");
	printf("0- Ana menuye don \n");
	printf("Seciminiz : \n");
	scanf("%d", &secim);	
	
	switch(secim)
	{
		case 1: kitapEkle();
		break;
		case 2: kitapSil();
		break;
		case 3: kitapListele();
		break;
		case 4: break;
		default: printf("Hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz. \n ");
		break;
	 } 
	
}

void uyeEkle()
{
	system("cls");
	printf("Uye ekleme ekrani \n\n");
	
	uye u1;
	
	printf("TC            :"); scanf(" %[^\n]s", u1.TC);
	printf("AD-SOYAD      :"); scanf(" %[^\n]s", u1.adSoyad);
	printf("CINSIYET      :"); scanf(" %[^\n]s", &u1.cinsiyet);
	printf("DOGUM TARIHI  :"); scanf(" %[^\n]s", u1.dogumTarihi);
	printf("TELEFON       :"); scanf(" %[^\n]s", u1.telefon);
	printf("E-POSTA       :"); scanf(" %[^\n]s", u1.eposta);
	printf("UYELIK TARIHI :"); scanf(" %[^\n]s", u1.uyelikTarihi);
	printf("ADRES         :"); scanf(" %[^\n]s", u1.adres);
	
	u1.durum = 0;
	
	FILE * ptr = fopen("uyeler.dat", "a+b");
	fwrite( &u1, sizeof(uye), 1, ptr);
	fclose(ptr);
	printf("Uye kaydi tamamlandi\n");
	
}


void uyeSil() 
{
	system("cls");
	printf("Uye silme ekrani \n\n");
	
	uye u1;
	int sonuc = 0;
	char TC[20];
	
	
	printf("TC : "); scanf(" %[^\n]s", TC);
	
	FILE * ptr = fopen("uyeler.dat", "r+b");
	FILE * yptr = fopen("yedek.dat", "w+b");

	while(	fread( &u1, sizeof(uye), 1, ptr) != NULL )
	{
		if( strcmp( TC, u1.TC) != 0)
		fwrite( &u1, sizeof(uye), 1, yptr);
		else
		sonuc = 1;
		
	}
	
	fclose(ptr);
	fclose(yptr);
	if(sonuc == 0)
	{
		printf("%s TC numarali kisi bulunamadi\n", TC);
	}
	else
	{
		remove("uyeler.dat");
		rename("yedek.dat", "uyeler.dat");
		printf("%s TC numarali uye silindi", TC);
	}
	
}

void uyeListele()
{
    system("cls");
    printf("Uye listeleme ekrani\n\n");

    uye u1;
    int kisiSayisi = 0;

    FILE *ptr = fopen("uyeler.dat", "rb");

    printf("%-12s%-30s%-10s%-15s%-15s%-30s%-15s%-50s\n", "TC", "AD-SOYAD", "CINSIYET", "DOGUM-TARIHI", "TELEFON", "E-POSTA", "UYELIK-TARIHI", "ADRES");

    while (fread(&u1, sizeof(uye), 1, ptr) == 1)
    {
        printf("%-12s%-30s%-10c%-15s%-15s%-30s%-15s%-50s\n", u1.TC, u1.adSoyad, u1.cinsiyet, u1.dogumTarihi, u1.telefon, u1.eposta, u1.uyelikTarihi, u1.adres);
        kisiSayisi++;
    }

    fclose(ptr);
    printf("Toplam uye sayisi: %d\n", kisiSayisi);
}


void uyeIslemleri()
{
	int secim;
	system("cls");
	printf("Uye islemleri ekrani \n\n");
	
	printf("1- Uye ekle \n");
	printf("2- Uye sil \n");
	printf("3- Uye listele \n");
	printf("0- Ana menuye don \n");
	printf("Seciminiz : \n");
	scanf("%d", &secim);	
	
	switch(secim)
	{
		case 1: uyeEkle();
		break;
		case 2: uyeSil();
		break;
		case 3: uyeListele();
		break;
		case 0: break;
		default: printf("Hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz. \n ");
		break;
	 } 
}

void stokGuncelle( int barkod, int sayi)
{
	
	kitap k1;
	int  sayac = 0;
	
	FILE * ptr = fopen("kitaplar.dat", "r+b");

	while(	fread( &k1, sizeof(kitap), 1, ptr) != NULL )
	{
		if( barkod == k1.barkod)
		break;
		
		sayac++;		
	}

	rewind(ptr);
	
	fseek( ptr, (sayac) * sizeof(kitap), 0);
	
	k1.stokSayisi += sayi;
	fwrite( &k1, sizeof(kitap), 1, ptr);
	fclose(ptr);
	printf("Stok guncellendi \n");

}

void emanetKitapVer()
{
    system("cls");
    printf("Emanet kitap verme ekrani \n\n");
    emanet e1;
    uye u1;
    kitap k1;
    int usonuc = 0, ksonuc = 0;
    printf("TC     : ");
    scanf(" %[^\n]s", e1.uyeTC);
    printf("BARKOD : ");
    scanf(" %d", &e1.kitapBarkod);

    FILE *uptr = fopen("uyeler.dat", "r+b");
    while (fread(&u1, sizeof(uye), 1, uptr) != NULL)
    {
        if (strcmp(e1.uyeTC, u1.TC) == 0)
        {
            usonuc = 1;
            break;
        }
    }
    fclose(uptr);
    if (usonuc == 0)
    {
        printf("%s TC numarali uye yok, ana menuye yonlendiriliyorsunuz\n", e1.uyeTC);
        return;
    }

    FILE *kptr = fopen("kitaplar.dat", "r+b");
    while (fread(&k1, sizeof(kitap), 1, kptr) != NULL)
    {
        if (e1.kitapBarkod == k1.barkod)
        {
            ksonuc = 1;
            break;
        }
    }
    fclose(kptr);
    if (ksonuc == 0)
    {
        printf("%d barkod numarali kitap kaydi yok, ana menuye yonlendiriliyorsunuz\n", e1.kitapBarkod);
        return;
    }
    if (k1.stokSayisi < 1)
    {
        printf("%d barkod numarali kitaptan stokta kalmamis, ana menuye yonlendiriliyorsunuz\n", e1.kitapBarkod);
        return;
    }

    if (u1.durum == -1)
    {
        printf("%s TC numarali uye yasakli, ana menuye yonlendiriliyorsunuz\n", e1.uyeTC);
        return;
    }

    FILE *ptr = fopen("emanetler.dat", "a+b");
    printf("Kac gun kullanilacak : ");
    scanf(" %d", &e1.kullanacagiGunSayisi);
    e1.teslimTarihi = time(0);

    fwrite(&e1, sizeof(emanet), 1, ptr);
    fclose(ptr);
    printf("Emanet kaydi tamamlandi \n");
    stokGuncelle(e1.kitapBarkod, -1);
}


void uyeGuncelle( char *tcPtr )
{
	uye u1;
	int sonuc = 0, sayac = 0;;
		
	FILE * ptr = fopen("uyeler.dat", "r+b");

	while(	fread( &u1, sizeof(uye), 1, ptr) != NULL )
	{
		if( strcmp( tcPtr, u1.TC) == 0)
		{
			sonuc = 1;
			break;
		}
		sayac++;
		
	}
	if(sonuc == 1)
	{
	rewind(ptr);
	fseek( ptr,(sayac) * sizeof(uye), 0);
	u1.durum = -1;
	fwrite( &u1, sizeof(uye), 1, ptr);
	printf("Uye durumu guncellendi \n");
	}
	
	
	fclose(ptr);
	
}


void emanetKitapIadeAl()
{
    system("cls");
    printf("Emanet kitap iade alma ekrani \n\n");
    emanet e1;
    uye u1;
    kitap k1;
    int sonuc = 0, sayac = 0;
    char uyeTC[20];
    int kitapBarkod;

    printf("TC     : ");
    scanf(" %[^\n]s", uyeTC);
    printf("BARKOD : ");
    scanf(" %d", &kitapBarkod);

    FILE *ptr = fopen("emanetler.dat", "r+b");
    while (fread(&e1, sizeof(emanet), 1, ptr) != NULL)
    {
        if (strcmp(e1.uyeTC, uyeTC) == 0 && kitapBarkod == e1.kitapBarkod)
        {
            sonuc = 1;
            break;
        }
        sayac++;
    }
    if (sonuc == 0)
    {
        fclose(ptr);
        printf("%s TC veya %d barkod numarali emanet yok\n", uyeTC, kitapBarkod);
        return;
    }
    else
    {
        rewind(ptr);

        e1.iadeTarihi = time(0);
        float saniye, dakika, saat, gun;
        saniye = difftime(e1.iadeTarihi, e1.teslimTarihi);
        dakika = saniye / 60;
        saat = dakika / 60;
        gun = saat / 24;

        e1.kullandigiGunSayisi = gun;

        e1.gecikmeGunSayisi = e1.kullanacagiGunSayisi - e1.kullandigiGunSayisi;

        if (e1.gecikmeGunSayisi > 10)
        {
            e1.durum = -1;
        }
        else
            e1.durum = 1;

        fseek(ptr, (sayac) * sizeof(emanet), 0);
        fwrite(&e1, sizeof(emanet), 1, ptr);
        fclose(ptr);
        printf("Emanet iade kaydi tamamlandi \n");

        stokGuncelle(e1.kitapBarkod, -1);
        if (e1.durum == -1)
            uyeGuncelle(uyeTC);
    }
}

void emanetKitaplariListele()
{
	printf("cls");
	printf("Emanet kitap listeleme ekrani \n\n");
	emanet e1;
	int sayac = 0;
	FILE * ptr = fopen("emanetler.dat", "r+b");
	printf("%-20s%-20s%-20s%-20s", "TC", "BARKOD", "TARIH", "DURUM" );
	while( fread(&e1, sizeof(emanet) ,1, ptr ) != NULL )
	{
		struct tm * tbilgi = localtime(&e1.teslimTarihi);
		char tarih[20];
		strftime( tarih, sizeof(tarih), "%d.%m.%Y", tbilgi );
		
		if( e1.durum == 0)
		{
			printf("%-20s%-20d%-20s%-20d\n", e1.uyeTC, e1.kitapBarkod, tarih, e1.durum);
			sayac++;
		}
	}
	fclose(ptr);
	printf("Emanet kayit sayisi : %d\n", sayac);
}


void emanetKitapIslemleri()
{
	int secim;
	system("cls");
	printf("Emanet kitap islemleri ekrani \n\n");
	
	printf("1- Emanet kitap ekle \n");
	printf("2- Emanet kitab� al \n");
	printf("3- Emanet kitaplari listele \n");
	printf("0- Ana menuye don \n");
	printf("Seciminiz : \n");
	scanf("%d", &secim);	
	
	switch(secim)
	{
		case 1: emanetKitapVer();
		break;
		case 2: emanetKitapIadeAl();
		break;
		case 3: emanetKitaplariListele();
		break;
		case 0: break;
		default: printf("Hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz. \n ");
		break;
	 } 
}



int menu() {
	
	int secim;
	printf("\nKUTUPHANE OTOMASYONU\n\n");
	printf("\t1-KITAP ISLEMLERI \n");
	printf("\t2-UYE ISLEMLERI \n");
	printf("\t3-EMENAT KITAP ISLEMLERI \n");
	printf("\t0-PROGRAMI KAPAT \n\n");
	printf("\tSeciminiz : ");
	scanf("%d", &secim);
	
	return secim;

}

 
int main() {
	
	int secim = menu();
	
	while(secim != 0)
	{
		switch(secim )
		{
			case 1: kitapIslemleri(); 
			break;
			case 2: uyeIslemleri();
			break;
			case 3: emanetKitapIslemleri();
			break;
			case 0: break;
			default : printf("\nHATALI SECIM YAPTINIZ \n");
		}
		secim = menu();
	}
	
	printf("Program kapatildi");
	return 0;
}
