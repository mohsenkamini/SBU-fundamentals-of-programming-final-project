#include <iostream>
#include <string>
#define phone_number_size 12
#define name_max_length 
#define max_number_of_users 100
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
    float supply;     // how many of that food we have to offer
    string reserved_by[max_number_of_users];
    int reserved_by_index =0;
};

enum self {
    central,dorm
};  

