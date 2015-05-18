/*This program converts a file from .txt to binary
which contains matches from a league it will then
display the results of the match in a league table.
The user can enter then new results or teams,
the user can then see the matches with the highest 
amount of goals scored and finally search for a certain 
team, all of their matches will be displayed then
Author:Eoin Irwin
Date:06/05/2014
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct teams
{
    char team_1[20];
    char team_2[20];
    int goal_1;
    int goal_2;
};

struct single
{
    int points;
    int goals_for;
    int goals_against;
    
};

struct single match[10]; // 
struct teams results; //To read the results into the structure
    
//Declare prototypes
//

void convert();
void show_table();
void insert_team();
void highest_goals();
void all_matches();
void exit();
    
/*
* Displays the menu and gives the option to

* call each of the 6 functions

* Parameters: Can call 6 functions

*Return: Void
*/

main()
{
    int choice = 0;
    
    //do while loop to keep the menu displaying constantly
    do
    {
        flushall();
        printf("\n\n\n(1)Convert to .bin ");
        printf("\n(2)Show results table ");
        printf("\n(3)Insert new results ");
        printf("\n(4)Matches with highest goals ");
        printf("\n(5)Display a teams results");
        printf("\n(0)Exit \n");
        printf("\nOption (1-5): ");
        scanf("\n%d",&choice);
        clrscr();
        
    
        switch(choice)
        {
            case 1:
            {
                convert();
                break;
                
            }
            
            case 2:
            {
                show_table();
                break;
                
            }
            
            
            case 3:
            {
                insert_team();
                break;
                
            }
            
            
            case 4:
            {
                highest_goals();
                break;
                
            }
            
            
            case 5:
            {
                all_matches();
                break;
                
            }
            
            case 0:
            {
                exit();
                break;
            }
            
            default: //If user doesn't enter a number between 1 and 5 they get an error message
            {
                printf("Please choose a number between (1-5)");
                break;
                
            } // end default
            
        } // end switch
        
    }while(choice!=0); // end while
    
} // end main()

/*

* Converts a .txt file into a .bin

* file and stores the results of it

* Parameters: Convert .txt to .bin

*Return: Void

*/

void convert()
{
    FILE * filer; //File pointer to read .txt
    FILE * filew; //File pointer to write from .txt to .bin
    
    filer = fopen("matches.txt", "r");   //Opens the .txt file, in reading mode.
    filew = fopen("matches.bin", "w+b"); //Write plus binary
    
    if(filer == NULL)
    {
        fprintf(stderr,"Error in opening matches.txt.\n\n"); //If the user open the .txt file they get an error
    }
    
    if(filew == NULL)
    {
        
        fprintf(stderr,"Error in opening matches.bin.\n\n"); //If the user cannot open write to binary file 
        
        
    } // end if 
    
    else
    {
        
        printf(".txt converted to .bin file\n\n"); //Otherwise this tells you the .txt converted
        
        
    } // end else
    
    
    while(fscanf(filer, " %[^,] , %[^,] , %i , %i ", results.team_1, results.team_2 , &results.goal_1, &results.goal_2)!=EOF) //Scans through the whole file
    {
        fwrite(&results,sizeof(results),1,filew); //Write to the file so it converts into binary
        
    } // end while
    
    fclose(filer); //Close the read file
    fclose(filew); //Close the write file
    
} // void convert()


/*

* Shows the league table and the position

* of each team in the table.

* Parameters: Show the league table

*Return: Void

*/

