#include <stdio.h>
#include <conio.h>
int sayi_kontrol(int sayi) {
  if (sayi == (int)sayi)
  {
  	return sayi;
  }
}

void main() {
  int sayi;
  printf("Lutfen bir sayi girin: ");
  scanf("%d", &sayi);
 
  if (sayi_kontrol(sayi)) {
    printf("Girdiginiz deger sayidir.\n");
  } else {
    printf("Girdiginiz deger sayi degildir.\n");
  }
  getch();
}



