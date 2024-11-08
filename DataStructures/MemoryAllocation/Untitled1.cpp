#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
int main(){
	srand((unsigned) time(NULL));
	float* ptr=(float*)malloc(5 * sizeof(float));
    if(!ptr){
    	cout<<"Bellek Ayirma Basarisiz";
    	exit(1);
	}
	cout<<"Degerler baslatiliyor......\n\n";
	for(int i =0;i<5;i++){
		ptr[i]=rand();
	}
	cout<<"Baslatilan Degerler\n\n";
	for(int i =0;i<5;i++){
		//ptr[i] ve *(ptr+i) birbirinin yerine kullanılabilir.
		cout<<ptr[i]<<endl;
	}
	cout<<endl;
	for(int i =0;i<5;i++){
		//ptr[i] ve *(ptr+i) birbirinin yerine kullanılabilir.
		cout<<*(ptr+i)<<endl;
	}
	
	free(ptr);
	getch();
	return 0;
}