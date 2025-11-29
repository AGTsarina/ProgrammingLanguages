#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "random.h"
using namespace std;

struct Person
{
    int id;
    string name;
    string surname;
    int FlightNumber;
    int typeTicket;
    vector<int> luggage = {};
};

Person get_random(int id){
    Person person{id, get_random_str(), get_random_str(),
        random(1,5), random_class({20, 30, 50}), get_random_vector() };
    return person;
}

int main(){
    srand(time(NULL));
    vector<Person> passengers;
    int n = random(100, 200);
    for(int i=0; i<n; i++){
        passengers.push_back(get_random(i + 1));
    }

    vector<int> tickets(3);
    for(const Person &p: passengers){
       tickets[p.typeTicket - 1]++;
    }
    return 0;
}