#include <iostream>
using namespace std;
void Degistir1(int *a){
	*a=100;
}
void Degistir2(int &b){
	b=200;
}
void Degistir3(int c){
	c=300;
}
int main(){
	int x =200;
	int *r =&x;
	Degistir1(r);
	Degistir2(x);
	Degistir3(x);
	cout<<x;
	return 0;
}