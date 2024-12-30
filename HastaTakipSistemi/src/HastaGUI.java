import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class HastaGUI extends JFrame {
    private HastaSistemi hastaSistemi;
    private JTextArea textArea;

    public HastaGUI() {
        hastaSistemi = new HastaSistemi();
        initUI();
    }

    private void initUI() {
        setTitle("Hastane Hasta Takip Sistemi");
        setSize(800, 600);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // Arka planda kullanılacak ikon
        ImageIcon backgroundImage = new ImageIcon("path_to_your_image.jpg");  // İkon resminizi buraya ekleyin

        // Panel oluşturma
        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                // Resmi panelin boyutlarına göre çiz
                g.drawImage(backgroundImage.getImage(), 0, 0, getWidth(), getHeight(), null);
            }
        };
        panel.setLayout(new BorderLayout());

        // Menü paneli
        JPanel menuPanel = new JPanel(new GridLayout(1, 7));
        menuPanel.setBackground(new Color(0, 51, 102)); // Menü paneli arka planını koyu mavi yap

        JButton btnEkle = new JButton("Hasta Ekle");
        JButton btnSil = new JButton("Hasta Sil");
        JButton btnGuncelle = new JButton("Hasta Güncelle");
        JButton btnSirala = new JButton("Hasta Sıralama");
        JButton btnSorgula = new JButton("Hasta Sorgulama");
        JButton btnGoruntule = new JButton("Hastaları Görüntüle");

        // Menü butonlarına tıklama işlemleri
        btnEkle.addActionListener(e -> hastaEkle());
        btnSil.addActionListener(e -> hastaSil());
        btnGuncelle.addActionListener(e -> hastaGuncelle());
        btnSirala.addActionListener(e -> hastaSirala());
        btnSorgula.addActionListener(e -> hastaSorgula());
        btnGoruntule.addActionListener(e -> hastalariGoruntule());

        menuPanel.add(btnEkle);
        menuPanel.add(btnSil);
        menuPanel.add(btnGuncelle);
        menuPanel.add(btnSirala);
        menuPanel.add(btnSorgula);
        menuPanel.add(btnGoruntule);

        panel.add(menuPanel, BorderLayout.NORTH);

        // Fontları güzelleştirme
        Font defaultFont = new Font("Arial", Font.PLAIN, 14);
        btnEkle.setFont(defaultFont);
        btnSil.setFont(defaultFont);
        btnGuncelle.setFont(defaultFont);
        btnSirala.setFont(defaultFont);
        btnSorgula.setFont(defaultFont);
        btnGoruntule.setFont(defaultFont);

        // Metin alanı
        textArea = new JTextArea();
        textArea.setFont(new Font("Arial", Font.PLAIN, 14)); // Metin fontunu değiştir
        textArea.setBackground(new Color(0, 51, 102)); // Text area'nın arka planını koyu mavi yap
        textArea.setForeground(Color.WHITE); // Yazı rengini beyaz yap
        JScrollPane scrollPane = new JScrollPane(textArea);
        panel.add(scrollPane, BorderLayout.CENTER);

        add(panel);
    }
    private void hastaEkle() {
        try {
            int hastaId = Integer.parseInt(JOptionPane.showInputDialog(this, "Hasta ID:"));
            String ad = getValidStringInput("Ad:");
            String soyad = getValidStringInput("Soyad:");
            String tedaviTuru = getValidStringInput("Tedavi Türü:");

            // Tarih seçimi için yeni bir panel oluşturulacak
            JPanel datePanel = new JPanel();
            datePanel.setLayout(new GridLayout(1, 3));

            // Gün, Ay, Yıl için combobox ekle
            JComboBox<String> dayComboBox = new JComboBox<>();
            for (int i = 1; i <= 31; i++) {
                dayComboBox.addItem(String.format("%02d", i)); // 01, 02, ..., 31 formatında
            }
            JComboBox<String> monthComboBox = new JComboBox<>();
            for (int i = 1; i <= 12; i++) {
                monthComboBox.addItem(String.format("%02d", i)); // 01, 02, ..., 12 formatında
            }
            JComboBox<String> yearComboBox = new JComboBox<>();
            for (int i = 1923; i <= 2100; i++) {
                yearComboBox.addItem(String.valueOf(i)); // 1923, 1924, ..., 2100
            }

            datePanel.add(new JLabel("Gün:"));
            datePanel.add(dayComboBox);
            datePanel.add(new JLabel("Ay:"));
            datePanel.add(monthComboBox);
            datePanel.add(new JLabel("Yıl:"));
            datePanel.add(yearComboBox);

            int option = JOptionPane.showConfirmDialog(this, datePanel, "Giriş Tarihi Seç", JOptionPane.OK_CANCEL_OPTION);
            if (option == JOptionPane.OK_OPTION) {
                String girisTarihi = dayComboBox.getSelectedItem() + "-" + monthComboBox.getSelectedItem() + "-" + yearComboBox.getSelectedItem();
                Hasta yeniHasta = new Hasta(hastaId, ad, soyad, tedaviTuru, girisTarihi);
                hastaSistemi.hastaEkle(yeniHasta);
                textArea.append("Hasta eklendi: " + yeniHasta + "\n");
            }

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Geçerli bir ID giriniz.");
        }
    }

    private void hastaSil() {
        try {
            int hastaId = Integer.parseInt(JOptionPane.showInputDialog(this, "Silinecek Hasta ID:"));
            hastaSistemi.hastaSil(hastaId);  // Hasta silme işlemi
            textArea.append("Hasta silindi: " + hastaId + "\n");
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Geçerli bir ID giriniz.", "ID", JOptionPane.WARNING_MESSAGE);
        }
    }


    private void hastaGuncelle() {
        try {
            int hastaId = Integer.parseInt(JOptionPane.showInputDialog(this, "Güncellenecek Hasta ID:"));
            String yeniAd = getValidStringInput("Yeni Ad:");
            String yeniSoyad = getValidStringInput("Yeni Soyad:");
            String yeniTedaviTuru = getValidStringInput("Yeni Tedavi Türü:");

            // Tarih seçimi için yeni bir panel oluşturulacak
            JPanel datePanel = new JPanel();
            datePanel.setLayout(new GridLayout(1, 3));

            // Gün, Ay, Yıl için combobox ekle
            JComboBox<String> dayComboBox = new JComboBox<>();
            for (int i = 1; i <= 31; i++) {
                dayComboBox.addItem(String.format("%02d", i)); // 01, 02, ..., 31 formatında
            }
            JComboBox<String> monthComboBox = new JComboBox<>();
            for (int i = 1; i <= 12; i++) {
                monthComboBox.addItem(String.format("%02d", i)); // 01, 02, ..., 12 formatında
            }
            JComboBox<String> yearComboBox = new JComboBox<>();
            for (int i = 1923; i <= 2100; i++) {
                yearComboBox.addItem(String.valueOf(i)); // 1923, 1924, ..., 2100
            }

            datePanel.add(new JLabel("Gün:"));
            datePanel.add(dayComboBox);
            datePanel.add(new JLabel("Ay:"));
            datePanel.add(monthComboBox);
            datePanel.add(new JLabel("Yıl:"));
            datePanel.add(yearComboBox);

            int option = JOptionPane.showConfirmDialog(this, datePanel, "Güncelleme Tarihi Seç", JOptionPane.OK_CANCEL_OPTION);
            if (option == JOptionPane.OK_OPTION) {
                String yeniGirisTarihi = dayComboBox.getSelectedItem() + "-" + monthComboBox.getSelectedItem() + "-" + yearComboBox.getSelectedItem();
                hastaSistemi.hastaGuncelle(hastaId, yeniAd, yeniSoyad, yeniTedaviTuru, yeniGirisTarihi);
                textArea.append("Hasta güncellendi: " + hastaId + "\n");
            }

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Geçerli bir ID giriniz.");
        }
    }

    private String getValidStringInput(String message) {
        String input;
        while (true) {
            input = JOptionPane.showInputDialog(this, message);
            if (input != null && input.matches("[a-zA-Z]+")) {  // Sadece harf kabul et
                return input;
            } else {
                JOptionPane.showMessageDialog(this, "Lütfen sadece harf giriniz.");
            }
        }
    }

    private void hastaSirala() {
        String kriter = JOptionPane.showInputDialog(this, "Sıralama Kriteri (ad/giris/tedavi):");
        if (kriter != null && !kriter.isEmpty()) {
            hastaSistemi.hastaSirala(kriter);
            List<Hasta> hastalar = hastaSistemi.getHastalar();
            textArea.setText(""); // Önceki içeriği temizle
            for (Hasta hasta : hastalar) {
                textArea.append(hasta + "\n");
            }
        } else {
            JOptionPane.showMessageDialog(this, "Geçerli bir kriter giriniz.");
        }
    }

    private void hastaSorgula() {
        String sorgu = JOptionPane.showInputDialog(this, "Sorgulamak istediğiniz ad veya ID:");
        if (sorgu != null && !sorgu.isEmpty()) {
            List<Hasta> sorguSonucu = hastaSistemi.hastaSorgula(sorgu);
            textArea.setText(""); // Önceki içeriği temizle
            for (Hasta hasta : sorguSonucu) {
                textArea.append(hasta + "\n");
            }
        } else {
            JOptionPane.showMessageDialog(this, "Geçerli bir sorgu giriniz.");
        }
    }

    private void hastalariGoruntule() {
        List<Hasta> hastalar = hastaSistemi.getHastalar();
        textArea.setText(""); // Önceki içeriği temizle
        for (Hasta hasta : hastalar) {
            textArea.append(hasta + "\n");
        }
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            HastaGUI gui = new HastaGUI();
            gui.setVisible(true);
        });
    }
}
