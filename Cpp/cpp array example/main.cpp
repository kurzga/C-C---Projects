#include<iostream>
#include "header.hpp"
#include <conio.h>
using namespace std;
int main()
{
 
 double dizi[]={12, 3, 4, 15};
 int n = sizeof(dizi) / sizeof(dizi[0]);
 cout<<"Dizi Elemanlari=";
 print(dizi,n); cout<<endl;
 cout<<"Toplam ="<< toplam(dizi,n)<<endl;
 cout<<"Ortalama ="<< ortalama(dizi,n)<<endl;
 getch();
 return 0;
}
