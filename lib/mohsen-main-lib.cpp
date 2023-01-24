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



// date related functions

date translate_ctime (string string_from_ctime) {
  date result;
  
  result.dow=string_from_ctime.substr(0,string_from_ctime.find(' '));
  
  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);
  result.month=string_from_ctime.substr(0,string_from_ctime.find(' '));

  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);
  result.dom=stoi( string_from_ctime.substr(0,string_from_ctime.find(' ')) );

  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);

  string_from_ctime=string_from_ctime.substr(string_from_ctime.find(' ')+1);
  result.year=stoi( string_from_ctime.substr(0,string_from_ctime.find(' ')) );

  return result;
}

date todays_date () {
  date result;
  time_t now = time(0);
  string dt = ctime(&now);
  //cout << dt;
  result=translate_ctime(dt);
  return result;
}

int index_of_dow (string days[],int size, string dt_dow) {

  for (int i=0 ; i < size; i++)
  {
    if (dt_dow == days[i])
      return i;
  }
}

int index_of_month (string months[],int size, string dt_month) {

  for (int i=0 ; i < size; i++)
  {
    if (dt_month == months[i])
      return i;
  }
}

int compare_dates (date dt1, date dt2) {

  // This function returns the number of days 
  // it takes to go from dt1 to dt2
  
  int result=0; 
  result = ( ((dt2.year-dt1.year)*number_of_days_in_year) + ((index_of_month(months,number_of_months,dt2.month) - index_of_month(months,number_of_months,dt1.month) )*number_of_days_in_month) + (dt2.dom - dt1.dom) );
  return result;
  
}

string incremented_dow (string dow) {
  int size=number_of_dow;
  if (index_of_dow(days,size,dow) != number_of_dow-1 )
    return days[index_of_dow(days,size,dow)+1];
  
  return days[0];
}

void initiate_calendar (food_item dining[],int size,date today) {

  dining[0].dt=today;
  date base=today;
  for (int i=0 ; i < size-1 ; i++)
  {
    if (base.dom+1 <= number_of_days_in_month)
    {
      base.dom++;
      base.dow=incremented_dow(base.dow);
      dining[i+1].dt.dow=base.dow;
      dining[i+1].dt.dom=base.dom;
      dining[i+1].dt.month=base.month;
      dining[i+1].dt.year=base.year;
    }
    else
    {
      if (index_of_month(months,number_of_months,base.month) != number_of_months-1)
      {
        base.dom=1;
        base.dow=incremented_dow(base.dow);
        dining[i+1].dt.dow=base.dow;
        base.month=months[index_of_month(months,number_of_months,base.month)+1];

        dining[i+1].dt.dom=base.dom;
        dining[i+1].dt.month=base.month;
        dining[i+1].dt.year=base.year;
      }
      else
      {
        base.dom=1;
        base.dow=incremented_dow(base.dow);
        dining[i+1].dt.dow=base.dow;

        base.month=months[0];
        base.year++;

        dining[i+1].dt.dom=base.dom;
        dining[i+1].dt.month=base.month;
        dining[i+1].dt.year=base.year;
      }
      
    }
  }
}

// Add food items



void add_new_food_item (food_item dining[],int index) {
  
  dining[index].fd.name=print_message_input_string("\nPlease enter food name: ");
  dining[index].fd.price= print_message_input_int ("enter price (in hezar Toman): ");
  dining[index].supply= print_message_input_int   ("         enter supply amount: ");
}

void show_week_food_plan_admin(food_item dining[],int index) {

  for (int i=index; i < index+7 ; i++)
  {
    cout << "Plan " << i << ")\n";
    cout << dining[i].dt.dow << "  ";    
    cout << dining[i].dt.dom << "  ";    
    cout << dining[i].dt.month << "  ";  
    cout << dining[i].dt.year << endl ;
    cout << "Defined food for "<< i << ": " ; 
    cout << dining[i].fd.name << " Supply: " <<dining[i].supply<< " Price: " <<dining[i].fd.price<< endl << endl;
  }

}

