//
// Created by abondar on 04.05.16.
//
#include <iostream>
using namespace std;

class Estimator{
public:
    virtual int getMileLeft(){
        return getMilesPerGallon()*getGallonsLeft();
    }

    virtual void setGallonsLeft(int val){
        gallonsLeft = val;
    }

    virtual int getGallonsLeft(){ return gallonsLeft;}

private:
    int gallonsLeft;
    virtual int getMilesPerGallon(){ return 20;}
};

class EfficientEstimator : public Estimator{
private:
    virtual int getMilesPerGallon(){ return 35;}
};

int main(){
    Estimator estimator;
    estimator.setGallonsLeft(7);
    cout <<"I can go "<<estimator.getMileLeft()<< " more miles "<<endl;


    EfficientEstimator estimator1;
    estimator1.setGallonsLeft(7);
    cout <<"I can go "<<estimator1.getMileLeft()<< " more miles "<<endl;

    return 0;
}