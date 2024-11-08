#include <iostream>
#include <fstream>
#include <locale>
#include <conio.h>
#include <math.h>
#include <vector>
#include <chrono>
#include <thread>

const float pi = 3.14;
using namespace std;

class Point {
private:
    int x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    friend class Cember;
};

class Cember {
private:
    int radius;
    Point merkez;

public:
    Cember(int radius, int x, int y) {
        this->radius = radius;
        this->merkez.setX(x);
        this->merkez.setY(y);
    }

    int getR() const {
        return radius;
    }

    int getX() const {
        return merkez.getX();
    }

    int getY() const {
        return merkez.getY();
    }

    double cevre() const {
        return 2 * pi * radius;
    }

    double alan() const {
        return pi * pow(radius, 2);
    }

    double distance(const Point& point) const {
        double X = point.getX() - merkez.getX();
        double Y = point.getY() - merkez.getY();
        return sqrt(pow(X, 2) + pow(Y, 2));
    }

    void saveToFile(ofstream& outFile) const {
        outFile << radius << " " << merkez.getX() << " " << merkez.getY() << endl;
    }
    void draw() const {
        const int side = 2 * radius + 1;
        const int centerX = radius;
        const int centerY = radius;

        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                int dx = i - centerX;
                int dy = j - centerY;
                if (dx * dx + dy * dy <= radius * radius) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
};

void clearScreen() {
    system("cls");
}

void waitForKey() {
    wcout <<L"Bir tuşa basın...";
    _getwch();
}

void saveCembersToFile(const vector<Cember>& cembers, const string& filename) {
    ofstream outFile(filename);

    if (outFile.is_open()) {
        for (const auto& cember : cembers) {
            cember.saveToFile(outFile);
        }

        outFile.close();
        wcout <<L"Çemberler dosyaya kaydedildi.\n";
        wcout <<L"Programdan çıkılıyor...\n";
    } else {
        cerr << "Dosya açma hatası: " << filename << endl;
    }
}
void removeCember(vector<Cember>& cembers, int index) {
    if (index >= 0 && index < cembers.size()) {
        cembers.erase(cembers.begin() + index);
        wcout << L"Çember başarıyla silindi.\n";
    } else {
        wcout << L"Geçersiz çember indeksi!\n";
    }
}
void readCembersFromFile(vector<Cember>& cembers, const string& filename) {
    ifstream inFile(filename);

    if (inFile.is_open()) {
        int radius, x, y;
        while (inFile >> radius >> x >> y) {
            cembers.push_back(Cember(radius, x, y));
        }

        inFile.close();
        wcout <<L"Çemberler dosyadan okundu.\n";
    } else {
        cerr << "Dosya açma hatası: " << filename << endl;
    }
}

int main() {
    _wsetlocale(LC_ALL, L"Turkish");

    vector<Cember> cembers;
    Point p;

    int choice, x, y, yaricap;

    
    readCembersFromFile(cembers, "cembers.txt");

    do {
        clearScreen();
        wcout << L"Menu:\n";
        wcout << L"1. Çember Bilgilerini Göster\n";
        wcout << L"2. Uzaklık Hesapla\n";
        wcout << L"3. Noktayı Güncelle\n";
        wcout << L"4. Çember Girişi\n";
        wcout << L"5. Çember Sil\n";
        wcout << L"6. Çıkış\n";

        wcout << L"Seçiminizi yapın (1-6): ";
        while (!(wcin >> choice)) {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            wcout << L"Geçersiz giriş! Lütfen tekrar deneyin: ";
        }

        switch (choice) {
            case 1:
            	if (cembers.empty()) {
                    wcout << L"Çember bulunmamaktadır. Önce çember ekleyin.\n";
                    waitForKey();
                    break;
                }
                for (int i = 0; i < cembers.size(); i++) {
                    wcout << i + 1 << L". Çember: r - " << cembers[i].getR()
                          << L", x - " << cembers[i].getX() << L", y - " << cembers[i].getY() << endl;
                    wcout << L"Çember Çizimi:\n";
                	cembers[i].draw();
                	waitForKey();
                	clearScreen();
                }
                
                break;
            case 2:
                if (cembers.empty()) {
                    wcout << L"Çember bulunmamaktadır. Önce çember ekleyin.\n";
                    waitForKey();
                    break;
                }

                int cemberIndex;
                wcout << L"Çember indeksini girin (1-" << cembers.size() << L"): ";
                while (!(wcin >> cemberIndex) || cemberIndex < 1 || cemberIndex > cembers.size()) {
                    wcin.clear();
                    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    wcout << L"Geçersiz çember indeksi! Lütfen tekrar deneyin: ";
                }

                wcout << L"Uzaklık: " << cembers[cemberIndex - 1].distance(p) << endl;
                waitForKey();
                break;
            case 3:
                
                wcout << L"Nokta bilgileri\n---------------\n";
                wcout << L"Nokta x koordinatını girin:";
                while (!(wcin >> x)) {
                    wcin.clear();
                    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    wcout << L"Geçersiz giriş! Lütfen tekrar deneyin: ";
                }
                p.setX(x);

                wcout << L"Nokta y koordinatını girin:";
                while (!(wcin >> y)) {
                    wcin.clear();
                    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    wcout << L"Geçersiz giriş! Lütfen tekrar deneyin: ";
                }
                p.setY(y);
                break;
            case 4:
                
                wcout << L"Çember bilgileri\n---------------\n";
                wcout << L"Yarıçapı girin:";
                while (!(wcin >> yaricap) || yaricap <= 0)
 				{
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), '\n');
				wcout << L"Geçersiz giriş! Lütfen tekrar deneyin: ";
				}
                wcout << L"Merkezin x koordinatını girin:";
            while (!(wcin >> x)) {
                wcin.clear();
                wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                wcout << L"Geçersiz giriş! Lütfen tekrar deneyin: ";
            }

            wcout << L"Merkezin y koordinatını girin:";
            while (!(wcin >> y)) {
                wcin.clear();
                wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                wcout << L"Geçersiz giriş! Lütfen tekrar deneyin: ";
            }

            cembers.push_back(Cember(yaricap, x, y));
            break;
        case 5:
                
                if (cembers.empty()) {
                    wcout << L"Çember bulunmamaktadır. Önce çember ekleyin.\n";
                    waitForKey();
                    break;
                }

                int silinecekIndex;
                wcout << L"Silinecek çember indeksini girin (1-" << cembers.size() << L"): ";
                while (!(wcin >> silinecekIndex) || silinecekIndex < 1 || silinecekIndex > cembers.size()) {
                    wcin.clear();
                    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
                    wcout << L"Geçersiz çember indeksi! Lütfen tekrar deneyin: ";
                }

                
                removeCember(cembers, silinecekIndex - 1);
                waitForKey();
                break;
        case 6:
        	saveCembersToFile(cembers, "cembers.txt");
            this_thread::sleep_for(chrono::seconds(2));
            exit(EXIT_SUCCESS);
            break;
        default:
            wcout << L"Geçersiz seçim! Lütfen tekrar deneyin.\n";
            waitForKey();
    }

} while (choice != 6);
return 0;
}



