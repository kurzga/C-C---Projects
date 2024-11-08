#include <iostream>
#include <conio.h>
using namespace std;
double topla(double a, double b) {
 return a + b;
}
double carp(double a, double b) {
 return a*b;
}
double bol(double a, double b) {
 return a / b;
}
double cikar(double a, double b) {
 return a - b;
}
int main() {
 double a, b;
 char op = '*';
 cout << "1.Sayi Giriniz a= ";
 cin>>a;
 cout << "2.Sayi Giriniz b= ";
 cin>>b;
 cout << "Matematiksel Operatoru Giriniz +,*,/,- = ";
 cin>>op;
 cout << endl;
 switch (op) {
 case '+':
 cout << "a + b = " << topla(a, b) << endl;
 break;
 case '*':
 cout << "a * b = " << carp(a, b) << endl;
 break;
 case '/':
 cout << "a / b = " << bol(a, b) << endl;
 break;
 case '-':
 cout << "a - b = " << cikar(a, b) << endl;
 break;
 default:
 cout << "\t Hatalı seçim yaptınız!";
 break;
 }
 getch();
 return 0;
}
