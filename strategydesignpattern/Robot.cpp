#include<bits/stdc++.h>
using namespace std;

//Created strategies of different type required
//rather than extending a simple class Robot many times and increasing 
//inheritence
class Walkable{
    public:
    virtual void walk()=0;
};

class Talkable{
    public:
    virtual void talk()=0;
};

class Flyable{
    public:
    virtual void fly()=0;
};

//... create as many strategies do require


//Below created Robot class of their respective type walkable, talkable , flyable
// and make them walk, talk and fly according to their requirement
class NormalWalk: public Walkable{
    public:
    void walk()override{
        cout<<"Robot do Normal walk"<<endl;
    }
};


class NoWalk: public Walkable{
    public:
    void walk()override{
        cout<<"Robot cannot walk"<<endl;
    }
};

class NormalTalk: public Talkable{

    public:
    void talk()override{
        cout<<"Robot do Normal talk"<<endl;
    }
};

class NoTalk: public Talkable{

    public:
    void talk()override{
        cout<<"Robot cannot talk"<<endl;
    }
};

class NormalFly: public Flyable{

    public:
    void fly()override{
        cout<<"Robot do normal fly"<<endl;
    }
};

class NoFLy: public Flyable{

    public:
    void fly()override{
        cout<<"Robot cannot fly"<<endl;
    }
};


class Robot{
    protected:
        Talkable* talkRobot;
        Walkable* walkRobot;
        Flyable* flyRobot;
    
    public:
        Robot(Walkable* w, Talkable* t, Flyable* f){
            this->walkRobot=w;
            this->flyRobot=f;
            this->talkRobot=t;
        }

        void walk(){
            walkRobot->walk();
        }

        void talk(){
            talkRobot->talk();
        }

        void fly(){
            flyRobot->fly();
        }

        virtual void projection()=0;
};


//concrete Robot types
class CompanionRobot:public Robot{
    public:

    CompanionRobot(Walkable* w, Talkable* t, Flyable* f):Robot(w, t, f){
    }

    void projection()override{
        cout<<"Displaying Companion features"<<endl;
    }
};

class WorkerRobot:public Robot{
    public:
    WorkerRobot(Walkable* w, Talkable* t, Flyable* f):Robot(w,t,f){}

    void projection()override{
        cout<<"Displaying Worker efficiency"<<endl;
    }
};


int main(){

    //using our strategy we can create different type of robots
    //like here whatever type robot we will need we will pass that type 
    //of behaviour

    Robot* robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFLy());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    Robot* robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}