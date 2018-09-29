#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void option(void);
struct {
        char name[30];
        char city[30];
        char state[30];
        char country[30];
    }student;
// enter the detail of the students
void search();
void del();
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


void display(){
    
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
    printf("1.add more\n2.display\n3.search\n4.delete\n5.exit");
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
        search();
        break;
        case 4:
        del();
        break;
        case 5: 
        exit(0);
        break;
        default:
        printf("please select one of the option");
    }




};

// search the detail in the database
void search(){
    FILE *fp;
    fp = fopen("data.txt","r");
    char a[30];
    printf("Enter the name of the studnet: ");
    scanf("%s",a);
    while(fscanf(fp,"%s %s %s %s",student.name,student.city,student.state,student.country)!=EOF){

        if(strcmp(a, student.name) == 0){
            printf("student.name: %s\n",student.name);
            printf("city: %s\n",student.city);
            printf("state: %s\n", student.state);
            printf("country: %s\n\n",student.country);
        
    }    
    }
    option();
}
//remove the data of the user
void del(){
    FILE *fp;
    fp = fopen("data.txt","w");
    char a[30];
    printf("Enter the name of the studnet: ");
    scanf("%s",a);
    while(fscanf(fp,"%s %s %s %s",student.name,student.city,student.state,student.country)!=EOF){

        if(strcmp(a, student.name) == 0){
            remove(student.name);       
    }    
    }
    option();
    
}
int main(void)
{
    option();
    return 0;    
}

