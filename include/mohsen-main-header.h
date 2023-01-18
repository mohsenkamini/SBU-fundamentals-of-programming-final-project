#include <structures.h>

#ifndef max_number_of_users
#define max_number_of_users 200
#endif

void print_warning (char* text);
string print_message_input_string (string message);

// USERS

user create_user(user* new_user);

bool login (user users_array[], string user_id, string password);

bool login_prompt (user users_array[]);



// MENU

void general_menu (user users_array[]);

void admin_menu (user users_array[],string user_id);

void user_menu (user users_array[],string user_id);

void show_profile(user users_array[],string user_id);

void change_password(user users_array[],string user_id);

