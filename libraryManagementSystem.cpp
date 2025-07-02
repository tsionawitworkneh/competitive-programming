
#include <iostream>
#include <string>
#include <limits>   // for numeric_limits (used with cin.ignore)

using namespace std;



// Structure Definition for a Book Node.This struct defines the structure of each individual element
// (node)in our linked list. Each node holds the data for one book.
struct BookNode{
    string title;
    string author;
    int publishYear;
    string isbn;
    BookNode* next;     // Pointer to the next BookNode in the list. This is the link that connects nodes together.

};

// Pointer to the first node in the list (head of the linked list).
// Initialized to nullptr as the list is empty at the start.
BookNode* head = nullptr;


// Function Declarations

// Function to add a new book to the linked list.
// Takes the head pointer by reference to allow modifying it if the list was empty.
void addBook();

// Function to delete a book based on ISBN code or title.
// Takes the head pointer by reference to allow modifying it if the head is deleted.
void deleteBook();

// Function to search for a book based on its ISBN code.
// Takes the head pointer by value as it only reads the list, not modifies its structure.
void searchBookByISBN();

// Function to display all books currently in the list.
// Takes the head pointer by value as it only reads the list.
void listAllBooks();

// Function to free all dynamically allocated memory used by the list nodes.
// Called before exiting the program to prevent memory leaks.
// Takes the head pointer by reference to set it to nullptr after deletion.
void deleteAllBooks();

// Helper function to check if an ISBN already exists (useful for adding unique books)
bool isISBNExists(const string& isbn_to_check);


