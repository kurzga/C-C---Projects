#include <conio.h>
#include <iostream>
#include <list>
using namespace std;

struct agac { 
int  kod;
 int  mal; 
};

class Acc { 
public: 
list<agac*>agaclistesi;
 list<Acc*>acclist; 
};

Acc * acc  = new Acc(); 
Acc * acc1 = new Acc(); 
Acc * acc2 = new Acc();

int al(Acc* acc){
 acc->agaclistesi.pop_back();
 cout<<acc->agaclistesi.size()<<endl;
}

int main ()
{ 
  agac * cam = new agac();
  agac * kavak = new agac();
  cam->kod=2;
  cam->mal=5;
  kavak->kod=9;
  kavak->mal=25;
  
  
  acc->agaclistesi.push_back(cam);
  acc->agaclistesi.push_back(kavak);
  acc->agaclistesi.push_back(cam);
  acc->agaclistesi.push_back(kavak);

  acc1->acclist.push_back(acc);
  acc1->acclist.push_back(acc);

  cout<<acc1->acclist.size()<<endl;
  cout<< acc1->acclist.front()->agaclistesi.size()<<endl;

  acc2=acc1->acclist.front();

  cout<<acc2->agaclistesi.size()<<endl;

  al(acc1->acclist.front());
  cout<<acc->agaclistesi.size()<<endl;

  al(acc);  cout<<"son"<<endl;

  getch();
  return 0;
}
