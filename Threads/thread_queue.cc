#include<string.h>
#include<unistd.h>
#include<thread>
#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;
//using namespace util;

string data = "";
bool dataReady = false;
queue<char> Q;

void producer(string inFilePath) {
    cout << "Producer: started" << endl;
    sleep(1);

    ifstream inFile;
    inFile.open(inFilePath);
    if (inFile.fail()) {
        cerr << " Error opening in file" << endl;
        exit(1);
    }
    
    while (!inFile.eof()) {
       char item;
       inFile >> item;
       Q.push(item);
    //  getline(inFile, data);
    }
    
    //cout << "read data" << data << endl;
    inFile.close();

    dataReady = true;
}

void consumer(string outFilePath) {
    cout << "Consumer: started" << endl;
    while (!dataReady) sleep(1);
    
    ofstream outFile;
    outFile.open(outFilePath);
    if (outFile.fail()) {
        cerr << " Error opening out file" << endl;
        exit(1);
    }
    
    while (!dataReady || Q.empty()) {
        while (Q.empty==True) sleep(1);
        char temp = Q.front();
        Q.pop();
        outFile << temp;
    } 
   // cout << "after" << data << endl; 
    
    outFile.close();
}

int main (int argc, char *argv[]) {
    if (argc < 3) {
        cout << "usage: " << argv[0] << " <inFile> <outFile>" << endl;
        exit(1);
    }
    string inFile = argv[1];
    string outFile = argv[2];

    thread p(producer, inFile);
    thread c(consumer, outFile);

    p.join();
    c.join();
}
