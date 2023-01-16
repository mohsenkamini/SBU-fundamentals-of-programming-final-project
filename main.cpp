#include <mohsen-main-header.h>
#include <iostream>
#include <string>

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
  general_menu(list_of_users);

  return(0);
}