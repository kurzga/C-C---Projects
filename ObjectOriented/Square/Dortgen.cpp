#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <locale>
#include <limits>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

class dortgen {
private:
    double uzunluk;
    double genislik;

public:
    dortgen(double uzunluk = 1, double genislik = 1) {
        this->uzunluk = uzunluk;
        this->genislik = genislik;
    }
    void Goster() const {
        wcout << L"Uzunluk: " << uzunluk << L", Genislik: " << genislik << std::endl;
        
        wcout << L"+";
        for (int i = 0; i < genislik - 2; ++i) {
            wcout << L"- ";
        }
        wcout << L"+\n";

        for (int i = 0; i < uzunluk - 2; ++i) {
            wcout << L"|";
            for (int j = 0; j < (genislik - 2) * 2; ++j) {
                wcout << L" ";
            }
            wcout << L"|\n";
        }

        wcout << L"+";
        for (int i = 0; i < genislik - 2; ++i) {
            wcout << L"- ";
        }
        wcout << L"+\n";

        wcout << L"Alan: " << Alan() << L", Cevre: " << Cevre() <<endl <<endl;
    }
    double getU() const {
        return uzunluk;
    }

    void setU(double uzunluk) {
        this->uzunluk = uzunluk;
    }

    double getG() const {
        return genislik;
    }

    void setG(double genislik) {
        this->genislik = genislik;
    }

    double Alan() const {
        return uzunluk * genislik;
    }

    double Cevre() const {
        return uzunluk * 2 + genislik * 2;
    }
};
void clearScreen() {
    system("cls");
}

void waitForKey() {
    wcout <<L"Bir tuşa basın...";
    _getwch();
}
vector<dortgen> dortgenListesi;

void dortgenEkle();
void dortgenListesiniKaydet();
void dortgenListesiniYukle();
void dortgenSil();
double girdiAl();
bool gecerliGiris();

int main() {
    setlocale(LC_ALL, "Turkish");

    dortgenListesiniYukle();

    while (true) {
        system("cls");
        wcout << L"menu:[Dörtgen Oluştur:1],[Göster:2],[Sil:3],[Kaydet:4],[Çıkış:5]";
        int cevap;
        cin >> cevap;

        if (cevap < 1 || cevap > 5) {
            wcout << L"Geçersiz giriş! Lütfen 1-5 arasında bir seçenek girin." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getch();
            continue;
        }

        switch (cevap) {
            case 1:
                dortgenEkle();
                break;

            case 2:
                if (dortgenListesi.empty()) {
                    wcout << L"dörtgen nesnesi oluşturulmadı. Lütfen önce bir dörtgen oluşturun." << endl;
                } else {
                    for (size_t i = 0; i < dortgenListesi.size(); ++i) {
            			wcout << L"dörtgen " << i + 1 << L":\n";
            			dortgenListesi[i].Goster();
            			waitForKey();
            			clearScreen();
       				   }
                }
                break;
                
            case 3:
                if (dortgenListesi.empty()) {
                    wcout << L"dörtgen nesnesi oluşturulmadı. Lütfen önce bir dörtgen oluşturun." << endl;
                } else {
                    dortgenSil();
                }
                break;

            case 4:
                dortgenListesiniKaydet();
                break;

            case 5:
            	dortgenListesiniKaydet();
                wcout << L"Programdan çıkılıyor." << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                exit(EXIT_SUCCESS);
        }

        wcout << L"Devam etmek için herhangi bir tuşa basın...";
        getch();
    }
    return 0;
}

void dortgenEkle() {
    double uzunluk, genislik;

    do {
        wcout << L"Uzunluğu giriniz:";
        uzunluk = girdiAl();
        wcout << L"Genişliği giriniz:";
        genislik = girdiAl();
    } while (!gecerliGiris());

    dortgenListesi.push_back(dortgen(uzunluk, genislik));
    wcout << L"dörtgen oluşturuldu" << endl;
}

bool gecerliGiris() {
    if (cin.fail()) {
        wcout << L"Hatalı giriş! Lütfen bir sayı girin." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

double girdiAl() {
    double girdi;
    cin >> girdi;
    return girdi;
}


void dortgenListesiniKaydet() {
    ofstream dosya("dortgen_listesi.txt");

    if (dosya.is_open()) {
        for (size_t i = 0; i < dortgenListesi.size(); ++i) {
            dosya << dortgenListesi[i].getU() << " " << dortgenListesi[i].getG() << "\n";
        }
        dosya.close();
        wcout << L"dörtgen listesi başarıyla kaydedildi." << endl;
    } else {
        wcerr << L"Dosya açma hatası!" << endl;
    }
}

void dortgenListesiniYukle() {
    ifstream dosya("dortgen_listesi.txt");

    dortgenListesi.clear();

    if (dosya.is_open()) {
        double uzunluk, genislik;
        while (dosya >> uzunluk >> genislik) {
            dortgenListesi.push_back(dortgen(uzunluk, genislik));
        }
        dosya.close();
        wcout << L"dörtgen listesi başarıyla yüklendi." << endl;
    } else {
        wcerr << L"Dosya açma hatası! Metin belgesi bulunamadı veya açılamadı." << endl;

        // Dosya oluşturulamıyorsa, kullanıcıya bilgi ver
        ofstream yeniDosya("dortgen_listesi.txt");
        if (!yeniDosya.is_open()) {
            wcerr << L"Dosya oluşturma hatası! Programın çalıştığı klasörde yazma izinleri olduğundan emin olun." << endl;
            wcerr << L"Programdan çıkılıyor." << endl;
            exit(EXIT_FAILURE);
        }

        wcout << L"Yeni bir dörtgen listesi dosyası oluşturuldu." << endl;
        yeniDosya.close();
    }
}

void dortgenSil() {
    if (dortgenListesi.empty()) {
        wcout << L"Silinecek dikdörtgen yok." << endl;
        return;
    }

    int silinecekNo;

    do {
        wcout << L"Silinecek dörtgenin numarasını girin (1-" << dortgenListesi.size() << L"): ";
        wstring girdi = L"";

        while (girdi.empty() || !isdigit(girdi[0])) {
            wcin >> girdi;
            if (girdi.empty() || !isdigit(girdi[0])) {
                wcout << L"Geçersiz giriş! Lütfen bir sayı girin." << endl;
            }
        }

        silinecekNo = stoi(girdi);

        if (silinecekNo < 1 || silinecekNo > dortgenListesi.size()) {
            wcout << L"Geçersiz dörtgen numarası! Lütfen 1 ile " << dortgenListesi.size() << L" arasında bir sayı girin." << endl;
        }
    } while (silinecekNo < 1 || silinecekNo > dortgenListesi.size());

    dortgenListesi.erase(dortgenListesi.begin() + silinecekNo - 1);
    wcout << L"dörtgen silindi." << endl;
}





    