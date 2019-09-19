#include<iostream>
#include<queue>
#include<string>
#include <unordered_map>
#include "user.h"

using namespace std;

class User_table
{
        int user_no;
        unordered_map <string, User*> table;
        vector <pair <int, string> > score_table;
public:
        User_table()
        {
             user_no = 0;
        }
        struct compare_score{
             bool operator ()(User* const& p1, User* const& p2)
             {
                return (p1->get_score() > p2->get_score());
             }
        };

        void UPSERT_USER(string name, string country, string email_id);
        void UPSERT_SCORE(string email_id, int score);
        void SHOW_ITEM(User* u);
        void SHOW_ALL();
        void TOP_K(int k, string country);
};

