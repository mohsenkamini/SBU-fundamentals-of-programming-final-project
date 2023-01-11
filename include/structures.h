#include <iostream>
#include <string>
#define phone_number_size 12
#define name_max_length 200
using namespace std;

struct user {
    
    //char first_name[name_max_length];
    //char last_name[name_max_length];
    //char phone_number[phone_number_size];
    //
    //char id[name_max_length];
    //char password[name_max_length]; // or could be password_hash
    //
    //char major[name_max_length];
    //char degree_level[name_max_length];

    string first_name;
    string last_name;
    string phone_number;
    
    string id;
    string password; // or could be password_hash
    
    string major;
    string degree_level;

    //const int initial_wallet_balance=0 ;
    long int wallet_balance = 0;

    bool is_admin;
};

struct food {

    int id;
    string name;
    long int price;
};  