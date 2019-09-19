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
        void SHOW_ITEM(User* u)
        {
                cout << "Username " << u->get_name() << " email_id " << u->get_email() << " country " << u->get_country() << " score " << u->get_score() << endl;
        }
        void SHOW_ALL()
        {
             cout << "*********************** USER_TABLE ******************************" << endl;
             cout << " EMAIL_id " << "     NAME    " << "   COUNTRY   " << "   SCORE   " << endl;
             unordered_map <string, User*>::iterator itr;

             for (itr = table.begin(); itr != table.end(); itr++)
              {
                 cout << "    " << itr->second->get_email() << "     " << itr->second->get_name() << "   " << itr->second->get_country() << "  " << itr->second->get_score() << endl;
              }
        }
        void TOP_K(int k, string country)
        {
            priority_queue <User *, vector<User *>, compare_score> pq;
            int count = 0;
            unordered_map <string, User*>::iterator itr;
            for (itr = table.begin(); itr != table.end() && count < k; itr++)
               {
                 if (country.empty())
                   {
                      pq.push(itr->second);
                      count++;
                   }
                 else
                   {
                     if (itr->second->get_country() == country)
                       {
                          pq.push(itr->second);
                          count++;
                       }
                   }
               }
            while (itr != table.end())
              {
                 if (itr->second->get_score() > pq.top()->get_score() && (country.empty() || (itr->second->get_country() == country)))
                   {
                        pq.pop();
                        pq.push(itr->second);
                   }
                itr++;
              }

           cout << "Details of query -  " << endl;

           for (int i = 0; i < count && !pq.empty(); i++)
              {
                 User* u = pq.top();
                 SHOW_ITEM(u);
                 pq.pop();
              }
        }
};

void User_table::UPSERT_USER(string name, string country, string email_id)
{       
        User *u = NULL;
        unordered_map <string, User*>:: iterator itr;
        itr = table.find(email_id);
        if (itr != table.end())
        { 
        u = itr->second;
        }
        else
        {       
                u = new User;
                user_no++;
                u->set_seq(user_no);
        }
        u->set_email(email_id);
        u->set_name(name);
        u->set_country(country);
        table[email_id] = u;
        //U->setemail_id = email_id; 
        cout << "name " << "added to the leather board." << endl;
        SHOW_ALL();
}

void User_table::UPSERT_SCORE(string email_id, int score)
{       
        User *u = NULL;
        unordered_map <string, User*>:: iterator itr;
        itr = table.find(email_id);
        if (itr != table.end())
        {   
            u = itr->second;
        }
        else
        {       
                cout << " no user id exists with given mail id" << endl;
                return;
        }
    u->set_score(score);
    cout << "Score of User with name " << u->get_name() << " has been updated" << endl;
    score_table.push_back(make_pair(score, email_id));
    SHOW_ALL();
}


