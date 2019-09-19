#include <iostream>
#include <string>

using namespace std;

class User
{
        string name;
        string email_id;
        string country;
        int seq_id;
        int score;
public:
        string get_email()
        {
            return email_id;
        }
        void set_email(string email)
        {
            email_id = email;
        }
        string get_name()
        {
            return name;
        }
        string get_country()
        {
            return country;
        }
        int get_score()
        {
            return score;
        }
        void set_name(string name)
        {
            this->name = name;
        }
        void set_country(string country)
        {
            this->country = country;
        }
        void set_score(int score)
        {
            if (score > 0)
             {
                this->score = score;
             }
            else
                cout << "invalid score value";
         }
        int get_seq()
        {
            return seq_id;
        }
        void set_seq(int seq)
        {
            seq_id = seq;
        }

      };
