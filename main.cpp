#include <mohsen-main-header.h>
#include <iostream>
#include <string>
#include <ctime>  // only used to get the current time of the system

using namespace std;


int main() {
  
  user list_of_users[max_number_of_users];
  food_item food_plans[max_number_of_food_plans];

  food_plans[0].dt=todays_date();

  general_menu(list_of_users);

  return(0);
}