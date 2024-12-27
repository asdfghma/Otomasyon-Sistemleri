import java.text.ParseException;
import java.util.Scanner;

public class Uygulama {

	public static void main(String[] args) throws ParseException {
		
		Scanner scanner = new Scanner(System.in);

		BagliListe liste = new BagliListe();
		int secim = -1;
		while ( secim != 0) {

			System.out.println("1- Otoparka araç girişi");
			System.out.println("2- Otoparktan araç çıkışı");
			System.out.println("3- Otoparktaki araçları listele");
			System.out.println("4- Toplam gelir");
			System.out.println("0- Çıkış");
			System.out.println("Seçiminiz: "); secim = scanner.nextInt();
			
			switch (secim) {
			case 1: liste.ekle(); break;
			case 2: liste.sil(); break;
			case 3: liste.yazdir(); break;
			case 4: System.out.println(liste.toplamUcret); break;
			case 0: System.out.println("Çıkış yaptınız..."); break;
			default : System.out.println("Hatalı seçim ! [0-4] "); break;

			}
		}
		
	}

}
