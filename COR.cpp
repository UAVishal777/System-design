#include <iostream>
#include <string>
using namespace std;

//Chain of Responsibility Pattern

class MoneyHandler{
    protected:
    MoneyHandler* nextHandler;

    public:
    MoneyHandler(){
        this->nextHandler = nullptr;
    }

    void setNextHandler(MoneyHandler* handler){
        nextHandler = handler;
    }

    virtual void dispense(int amount)=0;

};

class ThousandRupeeHandler: public MoneyHandler{

    private:
        int numNotes;

    public:
        ThousandRupeeHandler(int notes){
            this->numNotes = notes;
        }

        void dispense(int amount) override{
            int notesNeeded = amount / 1000;
            if(notesNeeded > numNotes){
                notesNeeded = numNotes;
                numNotes = 0;
            }
            else{
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0){
                cout<<"Dispensing "<<notesNeeded<<" thousand rupee notes"<<endl;
            }

            int remainingAmount = amount - (notesNeeded * 1000);
            if(remainingAmount > 0 && nextHandler != nullptr){
                nextHandler->dispense(remainingAmount);
            }
            else if(remainingAmount > 0){
                cout<<"Cannot dispense the remaining amount: "<<remainingAmount<<endl;
            }

        }
};

class FiveHundredRupeeHandler: public MoneyHandler{

    private:
        int numNotes;

    public:
        FiveHundredRupeeHandler(int notes){
            this->numNotes = notes;
        }

        void dispense(int amount) override{
            int notesNeeded = amount / 500;
            if(notesNeeded > numNotes){
                notesNeeded = numNotes;
                numNotes = 0;
            }
            else{
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0){
                cout<<"Dispensing "<<notesNeeded<<" five hundred rupee notes"<<endl;
            }

            int remainingAmount = amount - (notesNeeded * 500);
            if(remainingAmount > 0 && nextHandler != nullptr){
                nextHandler->dispense(remainingAmount);
            }
            else if(remainingAmount > 0){
                cout<<"Cannot dispense the remaining amount: "<<remainingAmount<<endl;
            }

        }
};

int main(){
    MoneyHandler* thousandHandler = new ThousandRupeeHandler(5); // 5 notes of 1000
    MoneyHandler* fiveHundredHandler = new FiveHundredRupeeHandler(10); // 10 notes of 500  
    thousandHandler->setNextHandler(fiveHundredHandler);   
    int amountToDispense = 4500;
    cout<<"Requesting to dispense amount: "<<amountToDispense<<endl;   
    thousandHandler->dispense(amountToDispense);

    amountToDispense = 7000;
    cout<<"\nRequesting to dispense amount: "<<amountToDispense<<endl;  
    thousandHandler->dispense(amountToDispense);

    amountToDispense = 3000;
    cout<<"\nRequesting to dispense amount: "<<amountToDispense<<endl;
    thousandHandler->dispense(amountToDispense);
                2123456789-=-0987654321`234567890][oiuytrewEASRDTYUIO
                
                ';LKJHGFDzxcvBNM,./?><mNBVCXZ`      `   ']
    delete thousandHandler;
    delete fiveHundredHandler;   

    return 0;
}