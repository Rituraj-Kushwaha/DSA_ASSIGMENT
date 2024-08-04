#include <stdio.h>
#include <string.h>

// Define the structure Type to be nested in the Friend structure
struct Type {
    char friendtype[20]; // Type of friend (School, College or Area friend)
    char common_friends_name[50]; // Name of common friends
    int places_visited; // Number of places visited together
};

// Friends sturcture defining
struct Friends {
    char name[50]; // Friend's name
    char pet_name[20]; // Pet name
    char phone_number[20]; // Phone number
    struct Type type; // Nested structure Type
};

int main() {
    int num_of_friends;
    printf("Enter the number of friends to add: ");
    scanf("%d", &num_of_friends);

    struct Friends friends[num_of_friends];

    // User Input Data 
    for (int i = 0; i < num_of_friends; i++) {
        printf("Enter Friend Name: ");
        scanf("%s", friends[i].name);
        printf("Enter Pet Name: ");
        scanf("%s", friends[i].pet_name);
        printf("Enter Phone Number: ");
        scanf("%s", friends[i].phone_number);
        printf("Enter Type of friend: ");
        scanf("%s", friends[i].type.friendtype);
        printf("Enter Name of Common Friends: ");
        scanf("%s", friends[i].type.common_friends_name);
        printf("Enter No. of Places Visited Together: ");
        scanf("%d", &friends[i].type.places_visited);
        printf("\n");
    }

    // Displaying data
    printf("\nFriends List:\n");
    printf("S.No.\tName\t\tPet Name\tPhone Number\tType of Friend\tName of common friends\tNo. of places visited together\n");
    for (int i = 0; i < num_of_friends; i++) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\n", i + 1, friends[i].name, friends[i].pet_name, friends[i].phone_number, friends[i].type.friendtype, friends[i].type.common_friends_name, friends[i].type.places_visited);
    }

    return 0;
}