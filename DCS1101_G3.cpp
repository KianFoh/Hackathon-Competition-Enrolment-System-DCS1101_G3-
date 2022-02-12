#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// prototype
int main_menu_option_valid ();
void option_1 ();
string option_1_e_num_valid();
bool option_1_e_num_string_valid(string);

int main(){
	while(1){
		
		// main menu
		int option;
		cout << "<<Hackathon Competition>>" << endl;
		cout << "1) Enrolment" << endl;
		cout << "2) View summary report" << endl;
		cout << "3) Exit" << endl << endl;
		cout << "Enter Option: ";
		option = main_menu_option_valid ();   //this function allow user to input option and validate the data


		if(option == 3)         //option 3 Exit
			break;	
			
		switch(option){
			
			case 1:{            // option 1
				option_1 ();
			
				break;
			}
			case 2:{           //option 2
			
			
				break;
			}
		}
		
	}
	
  return 0;
}

int main_menu_option_valid (){                                // validate user input option 
	int option;
	while (!(cin >> option) || option < 1 || option >3 ){
		cout << endl << "Invalid option please reenter again : ";
		cin.clear();
		cin.ignore(INT_MAX , '\n');
	}	
	return option;
}

void option_1 (){
	string e_num;
	
	cout << endl << "Enter enrolment number : ";
    e_num = option_1_e_num_valid();
    cout << endl << "Enter enrolment date day, month, year : ";
    
    
	
}

string option_1_e_num_valid(){                                // allow user to input enrolment number and validate the data 
	string e_num_string , e_num;           
	char e_num_ch;
	
	while(!(cin >> e_num_ch >> e_num_string) || e_num_ch != 'E' || !option_1_e_num_string_valid(e_num_string)){     // validate first input must be E and no input failure 
		cout << endl << "\nInvalid enrolment number please reenter again : ";                                                          
	}
	e_num = e_num_ch + e_num_string;
	
	return e_num;
}

bool option_1_e_num_string_valid(string e_num_string){         // validate the input following by E

	bool true_or_false = true;
	char e_num_string_digit;
	
	for (int counter = 0; counter < e_num_string.length(); counter++){        //validate all string must be integer
		e_num_string_digit = e_num_string.at(counter);
		true_or_false = isdigit(e_num_string_digit);
		if(true_or_false == false)
			break;
	}

	if (e_num_string.length() != 5)                                          //validate all string must be 5 digits 
	true_or_false = false;

	return true_or_false;
}
	
	
	




