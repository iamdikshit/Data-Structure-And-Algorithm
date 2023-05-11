/*
	class and object
*/

#include<bits/stdc++.h>
using namespace std;

class Person{
	// if no access modifier than the property will be private
	// And private properties can be access with in the class , not out side the class..
	// Here password is private property of Person
	string password;
	public:
		// Public properties can be access with in the class and outside the class
	string name;
	int age;
	bool isActive;
	
	/******************************************
		Constructor (Default construtor) : Constructor is a function which runs when we 
										   create any object
					  of a class. And constructor function name is same as class name.
	*******************************************/
	Person(){
		isActive = true;
	}
	
	// Parameterized constructor
	Person(string name,int age){
		this->name = name;
		this->age = age;
		this->isActive = true;
	}
	
	/*
		Copy Constructor
		Default copy constructor use shallow copy means both object points same address
		and no need to create default copy constructor. it is created by compiler 
		but if you want to create own copy constructor you can create.
	*/
	
	/*
		Getter setter method
			Basically to access the private property outside the class we use
			getter setter method.
			getter -> get the data of private property
			setter -> set the data of private property
	*/
	string getPass(){
		return password;
	}
	void setPass(string pass)
	{
		this->password = pass;
	}
	
	void display()
	{
		cout<<"\nUser Data\n";
		cout<<"Name:"<<this->name<<endl;
		cout<<"Age:"<<this->age<<endl;
		cout<<"Active:"<<this->isActive<<endl;
		cout<<"Password:"<<this->getPass()<<endl;
	}
	
};



int main(){
	Person user1;
	user1.name = "Dikshit Bhardwaj";
	user1.age = 25;
	user1.setPass("tony@123");
	user1.display();
	
	
	// Dynamic object creation using pointer concept.
	Person *user2 = new Person();
	user2->name = "Anirban";
	user2->age = 24;
	user2->display();
	
	// Using Parameterized constructor
	Person user3 =  Person("Ram",30);
	user3.display();
	
	// Using Dynamic object creation
	Person *user4 = new Person("Samsung",28);
	user4->display();
	
	// Default copy constructor
	Person user5 = Person(user1);
	user5.name = "Rakesh";
	user5.setPass("tonyjarvis");
	user5.display();
	user1.display();

	
	
	return 0;
}
