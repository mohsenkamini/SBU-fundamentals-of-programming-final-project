#include <iostream>
#include <mohsen-main-header.h>
#include <global_vars.h>
#include <string>
//#include <structures.h>
using namespace std;


void myPrintHelloMake(void) {

  cout << "Hello makefiles!\n";

  return;
}
//void print_standard (char* text) 
//{
//  cout << text << endl;
//}
void print_warning (string text) 
{
  const std::string red("\033[0;31m");
  cout << red << text << endl;
}

string print_message_input_string (string message)
{
  string result;
  cout << message;
  cin >> result;
  cout << endl;
  return result;
}

user create_user (user* new_user) {

  char admin_state_ans;

  //cout <<  "Please Enter your first name: ";
  //cin >> new_user.first_name;
  //cout << endl;

  new_user -> first_name=print_message_input_string("Please Enter your first name: ");
  cout << new_user -> first_name <<endl;
  //cout <<  "                  last name: ";
  //cin >> new_user.last_name;
  //cout << endl;
  //cout <<  "                  phone number: ";
  //cin >>  new_user.phone_number;
  //cout << endl;
  //  
  //cout <<  "                  user ID: ";
  //cin >> new_user.id;
  //cout << endl;
  //cout <<  "                  password: ";
  //cin >> new_user.password; // or could be password_hash
  //cout << endl;
  //  
  //cout <<  "                  major: ";
  //cin >> new_user.major;
  //cout << endl;
  //cout <<  "                  degree level: ";
  //cin >> new_user.degree_level;
  //cout << endl;


  cout <<  "Great! Do you also want to be an Admin of dining ?[y/n]: ";
  cin >> admin_state_ans;
  cout << endl;

  //if (admin_state_ans == 'y')
  //{
  //  new_user.is_admin=true;
  //  is_there_any_admins=true;
  //}
  //else
  //  new_user.is_admin=false;
//
  //cout << "Your account is successfully created!\n";

}