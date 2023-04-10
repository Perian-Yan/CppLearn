#include <iostream>
using namespace std;

#define MAX 3   // the max number of the contacts

struct People
{
    string name;
    string school;
    string email;
};

struct Contacts
{
    int size;
    People* people;
};

void show_home()
{
    cout << "**********************" << endl;
    cout << "*****  1. Add    *****" << endl;
    cout << "*****  2. Show   *****" << endl;
    cout << "*****  3. Delete *****" << endl;
    cout << "*****  4. Search *****" << endl;
    cout << "*****  5. Modify *****" << endl;
    cout << "*****  6. Empty  *****" << endl;
    cout << "*****  7. Exit   *****" << endl;
    cout << "**********************" << endl;

}

void contacts_add(Contacts* ptr)
{
    int i = ptr->size;
    if (i == MAX)
    {
        cout << "The contact has reached its maximum storage." << endl;
    }
    else
    {
        cout << "Please enter the name: ";
        cin >> ptr->people[i].name;
        cout << "Please enter the school: ";
        cin >> ptr->people[i].school;
        cout << "Please enter the email: ";
        cin >> ptr->people[i].email;

        cout << "A new contact has been successfully added: " << endl;
        cout << ptr->people[i].name << "\t" << ptr->people[i].school
            << "\t" << ptr->people[i].email << endl;

        ptr->size++;
    }


}

void contacts_show(Contacts* ptr)
{
    if (ptr->size == 0)
    {
        cout << "Empty contacts! Please add new people first." << endl;
    }
    else
    {
        for (int i = 0; i < ptr->size; i++)
        {
            cout << i << '\t' << ptr->people[i].name << "\t"
                << ptr->people[i].school << "\t" << ptr->people[i].email << endl;
        }
    }

}

void contacts_delete(Contacts* ptr)
{
    string name;
    bool name_found = 0;
    if (ptr->size == 0)
    {
        cout << "Empty contacts! Please add new people first." << endl;
    }
    else
    {
        while (!name_found)
        {
            cout << "Enter the name that you want to delete: " << endl;
            cin >> name;
            for (int i = 0; i < ptr->size; i++)
            {
                if (name == ptr->people[i].name)
                {
                    name_found = 1;
                    cout << i << '\t' << ptr->people[i].name << "\t"
                        << ptr->people[i].school << "\t" << ptr->people[i].email << "\t"
                        << "has been deleted!" << endl;
                    for (int j = i; j < ptr->size; j++)
                    {
                        if (i < ptr->size - 1)
                        {
                            ptr->people[j] = ptr->people[j + 1];
                        }
                        ptr->size--;
                    }
                }
            }
            if (!name_found)
            {
                cout << "'" << name << "'" << " not found!" << endl;
            }
        }


    }

}

void contacts_search(Contacts* ptr)
{
    string name;
    bool name_found = 0;
    if (ptr->size == 0)
    {
        cout << "Empty contacts! Please add new people first." << endl;
    }
    else
    {
        while (!name_found)
        {
            cout << "Enter the name that you want to search: " << endl;
            cin >> name;
            for (int i = 0; i < ptr->size; i++)
            {
                if (name == ptr->people[i].name)
                {
                    name_found = 1;
                    cout << i << '\t' << ptr->people[i].name << "\t"
                        << ptr->people[i].school << "\t" << ptr->people[i].email << endl;
                }
            }
            if (!name_found)
            {
                cout << "'" << name << "'" << " not found!" << endl;
            }
        }
    }
}

void contacts_modify(Contacts* ptr)
{
    string name;
    bool name_found = 0;
    if (ptr->size == 0)
    {
        cout << "Empty contacts! Please add new people first." << endl;
    }
    else
    {
        while (!name_found)
        {
            cout << "Enter the name that you want to modify: " << endl;
            cin >> name;
            for (int i = 0; i < ptr->size; i++)
            {
                if (name == ptr->people[i].name)
                {
                    name_found = 1;
                    cout << "The current information is: " << endl;
                    cout << i << '\t' << ptr->people[i].name << "\t"
                        << ptr->people[i].school << "\t" << ptr->people[i].email << endl;
                    cout << "Change the name to: ";
                    cin >> ptr->people[i].name;
                    cout << "Change the school to: ";
                    cin >> ptr->people[i].school;
                    cout << "Change the eamil to: ";
                    cin >> ptr->people[i].email;
                    cout << "Changes saved!" << endl;
                    cout << i << '\t' << ptr->people[i].name << "\t"
                        << ptr->people[i].school << "\t" << ptr->people[i].email << endl;
                }
            }
            if (!name_found)
            {
                cout << "'" << name << "'" << " not found!" << endl;
            }
        }
    }
}

void contacts_empty(Contacts* ptr)
{
    string name;
    if (ptr->size == 0)
    {
        cout << "The contact is already empty." << endl;
    }
    else
    {
        for (int i = 0; i < ptr->size; i++)
        {
            ptr->people[i].name = "";
            ptr->people[i].school = "";
            ptr->people[i].email = "";
        }
        ptr->size = 0;
        cout << "The contact is empty now!" << endl;

    }
}

int main()
{
    People arr[MAX];
    Contacts contacts{};
    contacts.size = 0;
    contacts.people = arr;
    int select;

    while (true)
    {
        show_home();
        cout << "Please select a mode: " << endl;
        cin >> select;
        switch (select)
        {

        case 1:
            contacts_add(&contacts);
            break;
        case 2:
            contacts_show(&contacts);
            break;
        case 3:
            contacts_delete(&contacts);
            break;
        case 4:
            contacts_search(&contacts);
            break;
        case 5:
            contacts_modify(&contacts);
            break;
        case 6:
            contacts_empty(&contacts);
            break;
        case 7:
            cout << "Exit..." << endl;
            break;
        default:
            cout << "Please enter a valid number." << endl;
            break;
        }
        system("pause");
        system("cls");
        if (select == 7)
        {
            break;
        }
    }

    return 0;
}