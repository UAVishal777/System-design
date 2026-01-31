#ifndef CART_H
#define CART_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"
#include "Restaurant.h"
using namespace std;

class Cart{

    private:
        vector<MenuItem> items;
        Restaurant* restaurant;

    public:
        Cart(){
            restaurant = nullptr;
        }

        void addItem(const MenuItem& item){
            if(restaurant == nullptr){
                cout<<"Set restaurant before adding items to cart."<<endl;
                return;
            }
            items.push_back(item);
        }

        ~Cart(){
            cout<<"Destroying Cart"<<endl;
            items.clear();
        }

        double getTotalPrice() const{
            double total = 0.0;
            for(const auto& item : items){
                total += item.getPrice();
            }
            return total;
        }

        void setRestaurant(Restaurant* res){
            restaurant = res;
        }

        Restaurant* getRestaurant() const{
            return restaurant;
        }

        const vector<MenuItem>& getItems() const{
            return items;
        }
};

#endif //CART_H