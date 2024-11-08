#include <iostream>
#include <conio.h>
#define SIZE 100
using namespace std;
class Queue{
	private:
		int items[SIZE],front,rear;
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
	bool isFull(){
		if(rear==SIZE-1&&front==0){
			return true;
		}
		else{
			return false;
		}
	}
	bool isEmpty(){
		if (front == -1){
			return true;
		}     
        else{
        	return false;
		}
        	
	}
	void enQueue(int element){
		if(isFull()){
			cout<<endl<<"Queue is full"<<endl;
		}
		else{
			if(front == -1) {
				front = 0;
			}
			rear++;
			items[rear]=element;
			cout<<endl;
			cout<<"Added -> "<<element<<endl;
		}
	}
	int deQueue() {
    int element;
     if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
      } 
	  else {
        element = items[front];
        if (front >= rear) {
        front = -1;
        rear = -1;
        }
       else {
        front++;
        }
        cout << endl
        << "Deleted -> " << element << endl;
        return (element);
       }
   }
	void display(){
		int i;
			if(isEmpty()){
			cout<<endl<<"Queue is empty"<<endl;
		}
		else {
            cout << endl << "Front indeks-> " << front;
            cout << endl << "Elements -> ";
            for (i = front; i <= rear; i++)
            cout << items[i] << " ";
            cout << endl << "Rear indeks-> " << rear << endl;
       }       
	}
};

int main(){
	int elemansayisi,cikar;
	Queue q;
	cout<<"kac eleman ekleyeceksiniz?";
	cin>>elemansayisi;
	for(int i =0;i<elemansayisi;i++){
		int deger;
		cin>>deger;
		q.enQueue(deger);
	}
	cout<<"kac eleman cikaracaksiniz?";
	cin>>cikar;
	for(int i =0;i<cikar;i++){
		q.deQueue();
	}
	q.display();
	getch();
	return 0;
}