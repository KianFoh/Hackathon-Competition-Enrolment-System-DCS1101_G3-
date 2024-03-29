/*********************
Project Contributions
1. Thien Kian Foh
2. Aiman Hakimin
*********************/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

// prototype
//Global
int menu_option_valid ();
void colourMaker(int);
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
bool option_1_enrolment_slip (string , string , string ,string ,int ,string ,string ,double ,double ,double);
void option_1_enrolment_Text (string ,string ,int ,string ,double ,string);
//Summary Menu
void summary_menu();
void summary_option_choice(int);
void option_2_1_menu();
void option_2_1_display(int);
void option_2_2();
void readEnrolment();
int categoryPriceCounter(string, int);
void starMaker(int);


int main(){
	while(1){
		
		int option1 = 0;
		int option2 = 0;
		main_menu();   
		option1 = menu_option_valid(); //validate input

		if(option1 == 3){         //option 3 Exit
			colourMaker(6);
			cout << endl << "Program successfully closed" << endl;
			colourMaker(15);
			break;	
		}
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
	colourMaker(79);
	cout << "<<Hackathon Competition>>" << endl;
	colourMaker(9);
	cout << "1) Enrolment" << endl;
	colourMaker(14);
	cout << "2) View summary report" << endl;
	colourMaker(10);
	cout << "3) Exit" << endl << endl;
	colourMaker(15);
	cout << "Enter Option: ";
}

int menu_option_valid (){                                // validate user input option 
	int option;
	while (!(cin >> option) || option < 1 || option >3 ){        // checking for input failure and make sure option number between 1 to 3
		colourMaker(12);
		cout << endl << "Invalid option please reenter again : ";
		colourMaker(15);
		cin.clear();
		cin.ignore(INT_MAX , '\n');
	}	
	return option;                                               //return valid option
}
//**************************************************************************************************************
//Option 1 or enrolment Menu
void option_1 (){                                             // option 1 function 
	bool Error = false;
	string e_num , e_date , name , adr ,c_n , category , member;
	double ini_price , discount , total_price;
	int age;
	while (1){
		discount = 0;
		
		colourMaker(11);
		cout << endl << "Enter your enrolment number : ";
		colourMaker(15);
	    e_num = option_1_e_num_valid();            
		
		colourMaker(3);              
		cout << endl << "Enter your enrolment date day,month,year : ";
		colourMaker(15);
		e_date = option_1_e_date_valid();
		
		colourMaker(11);
		cout << endl << "Enter your Name : ";
		cin.ignore();
		colourMaker(15);
		getline (cin, name);
		
		colourMaker(3);
		cout << endl << "Enter your Address : ";
		colourMaker(15);
		getline (cin, adr); 
		
		colourMaker(11);
		cout << endl << "Enter your Contact Number : ";
		colourMaker(15);
		c_n = option_1_c_n_valid();
		cout << endl;
		
		colourMaker(3);
		cout << "Enter your age : ";
		colourMaker(15);
		age = option_1_age_valid();
		cout << endl;
		
		colourMaker(12);
		cout << "1 - Primary " << endl;                                                 //get category
		colourMaker(6);
		cout << "2 - Secondary" << endl;
		colourMaker(9);
		cout << "3 - Open" << endl;
		colourMaker(11);
		cout << "Enter your category : ";
		colourMaker(15);
		category = option_1_category_valid(age);
		
		colourMaker(3);
		cout << endl << "Are you a member of Creative Programming Club member Y or N : ";        //Creative Programming Club member Y or N
		colourMaker(15);
		member = option_1_member_valid();                                                        // return string Yes or No
		
		ini_price = option_1_ini_price(category);                                                // initial price
		
		if (member == "Yes")                                                                    // get discount for member only
			discount = ini_price * 10 / 100;
		
		total_price = ini_price - discount;                                                     // get total price
		
		colourMaker(14);
		cout << endl << "Amount of payment is RM" << total_price << "." << endl << endl;
		colourMaker(15);
		
		Error = option_1_enrolment_slip (e_num,  e_date,  name, adr, age, member, category, ini_price, discount, total_price);
    
		if (Error == true){
			colourMaker(12);
			cout << endl << "Failed to enrol Please try again" << endl;
			colourMaker(15);
			continue;
		}
		
		option_1_enrolment_Text (e_num, name, age, category, total_price, c_n);
		
		colourMaker(6);
		cout << "Enrollment done successfully." << endl << endl;
		colourMaker(15);
		
		categoryPriceCounter(category,total_price);			//this is used to update the summary after system has runned
	
	break;
	}
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
		
		colourMaker(12);	
		cout << "\nInvalid enrolment number please reenter again : ";
		colourMaker(15);
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
			colourMaker(12);                               
			cout << endl << "invalid enrolment date please reenter again : ";
			colourMaker(15);
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
			colourMaker(12);
			cout << endl << "Invalid contact number please reenter again : ";
			colourMaker(15);
			continue;
		}
		break;
	}
	
	return c_n;	                                                                  //return contact number 
}

