#include <mohsen-main-header.h>
#include <iostream>
#include <string>
#include <ctime>
//#include <global_vars.h>

using namespace std;


int main() {
  // call a function in another file
  //myPrintHelloMake();
  //print_warning("RED HELLO");

  // TEST CREATE_USER

  //user* new_user1=new user;
  //*new_user1=create_user(new_user1);
  //
  //user* new_user=new user;
  //*new_user=create_user(new_user);
  //cout << new_user -> first_name << endl;
  //cout << new_user -> last_name << endl;
  //cout << new_user -> phone_number << endl;
  //cout << new_user -> id << endl;
  //cout << new_user -> password << endl;
  //cout << new_user -> major << endl;
  //cout << new_user -> degree_level << endl;
  //cout << new_user -> is_admin << endl;

  // Login test

  user list_of_users[max_number_of_users];

  //for (int i=0 ; i < 3 ; i++)
  //  list_of_users[i]=create_user(&list_of_users[i]);
  
  //login_prompt(list_of_users);

  // General Menu
  //general_menu(list_of_users);
  //print_warning("test warn");
  //cout << "something";

  // test time
  //time_t now = time(0);
  //string dt = ctime(&now);
  //cout << dt ;

  //date today=todays_date();
  //  cout << today.dow << endl;        // Sat,Sun,Mon,Tues,Wed,Thurs
  //  cout << today.dom-1 << endl;        
  //  cout << today.month << endl;       // Jan,Feb,Mar,Apr,May,Jun,Jul,Sep,Oct,Nov,Dec
  //  cout << today.year+1 << endl;
//
  //date yesterday=today;
  //yesterday.dom--;

  //cout << compare_dates (today,yesterday);

  // testing initiating a calendar
  food_item central_dining[max_number_of_food_plans];
  food_item dorm_dining[max_number_of_food_plans];

  //cout << "1"<< endl;
  initiate_calendar(central_dining,max_number_of_food_plans,todays_date());
  //cout << "1"<< endl;

  //for (int i=0 ; i < number_of_days_in_year ; i++)
  //{
  //  cout << i << ".\n " << central_dining[i].dt.dow << "  ";    
  //  cout << central_dining[i].dt.dom << "  ";    
  //  cout << central_dining[i].dt.month << "  ";  
  //  cout << central_dining[i].dt.year << endl << endl;  
  //  //cout << i << " " << dining[i].dt.dow <<endl;      
  //}
   //cout << incremented_dow ("Tue");
  add_new_food_item_menu (central_dining,dorm_dining);
  add_new_food_item_menu (central_dining,dorm_dining);
  return(0);
}