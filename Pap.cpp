#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void addStudentData();
void existingStudentData();
void printStudentData();

struct Date
{
    int day, month, year;
    Date()
    {

        day = 1;
        month = 1;
        year = 2021;
    }

    Date(int dd, int mm, int yy)
    {
        day = dd;
        month = mm;
        year = yy;
    }
};

void showBranches()
{
    cout << "All the branches are listed below" << endl;
    string branches[10] = {"CSE",
                           "CCE",
                           "IT",
                           "ECE",
                           "EEE",
                           "E&I",
                           "AUTO",
                           "MECH"};

    for (int i = 0; i < 10; i++)
    {
        cout << to_string(i + 1) << ". " << branches[i] << endl;
    }
}

class Company
{
private:
    string company_name;
    string company_id;
    string location;

    string industry_sector;
    string job_profile;

    string offer_type;
    string category;
    Date deadline;

    float cgpa_cutoff;
    float XIImarks;
    float Xmarks;

    int backlogs_allowed;

    unordered_set<string> branches_eligible;

public:
    Company()
    {
        company_name = "";
        company_id = "";
        location = "";

        industry_sector = "";
        job_profile = "";

        float cgpa_cutoff = 0.00;
        float XIImarks = 0.00;
        float Xmarks = 0.00;

        int backlogs_allowed = 0;
    }

    Company(string company_name,
            string company_id,
            string location,
            string industry_sector,
            string job_profile,

            string offer_type,
            string category,
            Date deadline,

            float cgpa_cutoff,
            float XIImarks,
            float Xmarks,

            int backlogs_allowed,

            vector<string> brans)
    {
        this->company_name = company_name;
        this->company_id = company_id;
        this->location = location;
        this->industry_sector;
        this->job_profile = job_profile;

        this->offer_type = offer_type;
        this->category = category;
        this->deadline = deadline;

        this->cgpa_cutoff = cgpa_cutoff;
        this->XIImarks = XIImarks;
        this->Xmarks = Xmarks;

        this->backlogs_allowed = backlogs_allowed;

        for (auto it : brans)
        {
            branches_eligible.insert(it);
        }
    }

    // SETTER AND GETTER FUNCTIONS HERE

    void set_company_name(string s);
    void set_company_id(int comp_id_gen);
    void set_location(string s);
    void set_industry_sector(string s);
    void set_job_profile(string s);

    void set_offer_type(string t);
    void set_category(string c);
    void set_deadline(Date deadline);

    void set_cgpa_cutoff(float x);
    void setXIImarks(float x);
    void setXmarks(float x);

    void set_backlogs_allowed(int x);

    void insertAllBranches();

    friend void printCompany(string company_id);
    friend void addCompany(void);
};

void Company ::set_company_name(string s)
{
    company_name = s;
    cout << "Record updated.." << endl;
}

void Company ::set_company_id(int comp_id_gen)
{
    company_id = "CID_" + to_string(comp_id_gen);

    cout << "Record updated.." << endl;
}

void Company ::set_location(string s)
{
    location = s;
    cout << "Record updated.." << endl;
}

void Company ::set_industry_sector(string s)
{
    industry_sector = s;
    cout << "Record updated.." << endl;
}

void Company ::set_job_profile(string s)
{
    job_profile = s;
    cout << "Record updated.." << endl;
}

void Company ::set_offer_type(string t)
{
    offer_type = t;
    cout << "Record updated.." << endl;
}

void Company ::set_category(string c)
{
    category = c;
    cout << "Record updated.." << endl;
}

void Company ::set_deadline(Date deadline)
{

    cout << "Enter day of the month(1-30)" << endl;
    cin >> deadline.day;

    cout << "Enter month(1-12)" << endl;
    cin >> deadline.month;

    cout << "Enter year (2021 / 2022)" << endl;
    cin >> deadline.year;

    cout << "Record updated.." << endl;
}

void Company ::set_cgpa_cutoff(float x)
{
    cgpa_cutoff = x;
    cout << "Record updated.." << endl;
}

void Company ::setXIImarks(float s)
{
    if (s >= 0 && s <= 100)
    {
        XIImarks = s;
        cout << "Record updated.." << endl;
    }
    else
    {
        cout << "Marks invalid! Please try again!" << endl;
    }
}

void Company ::setXmarks(float s)
{
    if (s <= 100 && s >= 0)
    {
        Xmarks = s;
        cout << "Record updated.." << endl;
    }
    else
    {
        cout << "Marks invalid! Please try again!" << endl;
    }
}

