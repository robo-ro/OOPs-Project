#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void addStudentData();
void existingStudentData();
void printStudentData();
void findStudentData(string);
//student* checkStudentData(string);
void showBranches();
void printEliglibleStudents(float, float, float, int);
void printAllCompanies();
// Date* setDeadLine();

string branches[11] = {"CSE",
                       "CCE",
                       "IT",
                       "ECE",
                       "EEE",
                       "E&I",
                       "AUTO",
                       "MECH",
                       "CIVIL",
                       "BIOMED"};

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

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 2021;

// Returns true if
// given year is valid.

bool isLeap(int year)
{
    // Return true if year
    // is a multiple pf 4 and
    // not multiple of 100.
    // OR year is multiple of 400.
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

// Returns true if given
// year is valid or not.

bool isValidDate(int d, int m, int y)
{

    // If year, month and day
    // are not in given range

    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    // Handle February month
    // with leap year

    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    // Months of April, June,
    // Sept and Nov must have
    // number of days less than
    // or equal to 30.

    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}

void showBranches()
{
    cout << "All the branches are listed below:-" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". " << branches[i] << endl;
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
    Date *deadline;

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

    Company(string company_id,
            string company_name,
            string location,
            string industry_sector,
            string job_profile,

            string offer_type,
            string category,
            Date *deadline,

            float cgpa_cutoff,
            float XIImarks,
            float Xmarks,

            int backlogs_allowed,

            vector<string> brans)
    {
        this->company_name = company_name;
        this->company_id = company_id;
        this->location = location;
        this->industry_sector = industry_sector;
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
    void set_deadline(Date *deadline);

    void set_cgpa_cutoff(float x);
    void setXIImarks(float x);
    void setXmarks(float x);

    void set_backlogs_allowed(int x);

    void insertAllBranches();

    friend void printCompany(string company_id);
    friend void removeCompany(string company_id);
    friend void addCompany(void);
    friend void get_eligible_comps(string reg_no);
    friend ostream &operator<<(ostream &out, const Company *c);
};

ostream &operator<<(ostream &out, const Company *c)
{

    out << "Id:" << c->company_id << " | Name:" << c->company_name << " | Job location:" << c->location << " | Industry sector:" << c->industry_sector << " | Job Profile:" << c->job_profile << " | Offer type:" << c->offer_type << " | Category:" << c->category << " | Deadline:"
        << c->deadline->day << "/" << c->deadline->month << "/" << c->deadline->year << " | CGPA required:" << c->cgpa_cutoff << " | XII Marks:" << c->XIImarks << " | X marks:" << c->Xmarks << " | Backlogs allowed:" << c->backlogs_allowed << endl;

    return out;
}

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

void Company ::set_deadline(Date *deadline)
{
    this->deadline = deadline;
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
                           "MECH",
                           "CIVIL",
                           "BIOMED"};

    int digit = -1;
    cout << "Please enter the serial number corresponding to the eligible branch, enter 0 to exit." << endl;
    showBranches();
    while (1)
    {
        cin >> digit;

        if (digit >= 1 && digit <= 10)
        {

            branches_eligible.insert(branches[digit - 1]);
        }
        else
        {
            break;
        }
    }
}

// unordered_map<string, Company *> companies;

vector<Company *> com;

Date *setDeadLine()
{

    //     int day,month,year;

    //    cout << "Enter day of the month(1-30)" << endl;
    //     cin >> day;

    //     cout << "Enter month(1-12)" << endl;
    //     cin >> month;

    //     cout << "Enter year (2021 onwards)" << endl;
    //     cin >> year;

    // cout << "Record updated.." << endl;

    int dd, mm, yy;

    int flag = 0;

    while (1)
    {
        cout << "Enter day of the month(1-30)" << endl;
        cin >> dd;

        cout << "Enter month(1-12)" << endl;
        cin >> mm;

        cout << "Enter year (2021 / 2022)" << endl;
        cin >> yy;

        try
        {
            if (isValidDate(dd, mm, yy) == false)
            {
                throw dd;
                flag = 1;
            }
            else
            {
                break;
            }
        }
        catch (int dd)
        {
            cout << "The date is invalid ! Please enter a valid deadline" << endl;
        }
    }

    Date *d1;
    d1 = new Date(dd, mm, yy);

    return d1;
}

void printCompany(string cid)
{
    for (int i = 0; i < com.size(); i++)
    {
        if (com[i]->company_id == cid)
        {
            cout << "Company id :" << com[i]->company_id << endl;
            cout << "Company name :" << com[i]->company_name << endl;
            cout << "Company location :" << com[i]->location << endl;
            cout << "Company industry sector :" << com[i]->industry_sector << endl;
            cout << "Job profile :" << com[i]->job_profile << endl;
            cout << "Offer type :" << com[i]->offer_type << endl;
            cout << "Category :" << com[i]->category << endl;
            // cout << "Deadline :" << to_string(com[i]->deadline->day) << " / " << to_string(com[i]->deadline->month) << " / " << to_string(com[i]->deadline->year) << endl;
            cout << "CGPA cuttoff :" << com[i]->cgpa_cutoff << endl;
            cout << "Minimum Xth marks required :" << com[i]->Xmarks << endl;
            cout << "Minimum XIIth marks required :" << com[i]->XIImarks << endl;
            cout << "Maximum backlogs accepted :" << com[i]->backlogs_allowed << endl;
            cout << "Eligible branches :" << endl;

            for (auto it = com[i]->branches_eligible.begin(); it != com[i]->branches_eligible.end(); ++it)
                cout << *it << endl;
        }
    }
}

void printAllCompanies()
{
    for (int i = 0; i < com.size(); i++)
    {
        cout << com[i] << endl;
    }
}

void addCompany()
{
    static int comp_id_gen = 10;

    Company *ctemp = new Company();

    string company_name;
    string company_id;
    string location;
    string industry_sector;
    string job_profile;

    string offer_type;
    string category;
    Date *deadline;

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
    deadline = setDeadLine();
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

    // companies[ctemp->company_id] = ctemp;
    com.push_back(ctemp);

    printCompany(ctemp->company_id);
}

void removeCompany(string cid)

{

    int flag = 0;

    for (int i = 0; i < com.size(); i++)
    {
        if (com[i]->company_id == cid)
        {
            com.erase(com.begin() + i);
            cout << "The company with company id : " << cid << " is deleted " << endl;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "No company with the entered Company id present. 0 companies removed! " << endl;
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

set<string> adminIds;

class college_admin : private user
{
private:
    string admin_id;

public:
    void set_admin_id(string admin_id)
    {
        this->admin_id = admin_id;
        adminIds.insert(admin_id);
    }
};

void add_admin(string id){
    adminIds.insert(id);

}

class student : private user
{
private:
    string reg_no;
    float cgpa;
    float XIImarks;
    float Xmarks;
    int backlogs;
    string branch;

    // setter and getter functions
public:
    student()
    {
        name = "";
    }
    student(string funName, string regNo, float xiimark, float xmark, string Branches, float cgpas, int bl = 0)
    {
        name = funName;
        reg_no = regNo;
        cgpa = cgpas;
        XIImarks = xiimark;
        Xmarks = xmark;
        branch = Branches;
        backlogs = bl;
    }

    bool check_reg_no(string rnos);

    //void set_Name(string s);

    friend ostream &operator<<(ostream &out, const student *s);
    friend void get_eligible_comps(string reg_no);

    bool check_eligiblity(float cg, float twm, float tenm, int BL);
    void setXmarks(int x);
    void setXmarks(float x);
    void updateXIImarks(float x);
    void setBl(int x);
    void setCgpa(float x);
    string getName();

};

string student::getName()
{
    return name;
}


void student::updateXIImarks(float x)
{
    XIImarks = x;
}
void student::setBl(int x)
{
    backlogs = x;
}
void student::setCgpa(float x)
{
    cgpa = x;
}

void student::setXmarks(int x){
   Xmarks = float(x);
}
void student::setXmarks(float x){
   Xmarks = x*9.2;
}

ostream &operator<<(ostream &out, const student *s)
{

    out << "Name:" << s->name << " | Registration Number:" << s->reg_no << " | Class X score:" << s->Xmarks << " | Class XII score:" << s->XIImarks << " | CGPA:" << s->cgpa << " | Branch:" << s->branch << " | Pending Backlogs:" << s->backlogs << endl;
    return out;
}

vector<student *> stds;
// map<string, student *> studs;

bool student::check_reg_no(string rnos)
{
    if (reg_no == rnos)
        return true;
    else
        return false;
}

bool student::check_eligiblity(float cg, float twm, float tenm, int BL)
{

    // int year = stoi(reg_no.substr(0,1));
    // cout<<year<<endl;

    if (cgpa >= cg && Xmarks >= tenm && XIImarks >= twm && backlogs <= BL)
        return true;
    else
        return false;
}

void addRandomData()
{

    student *s01 = new student("Arsh Tangri", "180907590", 95, 9.8, "ECE", 8.72, 6);
    stds.push_back(s01);
    student *s02 = new student("Sakshi Goenka", "180907473", 89, 9.2, "CSE", 7.78);
    stds.push_back(s02);
    student *s03 = new student("Rahul Kumar", "180907326", 77, 8.4, "MECH", 6.57, 2);
    stds.push_back(s03);
    student *s04 = new student("Loki Odin", "190852443", 88, 9.6, "CIVIL", 7.45);
    stds.push_back(s04);
    student *s05 = new student("Steve Rogers", "170544752", 74, 7.2, "IT", 5.65, 3);
    stds.push_back(s05);
    student *s06 = new student("Faisal Khan", "210454684", 64, 8.5, "AUTO", 8.21);
    stds.push_back(s06);
    student *s07 = new student("Tammana", "210450084", 80, 50, "AUTO", 3.7);
    stds.push_back(s07);

    Date *dd = new Date(12, 12, 2021);
    Company *c1 = new Company("CID_1", "Oyo", "Bangalore", "IT", "Software Dveeloper", "P+I", "Spot", dd, 6.0, 60, 8.0, 0, {"CSE", "CCE", "IT", "ECE"});
    Company *c2 = new Company("CID_2", "Amazon", "Gurgaon", "IT", "Software Dveeloper", "P", "Spot", dd, 7.0, 65, 7.0, 0, {"CSE", "CCE", "IT"});
    Company *c3 = new Company("CID_3", "HP", "Bangalore, Pune", "IT", "Software Dveeloper", "I", "Core", dd, 5.0, 70, 7.0, 0, {"CSE", "CCE", "IT", "ECE", "EEE", "E&I"});
    Company *c4 = new Company("CID_4", "Infosys", "Bangalore, Mumbai", "IT", "Software Analyst", "P+I", "ADM", dd, 6.5, 60, 4.0, 0, {"CSE", "CCE", "IT", "ECE", "EEE", "E&I", "AUTO", "MECH"});
    Company *c5 = new Company("CID_5","Apple","Hyderabad , Mumbai","IT", "Software Developer","I","Spot",dd,8,80,75,3,{"CSE","CCE","ECE","IT","EEE"});
    Company *c6 = new Company("CID_6","Axxela","Banglore, Pune", "Finance", "Sales Associate","P","Spot",dd,7,70,70,5,{"MECH","AUTO","E&I","EEE","BIOMED","CIVIL"});

    com.push_back(c1);
    com.push_back(c2);
    com.push_back(c3);
    com.push_back(c4);
    com.push_back(c5);
    com.push_back(c6);


    adminIds.insert("123");
    adminIds.insert("234");
    adminIds.insert("345");
    adminIds.insert("456");
    adminIds.insert("567");
    adminIds.insert("678");
}

int mainMenu()
{
    cout << "Welcome to the Placement assistance portal" << endl;
    cout << "1. Student Login" << endl;
    cout << "2. College Admin login" << endl;
    cout << "3. Exit Portal" << endl;
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
    cout << "3. Print all Student records" << endl;
    cout << "4. Print all companies records" << endl;
    cout << "5. Add new admin id" << endl;
    cout << "6. Go back a menu" << endl;
    int Oi;
    cin >> Oi;
    return Oi;
}

student* checkStudentData(string rno);
void reviseStudentDetails(student* s1);
void get_eligible_comps(string reg_no);

void addStudentData()
{
    string name, reg_no, branch;
    float XIImarks, Xmarks, cgpa;
    int bll, branchNo;

    cin.ignore();

    cout << "Enter your name: ";
    getline(cin,name);
    cout << "Enter your Registration Number: ";
    cin >> reg_no;
    cout << "Enter your Class X marks: ";
    cin >> Xmarks;
    cout << "Enter your class XII marks: ";
    cin >> XIImarks;
    cout << "Enter your CGPA: ";
    cin >> cgpa;
    showBranches();
    cout << "Choose the number corresponding to your branch: ";
    cin >> branchNo;
    branch = branches[branchNo - 1];
    cout << "Enter your pending backlogs: ";
    cin >> bll;

    student *s1 = new student(name, reg_no, XIImarks, Xmarks, branch, cgpa, bll);
    // cout<<s1<<endl;
    stds.push_back(s1);
    // studs[reg_no]= s1;
    cout << endl;
    cout << "Record successfully added" << endl<<endl;

    cout<< "1. Get list of eligible companies"<<endl;
    cout<< "2. Revise Student Details"<<endl;
    cout<<"3. Press any other key to continue"<<endl;
    char opTion;
    cin>>opTion;
    if(opTion=='1')
        {get_eligible_comps(reg_no);}
    else if(opTion =='2')
    {
        //revise student details
        reviseStudentDetails(s1);

    }

}
void get_eligible_comps(string reg_no)
{
    int pos = 0;
    bool flag = false;

    for (int i = 0; i < stds.size(); i++)
    {
        if (stds[i]->check_reg_no(reg_no) == true)
        {
            flag = true;
            pos = i;
            break;
        }
    }

    if (flag == false)
    {
        cout << "No records found !" << endl;
        return;
    }

    student *curr_student = stds.at(pos);

    int count = 0;

    for (int i = 0; i < com.size(); i++)
    {
        if (com[i]->cgpa_cutoff <= curr_student->cgpa && com[i]->XIImarks <= curr_student->XIImarks && com[i]->Xmarks <= curr_student->Xmarks && curr_student->backlogs <= com[i]->backlogs_allowed)
        {

            if (find(com[i]->branches_eligible.begin(), com[i]->branches_eligible.end(), curr_student->branch) != com[i]->branches_eligible.end())
            {
                count++;
                cout << "You are eligible for :" << endl;
                printCompany(com[i]->company_id);
                cout << endl;
            }
        }
    }

    if (count == 0)
    {
        cout << "Dear " << curr_student->name << " , you are not eligible for any currently registered companies!" << endl;
    }
}

void reviseStudentDetails(student* s1){
  while(1)
  {
      cout<<"1. Update X marks"<<endl;
      cout<<"2. Update XII marks"<<endl;
      cout<<"3. Update CGPA"<<endl;
      cout<<"4. Update Backlogs"<<endl;
      cout<<"5. Exit"<<endl;
      int input;
      cin>>input;

      if(input == 5)
        break;

      switch(input){
      case 1: cout<<"Enter revised X marks: ";
              float Xm;
              cin>>Xm;
              s1->setXmarks(Xm);
              break;
      case 2: cout<<"Enter revised XII marks: ";
              float XIIm;
              cin>>XIIm;
              s1->updateXIImarks(XIIm);
              break;
      case 3:cout<<"Enter updated CGPA: ";
              float cg;
              cin>>cg;
              s1->setCgpa(cg);
              break;
      case 4:cout<<"Enter updated backlogs: ";
              int bl;
              cin>>bl;
              s1->setBl(bl);
              break;
      default: cout<<"Invalid option"<<endl;
      }

  }

}


void existingStudentData()
{
    cout << "Please enter your registration number: ";
    string reg_no;
    cin >> reg_no;
    cout << "Looking for your records..." << endl;
    student* record_data = checkStudentData(reg_no);

    if (record_data->getName() == "")
        {return; }

    //cout<<"Printing list of all eligible companies: "<<endl;

    cout<< "1. Get list of eligible companies"<<endl;
    cout<< "2. Revise Student Details"<<endl;
    cout<<"3. Press any other key to continue"<<endl;
    char opTion;
    cin>>opTion;
    if(opTion=='1')
        {get_eligible_comps(reg_no);}
    else if(opTion =='2')
    {
        //revise student details
        reviseStudentDetails(record_data);

    }
}

void printStudentData()
{
    for (int i = 0; i < stds.size(); i++)
    {
        cout << stds.at(i) << endl;
    }

    // cout<<stds[0]->reg_no<<stds[0]->cgpa<<endl;
}

student* checkStudentData(string rno)
{
    //bool flag = false;
    for (int i = 0; i < stds.size(); i++)
    {
        student *ss = stds.at(i);
        if (ss->check_reg_no(rno))
        {
            cout << ss << endl;
            //flag = true;
            return ss;
        }
    }


    cout << "No records found!" << endl;
    student* s1 = new student();
    return s1;

}

int main(int argc, char **argv)
{
    addRandomData();

    // printCompany("CID_1");

    while (1)
    {
        int op = mainMenu();
        if (op == 1)
        {
            int Oi = studentFunction();
            if (Oi == 1)
            {
                // cout << "Call new user function" << endl;
                addStudentData();
                // printStudentData();
            } // Insert new user function here
            else if (Oi == 2)
            {
                // cout << "Call Existing user function" << endl;
                existingStudentData();
            } // Insert existing user function here
            else
                continue;
        }
        else if (op == 2)
        {
            string id;
            cout << "Please enter your id to get access: " << endl;
            cin >> id;
            if (adminIds.find(id) == adminIds.end())
            {
                cout << "Please enter a valid admin ID!" << endl;
                continue;
            }
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
                removeCompany(cid);
            }

            else if (Oi == 3)
            {
                printStudentData();
                cout << "Currently we have data of " << stds.size() << " students" << endl;
                continue;
            }
            else if (Oi == 4)
            {
                printAllCompanies();
                continue;
            }

            else if (Oi == 5)
            {
                string id;
                cout << "Please enter the new college admin id to be added :" << endl;
                cin >> id;
                add_admin(id);

                continue;
            }

            else
                continue;
        }

        else if (op == 3)
        {
            cout << "Thank you for using the portal" << endl;
            break;
        }
        else
        {
            cout << "Please enter a valid option" << endl
                 << endl;
            continue;
        }
    }

    return 0;
}
