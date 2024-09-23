#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for contact node
typedef struct Contact {
    char name[50];
    struct Contact* next;
} Contact;

// Head pointer to the linked list
Contact* head = NULL;

// Function to create a new contact node
Contact* createContact(char name[]) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    newContact->next = NULL;
    return newContact;
}

// Function to insert a contact at a specific position
void insertContact(char name[], int position) {
    Contact* newContact = createContact(name);
    
    if (position == 0) {
        newContact->next = head;
        head = newContact;
    } else {
        Contact* temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position!\n");
        } else {
            newContact->next = temp->next;
            temp->next = newContact;
        }
    }
    printf("Contact inserted successfully.\n");
}

// Function to delete a contact by position
void deleteContactByPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position == 0) {
        Contact* temp = head;
        head = head->next;
        free(temp);
        printf("Contact deleted.\n");
    } else {
        Contact* temp = head;
        for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Invalid position!\n");
        } else {
            Contact* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            printf("Contact deleted.\n");
        }
    }
}

// Function to delete a contact by name
void deleteContactByName(char name[]) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (strcmp(head->name, name) == 0) {
        Contact* temp = head;
        head = head->next;
        free(temp);
        printf("Contact deleted.\n");
    } else {
        Contact* temp = head;
        while (temp->next != NULL && strcmp(temp->next->name, name) != 0) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Contact not found.\n");
        } else {
            Contact* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            printf("Contact deleted.\n");
        }
    }
}

// Function to display all contacts
void displayContacts() {
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }
    Contact* temp = head;
    printf("Contact list: ");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a contact by name
void searchContact(char name[]) {
    Contact* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("%s found at position %d.\n", name, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Contact '%s' not found.\n", name);
}

// Function to create the initial contact list
void createContactList() {
    int n;
    char name[50];
    printf("Enter the number of contacts: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter contact name %d: ", i + 1);
        scanf("%s", name);
        insertContact(name, i);
    }
}

// Main function with menu
int main() {
    int choice, position;
    char name[50];
    char delChoice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Create the list of contacts\n");
        printf("2. Insert a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Display contact list\n");
        printf("5. Search for a contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createContactList();
                displayContacts();
                break;
            case 2:
                printf("Enter the contact's name to insert: ");
                scanf("%s", name);
                printf("Enter the position (0-based index) to insert the contact: ");
                scanf("%d", &position);
                insertContact(name, position);
                displayContacts();
                break;
            case 3:
                printf("Delete by name or position? (n/p): ");
                scanf(" %c", &delChoice);  
                if (delChoice == 'p') {
                    printf("Enter the position to delete: ");
                    scanf("%d", &position);
                    deleteContactByPosition(position);
                } else if (delChoice == 'n') {
                    printf("Enter the contact's name to delete: ");
                    scanf("%s", name);
                    deleteContactByName(name);
                } else {
                    printf("Invalid choice.\n");
                }
                displayContacts();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Enter the contact's name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
