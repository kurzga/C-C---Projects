#include <cstdio>
#include <ctime>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

class konum{
     public:
     int x,y;
     konum(){
        x=0;
        y=0;
     }
};
class Karakter {
    private:
    int ID,money,food,water,power;    
    public:
      bool sleep;
      konum k;
      int stamina;
      Karakter(){
        srand(time(0));
        ID=1+ (rand() % 10);
        money=0;
        food=100;
        water=100;
        power=1+(rand() % 10);
        stamina=100;
        sleep=false;
        k.x=0;
        k.y=0;
        }
    int getmoney(){
        return money;
    }
    void setmoney(int value){
        money=value;
    }
    int getfood(){
        return food;
    }
    int getwater(){
        return water;
    }
    void paraGonder(int value,Karakter k){
        money=money-value;
        k.money+=value;
    }
    void paraAl(int value,Karakter k){
        money=money+value;
        k.money-=value;
    }
    void doyur(int value){
         food+=value;
         cout<<"yemek yedi"<<endl;
    }
    void suic(int value){
         water+=value;
         cout<<"su icti"<<endl;
    }
    void acikma(int saniye){
        food=food-0.0001*saniye;
    }
    void susama(int saniye){
        water=water-0.0001*saniye;
    }
    void energy(int saniye){
        stamina=stamina+1*saniye;
    }
};
int main() {
Karakter yolcu1,yolcu2;
while (true)
{
if(yolcu1.getfood()<50){
    cout<<"aciktiniz su kadar toksunuz"<<yolcu1.getfood()<<endl;
}
if(yolcu1.getwater()<50){
    cout<<"susadiniz su kadar sulusunuz"<<yolcu1.getwater()<<endl;
}
auto start = chrono::steady_clock::now();
cout << "w:ileri,s:geri,a:sol,d:sag,i:Suic,y:yemek,g:paraVer,t:paraAl,c:cikis";
char c;
cin >> c;
chrono::nanoseconds elapsed_ns = chrono::steady_clock::now() - start;
float saniye=elapsed_ns.count()/1000000000;
yolcu1.acikma(saniye);
yolcu1.susama(saniye);
yolcu1.energy(saniye);

cout<<"Saniye:"<<saniye<<endl;
switch (c)
{
case 'w':
yolcu1.k.y+=1;
cout<<"ileri gitti yolcu konum:("<<yolcu1.k.x<<","<<yolcu1.k.y<<")"<<endl;
    yolcu1.stamina=yolcu1.stamina-10;
    if(yolcu1.stamina<=0){
	cout<<"stamina sifir hareket edemezsiniz."<<endl;
	break;
	}
    cout<<"Kalan stamina"<<yolcu1.stamina<<endl;
    break;
case 's':
yolcu1.k.y-=1;
cout<<"Geri gitti yolcu konum:("<<yolcu1.k.x<<","<<yolcu1.k.y<<")"<<endl;
yolcu1.stamina=yolcu1.stamina-10;
      if(yolcu1.stamina<=0){
	cout<<"stamina sifir hareket edemezsiniz."<<endl;
	break;
}
cout<<"Kalan stamina"<<yolcu1.stamina<<endl;
    break;
case 'a':
yolcu1.k.x-=1;
cout<<"Sola gitti yolcu konum:("<<yolcu1.k.x<<","<<yolcu1.k.y<<")"<<endl;
yolcu1.stamina=yolcu1.stamina-10;
if(yolcu1.stamina<=0){
	cout<<"stamina sifir hareket edemezsiniz."<<endl;
	break;
}
cout<<"Kalan stamina"<<yolcu1.stamina<<endl;
    break;    
case 'd':
yolcu1.k.x+=1;
cout<<"Sağa gitti yolcu konum:("<<yolcu1.k.x<<","<<yolcu1.k.y<<")"<<endl;
yolcu1.stamina=yolcu1.stamina-10;
if(yolcu1.stamina<=0){
	cout<<"stamina sifir hareket edemezsiniz."<<endl;
	break;
}
cout<<"Kalan stamina"<<yolcu1.stamina<<endl;
    break;
case 'i':
cout<<"icilecek su miktari:"<<endl;
int su;
cin>>su;
yolcu1.suic(su);
cout<<"sululuk durumu"<<yolcu1.getwater()<<endl;
    break;
case 'y':
cout<<"yenilecek yemek miktari:"<<endl;
int yemek;
cin>>yemek;
yolcu1.doyur(yemek);
cout<<"tokluk durumu"<<yolcu1.getfood()<<endl;
    break;        
case 'g':

int verilecekpara;
cout<<"Verilecekl para miktari:"<<endl;
cin>>verilecekpara;
yolcu1.paraGonder(verilecekpara,yolcu2);
cout<<"para yolcu1:"<<yolcu1.getmoney()<<endl;
cout<<"para yolcu2:"<<yolcu2.getmoney()<<endl;
    break;
case 't':

int alinacakpara;
cout<<"Alinacak para miktari:"<<endl;
cin>>alinacakpara;
yolcu1.paraAl(alinacakpara,yolcu2);
cout<<"para yolcu1:"<<yolcu1.getmoney()<<endl;
cout<<"para yolcu2:"<<yolcu2.getmoney()<<endl;
    break;    
case 'c':
    cout<<"cikiliyor."<<endl;
    Sleep(2);
    exit(1);
    break;
default:
cout<<"eksik ya da yanlis girdiniz."<<endl;
    break;
}
}
}