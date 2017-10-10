#include "Donor.h"

Donor::Donor()
{
}

Donor::Donor(string fn, string ln, string id, string pw, int _age, int sn, string sname, string _town, string code)
	:firstName(fn), lastName(ln), userId(id), password(pw), age(_age), streetNumber(sn),
	streetName(sname), town(_town), zipCode(code), amount(0)
{
}

Donor::Donor(string fn, string ln, string id, string pw, int _age, int sn, string sname, string _town, string code, double _amount)
	: firstName(fn), lastName(ln), userId(id), password(pw), age(_age), streetNumber(sn),
	streetName(sname), town(_town), zipCode(code), amount(_amount)
{

}


Donor::~Donor()
{
}

void Donor::displayData()
{
	cout << "ID: " << userId << endl;
	cout << "Name: " << lastName << " " << firstName << endl;
	cout << "Age: " << age << endl;
	cout << "Street number: " << streetNumber << endl;
	cout << "Street name: " << streetName << endl;
	cout << "Town: " << town << endl;
	cout << "Zip code: " << zipCode << endl;
	cout << "Amount: " << amount << endl << endl;
}

ostream& operator << (ostream &out, const Donor &d)
{
	out << d.firstName << endl;
	out << d.lastName << endl;
	out << d.userId << endl;
	out << d.password << endl;
	out << d.age << endl;
	out << d.streetNumber << endl;
	out << d.streetName << endl;
	out << d.town << endl;
	out << d.zipCode << endl;
	out << d.amount << endl;

	return out;
}

