#include <iostream>
#include <string>

using namespace std;


struct Node {
    string name;
    string ph_No;
    Node* next;
};

// class phone directory;
class PhoneDirectory {
private:
	//pointer
    Node* head; 

public:
    
    PhoneDirectory() {
        head = nullptr;
    }

    // Destructor
    ~PhoneDirectory() {
        // Delete all nodes
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // add a new contact number
    void addContact(const string& name, const string& ph_No) {
        // Create  new node
        
        Node* newNode = new Node;
        newNode->name = name;
        newNode->ph_No = ph_No;
        newNode->next = nullptr;

        if (head == nullptr) {
            // If the list is empty, set the new node as the head
            head = newNode;
        } else {
            // Find the last node and add the new node at the end
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Contact Numner has added successfully." << endl;
        cout<<endl;
    }

    // search for a contact number
    
    void searchContact(const string& name) {
        Node* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->name == name) {
                cout << "Name: " << current->name << endl;
                cout << "Phone Number: " << current->ph_No << endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    // delete a contact number
    void deleteContact(const string& name) {
        if (head == nullptr) {
            cout << "Phone directory is empty." << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        bool found = false;

        while (current != nullptr) {
            if (current->name == name) {
                if (previous == nullptr) {
                    // If the contact to be deleted is the head node
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                found = true;
                cout << "Contact deleted successfully." << endl;
                cout<<endl;
                break;
            }
            previous = current;
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    // Function to display all contacts
    void displayContacts() {
        if (head == nullptr) {
            cout << "Phone directory is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << endl;
            cout << "Phone Number: " << current->ph_No<< endl;
            cout << "---------------------------" << endl;
            current = current->next;
        }
    }
};

// Main function
int main() {
    PhoneDirectory directory;
    int choice;

cout<<"\n\tSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n\n"; 
cout<<"\t\t\t PHONE DIRECTORY SYSTEM\n"; 
cout<<"\n\tSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n\n"; 
cout<<"\n\t1- ADD CONTACT NUMBERS\n"; 
cout<<"\n\t2- SEARCH CONTACT NUMBERS\n";
cout<<"\n\t3- DELETE CONTACT NUMBERS\n";
cout<<"\n\t4- SEE THE OVERALL LIST OF CONTACT NUMBERS\n";                                        
cout<<"\n\tSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n\n"; 

    do {
        cout << "PHONE DIRECTORY" << endl;
        cout<<endl;
        cout << "1. Add Contact Number" << endl;
        cout << "2. Search  Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Display All Contact Numbers" << endl;
        cout << "5. Exit" << endl;
        cout<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1: {
                string name, ph_No;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter phone number: ";
                cin >> ph_No;
                directory.addContact(name, ph_No);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, name);
                directory.searchContact(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter name to delete: ";
                cin.ignore();
                getline(cin, name);
                directory.deleteContact(name);
                break;
            }
            case 4:
                directory.displayContacts();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);
    cout<<"\nTHANK YOU"<<endl;

    return 0;
}
