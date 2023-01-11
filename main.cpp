#include <mohsen-main-header.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
  // call a function in another file
  //myPrintHelloMake();
  //print_warning("RED HELLO");

  user* new_user=new user;
  *new_user=create_user(new_user);
  cout << new_user -> first_name << endl;
  cout << new_user -> last_name << endl;
  cout << new_user -> phone_number << endl;
  cout << new_user -> id << endl;
  cout << new_user -> password << endl;
  cout << new_user -> major << endl;
  cout << new_user -> degree_level << endl;
  cout << new_user -> is_admin << endl;


  return(0);
}