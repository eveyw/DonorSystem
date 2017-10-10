# DonorSystem
This is a C++ program that allows its user to input, change, and show a small amount of “donor
information,” for use by a fictional funding campaign. The program support different “accounts” for
multiple donor, and hold the following things for each donor, using the indicated C++ types. 

• Last Name (C++ string, contains only letters)

• First Name (C++ string, contains only letters)

• Userid (C++ string, contains at least 5 characters but no more than 10, containing only letters and digits)

• Password (C++ string, contains at least 6 characters, including at least one digit and one character that is
neither a letter nor a digit)

• Age (int, must be at least 18)

• Street Number (int, must be positive)

• Street Name (C++ string, may include multiple words separated by spaces or tabs)

• Town (C++ string, may also include multiple words separated by spaces or tabs)

• State (C++ enum of 2-character state codes for NY, PA, and the New England states only (RI, NH, VT,
MA, CT, ME)

• Zip Code (C++ string, contains exactly 5 digits)

• Amount Donated (float, non-negative, total amount donated must not grow beyond $5,000)

The program initially prompt the user to make a selection by typing one of the following commands,
with the following effects:

• Type “Login” to have the user present a userid and password, and to proceed to a 2nd-level menu (see
below). The userid and password that the user presents should be checked for inclusion in the current set
of donor accounts.

• Type “Add” to add an additional donor with all new donor information (userid, name, address,
password, etc.) and to zero out the donor’s amount donated. Please ensure that the new userid is not
already in use and that the programmer does not try to create more than the maximum allowable number
of donors (see below under “Command Line Arguments”).

• Type “Save” to store all current donor database information, including donor account information and
amounts donated, into a file. After the user enters “Save”, your program should prompt him or her for
the name of the file to save the information to, and should open that file and write into it. If the file
exists, your program should warn the user that it exists and offer to overwrite its contents or allow theuser to select a different file.

• Type “Load” to restore donor information, including donor information and amounts donated, from a
file. Again, the user should be prompted for the name of the file, and any existing donor information “in
memory” should simply be overwritten by the contents of the file. The format of the input file for Load
should match the format of the output file for Save, so that your program can read and write its own
data. You get to decide that format; do not design the file to be used by any program other than your
own. In other words, the data does not have to “look pretty” within the file (although it might), it just
needs to be accessible to your own code.

• Type “Report” to generate a report about how many donors are in the database, and how much money
has been donated to the campaign (report one number, namely the sum of all individual contributions).

• Type “Quit” to end the program. Before quitting, the program should ask the user whether he or she
would like to save donor information into a file, and should then do so (if requested).
All other words that a user may type as input at this menu level (including misspellings, incorrect capitalization,
and anything else that does not exactly match the choices above), should generate an error, but should then
continue to accept commands. Please make sure your program operates correctly on well-formed “expected”
input, but please also have it react appropriately to as many different kinds of malformed input as you can.
Once a user has successfully logged in as a donor, he or she should be able to enter the following commands,
with the indicated results.

• Type “Manage” to change some or all of the donor information (other than the userid and password)
associated with the record for the donor who is logged in. Please allow the user to select which fields to
update, keeping all other information the same.

• Type “Passwd” to change the password of the donor who is logged in. Prompt the user for the old
password, and require her to type the new one correctly twice. (Don't worry about not echoing input
characters for the password.) If the user does not successfully enter the exact same password twice, your
program should disallow the password change.

• Type “View” to see all donor information associated with the currently logged in donor, in wellformatted, professional, “easy to read” output.

• Type “Donate” to donate money to the campaign (associating it with the donor who is currently logged
in). Your program should prompt the user for an amount to donate, should not allow users to enter a
negative amount for deposit, and should not allow donors to donate more than a total of $5,000.

• Type “Total” to display the last name of the currently logged-in donor, followed by the amount he or she
has donated (formatted with a dollar sign and exactly two decimal places of accuracy) on the same line
of output, as follows (for example):
o Lewis $45.33

• Type “Logout” to log back out to the previous top-level menu.
Your program should continue to accept commands for the current donor, until the user enters “Logout”. As
with the top-level menu, your program should support well-formed “expected” input, but should also recognize
and react appropriately to as many malformed inputs as possible.

Command Line Arguments
This program read arguments from the command line to support the following interface:

./Donate <max donors> <filename>

The <max donors> parameter specifies the largest number of donors that your program will accept. The
<filename> parameter indicates the name of a file from which to read initial donor database information.
The user may omit the <filename> parameter, but must specify a <max donors> value that falls between1 and 1000. 

So, for example, the user may run your program as follows, to support an initially empty donor
database that can hold information for up to 25 donors:

$ ./Donate 25

Or the user may run your program to support a donor database that can hold up to 100 donors, with initial donor
information found in the file named mydonors.txt, as follows:

$ ./Donate 100 mydonors.txt

To support command line arguments in C++, parse the argc and argv parameters passed to main(). This
will give you practice working with C/C++ arrays. The type of argv is “pointer to pointer to char” or
equivalently “pointer to an array of character pointers.” Base your solution for parsing command line arguments
on the simple example in Blackboard.

Design

Create two C++ classes, one for Donor objects, and one for a single DonorDatabase object. Each C++
class have an associated .h file and a.cpp file to hold the class definition and member function
implementations, respectively. File names match the class names, we have
DonorDatabase.cpp, DonorDatabase.h, Donor.cpp, and Donor.h. Set up makefile to
build DonorDatabase.o from the code for the DonorDatabase class, and Donor.o from the code for the
Donor class, then link those object code files against a third file that includes compiled main() program and link everything into a single executable called “Donate”.

