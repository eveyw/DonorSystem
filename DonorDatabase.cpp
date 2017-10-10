#include "DonorDatabase.h"
#include <fstream>
#include <stdlib.h>
#include <iomanip>

int main(int argc, char *argv[])
{
	DonorDatabase *pdd = new DonorDatabase(atoi(argv[1]));

	if( argc >= 2)
		pdd->initialize(argv[2]);

	pdd->run();
}

DonorDatabase::DonorDatabase(int _maxNum)
{
	maxNum = _maxNum;
	isLogin = false;
}

DonorDatabase::~DonorDatabase()
{
}

void DonorDatabase::initialize(const char * fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		cout << "Can't open file-" << fileName << endl;
		return;
	}

	string firstName, lastName, userId, password;
	int age, streetNumber;
	string streetName, town, zipCode, temp;
	double amount;

	while (true)
	{
		fin >> firstName >> lastName >> userId >> password >> age >> streetNumber;
		getline(fin, temp);
		getline(fin, streetName);
		fin >> town >> zipCode >> amount;

		if (fin.good())
		{
			donors.push_back(Donor(firstName, lastName, userId, password, age, streetNumber, streetName, town, zipCode, amount));
		}
		else
		{
			return;
		}
	}
}


void DonorDatabase::run()
{
	string cmd;
	while (true)
	{
		showMenu();

		cout << ">";
		cin >> cmd;
		getchar();

		parseCmd(cmd);
	}
}


void DonorDatabase::showMenu()
{
	if (isLogin)
	{
		cout << " 1-Manage\n 2-Passwd\n 3-View\n 4-Donate\n 5-Total\n 6-Logout\n" << endl;
	}
	else
	{
		cout << " 1-Login\n 2-Add\n 3-Save\n 4-Load\n 5-Report\n 6-Quit\n" << endl;
	}
}

void DonorDatabase::parseCmd(string cmd)
{
	if (!isLogin)
	{
		if (cmd == "Login")
			userLogIn();
		else if (cmd == "Add")
			addDonor();
		else if (cmd == "Save")
			saveToFile();
		else if (cmd == "Load")
			loadFromFile();
		else if (cmd == "Report")
			report();
		else if (cmd == "Quit")
			exit(0);
		else
			cout << "Error!" << endl;
	}
	else
	{
		if (cmd == "Manage")
			manageDonor();
		else if (cmd == "Passwd")
			changePassword();
		else if (cmd == "View")
			viewCurDonor();
		else if (cmd == "Donate")
			donate();
		else if (cmd == "Total")
			total();
		else if (cmd == "Logout")
			isLogin = false;
		else
			cout << "Error!" << endl;
	}
}

void DonorDatabase::userLogIn()
{
	if (donors.empty())
	{
		cout << "No donors in database" << endl;
	}
	else
	{
		string id, password;
		cout << "Enter user id: ";
		getline(cin, id);

		cout << "Enter user password: ";
		getline(cin, password);

		for (Donor d : donors)
		{
			if (d.getID() == id && d.getPassword() == password)
			{
				cout << "Login success" << endl;
				isLogin = true;
				curDonor = d;
				return;
			}
		}

		cout << "Login failed" << endl;
	}
}


void DonorDatabase::addDonor()
{
	if (donors.size() == maxNum)
	{
		cout << " maximum allowable number of donors is reatched." << endl;
	}
	else
	{
		string firstName, lastName, userId, password;
		int age, streetNumber;
		string streetName, town, zipCode, temp;
		cout << "Enter <first name> <last name> <userid> <password> <age> <street number> \n";
		cin >> firstName >> lastName >> userId >> password >> age >> streetNumber;

		for (Donor d : donors)
		{
			if (d.getID() == userId)
			{
				cout << "User id-" << userId << " has already exist" << endl;
				return;
			}
		}

		getline(cin, temp);
		cout << "Enter street name: ";
		getline(cin, streetName);
		cout << "Enter <town> <zip code>: ";
		cin >> town >> zipCode;

		donors.push_back(Donor(firstName, lastName, userId, password, age, streetNumber, streetName, town, zipCode));
		cout << "Add user success." << endl;
	}
}


