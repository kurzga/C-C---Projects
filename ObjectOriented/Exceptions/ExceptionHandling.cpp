// typeid, polymorphic class
#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <conio.h>

using namespace std;

class myexception: public  exception
{
   
   virtual const char* what() const throw(){
       return "Division by zero";
       
       
   }
  
   
};


class CBase {
       virtual void f(){} 
};

class CDerived : public CBase {
};

int main () {
     myexception myex;
  try {
      /*
       int a=5;
        int b,c;
        b=0;
         if (b==0)
         throw myex;
         else
         c=a/b;
       */
      /*
      CBase* a = new CBase;
      CBase* b = new CDerived;
      cout << "a is: " << typeid(a).name() << '\n';
      cout << "b is: " << typeid(b).name() << '\n';
      cout << "*a is: " << typeid(*a).name() << '\n';
      cout << "*b is: " << typeid(*b).name() << '\n';
    
    /*
      CBase  cb1;
      CBase *cb2=&cb1;
	  cout << typeid(cb2).name();
      CBase * cb = 0;
      cout << typeid(*cb).name();
	*/
    
 	CDerived rd;
    CBase& cbc = dynamic_cast<CBase&>(rd);
    
    
    
   // CBase cbc;
   // CDerived& rd = dynamic_cast<CDerived&>(cbc);

	

   } 
   
   catch (exception& e) { 
         cout << "Exception: " << e.what() << endl; 
   }
   
   catch (bad_typeid& bt)
    {
        cout<< "bad_typeid caught: " << bt.what() << '\n';
    }
    
      catch (bad_cast& bc)
  {
     cout << "bad_cast caught: " << bc.what() << '\n';
  }


   getch();
  return 0;
}
