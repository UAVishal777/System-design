#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager {
    private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;

    RestaurantManager() {
        // Private constructor for singleton pattern
    }

    public:
    static RestaurantManager* getInstance() {
        if (!instance) {
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> searchByLocation(const string& location) {
        vector<Restaurant*> results;
        for (auto& restaurant : restaurants) {
            if (restaurant->getLocation() == location) {
                results.push_back(restaurant);
            }
        }
        return results;
    }

    const vector<Restaurant*>& getRestaurants() const {
        return restaurants;
    }

    
};

RestaurantManager* RestaurantManager::instance = nullptr;



#endif //RESTAURANT_MANAGER_H