#include <iostream>
#include <conio.h>
using namespace std;
int digitSum(int num){
	if(num<10)return num;
	return num%10+digitSum(num/10);
}
int main(){
	int sayi;
	cout<<"Rakamlarini toplamak istediginiz sayiyi giriniz."<<endl;
	cin>>sayi;
    cout<<"sonuc= "<<digitSum(sayi);
	getch();
	return 0;
}