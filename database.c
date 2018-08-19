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
       
        printf("2.Enter the name of the student: \n");
        scanf("%s", student.name);
        printf("3.Enter the city of the student: \n");
        scanf("%s", student.city);
        printf("4.Enter the state of the student: \n");
        scanf("%s", student.state);
        printf("5.Enter the country of the student: \n");
        scanf("%s", student.country);
        
    
    option();
};


void display(void){
    
    FILE *fp;
    fp = fopen("data.txt","a+");
    
    fprintf(fp,"%s\n",student.name);
    fprintf(fp,"%s\n",student.city);
    fprintf(fp,"%s\n", student.state);
    fprintf(fp,"%s\n",student.country);
    fclose(fp);
    fp = fopen("data.txt","r");
    while(fscanf(fp,"%s %s %s %s",student.name,student.city,student.state,student.country)!=EOF){
        
        printf("student.name: %s\n",student.name);
        printf("city: %s\n",student.city);
        printf("state: %s\n", student.state);
        printf("country: %s\n\n",student.country);
        
    }
    if(EOF){
        printf("There is no data! please add some data\n");
    }
    fclose(fp);
   
    
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
