#include<iostream>
#include<vector>
using namespace std;

void outputRoster(const vector<int>jerseyNumbers, const vector<int> ratings);
char getMenuoption();
int search(const vector<int>jerseyNumbers, const vector<int> ratings, int target);

int search(const vector<int>jerseyNumbers, const vector<int> ratings, int target)
{
   for (unsigned int i = 0; i < jerseyNumbers.size(); i++)
   {
      if (jerseyNumbers[i] == target)
         return i;
   }
   return -1;
}
char getMenuoption()
{
   cout << "MENU\n";
   cout << "a - Add player\nd - Remove player\nu - Update player rating\n" <<
      "r - Output players above a rating\no - Output roster\n" <<
      "q - Quit\n\nChoose an option:"<<endl;
   char choice;
   cin >> choice;
   return choice;
}

void outputRoster(const vector<int>jerseyNumbers, const vector<int> ratings)
{
   cout << "ROSTER\n";
   for (unsigned int i = 0; i < jerseyNumbers.size(); i++)
   {
      cout << "Player " << (i + 1) << " -- Jersey number: " << jerseyNumbers[i] << ", Rating: " << ratings[i] << endl;
   }
   cout << endl;
}

void addPlayer(vector<int>& v1, vector<int>& v2) //jerseyNumbers, ratings
{
   int jersey_number;
   cout << "Enter another player's jersey number:";
   cin >> jersey_number;
   cout << endl;
   int rating;
   cout << "Enter another player's rating:";
   cin >> rating;
   cout << endl << endl;
   v1.push_back(jersey_number);
   v2.push_back(rating);
}


void removePlayer(vector<int>& v1, vector<int>& v2) //jerseyNumbers, ratings
{
   int jersey_number;
   cout << "Enter a jersey number: ";
   cin >> jersey_number;
   int index = search(v1, v2, jersey_number);
   if (index == -1)
   {
      cout << "Jersey Number " << jersey_number << " not found.\n\n";
   }
   else {
         v1.erase(v1.begin()+index);
         v2.erase(v2.begin() + index);
         cout << "deleted...\n\n";
   }
}

void updatePlayerRating(vector<int>& v1, vector<int>& v2) //jerseyNumbers, ratings
{
   int jersey_number;
   cout << "Enter a jersey number: ";
   cin >> jersey_number;
   int index = search(v1, v2, jersey_number);
   if (index == -1)
   {
      cout << "Jersey Number " << jersey_number << " not found.\n\n";
   }
   else
   {
      int rating;
      cout << "Enter a new rating for player: ";
      cin >> rating;
      v2[index] = rating;
      cout << "Updated...\n\n";
   }
}

void outputPlayersAboveRating(const vector<int> v1, const vector<int> v2) //jerseyNumbers, ratings
{
   int rating;
   cout << "Enter a rating: ";
   cin >> rating;
   cout << "ABOVE " << rating << endl;
   for (unsigned int i = 0; i < v1.size(); i++)
   {
      if(v2[i] > rating)
       cout << "Player " << (i + 1) << " -- Jersey number: " << v1[i] << ", Rating: " << v2[i] << endl; 
      }
   cout << endl;
}

int main()
{
   vector<int>jerseyNumbers,ratings;

   
   int jersey_number, rating;
   for (int i = 0; i < 5; i++)
   {
      cout << "Enter player " << (i + 1) << "'s jersey number:"<< endl;
      cin >> jersey_number;
      cout << "Enter player " << (i + 1) << "'s rating:"<<endl;
      cin >> rating;
      cout<<endl;
      jerseyNumbers.push_back(jersey_number);
      ratings.push_back(rating);

   }

   
   outputRoster(jerseyNumbers, ratings);

   
   char choice = ' ';
   bool loop = true;
   while (loop)
   {
      choice = getMenuoption();
      switch (choice)
    {
      case 'a':
      case 'A':
         addPlayer(jerseyNumbers, ratings);
         break;
      case 'd':
      case 'D':
      removePlayer(jerseyNumbers, ratings);
      break;
      case 'u':
      case 'U':
      updatePlayerRating(jerseyNumbers, ratings);
       break;
       case 'r':
       case 'R':
      outputPlayersAboveRating(jerseyNumbers, ratings);
      break;
      case 'o':
      case 'O':
      outputRoster(jerseyNumbers, ratings);
      break;
      default:
      loop = false;
      break;
      }
   }
   return 0;
}
