#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct songs
{
	char *name;
	int duration;
	char *genre;
};

struct song
{
	char *name;
	char *singername;
	int proyear;
	char *procompany;
	struct songs *songs1;
};


void create(struct song *album);
void display(struct song *album);
void modify(struct song *album);
void remove1(char *);

int main()
{
	char name[50];
	char choice;
	do
	{
		struct song album1;
		fflush(stdin);
		printf("Press (c)reate an album, (d)isplay an album ,(r)emove an album, (m)odify an album, (e)xit\n");	
		fflush(stdin);
		scanf(" %c",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 'c':
				printf("\nLet's create an album\n");
				fflush(stdin);
				create(&album1);
				fflush(stdin);
				break;
			case 'r':
				printf("\nLet's delete an album\n");
				fflush(stdin);
				printf("Enter the name of the album\n");
				scanf(" %s",name);
				remove1(name);
				printf("\nSuccessfully deleted\n");
				fflush(stdin);
				break;
			case 'd':
				display(&album1);
				break;
			case 'm':
				fflush(stdin);
				printf("Enter the name of album to be modified:\n");
				fflush(stdin);
				modify(&album1);		
				break;	  
			case 'e':
				fflush(stdin);
				printf("\nYou exitted from program\n");
				fflush(stdin);
				break;
			default :
				fflush(stdin);
				printf("\nInvalid choice!\n");
				fflush(stdin);
				break;

		}
		fflush(stdin);
	}while(choice != 'e');	
	
}
void create(struct song *album)
{		
	album->songs1 = (struct songs *)malloc(sizeof(struct songs));
			//Name
	char array[100];   // here I wrote array to get name of the album then, I calculated the length of it and allocate space for its length in struct name 
	int n,i;
	fflush(stdin);
	printf("\nEnter the name of album:");
	fflush(stdin);
	scanf(" %s",array);
	fflush(stdin);	
		n = strlen(array);      
		album->name = (char *)malloc((sizeof(char) +1)*n);
		strcpy(album->name, array);   
	
	
	
				// Singername
	printf("\nEnter the singer name of album:"); 
	fflush(stdin);   // I did all of creation parts exactly like the first part.
	scanf(" %s",array);
	fflush(stdin);
	
		n = strlen(array);
		album->singername = (char *)malloc((sizeof(char) +1)*n);
		strcpy(album->singername, array);
	

	           // Production Year
	printf("\nEnter production year:");
	
	fflush(stdin);
	scanf(" %d",&album->proyear);
	fflush(stdin);
		
	
	
			  // Production Company	
	printf("\nEnter the production company of album:");
	fflush(stdin);
	scanf(" %s",array);
	fflush(stdin);
	
		n = strlen(array);
		album->procompany = (char *)malloc((sizeof(char) +1)*n);
		strcpy(album->procompany, array);
		fflush(stdin);
	
	
				// Song name 
				
	printf("\nEnter the song name:");
	fflush(stdin);
	scanf(" %s",array);
	fflush(stdin);
	
		n = strlen(array);
		album->songs1->name = (char *)malloc((sizeof(char) +1)*n);
		strcpy(album->songs1->name, array);
		fflush(stdin);
		
		
			//Song duration
			
	printf("\nEnter song duration:");
	
	fflush(stdin);
	scanf(" %d",&album->songs1->duration);
	fflush(stdin);
	
	
			//Song genre
	
	printf("\nEnter the song genre:");
	fflush(stdin);
	scanf(" %s",array);
	fflush(stdin);
	
		n = strlen(array);
		album->songs1->genre = (char *)malloc((sizeof(char) +1)*n);
		strcpy(album->songs1->genre, array);
		fflush(stdin);
			
			
		//Writing struct to a file
	
	FILE * fp;
	fp = fopen("txt.txt", "a+");
	
		fprintf(fp,"%s %s %d %s %s %d %s \n",album->name, album->singername, album->proyear, album->procompany, album->songs1->name, album->songs1->duration, album->songs1->genre);

	   
	fclose(fp);
		
	

}

int line_find(char *name)
{
	FILE * fp;
	int temp;
	fp = fopen("txt.txt", "r");
	int k=0;
	int flag=0;
	char str1[256];
	char *str2;

	while(fgets(str1,256,fp)!=NULL && flag==0)
	{
		k++;
		str2 = strtok(str1," ");
		
		if(strcmp(str2,name)==0)
		{
		
			flag=1;
		}
	}
 	
	 fclose(fp);
	
	if(flag==0)return -1;
	
	return k;

}

void modify(struct song *album)
{

	char name[50];
	printf("Enter the name\n");
	scanf(" %s",name);
	int line = line_find(name);
	FILE * fp;
    fp = fopen("txt.txt", "r+");
    rewind(fp);      // it takes cursor to the beginning of the function
    
	if(line==-1)
	{
		printf("Not found\n");
	}
	
	else 
	{
		remove1(name);
		fseek(fp, 0, SEEK_END);
		printf("Enter the new Album\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc(' ',fp);
		printf("Enter the new Author\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc(' ',fp);
		printf("Enter the new date\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc(' ',fp);
		printf("Enter the new Company\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc(' ',fp);
		printf("Enter the new song\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc(' ',fp);
		printf("Enter the new duration\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc(' ',fp);
		printf("Enter the new genre\n");
		scanf(" %s",name);
		fputs(name,fp);
		fputc('\n',fp);
	}

		fclose(fp);
			
}

void remove1(char *name) 
{
	FILE * fp;
	int temp;
	fp = fopen("txt.txt", "r+");
	char arr[50];
	char a;
	int i=0;
	while((a=getc(fp))!=EOF){
	
		if(a!=' '){
			arr[i]=a;
			i++;
		}
		else {
			arr[i]='\0';
			if(!strcmp(arr,name)){
				//Trace the cursor back to the front of the line
				fseek(fp, -(i+1), SEEK_CUR);
				
				while((a=getc(fp))!='\n'){
				
					fseek(fp, -1, SEEK_CUR);
					fputc(' ',fp);
				}
		
			}
			else {
				while((a=getc(fp))!='\n'){
					
				}
			}

			i=0;
		}
	}
	
	fclose(fp); 
}

void display(struct song *album)
{
	int i, n = 8;
	
	printf("\nThe name is: ");
		for(i = 0; i < n; i++)
		{         
			printf("%c",(album->name)[i]);           
		}
		printf("\n");
	
	printf("\nThe singername is: ");
		for(i = 0; i < n; i++)
		{
			printf("%c",(album->singername)[i]);
		}
		printf("\n");
		
	printf("\n%d\n",album->proyear);
	
	printf("\nThe production company is: ");
		for(i = 0; i < 8; i++)
		{
			printf("%c",(album->procompany)[i]);
		}
	printf("\n");
}
