import java.io.Serializable;

public class Hasta implements Serializable{
	private int hastaId;
	private String ad;
	private String soyad;
	private String tedaviTuru;
	private String girisTarihi;
	
	
	public Hasta(int hastaId, String ad, String soyad, String tedaviTuru, String girisTarihi)
	{
		this.hastaId = hastaId;
		this.ad = ad;
		this.soyad = soyad;
		this.tedaviTuru = tedaviTuru;
		this.girisTarihi = girisTarihi;
	}
	
	// Getter ve Setter metodları
	public int getHastaId() {
		return hastaId;
	}
	
	public void setHastaId(int hastaId) {
		this.hastaId = hastaId;
	}
	
	public String getAd() {
		return ad;
	}
	
	public void setAd(String ad) {
		this.ad = ad;
	}
	
	
	public String getSoyad() {
		return soyad;
	}
	
	public void setSoyad(String soyad) {
		this.soyad = soyad;
	}
	
	public String getTedaviTuru() {
		return tedaviTuru;
	}
	
	public void setTedaviTuru(String tedaviTuru) {
		this.tedaviTuru = tedaviTuru;
	}
	
	public String getGirisTarihi() {
		return girisTarihi;
	}
	
	public void setGirisTarihi(String girisTarihi) {
		this.girisTarihi = girisTarihi;
	}
	
	@Override
	public String toString() {
        return hastaId + "|" + ad + "|" + soyad + "|" + tedaviTuru + "|" + girisTarihi;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	

}
