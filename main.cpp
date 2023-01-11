#include <mohsen-main-header.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
  // call a function in another file
  //myPrintHelloMake();
  //print_warning("RED HELLO");

  user new_user;
  create_user(&new_user);
  cout << new_user.first_name << endl;
  cout << new_user.last_name;


  return(0);
}