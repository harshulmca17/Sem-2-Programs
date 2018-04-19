#include <iostream>
#include <fstream>
#define FILE_NAME "9BFILE.dat"

using namespace std;

//class employee declaration
class Employee {
private : 
	int 	empID;
	char 	empName[100] ;
	char 	designation[100];
public  :
	//function to read employee details
	void readEmployee(){
		cout<<"EMPLOYEE DETAILS"<<endl;
		cout<<"ENTER EMPLOYEE ID : " ;
		cin>>empID;
		cin.ignore(1);
		cout<<"ENTER  NAME OF THE EMPLOYEE : ";
		cin.getline(empName,100);

		cout<<"ENTER DESIGNATION : ";
		cin.getline(designation,100);
		
	}

	void displayEmployee(){
		cout<<"EMPLOYEE ID: "<<empID<<endl
		 <<"EMPLOYEE NAME: "<<empName<<endl
		 <<"DESIGNATION: "<<designation<<endl;
	}
};

int main(){
	
	Employee emp;
	emp.readEmployee();
	
	fstream file;
	file.open(FILE_NAME,ios::out|ios::binary|ios::app);
	if(!file){
		cout<<"Error in creating file...\n";
		return -1;
	}
	
	file.write((char*)&emp,sizeof(emp));
	file.close();
	cout<<"Date saved into file the file.\n";
	
	file.open(FILE_NAME,ios::in|ios::binary);
	if(!file){
		cout<<"Error in opening file...\n";
		return -1;
	}
	
	while(!file.eof()){
		if(file.read((char*)&emp,sizeof(emp))){
				cout<<endl<<endl;
				cout<<"Data extracted from file..\n";
				emp.displayEmployee();
		}
		else{
			cout<<"File Empty\n";
			return -1;
		}
	}
	
	file.close();	
	return 0;
}