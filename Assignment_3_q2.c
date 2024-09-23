#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent a contact in a doubly linked list
typedef struct Contact {
    char name[50];
    struct Contact* prev;
    struct Contact* next;
} Contact;
// Head and tail pointers for the doubly linked list
Contact* head = NULL;
Contact* tail = NULL;
// Function to create a new contact
Contact* createContact(char* name) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    newContact->prev = NULL;
    newContact->next = NULL;
    return newContact;
}
// Function to display the contact list in forward order
void displayForward() {
    Contact* temp = head;
    printf("Contact list (forward): ");
    while (temp != NULL) {
        printf("%s <-> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Function to display the contact list in reverse order
void displayBackward() {
    Contact* temp = tail;
    printf("Contact list (backward): ");
    while (temp != NULL) {
        printf("%s <-> ", temp->name);
        temp = temp->prev;
    }
    printf("NULL\n");
}
// Function to insert a new contact at a specific position
void insertContact(char* name, int position) {
    Contact* newContact = createContact(name);

    if (head == NULL && position == 0) {
        head = newContact;
        tail = newContact;
    } else {
        Contact* temp = head;
        int i = 0;
        while (temp != NULL && i < position - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newContact);
            return;
        }

        if (temp->next == NULL) {
            temp->next = newContact;
            newContact->prev = temp;
            tail = newContact;
        } else {
            newContact->next = temp->next;
            temp->next->prev = newContact;
            temp->next = newContact;
            newContact->prev = temp;
        }
    }

    printf("Contact inserted successfully.\n");
    displayForward();
    displayBackward();
}
// Function to delete a contact by name or position
void deleteContactByPosition(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Contact* temp = head;
    int i = 0;
    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;
    free(temp);
    printf("Contact deleted successfully.\n");
    displayForward();
    displayBackward();
}
void deleteContactByName(char* name) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Contact* temp = head;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
    printf("Contact deleted successfully.\n");
    displayForward();
    displayBackward();
}
// Function to search for a contact
void searchContact(char* name) {
    Contact* temp = head;
    int position = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("%s found at position %d\n", name, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Contact not found!\n");
}
// Main function to run the contact management system
int main() {
    int choice, position, numContacts, i;
    char name[50];
    while (1) {
        printf("\n1. Create the list of contacts\n");
        printf("2. Insert a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Display contact list\n");
        printf("5. Search for a contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the number of contacts: ");
            scanf("%d", &numContacts);
            for (i = 0; i < numContacts; i++) {
                printf("Enter contact name %d: ", i + 1);
                scanf("%s", name);
                if (i == 0) {
                    head = createContact(name);
                    tail = head;
                } else {
                    Contact* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = createContact(name);
                    temp->next->prev = temp;
                    tail = temp->next;
                }
            }
            displayForward();
            displayBackward();
            break;
        case 2:
            printf("Enter the contact's name to insert: ");
            scanf("%s", name);
            printf("Enter the position (0-based index) to insert the contact: ");
            scanf("%d", &position);
            insertContact(name, position);
            break;
        case 3:
            printf("Delete by name or position? (n/p): ");
            char delChoice;
            scanf(" %c", &delChoice);  // Extra space before %c to consume newline
            if (delChoice == 'p') {
                printf("Enter the position (0-based index) to delete the contact: ");
                scanf("%d", &position);
                deleteContactByPosition(position);
            } else if (delChoice == 'n') {
                printf("Enter the contact's name to delete: ");
                scanf("%s", name);
                deleteContactByName(name);
            } else {
                printf("Invalid option!\n");
            }
            break;
        case 4:
            displayForward();
            displayBackward();
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
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}