#include <iostream>
#include <array>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::getline;
using std::array;
using std::stoi;

class Contact
{
    public:
        Contact();
        Contact(string name, string phoneNumber);
        Contact(string name, string email, string phoneNumber);
        string name();
        string email();
        string phoneNumber();

    private:
        string _name;
        string _email;
        string _phoneNumber;
};

Contact::Contact() {}

Contact::Contact(string name, string phoneNumber)
{
    this->_name = name;
    this->_phoneNumber = phoneNumber;
}

Contact::Contact(string name, string email, string phoneNumber)
{
    this->_name = name;
    this->_email = email;
    this->_phoneNumber = phoneNumber;
}

string Contact::name()
{
    return this->_name;
}

string Contact::email()
{
    return this->_email;
}

string Contact::phoneNumber()
{
    return this->_phoneNumber;
}

template <typename T>
class ArrayList
{   
    public:
        ArrayList(int size = 100);
        int length() const;
        int maxLength() const;
        T at(int location);
        void insert(const T& element);
        void removeAt(int location);
        void replaceAt(int location, const T& element);
    
    private:
        int _length;
        int _maxLength;
        T* _list;
};

template <typename T>
ArrayList<T>::ArrayList(int size)
{
    if(size < 0)
    {
        cerr << "size must be positive. Creating an array of size 100." << endl;
        this->_maxLength = 100;
    }
    else
    {
        this->_maxLength = size;
    }

    this->_length = 0;
    this->_list = new T[this->_maxLength];
}

template <typename T>
int ArrayList<T>::length() const
{
    return this->_length;
}

template <typename T>
void ArrayList<T>::insert(const T& element)
{
    if(this->length() >= this->_maxLength)
    {
        cerr << "Cannot insert in a full list." << endl;
    }
    else
    {
        this->_list[this->length()] = element;
        this->_length++;
    }
}

template <typename T>
T ArrayList<T>::at(int location)
{
    return this->_list[location];
}

template <typename T>
void ArrayList<T>::replaceAt(int location, const T& element)
{
    this->_list[location] = element;   
}

template <typename T>
void ArrayList<T>::removeAt(int location)
{
    if(location < 0 || location >= this->length())
    {
        cerr << "The location of the item to be removed is invalid. Out of range." << endl;
    }
    else
    {
        for(int i = location; i < this->length(); i++)
        {
            this->_list[i] = this->_list[i + 1];
        }
        this->_length--;
    }
}

class ContactBook
{
    public:
        ContactBook();
        void showAllContacts();
        void showContacts(ArrayList<Contact>* contacts);
        void showContactsWithNumber(ArrayList<Contact>* contacts);
        ArrayList<Contact>* findContacts(string keyword);
        void addContact(Contact contact);
        void editContact(int location);
        void printMenu();
        void run();
    
    private:
        ArrayList<Contact>* _contactList;
};

ContactBook::ContactBook()
{
    this->_contactList = new ArrayList<Contact>();
}

void ContactBook::showAllContacts()
{
    for(int i = 0; i < this->_contactList->length(); i++)
    {
        cout << "Name: " << this->_contactList->at(i).name() << endl;
        cout << "PhoneNumber: " << this->_contactList->at(i).phoneNumber() << endl;
        cout << "Email: " << this->_contactList->at(i).email() << endl;
        cout << endl;
    }
}

void ContactBook::showContacts(ArrayList<Contact>* contacts)
{
    for(int i = 0; i < contacts->length(); i++)
    {
        cout << "Name: " << contacts->at(i).name() << endl;
        cout << "PhoneNumber: " << contacts->at(i).phoneNumber() << endl;
        cout << "Email: " << contacts->at(i).email() << endl;
    }
}

void ContactBook::showContactsWithNumber(ArrayList<Contact>* contacts)
{
    for(int i = 0; i < contacts->length(); i++)
    {
        cout << i <<".  Name: " << contacts->at(i).name() << endl;
        cout << "   PhoneNumber: " << contacts->at(i).phoneNumber() << endl;
        cout << "   Email: " << contacts->at(i).email() << endl;
    }
}

void ContactBook::addContact(Contact contact)
{   
    this->_contactList->insert(contact);
    cout << "Contact successfully added." << endl;
}

void ContactBook::editContact(int location)
{
    string name, phoneNumber, email;
    cout << "Enter new Name: ";
    getline(cin, name);
    cout << "Enter new PhoneNumber: ";
    getline(cin, phoneNumber);
    cout << "Enter new Email: ";
    getline(cin, email);
    this->_contactList->replaceAt(location, *(new Contact(name, email, phoneNumber)));
    cout << "Contact successfully updated." << endl;
}

ArrayList<Contact>* ContactBook::findContacts(string keyword)
{
    ArrayList<Contact>* result = new ArrayList<Contact>();
    for(int i = 0; i < this->_contactList->length(); i++)
    {
        if(this->_contactList->at(i).name().find(keyword) != string::npos || this->_contactList->at(i).phoneNumber().find(keyword) != string::npos)
        {
            result->insert(this->_contactList->at(i));
        }
    }
    return result;
}

void ContactBook::run()
{
    bool running = true;
    int userInput;
    string keyword;
    string name;
    string phoneNumber;
    string email;
    string userInputStr;
    Contact* contact;
    ArrayList<Contact>* searchedContacts;
    while(running)
    {
        cout << "--CONTACT BOOK--" << endl;
        cout << "1. Show all contacts" << endl;
        cout << "2. Add a new contact" << endl;
        cout << "3. Edit a new contact" << endl;
        cout << "4. Delete a contact" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "What is your choice? ";
        getline(cin, userInputStr);
        userInput = stoi(userInputStr);
        switch(userInput)
        {
            case 1:
                if(this->_contactList->length() == 0)
                {
                    cout << "No contacts" << endl;
                    break;
                }
                this->showAllContacts();
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phoneNumber: ";
                getline(cin, phoneNumber);
                cout << "Enter email: ";
                getline(cin, email);
                contact = new Contact(name, phoneNumber, email);
                this->addContact(*contact);
                break;
            case 3:
                this->showContactsWithNumber(this->_contactList);
                cout << "What is your choice? ";
                getline(cin, userInputStr);
                userInput = stoi(userInputStr);
                this->editContact(userInput);
                cout << "Contact successfully updated";
                break;
            case 4:
                this->showContactsWithNumber(this->_contactList);
                cout << "What is your choice? ";
                getline(cin, userInputStr);
                userInput = stoi(userInputStr);
                this->_contactList->removeAt(userInput);
                cout << "Contact successfully removed";
                break;
            case 5:
                running = false;
                break;
            default:
                break;
        }
    }
}

int main()
{
    ContactBook *contactBook = new ContactBook();
    contactBook->run();
    return 0;
}