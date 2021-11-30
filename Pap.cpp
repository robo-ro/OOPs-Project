#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

struct Date
{
    int day, month, year, hour, minute;
    Date()
    {

        day = 1;
        month = 1;
        year = 2021;
        hour = 0;
        minute = 0;
    }
};

// enum OfferType
// {
// 	P,
// 	I,
// 	P + I
// };

// enum Category
// {
// 	Core,
// 	Spot,
// 	ADM
// }

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
        cout << to_string(i+1) << ". " << branches[i] << endl;
    }
}

class Company
{
private:
    string company_name;
    string company_id;
    string location;
    ;
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

void Company ::set_deadline(Date deadline){
    
    // 	int day, month, year, hour, minute;

	// deadline

	cout << "Enter day of the month(1-30)" << endl;
	cin >> deadline.day;

	cout << "Enter month(1-12)" << endl;
	cin >> deadline.month;

	cout << "Enter year (2021 / 2022)" << endl;
	cin >> deadline.year;

	cout << "Enter hours (0-23)" << endl;
	cin >> deadline.hour;

	cout << "Enter minute (0-60)" << endl;
	cin >> deadline.minute;

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

    string branches[10] = { "CSE",
                            "CCE",
                            "IT",
                            "ECE",
                            "EEE",
                            "E&I",
                            "AUTO",
                            "MECH" };

    int digit = -1;

    while (digit != 0)
    {
        cout << "Please enter the serial number corresponding to the eligible branch, enter 0 to exit." << endl;
        showBranches();
        cin >> digit;
        branches_eligible.insert(branches[digit - 1]);
    }
}

map<string, Company> companies;

void addCompany()
{
    static int comp_id_gen = 1;

    Company ctemp ;

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

    ctemp.set_company_id(comp_id_gen);
    comp_id_gen++;

    cout << "Please note the company id :" << ctemp.company_id;

    cout << "Please enter the following details about the new company :" << endl;

    cout << "Enter company name :" << endl;
    cin >> company_name;
    ctemp.set_company_name(company_name);

    cout << "Enter location(s) of the comapny:" << endl;
    cin >> location;
    ctemp.set_location(location);

    cout << "Enter industry sector :" << endl;
    cin >> industry_sector;
    ctemp.set_industry_sector(industry_sector);

    cout << "Enter job profile :" << endl;
    cin >> job_profile;
    ctemp.set_job_profile(job_profile);

    cout << "Enter offer type (P, I, P+I) :" << endl;
    cin >> offer_type;
    ctemp.set_offer_type(offer_type);

    cout << "Enter the category (Core, Spot, ADM) :" << endl;
    cin >> category;
    ctemp.set_category(category);

    cout << "Enter the last date for registration :" << endl;
    ctemp.set_deadline(deadline);

    cout << "Enter the minimum CGPA required (<= 10.00) :" << endl;
	cin >> cgpa_cutoff;
	ctemp.set_cgpa_cutoff(cgpa_cutoff);

	cout << "Enter the minimum 12th percentage required  :" << endl;
	cin >> XIImarks;
	ctemp.setXIImarks(XIImarks);

	cout << "Enter the minimum 10th percentage required  :" << endl;
	cin >> Xmarks;
	ctemp.setXmarks(Xmarks);

	cout << "Enter the maximum number of backlogs acceptable :" << endl;
	cin >> backlogs_allowed;
	ctemp.set_backlogs_allowed(backlogs_allowed);

	cout << "Enter the eligible branches :" << endl;
	ctemp.insertAllBranches();


	companies[ctemp.company_id] = ctemp;
}

class user
{

private:
    string name;
    string loginId;

public:
    void set_Name(string s);
    void set_LoginID(string s);
};

class College_Admin : public user{

};

int main()
{

    addCompany();

    return 0;
}

// class student : public user
// {
// public:
// 	string reg_no;
// 	float cgpa;
// 	float XIImarks;
// 	float Xmarks;
// 	string branch;
// };

// class college_Instructor
// {

// private:
// 	string userID;
// 	string instr_Password;

// public:
// 	void login();

// 	void add_Company();

// 	void remove_Company();

// 	void update_Company();
// };

// void college_Instructor ::login()
// {
// Start:

// 	while (attempts < 3)
// 	{
// 		cout << "\nEnter your Instructor ID : ";
// 		cin >> userID;
// 		cout << "Enter the Instructor Password : ";
// 		cin >> instr_Password;

// 		if (userID == "Admin" && instr_Password == "a1b2c3d4e5")
// 		{
// 			cout << "\nWelcome Instructor!\n";

// 			cout << "\nAccessible Operations: \n\n1. Add Company\n"
// 				 << "2. Remove Company \n3. Update Company\n"
// 				 << "4. Exit \n\nEnter option: ";
// 			cin >> ch;

// 			while (ch != 4)
// 			{
// 				if (ch == 1)
// 				{
// 					add_Company();
// 				}
// 				else if (ch == 2)
// 				{
// 					remove_Company();
// 				}
// 				else if (ch == 3)
// 				{
// 					update_Company();
// 				}
// 			}
// 			break;
// 		}
// 		else
// 		{
// 			cout << "\nInvalid login attempt. Please try again.\n";
// 			attempts++;
// 			goto Start;
// 		}
// 	}

// 	if (attempts == 3)
// 	{
// 		cout << "\nToo many login attempts! The program will now terminate.\n";
// 	}
// }

// void college_Instructor ::add_Company()
// {
// 	string Job_description, Work_location, Due_date, Field;
// 	int Max_backlogs;
// 	float CGPA, Min_12th, Min_10th;
// 	char Offer_type;

// 	string empty = "00";

// 	ifstream f("Companies.txt");
// 	string line;

// 	for (int i = 0; std::getline(f, line); ++i)
// 	{
// 		count_n++;
// 	}

// 	cout << "Enter the number of Companies:";
// 	cin >> n;

// 	count_n = count_n + n;

// 	for (i = 0; i < n; i++)
// 	{
// 		ofstream outfile;
// 		outfile.open("Companies.txt", ios::app);
// 		// The entire data of a single company is stored line-by-line.

// 		cout << "Enter the Name of the Company: ";
// 		cin >> Name;
// 		outfile << Name << "\t";

// 		cout << "Enter the Job description: ";
// 		cin >> Job_description;

// 		// while (len < 5)
// 		//{
// 		// data[len] = ' ';
// 		// len = len + 1;
// 		//}
// 		outfile << Job_description << "\t";

// 		cout << "Enter the Work Location: ";
// 		cin >> Work_location;

// 		outfile << Work_location << "\t";

// 		cout << "Enter the Last Date to Apply: ";
// 		cin >> Due_date;

// 		outfile << Due_date << "\t";

// 		cout << "Enter the CGPA Requirements: ";
// 		cin >> CGPA;

// 		outfile << CGPA << "\t";

// 		cout << "Enter the 12th Marks Requirements: ";
// 		cin >> Min_12th;

// 		outfile << Min_12th << "\t";

// 		cout << "Enter the 10th Marks Requirements: ";
// 		cin >> Min_10th;

// 		outfile << Min_10th << "\t";

// 		cout << "Enter the total number of acceptable Backlogs: ";
// 		cin >> Max_backlogs;

// 		outfile << Max_backlogs << "\t";

// 		cout << "Enter the Offer type: ";
// 		cin >> Offer_type;

// 		outfile << Offer_type << "\t";

// 		cout << "Enter the Field of the Job: ";
// 		cin >> Field;

// 		outfile << Field << endl;
// 	}

// 	login();
// }

// void college_Instructor ::remove_Company()
// {
// 	cout << "Enter the details:";
// }

// void college_Instructor ::update_Company()
// {

// 	cout << "Enter the details:";
// }

// cout << "\n-----------------------------------Welcome to the Student Placement Assitance Portal!-----------------------------------\n";
// Start : cout << "\nPlease choose your designated Account: \n\n1. Student\n"
// 			 << "2. Company \n3. College Instructor \n4. Exit \n\nEnter your Choice: ";
// cin >> ch;

// while (attempts < 3 && ch != 4)
// {
// 	if (ch == 1)
// 	{
// 		// Student S;
// 	}
// 	else if (ch == 2)
// 	{
// 		// Company C;
// 	}
// 	else if (ch == 3)
// 	{
// 		college_Instructor I;
// 		I.login();
// 	}
// 	else
// 	{
// 		cout << "\nInvalid Choice. Please choose again.\n";
// 		attempts++;
// 		goto Start;
// 	}
// }
// if (attempts == 3)
// {
// 	cout << "\nPlease reload the page and try again! Thank you.\n";
// }
