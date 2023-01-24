#include <mohsen-main-header.h>
#include <iostream>
#include <string>
#include <ctime>  // only used to get the current time of the system

using namespace std;


int main() {
  
  
  user list_of_users[max_number_of_users];
  food_item central_dining[max_number_of_food_plans];
  food_item dorm_dining[max_number_of_food_plans];

  initiate_calendar(central_dining,max_number_of_food_plans,todays_date());
  initiate_calendar(dorm_dining,max_number_of_food_plans,todays_date());

  general_menu(list_of_users,central_dining,dorm_dining);

  return(0);
}