#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 100

/* Define the contact structure */
struct Contact {
	char name[MAX_NAME_LENGTH];
	char phone[MAX_PHONE_LENGTH];
	char email[MAX_EMAIL_LENGTH];
	struct Contact *next; /* for linked list implementation */
};

struct Contact *head = NULL; /* the head of the linked list */

/* Function to add a new contact */
void addContact()
{
	struct Contact *newContact = (struct Contact *)malloc(sizeof(struct Contact));
	printf("Enter name: ");
	fgets(newContact->name, MAX_NAME_LENGTH, stdin);
	printf("Enter phone number: ");
	fgets(newContact->phone, MAX_PHONE_LENGTH, stdin);
	printf("Enter email address: ");
	fgets(newContact->email, MAX_EMAIL_LENGTH, stdin);
	newContact->next = head;
	head = newContact;
}

/* Function to display all contacts */
void displayContacts()
{
	struct Contact *current = head;
	while (current != NULL)
	{
		printf("Name: %sPhone: %sEmail: %s\n", current->name, current->phone, current->email);
		current = current->next;
	}
}

/* Function to search for a contact by name */
void searchContact(const char *name)
{
	struct Contact *current = head;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			printf("Contact found:\n");
			printf("Name: %sPhone: %sEmail: %s\n", current->name, current->phone, current->email);
			return;
		}
		current = current->next;
	}
	printf("Contact not found.\n");
}

/* Function to delete a contact by name */
void deleteContact(const char *name)
{
	struct Contact *current = head;
	struct Contact *prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			if (prev == NULL)
			{
				head = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current);
			printf("Contact deleted successfully.\n");
			return;
		}
		prev = current;
		current = current->next;
	}
	printf("Contact not found.\n");
}

/* Function to free memory when the program exits */
void cleanup()
{
	struct Contact *current = head;
	while (current != NULL)
	{
		struct Contact *next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	int choice;
	char searchName[MAX_NAME_LENGTH];

	while (1)
	{
		printf("\nContact Management System\n");
		printf("1. Add Contact\n");
		printf("2. View All Contacts\n");
		printf("3. Search Contact\n");
		printf("4. Delete Contact\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);

		switch (choice)
		{
		case 1:
			addContact();
			break;
		case 2:
			displayContacts();
			break;
		case 3:
			printf("Enter name to search: ");
			fgets(searchName, MAX_NAME_LENGTH, stdin);
			searchContact(searchName);
			break;
		case 4:
			printf("Enter name to delete: ");
			fgets(searchName, MAX_NAME_LENGTH, stdin);
			deleteContact(searchName);
			break;
		case 5:
			cleanup();
			exit(0);
		default:
			printf("Invalid choice. Try again.\n");
		}
	}

	return 0;
}