void show_table()
{ 
    struct teams matches[190]; //Declaring an array of structures of the 190 matches 
    FILE * filer; 
    int i, j, temp;
    
    filer = fopen("matches.bin","r+b"); //Open matches.bin in read_binary mode
    
    char *teams[10] = {"Inter Milan   ", "Chelsea       ", "Bayern Munich ",
                        "Juventus      ", "Manchester Utd", "Porto         ", "Real Madrid   ",
                        "Liverpool     ", "Barcelona     ", "PSG           " }; //A pointer to the array of teams which are displayed on the table
                        
    
    for(i=0;i<190;i++)
    {
        fread(&matches,sizeof(results),190,filer); //Read through the 190 matches of results 
        
        if(strstr(matches[i].team_1,"Inter Milan")) //If team 1 match is Inter Milan
        {
            if(matches[i].goal_1 > matches[i].goal_2) //If home team goals(Inter Milan) are greater than the away teams goals
            {
                match[0].points = match[0].points + 3; //Give Inter Milan 3 points to their total (add to the structure of points)
            }
            else if(matches[i].goal_1 == matches[i].goal_2) //But if Inter Milan get the same amount of goals as the away team
            {
                match[0].points++; //Only give Inter Milan 1 point
            }
            match[0].goals_for = match[0].goals_for + matches[i].goal_1; // The goals for part of the table is equal to goals_for + goal_1 which is equal to the goals Inter scored in that game
            match[0].goals_against = match[0].goals_against + matches[0].goal_2; // The goals against part of the table is equal to goals_against + goal_2 which is equal to the goals away team scored in that game
        }
        if(strstr(matches[i].team_2,"Inter Milan")) //If Inter is the away team 
        {
            if(matches[i].goal_2 > matches[i].goal_1) //If the away team (Inter Milan) scores more than the home team
            {
                match[0].points = match[0].points + 3; //Inter Milan get 3 points
            }
            else if(matches[i].goal_1 == matches[i].goal_2) //If the home team draws with the away team (Inter Milan)
            {
                match[0].points++; //Inter Milan get 1 point
            }
            match[0].goals_for = match[0].goals_for + matches[i].goal_2; // The goals for part of the table is equal to goals_for + goal_2 which is equal to the goals Inter scored in that game
            match[0].goals_against = match[0].goals_against + matches[0].goal_1; // The goals for part of the table is equal to goals_against  + goal_2 which is equal to the goals Inter scored in that game
        }
        
        /*Please see above comments for the rest
                of the teams*/
        
        if(strstr(matches[i].team_1,"Real Madrid"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[1].points = match[1].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[1].points++;
            }
            match[1].goals_for = match[1].goals_for + matches[i].goal_1;
            match[1].goals_against = match[1].goals_against + matches[1].goal_2;
        }
        if(strstr(matches[i].team_2,"Real Madrid"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[1].points = match[1].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[1].points++;
            }
            match[1].goals_for = match[1].goals_for + matches[i].goal_2;
            match[1].goals_against = match[1].goals_against + matches[1].goal_1;
        }
        
        if(strstr(matches[i].team_1,"Juventus"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[2].points = match[2].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[2].points++;
            }
            match[2].goals_for = match[2].goals_for + matches[i].goal_1;
            match[2].goals_against = match[2].goals_against + matches[2].goal_2;
        }
        if(strstr(matches[i].team_2,"Juventus"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[2].points = match[2].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[2].points++;
            }
            match[2].goals_for = match[2].goals_for + matches[i].goal_2;
            match[2].goals_against = match[2].goals_against + matches[2].goal_1;
        }
        
        if(strstr(matches[i].team_1,"Barcelona"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[3].points = match[3].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[3].points++;
            }
            match[3].goals_for = match[3].goals_for + matches[i].goal_1;
            match[3].goals_against = match[3].goals_against + matches[3].goal_2;
        }
        if(strstr(matches[i].team_2,"Barcelona"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[3].points = match[3].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[3].points++;
            }
            match[3].goals_for = match[3].goals_for + matches[i].goal_2;
            match[3].goals_against = match[3].goals_against + matches[3].goal_1;
        }
        
        if(strstr(matches[i].team_1,"Chelsea"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[4].points = match[4].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[4].points++;
            }
            match[4].goals_for = match[4].goals_for + matches[i].goal_1;
            match[4].goals_against = match[4].goals_against + matches[4].goal_2;
        }
        if(strstr(matches[i].team_2,"Chelsea"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[4].points = match[4].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[4].points++;
            }
            match[4].goals_for = match[4].goals_for + matches[i].goal_2;
            match[4].goals_against = match[4].goals_against + matches[4].goal_1;
        }
        
        
        if(strstr(matches[i].team_1,"Bayern Munich"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[5].points = match[5].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[5].points++;
            }
            match[5].goals_for = match[5].goals_for + matches[i].goal_1;
            match[5].goals_against = match[5].goals_against + matches[5].goal_2;
        }
        if(strstr(matches[i].team_2,"Bayern Munich"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[5].points = match[5].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[5].points++;
            }
            match[5].goals_for = match[5].goals_for + matches[i].goal_2;
            match[5].goals_against = match[5].goals_against + matches[5].goal_1;
        }
        
        
        if(strstr(matches[i].team_1,"PSG"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[6].points = match[6].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[6].points++;
            }
            match[6].goals_for = match[6].goals_for + matches[i].goal_1;
            match[6].goals_against = match[6].goals_against + matches[6].goal_2;
        }
        if(strstr(matches[i].team_2,"PSG"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[6].points = match[6].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[6].points++;
            }
            match[6].goals_for = match[6].goals_for + matches[i].goal_2;
            match[6].goals_against = match[6].goals_against + matches[6].goal_1;
        }
        }
        
        
        if(strstr(matches[i].team_1,"Liverpool"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[7].points = match[7].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[7].points++;
            }
            match[7].goals_for = match[7].goals_for + matches[i].goal_1;
            match[7].goals_against = match[7].goals_against + matches[7].goal_2;
        }
        if(strstr(matches[i].team_2,"Liverpool"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[7].points = match[7].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[7].points++;
            }
            match[7].goals_for = match[7].goals_for + matches[i].goal_2;
            match[7].goals_against = match[7].goals_against + matches[7].goal_1;
        }
        
        
        if(strstr(matches[i].team_1,"Porto"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[8].points = match[8].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[8].points++;
            }
            match[8].goals_for = match[8].goals_for + matches[i].goal_1;
            match[8].goals_against = match[8].goals_against + matches[8].goal_2;
        }
        if(strstr(matches[i].team_2,"Porto"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[8].points = match[8].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[8].points++;
            }
            match[8].goals_for = match[8].goals_for + matches[i].goal_2;
            match[8].goals_against = match[8].goals_against + matches[8].goal_1;
        }
        
        
        if(strstr(matches[i].team_1,"Manchester Utd"))
        {
            if(matches[i].goal_1 > matches[i].goal_2)
            {
                match[9].points = match[9].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[9].points++;
            }
            match[9].goals_for = match[9].goals_for + matches[i].goal_1;
            match[9].goals_against = match[9].goals_against + matches[9].goal_2;
        }
        
        if(strstr(matches[i].team_2,"Manchester Utd"))
        {
            if(matches[i].goal_2 > matches[i].goal_1)
            {
                match[9].points = match[9].points + 3;
            }
            else if(matches[i].goal_1 == matches[i].goal_2)
            {
                match[9].points++;
            }
            match[9].goals_for = match[9].goals_for + matches[i].goal_2;
            match[9].goals_against = match[9].goals_against + matches[9].goal_1;
        }
        
        for (j = 10 ; j > 1; j--)     // pass number (last index of array to sort)
        {
            
        for (i = 0; i < 10; i++) //For loop for the 10 matches
        {
           if(match[i-1].points < match[i].points) 
            {
                temp       = match[i].points; //Bubble sort to sort the table above
                match[i].points   = match[i-1].points;
                match[i-1].points = temp; //The struct is stored in the temporary variable

            } // end if
         
        } // end inner for
      
    } //end outer for
        
        printf("\t\t\t       LEAGUE TABLE\n ");
        printf("\n");
        printf("Name\t\t\tPoints\t\tGoals For\tGoals Against\n");
    
        for(int i=0; i<10; i++) //For loop to display all of the teams, points, goals for and goals against
        {
            printf("\n%d.%s",i+1,teams[i]);
            printf("  \t%d",match[i].points);
            printf("  \t\t%d",match[i].goals_for);
            printf("  \t\t%d",match[i].goals_against);
        }
        
        fclose(filer); //Close file
    
}//end void show_table()

