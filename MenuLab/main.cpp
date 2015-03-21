//
//  main.cpp
//  MenuLab
//
//  Created by Nick Williams on 10/12/14.
//  Copyright (c) 2014 Ninjaneer. All rights reserved.
//
//  This program display a menu for a User to choose to view a List of Names or
//  Add Names to a list. If a file does not exist for viewing, and error is shown.
//  If a file does not exist for adding names, one is created.

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void showMenu(); //Displays Main Menu with Choices
void promptShowList(); //Prompts User for Filename entry to View List of Names
void promptAddToList(); //Prompts User for Filename entry. Then Prompts for Name to Add.
void promptInvalid(); //Tells User an Invalid Entry has been Submitted
void readFile(istream&); //Function to Read Names in File
void printToFile(ostream&, string); //Function to Add Names to a File.

ifstream in_stream;
ofstream out_stream;

string fileName;
string name;

int main(int argc, const char * argv[])
{
    int selection = 0;
    
    do
    {
        showMenu();
        
        cin >> selection;
        
        switch (selection)
        {
            case 1: //Show a List
                promptShowList();
                cin >> fileName;
                
                cout << "Opening: " << fileName << endl <<endl;
                
                in_stream.open(fileName);
                if (in_stream.fail())
                {
                    cout << "File Does Not Exist\n" << endl;
                    cout << "Returning to Main Menu\n" << endl;
                    break;
                }
                
                readFile(in_stream);
                in_stream.close();
                
                break;
            case 2: //Add a Name to a List
                promptAddToList();
                cin >> fileName;
                
                out_stream.open(fileName, ios::app);
                if (out_stream.fail())
                {
                    cout << "File Opening Failed\n";
                    break;
                }
                
                printToFile(out_stream, name);
                out_stream.close();
                
                break;
            case 3: //EXIT
                break;
            default:
                promptInvalid();
        }
        
    } while (selection != 3);
    
    cout << "Thank You. Program has Ended.\n" << endl;;
    
    return 0;
}

void showMenu()
{
    cout << "MAIN MENU\n";
    cout << "Please Make a Selection by Typing the Number that\n";
    cout << "Corresponds to your Desired Operation\n" << endl;
    cout << "1: Show a List\n";
    cout << "2: Add a Name to a List\n";
    cout << "3: EXIT" << endl << endl;
}

void promptShowList()
{
    cout << "You have Selected 'Show a List'\n" << endl;
    cout << "Please Enter the Name of the List File including Extension\n";
    cout << "Example: Names1.txt" << endl << endl;
    cout << "File Name: ";
}

void promptAddToList()
{
    cout << "You have Selected 'Add a Name to a List'\n" << endl;
    cout << "Please Enter the Name of the List File including Extension\n";
    cout << "Example: Names1.txt\n";
    cout << "If the File does not Exist, one will be Created/n" << endl;
    cout << "File Name: ";
}

void promptInvalid()
{
    cout << "You have provided an invalid input\n";
    cout << "Please Try Again\n" << endl;
}

void printToFile(ostream& out_stream, string name)
{
    cout << "Type the Name you would like to Add: ";
    
    cin.ignore();
    getline(cin, name);
    
    out_stream << name << endl;
}

void readFile(istream& in_stream)
{
    string inBuffer;
    
    do
    {
        getline(in_stream, inBuffer);
        cout << inBuffer << endl;
    } while (!in_stream.eof());
        
    cout << endl << endl;
}