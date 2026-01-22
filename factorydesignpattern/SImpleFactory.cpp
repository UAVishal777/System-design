#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
        virtual void prepare()=0;
};

class BasicBurger:public Burger{

    void prepare()override{
        cout<<"Created Basic Burger"<<endl;
    }

};

class StandardBurger:public Burger{

    void prepare()override{
        cout<<"Created Standard Burger"<<endl;
    }

};

class PremiumBurger:public Burger{

    void prepare()override{
        cout<<"Created Premium Burger"<<endl;
    }
};

class BurgerFactory{

    public:
        Burger* CreateBurger(string& type){
            if(type=="basic"){
                return new BasicBurger();
            }
            else if(type=="standard"){
                return new StandardBurger();
            }
            else if(type=="premium"){
                return new PremiumBurger();
            }
            else{
                cout<<"Invalid Burger Type"<<endl;
                return nullptr;
            }
        }
};



int main(){
    string type= "standard";

    BurgerFactory* myburgerFactory= new BurgerFactory();
    
    Burger* burger = myburgerFactory->CreateBurger(type);

    burger->prepare();
    return 0;
}