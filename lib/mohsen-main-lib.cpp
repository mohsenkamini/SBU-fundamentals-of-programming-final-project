#include <iostream>
#include <mohsen-main-header.h>
#include <global_vars.h>
#include <string>
#include <ctime>  // only used to get the current time of the system

//#include <structures.h>
using namespace std;





void print_warning (char* text) 
{
  const std::string red("\033[0;31m");
  const std::string normal("\033[0;37m");
  cout << red << text << normal << endl;
}

string print_message_input_string (string message)
{
  string result;
  cout << message;
  getline(cin >> ws,result);
  // >> ws removes any whitespace from input
  cout << endl;
  return result;
}

int print_message_input_int (string message)
{
  int result;
  cout << message;
  cin >> result;
  cout << endl;
  return result;
}

float print_message_input_float (string message)
{
  float result;
  cout << message;
  cin >> result;
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
  number_of_users++;
  return *new_user;
}

bool login_prompt (user users_array[])
{
  string user_id, password;
  user_id=print_message_input_string("Login Prompt:\nPlease enter your ID: ");
  password=print_message_input_string("             your password: ");
  return login(users_array,user_id,password);
}

bool login (user users_array[], string user_id, string password) {
  bool flag=false;
  for (int i=0 ; i < max_number_of_users ; i++ )
  {
    if (users_array[i].id == user_id)
      {
        if (users_array[i].password == password)
        {
          if (users_array[i].is_admin)
          {
            cout << "You are successfully logged in with admin privilege!"<<endl;
            logged_in_user_id=users_array[i].id;
            is_a_user_logged_in=true;
            is_an_admin_logged_in=true;
          }
          else
          {
            cout << "You are successfully logged in!"<<endl;
            logged_in_user_id=users_array[i].id;
            is_a_user_logged_in=true;
          }
          flag=true;
          break;
        }
      }
        
  }

  if (!flag)
    print_warning("The user ID and password does not match");

  return flag;
}

void logout () {

  logged_in_user_id="";
  is_a_user_logged_in=false;
  is_an_admin_logged_in=false;
}

int index_of_user_id(user users_array[],string user_id)
{
  int i;
  for (i=0 ; users_array[i].id != user_id ; i++);
  return i;
}

date translate_ctime (string string_from_ctime) {
  date result;
  
  result.dow=string_from_ctime.substr(0,string_from_ctime.find(' '));
  
  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);
  result.month=string_from_ctime.substr(0,string_from_ctime.find(' '));

  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);
  result.dom=string_from_ctime.substr(0,string_from_ctime.find(' '));

  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);

  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);
  result.year=string_from_ctime.substr(0,string_from_ctime.find(' '));

  return result;
}

date todays_date () {
  date result;
  time_t now = time(0);
  string dt = ctime(&now);
  cout << dt;
  result=translate_ctime(dt);
  return result;
}









void admin_menu (user users_array[],string user_id) 
{
  cout << "Hey there! you're an admin";
}


void charge_wallet (user users_array[],string user_id,float amount) 
{
  users_array[index_of_user_id(users_array, user_id)].wallet_balance += amount;
} 


void dining_menu (user users_array[],string user_id) 
{
  int reserve_or_charge=print_message_input_int("\n \n   1) Reserve\n   2) Add money to balance\n   3) back\n   4) logout\n   [1/2/3/4]: ");
  switch (reserve_or_charge)
  {
    case 1:
      cout << "to be made";
      dining_menu(users_array, user_id);
      break;

    case 2:
      {
        float amount=print_message_input_float("\nHow much do you want to increase your wallet? [in \"hezar Toman\"]: ");
        charge_wallet(users_array, user_id,amount);
        cout << "\nYour balance is increased by " << amount << " hezar Toman!" << endl;
        dining_menu(users_array, user_id);
        break;
      }
    case 3:
      break;      
    case 4:
      logout();
      break;
  }
}

void change_password(user users_array[],string user_id)
{
  string current_password=print_message_input_string("\nPlease enter your current password: ");
  int i=index_of_user_id(users_array,user_id);
  if (current_password == users_array[i].password)
  {  
    string new_password=print_message_input_string  ("\n                  new password: ");
    users_array[i].password = new_password; 
    cout << "\n Password successfully changed." << endl;
  }
  else
  {
    cout << current_password<< endl <<endl;
    print_warning("\nSorry! the password you provided did not match your current password!");
  }
}


void show_profile(user users_array[],string user_id)
{
  int i=index_of_user_id(users_array, user_id);
  cout << "First name: " << users_array[i].first_name << endl;
  cout << "Last name: " << users_array[i].last_name << endl;
  cout << "Phone number: " << users_array[i].phone_number << endl;
  cout << "ID: " << users_array[i].id << endl;
  cout << "Password: " << "********" << endl;
  cout << "Major: " << users_array[i].major << endl;
  cout << "Degree level: " << users_array[i].degree_level << endl;
  cout << "Wallet balance: " << users_array[i].wallet_balance << endl;
  cout << "admin state: " << users_array[i].is_admin << endl;

}

 void account_menu (user users_array[], string user_id)
{
  int profile_or_change_password=print_message_input_int("\n \n   1) Show me my profile\n   2) Change my password\n   3) back\n   4) logout\n   [1/2/3/4]: ");
  switch (profile_or_change_password) {

    case 1:
      show_profile(users_array, user_id);
      account_menu(users_array, user_id);
      break;

    case 2:
      change_password(users_array, user_id);
      account_menu(users_array, user_id);
      break;
    case 3:
      break;      
    case 4:
      logout();
      break;
  }
}

void user_menu (user users_array[], string user_id)
{
  int dining_or_account=print_message_input_int("\n \n   1) Dining system\n   2) My account\n   3) logout\n   [1/2/3]: ");
  switch (dining_or_account) {

    case 1:
      dining_menu(users_array, user_id);
      break;

    case 2:
      account_menu(users_array, user_id);
      break;
    case 3:
      logout();
      break;
    

  }
}


void general_menu (user users_array[]) {

  switch (is_a_user_logged_in)
  {
    case 1:
      switch (is_an_admin_logged_in)
      {
        case 1:
          admin_menu(users_array, logged_in_user_id);
          general_menu(users_array);
          break;
        case 0:
          user_menu(users_array, logged_in_user_id);
          general_menu(users_array);
          break;
      }
      break;  
    case 0:
      string signin_or_login=print_message_input_string("\nWhat can I do for you?\n   1) Make me an account\n   2) Log me in\n   [1/2]: ");
      if (signin_or_login == "1")
      {
        if (number_of_users < max_number_of_users)
          users_array[number_of_users]=create_user(&users_array[number_of_users]);
        else
          cout << "This program cannot hold more than "<< max_number_of_users << " users. Please consult the administrator";
      }
      login_prompt(users_array);
      general_menu(users_array);
      break;
  }
}


