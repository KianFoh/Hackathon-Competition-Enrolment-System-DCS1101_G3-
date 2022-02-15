#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

// prototype
//Global
int menu_option_valid ();
//Main Menu
void main_menu();
void option_1 ();
// Enrolment Option 1 function
string option_1_e_num_valid();
string option_1_e_date_valid();
string option_1_c_n_valid();
int option_1_age_valid();
string option_1_category_valid(int);
string option_1_member_valid ();
double option_1_ini_price(string);
void option_1_enrolment_slip (string , string , string ,string ,int ,string ,string ,double ,double ,double );
//Summary Menu
void summary_menu();
void summary_option_choice(int);
void option_2_2();
int categoryPriceCounter(string, int);


int main(){
	while(1){
		
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
//**************************************************************************************************************
//Option 1 or enrolment Menu
void option_1 (){                                             // option 1 function 
	string e_num , e_date , name , adr ,c_n , category , member;
	double ini_price , discount , total_price;
	int age;
	
	cout << endl << "Enter your enrolment number : ";
    e_num = option_1_e_num_valid();            
	              
	cout << endl << "Enter your enrolment date day,month,year : ";
	e_date = option_1_e_date_valid();
	
	cout << endl << "Enter your Name : ";
	cin.ignore();
	getline (cin, name);
	
	cout << endl << "Enter your Address : ";
	getline (cin, adr); 
	
	cout << endl << "Enter your Contact Number: ";
	c_n = option_1_c_n_valid();
	cout << endl;
	
	cout << "Enter your age : ";
	age = option_1_age_valid();
	cout << endl;
	
	cout << "1 - Primary " << endl                                                 //get category
		 << "2 - Secondary" << endl
		 << "3 - Open" << endl
		 << "Enter your category : ";
	category = option_1_category_valid(age);
	
	cout << endl << "Are you a member of Creative Programming Club member Y or N : ";        //Creative Programming Club member Y or N
	member = option_1_member_valid();                                                        // return string Yes or No
	
	ini_price = option_1_ini_price(category);                                                // initial price
	
	if (member == "Yes")                                                                    // get discount for member only
		discount = ini_price * 10 / 100;
	
	total_price = ini_price - discount;                                                     // get total price
	
	cout << endl << "Amount of payment is RM" << total_price << "." << endl << endl;
	
	categoryPriceCounter(category, total_price);

	option_1_enrolment_slip (e_num,  e_date,  name, adr, age, member, category, ini_price, discount, total_price);
	

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
		ifstream duplicate;
		
		duplicate.open(e_num_string + ".txt");                                       //validate if there is a duplicate 
		if (duplicate.is_open()){
			duplicate.close();
			true_or_false = false;
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
			cout << endl << "invalid enrolment date please reenter again : ";
			continue;		
		}
		
		break;
	}
	
	if (day <10)                                                         // validate the date in the correct format
		e_date += "0";
	e_date = e_date + to_string(day) + "-";
	if (month <10)
		e_date += "0";
	e_date = e_date + to_string (month) + "-" + to_string (year);

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
			cout << endl << "Invalid contact number please reenter again : ";
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

string option_1_category_valid(int age){                     // allow user to input category and validate
	int category_int;
	string category;
	bool true_or_false;
	while(1){
		true_or_false = false;
		cin >> category_int;
		
		if (cin.fail()){                            // validate input failure
			cin.clear();
			cin.ignore(INT_MAX , '\n');
		}
		if (category_int == 1)                      // primary
			if (age <=12){
				category = "Primary";
				true_or_false = true;
			}
		if (category_int ==2)                  //secondary
			if (age >= 13 && age <= 17){
				category = "Secondary";
				true_or_false = true;
			}

		if (category_int ==3){                       //open
			category = "Open";
			true_or_false = true;
		}
		if (true_or_false == false){                     
			cout << endl << "Invalid category please reenter again : ";
			continue;
		}
		break;
	}
	return category;                                 // return string category
}

string option_1_member_valid (){                             // allow user to input is a member or no
	string member;
		while (1){
			cin >> member;
			
			if (member == "Y" || member =="N"){                        
				if (member == "Y")
					member = "Yes";
					
				else		
					member = "No";
			}
			else{                                                             //validate invalid input
				cout << endl << "Invalid input please reenter again : ";                
				continue; 
			}
			
			break;
		}
		return member;
}

double option_1_ini_price(string category){                  // finding initial price with the category
	double ini_price;
	
	if (category == "Primary")
		ini_price = 20;
	else if (category == "Secondary")
		ini_price = 30;
	else 
		ini_price = 40;
	cout << fixed << setprecision(2);
	return ini_price;
}

void option_1_enrolment_slip (string e_num, string e_date, string name,string adr,int age,string member,string category,double ini_price,double discount,double total_price){ // function for slip text file
	fstream enrolment;
	enrolment.open(e_num + ".txt", ios::app);
	if (enrolment.is_open()){
		enrolment << "Hackathon Competition Enrolment Slip" << endl;
		for (int counter = 1; counter <= 42; counter++)
			enrolment << "*";
		enrolment << endl << fixed << setprecision(2)
			      << "Enrolment Number : " << e_num << setw(24) << "Date : " << e_date << endl <<endl
				  << setw(11) << left << "Name" << setw(4) << left << ":" << name << endl
				  << setw(11) << left << "Address" << setw(4) << left << ":" << adr <<endl
				  << setw(11) << left << "Age" << setw(4) << left << ":" << age <<endl
				  << setw(11) << left << "Member" << setw(4) << left << ":" << member << endl <<endl
				  << setw(22) << left << "Description" << "Fees " << "(RM)" <<endl
				  << setw(22) << left << category << right << setw(9) << ini_price << endl
				  << setw(22) << left << "Discount (10%)" << right << setw(9) << discount << endl
				  << setw(22) << left << "Total Payment"  << right << setw(9) << total_price <<endl <<endl
				  << "All the best!";
		
	}
	
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
			option_2_2();
			break;
		}	
}

int primary_count,primary_total,secondary_count,secondary_total,open_count,open_total;

void option_2_2(){
	
	cout << "Enrolment Summary" << endl;	//Option 2 of main menu and option 2(Enrollment SUmmary)
	for(int i = 0; i <= 20; i++){
		cout << "-";
	}
	cout << "\n";
			
	cout << setw(15) << left << "Category"
		 << setw(20) << right << "Number of People"	
		 << setw(10) << "Price\n";
			
	cout << setw(15) << left << "Primary"
	     << setw(20) << right << primary_count
	     << setw(10) << primary_total << endl;
	
	cout << setw(15) << left << "Secondary"
	     << setw(20) << right << secondary_count
	     << setw(10) << secondary_total << endl;
	     
	cout << setw(15) << left << "Open"
		 << setw(20) << right << open_count
	     << setw(10) << open_total << endl;
	
	cout << "(Each * represents 1 participant)\n\n";
}


int categoryPriceCounter(string category, int total_price){
	
	if(category == "Primary"){
		++primary_count;
		primary_total += total_price;
	}
	else if(category == "Secondary"){
		++secondary_count;
		secondary_total += total_price;
	}
	else{
		++open_count;
		open_total += total_price;
	}
}





