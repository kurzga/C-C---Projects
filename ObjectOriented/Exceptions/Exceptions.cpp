// typeid, polymorphic class
#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

using namespace std;

class myexception : public exception {
    virtual const char* what() const throw() {
        return "Division by zero";
    }
};

class CBase {
    virtual void f() {}
};

class CDerived : public CBase {
};

int main() {
    exception e;
    try {
    	/*
        int a = 5;
        int b = 0;
        if (b == 0)
            throw e;
        else
            int c = a / b;
        */
		/*
           CBase* a = new CBase;
           CBase* b = new CDerived;
           cout << "a is: " << typeid(a).name() << '\n';
           cout << "b is: " << typeid(b).name() << '\n';
           cout << "*a is: " << typeid(*a).name() << '\n';
           cout << "*b is: " << typeid(*b).name() << '\n';
        */
        /*
          CBase  cb1;
          CBase *cb2=&cb1;
          cout << typeid(cb2).name();
          CBase * cb = 0;
          cout << typeid(*cb).name();
        */
        /*
          CDerived rd;
          CBase& cbc = dynamic_cast<CBase&>(rd);
        
          CBase cbc;
          CDerived& rd = dynamic_cast<CDerived&>(cbc);
          */
    }

    catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    cin.get();
    return 0;
}