void DonorDatabase::saveToFile()
{
	ofstream fout;

	while (true)
	{
		string fileName;
		cout << "Enter file name: ";
		getline(cin, fileName);

		ifstream fin(fileName);
		

		if (fin.is_open())
		{
			cout << "File-" << fileName << " already exit, overwrite it?(y/n) ";
			char c = getchar();
			getchar();
			if (c == 'y' || c == 'Y')
			{
				fout.open(fileName.c_str(), ios::out);
				break;
			}
			else
			{
				fin.close();
				continue;
			}
		}
		else
		{
			fout.open(fileName.c_str(), ios::out);
			break;
		}	
	}

	for (Donor d : donors)
	{
		fout << d << endl;
	}

	cout << "Save to file success." << endl;
}

void DonorDatabase::loadFromFile()
{
	string fileName;
	cout << "Enter file name: ";
	getline(cin, fileName);

	ifstream fin(fileName);

	if (fin.is_open())
	{
		donors.clear();
		initialize(fileName.c_str());
		isLogin = false;
	}
	else
	{
		cout << "Can't open file-" << fileName << endl;
	}
}

void DonorDatabase::report()
{
	double total = 0;
	for (Donor d : donors)
	{
		total += d.getAmount();
	}

	cout << "There " << donors.size() << " donors, the sum of all individual contributions is " << total << endl;
}


void DonorDatabase::manageDonor()
{
	cout << " 1-password	\n 2-age\n 3-streetNumber\n 4-streetName\n 5-town\n 6-zipCode\n" << endl;
	cout << "Choose data field you want to change: ";
	int choice = 0;
	cin >> choice;
	getchar();

	int age, streetNumber;
	string password, streetName, town, zipCode, temp;

	switch (choice)
	{
	case 1:
	{
		changePassword();
		break;
	}
	case 2:
	{	
		cout << "Enter new age: ";
		cin >> age;
		curDonor.setAge(age);
		getchar();
		break;
	}
	case 3:
	{
		cout << "Enter new streetNumber: ";
		cin >> streetNumber;
		curDonor.setStreetNumber(streetNumber);
		getchar();
		break;
	}
	case 4:
	{
		cout << "Enter new streetName: ";
		getline(cin, streetName);
		curDonor.setStreetName(streetName);
		break;
	}
	case 5:
	{
		cout << "Enter new town: ";
		cin >> town;
		curDonor.setTown(town);
		break;
	}
	case 6:
	{
		cout << "Enter new zip code: ";
		cin >> zipCode;
		curDonor.setZipCode(zipCode);
		break;
	}
	default:
		break;
	}

	updateCurDonor();
}

void DonorDatabase::changePassword()
{
	string password;
	cout << "Enter old password: ";
	cin >> password;
	if (password != curDonor.getPassword())
	{
		cout << "Wrong old password!" << endl;
	}
	else
	{
		cout << "Enter new password: ";
		cin >> password;
		curDonor.setPassword(password);

		updateCurDonor();

		cout << "Change password success." << endl;
	}
}

void DonorDatabase::updateCurDonor()
{
	for (int i = 0; i < donors.size(); i++)
	{
		if (donors[i].getID() == curDonor.getID())
		{
			donors[i] = curDonor;
			break;
		}
	}
}

void DonorDatabase::viewCurDonor()
{
	curDonor.displayData();
}


void DonorDatabase::donate()
{
	double max = 5000 - curDonor.getAmount();
	int amount = 0;
	do {
		cout << "Input donate amount<0-" << max << ">: ";
		cin >> amount;
		getchar();
	} while (amount <= 0 || amount > max);

	curDonor.donate(amount);

	updateCurDonor();
}

void DonorDatabase::total()
{
	cout << curDonor.getLastName() << setiosflags(ios::fixed) << setprecision(2) << " $" << curDonor.getAmount() << endl;
}

