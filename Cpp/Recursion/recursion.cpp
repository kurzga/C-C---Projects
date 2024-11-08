#include <iostream>
#include <conio.h>
using namespace std;
double fa(int);
double fb(int);

double fa(int n){
	if(n<=1){
		return 1;
	}
	else
	return n*fb(n-1);
}
double fb(int n){
	if(n<=1){
		return 1;
    }
	else
	return n*fa(n-1);
}
int main(){
	int f;
	cout<<"Type a number:";
	cin>>f;
	cout<<"Factorial a:"<<fa(f)<<endl;
	cout<<"Factorial b:"<<fb(f)<<endl;
	getch();
	return 0;
}