bool is_resevered_for_userid (food_item dining[],int index, string user_id) {
  for (int i=0 ; i < max_number_of_users ; i++)
  {
    if (dining[index].reserved_by[i] == user_id)
      return true;
  }
  return false; //temporary
}

void show_week_food_plan_user(food_item dining[],int index,string user_id) {

  for (int i=index; i < index+7 ; i++)
  {
    cout << "Plan " << i << ")\n";
    cout << dining[i].dt.dow << "  ";    
    cout << dining[i].dt.dom << "  ";    
    cout << dining[i].dt.month << "  ";  
    cout << dining[i].dt.year << endl ;
    cout << "Defined food for "<< i << ": " ; 
    cout << dining[i].fd.name << " Supply: " <<dining[i].supply<< " Price: " <<dining[i].fd.price<< endl;
    cout << "Reserveration status: " << is_resevered_for_userid(dining,index,user_id)  <<endl << endl;
  }

}

void add_new_food_item_menu(food_item central_dining[],food_item  dorm_dining[]) {

 int central_or_dorm=print_message_input_int("\nChoose Dining:\n   1) Central\n   2) Dorm\n   3) logout\n   [1/2/3]:");
  switch (central_or_dorm){
    case 1:
      for (int i=0 ; i < max_number_of_food_plans ; i+=7)
      {
      show_week_food_plan_admin(central_dining,i);
      int plan_number=print_message_input_int("Choose Plan number: [0/1/2/.../-1(show next week plan)]: ");
      
      if (plan_number == -1)
        continue;

      add_new_food_item(central_dining,plan_number);
      break;
      
      }
      break;
    case 2:
      for (int i=0 ; i < max_number_of_food_plans ; i+=7)
      {
      show_week_food_plan_admin(dorm_dining,i);
      int plan_number=print_message_input_int("Choose Plan number: [0/1/2/.../-1(show next week plan)]: ");
      
      if (plan_number == -1)
        continue;

      add_new_food_item(dorm_dining,plan_number);
      break;
      
      }
      break;
      case 3:
      logout(); 
  }
}

void reserve_food_item(user list_of_users[] ,food_item dining[],int plan_number,string user_id) {

  if (is_resevered_for_userid (dining,plan_number,user_id))
  {
    cout << "\nYou have already reserved this food item!";
    return;
  }
  
  if (compare_dates(todays_date(),dining[plan_number].dt) < 2 )
  {
    cout << "\nYou cannot reserve a food plan for this date." << endl;
    return;
  }

  

  if (dining[plan_number].supply == 0 )
  {
    cout << "\nThere are no more supply of this food Plan."<< endl;
    return;
  }
  
  int half_or_full=print_message_input_int("\nDo you want 1) Half or 2) full? [1/2]: ");
  switch (half_or_full) {
    case 1:
      if ( (dining[plan_number].fd.price*0.5) > list_of_users[index_of_user_id(list_of_users, user_id)].wallet_balance  )
      {
        cout << "\nNOT ENOUGH MONEY!"<< endl;
        return;
      }
      dining[plan_number].supply -= 0.5;
      dining[plan_number].reserved_by[dining[plan_number].reserved_by_index]=user_id;
      dining[plan_number].reserved_by_index++;
      list_of_users[index_of_user_id(list_of_users, user_id)].wallet_balance -= (0.5*dining[plan_number].fd.price) ;

      break;
    
    case 2:
      if (dining[plan_number].supply == 0.5 )
      {
        cout << "\nThere are only 0.5 supply of this food Plan."<< endl;
        return;
      }
      if ( dining[plan_number].fd.price > list_of_users[index_of_user_id(list_of_users, user_id)].wallet_balance  )
      {
        cout << "\nNOT ENOUGH MONEY!"<< endl;
        return;
      }

      dining[plan_number].supply -= 1;
      dining[plan_number].reserved_by[dining[plan_number].reserved_by_index]=user_id;
      dining[plan_number].reserved_by_index++;
      list_of_users[index_of_user_id(list_of_users, user_id)].wallet_balance -= (dining[plan_number].fd.price) ;
  }
}


