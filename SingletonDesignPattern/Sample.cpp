#include <iostream>
using namespace std;

// Implementation of Singleton Design Pattern very Simple
class Singleton {
    
    public:
    Singleton(){
        cout<<"Singleton Instance Created"<<endl;
    }
};


int main(){

    Singleton* s1 = new Singleton();
    Singleton* s2 = new Singleton();

    cout<<"Address of s1: "<<s1<<endl;
    cout<<"Address of s2: "<<s2<<endl;

    return 0;

}