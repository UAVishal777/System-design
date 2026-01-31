#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"
using namespace std;

class Restaurant{
    private:
        static int nextRestaurantId;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem>menu;

    public:
        Restaurant(const string&name, const string& location){
            this->name = name;
            this->location=location;
            this->restaurantId = nextRestaurantId+1;
        }

        ~Restaurant(){
            cout<<"Destroying Restaurant"<<endl;
            menu.clear();
        }

        //getters and setters
        string getName() const{
            return name;
        }

        void setName(const string &name){
            this->name = name;
        }

        string getLocation() const{
            return location;
        }

        void setLocation(const string &loc){
            this->location = loc;
        }

        void addMenuItem(const MenuItem& item){
            menu.push_back(item);
        }

        const vector<MenuItem>& getMenu() const{
            return menu;
        }
};

int Restaurant::nextRestaurantId = 0;


#endif //RESTAURANT_H