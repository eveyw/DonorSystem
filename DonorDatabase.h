#pragma once


#include "Donor.h"
#include <vector>
#include <string>

using namespace std;

class DonorDatabase {
public:
	DonorDatabase(int _maxNum);
	~DonorDatabase();

	void initialize(const char *fileName);
	void run();
	void showMenu();

private:
	
	int maxNum;
	bool isLogin;
	vector<Donor> donors;
	Donor curDonor;

	void parseCmd(string cmd);
	void userLogIn();
	void addDonor();
	void saveToFile();
	void loadFromFile();
	void report();

	void updateCurDonor();

	void manageDonor();
	void changePassword();
	void viewCurDonor();
	void donate();
	void total();

};