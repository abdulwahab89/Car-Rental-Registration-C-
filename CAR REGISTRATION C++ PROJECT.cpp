//Ths program is about the CAR RENTAL SYSTEM 
#include<iostream>
#include<conio.h>
using namespace std;
int getinput;
char getinput8;
string findcar;
bool ex=false;
string fname,lname;
int const size=5;
int j;
int package;
string subscription;
string carname;
int carmodel;
int count=0;
struct Vehicle{    //The struct is used to struct vehicle contents
	string Car_Name;
	int Car_Model;
	int Car_Rent;
}vehicles[size]; 
static class RentalSys{    //This is the main class for RentalSys. 
	public:
void getcustomerDetails(){       //This void function gets data from the user
    cout<<"____ Registration form____ "<<endl;
	cout<<"Enter First Name: "<<endl;
	getline(cin,fname);
	cout<<"Enter Last Name: "<<endl;
	getline(cin,lname);
	cout<<"Choose your pacakage : "<<endl;
	cout<<"1.Monthly Package\t 2.Weekly Package \t 3.Daily Package\n";
	cin>>getinput;
	cin.ignore();
	    while(cin.fail())  //This condition is used incase the cin fails to get input.
	    {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers(i.e 1 to 3).\n";
        cin>>getinput; 
		cin.ignore();
    }
	if(getinput==1){
	package=vehicles[j].Car_Rent*30;
		subscription="Monthly";
	}
	else if(getinput==2){
	package=vehicles[j].Car_Rent*7;
		subscription="Weekly";
	}
	else if(getinput==3){
	package=vehicles[j].Car_Rent;
		subscription="Daily";
	}
	else{
	 cout<<"Invalid Choice"<<endl;
		getcustomerDetails();
	}
}
void booklist(){              //void function where vehicles are booked by the user are stored here.
	cout<<"-------Vehicles booked---------"<<endl;
	if(carmodel==0){
	cout<<"You don't have any bookings"<<endl;
	cout<<endl;
	}else{
		cout<<"First Name: "<<fname<<endl;
		cout<<"Last Name: "<<lname<<endl;
		cout<<"Vehicle name: "<<carname<<endl;		
	cout<<"Vehicle Model: "<<carmodel<<endl;
	cout<<"Package :"<<(char)36<<subscription<<endl;
	cout<<"Amount: "<<(char)36<<package<<endl;
}
}
void deleteCar(){  //the void deleteCar function deletes the car details
	booklist();
	if(carmodel!=0){
	cout<<"Do you want to cancel the booking[y/n]"<<endl;
	cin>>getinput8;
	if(getinput8=='y'){
		carmodel=0;
		count=0;
		cout<<"Car Sucesfully unbooked! "<<endl;
	}
	else{
	ex=true;	
	}
}
cout<<"Press enter to go back"<<endl;
getch();
system("cls");
}
 void searchCar(){ //this function searches for the vehicle entered by the user
do{
cout<<"Enter the vehicle name: [Enter 3 to go back to menu]"<<endl;
cout<<"\n\n Vehicle name: ";
	getline(cin,findcar);
	cin.ignore();
	for(j=0; j<size; j++){
	if(findcar==vehicles[j].Car_Name){
		cout<<"----Vehicle Information----"<<endl;
		cout<<"Vehicle Name: "<<vehicles[j].Car_Name<<endl;		
		cout<<"Vehicle Model: "<<vehicles[j].Car_Model<<endl;		
		cout<<"Per day: "<<vehicles[j].Car_Rent<<endl;		
		cout<<"Enter 'y' to add this vehicle to booklist."<<endl;
		cin>>getinput8;
		cin.ignore();
		if(getinput8=='y' && count!=1){	
			carname=vehicles[j].Car_Name;
			carmodel=vehicles[j].Car_Model;
			getcustomerDetails();
			count++;
			cout<<"Congratulations! you have booked "<<vehicles[j].Car_Name<<endl;
			cout<<"Enter 3 to go back to menu"<<endl;
			cin>>findcar;
			system("cls");
			cin.ignore();
			if(findcar=="3"){
				ex=true;
			}
			else{
				system("cls");
				searchCar();
			}
		}
		else if(count>=1){
			system("cls");
		    cout<<"You can't book more than one vehicle at a time"<<endl;
			searchCar();
		}
		else{
		system("cls");
		searchCar();
		}	
		}
	else if(findcar=="3"){	
	ex=true;
	}
	else if(j==size && findcar!=vehicles[j].Car_Name){
		searchCar();
	}
	}
	}while(!ex);
}
void carDetails(){ //shows car details
for(int i=0;i<size; 
i++){
cout<<"Car name: "<<vehicles[i].Car_Name<<endl;
cout<<"Car model: "<<vehicles[i].Car_Model<<endl;
cout<<"Car Rent: "<<vehicles[i].Car_Rent<<endl;
cout<<"*************"<<endl;
}
}
void showCustomer(){ //void function displays the main menu
do{
string findcar;
cout<<"                                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"                                                   	MAIN MENU\n";
cout<<"                                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"\n\nWhat would you like to do? \n";
cout<<"\n\n 1.Car details \n 2.Book a car \n 3.Bookings \n 4.Cancel Bookings \n 5.Go back\n ";
cout<<"\n\n OPTION: ";
cin>>getinput;
system("cls");
	    while(cin.fail()) //this condition is used if cin fails to get input 
	    {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers(i.e 1 to 5).\n";
        showCustomer();
    }
cin.ignore();
if(getinput==1){
	carDetails();
cout<<"Press any key to get back to menu"<<endl;
getch();
system("cls");
showCustomer();
}
else if(getinput==2){
searchCar();
system("cls");
showCustomer();
}
else if(getinput==3){
	booklist();
	cout<<"Press any key to go back to menu"<<endl;
	getch();
	system("cls");
	showCustomer();
}
else if(getinput==4){
	deleteCar();
	showCustomer();
	}
else if(getinput==5){
	ex=true;
}
	else{
		cout<<endl<<endl;
		cout<<"Invalid Input! "<<endl;
		showCustomer();
	}
}while(!ex);
}
void userInterface(){ //This is the main interface
{
	string findcar;
	cout<<"\n      Hello welcome to the Car Rental! \a \n ";
	cout<<"\n      Press 1 to login as a customor \n";
	cout<<"\n      Press 2 to exit; \n";
	cout<<"\n\n\n     OPTION: ";
	cin>>getinput;
	system("cls");
	cin.ignore();
	    while(cin.fail())
	    {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers(i.e 1 to 2).\n";
        userInterface();
        cin.ignore();
    }
    if(getinput==1){
    	showCustomer();
    	userInterface();
   	}
	else if(getinput==2){
		ex=true;
	}
	else{
	cout<<"Invalid choice"<<endl;
	getinput=getch();
	cin.ignore();
	userInterface();
	}
}
}
void data(){  //This is the data of the vehicles 
	vehicles[0].Car_Name="Toyota";
	vehicles[0].Car_Model=2010;
	vehicles[0].Car_Rent=430;
	vehicles[1].Car_Name="Honda";
	vehicles[1].Car_Model=2004;
	vehicles[1].Car_Rent=345;
	vehicles[2].Car_Name="Lexus";
	vehicles[2].Car_Model=2014;
	vehicles[2].Car_Rent=439;
	vehicles[3].Car_Name="Mazda";
	vehicles[3].Car_Model=1994;
	vehicles[3].Car_Rent=200;
	vehicles[4].Car_Name="Chevrolet";
	vehicles[4].Car_Model=2022;
	vehicles[4].Car_Rent=600;
}
};
int main(){  //Main function
	cout<<"\n\n\n\n                         ````````````````````````````````````````    "<<endl;
	cout<<"\n                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  "<<endl;
	cout<<"                                    CAR RENTAL SYSTEM"<<endl;
	cout<<"\n                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\n                         ````````````````````````````````````````"<<endl;
	cout<<"\n\n";
	RentalSys.userInterface();
}
//end of programmm
