#include <structures.h>

#ifndef max_number_of_food_plans
#define max_number_of_users 100
#define max_number_of_food_plans 365
#define number_of_days_in_year 365
#define number_of_days_in_month 30
#define number_of_months 12
#define number_of_dow 7
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




// date

date todays_date ();
int compare_dates (date dt1, date dt2);
void initiate_calendar (food_item dining[],int size,date today);
string incremented_dow (string dow);