void Company ::set_backlogs_allowed(int x)
{
    backlogs_allowed = x;
}

void Company ::insertAllBranches()
{

    string branches[10] = {"CSE",
                           "CCE",
                           "IT",
                           "ECE",
                           "EEE",
                           "E&I",
                           "AUTO",
                           "MECH"};

    int digit = -1;
    cout << "Please enter the serial number corresponding to the eligible branch, enter 0 to exit." << endl;
    showBranches();
    while (1)
    {
        cin >> digit;

        if (digit >= 1 && digit <= 8)
        {

            branches_eligible.insert(branches[digit - 1]);
        }
        else
        {
            break;
        }
    }
}

unordered_map<string, Company *> companies;

vector<Company *> com;

void printCompany(string cid)
{
    for (int i = 0; i < com.size(); i++)
    {
        if (com[i]->company_id == cid)
        {

            cout << "Company name :" << com[i]->company_name << endl;
            cout << "Company location :" << com[i]->location << endl;
            cout << "Company industry sector :" << com[i]->industry_sector << endl;
            cout << "Job profile :" << com[i]->job_profile << endl;
            cout << "Offer type :" << com[i]->offer_type << endl;
            cout << "Category :" << com[i]->category << endl;
            cout << "Deadline :" << com[i]->deadline.day << " / " << com[i]->deadline.month << " / " << com[i]->deadline.year << endl;
            cout << "CGPA cuttoff :" << com[i]->cgpa_cutoff << endl;
            cout << "Minimum Xth marks required :" << com[i]->Xmarks << endl;
            cout << "Minimum XIIth marks required :" << com[i]->XIImarks << endl;
            cout << "Maximum backlogs accepted :" << com[i]->backlogs_allowed << endl;
            cout << "Eligible branches :" << endl;

            for (auto it = com[i]->branches_eligible.begin(); it !=
                                                              com[i]->branches_eligible.end();
                 ++it)
                cout << *it << endl;
        }
    }
}

void addCompany()
{
    static int comp_id_gen = 1;

    Company *ctemp = new Company();

    string company_name;
    string company_id;
    string location;
    string industry_sector;
    string job_profile;

    string offer_type;
    string category;
    Date deadline;

    float cgpa_cutoff;
    float XIImarks;
    float Xmarks;

    int backlogs_allowed;

    // set<string> branches;

    ctemp->set_company_id(comp_id_gen);
    comp_id_gen++;

    cout << "Please note the company id :" << ctemp->company_id << endl;

    cout << "Please enter the following details about the new company :" << endl;

    cout << "Enter company name :" << endl;
    cin >> company_name;
    ctemp->set_company_name(company_name);

    cout << "Enter location(s) of the comapny:" << endl;
    cin >> location;
    ctemp->set_location(location);

    cout << "Enter industry sector :" << endl;
    cin >> industry_sector;
    ctemp->set_industry_sector(industry_sector);

    cout << "Enter job profile :" << endl;
    cin >> job_profile;
    ctemp->set_job_profile(job_profile);

    cout << "Enter offer type (P, I, P+I) :" << endl;
    cin >> offer_type;
    ctemp->set_offer_type(offer_type);

    cout << "Enter the category (Core, Spot, ADM) :" << endl;
    cin >> category;
    ctemp->set_category(category);

    cout << "Enter the last date for registration :" << endl;
    ctemp->set_deadline(deadline);

    cout << "Enter the minimum CGPA required (<= 10.00) :" << endl;
    cin >> cgpa_cutoff;
    ctemp->set_cgpa_cutoff(cgpa_cutoff);

    cout << "Enter the minimum 12th percentage required  :" << endl;
    cin >> XIImarks;
    ctemp->setXIImarks(XIImarks);

    cout << "Enter the minimum 10th percentage required  :" << endl;
    cin >> Xmarks;
    ctemp->setXmarks(Xmarks);

    cout << "Enter the maximum number of backlogs acceptable :" << endl;
    cin >> backlogs_allowed;
    ctemp->set_backlogs_allowed(backlogs_allowed);

    cout << "Enter the eligible branches :" << endl;
    ctemp->insertAllBranches();

    companies[ctemp->company_id] = ctemp;
    com.push_back(ctemp);

    printCompany(ctemp->company_id);
}

void removeCompany(string cid)
{
    if (companies.find(cid) != companies.end())
    {
        companies.erase(cid);
    }
    else{
        cout<< "No company with the entered Company id present. 0 companies removed! " << endl;
    }
}

