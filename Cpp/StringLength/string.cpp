#include <iostream>
#include <string.h>
using namespace std;
int abc(string str){
	if(str[0]=='\0'){
		return 0;
	}
	return abc(str.substr(1))+1;
}
int main(){
	string kelime ="Ahmet";
	cout<<abc(kelime);
}