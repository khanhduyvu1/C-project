/*
 * Khanh Vu
 * U56604117
 * Program manages and tracks the guest list for a local restaurant
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
	char phone[PHONE_LEN+1];
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int party_size;
	struct guest *next;
};
struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct guest *new_list = NULL;  
  printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = add_guest(new_list);
                break;
      case 'p': print_list(new_list);
                break;
      case 'q': clear_list(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
struct guest *add_guest(struct guest *list){
    char phone[PHONE_LEN+1];
    char last[NAME_LEN+1];
    char first[NAME_LEN+1];
    int party_size;
    struct guest *current = list;
    struct guest *new = (struct guest *)malloc(sizeof(struct guest));

    //enter phone number and check for if it exist or not
    printf("Enter phone number: ");
    scanf("%s", phone);
    while (current != NULL){
        if (strcmp(current->phone,phone)==0){
            printf("guest already exists.");
            free(new);
            return list;
        }
        current = current->next;
    }
    strcpy(new->phone,phone);
    //enter first and last name and party size
    printf("Enter guest's last name: ");
    read_line(last,NAME_LEN+1);
    strcpy(new->last,last);
    printf("Enter guest's first name: ");
    read_line(first,NAME_LEN+1);
    strcpy(new->first,first);
    printf("Enter party size: ");
    scanf("%d", &party_size);
    new->party_size = party_size;
    new->next = NULL;

// move to the end of the list
    if (list == NULL){
        return new;
    }
    else{
        current = list;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new;
        return list;
    }
}
void print_list(struct guest *list){
    while (list != NULL) {
        printf("%-15s%-20s%-20s%5d\n", list->phone, list->last, list->first, list->party_size);
        list = list->next;
    }
}
void clear_list(struct guest *list){
    struct guest *current = list;
    struct guest *next;
    //clear the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
