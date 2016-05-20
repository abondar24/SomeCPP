//
// Created by abondar on 19.05.16.
//
#include <iostream>
#include <fstream>

#include <ratio>
#include <random>
#include <tuple>
#include <functional>

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

    typedef ratio<1,7> r1;
    typedef ratio<1,2> r2;
    typedef ratio_less<r1,r2> r3;

    cout<< r1::num << endl;
    cout<< r1::den << endl;

    cout<<boolalpha<<r3::value<<endl;
    typedef ratio_add<r1,r2>::type res;
    cout<< res::num<<"/"<<res::den << endl;

   random_device rd;
    cout<< "Enthropty "<<rd.entropy() << endl;
    cout<< "Min "<<rd.min() << endl;
    cout<< "Max "<<rd.max() << endl;
    cout<< "Rand "<<rd() << endl;

typedef  linear_congruential_engine<uint_fast32_t ,32767,0,2133242534> lce1;
    cout<< "Min "<<lce1::min() << endl;
    cout<< "Max "<<lce1::max() << endl;
    cout<< "Rand "<<lce1(static_cast<unsigned long>(time(nullptr)))<< endl;

    typedef tuple<int,string,bool>MyTuple;
    MyTuple t(1,"sdfds",true);
    cout<< get<0>(t)<< endl;
    cout<< get<1>(t)<< endl;
    cout<< get<2>(t)<< endl;
    cout<< "t size "<<tuple_size<MyTuple>::value<< endl;

    auto t1 = make_tuple(1,true,cref(t));
    cout<< get<1>(t1)<< endl;

    int j=2;
    string s="aaa";
    bool f = false;

    tie(j,s,f) = t;//tie creates a tuple of references to j s f
    cout<< j<< endl;
    cout<< s<< endl;
    cout<< f<< endl;

    return 0;
}