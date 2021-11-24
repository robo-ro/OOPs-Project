#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>



using namespace std;


class date{

}



void showBranches()
{
	cout << "All the branches are listed below" << endl;
	string branches[10] = { "CSE",
							"CCE",
							"IT",
							"ECE",
							"EEE",
							"E&I",
							"AUTO",
							"MECH" }

	for (int i = 0; i < 10; i++)
	{
		cout << i + '1' << ". " << branches[i] << endl;
	}
}



	class Company
	{
	private:
		string company_name;
		string id;
		string location;
		string deadline;
		string industry_sector;
		string job_profile;
		string category;

		float cgpa_cutoff;
		float XIImarks;
		float Xmarks;

		char offer_type;
		int backlogs_allowed;

		
		set<string> branches;
		int batch_eligilble // 2022 or 2023 batch or both
			public :
			// SETTER AND GETTER FUNCTIONS HERE
			void
			set_name(string s);
		void set_jd(string s);
		void setLocation(string s);
		void setCgpa(float x);
		void setXIImarks(float x);
		void setXmarks(float x);
		void setOfferType(char x);
		void setCategory(string s);
		void insertAllBranches(string s);
		void setBatches(int x);
	};

	void companies ::set_name(string s)
	{
		name = s;
		cout << "Record updated.." << endl;
	}
	void companies ::set_jd(string s)
	{
		jd = s;
		cout << "Record updated.." << endl;
	}
	void companies ::setLocation(string s)
	{
		location = s;
	}
	void companies ::setXmarks(float s)
	{
		if (s <= 100 && s >= 0)
			Xmarks = s;

		void companies ::setXIImarks(float s)
		{
			if (s >= 0 && s <= 100)
				XIImarks = s;
			else
			{
				cout << "Value must be between 0 and 100" << endl
					 << "Try again!" << endl;
				float ss;
				cin >> ss;

				.
			}
		}
		void companies ::setOfferType(char x)
		{
		}
		void companies ::setCategory(string s)
		{
		}
		void companies ::insertAllBranches(string s)
		{
		}
		void companies ::setBatches(int x)
		{
		}

		class user
		{
		public:
			string name;
			string loginId;
			string password;

			void set_Name(string s);
			void set_LoginID(string s);
			void set_pass(string s);
		};

		class student : public user
		{
		public:
			string reg_no;
			float cgpa;
			float XIImarks;
			float Xmarks;
			string branch;
		};

		class college_Instructor
		{

		private:
			string userID;
			string instr_Password;

		public:
			void login();

			void add_Company();

			void remove_Company();

			void update_Company();
		};

		void college_Instructor ::login()
		{
		Start:

			while (attempts < 3)
			{
				cout << "\nEnter your Instructor ID : ";
				cin >> userID;
				cout << "Enter the Instructor Password : ";
				cin >> instr_Password;

				if (userID == "Admin" && instr_Password == "a1b2c3d4e5")
				{
					cout << "\nWelcome Instructor!\n";

					cout << "\nAccessible Operations: \n\n1. Add Company\n"
						 << "2. Remove Company \n3. Update Company\n"
						 << "4. Exit \n\nEnter option: ";
					cin >> ch;

					while (ch != 4)
					{
						if (ch == 1)
						{
							add_Company();
						}
						else if (ch == 2)
						{
							remove_Company();
						}
						else if (ch == 3)
						{
							update_Company();
						}
					}
					break;
				}
				else
				{
					cout << "\nInvalid login attempt. Please try again.\n";
					attempts++;
					goto Start;
				}
			}

			if (attempts == 3)
			{
				cout << "\nToo many login attempts! The program will now terminate.\n";
			}
		}

		void college_Instructor ::add_Company()
		{
			string Job_description, Work_location, Due_date, Field;
			int Max_backlogs;
			float CGPA, Min_12th, Min_10th;
			char Offer_type;

			string empty = "00";

			ifstream f("Companies.txt");
			string line;

			for (int i = 0; std::getline(f, line); ++i)
			{
				count_n++;
			}

			cout << "Enter the number of Companies:";
			cin >> n;

			count_n = count_n + n;

			for (i = 0; i < n; i++)
			{
				ofstream outfile;
				outfile.open("Companies.txt", ios::app);
				// The entire data of a single company is stored line-by-line.

				cout << "Enter the Name of the Company: ";
				cin >> Name;
				outfile << Name << "\t";

				cout << "Enter the Job description: ";
				cin >> Job_description;

				// while (len < 5)
				//{
				// data[len] = ' ';
				// len = len + 1;
				//}
				outfile << Job_description << "\t";

				cout << "Enter the Work Location: ";
				cin >> Work_location;

				outfile << Work_location << "\t";

				cout << "Enter the Last Date to Apply: ";
				cin >> Due_date;

				outfile << Due_date << "\t";

				cout << "Enter the CGPA Requirements: ";
				cin >> CGPA;

				outfile << CGPA << "\t";

				cout << "Enter the 12th Marks Requirements: ";
				cin >> Min_12th;

				outfile << Min_12th << "\t";

				cout << "Enter the 10th Marks Requirements: ";
				cin >> Min_10th;

				outfile << Min_10th << "\t";

				cout << "Enter the total number of acceptable Backlogs: ";
				cin >> Max_backlogs;

				outfile << Max_backlogs << "\t";

				cout << "Enter the Offer type: ";
				cin >> Offer_type;

				outfile << Offer_type << "\t";

				cout << "Enter the Field of the Job: ";
				cin >> Field;

				outfile << Field << endl;
			}

			login();
		}

		void college_Instructor ::remove_Company()
		{
			cout << "Enter the details:";
		}

		void college_Instructor ::update_Company()
		{

			cout << "Enter the details:";
		}

		cout << "\n-----------------------------------Welcome to the Student Placement Assitance Portal!-----------------------------------\n";
	Start:
		cout << "\nPlease choose your designated Account: \n\n1. Student\n"
			 << "2. Company \n3. College Instructor \n4. Exit \n\nEnter your Choice: ";
		cin >> ch;

		while (attempts < 3 && ch != 4)
		{
			if (ch == 1)
			{
				// Student S;
			}
			else if (ch == 2)
			{
				// Company C;
			}
			else if (ch == 3)
			{
				college_Instructor I;
				I.login();
			}
			else
			{
				cout << "\nInvalid Choice. Please choose again.\n";
				attempts++;
				goto Start;
			}
		}
		if (attempts == 3)
		{
			cout << "\nPlease reload the page and try again! Thank you.\n";
		}
	
