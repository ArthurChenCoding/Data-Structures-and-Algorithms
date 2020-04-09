#include<iostream>
#include"OrderedMap.h"

int main(){
    OrderedMap<std::string, std::string> map(20);
    map.insert ("Fruit", "Apple");
    map.insert ("Fruit", "Orange");
    map.insert ("Vegetable", "Carrot");
    map.insert ("Insect", "Cockroach");
    map.insert ("Place", "Los Angeles");
    map.insert ("Place", "New Orleans");
    map.insert ("State", "Texas");
    map.insert ("Ocean", "Pacific");
    
    map.printMap();

    return 0;
}
