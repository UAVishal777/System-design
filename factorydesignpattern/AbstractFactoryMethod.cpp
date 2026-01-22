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

// New product
class GarlicBread{
    public:
        virtual void prepare()=0;
};

class BasicGarlicBread: public GarlicBread{
    public:
        void prepare()override{
            cout<<"Prepare Basic Garlic bread"<<endl;
        }
};

class CheeseGarlicBread: public GarlicBread{
    public:
        void prepare()override{
            cout<<"Prepare Cheese Garlic Bread"<<endl;
        }
};

class BasicGarlicWheatBread: public GarlicBread{
    public:
        void prepare()override{
            cout<<"Preapre Basic Garlic Wheat bread"<<endl;
        }
};

class CheeseGarlicWheatBread: public GarlicBread{
    public:
        void prepare()override{
            cout<<"Prepare cheese Garlic wheat bread"<<endl;
        }
};

class MealFactory{

    public:
        virtual Burger* createBurger(string& type)=0;
        virtual GarlicBread* createGarlicBread(string& type)=0;
};

class SinghBurgerFactory:public MealFactory{

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

        GarlicBread* createGarlicBread(string& type)override{
            if(type=="basic"){
                return new BasicGarlicBread();
            }

            else if(type=="cheese"){
                return new CheeseGarlicBread();
            }
            else if(type=="cheesewheat"){
                return new CheeseGarlicWheatBread();
            }
            else{
                cout<<"Invalid type bread"<<endl;
                return nullptr;
            }
        }
};

class KingBurgerFactory:public MealFactory{

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

        GarlicBread* createGarlicBread(string& type)override{
            if(type=="basic"){
                return new BasicGarlicWheatBread();
            }
            else if(type=="cheese"){
                return new CheeseGarlicWheatBread();
            }
            else{
                cout<<"Invalid Burger"<<endl;
                return nullptr;
            }
        }
};

int main(){

    string type1 = "premium";
    string type2 = "paneer";
    string type3 = "basic";

    MealFactory* singhBurger= new SinghBurgerFactory();
    MealFactory* kingBurger = new KingBurgerFactory();

    Burger* burger1= singhBurger->createBurger(type1);
    Burger* burger2= kingBurger->createBurger(type2);

    GarlicBread* burger3 = kingBurger->createGarlicBread(type3);

    burger1->prepare();
    burger2->prepare();
    burger3->prepare();

    return 0;
}