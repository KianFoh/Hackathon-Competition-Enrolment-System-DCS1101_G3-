#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// prototype
//Global
int menu_option_valid ();
//Main Menu
void main_menu();
void option_1 ();
string option_1_e_num_valid();
string option_1_e_date_valid();
string option_1_c_n_valid();
int option_1_age_valid();
//Summary Menu
void summary_menu();
void summary_option_choice(int);


int main(){
	while(1){
		
		// main menu
		int option1 = 0;
		int option2 = 0;
		main_menu();   
		option1 = menu_option_valid(); //validate input

		if(option1 == 3)         //option 3 Exit
			break;	
			
		switch(option1){
			
			case 1:{            // option 1
				option_1 ();
			
				break;
			}
			case 2:{           //option 2
				while(option2 != 3) {
					summary_menu();
					option2 = menu_option_valid();
					summary_option_choice(option2);
				}
			}
		}
		
	}
	
  return 0;
}
//**************************************************************************************************************
//Main Menu 
void main_menu(){ 										//display main_menu
	cout << "<<Hackathon Competition>>" << endl;
	cout << "1) Enrolment" << endl;
	cout << "2) View summary report" << endl;
	cout << "3) Exit" << endl << endl;
	cout << "Enter Option: ";
}

int menu_option_valid (){                                // validate user input option 
	int option;
	while (!(cin >> option) || option < 1 || option >3 ){        // checking for input failure and make sure option number between 1 to 3
		cout << endl << "Invalid option please reenter again : ";
		cin.clear();
		cin.ignore(INT_MAX , '\n');
	}	
	return option;                                               //return valid option
}

void option_1 (){                                             // option 1 function 
	string e_num , e_date , name , adr ,c_n;
	int age;
	
	cout << endl << "Enter your enrolment number : ";
    e_num = option_1_e_num_valid();            
	              
	cout << endl << "Enter your enrolment date day,month,year : ";
	e_date = option_1_e_date_valid();
	
	cout << endl << "Enter your Name : ";
	cin.ignore();
	getline (cin, name);
	
	cout << endl << "Enter your Address : ";
	cin.ignore();
	getline (cin, adr); 
	
	cout << endl << "Enter your Contact Number: ";
	c_n = option_1_c_n_valid();
	cout << endl;
	
	cout << "Enter your age : ";
	age = option_1_age_valid();
	cout << endl;
    
}

string option_1_e_num_valid(){                                // allow user to input enrolment number and validate
	string e_num_string;
	char e_num_string_digits;
	bool true_or_false = true , true_or_false_digits = true;
	
	while(1){
		true_or_false = true;
		cin >> e_num_string;
		
		if (e_num_string.length() != 6 || e_num_string.at(0) != 'E' )              //validate the length of the string and first char must start with E
			true_or_false = false;
		
		if (true_or_false == true){                                               
			for (int counter = 1; counter < e_num_string.length(); counter++){     //validate the string following E is interger
				e_num_string_digits = e_num_string.at(counter);
				true_or_false_digits = isdigit(e_num_string_digits);
				if (true_or_false_digits == false)
					true_or_false = false;
			}
		}
		if (true_or_false == true)
			break;
		cout << "\nInvalid enrolment number please reenter again : ";
	}
	return e_num_string;                                                           //return the valid enrolment number
}

string option_1_e_date_valid(){                              // allow user to input enrolment date and validate 
	int day , month , year , max_valid_day;
	bool true_or_false , leap_year;
	string e_date = "";
	
	while (1){
		max_valid_day = 31;
		true_or_false = true;
		leap_year = false;
		cin >> day >> month >> year;
		
		if (cin.fail()){                            // validate input failure
			cin.clear();
			cin.ignore(INT_MAX , '\n');
			true_or_false = false;
		}
		else if (int(log10(day)) + 1 <1 || int(log10(day)) + 1 >2 || int(log10(month)) + 1 <1 || int(log10(month)) + 1 >2 || int(log10(year)) + 1 != 4)   //validate day,month,year digits
			true_or_false = false;
			
		if (true_or_false == true ){                        //validate the year is a or not leap year
			if (year % 4 == 0){
			leap_year = true;
			}
			if (month == 4 || month ==6 || month == 9 || month == 11)      //validate the maximum day in the month 
				max_valid_day = 30;
			else if (month == 2){                                          // validate february 
				max_valid_day = 28;
				if (leap_year == true )
					max_valid_day = 29;                                   // validate leap year february 
					
			}
			
			if (month <=0 || month >12)                                 // validate month 
				true_or_false = false;
			
			else if (day <= 0 || day > max_valid_day )                 //validate day
				true_or_false = false;
		}
		if (true_or_false == false){                                    
			cout << "invalid enrolment date please reenter again : ";
			continue;		
		}
		
		break;
	}
	
	if (day <10)                                                         // validate the date in the correct format
		e_date += "0";
	e_date = e_date + to_string(day) + "/";
	if (month <10)
		e_date += "0";
	e_date = e_date + to_string (month) + "/" + to_string (year);

	return e_date;                                                        // return enrolment date
}

string option_1_c_n_valid(){                                 // allow user to input contact number and validate 
	bool true_or_false ,contac_int;
	string c_n;
	char c_n_digits;
	while (1){
		true_or_false = true;
		contac_int = true;
		cin >> c_n;
		if (c_n.length() != 10)     {                        // validate contact number length
			true_or_false = false;
		}
		else{
			for (int counter = 0; counter < c_n.length(); counter++){              // validate contact number must be integer/ digit
			c_n_digits = c_n.at(counter);
			contac_int = isdigit(c_n_digits);
			if (contac_int == false)
				true_or_false = false;
			}
		}
		if (true_or_false == false){
			cout << "Invalid contact number please reenter again : ";
			continue;
		}
		break;
	}
	
	return c_n;	                                                                  //return contact number 
}

int option_1_age_valid(){
	int age;
	while (!(cin >> age) || age < 6 || age > 130){
		cout << endl << "Invalid age please reenter again : ";
		cin.clear();
		cin.ignore(INT_MAX , '\n');
	}
	
	return age;
}
//**************************************************************************************************************
//Summary Menu 
void summary_menu(){									//display summary menu
	cout << "<<Hackathon Competition>>" << endl;
	cout << "1) List all the participant" << endl;
	cout << "2) Enrollment Summary" << endl;
	cout << "3) Back to Main Menu" << endl << endl;
	cout << "Enter Option: ";
}

void summary_option_choice(int option2){			// option selection for summary menu
		switch(option2){
		case 3:
			break;
		case 1:
			cout << "Case 1" << endl;
			break;
		case 2:
			cout << "Case 2" << endl;
			break;
		}	
}






