import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		HastaSistemi hastaSistemi = new HastaSistemi();
		Scanner scanner = new Scanner(System.in);
		int secim;
		
		do {
            System.out.println("\n--- Hastane Hasta Takip Sistemi ---");
            System.out.println("1. Hasta Ekle");
            System.out.println("2. Hasta Sil");
            System.out.println("3. Hasta Güncelle");
            System.out.println("4. Hasta Sıralama");
            System.out.println("5. Hasta Sorgulama");
            System.out.println("6. Hastaları Görüntüle");
            System.out.println("0. Çıkış");
            System.out.print("Seçiminiz: ");	
            secim = scanner.nextInt();
            
            
            switch (secim) {
            
            case 1:            	
            	System.out.println("Hasta ID: ");
            	int hastaId = scanner.nextInt();
            	scanner.nextLine();
            	System.out.println("Ad: ");
            	String ad = scanner.nextLine();
            	System.out.println("Soyad: ");
            	String soyad = scanner.nextLine();
            	System.out.println("Tedavi Türü: ");
            	String tedaviTuru = scanner.nextLine();
            	System.out.println("Giriş Tarihi (yıl-ay-gün): ");
            	String girisTarihi = scanner.nextLine();
            	Hasta yeniHasta = new Hasta(hastaId, ad, soyad, tedaviTuru, girisTarihi);
            	hastaSistemi.hastaEkle(yeniHasta);
            	break;
            	
            case 2:            	
            	System.out.println("Silinecek Hasta ID: ");
            	int silinecekId = scanner.nextInt();
            	hastaSistemi.hastaSil(silinecekId);
            	break;
            	
            case 3:            	
            	System.out.println("Güncellenecek Hasta ID: ");
            	int guncellencekId = scanner.nextInt();
            	scanner.nextLine();
            	System.out.println("Yeni Ad: ");
            	String yeniAd = scanner.nextLine();
            	System.out.println("Yeni Soyad: ");
            	String yeniSoyad = scanner.nextLine();
            	System.out.println("Yeni Tedavi Türü: ");
            	String yeniTedaviTuru = scanner.nextLine();
            	System.out.println("Yeni Giriş Tarihi (yıl-ay-gün): ");
            	String yeniGirisTarihi = scanner.nextLine();
            	hastaSistemi.hastaGuncelle(guncellencekId, yeniAd, yeniSoyad, yeniTedaviTuru, yeniGirisTarihi);
            	break;
            	
            case 4:            	
            	System.out.println("Sıralama Kriteri (ad/giris/tedavi): ");
            	String kriter = scanner.next();
            	hastaSistemi.hastaSirala(kriter);
            	break;
            	
            case 5:            	
            	System.out.println("Sorgulamak istediğiniz ad veya ID: ");
            	String sorgu = scanner.next();
            	hastaSistemi.hastaSorgula(sorgu);
            	break;    
            	
            case 6:
            	hastaSistemi.hastalariYazdir();
            	break;
            	
            case 0:
            	System.out.println("Çıkılıyor...");
            	break;
            	
            default:
            	System.out.println("Geçersiz seçenek");
            	break;
            	
            	}
            
            } while (secim != 0);
		
			scanner.close();
	} 

}