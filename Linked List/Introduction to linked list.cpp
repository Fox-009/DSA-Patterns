#include <iostream>
using namespace std;

// ========================
// NODE CLASS
// ========================
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = nullptr;
        // constructor automatically sets up the node!
    }
};

// ========================
// LINKED LIST CLASS
// ========================
class LinkedList
{
private:
    Node *head; // pointer to first node
    int size;   // track number of nodes

public:
    // Constructor - called when LinkedList object is created
    LinkedList()
    {
        head = nullptr; // empty list
        size = 0;
    }

    // Destructor - called when LinkedList object is destroyed
    // Automatically frees all memory!
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current; // free each node
            current = nextNode;
        }
        cout << "LinkedList destroyed, memory freed!\n";
    }

    // ========================
    // INSERT AT BEGINNING
    // ========================
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data); // create new node

        newNode->next = head; // new node points to old head
        head = newNode;       // head now points to new node
        size++;

        cout << data << " inserted at beginning\n";
    }

    // ========================
    // INSERT AT END
    // ========================
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            size++;
            return;
        }

        // Travel to last node
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
        size++;

        cout << data << " inserted at end\n";
    }

    // ========================
    // INSERT AT POSITION
    // ========================
    void insertAtPosition(int data, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 0)
        {
            insertAtBeginning(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *current = head;

        // Go to node just before position
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        size++;

        cout << data << " inserted at position " << position << "\n";
    }

    // ========================
    // DELETE FROM BEGINNING
    // ========================
    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        int deletedValue = temp->data;
        delete temp; // C++ uses delete, not free
        size--;

        cout << deletedValue << " deleted from beginning\n";
    }

    // ========================
    // DELETE FROM END
    // ========================
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        // Only one node
        if (head->next == nullptr)
        {
            int deletedValue = head->data;
            delete head;
            head = nullptr;
            size--;
            cout << deletedValue << " deleted from end\n";
            return;
        }

        // Travel to second to last
        Node *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        int deletedValue = current->next->data;
        delete current->next;    // delete last node
        current->next = nullptr; // second to last becomes last
        size--;

        cout << deletedValue << " deleted from end\n";
    }

    // ========================
    // DELETE SPECIFIC VALUE
    // ========================
    void deleteValue(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        // If head node has the value
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            cout << value << " deleted\n";
            return;
        }

        // Search for value
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
                cout << value << " deleted\n";
                return;
            }
            current = current->next;
        }

        cout << value << " not found!\n";
    }

    // ========================
    // SEARCH
    // ========================
    int search(int value)
    {
        Node *current = head;
        int position = 0;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << "Found " << value << " at position " << position << "\n";
                return position;
            }
            current = current->next;
            position++;
        }

        cout << value << " not found!\n";
        return -1;
    }

    // ========================
    // REVERSE THE LIST
    // ========================
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *nextNode = nullptr;

        while (current != nullptr)
        {
            nextNode = current->next; // save next
            current->next = prev;     // reverse pointer
            prev = current;           // move prev ahead
            current = nextNode;       // move current ahead
        }

        head = prev; // prev is now new head
        cout << "List reversed!\n";
    }

    // ========================
    // GET MIDDLE NODE
    // ========================
    void findMiddle()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        // Two pointer technique (slow and fast)
        // slow moves 1 step, fast moves 2 steps
        // When fast reaches end, slow is at middle!

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // move 1 step
            fast = fast->next->next; // move 2 steps
        }

        cout << "Middle element = " << slow->data << "\n";
    }

    // ========================
    // DISPLAY
    // ========================
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr)
            {
                cout << " --> ";
            }
            current = current->next;
        }
        cout << " --> nullptr\n";
    }

    // ========================
    // GET SIZE
    // ========================
    int getSize()
    {
        return size;
    }

    // ========================
    // GET ELEMENT AT INDEX
    // ========================
    int getAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range!\n";
            return -1;
        }

        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }
};

// ========================
// MAIN - TESTING
// ========================
int main()
{
    LinkedList ll; // creates LinkedList object (calls constructor)

    cout << "========= INSERTION =========\n";
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.display(); // 10 --> 20 --> 30 --> nullptr

    ll.insertAtBeginning(5);
    ll.display(); // 5 --> 10 --> 20 --> 30 --> nullptr

    ll.insertAtPosition(25, 3);
    ll.display(); // 5 --> 10 --> 20 --> 25 --> 30 --> nullptr

    cout << "\n========= DELETION =========\n";
    ll.deleteFromBeginning();
    ll.display(); // 10 --> 20 --> 25 --> 30 --> nullptr

    ll.deleteFromEnd();
    ll.display(); // 10 --> 20 --> 25 --> nullptr

    ll.deleteValue(20);
    ll.display(); // 10 --> 25 --> nullptr

    cout << "\n========= SEARCH =========\n";
    ll.search(25); // Found 25 at position 1
    ll.search(99); // 99 not found

    cout << "\n========= REVERSE =========\n";
    ll.insertAtEnd(50);
    ll.insertAtEnd(60);
    ll.display(); // 10 --> 25 --> 50 --> 60 --> nullptr
    ll.reverse();
    ll.display(); // 60 --> 50 --> 25 --> 10 --> nullptr

    cout << "\n========= MIDDLE =========\n";
    ll.findMiddle(); // Middle = 50

    cout << "\n========= SIZE =========\n";
    cout << "Size = " << ll.getSize() << "\n"; // 4

    cout << "\n========= GET AT INDEX =========\n";
    cout << "Element at index 2 = " << ll.getAt(2) << "\n"; // 25

    // Destructor called automatically when ll goes out of scope
    return 0;
}