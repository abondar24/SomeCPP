//
// Created by abondar on 19.05.16.
//
#include <iostream>
#include <fstream>
#include <fcntl.h>

using namespace std;
int main(){

    bool myBool = true;
    cout << myBool<<endl;
    cout <<boolalpha <<myBool<<endl;
    cout <<noboolalpha <<myBool;
    cout.flush();

    string inpt;
    cin>>inpt;
    cout << inpt<<endl;

    int i=100;
    cout << i<<endl;
    cout <<hex <<i<<endl;
    cout << oct<<i<<endl;

    ofstream outFile;
    outFile.open("/home/abondar/agents.csv");
    if (!outFile.good()){
        cerr<<"Can't open file"<<endl;
        return -1;
    }
    outFile << "SALO"<<endl;
    outFile << "POKKKOOONOOO"<<endl;

outFile.close();

    return 0;
}