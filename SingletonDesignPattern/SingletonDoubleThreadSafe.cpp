#include<iostream>
#include<mutex>
using namespace std;

// Implementation of Singleton using Locking Mechanism
// Double Thread safe implementation

class Singleton{
    private:
    static Singleton* instance;
    static mutex* mtx;
    Singleton(){
        cout<<"Singleton Instance Created"<<endl;
    }

    public:
    static Singleton* getInstanceInternal(){
        //we will lock in multithreaded environment
        if(instance==nullptr){
            lock_guard<mutex> lock(*mtx); // do locking only when instance is null
            if(instance==nullptr){ //double check
                instance = new Singleton();
                cout<<"Instance created inside lock"<<endl;
            }
            return instance;
        }
    }
};

Singleton* Singleton::instance = nullptr; // Eager intitialization is also possible to remove locke and double check
// Singleton* Singleton::instance = new Singleton();
mutex* Singleton::mtx = new mutex();


int main(){

    cout<<"Singleton Design Pattern with Lock Example"<<endl;

    Singleton* s1 = Singleton::getInstanceInternal();
    Singleton* s2 = Singleton::getInstanceInternal();
    cout<<"Address of s1: "<<s1<<endl;
    cout<<"Address of s2: "<<s2<<endl;

    return 0;
}