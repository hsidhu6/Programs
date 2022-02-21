#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;
/*definations of all data types and functions*/
class Date{
  private:
    unsigned day;
    unsigned month;
    string monthName;
    unsigned year;

  public:
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const string &mn, unsigned d, unsigned y);
    void printNumeric() const;
    void printAlpha() const;

  private:
    bool isLeap(unsigned y) const;
    unsigned daysPerMonth(unsigned m, unsigned y) const;
    string name(unsigned m) const;
    unsigned number(const string &mn) const;
};
/*declarations of Date class */

Date::Date()
{
   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;
}

Date::Date (unsigned m, unsigned d, unsigned y)
{
   bool invalid = false;
  
   //if invalid month input, change to closest month
   if (m < 1)
   {
       m = 1;
       invalid = true;
   }
   else if (m > 12)
   {
       m = 12;
       invalid = true;
   }
  
   //invalid day
   if (d > daysPerMonth(m, y))
   {
       d = daysPerMonth(m,y);
       invalid = true;
   }
  
   day = d;
   month = m;
   monthName = name(m);
   year = y;
  
   if (invalid)
   {
       cout << "Invalid date values: Date corrected to ";
       cout << month << "/" << day << "/" << year << "." << endl;
   }
}

Date::Date (const string &mName, unsigned d, unsigned y)
{
   //will change to true if invalid day
   bool invalidDay = false;
   //will change to true if invalid month
   bool invalidMonth = false;
  
   if (mName == "January" || mName == "january")
   {  
       month = number("January");
       monthName = "January";
   }
   else if (mName == "February" || mName == "february")
   {
       month = number("February");
       monthName = "February";
   }
   else if (mName == "March" || mName == "march")
   {
       month = number("March");
       monthName = "March";
   }
   else if (mName == "April" || mName == "april")
   {
       month = number("April");
       monthName = "April";
   }
   else if (mName == "May" || mName == "may")
   {
       month = number("May");
       monthName = "May";
   }
   else if (mName == "June" || mName == "june")
   {
       month = number("June");
       monthName = "June";
   }
   else if (mName == "July" || mName == "july")
   {
       month = number("July");
       monthName = "July";
   }
   else if (mName == "August" || mName == "august")
   {
       month = number("August");
       monthName = "August";
   }
   else if (mName == "September" || mName == "september")
   {
       month = number("September");
       monthName = "September";
   }
   else if (mName == "October" || mName == "october")
   {
       month = number("October");
       monthName = "October";
   }
   else if (mName == "November" || mName == "november")
   {
       month = number("November");
       monthName = "November";
   }
   else if (mName == "December" || mName == "december")
   {
       month = number("December");
       monthName = "December";
   }
   //If invalid month name, change date to 1/1/2000
   else
   {
       day = 1;
       month = number("January");
       monthName = "January";
       year = 2000;
      
       invalidMonth = true;
   }

   //if monthName is correct but day number is invalid, change to closest day
   if ((!invalidMonth) && (d > daysPerMonth(month, y)))
   {
       day = daysPerMonth(month,y);
       invalidDay = true;
   }
  
   //outputs message if input was invalid
   if (invalidDay || invalidMonth)
   {
       cout << "Invalid date values: Date corrected to ";
       if (invalidDay)
       {
           year = y;
       }
       cout << month << "/" << day << "/" << year << "." << endl;
   }

   else
   {
       day = d;
       year = y;
   }
}

void Date::printNumeric () const
{
   cout << month << "/" << day << "/" << year;
}

void Date::printAlpha () const
{
   cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const
{
   //implies leap year
   if (y % 4 == 0)
   {
       //does not imply leap year
       if (y % 100 == 0)
       {
           //unless its a multiple of 400
           if (y % 400 == 0)
           {
               return true;
           }
           return false;
       }
       return true;
   }
   return false;
}


unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
   if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
   {
       return 31;
   }
   else if (m == 4 || m == 6 || m == 9 || m == 11)
   {
       return 30;
   }
   else if (isLeap(y))
   {
       return 29;
   }
   return 28;
}

/* Returns the name of a given month
- e.g. name(12) returns the string "December"
*/
string Date::name(unsigned m) const
{
   if (m <= 1)
   {
       return "January";
   }
   else if (m >= 12)
   {
       return "December";
   }
  
   if (m == 2)
   {
       return "February";
   }
   else if (m == 3)
   {
       return "March";
   }
   else if (m == 4)
   {
       return "April";
   }
   else if (m == 5)
   {
       return "May";
   }
   else if (m == 6)
   {
       return "June";
   }
   else if (m == 7)
   {
       return "July";
   }
   else if (m == 8)
   {
       return "August";
   }
   else if (m == 9)
   {
       return "September";
   }
   else if (m == 10)
   {
       return "October";
   }
   else if (m == 11)
   {
       return "November";
   }
}
      
/* Returns the number of a given named month
*/
unsigned Date::number(const string &mName) const
{
   if (mName == "January")
   {
       return 1;
   }
   else if (mName == "February")
   {
       return 2;
   }
   else if (mName == "March")
   {
       return 3;
   }
   else if (mName == "April")
   {
       return 4;
   }
   else if (mName == "May")
   {
       return 5;
   }
   else if (mName == "June")
   {
       return 6;
   }
   else if (mName == "July")
   {
       return 7;
   }
   else if (mName == "August")
   {
       return 8;
   }
   else if (mName == "September")
   {
       return 9;
   }
   else if (mName == "October")
   {
       return 10;
   }
   else if (mName == "November")
   {
       return 11;
   }
   else if (mName == "December")
   {
       return 12;
   }
}





// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
