#include <iostream>
#include <mohsen-main-header.h>
#define phone_number_size 11


struct user {
    
    char* first_name;
    char* last_name;
    char phone_number[phone_number_size];
    
    char* username;
    char* password; // or could be password_hash
    
    char* major;
    char* degree_level;

    const long int initial_wallet_balance=0 ;
    long int wallet_balance;

    bool is_admin;
}