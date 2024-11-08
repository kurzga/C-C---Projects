#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PermKombFak.h"
void main(){
	srand(time(NULL));
	int i,j,islem,secim,deger;
	int sayilar[100];
	int rastgele[100];
	int sonuclar[100];
    for(i = 0; i < 10 ; i++)
    {
	    sayilar[i] = rand() % 10 + 1;
    }
    printf("0 ile 9 arasinda bir sayi giriniz:");
    scanf("%d",&secim);
    printf("Rastgele sayi = %d\n",sayilar[secim]);
    A:
    printf("Kombinasyon veya permutasyon icin deger giriniz:");
    scanf("%d",&deger);
    if(deger > sayilar[secim]){
    	printf("Deger sayidan buyuk olamaz.\n");
    	printf("Lutfen tekrar giriniz.\n");
    	goto A;
	}

	    while(1){
    	printf("islem seciniz(1:Kombinasyon,2:Faktoriyel,3:Permutasyon,4:Cikis)");
    	scanf("%d",&islem);
	    switch(islem){
	    	case 1:
	    		printf("c(%d,%d) = %d\n",sayilar[secim],deger,komb(sayilar[secim],deger));
	    	break;
	    	case 2:	
	    	    printf("%d sayısının faktoriyeli = %d\n",sayilar[secim],fak(sayilar[secim]));
	    	break;
	    	case 3:
	    	    printf("p(%d,%d) = %d\n",sayilar[secim],deger,perm(sayilar[secim],deger));
	    	break;
	    	case 4:
	    		exit(1);
	    	default:
	    		printf("Eksik ya da yanlis tusladiniz.\n");
	    	break;
		}
		
	}
}