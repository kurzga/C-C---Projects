#include <iostream>
#include <conio.h>
using namespace std;
int yaz(int sayi){
	if(sayi==0)
	return 0;
	else
	return sayi+yaz(sayi-1);
}
int main(){
	int sayi;
	cout<<"sayi:";
	cin>>sayi;
	cout<<"toplam:"<<yaz(sayi);
	getch();
	return 0;
}