#include<iostream>
#include<thread>

using namespace std;


void foo() {
    thread::id this_id = this_thread::get_id();
      
    cout << " t1 id:" << this_id << endl;
}

void bar() {
    thread::id this_id = this_thread::get_id();
    
    cout << " t2 id:" << this_id << endl;
    
}

int main(){

    thread t1(foo);
    thread t2(bar);

    cout << "\n" ;

    t1.join();
    t2.join();

    cout << "foo and bar are completed" << endl;

        return 0;

}
