#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

class User{
    private:
        int userId;
        string username;
        string address;
        Cart* cart;

    public:
        User(int userId, const string& username, const string& address){
            this->userId = userId;
            this->username = username;
            this->address = address;
            this->cart = new Cart();
        }

        ~User(){
            cout<<"Destroying User"<<endl;
            delete cart;
        }

        //Getters and Setters
        int getUserId() const{
            return userId;
        }

        void setUserId(int id){
            userId = id;
        }

        string getUsername() const{
            return username;
        }

        void setUsername(const string& name){
            username = name;
        }

        string getAddress() const{
            return address;
        }

        void setAddress(const string& addr){
            address = addr;
        }

        Cart* getCart() const{
            return cart;
        }
};

#endif //USER_H