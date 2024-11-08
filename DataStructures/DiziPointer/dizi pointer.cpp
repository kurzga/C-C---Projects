#include <iostream>
#include <conio.h>
using namespace std;
int main(){
	int a[][3]={{100,200,300},
	           {400,500,600},
	           {700,800,900}
	       };
	int *p=a[0];
	p++;
	p++;
	p++;
	cout<<*p;
	getch();
	return 0;
}