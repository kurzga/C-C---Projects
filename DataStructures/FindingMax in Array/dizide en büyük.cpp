#include <iostream>
#include <conio.h>
using namespace std;
void dizisirala(int dizi[],int siralidizi[]){
	for (int i = 0; i < 10; i++) {
        int minIndex = i;

        for (int j = i + 1; j < 10; j++) {
            if (dizi[j] < dizi[minIndex]) {
                minIndex = j;
            }
        }

        int temp = dizi[i];
        dizi[i] = dizi[minIndex];
        dizi[minIndex] = temp;
        siralidizi[i] = dizi[i];
    }
}
int main() {
    int dizi[10] = {10, 23, 67, 2, 4, 18, 79, 64, 1, 7};
    int siralidizi[10];
    cout << "Siralanmamis Dizi:"<<endl;
    for (int a = 0; a < 10; a++) {
        cout << dizi[a] <<"\t";
    }
    cout<<endl;
    dizisirala(dizi,siralidizi);
    cout << "Sirali Dizi:"<<endl;
    for (int a = 0; a < 10; a++) {
        cout << siralidizi[a] <<"\t";
    }
    cout << "\nEn Buyuk Eleman: " <<endl<< siralidizi[9] << endl;
    getch();
    return 0;
}
