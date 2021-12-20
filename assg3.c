#include<stdio.h>
#include<string.h>

struct bill
{
    char item[20];
    int quantity;
    int unit_price;
};

void accept(struct bill arr[10], int size);
void write_to_file(struct bill temp);
void read_and_display();
void display_one(char item_in[]);
void delete(char item_in[]);

int main()
{
    int n, choice;
    char inputitem[20];
    printf("Enter no. of entries (0 if you do not wish to enter): ");
    scanf("%d", &n);
    struct bill B[20];
    accept(B, n);
    for(int i=0; i<n; i++)
    {
        write_to_file(B[i]);
    }
    do
    {         
        printf("\nChoose an action:\n1)Add an entry\n2)Display all entries\n3)Display entry of a particular item\n4)Delete an entry\n5)Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if(n>=20)
            {
                printf("No more space\n");
            }
            else
            {
                printf("Enter product name: ");
                scanf("%s", B[n].item); 
                printf("Enter quantity: ");
                scanf("%d", &B[n].quantity);
                printf("Enter unit price: ");
                scanf("%d", &B[n].unit_price);            
                write_to_file(B[n]);      
            }
            break;

        case 2:
            read_and_display();
            break;

        case 3:
            printf("Enter an item to search for: ");
            scanf("%s", inputitem);
            display_one(inputitem);
            break;

        case 4:
            printf("Enter an item to delete its record: ");
            scanf("%s", inputitem);
            delete(inputitem);
            break;

        default: 
            break;
        }
    }while(choice!=5);  
    return 0;  
}

void accept(struct bill arr[10], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("\n");
        printf("Enter product name: ");
        scanf("%s", arr[i].item);
        printf("Enter quantity: ");
        scanf("%d", &arr[i].quantity);
        printf("Enter unit price: ");
        scanf("%d", &arr[i].unit_price);
        printf("\n");
    }
}

void write_to_file(struct bill temp)
{
    FILE *fp;
    fp=fopen("assg3data.txt", "a");
    if(fp==NULL)
    {
        printf("File not found");
    }
    else
    {
        fprintf(fp, "%s\t\t%d\t%d\t", temp.item, temp.quantity, temp.unit_price);
        fputs("\n", fp);
    }
    fclose(fp);
}

void read_and_display()
{
    char item[20];
    int quantity, price;
    FILE *fp;
    fp=fopen("assg3data.txt", "r"); 
    if(fp==NULL)
    {
        printf("File not found");
    }    
    else
    {
        while(fscanf(fp, "%s%d%d", item, &quantity, &price)!=EOF)
        {
            printf("%s\t\t%d\t%d\n", item, quantity, price);
        }        
    }
    fclose(fp);
}

void display_one(char item_in[])
{
    char item[20];
    int quantity, price, flag=0;
    FILE *fp;
    fp=fopen("assg3data.txt", "r");    
    if(fp==NULL)
    {
        printf("File not found");
    }
    else
    {
        while(fscanf(fp, "%s%d%d", item, &quantity, &price)!=EOF)
        {
            if(strcmp(item_in, item)==0)
            {
                printf("%s\t\t%d\t%d\n", item, quantity, price);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No matching entry found.");
        }
    }
    fclose(fp); 
}

void delete(char item_in[])
{
    char item[20];
    int quantity, price;
    FILE *fp, *fp1;
    fp=fopen("assg3data.txt", "r");
    fp1=fopen("assg3temp.txt", "w");
    if(fp==NULL || fp1==NULL)
    {
        printf("File not found");
    }
    else
    {
        while(fscanf(fp, "%s%d%d", item, &quantity, &price)!=EOF)
        {
            if(strcmp(item_in, item)!=0)
            {
                fprintf(fp1, "%s\t\t%d\t%d\n", item, quantity, price);
            }
        }
        fclose(fp);
        fclose(fp1);
        fp=fopen("assg3data.txt", "w");
        fp1=fopen("assg3temp.txt", "r");
        while(fscanf(fp1, "%s%d%d", item, &quantity, &price)!=EOF)
        {           
            fprintf(fp, "%s\t\t%d\t%d\n", item, quantity, price);            
        }
    }
    fclose(fp);
    fclose(fp1);
}