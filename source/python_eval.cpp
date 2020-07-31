#include <iostream>
using namespace std;

class CPPClass{
    public:
        CPPClass(){}

        void func(double& x){
            x = 13.444444444444;
        }
};

extern "C" {
    CPPClass* CPPClass_py(){
        return new CPPClass();
    }
    double func_py(CPPClass* myClass){
        double x;
        myClass->func(x);
        return x;
    }
}
