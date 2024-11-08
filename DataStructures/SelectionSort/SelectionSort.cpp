#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;
void print(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
	cout << arr[i] << " ";
	cout << endl;
}
void selection_sort(int a[],int N){
int i,j;
   for (i = 0; i < N-1; i++)
	{
	int jMin = i;//ilk eleman minimum olsun
	for (j = i+1; j < N; j++)//i'ye göre diziyi gez.(0,1),(0,2)..(0.N) (1,1),(1,2)...(1,N)...(N-1,N)
	{
		if (a[j] < a[jMin])//daha küçük sayı var mı?
		{
			jMin = j;//daha küçük sayı yeni minimum olsun.
			
		}
	}
	if (jMin != i)//daha küçük eleman bulunduysa değiştir.
	{
			swap(a[i], a[jMin]);
	}
		cout<<"i="<<i<<": ";
		print(a, N);
	}
}
int main(){
	int a[]={1,13,6,15,5,8,7,29,9,10};
	int N=sizeof(a)/sizeof(int);
	cout<<"Initial array:"<<endl;
	print(a,N);
	selection_sort(a,N);
	cout<<"\nSorted array:"<<endl;
	print(a,N);
	return 0;
}