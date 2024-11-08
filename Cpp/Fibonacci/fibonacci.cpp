#include <iostream>
#include <conio.h>
using namespace std;
void fibonacci(int n){
	
	float toplam[n];
	toplam[0]=0;
	toplam[1]=1;
	for(int i =2;i<n;i++){
	    toplam[i]=toplam[i-2]+toplam[i-1];
	}
    for(int a=0;a<n;a++){
    	cout<<toplam[a]<<"\t";
	}
}
float fibonacci2(float n){
    if(n<=1){
    return n;
	}
	return fibonacci2(n-1)+fibonacci2(n-2);
}
int main(){
	int n;
	cout<<"Fibonacci eleman sayisi:";
	cin>>n;
	fibonacci(n);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<fibonacci2(i)<<"\t";
	}
	getch();
	return 0;
}