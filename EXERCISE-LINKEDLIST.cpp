/**
 * Create a singly linked list that has 9
 * user defined functions to be called inside
 * the main function.
 * 
 * Created 2020-04-11 09:08:51
 * Finished 2020-04-11 20:00:41
 */

#include<iostream>
using namespace std;

struct Node {
    Node *next;
    int data;
};

Node *head, *tail;

void createList();
void addListBeginning();
void addListPosition();
void deleteListBeginning();
void deleteListEnd();
void deleteListPosition();
void reverseList();
void sortList();
void displayList();

int main() {
    while(true) {
        cout << "1. Create a list" << endl;
        cout << "2. Add at beginning" << endl;
        cout << "3. Add at a specific node" << endl;
        cout << "4. Delete at the beginning" << endl;
        cout << "5. Delete at the end" << endl;
        cout << "6. Delete at a specific node" << endl;
        cout << "7. Reverse" << endl;
        cout << "8. Sort" << endl;
        cout << "9. Display" << endl;
        cout << "Enter your choice: ";

        int selection;

        cin >> selection;

        if(selection != 1 && !head) {      
            cout << "Error: You don't have a list defined yet!" << endl;
            cout << "Please create a list first before modifying data. ";
            system("pause && cls");
            continue;
        }

        cin.ignore();

        switch(selection) {
            case 1:
                createList();
                break;
            case 2:
                addListBeginning();
                break;
            case 3:
                addListPosition();
                break;
            case 4:
                deleteListBeginning();
                break;
            case 5:
                deleteListEnd();
                break;
            case 6:
                deleteListPosition();
                break;
            case 7:
                reverseList();
                break;
            case 8:
                sortList();
                break;
            case 9:
                displayList();
                break;
            default:
                cout << "Invalid choice!";
        }
        
        cout << endl;
        system("pause && cls");
    }

    return 0;
}

void createList() {
    if(head != NULL) {
        cout << "Note: You already have a list defined." << endl;
        cout << "We'll just append this list to your current list." << endl;
        cout << "=================================" << endl;
    }

    int nodeCount;
    cout << "How many nodes do you want for the list? (int) > ";
    cin >> nodeCount;
    cout << "=================================" << endl;

    cin.ignore();
    cout << "Please enter " << nodeCount << " values of the list, separated by spaces. (ints) > ";

    for(int i = 0; i < nodeCount; i++) {
        int data;
        cin >> data;

        Node *tmp;

        tmp = new Node;
        tmp -> data = data;
        tmp -> next = NULL;

        if(head == NULL) {
            head = tmp;
        } else {
            Node *p = head;
            while(p -> next != NULL)
                p = p -> next;
            p -> next = tmp;
        }

        tail = tmp;
    }

    cin.ignore();

    cout << "=================================" << endl;
    cout << "List created.";

};

void addListBeginning() {
    int nodeData;
    cout << "Enter the data for the node to be inserted at the beginning (int) > ";
    cin >> nodeData;

    Node *p, *tmp;

    tmp = new Node;
    tmp -> data = nodeData;
    tmp -> next = NULL;

    p = head;
    head = tmp;
    head -> next = p;

    cout << "Node added to the beginning of the list.";
};

void addListPosition() {
    displayList();

    int nodePos;
    cout << endl << "What position do you want the node to be in? (int) > ";
    cin >> nodePos;
    cin.ignore();

    Node *ptr = head, *tmp, *sel;
    for(int i = 0; i < nodePos; i++) {
        ptr = ptr -> next;
        if(ptr == NULL) {
            cout << "Position out of bounds! Try again.";
            return;
        }
    }

    int nodeData;
    cout << "Enter the data of the new node > ";
    cin >> nodeData;

    Node *newNode = new Node;
    newNode -> data = nodeData;

    if(ptr == head) {
        tmp = head;
        head = ptr;
        head -> next = tmp;
    } else {
        sel = new Node;
        sel -> data = ptr -> data;
        ptr = head;
        while(ptr != NULL && ptr -> next -> data != sel -> data) {
            ptr = ptr -> next;
        }
        sel = ptr -> next;

        ptr -> next = newNode;
        newNode -> next = sel;
    }

    cout << "Node added.";
};

void deleteListBeginning() {
    if(!head -> next) {
        head = NULL;
    } else {
        Node *tmp = head -> next;
        delete(head);
        head = tmp;
    }

    cout << "First node in the list has been deleted.";
};

void deleteListEnd() {
    if(head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        Node *tmp = head;    
        while(tmp -> next != tail) {
            tmp = tmp -> next;
        }

        delete(tail);
        tail = tmp;
        tail -> next = NULL;
    }

    cout << "Last node deleted.";
};

void deleteListPosition() {
    displayList();

    int nodePos;
    cout << endl << "What node do you want to delete? (int) > ";
    cin >> nodePos;
    cin.ignore();

    Node *ptr = head, *tmp, *sel;
    for(int i = 0; i < nodePos; i++) {
        ptr = ptr -> next;
        if(ptr == NULL) {
            cout << "Position out of bounds! Try again.";
            return;
        }
    }

    if(ptr == head) {
        tmp = head -> next;
        delete(head);
        head = tmp;
    } else {
        tmp = head;

        while(tmp != NULL && tmp -> next != ptr) {
            tmp = tmp -> next;
        }

        tmp -> next = tmp -> next -> next;
        delete(ptr);
    }
    
    cout << "Node deleted.";
};

void reverseList() {
    Node *ptr = NULL, *lastptr = NULL, *temp = NULL;
    Node *newHead = NULL, *newTail = NULL;

    temp = head;

    while(temp!=NULL) {
        ptr = new Node;
        ptr -> next = NULL;
        ptr -> data = temp -> data;
        if(temp == head) { 
            ptr -> next = NULL;
            newTail = ptr;
        }
        else ptr -> next = lastptr;
        if(temp == tail) newHead = ptr;
        temp = temp -> next;
        lastptr = ptr;
    }

    head = newHead;
    tail = newTail;

    cout << "List has been reversed.";
};

void sortList() {
    Node *ptr2, *ptr, *tmp;
    Node *newHead = NULL, *newTail = NULL;

    ptr2 = head;

    while(ptr2 != NULL) {
        ptr = new Node;
        ptr -> data = ptr2 -> data;
        ptr -> next = NULL;

        if(newHead == NULL || newHead -> data >= ptr -> data) {
            ptr -> next = newHead;
            newHead = ptr;
        } else {
            tmp = newHead;
            while(tmp -> next != NULL &&
                tmp -> next -> data < ptr -> data) {
                tmp = tmp -> next;
            }
            ptr -> next = tmp -> next;
            tmp -> next = ptr;
        }

        if(ptr2 -> next == NULL) newTail = ptr2;
        ptr2 = ptr2 -> next;
    }

    head = newHead;
    tail = newTail;

    cout << "List has been sorted.";

};

void displayList() {
    Node *ptr = head;
    int pos = 0;

    cout << "List contents: ";

    while(ptr != NULL) {
        cout << "[" << pos << "] "  <<  ptr -> data << " ";
        ptr = ptr -> next;
        pos++;
    }

};

