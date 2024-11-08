#include <iostream>
#include <conio.h>
using namespace std;
class Node{
public:
int data;
Node* next;

Node(){
    data = 0;
    next=NULL;
}
Node(int data,Node* next=NULL){
	this->data = data;
	this->next = next;
}
};
void print(Node *temp){
	while(temp!=NULL){
		cout << temp->data << endl;
        temp=temp->next;

	}
}
int boyut(Node *temp){
 int sayac=0;
 while(temp!=NULL){
 sayac++;
 temp=temp->next;
 }
 return sayac;
}
void basaekle(Node *&head, int deger) {
    Node *yeni = new Node(deger);
    if (head == NULL)
        head = yeni;
    else {
        yeni->next = head;
        head = yeni;
    }
}
void sonaekle(Node *head,Node *temp,int deger){
	Node *yeni = new Node(deger);
    if(head==NULL){
      head=yeni;	
	}
    
    else{
      temp=head;
      while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=yeni;
    }
}
void konumaekle(Node *head,Node *temp,int deger,int konum){
	Node *yeni= new Node(deger);
    int sayac=0;
    temp=head;
    while(temp->next!=NULL){
    if((konum-1)==sayac) break;
    temp=temp->next;
    sayac++;
    }
    yeni->next=temp->next;
    temp->next=yeni;
}
void konumdansil(Node *head,Node *temp,int konum){
    if (head == NULL) throw "Liste Boş";
    if (konum < 0 || konum > boyut(head) - 1) throw "Geçersiz Konum";
    temp = head;
    if (konum == 0) {
    head = head->next;
    delete temp;
    } else {
    int sayac = 0;
    while (temp->next != NULL) {
    if (sayac == (konum - 1)) break;
     temp = temp->next;
    sayac++;
    }
    Node *eskidugum = temp->next;
    temp->next = eskidugum->next;
    delete eskidugum;
   }

}
int main(){
	Node *head,*temp;
	int elemansayisi,deger,ilkeleman;
	cout<<"Eleman Sayisi:";
	cin>>elemansayisi;
	cout<<"ilk eleman:"<<endl;
	cin>>ilkeleman;
	head = new Node(ilkeleman);
  	temp = head;
  	cout<<"Kalan Elemanlar:"<<endl;
	for(int i =0;i<elemansayisi-1;i++){
		cin>>deger;
		temp->next = new Node(deger);
	    temp = temp->next;
	}
	sonaekle(head,temp,10);
	basaekle(head,10);
    cout<<"Eleman Sayisi:"<<boyut(head)<<endl;
    print(head);
    getch();
	return 0;
}