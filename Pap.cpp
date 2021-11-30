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

// vector<Company*> ccc;

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

    // ccc.push_back(ctemp);
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

