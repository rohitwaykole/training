#include<iostream>
#include<thread>
#include<fstream>
#include <unistd.h>

using namespace std;

void producer(char **buf) {
    thread::id this_id = this_thread::get_id();
    cout <<" t1 id:" << this_id << endl;

    ifstream inFile;
    inFile.open("sample.txt", ios_base::in | ios_base::binary);

    if (inFile.fail()) {
        cerr << " Error opening file" << endl;
        exit(1);
    }

    inFile.seekg(0, inFile.end);
    int length = inFile.tellg();
    inFile.seekg(0, inFile.beg);
    *buf = (char *)malloc(length);
    if (*buf == NULL) exit(1);
    
    inFile.read(*buf, length);
    cout << "t1 read: " << endl << *buf << endl;
}

void consumer(char *buf) {
    thread::id this_id = this_thread::get_id();
    cout <<" t2 id:" << this_id << endl;

    ofstream outFile;
    outFile.open("sampleout.txt", ios_base::out | ios_base::binary);
  //  while( *buf != NULL) outFile << buf;
    outFile << buf;
    cout << "t2 wrote: " << endl << buf << endl;
}

int main() {
    char *buf;

    thread t1(producer, &buf);
    sleep(1);
    thread t2(consumer, buf);

    cout << "\n" ;

    t1.join();
    t2.join();

    cout << "read and write are completed" << endl;

    return 0;
}