class user
{
public:
    string name;
    // string loginId;
    // string password;

    void set_Name(string s);
    // void set_LoginID(string s);
    // void set_pass(string s);
};

class College_Admin : public user
{
};

class student : private user
{
private:
    string reg_no;
    float cgpa;
    float XIImarks;
    float Xmarks;
    string branch;

    // setter and getter functions
public:
    student(string funName, string regNo, float xiimark, float xmark, string Branches, float cgpas)
    {
        name = funName;
        reg_no = regNo;
        cgpa = cgpas;
        XIImarks = xiimark;
        Xmarks = xmark;
        branch = Branches;
    }

    friend ostream &operator<<(ostream &out, const student *s);
};

ostream &operator<<(ostream &out, const student *s)
{

    out << "Welcome " << s->name << " Reg No. " << s->reg_no << " with score in class X:" << s->Xmarks << " ,class XII marks:" << s->XIImarks << " ,CGPA of: " << s->cgpa << " and branch is " << s->branch << endl;
    return out;
}

vector<student *> stds;
map<string, student *> studs;

int mainMenu()
{
    cout << "Welcome to the Placement assistance portal" << endl;
    cout << "1. Student Login" << endl;
    cout << "2. College admin login" << endl;
    cout << "3. Exit portal" << endl;
    int option;
    cin >> option;
    return option;
}

int studentFunction()
{
    cout << "1. New user registration" << endl;
    cout << "2. Existing user" << endl;
    cout << "3. Go back a menu" << endl;
    int Oi;
    cin >> Oi;
    return Oi;
}

int collegeAdminFunction()
{
    cout << "1. Add Company" << endl;
    cout << "2. Remove Company" << endl;
    cout << "3.Go back a menu" << endl;
    int Oi;
    cin >> Oi;
    return Oi;
}

void addStudentData()
{
    cout << "Enter your name: ";
    string name, reg_no, branch;
    float XIImarks, Xmarks, cgpa;
    // getline(cin,name);
    cin >> name;
    cout << "Enter your Registration Number: ";
    // string reg_no;
    cin >> reg_no;
    cout << "Enter your Class X marks: ";
    cin >> Xmarks;
    cout << "Enter your class XII marks: ";
    cin >> XIImarks;
    cout << "Enter your CGPA: ";
    cin >> cgpa;
    // string branch;
    cout << "Enter your branch: ";
    cin >> branch;

    // cout<<"Welcome "<<name<<" Reg No. "<<reg_no<<" with score in class X:"<<Xmarks<<" ,class XII marks:"<<XIImarks<<" ,CGPA of: "<<cgpa<<" and branch is "<<branch<<endl;

    student *s1 = new student(name, reg_no, XIImarks, Xmarks, branch, cgpa);
    // cout<<s1<<endl;
    stds.push_back(s1);
    studs[reg_no] = s1;
}

void existingStudentData()
{
    cout << "Please enter your registration number: ";
    string reg_no;
    cin >> reg_no;
    cout << "Looking for your records..." << endl;
}

void printStudentData()
{
    for (int i = 0; i < stds.size(); i++)
    {
        cout << stds.at(i) << endl;
    }

    // cout<<stds[0]->reg_no<<stds[0]->cgpa<<endl;
}

int main(int argc, char **argv)
{

    while (1)
    {
        int op = mainMenu();
        if (op == 1)
        {
            int Oi = studentFunction();
            if (Oi == 1)
            {
                cout << "Call new user function" << endl;
                addStudentData();
                printStudentData();
            } // Insert new user function here
            else if (Oi == 2)
            {
                cout << "Call Existing user function" << endl;
                existingStudentData();
            } // Insert existing user function here
            else
                continue;
        }
        else if (op == 2)
        {
            int Oi = collegeAdminFunction();
            if (Oi == 1)
            {

                //  cout << "Call add company function" << endl; // Insert add comp function here
                addCompany();
            }

            else if (Oi == 2)
            {

                // cout << "Call Remove company function" << endl; // Insert remove company function here
                string cid;
                cout << "Please enter the company id :" << endl;
                cin >> cid;
                // removeCompany(cid);
                cout << "The company with company id : " << cid << " is deleted " << endl;
            }
            else
                continue;
        }
        else
        {
            cout << "Thank you for using the Portal" << endl;
            break;
        }
    }

    printStudentData();

    return 0;
}