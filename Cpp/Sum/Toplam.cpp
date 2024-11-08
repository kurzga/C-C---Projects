#include <iostream>
#include <conio.h>
using namespace std;
int toplam(int sayi){
	if(sayi==0)
	return 0;
	else
	return sayi+toplam(sayi-1);
}
int main(){
	int sayi;
	cout<<"sayi:";
	cin>>sayi;
	cout<<"toplam:"<<toplam(sayi);
	return 0;
}