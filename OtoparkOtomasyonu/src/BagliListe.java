import java.awt.image.DataBufferByte;
import java.sql.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class BagliListe {

	Scanner scanner = new Scanner(System.in);
	
	OtoNode head = null;
	OtoNode tail = null;
	OtoNode temp = head;
	OtoNode temp2 = temp;
	
	String plaka;
	String giris;
	String cikis;
	long dakika;
	long ucret;
	long toplamUcret = 0;
	
	void ekle()
	{
		System.out.print("Plaka: "); plaka = scanner.nextLine();
		System.out.print("Giriş (SS:DK): "); giris = scanner.nextLine();
		
		OtoNode arac = new OtoNode(plaka, giris);
		
		if (head == null) {
			head = arac;
			tail = arac;
			
			head.next = tail;
			tail.prev = head;
			head.prev = tail;
			tail.next = head;
			System.out.println("Araç otoparka girdi.");
		}
		else
		{
			arac.next = head;
			head.prev = arac;
			head = arac;
			
			head.prev = tail;
			tail.next = head;
			System.out.println("Araç otoparka girdi.");			
		}
	}
	
	
    void sil() throws ParseException {
        if (head == null) {
            System.out.println("Otopark boş");
        } else {
            System.out.print("Plaka: "); 
            plaka = scanner.nextLine(); 
            System.out.print("Çıkış (SS:DK): "); 
            cikis = scanner.nextLine();  

            if (head.plaka.equals(plaka)) {  
                ucretHesapla(head, cikis); 
                if (head == tail) {  
                    head = null;
                    tail = null;
                } else {
                    head = head.next; 
                    head.prev = tail;
                    tail.next = head;
                }
                System.out.println("Araç çıkışı yapıldı.");
            } else {
                OtoNode temp = head;
                while (temp != null && !temp.plaka.equals(plaka)) {
                    temp = temp.next;  
                }
                if (temp != null) {  
                    ucretHesapla(temp, cikis);
                    if (temp == tail) {  
                        tail = temp.prev;
                        tail.next = head;
                        head.prev = tail;
                    } else {  
                        temp.prev.next = temp.next;
                        temp.next.prev = temp.prev;
                    }
                    System.out.println("Araç çıkışı yapıldı.");
                } else {
                    System.out.println("Araç bulunamadı.");
                }
            }
        }
    }

	 void ucretHesapla(OtoNode temp3, String cikis2)  throws ParseException {
		 
		 giris = temp3.giris;
		 SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
		
		 
		java.util.Date d1;
		java.util.Date d2;
		 d1 = sdf.parse(giris);
		 d2 = sdf.parse(cikis2);
		 
		 dakika = d2.getTime() - d1.getTime();
		 dakika = dakika/60000;
		 ucret  = dakika / 4;
		 System.out.print("Süre: " + dakika + " dk ");
		 System.out.println("Ücret: " + ucret + " TL");
		 toplamUcret += ucret;
	}
	
	 
	 void yazdir()
	 {
		 if (head == null) {
			System.out.println("Otoparkta araç yok");
		}
		 else {
			 System.out.println("Plaka\t\tGiriş Saati");
			temp = head;
			while (temp != tail) {
				System.out.println(temp.plaka + "\t\t" + temp.giris);
			}
			System.out.println(temp.plaka + "\t\t" + temp.giris + "\n");			
		}
	 }
}