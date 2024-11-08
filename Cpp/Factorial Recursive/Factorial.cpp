#include <iostream>   
using namespace std;
double factorial(int n){
	if(n==0)
	return 1;
	
	else
	return(n*factorial(n-1));
}
int main(){
	int f;
	cout<<"Type a number:";
	cin >> f;
	cout<<"Factorial:"<<factorial(f);
	return 0;
}
