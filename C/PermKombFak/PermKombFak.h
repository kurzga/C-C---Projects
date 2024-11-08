int fak(int sayi){
	int i = 1;
	int fak=1;
	for(i;i<=sayi;i++){
		fak = fak*i;
	}
	return fak;
}

int perm(int n,int r){
	int fark = n - r;
	n=fak(n);
	r=fak(fark);
	int perm = n/r;	
	return perm;
}
int komb(int n,int r){
	int fark = n-r;
	n=fak(n);
	fark=fak(fark);
	r = fak(r);
	int komb = n/(fark*r);
	return komb;
}