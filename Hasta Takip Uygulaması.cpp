#include <stdio.h>
#include <stdlib.h>

struct Hasta{
	int no;
	char ad[20];
	int yas;
	char hastalik[20];
};

struct Hasta bosHasta = { 0, "", 0,""};
struct Hasta kisi;

FILE *ptr;

void listeOlustur()
{
	if((ptr = fopen("hastaKayit.dat","w")) != NULL)
	{
		for(int i = 0; i < 100; i++)
		{
			fwrite (&bosHasta,sizeof(struct Hasta),1,ptr);
		}
		printf("100 hasta kaydi icin gerekli yer ayarlandi\n");
		fclose(ptr);
	}
}

void ekle()
{
	if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
	{
		int hastaID;
		printf("Hasta no :"); scanf("%d",&hastaID);
		fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
		fread (&kisi,sizeof(struct Hasta),1,ptr);
		if(hastaID < 1 || hastaID > 100){
		printf("Hasta numarasi 1 ile 100 arasinda olmali!\n");}
		else
		{
			fseek(ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET );
			fread (&kisi,sizeof(struct Hasta),1,ptr);
			if(kisi.no != 0)
			{
				printf("%d numarali hasta mevcut\n",hastaID);
			}
			else 
		{
			printf("Ad/ Yas/ Hastalik :" ); scanf("%19s%d%19s",kisi.ad,&kisi.yas,kisi.hastalik);
			kisi.no = hastaID;
			fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
			fwrite (&kisi,sizeof(struct Hasta),1,ptr);
			printf("Hasta kayit edildi \n");
			}
		}
		fclose(ptr);
	}
}

void sil()
{
	if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
	{
		int hastaID;
		printf("Silinecek no :"); scanf("%d",&hastaID);
		fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
		fread (&kisi,sizeof(struct Hasta),1,ptr);
		if(kisi.no == 0)
		{
			printf("%d numarali kayýtlý hasta mevcut degil\n",hastaID);
		}
		else
		{
			fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
			fwrite (&bosHasta,sizeof(struct Hasta),1,ptr);
			printf("Hasta kayidi silindi \n");
		}
		fclose(ptr);
	}
}

void guncelle()
{
	system("cls");
	if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
	{
		int hastaID;
		printf("Guncellenecek hasta no :"); scanf("%d",&hastaID);
		fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
		fread (&kisi,sizeof(struct Hasta),1,ptr);
		if(kisi.no == 0)
		{
			printf("%d numarali kayýtlý hasta mevcut degil\n",hastaID);
		}
		else
		{
			printf("%d numarali hasta bilgileri : \n", hastaID);
			printf("Ad : %s\n",kisi.ad);
			printf("Yas : %d\n",kisi.yas);
			printf("Hastalik : %s\n",kisi.hastalik);
			
			printf("Ad/ Yas/ Hastalik :" ); scanf("%19s%d%19s",kisi.ad,&kisi.yas,kisi.hastalik);
			kisi.no = hastaID;
			fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
			fwrite (&kisi,sizeof(struct Hasta),1,ptr);
			printf("Guncelleme yapildi \n");
		}
		fclose(ptr);
	}
}

void hastaAra()
{
	system("cls");
	if((ptr = fopen("hastaKayit.dat","r")) != NULL)
	{
		int hastaID;
		printf("Aranan hasta no :"); scanf("%d",&hastaID);
		fseek (ptr,(hastaID - 1 ) * sizeof(struct Hasta),SEEK_SET);
		fread (&kisi,sizeof(struct Hasta),1,ptr);
		if(kisi.no == 0)
		{
			printf("%d numarali kayitli hasta mevcut degil\n",hastaID);
		}
		else
		{
			printf("%d numarali hasta bilgileri : \n", hastaID);
			printf("Ad : %s\n",kisi.ad);
			printf("Yas : %d\n",kisi.yas);
			printf("Hastalik : %s\n",kisi.hastalik);
		}
		fclose(ptr);
	}
}

void yazdir()
{
	system("cls");
	if((ptr = fopen("hastaKayit.dat","r")) != NULL)
	{
		printf("NUMARA\tAD\tYAS\tHASTALIK\n");
		while(fread (&kisi,sizeof(struct Hasta),1,ptr))
		{
			if(kisi.no != 0)
			{
				printf("%d\t%s\t%d\t%s\n",kisi.no,kisi.ad,kisi.yas,kisi.hastalik);
			}
		}
		fclose(ptr);
	}
}

int main()
{
	int secim = -1;
	while(secim != 0)
	{
		printf("\n1-ekle \n");
		printf("2-sil \n");
		printf("3-guncelle \n");
		printf("4-ara \n");
		printf("5-yazdir \n");
		printf("6-kayit listesi olustur (resetle) \n");
		printf("0-cikis \n");
		printf("Seciminiz :"); scanf("%d",&secim);
		
		switch(secim)
		{
			case 1: ekle(); break;
			case 2: sil(); break;
			case 3: guncelle(); break;
			case 4: hastaAra(); break;
			case 5: yazdir(); break;
			case 6: listeOlustur(); break;
			case 0: printf("Cikis yaptiniz...\n"); break;
			default : printf("Hatali secim yaptiniz.\n");
		}
	}
	return 0;
}