int option_1_age_valid(){
	int age;
	while (!(cin >> age) || age < 6 || age > 130){
		colourMaker(12);
		cout << endl << "Invalid age please reenter again : ";
		colourMaker(15);
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
			colourMaker(12);                 
			cout << endl << "Invalid category please reenter again : ";
			colourMaker(15);
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
				colourMaker(12);
				cout << endl << "Invalid input please reenter again : "; 
				colourMaker(15);               
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

bool option_1_enrolment_slip (string e_num, string e_date, string name,string adr,int age                             // function for slip text file
							 ,string member,string category,double ini_price,double discount,double total_price){ 

	bool error = false;
	fstream enrolment_slip;
	enrolment_slip.open(e_num + ".txt", ios::app);
	if (enrolment_slip.is_open()){
		enrolment_slip << "Hackathon Competition Enrolment Slip" << endl;
		for (int counter = 1; counter <= 42; counter++)
			enrolment_slip << "*";
		enrolment_slip << endl << fixed << setprecision(2)
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
				  
		enrolment_slip.close();
	}
	else
		error = true;
	
	return error;
}

void option_1_enrolment_Text (string e_num, string name, int age, string category, double total_price, string c_n){  //function for add/update enrolment text file
	fstream enrolment;
	enrolment.open("enrolment.txt", ios::app);
		if (enrolment.is_open()){
			enrolment << "Category : " << category << endl
					  << "Name : " << name << endl
					  << "Contact number : " << c_n << endl
					  << "Age : " << age << endl
					  << "Enrolment number : " << e_num << endl
					  << "Payment : RM" << fixed << setprecision(2) << total_price << endl <<endl;
					  
			enrolment.close();
		}
}
//**************************************************************************************************************
//Summary Menu 
void summary_menu(){									//display summary menu
	colourMaker(79);
	cout << endl<< "<<Hackathon Competition>>" << endl;
	colourMaker(13);
	cout << "1) List all the participant" << endl;
	colourMaker(11);
	cout << "2) Enrolment Summary" << endl;
	colourMaker(10);
	cout << "3) Back to Main Menu" << endl << endl;
	colourMaker(15);
	cout << "Enter Option: ";
}

void summary_option_choice(int option2){			// option selection for summary menu
		switch(option2){
		case 3:
			break;
		case 1:
			option_2_1_menu();
			option_2_1_display(menu_option_valid ());
			break;
		case 2:
			option_2_2();
			break;
		}	
}

void option_2_1_menu(){                                  //option 2 > option 1 menu
	colourMaker(79);
	cout << endl<< "<<Hackathon Competition>>" << endl;
	colourMaker(12);
	cout << "1) Primary" << endl;
	colourMaker(6);
	cout << "2) Secondary" << endl;
	colourMaker(9);
	cout << "3) Open" << endl << endl;
	colourMaker(15);
	cout << "Which Category participant would you like to list : ";
}

void option_2_1_display(int option){                                 // display all participant data from enrolment text file for the category user input
	string line, category;
	int cout_counter = 0;
	if (option == 1){
		category = "Primary";
		colourMaker(12);
	}                                           
	else if (option == 2){
		category = "Secondary";
		colourMaker(6);
	}
	else{
		category = "Open";
		colourMaker(9);
	}
	
	cout << endl << "Listing all the participant information in the " << category << " category :" << endl;  
	colourMaker(15);               
	fstream read_enrolment_text;                                      
	read_enrolment_text.open("enrolment.txt", ios::in);               // open enrolment text file
		if (read_enrolment_text.is_open()){                           // check if it's open			
			while(!read_enrolment_text.eof()){                        // keep looping until end of the line
				getline(read_enrolment_text, line);                  // get everyline store into string line
				if (cout_counter > 0){                               // counter for print the data 4 line only
					cout << line << endl;
					cout_counter--;
				}
	
				if (line.find(category) != string::npos){             // check if the category key word is in the line
					cout_counter = 4;                                 // if yes cout counter become 4 to print 4 line following by the category
					cout << endl;
				}
			}
			read_enrolment_text.close();
		}	
}

//global variable
int primaryCount = 0,secondaryCount = 0,openCount = 0;
float primaryTotal = 0,secondaryTotal = 0,openTotal = 0;

void option_2_2(){
	
	bool hasRunned;
	
	if(hasRunned == false){				//if the program has read the enrolment.txt. do not make it run again but instead use categoryPriceCounter. saves memory
		primaryCount = 0,secondaryCount = 0,openCount = 0;
		primaryTotal = 0,secondaryTotal = 0,openTotal = 0;
		readEnrolment();
		hasRunned = true;	
	}
	
	colourMaker(176);
	cout << "Enrolment Summary" << endl;	//Option 2 of main menu and option 2(Enrollment SUmmary)
	colourMaker(15);
	for(int i = 0; i <= 20; i++){
		cout << "-";
	}
	cout << "\n";
			
	cout << setw(15) << left << "Category"				//display first line
		 << setw(20) << right << "Number of People"	
		 << setw(14) << "Price(RM)\n";
	
	cout << fixed << setprecision(2);	

	colourMaker(12);
	cout << setw(15) << left << "Primary"			//display primary count and total price
	     << setw(20) << right << primaryCount
	     << setw(12) << primaryTotal << "   ";
		 
	starMaker(primaryCount);
	
	cout << endl;
	
	colourMaker(6); 
	cout << setw(15) << left << "Secondary"		//display secondary count and total price
	     << setw(20) << right << secondaryCount
	     << setw(12) << secondaryTotal << "   ";
	      
	starMaker(secondaryCount);
	
	cout << endl;
	
	colourMaker(9); 
	cout << setw(15) << left << "Open"			//display open count and total price
		 << setw(20) << right << openCount
	     << setw(12) << openTotal << "   ";
	     
	starMaker(openCount);
	
	cout << endl;
	
	colourMaker(15); 
	cout << "(Each "; 
	colourMaker(14);
	cout << "*";
	colourMaker(15);
	cout << " represents 1 participant)" << endl;
	cout << "(Each ";
	colourMaker(11);
	cout << "%";
	colourMaker(15);
	cout << " represents 10 participant)" << endl;
	cout << "(Each ";
	colourMaker(13);
	cout << "#";
	colourMaker(15);
	cout << " represents 50 participant)" << endl;
	cout << "(Each ";
	colourMaker(10);
	cout << "@";
	colourMaker(15);
	cout << " represents 100 participant)" << endl;
	
}


void readEnrolment(){
	
	bool primaryTrue = false,secondaryTrue = false,openTrue = false; 
	string input; 
	fstream nameFile; 
	
	nameFile.open("enrolment.txt", ios::in); 			//open file
	
	if (nameFile){
		getline(nameFile, input);
		
		while (nameFile){
			
			//cout << input << endl;							//just some test
			
			if (input.find("Primary") != string::npos){      //Primary Count     
				primaryCount++;
				primaryTrue = true;
			}
			else if (input.find("Secondary") != string::npos){      //Secondory Count     
				secondaryCount++;
				secondaryTrue = true;
			}
			else if (input.find("Open") != string::npos){            //Open Count
				openCount++;
				openTrue = true;
			}	
					
			if(input.find("Payment") != string::npos){		//assign payment to the right category
				
				string payment[2];
				payment[0] = input[12];
				payment[1] = input[13]; 
				string paymentCombo = payment[0] + payment[1];
				int paymentFull = stoi(paymentCombo);
				
				
				if(primaryTrue == true){
					primaryTotal += paymentFull;
					primaryTrue = 0;
				}
				else if(secondaryTrue == true){
					secondaryTotal += paymentFull;
					secondaryTrue = 0;
				}
				else if(openTrue == true){
					openTotal += paymentFull;
					openTrue = 0;
				}
			}
					
			getline(nameFile, input);
		}
		//cout << "Primary " << primaryTotal << " Secondary " << secondaryTotal << " Open " << openTotal;		//just some test
		
		nameFile.close();			//close file
	}
	else{
		nameFile.close();
	}
}

int categoryPriceCounter(string category, int total_price){ //calculates the category total and price total
															
	if(category == "Primary"){
		++primaryCount;
		primaryTotal += total_price;
	}
	else if(category == "Secondary"){
		++secondaryCount;
		secondaryTotal += total_price;
	}
	else{
		++openCount;
		openTotal += total_price;
	}
}

void colourMaker(int colour){		//adds some colour to text
	HANDLE hConsole;
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, colour);
}

void starMaker(int counter){					//properly show data on summary 
	if(counter >= 100){
		colourMaker(10);
		for(int i = 1;i <= counter/100;i++){
			cout << "@";
		}
		colourMaker(13);
		for(int i = 1;i <= (counter-100 * (counter/100))/50;i++){
			cout << "#";
		}
		colourMaker(11);
		for(int i = 1; i <= (counter - 50 * (counter/50))/10;i++){
			cout << "%";
		}
		colourMaker(14);
		for(int i = 1; i <= (counter - 10*(counter/10)); i++){
			cout << "*";
		}
	}
	else if(counter >= 50){
		colourMaker(13);
		for(int i = 1; i <= counter/ 50; i++){
			cout << "#";
		}
		colourMaker(11);
		for(int i = 1; i <= (counter - 50*(counter/50))/10;i++){
			cout << "%";
		}
		colourMaker(14);
		for(int i = 1; i <= counter % 10; i++){
			cout << "*";
		}
	}
	else if(counter >= 10){
		colourMaker(11);
		for(int i = 1; i <= counter/10;i++){
			cout << "%";
		}
		colourMaker(14);
		for(int i = 1; i <= counter % 10; i++){
			cout << "*";
		}
	}
	else{
		colourMaker(14);
		for(int i = 1; i <= counter; i++){
			cout << "*";
		}
	}
}
