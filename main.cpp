#include<iostream>
#include<vector>
using namespace std;

//--------- Contact Management System -----------

class Contact  
{
    private:
        char fName[50];
        char lName[50];
        char address[50];
        char email[50];
        long long phoneNum;
    public:
        // function to read data from the user
        void createContact()
        {
            cout << "Enter Your First Name: ";
            cin >> fName;
            cout << "Enter Your Last Name: ";
            cin >> lName;
            cout << "Enter Your Address: ";
            cin >> address;
            cout << "Enter your phone number: ";
            cin >> phoneNum;
        }
        // function to show data to the user
        void showContact()
        {
            cout << "Your Name is: " << fName << " " << lName << endl;
            cout << "Your Address is: " << address << endl;
            cout << "Your Email is: " << email << endl;
            cout << "Your Phone Number is: " << phoneNum << endl;
        }
        // function to save data in the file (write in the File)
        void writeOnFile()
        {
            char ch;
            ofstream myFile; // use to write in the file
            myFile.open("CMS.txt", ios::binary | ios::app);
            do
            {
                createContact();
                myFile.write(reinterpret_cast<char*>(this), sizeof(*this));
                cout << "Do you have next data? [yes/no]: ";
                cin >> ch;
            }while(ch == 'y' || ch == 'Y');
            cout << "Contact Has Been Created Successfully";
            myFile.close();
            
        }

        // function to Take the data from the File(Read from the File)
        void readFromFile()
        {
            ifstream File2;
            File2.open("CMS.txt", ios::binary | ios::app);
            cout <<"\n-----------------------------";
            cout << "------ List of Contact\n -----";
            cout <<"\n-----------------------------";

            while(File2.eof())
            {
                if(File2.read(reinterpret_cast<char*>(this), sizeof(*this)))
                {
                    showContact();
                    cout << "-------------------------\n";
                }
            }
            File2.close();
        }
        // function to search on record from file
        void searchOnFile()
        {
            ifstream File3;
            long long phone;
            cout << "enter Your phone number: \n";
            cin >> phone;
            File3.open("CMS.txt", ios::binary | ios::app);
            while (File3.eof())
            {
                if (File3.read(reinterpret_cast<char*>(this), sizeof(*this)))
                {
                    if (phone == phoneNum)
                    {
                        showContact();
                        return;
                    }
                }
            }
            cout << "No Record Found\n";
            File3.close();
        }
        // function to delete contact form from the file
        void deleteFromFile()
        {
            long long phone;
            int flag = 0;
            ofstream file4;
            ifstream file5;
            
            file5.open("CMS.txt", ios::binary);
            // file4.open("temp.txt", ios::binary);

            cout << "Enter phone number to delete: ";
            cin >> phone;

            while (!file5.eof())
            {
                if (file5.read(reinterpret_cast<char*>(this), sizeof(*this)))
                {
                    if (phoneNum != phone)
                    {
                        file4.write(reinterpret_cast<char*>(this), sizeof(*this));

                    }else{
                        flag = 1;
                    }
                }
                file5.close();
                file4.close();
                remove("CMS.txt");
                // remove("temp.txt", "CMS.txt");

                flag == 1 ;
                cout << "\t Contact Deleted....";
                cout << "\t Contact Not Found....";
            }
        }
        // function to edit about contact system
        void editContact()
        {
            long long phone;
            fstream file6;
            cout << "Edit Contact";
            cout << "\n-------------------------\n";
            cout << "Enter Phone Number to Edit: ";
            cin >> phone;

            file6.open("CMS.txt", ios::binary | ios::out | ios::in);
            while (file6.eof())
            {
                if(file6.read(reinterpret_cast<char*>(this), sizeof(*this)))
                {
                    if (phone == phoneNum)
                    {
                        cout << "Enter New Record Number\n";
                        createContact();

                        long long pos = -1 * sizeof(*this);
                        file6.seekp(pos, ios::cur);
                        file6.write(reinterpret_cast<char*>(this), sizeof(*this));
                        cout << endl << "Contact Successfully Updated...\n";
                        return;
                    }
                }
            }
            cout << "No Record Found\n";
            file6.close();
        }
};
// int main function that implement the code
int main()
{
    system("cls");
    system("color 3f"); 
    
    cout << "\n--------- WELCOME TO THE CONTACT MANAGEMENT SYSTEM ---------\n";

    while (1)
    {
        Contact c1;
        int choice;

        system("cls");
        system("color 03");

        cout << "Contact Management System";
        cout << "Main Menu";
        cout << "\n-------------------------------\n";
        cout << "1- Add a new Contact\n";
        cout << "2- List All new Contact\n";
        cout << "3- Search For Contact\n";
        cout << "4- Delete a Contact\n";
        cout << "5- Edit a Contact\n";
        cout << "0- Exit\n";
        cout << "\n-------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1 :
                system("cls");
                c1.createContact();
                break;
            case 2:
                system("cls");
                c1.readFromFile();
                break;
            case 3:
                system("cls");
                c1.searchOnFile();
                break;
            case 4:
                system("cls");
                c1.deleteFromFile();
                break;
            case 5:
                system("cls");
                c1.editContact();
                break;
            case 0:
                system("cls");
                cout << "Thank YOu For Uisng CMS\n";
                exit(0);
                break;
            default:
                continue;
        }
        int option;
        cout << "Enter the choice:\n[1]: Main Menu\t\t [0]: Exit";
        cin >> option;
        switch(option) {
            case 0:
                system("cls");
                cout << "Thank YOu For Uisng CMS\n";
                exit(0);
                break;
            default:
                continue;
        }
    }

    return 0;
}