int main() {
    int choice;


    do {
        // Display the menu options to the user
        cout << "\n------********* Library Management System ******----------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Delete Book" << endl;
        cout << "3. Search Book by ISBN" << endl;
        cout << "4. List All Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";


        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                // Call the function to add a new book
                addBook();
                break;
            case 2:
                // Call the function to delete a book
                deleteBook();
                break;
            case 3:
                // Call the function to search for a book by ISBN
                searchBookByISBN();
                break;
            case 4:
                // Call the function to list all books
                listAllBooks();
                break;
            case 5:
                // Call deleteAllBooks to clean up memory before exiting
                deleteAllBooks();
                cout << "Exiting program. Memory cleared." << endl;
                break;
            default:
                // Handle invalid input
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // Loop continues as long as the choice is not 5


    return 0;
}


// Function Definitions

// Helper function to check if an ISBN already exists in the list.
// Parameter 'isbn_to_check' is the ISBN to look for.
// Returns true if the ISBN is found, false otherwise.
bool isISBNExists(const string& isbn_to_check) {
    BookNode* current = head; // Start traversal from the head of the list
    while (current != nullptr) {
        if (current->isbn == isbn_to_check) {
            return true; // ISBN found in the list
        }
        current = current->next; // Move to the next node
    }
    return false; // ISBN not found in the list
}


// Function to add a new book to the linked list.
// Creates a new node, gets data from the user, and links it to the end of the list.
void addBook() {
    string isbn;

    // Prompt for ISBN first to check for duplicates
    cout << "Enter ISBN code: ";
    getline(cin, isbn);

    // Check for duplicate ISBN BEFORE creating the node
    if (isISBNExists(isbn)) {
        cout << "Error: Book with ISBN " << isbn << " already exists. Book not added." << endl;
        return; // Exit the function without inserting
    }

    // If ISBN is unique, proceed to get other details and create the node
    BookNode* newNode = new BookNode; // Create a new node using dynamic memory allocation

    newNode->isbn = isbn; // Assign the validated ISBN

    cout << "Enter Title: ";
    getline(cin, newNode->title);

    cout << "Enter Author: ";
    getline(cin, newNode->author);

    cout << "Enter Publish Year: ";
    cin >> newNode->publishYear;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    // Set the 'next' pointer of the new node to nullptr,
    // as it will be the last node in the list (or the only node).
    newNode->next = nullptr;

    // Now, link the new node into the list (at the end)
    // Check if the list is currently empty
    if (head == nullptr) {
        // If empty, the new node becomes the head of the list
        head = newNode;
    } else {
        // If the list is not empty, traverse to the last node
        BookNode* temp = head; // Start traversal from the head
        while (temp->next != nullptr) {
            temp = temp->next; // Move to the next node until the last one is found
        }
        // The last node's 'next' pointer now points to the new node
        temp->next = newNode;
    }

    cout << "Book with ISBN " << isbn << " added successfully!" << endl;
}

// Function to delete a book from the linked list based on ISBN or title.
// Prompts the user to choose deletion criteria.
void deleteBook() {
    // Check if the list is empty
    if (head == nullptr) {
        cout << "No books to delete (library is empty)." << endl;
        return; // Exit the function
    }

    int criteria_choice;
    cout << "Delete by:\n1. ISBN\n2. Title\nEnter choice (1 or 2): ";
    cin >> criteria_choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    string search_criteria; // Variable to store the ISBN or Title the user enters

    if (criteria_choice == 1) {
        cout << "Enter ISBN of the book to delete: ";
        getline(cin, search_criteria);
    } else if (criteria_choice == 2) {
        cout << "Enter Title of the book to delete: ";
        getline(cin, search_criteria);
    } else {
        cout << "Invalid deletion criteria choice." << endl;
        return; // Exit the function if criteria is invalid
    }

    // Pointers for traversal: 'current' points to the node being examined,
    // 'previous' points to the node just *before* 'current'.
    BookNode* current = head;
    BookNode* previous = nullptr;
    bool found = false; // Flag to indicate if the book was found

    // Traverse the list to find the node based on the chosen criteria
    while (current != nullptr) {
        bool match = false;
        if (criteria_choice == 1 && current->isbn == search_criteria) {
            match = true; // Found by ISBN
        } else if (criteria_choice == 2 && current->title == search_criteria) {
            match = true; // Found by Title
        }

        if (match) {
            found = true; // Mark as found
            // If deleting the head node (previous is nullptr)
            if (previous == nullptr) {
                head = current->next; // Make head point to the next node
            } else {
                // If deleting a node in the middle or at the end
                previous->next = current->next; // Bypass the node to be deleted
            }

            // Store details before deleting for confirmation message
            string deleted_title = current->title;
            string deleted_isbn = current->isbn;

            delete current; // Free the memory occupied by the node

            cout << "Book \"" << deleted_title << "\" (ISBN: " << deleted_isbn << ") deleted successfully!" << endl;

            // For deletion by title, we might delete *all* matching titles or just the first.
            // This implementation deletes the *first* match found if deleting by title.
            // If deleting by ISBN, it should be unique, so we can exit after the first match.
            if (criteria_choice == 1 || criteria_choice == 2) { // Exit after finding one for either case as per typical requirement
                return; // Exit the function after deleting one match
            }

        } else {
             // Only move pointers if no match is found in the current node
             previous = current; // 'previous' always follows 'current'
             current = current->next; // Move 'current' to the next node
        }
    }

    // If the loop finishes and found is still false
    if (!found) {
         if (criteria_choice == 1) {
            cout << "Book with ISBN " << search_criteria << " not found!" << endl;
         } else if (criteria_choice == 2) {
            cout << "Book with Title \"" << search_criteria << "\" not found!" << endl;
         }
    }
}

// Function to find and display a book by its ISBN code.
void searchBookByISBN() {
    // Check if the list is empty
    if (head == nullptr) {
        cout << "No books available to search (library is empty)." << endl;
        return; // Exit the function
    }

    string isbn_to_find; // Variable to store the ISBN to find
    cout << "Enter ISBN of the book to find: ";
    // Use getline to read the ISBN
    getline(cin, isbn_to_find);

    
    BookNode* current = head;

    // Traverse the list starting from the head
    while (current != nullptr) {
        // Check if the current node's ISBN matches the target ISBN
        if (current->isbn == isbn_to_find) {
            // If found, display the book details
            cout << "\n--- Book Found ---" << endl;
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "Publish Year: " << current->publishYear << endl;
            cout << "ISBN: " << current->isbn << endl;
            cout << "------------------" << endl;
            return; // Book found and displayed, exit the function
        }
        // Move to the next node if the current one doesn't match
        current = current->next;
    }

    // If the loop finishes without finding the ISBN (current becomes nullptr), print a message
    cout << "Book with ISBN " << isbn_to_find << " not found!" << endl;
}

// Function to display all books in the linked list.
// Parameter 'head' is passed by value because the list structure is not modified.
void listAllBooks() {
    // Check if the list is empty
    if (head == nullptr) {
        cout << "No books to display (library is empty)." << endl;
        return; // Exit the function
    }

    // Print a header for the report
    cout << "\n===== All Books in the Library =====" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    // Optional: Add formatting header for columns (adjust widths as needed)
    // cout << "ISBN          | Year | Title                 | Author" << endl;
    // cout << "-------------------------------------------------------------------" << endl;


    BookNode* current = head; // Use a separate pointer for traversal
    int count = 0; // To count books for the total at the end

    // Traverse the list starting from the head
    while (current != nullptr) {
        // Print the details of the current book
        cout << "Book " << (count + 1) << ":" << endl;
        cout << "  ISBN: " << current->isbn << endl;
        cout << "  Title: " << current->title << endl;
        cout << "  Author: " << current->author << endl;
        cout << "  Publish Year: " << current->publishYear << endl;
        cout << "-------------------------------------------------------------------" << endl;


        // Move to the next node
        current = current->next;
        count++; // Increment count
    }

    cout << "Total Books: " << count << endl;
}

// Function to free all dynamically allocated memory in the linked list.
// This is essential to prevent memory leaks when the program exits.
// Parameter 'head' is passed by reference so the actual head pointer
void deleteAllBooks() {
    BookNode* current = head; // Start traversal from the head
    BookNode* nextNode;       // Pointer to hold the next node before deleting the current one

    // Traverse the list node by node until the end (current becomes nullptr)
    while (current != nullptr) {
        nextNode = current->next; //  Save pointer to the next node *before* deleting the current one
        delete current;           // Delete the node pointed to by current, freeing its memory
        current = nextNode;       // Move to the next node (which we saved)
    }
    // After the loop, all nodes have been deleted.
    // Set head to nullptr explicitly to indicate the list is now empty.
    head = nullptr;
    cout << "Memory cleared for all books." << endl; 
}