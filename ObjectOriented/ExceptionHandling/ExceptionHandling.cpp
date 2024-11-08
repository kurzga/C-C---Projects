// typeid, polymorphic class
#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <conio.h>

using namespace std;


int main () {

  try {
         float x,y,z;
         cin>>x;
         cout<<endl;
         cin>>y;
         cout<<endl;
         if (y==0)
         throw 1;
         else{
         	 z=x/y;
         cout<<z<<endl<<endl;
		 }
}   catch(int a){
	if(a==1){
		cout<<"sifira bolme hatasi"<<endl;
	}
	else{
		cout<<"tanimlanamayan hata"<<endl;
	}
}
    
   getch();
  return 0;
}
