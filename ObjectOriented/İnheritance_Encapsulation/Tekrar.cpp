#include <iostream>
#include <conio.h>
using namespace std;

class Dede {
protected:
    string soyad;

public:
    Dede() {
        cout << "Dede NT" << endl;
        soyad = "Albayrak";
    }

    string getSoyad() {
        return this->soyad;
    }

    void icecekSoyle() {
        cout << soyad << " dede ayran ismarladi" << endl;
    }
};

class Baba : public Dede {
protected:
    int tc;

public:
    Baba() {
        cout << "Baba NT" << endl;
        tc = 12345;
    }

    void ArabaSur() {
        cout << tc<<" tcli "<< soyad << " baba toros suruyor" << endl;
    }
	void icecekSoyle(){
		cout << soyad << " baba cay ismarladi" << endl;
	}
};
class Cocuk : public Baba{
	private:
		string heskodu;
	public:
	Cocuk(){
		cout << "Cocuk NT" << endl;
		heskodu="Ao48e23R";
		tc=45678;
	}
	void ArabaSur() {
        cout << tc<<" tcli "<<soyad << " cocuk toros suruyor" << endl;
    }
    void icecekSoyle(){
		cout << soyad << " cocuk kahve ismarladi" << endl;
	}
	void KodYaz() {
        cout <<heskodu<<" hes kodlu "<<tc<<" tcli "<<soyad << " cocuk kod yaziyor" << endl;
    }
};
int main() {
    Dede *d=new Dede();
    d->icecekSoyle();
    Baba *b= new Baba();
    b->ArabaSur();
    b->icecekSoyle();
    Cocuk *c=new Cocuk();
    c->ArabaSur();
    c->icecekSoyle();
    c->KodYaz();
    getch();
    return 0;
}
