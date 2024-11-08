#include <iostream>
#include <conio.h>
using namespace std;
int usal(int sayi ,unsigned int us){
	if(us == 0)
	return 1;
	else
	return usal(sayi,us-1)*sayi;
}
int usal2(int sayi,int us){
	int sonuc=1;
	for(int i =1;i<=us;i++){
		sonuc = sonuc*sayi;
	}
	return sonuc;
}
int main() {
	int sayi,us;
	cout<<"sayi:";
	cin>>sayi;
	cout<<"us:";
	cin>>us;
	cout<<"sonuc ="<<usal(sayi,us)<<endl;
	cout<<"sonuc ="<<usal2(sayi,us);
	getch();
	return 0;
}