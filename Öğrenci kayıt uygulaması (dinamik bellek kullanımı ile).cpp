#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Ogrenci {
	int numara;
	char ad[20];
	int vize;
	int final;
};


void yeniKayit(struct Ogrenci * ptr, int n)
{
	int numara;
	char ad[20];
	int vize;
	int final;
	int i = 0;
	printf("Yeni kayýt edilecek öðrenci bilgilerini giriniz : \n");

	while( i < n )
	{
		printf("%d. öðrenci bilgilerini giriniz : \n",i+1);
		printf("Numara:"); scanf("%d",&numara);
		printf("Ad:"); scanf("%s",ad);
		printf("Vize:"); scanf("%d",&vize);
		printf("Final:"); scanf("%d",&final);
		
		ptr->numara = numara;
		strcpy (ptr->ad, ad);
		ptr->vize = vize;
		ptr->final = final;

		i++;
		ptr++;
	}
	
	
	printf("Kayýt iþlemi tamamlandý \n");
}

void kayitListele (struct Ogrenci *ptr, int n)
{
	system("cls");
	int i = 0;
	while( i < n)
	{
		printf("%d.numaralý öðrenci bilgileri : \n",i+1);
		printf("Ad : %s\n",ptr->ad); 
		printf("Vize :%d\n",ptr->vize);
		printf("Final : %d\n",ptr->final); 
		printf("\n\n");	

		i++;
		ptr++;
	}
	
	
	printf("Listeleme iþlemi tamamlandý \n");
}
	
void kayitGuncelle(struct Ogrenci *ptr,int n)
{
	int numara;
	char ad[20];
	int vize;
	int i = 0;
	int final;
	printf("Kaydi güncellenecek öðrenci numarasý :"); scanf("%d",&numara);

	while( i < n )
	{
		int sonuc = 0;
		if(numara == ptr->numara)
		{
		printf("%d.numaralý öðrenci bilgilerini giriniz : \n",numara);
		printf("Ad :"); scanf("%s",ad);
		printf("Vize :"); scanf("%d",&vize);
		printf("Final :"); scanf("%d",&final);
		
		ptr->numara = numara;
		strcpy(ptr->ad,ad);
		ptr->vize = vize;
		ptr->final = final;
		sonuc = 1;
		break;
		}
		
		if( sonuc == 0)
		{
			printf("%d numaralý öðrenci listede yok",numara);
		}

		i++;
		ptr++;
	}
	
	
	printf("Kayýt iþlemi tamamlandý \n");
} 


void ortalamaHesapla (struct Ogrenci *ptr, int n)
{
	system("cls");
	int i = 0;
	int toplam = 0;
	int ortalama;
	int sonOrtalama;
	while( i<n )
	{
		
		ortalama = ptr->vize * 0.4 + ptr->final * 0.6;		
		toplam += ortalama;
		
		i++;
		ptr++;
	}
	sonOrtalama = toplam/n;
	printf("Sýnýf ortalamasý : %d\n",sonOrtalama);	
	printf("\n");
}

void enBasariliOgrenciyiBul (struct Ogrenci *ptr, int n)
{
	system("cls");
	int numara;
	char ad[20];
	int vize;
	int final;	
	int i = 0;
	int buyuk = 0;
	int ortalama;
	
	while( i<n )
	{
		ortalama = ptr->vize * 0.4 + ptr->final * 0.6;	
			
		if(buyuk < ortalama )
		{
			buyuk = ortalama;
			numara = ptr->numara;
			strcpy(ad , ptr->ad);
			ortalama = buyuk;
			}

		
		i++;
		ptr++;
	}
	printf("En baþarýlý öðrenci bilgileri : \n",i+1);
		printf("Numara : %d\n",numara); 
		printf("Ad :%s\n",ad);
		printf("Ortalama : %d\n",buyuk); 
		printf("\n\n");	
}
	
int menu()
{
	int secim;
	
	
	printf("1-Yeni kayýt ekleme \n");
	printf("2-Kayýt listeleme \n");
	printf("3-Kayýt listesi güncelleme\n");
	printf("4-Sýnýf ortalamasý hesaplama \n");
	printf("5-Ortalamaya göre en baþarýlý öðrenciyi göster \n");
	printf("0-Çýkýþ\n");
	printf("Seçiminiz : "); scanf("%d",&secim);
	return secim;
}



int main()
{
	setlocale(LC_ALL,"Turkish");
	int secim;
	int n;
	printf("Kaç öðrenci kayýt etmek istersiniz : "); scanf("%d",&n);
	
	struct Ogrenci *ogrPtr = (struct Ogrenci *)malloc(n * sizeof(struct Ogrenci));
	
	struct  Ogrenci *ptr = ogrPtr; 
	
	secim = menu();
	
	while(secim != 0)
	{
			if(secim == 1)
			yeniKayit(ptr, n);
			else if(secim == 2)
			kayitListele(ptr, n);
			else if(secim == 3)
			kayitGuncelle(ptr, n);
			else if( secim == 4)
			ortalamaHesapla(ptr, n);
			else if(secim == 5)
			enBasariliOgrenciyiBul(ptr, n);
			else if(secim == 0) 
			exit(0);
			else
			printf("Hatalý seçim yaptýnýz\n");
			secim = menu();
		
	}
	
	
	return 0;
}









