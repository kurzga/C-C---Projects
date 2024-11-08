#include <iostream>
#include <conio.h>
using namespace std;
int OddEven(int num){
	if(num % 2==0){
		return 0;
	}
	else{
		return 1;
	}	
}
int collatz(int num){
	int isOdd=OddEven(num);
	cout<<"num: "<<num<<endl;
	if(isOdd==0){
		num = num/2;
	}
	if(isOdd==1){
		num = 3*num+1;
	}
	if(num==1){
		cout<<"num: "<<num<<endl;
		return 0;
	}
	return collatz(num);
	
}
int main(){
    	collatz(100);
    	cout<<endl<<endl;
	return 0;
}