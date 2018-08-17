#include <stdio.h>
#include <stdlib.h>
void option(void);
struct {
        char name[30];
        char city[30];
        char state[30];
        char country[30];
    }student;
// enter the detail of the students
void enter(void){
    int no_of_student,i;
    printf("Enter the no of student :");
    scanf("%d",&no_of_student);
    if(no_of_student == 0){
            printf("\nPlease select more than 1 student to add\n\n\a");
        }
    
    for(i = 1; i <= no_of_student; ++i)
    {
        printf("1.Enter the name of  %d the student: \n",i);
        scanf("%s", student.name);
        printf("2.Enter the city of %d the student\n",i);
        scanf("%s", student.city);
        printf("2.Enter the state of %d the student\n",i);
        scanf("%s", student.state);
        printf("2.Enter the country of %d the student\n",i);
        scanf("%s", student.country);
        
    }
    option();
};
void display(void){
    
    printf("student name:- %s\n", student.name);
    printf("student city:- %s\n", student.city);
    printf("student state:- %s\n", student.state);
    printf("student country:- %s\n", student.country);
    option();
};

//ask the user about task after enter function 
void option(void){
    int choice;
    printf("------------------------------------\n");
    printf("1.add more\n2.display\n3.exit\n");
    printf("select one of the following: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        enter();
        break;
        case 2:
        display();
        break;
        case 3:
        exit (0);
        break;
        default:
        printf("please select one of the option");
    }




};


int main(void)
{
    
    printf("1.enter\n2.display\n");
    int user;
    printf("Select one of the following option:\n");
    scanf("%d",&user);
    switch(user){
        case 1:
            enter();
            break;
        case 2:
           display();
           break; 
        default :
            printf("Enter correct option\n");
    };
    
    
    
    return 0;    
}
