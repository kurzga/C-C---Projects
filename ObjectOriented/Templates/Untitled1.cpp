#include <iostream>
#include <conio.h>
using namespace std;

template <class T, class U>
 class Dortgen {
   T x;
   U y;

public:
void DegerVer(T,U);
U Alan (void);
};

template <class T, class U>
void Dortgen<T,U>::DegerVer(T a, U b) {
x = a;
y = b;
}

template <class T, class U>
U Dortgen<T,U>::Alan (void) {
 return x*y;

}
int main ()
{
Dortgen <int,float>D1;
Dortgen <int,float>D2;

D1.DegerVer(4,3.1);
D2.DegerVer(7.4,2.5);

cout << "Alan1: " << D1.Alan()<<'\n';
cout << "Alan2: " << D2.Alan()<<endl;
return 0;
}
