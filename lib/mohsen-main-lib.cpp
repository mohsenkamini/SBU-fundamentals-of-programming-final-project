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
  getline(cin,result);
  cout << endl;
  return result;
}

user create_user (user* new_user) {


  //cout <<  "Please Enter your first name: ";
  //cin >> new_user.first_name;
  //cout << endl;

  new_user -> first_name=print_message_input_string("Please Enter your first name: ");

  new_user -> last_name=print_message_input_string("                  last name: ");

  new_user -> phone_number=print_message_input_string("                  phone number: ");

  new_user -> id=print_message_input_string("                  user ID: ");

  new_user -> password=print_message_input_string("                  password: ");

  new_user -> major=print_message_input_string("                  major: ");

  new_user -> degree_level=print_message_input_string("                  degree level: ");

  if (!is_there_any_admins)
  {
    string admin_state_ans;
    admin_state_ans=print_message_input_string("Great! Do you also want to be an Admin of dining ?[yes/no]: ");
    if (admin_state_ans == "yes")
    {
      new_user -> is_admin=true;
      is_there_any_admins=true;
    }
    else
      new_user -> is_admin=false;
  }

  cout << "Your account is successfully created!" << endl ;
  return *new_user;
}