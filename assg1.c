#include<stdio.h>
void getset(int *set, int size);
void showset(int *set, int n);
int unionF(int *setU, int *set1, int size1, int *set2, int size2);
int intersectionF(int *setI, int *set1, int size1, int *set2, int size2);
int difference(int *diff, int*set1, int size1, int*set2, int size2);
int min(int a, int b)
{
    int m;
    if(a>b)
    {
        m=b;
    }
    else
    {
        m=a;
    }
    return m;
}
int main()
{
    int sizeA, sizeB, choice=0;
    printf("Enter size of set A: ");
    scanf("%d", &sizeA);
    printf("Enter size of set B: ");
    scanf("%d", &sizeB);

    int setA[sizeA], setB[sizeB], unionSet[sizeA+sizeB], intersectionSet[min(sizeA, sizeB)], diffAB[sizeA], diffBA[sizeB], symmAB[sizeA+sizeB];

    printf("Enter the set A:\n");
    getset(setA, sizeA);

    printf("Enter the set B:\n");
    getset(setB, sizeB);

    int Usize=unionF(unionSet, setA, sizeA, setB, sizeB);
    int Isize=intersectionF(intersectionSet, setA, sizeA, setB, sizeB);
    int diffABsize=difference(diffAB, setA, sizeA, setB, sizeB);
    int diffBAsize=difference(diffBA, setB, sizeB, setA, sizeA);
    int symmsize=unionF(symmAB, diffAB, diffABsize, diffBA, diffBAsize);

    do
    {    
        printf("\nSelect an Operation:\n1]Union of A and B\n2]Intersection of A and B\n3]A-B\n4]B-A\n5]Symmetric difference of A and B\n6]Quit\n");
        scanf("%d", &choice);
        switch(choice)
        {  
            case 1: 
            printf("The union of A and B is: ");
            showset(unionSet, Usize);
            break;

            case 2: 
            printf("The intersection of A and B is: ");
            showset(intersectionSet, Isize);
            break;

            case 3: 
            printf("A-B is: ");
            showset(diffAB, diffABsize);
            break;

            case 4: 
            printf("B-A is: ");
            showset(diffBA, diffBAsize);
            break;

            case 5: 
            printf("Symmetric difference is: ");
            showset(symmAB, symmsize);
            break;

            case 6: break;

            default: printf("Invalid input, please retry with valid choice.");
            break;
        }
    }while(choice!=6);    

    return 0;
}
void getset(int *set, int size)
{
    for(int i=0;i<size;i++)  
    {
        printf("Element %d: ", i+1);
        scanf("%d", set+i);

    } 
}
void showset(int *set, int n)
{
    printf("{ ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", *(set+i));
    }
    printf("}\n");
}
int unionF(int *setU, int *set1, int size1, int *set2, int size2)
{
    int count=size1;
    for(int i=0;i<size1;i++)
    {
        *(setU)=*(set1+i);
        setU++;
    }    
    for(int j=0; j<size2; j++)
    {
        int flag=0;
        for(int k=0; k<size1; k++)
        {
            if(*(set2+j)==*(set1+k))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            *setU=*(set2+j);
            setU++;
            count++;
        }
    }
    return count;
}
int intersectionF(int *setI, int *set1, int size1, int *set2, int size2)
{
    int count=0;
    for(int j=0; j<size2; j++)
    {
        for(int k=0; k<size1; k++)
        {
            if(*(set2+j)==*(set1+k))
            {
                *setI=*(set2+j);
                setI++;
                count++;             
            }
        }       
    }
    return count;
}
int difference(int *diff, int*set1, int size1, int*set2, int size2)
{
    int count=0;
    for(int j=0; j<size1; j++)
    {
        int flag=0;
        for(int k=0; k<size2; k++)
        {
            if(*(set1+j)==*(set2+k))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            *diff=*(set1+j);
            diff++;
            count++;
        }
    }
    return count;
}
