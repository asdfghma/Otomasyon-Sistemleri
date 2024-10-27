#include <stdio.h>
#include <stdlib.h>

struct musteri {
	int no;
	char ad[40];
	char urun[40];
	int ucret;
	char adres[80];
	struct musteri * next;
};

typedef struct musteri node;

node * ekle(node * head) {
	node *m1 = (node *)malloc(sizeof(node));
	printf("müsteri no : "); scanf("%d", &m1->no);
	printf("adi : "); scanf("%s", m1->ad);
	printf("urun : "); scanf("%s", m1->urun);
	printf("ucret : "); scanf("%d", &m1->ucret);
	printf("adres : "); scanf("%s", m1->adres);

	if (head == NULL) {
		head = m1;
		head->next = head;
		printf("liste olusturuldu musteri eklendi\n");
	} else {
		node *p = head;
		while (p->next != head) {
			p = p->next;
		}

		m1->next = head;
		head = m1;
		p->next = head;
		printf("listeye musteri eklendi\n");
	}
	return head;
}

node * sil(node * head) {
	int mNo;
	node *temp;
	if (head == NULL) {
		printf("liste bos \n");
	} else {
		printf("silinecek musteri no: "); scanf("%d", &mNo);
		if (head->next == head && head->no == mNo) {
			free(head);
			head = NULL;
			printf("listede kalan son musteride silindi");
		} else if (head->next != head && head->no == mNo) {
			temp = head;
			head = head->next;
			free(temp);
			printf("%d numarali musteri silindi \n", mNo);
		} else {
			node *p = head;
			node *q = head;
			while (p->next != head) {
				q = p;
				p = p->next;
				if (p->no == mNo) {
					q->next = p->next;
					free(p);
					printf("%d numarali musteri silindi \n", mNo);
					break;
				}
			}
			if (p->no == mNo) {
				q->next = p->next;
				free(p);
				printf("%d numarali musteri silindi \n", mNo);
			}
		}
	}
	return head;
}

node * yazdir(node * head) {
	if (head == NULL) {
		printf("liste bos \n");
	} else {
		node *p = head;
		do {
			printf("********************\n");
			printf("musteri no : %d adi : %s aldigi urun : %s ucreti : %d adres : %s \n", p->no, p->ad, p->urun, p->ucret, p->adres);
			p = p->next;
		} while (p != head);
	}
	return head;
}

node * ara(node * head) {
	if (head == NULL) {
		printf("liste boþ \n");
	} else {
		int mNo;
		printf("musteri no : "); scanf("%d", &mNo);
		node *p = head;
		while (p->next != head )
		{
			if( p->no==mNo)
			{
				printf("%d numarali musteri bilgileri : \n");
				printf("adi          :%s\n",p->ad);
		     	printf("urun          :%s\n",p->urun);
				printf("ucret          :%d\n",p->ucret);
				printf("adres          :%s\n",p->adres);

			}
			p= p->next;
		}
		if(p->no==mNo)
			{
				printf("%d numarali musteri bilgileri : \n");
				printf("adi          :%s\n",p->ad);
		     	printf("urun          :%s\n",p->urun);
				printf("ucret          :%d\n",p->ucret);
				printf("adres          :%s\n",p->adres);

			}
	
	}
	return head;
}
node * toplamgelir (node * head )
{
	int toplam=0;
	if(head==NULL)
	{
		printf("liste bostur \n");
	}
	else
	{
		node * p=head;
		while(p->next!=head)
		{
			toplam+= p->ucret;
			printf("toplam gelir : %d",toplam) ;
		}
	}
	
	
	
	return head;
}






int main()
{
	int secim;
	node * head=NULL;
	while(1)
	{
		printf("\ntek yonlu dairesel bagýl liste ile musteri takip uygulamasý\n");
		printf("1---ekle \n");
		printf("2---sil \n");
		printf("3---yazdir \n");
		printf("4---ara\n");
		printf("5---toplam gelir\n");
		printf("6---cikis \n");
	    printf("seciminizi yapin [0-5] \n");
	    scanf("%d",&secim);
	    switch(secim)
	    {
	    	case 1: head =ekle(head);
	    	break;
	    	case 2: head =sil(head);
	    	break;
	    	case 3: head =yazdir(head);
	    	break;
	    	case 4: head =ara(head);
	    	break;
	    	case 5: head =toplamgelir(head );
	    	break;
	    	case 0: exit(0);
	    	break;
	    	default : printf("hatali secim \n");
		}


	}
	return 0;
	
}
