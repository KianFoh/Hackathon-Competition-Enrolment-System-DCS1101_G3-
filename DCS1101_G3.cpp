#include <iostream>
#include <string>
using namespace std;

// prototype
int main_menu_option_valid ();
void option_1 ();
string option_1_e_num_valid();


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

void option_1 (){                                             // option 1 function 
	string e_num , e_date;
	
	cout << endl << "Enter enrolment number : ";
    e_num = option_1_e_num_valid();                          

    
    
	
}

string option_1_e_num_valid(){                                // allow user to input enrolment number and validate the data 
	string e_num_string;
	char e_num_string_digits;
	bool true_or_false = true , true_or_false_digits = true;
	
	while(1){
		cin >> e_num_string;
		
		if (e_num_string.length() != 6 || e_num_string.at(0) != 'E' )
			true_or_false = false;
		
		if (true_or_false == true){
			for (int counter = 1; counter < e_num_string.length(); counter++){
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
	return e_num_string;
}