/*

*Inserting tothe .bin a new result for team A and team B

* with Goal A and Goal B also being inserted

* Parameters: Insert new teams

*Return: Void

*/


void insert_team()
{
    FILE * filer;
    FILE * filew;
    
    filer=fopen("matches.bin","r+b"); // Read binary file
    filew=fopen("matches.bin","a+b"); //Append the binary file
    printf("Please enter a new result:\n");
    flushall(); //clears the buffer memory 

    printf("Team A: ");
    gets(results.team_1); //Insert a new Team A

    printf("Team B: ");
    gets(results.team_2);

    printf("Goal A: ");
    scanf("%d",&results.goal_1); //Insert a Goal A

    printf("Goal B: ");
    scanf("%d",&results.goal_2);
    
    fseek(filer , 0 , SEEK_END);//Go to end the end of fwrite and write the match out to binary
    fwrite(&results,sizeof(results),1,filew);
    fclose(filew);
    fclose(filer);
    
} //end void insert_team()

/*

* Display the matches with the

* highest number of goals scored

* Parameters: Display highest goals

*Return: Void

*/


void highest_goals()
{
    FILE * filer;
    filer=fopen("matches.bin","r+b"); //Open matches.bin to read in binary
    
    for(int i = 0 ; i < 180 ; i++)
    {
       fread(&results,sizeof(results),1,filer); //Read all of the 180 games
        
       if(results.goal_1 + results.goal_2>=7) //If the results are greater than or equal to 7 print them out
        {
            printf("%s,%s,%i,%i\n", results.team_1, results.team_2 , results.goal_1, results.goal_2);
            
        }
        
    } // end for
    
    fclose(filer);
    
} // end void highest_goals()


