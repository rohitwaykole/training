#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){
    ifstream inFile;
    inFile.open("sample.txt");
    
    if(inFile.fail()){
        cerr << " Error opening file" << endl;
        exit(1);
    }

    ofstream outFile;
    outFile.open("sampleout.txt");
    
    while(!inFile.eof()){
       char item = inFile.get();
       outFile << item;
        
    }
    
    inFile.close();
    outFile.close();
   // cout << count << endl;

    return 0;
}
    
