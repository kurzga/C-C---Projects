#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int* p;
	int dizi[5]={1,2,3,4,5};
	p = dizi;
	cout<<p<<endl;
	p++;
	cout<<p<<endl;
	p++;
	cout<<p<<endl;
	p++;
	cout<<p<<endl;
	p++;
	cout<<p<<endl;
	p++;
	*p=10;
	cout<<p<<endl;
	for(int i;i<6;i++){
		cout<<dizi[i]<<endl;
	}
	getch();
	return 0;
}