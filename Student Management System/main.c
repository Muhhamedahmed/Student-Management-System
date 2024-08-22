/*
 * main.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Muhamed Ahmed
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int id;           /* student id   */
    char name[50];   /* student name */
    int age;        /* student age  */
    float gpa;     /* student gpa  */
};
/* Define a struct to represent a node in the linked list */
struct node{
    struct student data;
    struct node *next;
};
//Defining the head of the linked list//
struct node *head = NULL;
// function to add students with their data as a scan input from user to linked list//
void addstudent(const struct student*const ptr){
    struct node *current =NULL;
    struct node *link = (struct node *)malloc(sizeof(struct node));
    /* Assign the student data to the node */
    link->data.id = ptr->id;
    strcpy(link->data.name, ptr->name);
    link->data.age = ptr->age;
    link->data.gpa = ptr->gpa;
    link->next= NULL;
    if(head==NULL){
        head=link;
        return;
    }
    current = head;
    // loop until reach the last node in the old list//
    while(current->next!=NULL){
        current=current->next;
    }
    // Make the last node in the old list point to new node//
    current->next=link;
}
//Afunction to display all the students that enteret the sysytem//
void display(void){
    struct node*ptr=head;
    while(ptr!=NULL){
          printf("ID: %d, Name: %s, Age: %d, GPA: %f\n",ptr->data.id, ptr->data.name, ptr->data.age, ptr->data.gpa);
        ptr = ptr->next;
    }
}
// a function to search on a student ino. by id//
void searchid(int id){
    struct node *current= NULL;
    if(head==NULL){
        printf("The list is empty");
        return;
    }
    current=head;
    while(current!=NULL){
        if(current->data.id==id){
            printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", current->data.id,
            current->data.name, current->data.age, current->data.gpa);
            return;
        }
        current=current->next;
    }
    printf("ID not found");
}
// a function to update the data of the student by entering the id//
void update(int id){
    struct node *current=NULL;
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    current =head;
    while(current != NULL){
        if(current->data.id==id){
            printf("Enter new name:");
            fflush(stdout);
            scanf("%s",&current->data.name);
            printf("Enter new age:");
            fflush(stdout);
            scanf("%d", &current->data.age);
            printf("Enter new gpa:");
            fflush(stdout);
            scanf("%f",&current->data.gpa);
            printf("The student information has been updated successfully");
            return;
        }
        current=current->next;
    }
    printf("The ID is not found");
}
// a function to delete the info of the student by entering his id//
void delete(int id){
    // pointer to loop in linked list//
    struct node *current=NULL;
    struct node *prev =NULL;
    struct node *delete_node = NULL;// pointer to point the node that will be deleted//

    if(head==NULL){//check if the linked list is empty//
        printf("The list is empty");
        return;
    }
    //check the first node in the linked list//
    if(head->data.id==id){
        delete_node = head;
        head = head->next;
        free(delete_node);
        return;
    }
    //check the rest of nodes in the linked list//
    current=head->next;
    prev=head;
    while(current!=NULL){
        if(current->data.id==id){
            delete_node=current;
            prev->next=current->next;
            free(delete_node);
            return;
        }
        prev=current;
        current=current->next;
    }
//in case the data not found in the linked list//
printf("%d not found in the List.",id);
}
// function to calculate the average gpa of the total students//
void average(void){
    struct node *current= NULL;
    float total_gpa=0.0;
    int count=0;
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    current=head;
    while(current!=NULL){
        total_gpa+=current->data.gpa;// Sum up the GPA//
        count++;// Count the number of students//
        current=current->next;
    }
     if (count == 0) {
        printf("No students found to calculate the average GPA.\n");
        return;
    }
     // Calculate and print the average GPA//
     float average_gpa=total_gpa/count;
     printf("The average gpa fo rall students: %f",average_gpa);

}
// function to get the student with the max gpa//
void max(void){
    struct node *current=NULL;
    int max;
    if(head==NULL){
        printf("the list is empty");
        return;
    }
    max = head->data.gpa;
    current=head->next;
    while(current != NULL){
        if(current->data.gpa > max){
            max=current->data.gpa;
        }
        current = current->next;
    }
     printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", current->data.id,
            current->data.name, current->data.age, current->data.gpa);
}
int main(void){
    int op;
    struct student temp_student;
    int id;
     for(;;){//makink an infinite loop to keep runing while user still entering data//

    printf("1.Add student\n2.Display students\n3.Search by id\n4.Update student information\n5.Delete student\n6.Calculate average gpa\n7.Search for student for highest gpa\n8.Exit\n");
    printf("Enter choice: ");
    fflush (stdout);
    scanf("%d",&op);
    printf("==================================\n");
    switch (op) {
        case 1:
        printf("Enter ID: ");
        fflush(stdout);
        scanf("%d",&temp_student.id);
        printf("Enter name: ");
        fflush(stdout);
        scanf("%s",&temp_student.name);
        printf("Enter Age: ");
        fflush(stdout);
        scanf("%d", &temp_student.age);
        printf("Enter GPA: ");
        fflush(stdout);
        scanf("%f", &temp_student.gpa);
        addstudent(&temp_student);
        printf("==================================\n");
        break;
        case 2:
        display();
        printf("==================================\n");
        break;
        case 3:
        printf("Enter ID:");
        fflush(stdout);
        scanf("%d",&id);
        searchid(id);
        printf("==================================\n");
        break;
        case 4:
        printf("Enter student ID to update it's information:");
        fflush(stdout);
        scanf("%d",&id);
        update(id);
        printf("==================================\n");
        break;
        case 5:
        printf("Enter student ID to be deleted:");
        fflush(stdout);
        scanf("%d", &id);
        delete(id);
         printf("Student with ID: %d deleted successfully,",id);
         printf("==================================\n");
        break;
        case 6:
        average();
        printf("==================================\n");
        break;
        case 7:
        max();
        printf("==================================\n");
        break;
        case 8:
        printf("Exiting....");
        exit(0);
        break;
    }
     }
}

