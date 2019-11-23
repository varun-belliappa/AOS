#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <time.h>

//Global array that acts as the cache
//Initially the cache has all 0's

int arr[10]; 


//Structure holds key value pairs
//Our aim is to find the key with respect to an input value

struct node{
int val1;
int val2;
int key1;
int key2;
struct node *next;
} *head;


//This function simulates searching the main memory
//This is only called when a cache miss occurs

void searchlist(int k, struct node *head)
{

	sleep(1);
	struct node *tmp = head;
	while(tmp!=NULL)
	{
		//If both val1 and val2 of a node does not match with input value(k), traverse to the next node
		if(((tmp->val1)!=k)&&((tmp->val2)!=k))
		{
			
			tmp = tmp->next;
			continue;
		}
		
		int u = (tmp->val1)%10;
		
		int v = (tmp->val2)%10;
		arr[u] = tmp->key1;
		arr[v] = tmp->key2;
		printf("Cache miss: Element %d and %d brought into cache",u,v);
		break;
	}
}

void display(struct node *tmp)
{
	while(tmp!=NULL)
	{
		printf("%d\t%d\n%d\t%d\n",tmp->val1,tmp->key1,tmp->val2,tmp->key2);
		tmp = tmp->next;
	}
}
	


void createlist(int n,struct node *head)
{

	struct node *tmp = head;
	char ch;
	scanf("%d",&(tmp->val1));
	scanf("%d",&(tmp->key1));
	scanf("%d",&(tmp->val2));
	scanf("%d",&(tmp->key2));
	
	while((n-1)>0)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->next = NULL;
		tmp->next = temp;
		tmp = tmp->next;
		n--;
		scanf("%d",&(temp->val1));
		scanf("%d",&(temp->key1));
		scanf("%d",&(temp->val2));
		scanf("%d",&(temp->key2));
	}
	display(head);
		
}


void find(int k,struct node *head)
{
	struct node *tmp = head;
	clock_t start,end;
    double cpu_time_used;
    
    start = clock();
    int j = k%10;
    if ((arr[j]!=0))
    		{
    			printf("Cache hit, value is %d",arr[j]);
    			
    			end = clock();
    			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    			printf(" and time to access is %.5f\n",(cpu_time_used*100000));
    			return;
    		}
    	
    	searchlist(k,head);
    	end = clock();
    	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    	printf(" :Time taken is %.5f\n",(cpu_time_used*100000));
    	
}
    
    
    
    
   




void main()
{

	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	for(int i = 0;i<10;i++)
	arr[i] = 0;
	int n,k,a[20];
	printf("Initial Cache values are\n");
		for(int i = 0;i<10;i++)
		printf("%d\t",arr[i]);
		printf("\n");
	printf("\nEnter the number of key value pairs\n");
	scanf("%d",&n);
	printf("Enter key value pairs (one pair in each line) seperated by space\n");
	createlist(n,head);

	while(1)
	{
		printf("\n\nEnter value to access,Enter 999 to exit\n");
		scanf("%d",&k);
		if(k==999)
		break;
		find(k,head);
		printf("\n\nPresent entries in cache\n");
		for(int i = 0;i<10;i++)
		printf("%d\t",arr[i]);
	}
	printf("\n");

		
}
