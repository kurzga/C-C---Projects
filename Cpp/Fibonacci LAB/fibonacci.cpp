#include <iostream>
#include <conio.h>
using  namespace std;
int fib(int n){
if(n<=1)
return n;
else
return (fib(n-1)+fib(n-2));
}

int fibo(int n) {
if (n <= 1)
return n;
int fib0 = 0;
int fib1 = 1;
int x=0;
for (int i = 2; i <= n; ++i) {
x = fib0;
fib0 = fib1;
fib1 = x + fib0;
}
return fib1;
}

int main() {
	int num;
    cout << "Bir sayi giriniz: ";
    cin>>num;
	cout << "Girilen sayi=" << num << endl;
	cout << "fibonacci serisi = " << fib(num);
	getch();
	return 0;
}