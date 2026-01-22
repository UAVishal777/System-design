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


class CheeseBurger:public Burger{

    void prepare()override{
        cout<<"Created Cheese Burger"<<endl;
    }

};

class PaneerBurger:public Burger{

    void prepare()override{
        cout<<"Created Paneer Burger"<<endl;
    }

};

class ProteinBurger:public Burger{

    void prepare()override{
        cout<<"Created Protein Burger"<<endl;
    }
};

class BurgerFactory{

    public:
        virtual Burger* createBurger(string& type)=0;
};

class SinghBurgerFactory:public BurgerFactory{

    public:
        Burger* createBurger(string& type)override{
            if(type=="basic"){
                return new BasicBurger();
            }
            else if(type=="standard"){
                return new StandardBurger();
            }
            else if(type=="premium"){
                return new PremiumBurger();
            }
            else {
                cout<<"Invalid Burger type";
                return nullptr;
            }
        }
};

class KingBurgerFactory:public BurgerFactory{

    public:
        Burger* createBurger(string& type)override{
            if(type=="cheese"){
                return new CheeseBurger();
            }
            else if(type=="paneer"){
                return new PaneerBurger();
            }
            else if(type=="protein"){
                return new ProteinBurger();
            }
            else {
                cout<<"Invalid Burger type";
                return nullptr;
            }
        }
};

int main(){

    string type1 = "premium";
    string type2 = "paneer";

    BurgerFactory* singhBurger= new SinghBurgerFactory();
    BurgerFactory* kingBurger = new KingBurgerFactory();

    Burger* burger1= singhBurger->createBurger(type1);
    Burger* burger2= kingBurger->createBurger(type2);

    burger1->prepare();
    burger2->prepare();

    return 0;
}