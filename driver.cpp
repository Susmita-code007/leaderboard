#include<iostream>
#include<string>
#include "user_table.h"

using namespace std;

int main()
{
        User_table U;
        string input;

        string cont = "NO";
        do{
            cout << "Enter operation" << endl;
            cin >>  input;
           if (input == "UPSERT_USER")
            {
                string name;
                string email;
                string country;
                cin >> name >> email >> country;
                U.UPSERT_USER(name, country, email);
            }
           else if (input == "UPSERT_SCORE")
           {
                string email;
                int score;
                cin >> email >> score;
                U.UPSERT_SCORE(email, score);
           }
           else if (input == "TOP_K")
           {
              int k;
              string country = "";
              cout << "input k " << endl;
              cin >> k;
              if (!cin.fail()){
              cout << "is there a country " << endl;
              string ans;
              cin >> ans;
              if (ans == "YES")
              cin >> country;
              U.TOP_K(k, country);
              }
              else{
                 cout << "Invalid k value " << endl;
                 cin.clear();
                 std::cin.ignore(256,'\n');
                 }
           }
           else
             cout << "INVALID OPERATION" << endl;
           cout << "want to continue?" << endl;
           cin >> cont;
        } while(cont == "YES" || cont == "yes" || cont == "y");
        return 0;
}

