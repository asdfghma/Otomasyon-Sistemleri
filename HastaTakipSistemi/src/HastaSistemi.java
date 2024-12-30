import java.io.*;
import java.util.*;

public class HastaSistemi {
	private List<Hasta> hastalar;
	private String dosyaYolu = "hasta.txt";
	
	public HastaSistemi() {
		hastalar = new ArrayList<>();
		dosyadanYukle();
		
	}
	
	private void dosyadanYukle() {
		try (BufferedReader reader = new BufferedReader(new FileReader(dosyaYolu))) {
			String satir;
			while ((satir = reader.readLine()) != null) {
				String[] veri = satir.split("\\|");
				int hastaId = Integer.parseInt(veri[0]);
				String ad = veri[1];
				String soyad = veri[2];
				String tedaviTuruString = veri[3];
				String girisTarihiString = veri[4];
				hastalar.add(new Hasta(hastaId, ad, soyad, tedaviTuruString, girisTarihiString));
				
			}
			
		} catch (IOException e) {
			System.out.println("Dosya okuma hatası: " + e.getMessage());
		}
	}
	
	private void dosyayaKaydet() {
		try (BufferedWriter writer = new  BufferedWriter(new FileWriter(dosyaYolu))) {
			for (Hasta hasta : hastalar) {
				writer.write(hasta.toString());
				writer.newLine();
			}
		} catch (IOException e) {
			System.out.println("Dosyaya yazma hatası: " + e.getMessage());
		}
	}
	
	
	public void hastaEkle(Hasta hasta) {
		hastalar.add(hasta);
		dosyayaKaydet();
	}
	
	public void hastaSil(int hastaId) {
		hastalar.removeIf(hasta -> hasta.getHastaId() == hastaId);
		dosyayaKaydet();
	}
	
    public void hastaGuncelle(int hastaId, String yeniAd, String yeniSoyad, String yeniTedaviTuru, String yeniGirisTarihi) {
    	
    	for (Hasta hasta : hastalar) {
    		if (hasta.getHastaId() == hastaId) {
    			hasta.setAd(yeniAd);
    			hasta.setAd(yeniSoyad);
    			hasta.setTedaviTuru(yeniTedaviTuru);
    			hasta.setGirisTarihi(yeniGirisTarihi);
    			break;
    		}
    	}
    	dosyayaKaydet();
    	
    }
    
    public void hastaSirala(String kriter) {
        switch (kriter.toLowerCase()) {
            case "ad":
                hastalar.sort(Comparator.comparing(Hasta::getAd));
                break;
            case "giris":
                hastalar.sort(Comparator.comparing(Hasta::getGirisTarihi));
                break;
            case "tedavi":
                hastalar.sort(Comparator.comparing(Hasta::getTedaviTuru));
                break;
            default:
                System.out.println("Geçersiz sıralama kriter.");
                return;
        }
        // Sıralama işlemi sonrası GUI'yi güncelleme işlevini burada yapmayacağız
    }

    
    
    public List<Hasta> hastaSorgula(String sorgu) {
        List<Hasta> sonuc = new ArrayList<>();
        for (Hasta hasta : hastalar) {
            if (hasta.getAd().contains(sorgu) || Integer.toString(hasta.getHastaId()).contains(sorgu)) {
                sonuc.add(hasta);
            }
        }
        return sonuc;
    }

    
    
    public List<Hasta> getHastalar() {
        return hastalar;
    }
    
    
    public void hastalariYazdir() {
    	for (Hasta hasta : hastalar) {
    		System.out.println(hasta);
    	}
    }
}
