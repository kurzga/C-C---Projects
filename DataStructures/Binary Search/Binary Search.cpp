#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
int binarySearch(int A[],int ilk,int son,int x){
cout<<"binarySearch(ilk="<<ilk<<",son="<<son<<")"<<endl; 

if (ilk>son){
    return -1;
} 
int middle=(ilk+son)/2;
if (x==A[middle]){
//Eleman bulundu
return middle;//elemanın indeksi
}

else if (x <A[middle]){ 

return binarySearch(A,ilk,middle-1,x);//ortadan daha küçük

}
else{
return binarySearch(A,middle+1,son,x);//ortadan daha büyük
}
 
}
int main()
{
int A[]={1,3,5,6,8,11,23,45,67,89,99,111,122,134}; 
int N=sizeof(A)/sizeof(int);
int x=45;//dizide x'i arıyoruz
int find=binarySearch(A,0,N-1,x); 
if (find==-1){
cout<<"Eleman bulunamadi."<<endl;
}
else{
cout<<"Eleman bulundu.Sirasi:"<<find<<endl;
cout<<"A["<<find<<"]="<<A[find]<<endl; 
} 
getch();
return 0;
}