/*

*Display all of the fixtures of

*one team entered by the user

* Parameters: Display a teams matches

*Return: Void

*/


void all_matches()
{
    FILE * filer;
    char name[20];
   
   printf("Please put capitals in for first letter of team"); //You are required to enter a capital first letter e.g Real madrid instead of real madrid  
   printf("\n\nEnter a team to display their matches: ");
   scanf("\n%s",name);
   clrscr();
    
   filer = fopen("matches.bin", "r+b");

   for(int i = 0 ; i < 90 ; i++)
   {
        fread(&results,sizeof(results),1,filer);  //read in all of the matches
       
        if(strstr(results.team_1,name)) //If the home team name is entered display all of their home matches e.g Inter Milan home matches
        {
            
            printf("%s,%s,%d,%d\n",results.team_1,results.team_2,results.goal_1,results.goal_2);
            
        }
        else if(strstr(results.team_2,name)) //If the away team name is entered display all of their away matches e.g Inter Milan away matches
        {
            
            printf("%s,%s,%d,%d\n",results.team_1,results.team_2,results.goal_1,results.goal_2);
            
        }
    
    } // end while */
    
    fclose(filer);
    
} // end void all_matches()

/*

*Exits the program, else it will

*return to the main menu 

* Parameters: Exit the program

*Return: Void

*/

void exit()
{
    char yesno;
    printf("\nWould you like to exit? Y/N: ");
    scanf("%1s",&yesno);

    //The user has the option to enter 
    if(yesno=='Y' || yesno=='y')
    {
        printf("\n\nGoodbye, thanks for viewing the table");
        Sleep(1200); //Display this 
    }
  
} // end void exit()