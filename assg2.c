#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct cricket
{
    char name[15], country[15], category[15];
    int age, odi, TT, batscore, wickets;
}cricket;

void accept(cricket *tempP);
void display(cricket *tempP);
void delete(cricket arrP[], int *size);
void modify(cricket arrP[], int size);

int main()
{
    int n, choice=0, c, max, index;
    printf("Enter number of players: \n");
    scanf("%d",&n);
    cricket s[n];
    for(int i=0; i<n; i++)
    {
        accept(&s[i]);
    }

    char inpcnt[15], inpname[15];

    do
    {        
        printf("\n1) Show the number of batsmen of a particular country\n");
        printf("2) Show the number of baowlers of a particular country\n");
        printf("3) Show the player with average batting score\n");
        printf("4) Show the player with most wickets taken\n");
        printf("5) Show a particular player's entire Display Board information\n");
        printf("6) Delete an entry\n");
        printf("7) Modify an entry\n");
        printf("8) Quit\n");
        scanf("%d", &choice);

    
        switch(choice)
        {
            case 1: c=0;
            printf("Enter name of a country: ");
            scanf("%s", inpcnt);
            for(int i=0; i<n; i++)
            {
                
                if((strcmp(s[i].category, "Batsman")==0)&&(strcmp(s[i].country, inpcnt)==0))
                {
                    c++;
                }
            }
            printf("Number of batsmen in %s is %d\n", inpcnt, c);
            break;

            case 2: c=0;
            printf("Enter name of a country: ");
            scanf("%s", inpcnt);
            for(int i=0; i<n; i++)
            {
                
                if((strcmp(s[i].category, "Bowler")==0)&&(strcmp(s[i].country, inpcnt)==0))
                {
                    c++;
                }
            }
            printf("Number of bowlers in %s is %d\n", inpcnt, c);
            break;

            case 3: max=0; 
            for(int i=0; i<n; i++)
            {            
                if(s[i].batscore>max)
                {
                    max=s[i].batscore;
                    index=i;                        
                }                
            }
            display(&s[index]);
            break;

            case 4: max=0; 
            for(int i=0; i<n; i++)
            {            
                if(s[i].wickets>max)
                {
                    max=s[i].wickets;
                    index=i;                        
                }                
            }
            display(&s[index]);
            break;

            case 5: printf("Enter name of player: ");
            scanf("%s", inpname);
            for(int i=0; i<n; i++)
            {
                if(strcmp(inpname, s[i].name)==0)
                {
                    display(&s[i]);
                }
            }
            break;

            case 6: delete(s, &n);
            break;

            case 7: modify(s, n); 
            break;
        }
    }while(choice!=8);
    return 0;
}

void accept(cricket *tempP)
{
    printf("\nEnter the name of the player: ");
    scanf("%s", tempP->name);
    printf("Enter the age of the player: ");
    scanf("%d", &tempP->age);
    printf("Enter country of the player: ");
    scanf("%s", tempP->country);
    printf("Enter category of the player: ");
    scanf("%s", tempP->category);
    printf("Enter the number of ODIs played: ");
    scanf("%d", &tempP->odi);
    printf("Enter the number of International 20-20s played: ");
    scanf("%d", &tempP->TT);
    printf("Enter the average batting score: ");
    scanf("%d", &tempP->batscore);
    printf("Enter the number of wickets taken: ");
    scanf("%d", &tempP->wickets);    
    printf("\n");
}

void display(cricket *tempP)
{
    printf("Name: %s\nAge: %d\nCountry: %s\nCategory: %s\nODIs: %d\n20-20s: %d\nBatting score: %d\nWickets: %d\n", tempP->name, tempP->age, tempP->country, tempP->category, tempP->odi, tempP->TT, tempP->batscore, tempP->wickets);
}

void delete(cricket arrP[], int *size)
{
    int pos;
    printf("Enter the entry you wish to delete (1 to %d): ", *size);
    scanf("%d", &pos);
    for(int i=pos-1; i<*(size)-1; i++)
    {
        arrP[i]=arrP[i+1];
    }
}

void modify(cricket arrP[], int size)
{
    int pos;
    printf("Enter the entry you wish to modify (1 to %d): ", size);
    scanf("%d", &pos);
    printf("\nEnter the name of the player: ");
    scanf("%s", arrP[pos].name);
    printf("Enter the age of the player: ");
    scanf("%d", &arrP[pos].age);
    printf("Enter country of the player: ");
    scanf("%s", arrP[pos].country);
    printf("Enter category of the player: ");
    scanf("%s", arrP[pos].category);
    printf("Enter the number of ODIs played: ");
    scanf("%d", &arrP[pos].odi);
    printf("Enter the number of International 20-20s played: ");
    scanf("%d", &arrP[pos].TT);
    printf("Enter the average batting score: ");
    scanf("%d", &arrP[pos].batscore);
    printf("Enter the number of wickets taken: ");
    scanf("%d", arrP[pos].wickets);
    printf("\n");
}

