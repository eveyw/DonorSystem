all:	DonorDatabase

DonorDatabase:	DonorDatabase.o Donor.o
	g++ DonorDatabase.o Donor.o -o DonorDatabase -std=c++11

DonorDatabase.o:	DonorDatabase.cpp Donor.h
	g++ -c DonorDatabase.cpp -std=c++11
	
Donor.o:	Donor.cpp Donor.h
	g++ -c Donor.cpp -std=c++11

clean: 
	rm Donor.o DonorDatabase.o
