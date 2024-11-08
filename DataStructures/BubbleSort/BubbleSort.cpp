#include <iostream>
#include <algorithm>
#include <conio.h>
using namespace std;
void BubbleSort(int *sayilar, int uzunluk) {
int i,j,tmp;
bool swapped;
for (i = 0; i < uzunluk; i++) {
	swapped=false;
	for (j = 1; j < uzunluk; j++) {
		if (sayilar[j - 1] > sayilar[j]) {
			tmp=sayilar[j-1];
			sayilar[j-1]=sayilar[j];
			sayilar[j]=tmp;
			swapped=true;
        }
	}
	if(swapped==false){
       	break;
	}
  }
}
void print(int *sayilar,int uzunluk){
	for (int i = 0; i < uzunluk; i++) {
		    cout<<sayilar[i];
		    cout<<" "; 
       }
    cout<<endl;
}
int main(){
	int sayilar[] = {1,3,10,5,4,6,8,11,2};
	int uzunluk = sizeof(sayilar)/sizeof(int);
	print(sayilar,uzunluk);
	BubbleSort(sayilar,uzunluk);	
    print(sayilar,uzunluk);
    getch();
	return 0;
}