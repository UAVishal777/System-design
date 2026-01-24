#include<iostream>
#include<cstdlib>
using namespace std;

//Implementation of Singleton using single instance method
class Singleton{
    private:
    static Singleton* instance;
    Singleton(){
        cout<<"Singleton Instance Created"<<endl;
    }


    public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){

    cout<<"Singleton Design Pattern Example"<<endl;

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout<<"Address of s1: "<<s1<<endl;
    cout<<"Address of s2: "<<s2<<endl;

    return 0;
}