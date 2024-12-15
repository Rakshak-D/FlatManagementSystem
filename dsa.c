#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.h"
#include "flats.h"

int main() {
    // Declare necessary variables
    char user[5];
    int pass, i = 2;  // Login attempts
    int choice, subChoice; // To store main and sub-menu options

    // Login Page
    printf("-------- Welcome to Flat Management System --------\n");
    printf("              Please Login to Continue\n");
    printf("--------------------------------------------------\n");

    printf("Username: ");
    scanf("%4s", user);

    printf("Password: ");
    while (1) {
        scanf("%d", &pass);
        if (i == 0) {
            printf("\nSorry, Maximum Number of Attempts Reached. Exiting...\n");
            exit(0);
        }
        if (pass != 1234) {
            printf("\nIncorrect Password. Try again (%d attempts left)\n", i);
            printf("Password: ");
            i--;
        } else {
            printf("\n-------- Successfully Logged In --------\n\n");
            break;
        }
    }

    // Administrator Menu
    while (1) {
        printf("\n===================== MENU =====================\n");
        printf("1. Load Flats Data (Read File)\n");
        printf("2. View Flats\n");
        printf("3. Search for a Flat\n");
        printf("4. Update Flat Information\n");
        printf("5. Add Owner\n");
        printf("6. Delete a Flat\n");
        printf("7. Save Changes (Write File)\n");
        printf("8. Logout\n");
        printf("================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n[INFO] Loading flats data...\n");
                // read_file(); // Function to read data from the file
                break;

            case 2:
                printf("\n[INFO] View Flats\n");
                printf("1. View by Flat Type (1BHK, 2BHK, 3BHK)\n");
                printf("2. View Booked Flats\n");
                printf("3. View Available Flats\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice) {
                    case 1:
                        printf("\n[INFO] Viewing flats by type...\n");
                        // view_by_type(); // Function to view flats by type
                        break;
                    case 2:
                        printf("\n[INFO] Viewing booked flats...\n");
                        // view_booked(); // Function to view booked flats
                        break;
                    case 3:
                        printf("\n[INFO] Viewing available flats...\n");
                        // view_available(); // Function to view available flats
                        break;
                    default:
                        printf("\n[ERROR] Invalid choice for viewing flats!\n");
                }
                break;

            case 3:
                printf("\n[INFO] Search for a Flat\n");
                printf("1. Search by Flat Number\n");
                printf("2. Search by Owner Name\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice) {
                    case 1:
                        printf("\n[INFO] Searching by flat number...\n");
                        // search_by_flat_number(); // Function to search by flat number
                        break;
                    case 2:
                        printf("\n[INFO] Searching by owner name...\n");
                        // search_by_owner_name(); // Function to search by owner name
                        break;
                    default:
                        printf("\n[ERROR] Invalid choice for searching flats!\n");
                }
                break;

            case 4:
                printf("\n[INFO] Update Flat Information\n");
                printf("1. Update Owner Name\n");
                printf("2. Update Contact Info\n");
                printf("3. Update the gender\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice) {
                    case 1:
                        printf("\n[INFO] Updating owner name...\n");
                        // update_owner_name(); // Function to update owner's name
                        break;
                    case 2:
                        printf("\n[INFO] Updating contact information...\n");
                        // update_contact_info(); // Function to update contact info
                        break;
                    case 3:
                        printf("\n[INFO] Updating gender information...\n");
                        // update_gender_info(); //function to update the gender info
                    default:
                        printf("\n[ERROR] Invalid choice for updating flat information!\n");
                }
                break;

            case 5:
               
                printf("\n[INFO] Add New Flat and Owner\n");
                char flatID[10], name[50], mobile[15], gender[10], paymentMethod[10];
                float emi, remaining;
                int isEMI, found = 0;

                printf("Enter Flat ID to Assign Owner: ");
                scanf(" %s", flatID);

                // Search for the flat in the loaded data
                for (int j = 0; j < current; j++) {
                    if (strcmp(residence[j].ID, flatID) == 0) {
                        found = 1; // Flat found
                        printf("Flat Found! Price: %.2f\n", residence[j].price);

                        // Prompt for owner details
                        printf("Enter Owner Name: ");
                        scanf(" %[^\n]", name);
                        printf("Enter Mobile Number: ");
                        scanf(" %s", mobile);
                        printf("Enter Gender: ");
                        scanf(" %s", gender);
                        printf("Choose Payment Method (Full/EMI): ");
                        scanf(" %s", paymentMethod);

                        if (strcmp(paymentMethod, "EMI") == 0 || strcmp(paymentMethod, "emi") == 0) {
                            printf("Enter EMI Amount: ");
                            scanf("%f", &emi);
                            remaining = residence[j].price - emi;
                            printf("EMI Chosen. Amount Paid: %.2f, Remaining: %.2f\n", emi, remaining);
                            residence[j].owner->paid = emi;    // Update paid amount
                            residence[j].owner->bal = remaining; // Update remaining balance
                        } else {
                            printf("Full Payment Chosen. Total Paid: %.2f, Remaining: 0.00\n", residence[j].price);
                            residence[j].owner->paid = residence[j].price; // Full payment
                            residence[j].owner->bal = 0;  // No balance
                        }

                        // Assign owner details
                        strcpy(residence[j].owner->owner, name);
                        strcpy(residence[j].owner->o_info, mobile);
                        break;
                    }
                }

                if (!found) {
                    printf("\n[ERROR] Flat ID not found in the dataset. Please try again.\n");
                }
                break;


            case 6:
                printf("\n[INFO] Deleting a flat...\n");
                // delete_flat(); // Function to delete a flat incase the flat is not rsidable
                break;

            case 7:
                printf("\n[INFO] Saving changes to the file...\n");
                // write_file(); // Function to write data back to the file
                break;

            case 8:
                printf("\n[INFO] Logging out. Thank you for using the system.\n");
                exit(0);

            default:
                printf("\n[ERROR] Invalid choice! Please try again.\n");
        }
    }

    return 0;
}



//rest of the code



//use comments wherever u wanna call fucntions
//just do the menu and log out option...
//add whatever features u want and call the functions as comments, i'll just write the functions... try to explain about the function using comments

