/*PHARMA STORE MANAGEMENT AND BILLING SYSTEM*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
void closing_program();//
void user();//----------------------------------------------------------Parent function of reg_for_login() and user_pass_checker();-----------------------------------------------
void reg_for_login();//
void user_pass_checker();//
void main_menu();//
void med_input();//-------------------------------------------------------ADDING MEDICINE TO THE STALK------------------------------------------------------------------
void view_and_sell_menu();//
void view_med();//
void view_med_1();//
void med_remove();//
void search_medicine();//
void read_me();//-----------------------------------------------------Parent Function of instruction ----------------------------------------------------------------------
void instruction_op1();//
void instruction_op2();//
void instruction_op3();//
void sell_1();//
void sell_main();//-------------------------------------------------------Parent Function of Purchase----------------------------------------------------------------------------
void bill_h_view();//
//*********************************************************************************for declare STRUCTURE*********************************
typedef struct
{
    char fname[20];
    char lname[20];
    char username[20];
    char password[20];
} iden_ty/*login*/;
FILE *file3;

typedef struct
{
    int d;
    int m;
    int y;
} date;
typedef struct
{
    int quan;
    char med_name[100];
    int m_id;
    int u_c;//unit cost
    date MFG;
    date EXP;
} medicine;
FILE * file1,*file2,*file4,*file5;
//---------------------------------------------------------------------------------------------------------STRUCTURE------------------------------------
int main(void) //--------------------------------------------------------------------------------------------------------------------------/*Main function*/---------------------------------
{
    int a;

    system("COLOR F9");

    user();//user input (void user() as input)

    main_menu();//for option

    printf("\n");

}
void closing_program()//------------------------------------------------------------FOR Closing the program
{
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("!!!!!!!!!!!Have a Nice Day!!!!!!!!!\n");
    sleep(1);
    system("cls");

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Closing program_");

    sleep(1);
    exit(closing_program);
}
void user()//-------------------------------------------------------------------------------------------------------------------------------------USER ID AND LOGIN INFO------------------------------------------------
{
    int a;
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Press (1) to login : \n");
    printf("Press (2) to create account or change username and password : \n");

    while(1)
    {
        scanf("%d",&a);
        if(a==1)
        {
            user_pass_checker();
            break;
        }
        else if(a==2)
        {
            reg_for_login();
            break;
        }
        else
        {
            printf("Kindly choose 1 or 2\n");
        }
    }
}
void reg_for_login()//---------------------------------------------------------------------------void registe()----------------------------
{
    int a;

    FILE *file3;
    file3=fopen("userlogin.txt","w+");

    iden_ty l;

    system("cls");

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("To create or change username and password : \n");
    printf("Enter First name : \n");
    scanf(" %[^\n]",l.fname);

    printf("Enter Last name : \n");
    scanf(" %[^\n]",l.lname);

    printf("Enter Username : \n");
    scanf(" %[^\n]",l.username);

    printf("Enter Password : \n");
    scanf(" %[^\n]",l.password);

    fprintf(file3,"%s %s %s %s\n",l.username,l.password,l.fname,l.lname);

    fclose(file3);

    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("!!! ACCOUNT CREATED !!!\n");
    printf("\n!!! Registration Complete !!!\n");
    printf("!!! Welcome to NSU Pharmacy !!!\n");

    printf("\n\n\n Press any digit to continue_");
    scanf("%d",&a);//***************optional

    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Redirecting You to Account login : ");
    sleep(1);

    system("cls");
    user();
}
void user_pass_checker()//-------------------------------------------------------------------------checking username and password------------------------------
{
    int a,b,i;
    char username[20];
    char password[20];

    file3=fopen("userlogin.txt","r");
    iden_ty l;

    system("cls");

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");

    if(file3==NULL)
    {
        system("cls");

        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("NO ACCOUNT AVAILABLE\n");
        printf("Please Create Account First:\n");
        printf("\n\n\n\nPress any digit to continue _");
        scanf("%d",&a);

        system("cls");

        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("Redirection You to Register for Creating New ID\n");
        sleep(1);

        reg_for_login();
    }

    for(i=0; ; i++)
    {
        printf("\nEnter User Name :_ ");
        scanf(" %[^\n]",username);

        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("\nEnter Password:_ ");
        scanf(" %[^\n]",password);

        system("cls");

        fscanf(file3," %s%s%s%s",l.username,l.password,l.fname,l.lname);

        if(strcmp(l.username,username)==0 && strcmp(l.password,password)==0)
        {
            printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
            printf("!!!!!Access Granted!!!!!");
            sleep(1);

            system("cls");
            printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
            printf("\nRedirecting you to the program_");
            sleep(1);

            main_menu();
            break;
        }
        else
            system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("Recheck Your ID");
    }
    fclose(file3);
}
void main_menu()//---------------------------------------------------------------------------------------MAIN OPTION-------------------------------------------------
{
    system("cls");//old screen gone
    int c,b;
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Choose a option you want to access\n\n");
    printf("(1)Add Medicine to the stock \n");
    printf("(2)View Medicine and Sell \n");
    printf("(3)Remove medicine from stock \n");
    printf("(4)View Sell History \n");
    printf("(5)READ ME \n");
    printf("(6)Exit the program\n\n");

    while(1)
    {
        printf("Enter Choice:  \n");
        scanf("%d",&c);
        if(c==1)
        {
            med_input();

        }
        else if(c==2)
        {
            view_and_sell_menu();

        }
        else if(c==3)
        {
            system("cls");
            med_remove();

        }
        else if(c==4)
        {
            bill_h_view();

        }
        else if(c==5)
        {
            read_me();

        }
        else if(c==6)
        {
            closing_program();
        }
        else
        {
            printf("Please choose between 1-6\n");
        }
    }
}
void med_input()//*************************************************************************************OPTION 1***********ADD MEDICINE
{
    system("cls");
    FILE * file1;
    file1 = fopen("medicinelogs.txt","a+");
    int med;
    char text[10000];
    medicine M[med];
    int quan,i;

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    med=1;//Take user input for multiple medicine entry
    for(i=0; i<med; i++)
    {
        //***
        printf("Medicine Name input format :**********\n\n");
        printf("%d)Enter Medicine Name: \n",i+1);
        scanf(" %[^\n]",M[i].med_name);

        printf("Enter Medicine ID(4 Digit) : \n");
        scanf(" %d",&M[i].m_id);

        printf("Enter Unit Cost : \n");
        scanf(" %d",&M[i].u_c);

        printf("Enter MFG DD/MM/YY :\n");
        scanf(" %d%d%d",&M[i].MFG.d,&M[i].MFG.m,&M[i].MFG.y);//mfg

        printf("Enter EXP DD/MM/YY :\n");
        scanf(" %d%d%d",&M[i].EXP.d,&M[i].EXP.m,&M[i].EXP.y);//exp

        printf("Enter Medicine Quantity for adding to list: \n");
        scanf(" %d",&M[i].quan);
    }

    for(i=0; i<med; i++)
    {
        fprintf(file1,"%10s%4d\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[i].med_name,M[i].m_id,M[i].MFG.d,M[i].MFG.m,M[i].MFG.y,M[i].EXP.d,M[i].EXP.m,M[i].EXP.y,M[i].u_c,M[i].quan);
    }
    fclose(file1);

    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Medicine Added to the stock\n");

    sleep(1);
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Redirecting you to Main Menu\n");

    sleep(1);
    main_menu();

}
void view_and_sell_menu()//---------------------------------------------------------VIEW DONE------------------------VIEW AND PURCHASE MEDICINE---------------------------------------
{
    system("cls");

    int c1;
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Press (1) to view medicine : \n");
    printf("Press (2) to search for specific medicine : \n");
    printf("Press (3) to Sell medicine : \n");
    printf("Press (4) to go back to OPTIONS\n");
    while(1)
    {
        printf("Choice: \n");
        scanf("%d",&c1);
        if(c1==1)
        {
            view_med();
        }
        else if(c1==2)
        {
            search_medicine();
        }
        else if(c1==3)
        {
            sell_main();//--------------------------------------------------------------------------------------------------------------
            system("cls");
            main_menu();
        }
        else if(c1==4)
        {
            main_menu();
        }
        else
        {
            printf("Choice must be between 1-4");
        }
    }
}

void view_med()//option 2 choice 1-------------------------------------------------------------------------------------------VIEW MEDICINE LOG-----------------------------------------
{
    int x;
    view_med_1();
    printf("\n\n\n\nPress any digit to continue_");
    scanf("%d",&x);
    sleep(1);
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Redirecting you to View Medicine and Sell menu_");
    sleep(1);
    view_and_sell_menu();
}
void view_med_1()//--------------------------------------------------------------------------------------view medicine --------------------------------------------------
{
    int q,i,x;

    char text[1000];
    FILE * file1=fopen("medicinelogs.txt","r");

    system("cls");
    if (file1==NULL)
    {
        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("\nPlease Add medicine first\n\n\n\n");
        printf("Press any digit to continue_");
        scanf(" %d",&q);
        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("Redirecting you to Add Medicine Menu");
        sleep(1);
        med_input();
    }
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("S/N    MEDICINE                    MFG              EXP        UNITCOST   QUANTITY");
    printf("\n     NAME AND ID                 DD/MM/YY        DD/MM/YY       IN TK             \n\n");

    for(i=0; ; i++)
    {
        fscanf(file1," %[^\n]",text);
        if(feof(file1))
        {
            break;
        }
        printf("(%d) %s\n\n",i+1,text);
    }
    fclose(file1);
}
void med_remove()//option 3---------------------------------------------------------------------------------------------------REMOVE MED FROM THE LOG
{
    FILE *file1,*file2;
    char med_named_d[50];
    int a;

    file1=fopen("medicinelogs.txt","r");
    file2=fopen("medicinelogs1.txt","w");
    view_med_1();
    printf("Enter the MEDICINE NAME AND ID you want to Remove : \n\n");
    scanf(" %[^\n]", med_named_d);

    medicine M[34];

    int i,j;

    for(j = 0; ; j++)
    {
        fscanf(file1," %s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[j].med_name,&M[j].MFG.d,&M[j].MFG.m,&M[j].MFG.y,&M[j].EXP.d,&M[j].EXP.m,&M[j].EXP.y,&M[j].u_c,&M[j].quan);
        if(feof(file1))
            break;
    }
    for(i=0; i<=j; i++)
    {
        if(strcmp(M[i].med_name,med_named_d)!=0)
        {
            //--------------------------------------------------------------------------------------
            fprintf(file2,"%14s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[i].med_name,M[i].MFG.d,M[i].MFG.m,M[i].MFG.y,M[i].EXP.d,M[i].EXP.m,M[i].EXP.y,M[i].u_c,M[i].quan);
        }
        else
        {
            printf("\nMedicine Removed Successfully!\n");
        }
    }

    fclose(file1);
    fclose(file2);

    remove("medicinelogs.txt");
    rename("medicinelogs1.txt","medicinelogs.txt");

    system("cls");

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("\n!!!!Delete Successful!!!!\n\n\n ");
    printf("Want to delete more medicine?: \n");
    printf("Press 1 to delete more \n");
    printf("Press 2 to go back to Main Menu \n");

    scanf("%d",&a);

    switch(a)
    {
    case(1):
        med_remove();
    case(2):
        main_menu();
    }
}
void search_medicine()//----------------------------------------------------------------------------------------For medicine search---------------------------------------------
{
    FILE *file1,*file2;
    char med_named_d[50];
    file1=fopen("medicinelogs.txt","r");
    int q;
    if (file1==NULL)
    {
        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("\nPlease Add medicine first before you search\n\n\n\n");
        printf("Press any digit to continue_");
        scanf(" %d",&q);
        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("Redirecting you to Add Medicine Menu");
        sleep(1);
        med_input();
    }
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    view_med_1();
    printf("Medicine name must be in this format **********xxxx\n");
    printf("'*'character of Medicine Name and 'X'ID of Medicine\n");
    printf("Enter the MEDICINE NAME AND ID SEARCH: \n\n");
    scanf(" %[^\n]",med_named_d);

    medicine M[34];
    int x,i,j;

    for(j = 0; ; j++)
    {
        fscanf(file1," %s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[j].med_name,&M[j].MFG.d,&M[j].MFG.m,&M[j].MFG.y,&M[j].EXP.d,&M[j].EXP.m,&M[j].EXP.y,&M[j].u_c,&M[j].quan);
        if(feof(file1))
            break;
    }
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Here is your medicine which you searched for :\n\n");
    printf("    MEDICINE               MFG              EXP        UNITCOST   QUANTITY\n");
    printf("   NAME AND ID           DD/MM/YY        DD/MM/YY       IN TK             \n\n");

    for(i=0; i<=j; i++)
    {
        if(strcmp(M[i].med_name,med_named_d)==0)
        {
            printf(" %14s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[i].med_name,M[i].MFG.d,M[i].MFG.m,M[i].MFG.y,M[i].EXP.d,M[i].EXP.m,M[i].EXP.y,M[i].u_c,M[i].quan);
        }
    }

    fclose(file1);
    printf("\n\nPress any digit to continue");
    scanf("%d",&x);
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Redirecting you to View Medicine and Purchase Menu_");
    sleep(1);
    system("cls");
    view_and_sell_menu();
}
void read_me()//--------------------------------------------------------------------------------------Mother Branch for Instruction --------------------------------------------------
{
    int c;
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Press (1) to see instructions for ADDING MEDICINE TO STOCK\n");
    printf("Press (2) to see instructions for VIEW MEDICINE and PURCHASE\n");
    printf("Press (3) to see instructions for DELETING MEDICINE FROM STOCK\n");
    printf("Press (4) to go back to OPTION MENU\n");

    scanf("%d",&c);

    while(1)
    {

        if(c==1)//***************************************************FOR ADDING MED INSTRUCTION***********************************
        {

            instruction_op1();
        }
        else if(c==2)//*************************************************FOR VIEW AND PURCHASE INSTRUCTION**************************
        {
            instruction_op2();
        }
        else if(c==3)//**************************************************FOR DELETING MEDICINE FROM THE STOCK******************************
        {
            instruction_op3();
        }
        else if(c==4)
        {
            main_menu();//**********************************************************************************************************************************        {

        }
        else
        {

            system("cls");
            read_me();
            printf("!!!PLEASE PRESS NUMBER BETWEEN 1-5 !!!");
        }
    }
}
void instruction_op1()//-------------------------------------------------------------------------------------Instruction for option 1--------------------------------------------
{
    int n;

    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("===============================================\n");
    printf("||------FOR ADDING MEDICINE TO STOCK---------||\n");
    printf("||----Name input must be 10 character--------||\n");
    printf("||----If name is less then 10 character------||\n");
    printf("||----EXAMPLE : If Name is 'NAPA' then-------||\n");
    printf("||----------Then input should be-------------||\n");
    printf("||---------------******NAPA------------------||\n");
    printf("||---------------NOT:NAPA--------------------||\n");
    printf("||-------ADD '*'BEFORE MEDICINE NAME---------||\n");
    printf("||--UNTIL IT FORM 10 LETTER CHARACTER NAME---||\n");
    printf("||--------TO MAKE IT 10 CHARACTER------------||\n");
    printf("||--ID for medicine must be 4 digit number---||\n");
    printf("||--No Zeros should be first digit input-----||\n");
    printf("||------EXAMPLE : 1001,2000,1111,9999--------||\n");
    printf("||--NO ID input like this= 0101,0011,0001----||\n");
    printf("||--------------------EXP--------------------||\n");
    printf("||--EXP first input is DAYs can be 2digit----||\n");
    printf("||--EXP second input is MONTHS can be 2digit-||\n");
    printf("||--EXP third input is YEARS can be 2digit---||\n");
    printf("||--------------------MFG--------------------||\n");
    printf("||--MFG first input is DAYs can be 2digit----||\n");
    printf("||--MFG second input is MONTHS can be 2digit-||\n");
    printf("||--MFG third input is YEARS can be 2digit---||\n");
    printf("||--UNIT COST AND QUANTITY BOTH 4digit input-||\n");
    printf("===============================================\n");
    printf("To continue press any number: \n\n\n");

    scanf(" %d",&n);

    read_me();
}
void instruction_op2()//-------------------------------------------------------------------------------------Instruction for option 2--------------------------------------------
{
    int n;

    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("--------------------------------------------------------\n");
    printf("||GO TO OPTION MENU==>Press '2' ==> VIEW MEDICINE LIST||\n");
    printf("--------------------------------------------------------\n");
    printf("\n\n\nTo continue press any number: ");

    scanf("%d",&n);

    read_me();

}
void instruction_op3()//-------------------------------------------------------------------------------------Instruction for option 3--------------------------------------------
{
    int m;
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("=====================================================\n");
    printf("||-------FOR DELETING MEDICINE FROM THE STOCK------||\n");
    printf("||------INPUT NAME AND ID SHOULD BE TOGETHER-------||\n");
    printf("||--10LETTER CHARACTER FOR NAME AND 4DIGIT FOR ID--||\n");
    printf("||--A TOTAL OF 14 CHARACTER INPUT SHOULD BE GIVEN--||\n");
    printf("||--------IF THE MEDICINE NAME IS 'ROXICODONE'-----||\n");
    printf("||------------AND MEDICINE ID IS : 2002------------||\n");
    printf("||---INPUT SHOULD BE FOR DELETE : ROXICODONE2002---||\n");
    printf("||-----FOR LESS TAHN 10 CHARACTER LETTER NAME------||\n");
    printf("||---------------FOR EXAMPLE : 'NAPA'--------------||\n");
    printf("||-------------AND MEDICINE ID IS 2299-------------||\n");
    printf("||-------------INPUT SHOULD BE GIVEN AS------------||\n");
    printf("||------------------******NAPA2299-----------------||\n");
    printf("||-----------ADD '*'BEFORE MEDICINE NAME-----------||\n");
    printf("||------UNTIL IT FORM 10 LETTER CHARACTER NAME-----||\n");
    printf("=====================================================\n");
    printf("To continue press any number: \n\n\n");

    scanf("%d",&m);

    read_me();
}
void sell_main()//
{
    system("cls");
    sell_1();
}
void sell_1()//--------------------------------------------------------------------------------------------------------
{
    FILE *file1,*file2,*file4;
    char med_named_d[50];
    int a;
    file1=fopen("medicinelogs.txt","r");
    file2=fopen("medicinelogs1.txt","w");
    view_med_1();
    printf("Enter the MEDICINE NAME AND ID you want to Sell : \n\n");
    scanf(" %[^\n]", med_named_d);

    printf("Enter number of quantity you want to sell\n");
    int x,i,j,w;
    int index=0;
    medicine M[34];
    scanf(" %d",&a);

    for(j = 0; ; j++)
    {
        fscanf(file1," %14s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[j].med_name,&M[j].MFG.d,&M[j].MFG.m,&M[j].MFG.y,&M[j].EXP.d,&M[j].EXP.m,&M[j].EXP.y,&M[j].u_c,&M[j].quan);
        if(feof(file1))
            break;
    }
    for(i=0; i<=j; i++)
    {
        if(strcmp(M[i].med_name,med_named_d)==0)
        {
            M[i].quan -= a;
            fprintf(file2,"%14s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[i].med_name,M[i].MFG.d,M[i].MFG.m,M[i].MFG.y,M[i].EXP.d,M[i].EXP.m,M[i].EXP.y,M[i].u_c,M[i].quan);
            index=i;
        }
        else
        {
            fprintf(file2,"%14s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d\n",M[i].med_name,M[i].MFG.d,M[i].MFG.m,M[i].MFG.y,M[i].EXP.d,M[i].EXP.m,M[i].EXP.y,M[i].u_c,M[i].quan);
        }
    }

    fclose(file1);
    fclose(file2);

    remove("medicinelogs.txt");
    rename("medicinelogs1.txt","medicinelogs.txt");

    file4=fopen("bill_history.txt","a+");

    fprintf(file4,"%14s\t\t %2d %2d %2d\t %2d %2d %2d\t %4d \t  %4d              %8d\n",M[index].med_name,M[index].MFG.d,M[index].MFG.m,M[index].MFG.y,M[index].EXP.d,M[index].EXP.m,M[index].EXP.y,M[index].u_c,a,a*M[index].u_c);
    fclose(file4);

    system("cls");

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("\n!!!!!SOLD!!!!!!\n");
    printf("Press any digit to continue_\n");
    scanf("%d",&w);

    system("cls");

    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("Redirecting You to Main menu");
    sleep(1);

    main_menu();


}
void bill_h_view()
{
    int q,i,x;
    char text[1000];
    FILE * file4=fopen("bill_history.txt","r");

    system("cls");
    if (file4==NULL)
    {
        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("\n!!There is No Sell Done YET!!\n\n\n\n");
        printf("Press any digit to continue_");
        scanf(" %d",&q);

        system("cls");
        printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
        printf("Redirecting you to Main Menu ");

        sleep(1);

        main_menu();
    }
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("S/N    MEDICINE                    MFG              EXP        UNITCOST   TOTAL QUANTITY    TOTAL COST OF SOLD      \n");
    printf("    NAME AND ID                  DD/MM/YY        DD/MM/YY       IN TK     SOLD              MEDICINE IN TK \n\n");

    for(i=0; ; i++)
    {
        fscanf(file4," %[^\n]",text);
        if(feof(file4))
        {
            break;
        }
        printf("(%d) %s\n\n",i+1,text);
    }
    fclose(file4);
    printf("\nPress any digit to continue _");
    scanf("%d",&x);
    system("cls");
    printf("\t\t\t\t---------------------------------------------------\n\t\t\t\t||                                               ||\n\t\t\t\t||                NSU PHARMACY                   ||\n\t\t\t\t||                                               ||\n\t\t\t\t---------------------------------------------------\n\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n");
    printf("\nRedirecting YOU to Main menu_");
    sleep(1);
    main_menu();
}