void reserve_food_item_menu (user list_of_users[] ,food_item central_dining[],food_item dorm_dining[],string user_id) {

  int central_or_dorm=print_message_input_int("\nChoose Dining:\n   1) Central\n   2) Dorm\n   3) logout\n   [1/2/3]:");
  switch (central_or_dorm){
    case 1:
      for (int i=0 ; i < max_number_of_food_plans ; i+=7)
      {
      show_week_food_plan_user(central_dining,i,user_id);
      int plan_number=print_message_input_int("Choose Plan number: [0/1/2/.../-1(show next week plan)]: ");
      
      if (plan_number == -1)
        continue;

      reserve_food_item(list_of_users,central_dining,plan_number,user_id);
      break;
      
      }
      break;
    case 2:
      for (int i=0 ; i < max_number_of_food_plans ; i+=7)
      {
      show_week_food_plan_admin(dorm_dining,i);
      int plan_number=print_message_input_int("Choose Plan number: [0/1/2/.../-1(show next week plan)]: ");
      
      if (plan_number == -1)
        continue;

      reserve_food_item(list_of_users,dorm_dining,plan_number,user_id);
      break;
      
      }
      break;
      case 3:
      logout();
  }

}





void admin_menu (user users_array[],string user_id,food_item central_dining[] , food_item dorm_dining[]) 
{
  cout << "You can add food items in weekly tables here!\n";
  add_new_food_item_menu (central_dining,dorm_dining);
}


void charge_wallet (user users_array[],string user_id,float amount) 
{
  users_array[index_of_user_id(users_array, user_id)].wallet_balance += amount;
} 


void dining_menu (food_item central_dining[],food_item dorm_dining[],user users_array[],string user_id) 
{
  int reserve_or_charge=print_message_input_int("\n \n   1) Reserve\n   2) Add money to balance\n   3) back\n   4) logout\n   [1/2/3/4]: ");
  switch (reserve_or_charge)
  {
    case 1:
      reserve_food_item_menu(users_array, central_dining,dorm_dining,user_id);
      dining_menu(central_dining,dorm_dining,users_array, user_id);
      break;

    case 2:
      {
        float amount=print_message_input_float("\nHow much do you want to increase your wallet? [in \"hezar Toman\"]: ");
        charge_wallet(users_array, user_id,amount);
        cout << "\nYour balance is increased by " << amount << " hezar Toman!" << endl;
        dining_menu(central_dining,dorm_dining,users_array, user_id);
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

void user_menu (food_item central_dining[],food_item dorm_dining[],user users_array[], string user_id)
{
  int dining_or_account=print_message_input_int("\n \n   1) Dining system\n   2) My account\n   3) logout\n   [1/2/3]: ");
  switch (dining_or_account) {

    case 1:
      dining_menu(central_dining,dorm_dining,users_array, user_id);
      break;

    case 2:
      account_menu(users_array, user_id);
      break;
    case 3:
      logout();
      break;
    

  }
}


void general_menu (user users_array[],food_item central_dining[] , food_item dorm_dining[]) {

  switch (is_a_user_logged_in)
  {
    case 1:
      switch (is_an_admin_logged_in)
      {
        case 1:
          admin_menu(users_array, logged_in_user_id,central_dining,dorm_dining);
          general_menu(users_array,central_dining,dorm_dining);
          break;
        case 0:
          user_menu(central_dining,dorm_dining,users_array, logged_in_user_id);
          general_menu(users_array,central_dining,dorm_dining);
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
      general_menu(users_array,central_dining,dorm_dining);
      break;
  }
}


