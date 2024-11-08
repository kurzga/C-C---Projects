#include <iostream>
#include <conio.h>
using namespace std;
void Boyutarttir(int dizi[]){
	int length = 5;
	int diziTemp[2*length];
	for (int i=0;i<2*length;i++){
		diziTemp[i]=dizi[i];
	}
	dizi = diziTemp;
}
void print(int arr[]){
	int uzunluk = 10;
	cout<<"dizi:"<<" ";
	for(int i=0;i<uzunluk;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int diz[]={1,2,3,4,5};
	int uzunluk = 10;
	print(diz);
	Boyutarttir(diz);
	for(int a=5;a<uzunluk;a++){
		diz[a]=a+1;
	}
	return 0;
}