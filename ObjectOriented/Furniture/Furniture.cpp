#include <iostream>
#include <conio.h>
using namespace std;
class Tree{
	private:
		string type;
	    int length;
	public:
	    Tree(){
	    type = "mese";
	    length=5;
		}
	    Tree(string type){
	    this->type=type;
		length=10;	
	    }
		Tree(string type,int length){
		this->type=type;
		this->length=length;
		}
		string getType(){
		return type;
	    }
		void dispTree(){
			cout<<"Type="<<type<<endl;
			cout<<"Length="<<length<<endl;
		}
};
class Furniture{
	private:
		string type;
		int size;
	public:
		Furniture(){
		type= "Okul";
		size= 5;
		}
		Furniture(string type){
		this->type=type;
		size=10;
		}
		Furniture(string type,int size){
		this->type=type;
		this->size=size;
		}
		void doTable(Tree *tr){
			cout<<"Table from to "<<tr->getType()<<" for "<<type<<" Size= "<<size<<endl;
		}
		void doChair(Tree *tr){
			cout<<"Chair from to "<<tr->getType()<<" for "<<type<<" Size= "<<size<<endl;
		}
};
int main(){
   Tree *t1=new Tree();
   Tree *t2=new Tree("Cam");
   Tree *t3=new Tree("Ladin",15);
   Furniture *f1 = new Furniture();
   Furniture *f2 = new Furniture("Ev");
   Furniture *f3 = new Furniture("Ofis",15);
   t1->dispTree();
   t2->dispTree();
   t3->dispTree();
   f1->doTable(t1);
   f2->doTable(t2);
   f3->doTable(t3);
   f1->doChair(t1);
   f2->doChair(t2);
   f3->doChair(t3);
   getch();
return 0;
}