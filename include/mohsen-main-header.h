#include <structures.h>

#ifndef max_number_of_users
#define max_number_of_users 200
#endif

user create_user(user* new_user);

void print_warning (char* text);

string print_message_input_string (string message);

bool login (user users_array[], string user_id, string password);

bool login_prompt (user users_array[]);