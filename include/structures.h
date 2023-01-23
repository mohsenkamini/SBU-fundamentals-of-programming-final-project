#include <iostream>
#include <string>
#define phone_number_size 12
#define name_max_length 200
using namespace std;

struct user {
    
    string first_name;
    string last_name;
    string phone_number;
    
    string id;
    string password; // or could be password_hash
    
    string major;
    string degree_level;

    //const int initial_wallet_balance=0 ;
    float wallet_balance = 0;

    bool is_admin;
};

struct food {

    int id;
    string name;
    float price;
};  

struct date {

    string dow;        // Sat,Sun,Mon,Tues,Wed,Thurs
    int dom;        
    string month;       // Jan,Feb,Mar,Apr,May,Jun,Jul,Sep,Oct,Nov,Dec
    int year;
};

struct food_item {
    date dt;
    food fd;
};

enum self {
    central,dorm
};  

