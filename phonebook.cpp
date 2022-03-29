#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;
void menu();
void Addnumber();
void DisplayRecord();
void SearchBySrno();
void deleteRecord();
void modifynumber();
class PhoneBook
{
  int srno;
  char name[25];
  char mobile[15];
  char email[30];
  char group[20];

public:
  int getSrNo()
  {
    return srno;
  }
  void storeData()
  {
    cout << "----------------CREATE NEW PHONE RECORD-----------------------\n";
    cout << "Enter SErial Number : ";
    cin >> srno;
    cin.ignore();

    cout << "Enter Record Name : ";
    cin.getline(name, 25);
    cout << "Enter Mobile Number : ";
    cin.getline(mobile, 25);
    cout << "Enter E-Mail I.D. : ";
    cin.getline(email, 30);
    cout << "Enter Group Number : ";
    cin.getline(group, 20);
    cout << endl;
  }

  void showData()
  {
    cout << "\n----------------------PHONE BOOK RECORD-------------------------\n";
    cout << "Sr. No.    : " << srno << endl;
    cout << "Name       : " << name << endl;
    cout << "Mobile No. : " << mobile << endl;
    cout << "E-Mail ID  : " << email << endl;
    cout << "Group      : " << group << endl;
  }
} b;

void AddNumber()
{
  ofstream fout;
  fout.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
  b.storeData();
  fout.write((char *)&b, sizeof(b));
  fout.close();
  cout << "Record Saved to file.....\n";
}

void DisplayRecord()
{
  ifstream fin;
  fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
  while (fin.read((char *)&b, sizeof(b)))
  {
    b.showData();
  }
  fin.close();
  cout << "\nReading of data file Completed...........\n";
}

void SearchBySrno()
{
  ifstream fin;
  int n, flag = 0;
  fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
  cout << "Enter Serail Number of Record To Display : ";
  cin >> n;

  while (fin.read((char *)&b, sizeof(b)))
  {
    if (n == b.getSrNo())
    {
      b.showData();
      flag++;
      cout << "\n\n......Record Found and Displayed.........\n";
    }
  }
  fin.close();
  if (flag == 0)
    cout << "\nThe record of Serial Number " << n << " is not in file....\n";
  cout << "\nReading of data File Completed...........\n";
}

void deleteRecord()
{
  ifstream fin;
  ofstream fout;
  int n, flag = 0;
  fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
  fout.open("temp.dat", ios::out | ios::binary);
  cout << "Enter Serial Number of Record To delete : ";
  cin >> n;

  while (fin.read((char *)&b, sizeof(b)))
  {
    if (n == b.getSrNo())
    {
      cout << "\nThe following record is deleted.....\n";
      b.showData();
      flag++;
    }
    else
    {
      fout.write((char *)&b, sizeof(b));
    }
  }
  fin.close();
  fout.close();
  if (flag == 0)
    cout << "\nthe Record of Serial Number " << n << " is not in file.....\n";
  remove("PhoneBook.dat");
  renmae("Temp.dat", "PhoneBook.dat");
}

void modifyRecord()
{
  fstream fin;
  int n, flag = 0, pos;
  fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app)
          cout
      << "Enter Serail Number of Record To Modify : ";
  cin >> n;
  while (fin.read((char *)&b, sizeof(b)))
  {
    pos = fin.tellg();
    if (n == b.getSrNo())
    {
      cout << "\nThe following record will be modified.....\n";
      b.showData();
      flag++;
      cout << "\nRe-Enter the New Details.....\n";
      b.storeData();
      fin.seekg(pos - sizeof(b));
      ;
      fin.write((char *)&b, sizeof(b));
      cout << "\n....Data Modified Successfully....\n";
    }
  }
  fin.close();
  if (flag == 0)
    cout << "\nThe Record of serial Number " << n << " is not in file.....\n";
  cout << "Reading of Data File Completed........\n ";
}

void menu()
{
  int ch;
  do
  {
    clrscr();
    cout << "......................................................................................\n";
    cout << "                             PHONE BOOK MANAGEMENT\n ";
    cout << "......................................................................................\n";
    cout << ":::::::::::::::::::::::::::::::::  PROGRAM MENU  :::::::::::::::::::::::::::::::::::::::\n";
    cout << "0. Exit\n";
    cout << "1. Save New Phone Record\n";
    cout << "2. Display All Saved Record\n";
    cout << "3. Search Specific Record\n";
    cout << "4. Delete Existing Record\n";
    cout << "5. Modify Existing Record\n";
    cout << "Enter your Choice : ";
    cin >> ch;
    clrscr() switch (ch)
    {
    case 1:
      AddNumber();
      break;
    case 2:
      DisplayRecord();
      break;
    case 3:
      SearchBySrno();
      break;
    case 4:
      deleteRecord();
      break;
    case 5:
      modifynumber();
      break;
    }
    getch();
  } while (ch);
}

void main()
{
  menu();
}