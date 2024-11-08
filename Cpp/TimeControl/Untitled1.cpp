#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
condition_variable cv;
string value;
int b;
void read_value() {
    cin >> value;
    cv.notify_one();
}
void issleeping(){
	thread th(read_value);

    mutex mtx;
    unique_lock<mutex> lck(mtx);
    while (cv.wait_for(lck, chrono::seconds(5)) == cv_status::timeout)
    {
        cout << "\nTime-Out: 5 second:";

    }
    cout << "You entered: " << value << '\n';

    th.join();
}


int main()
{   while(true){
	cout << "Please enter the input: ";
    issleeping();
    }
    return 0;
}