#pragma once

#include <iostream>
#include <string>

using namespace std;

//typedef enum State {
//	NY,
//	PA,
//	RI,
//	NH, 
//	VT,
//	MA,
//	CT,
//	ME
//}State;


class Donor {
public:
	Donor();
	Donor(string fn, string ln, string id, string pw, int _age, int sn, string sname, string _town, string code);
	Donor(string fn, string ln, string id, string pw, int _age, int sn, string sname, string _town, string code, double _amount);
	~Donor();

	void displayData();

	string getID() { return userId; }
	string getLastName() { return lastName; }
	string getPassword() { return password; }
	double getAmount() { return amount; }
	void setPassword(string pw) { password = pw; }
	void setAge(int _age) { age = _age; }
	void setStreetNumber(int sn) { streetNumber = sn; }
	void setStreetName(string name) { streetName = name; }
	void setTown(string _town) { town = _town; }
	void setZipCode(string code) { zipCode = code; }
	void donate(double amt) { amount += amt; }

	friend ostream& operator << (ostream &out, const Donor &d);

private:
	string firstName;
	string lastName;
	string userId;
	string password;
	int age;
	int streetNumber;
	string streetName;
	string town;
	string zipCode;
	double amount;
};