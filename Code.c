
// System Definition : Tours and Travel Agency Management System. By using this system the customer can view details of Holiday Packages which are provide by Agency.
//                     Customer can select his Location and Destination, on the basis of customer's selection this system shows available routes and customer can
//                     book his/her ticket.

// Developed By      : AU2040238   Jainam Shah
//                     AU2040240   Kinal Kagathara
//                     AU2040244   Aryan Bhavsar

// Note              : If you want to use this system directly then please login with username guest and password guest123.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct login
{
    char name[15];
    char passw[15];
} login[1000];

void clrscr() { system("cls"); }
int login_fun();
int getch();
int getche();

void WelcomeScreen()
{
    char k = 177;
    int i;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  %c", k);
    for (i = 1; i <= 80; i++)
    {
        printf("%c", k);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                                    %c", 196);
    for (i = 1; i <= 12; i++)
    {
        printf("%c", 196);
    }
    printf("\n                                                                                                   /             \\");
    printf("\n                                                                                                   %c", 196);
    for (i = 1; i <= 14; i++)
    {
        printf("%c", 196);
    }
    printf("\n                                                                                                 |-|      |      |-|");
    printf("\n                                                                                                 |-|      |      |-|");
    printf("\n                                                                                                   %c", 196);
    for (i = 1; i <= 14; i++)
    {
        printf("%c", 196);
    }
    printf("\n                                                                                                   |ooo       ooo|");
    printf("\n                                                                                                   %c", 196);
    for (i = 1; i <= 14; i++)
    {
        printf("%c", 196);
    }
    printf("\n                                                                                                    |_|       |_|  ");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                                  W E L C O M E  T O \n");
    printf("\n");
    printf("\n");
    printf("                                                                       T O U R S  A N D  T R A V E L  A G E N C Y  M A N A G E M E T  S Y S T E M \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                              :) Your comfort is our job!\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  %c", k);
    for (i = 1; i <= 80; i++)
    {
        printf("%c", k);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  Please press any key to continue: ");
    getch();
    system("cls"); // Use to clear screen
}

char *getPassword(char *checker)
{
    char ch1;
    printf("                                                                  ==> Password  :  ");
    int j;
    for (j = 0; j < 14; j++)
    {
        ch1 = getch();
        checker[j] = ch1;
        if (ch1 != 13)
        {
            printf("*");
        }
        if (ch1 == 13)
        {
            checker[j] = '\0';
            break;
        }
    }
    return checker;
}

void registration()
{
    system("cls");
    int i, flag = 1;
    char checker[15], k = 219;
    _flushall();
    FILE *fw;
    fw = fopen("userdatabase.txt", "a+");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  %c", k);
    for (i = 1; i < 80; i++)
    {
        printf("%c", k);
    }
    printf("\n");
    printf("\n");
    printf("                                                                  ---------------------------------- S I G N  U P --------------------------------\n");
    printf("\n");
    printf("                                                                  %c", k);
    for (i = 1; i < 80; i++)
    {
        printf("%c", k);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  Please fill below details carfully:\n");
    printf("\n");
    printf("\n");
    for (i = 0; i < 1000; i++)
    {
        printf("                                                                  ==> Username  :  ");
        scanf("%s", checker);
        _flushall();
        printf("\n");
        printf("\n");
        while (!feof(fw))
        {
            fread(&login[i], sizeof(login[i]), 1, fw);
            if (strcmp(checker, login[i].name) == 0)
            {
                printf("                                                                  Username Already Exists...");
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
        strcpy(login[i].name, checker);
        strcpy(login[i].passw, getPassword(checker));
        fwrite(&login[i], sizeof(struct login), 1, fw);
        printf("\n\n\n\n                                                                  :) You Registered Successfully...");
        break;
    }
    fclose(fw);
    getch();
}

int login_fun()
{
    FILE *fp;
    char name[15], pass[15], k = 219;
    int checku, checkp, i, flag = 0;
    fp = fopen("userdatabase.txt", "r");
    for (i = 0; i < 10000; i++)
    {
        clrscr();
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                                  %c", k);
        for (i = 1; i < 80; i++)
        {
            printf("%c", k);
        }
        printf("\n");
        printf("\n");
        printf("                                                                  ---------------------------------- S I G N  I N --------------------------------\n");
        printf("\n");
        printf("                                                                  %c", k);
        for (i = 1; i < 80; i++)
        {
            printf("%c", k);
        }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                                  ==> Username  :  ");
        _flushall();
        scanf("%s", name);
        printf("\n");
        printf("\n");
        strcpy(pass, getPassword(pass));
        while (!feof(fp))
        {
            fread(&login[i], sizeof(login[i]), 1, fp);
            checku = strcmp(name, login[i].name);
            checkp = strcmp(pass, login[i].passw);
            if (checku == 0 && checkp == 0)
            {
                flag = 1;
                break;
            }

            else if (checku != 0 || checkp != 0)
            {
                flag = 0;
            }
        }

        break;
    }
    fclose(fp);
    return flag;
}

void loop_fun()
{
    int j, choice, i;
    char k = 219;
    while (1)
    {
        clrscr();
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                                  %c", k);
        for (i = 1; i < 80; i++)
        {
            printf("%c", k);
        }
        printf("\n");
        printf("\n");
        printf("                                                                  ------------------------------- H O M E  P A G E -------------------------------\n");
        printf("\n");
        printf("                                                                  %c", k);
        for (i = 1; i < 80; i++)
        {
            printf("%c", k);
        }
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                                  Please select a kind of user:\n");
        printf("\n");
        printf("\n");
        printf("                                                                  1. New User\n");
        printf("\n");
        printf("                                                                  2. Existing User\n");
        printf("\n");
        printf("                                                                  3. Exit\n");
        printf("\n");
        printf("\n");
        printf("                                                                  Please give your choice: ");
        _flushall();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            registration();
            break;

        case 2:
            j = login_fun();
            if (j == 1)
            {
                printf("\n\n\n");
                printf("                                                                  :) You Logged In Successfully...");
                getch();
                MainMenu();
            }
            if (j == 0)
            {
                printf("\n\n\n");
                printf("                                                                  :( Username or Password is incorrect!");
                getch();
                continue;
            }
            break;
        case 3:
            ExitScreen();
            break;
        default:
            printf("                                                                  Invalid Input!");
        }
    }
}

void MainMenu()
{
    system("cls");
    char k = 177;
    int i, choose;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  %c", k);
    for (i = 1; i < 80; i++)
    {
        printf("%c", k);
    }
    printf("\n");
    printf("\n");
    printf("                                                                  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- M A I N  M E N U -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("                                                                  %c", k);
    for (i = 1; i < 80; i++)
    {
        printf("%c", k);
    }
    printf("\n");
    printf("\n");
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. View Holiday Packages\n");
    printf("\n");
    printf("                                                                  2. Book Holiday Package\n");
    printf("\n");
    printf("                                                                  3. View and Book Routes & Travels\n");
    printf("\n");
    printf("                                                                  4. View Your Bookings\n");
    printf("\n");
    printf("                                                                  5. Contact Us\n");
    printf("\n");
    printf("                                                                  6. About Us\n");
    printf("\n");
    printf("                                                                  7. Exit\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    fflush(stdin);
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        ViewPackages();
        break;
    case 2:
        BookPackage();
        break;
    case 3:
        ViewRoutes();
        break;
    case 4:
        ViewBookings();
        break;
    case 5:
        ContactUs();
        break;
    case 6:
        AboutUs();
        break;
    case 7:
        ExitScreen();
        break;
    default:
        printf("\n\n                                                                  :( Invalid Entry. Please enter the correct option!");
        getch();
        system("cls");
        MainMenu();
        break;
    }
}

void ViewPackages()
{
    system("cls");
    int i, choose;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("                                                                                             H O L I D A Y  P A C K A G E S\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Holiday Packages:\n");
    printf("\n");
    printf("                                                                   1. Jammu and Kashmir\n");
    printf("\n");
    printf("                                                                   2. Shimla - Manali\n");
    printf("\n");
    printf("                                                                   3. Mussorie - Nainital\n");
    printf("\n");
    printf("                                                                   4. Kerala\n");
    printf("\n");
    printf("                                                                   5. Goa - Mahabaleshwar\n");
    printf("\n");
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Please select any tour package to view more details and press 0 to go back: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        JammuKashmir();
        break;
    case 2:
        ShimlaManali();
        break;
    case 3:
        MussorieNainital();
        break;
    case 4:
        Kerala();
        break;
    case 5:
        Goa();
        break;
    case 0:
        MainMenu();
        break;
    default:
        printf("                                                                   :( Invalid Input....");
        getch();
        system("cls");
        ViewPackages();
        break;
    }
}

void JammuKashmir()
{
    system("cls");
    printf("\n");
    printf("                                                                                      H O L I D A Y  P A C K A G E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        JAMMU AND KASHMIR\n");
    printf("\n");
    printf("                                                                  Location             :        JAMMU, KASHMIR, SRINAGAR, PAHALGAM\n");
    printf("\n");
    printf("                                                                  Duration             :        6 Days 5 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        May 5 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Jammu\n");
    printf("                                                                                                (You will need to reach Jammu on 4 May 2021)\n");
    printf("\n");
    printf("                                                                  Tour Program         :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Day       Date                Daily Travel Shedule                Night Halt \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                    1      5-5-2021   Visiting in Jammu City                       Hotel C7, Jammu\n");
    printf("                                                                    2      6-5-2021   Way to Srinagar                              Hotel Holiday,\n");
    printf("                                                                                                                                   Srinagar\n");
    printf("                                                                    3      7-5-2021   Sonmarg, Gulmarg                             House Boat\n");
    printf("                                                                                                                                   Dal Lake, Srinagar\n");
    printf("                                                                    4      8-5-2021   Visting in Srinagar, Dal lake                House Boat\n");
    printf("                                                                                                                                   Dal Lake, Srinagar\n");
    printf("                                                                    5      9-5-2021   Vistiing in Pahelgam                         Hotel Royal,\n");
    printf("                                                                                                                                   Pahelgam\n");
    printf("                                                                    6     10-5-2021   Back to Jammu                                Hotel C7, Jammu\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                   Drop Point           :       Jammu Airport\\ Jammu Railway Station\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 12000 Rs, Per Person 9000 Rs for below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Jammu and\n");
    printf("                                                                                                returning from Jammu on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                   Press any key to go back: ");
    getch();
    ViewPackages();
}

void ShimlaManali()
{
    system("cls");
    printf("\n");
    printf("                                                                                      H O L I D A Y  P A C K A G E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        SHIMLA - MANALI\n");
    printf("\n");
    printf("                                                                  Location             :        SHIMLA, MANALI, DELHOUSIE, AMRITSAR\n");
    printf("\n");
    printf("                                                                  Duration             :        4 Days 3 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        May 11 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Shimla\n");
    printf("                                                                                                (You will need to reach Shimla on 10 May 2021)\n");
    printf("\n");
    printf("                                                                  Tour Program         :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Day       Date                Daily Travel Shedule                Night Halt \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                    1     11-5-2021   Visiting in Shimala and way to Manali     Hotel Blue Palace, Manali\n");
    printf("                                                                    2     12-5-2021   Visiting in Manali and Rohtank            Hotel Blue Palace, Manali\n");
    printf("                                                                    3     13-5-2021   Way to Delhousie and visiting Delhousie   Hotel Royal, Delhousie\n");
    printf("                                                                    4     14-5-2021   Way to Amrister and visiting in Amritser  Hotel Golden Palace,\n");
    printf("                                                                                                                                Amritser\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                   Drop Point           :       Chandigrah Airport\\ Chandigrah Railway Station\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 25000 Rs, Per Person 23500 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Shimla and\n");
    printf("                                                                                                returning Chandigrah on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                   Press any key to go back: ");
    getch();
    ViewPackages();
}

void MussorieNainital()
{
    system("cls");
    printf("\n");
    printf("                                                                                      H O L I D A Y  P A C K A G E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        MUSSORIE - NAINITAL\n");
    printf("\n");
    printf("                                                                  Location             :        HARIDWAR, DEHRADUN, MUSSORIE, NAINITAL\n");
    printf("\n");
    printf("                                                                  Duration             :        5 Days 4 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        April 13 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Dehradun\n");
    printf("                                                                                                (You will need to reach Dehradun on 12 April 2021)\n");
    printf("\n");
    printf("                                                                  Tour Program         :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Day       Date                Daily Travel Shedule                Night Halt \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                    1     13-4-2021   Visiting in Dehradun and way to Mussorie   Hotel Fortune Palace,\n");
    printf("                                                                                                                                 Mussorie\n");
    printf("                                                                    2     14-4-2021   Visiting in Mussorie and way to Haridwar   Hotel Blue Vista,\n");
    printf("                                                                                                                                 Haridwar\n");
    printf("                                                                    3     15-4-2021   Visiting in Haridwar                       Hotel Blue Vista,\n");
    printf("                                                                                                                                 Haridwar\n");
    printf("                                                                    4     16-4-2021   Way to Nainital and visiting in Nainital   Hotel one, Nainital\n");
    printf("                                                                    5     17-4-2021   Back to Dehradun                           Hotel Ginger,\n");
    printf("                                                                                                                                 Dehradun\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                   Drop Point           :       Dehradun Airport\\ Dehradun Railway Station\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 15000 Rs, Per Person 10000 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Dehradun and\n");
    printf("                                                                                                returning from Dehradun on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                   Press any key to go back: ");
    getch();
    ViewPackages();
}

void Kerala()
{
    system("cls");
    printf("\n");
    printf("                                                                                      H O L I D A Y  P A C K A G E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        KERALA\n");
    printf("\n");
    printf("                                                                  Location             :        ERNAKOLOM, MUNNR, THEKKADY, KOVALAM\n");
    printf("\n");
    printf("                                                                  Duration             :        5 Days 4 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        April 19 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Ernakolom\n");
    printf("                                                                                                (You will need to reach Ernakolom on 18 April 2021)\n");
    printf("\n");
    printf("                                                                  Tour Program         :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Day       Date                Daily Travel Shedule                Night Halt \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                    1     19-4-2021   Visiting in Ernakolom                      Hotel WyteFort, Ernakolom\n");
    printf("                                                                    2     20-4-2021   Way to Munnar and visiting in Munnar       Hotel C7, Munnar\n");
    printf("                                                                    3     21-4-2021   Way to Thekkdy and visiting in Thekkdy     Hotel Holiday Vista,\n");
    printf("                                                                                                                                 Thekkdy\n");
    printf("                                                                    4     22-4-2021   Way to Kovalam and visiting Kovalam Beach  Kovalam resort, Kovalam\n");
    printf("                                                                    5     23-4-2021   Way to Trivendram and visiting Trivendram  Hotel Grand Palace,\n");
    printf("                                                                                                                                 Trivendram\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                   Drop Point           :       Trivendram Airport\\ Kochuveli Railway Station\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 20000 Rs, Per Person 17000 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Ernakolom and\n");
    printf("                                                                                                returning from Trivendram\\ Kochuveli on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                   Press any key to go to Main Menu: ");
    getch();
    ViewPackages();
}

void Goa()
{
    system("cls");
    printf("\n");
    printf("                                                                                      H O L I D A Y  P A C K A G E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        GOA - MAHABALESHWAR\n");
    printf("\n");
    printf("                                                                  Location             :        GOA, MAHABALESHWAR, LONAWALA\n");
    printf("\n");
    printf("                                                                  Duration             :        4 Days 3 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        May 21 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Panji\n");
    printf("                                                                                                (You will need to reach Panji on 21 May 2021)\n");
    printf("\n");
    printf("                                                                  Tour Program         :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Day       Date                Daily Travel Shedule                Night Halt \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                    1     21-5-2021   Visiting in Panji and way to Goa           Hotel Fort Palace, Goa\n");
    printf("                                                                    2     22-5-2021   Visiting in Goa and way to Mahabaleshwar   Hotel Queen, Mahabaleshwar\n");
    printf("                                                                    3     23-5-2021   Visiting in Mahabalesshwar and way to      Holiday Resort, Lonawala\n");
    printf("                                                                                      Lonawala\n");
    printf("                                                                    4     24-5-2021   Visiting in Lonawala and back to Panji     travelling\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                   Drop Point           :       Panji Airport\\ Panji Railway Station\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 22000 Rs, Per Person 18000 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Panji and\n");
    printf("                                                                                                returning from Panji on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                   Press any key to go back: ");
    getch();
    ViewPackages();
}

void ViewRoutes()
{
    system("cls");
    int i, ans1, ans2;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("                                                                              T R A V E L S  D E T A I L S  A N D  B O O K I N G\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Your Location:\n");
    printf("\n");
    printf("                                                                   1. Ahmedabad\n");
    printf("\n");
    printf("                                                                   2. Vadodra\n");
    printf("\n");
    printf("                                                                   3. Surat\n");
    printf("\n");
    printf("                                                                   4. Rajkot\n");
    printf("\n");
    printf("                                                                   5. Mumbai\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Please select your Location or press 0 to go back: ");
    scanf("%d", &ans1);
    printf("\n");
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("\n");
    if (ans1 == 1)
    {
        printf("                                                                   Your Destination:\n");
        printf("\n");
        printf("                                                                   1. Vadodra\n");
        printf("\n");
        printf("                                                                   2. Surat\n");
        printf("\n");
        printf("                                                                   3. Rajkot\n");
        printf("\n");
        printf("                                                                   4. Mumbai\n");
        printf("\n");
        printf("\n");
        printf("                                                                   Please select your Destination or press 0 to go back: ");
        scanf("%d", &ans2);
        if (ans2 == 1)
        {
            AhmedabadVadodra();
        }
        else if (ans2 == 2)
        {
            AhmedabadSurat();
        }
        else if (ans2 == 3)
        {
            AhmedabadRajkot();
        }
        else if (ans2 == 4)
        {
            AhmedabadMumbai();
        }
        else if (ans2 == 0)
        {
            MainMenu();
        }
        else
        {
            printf("                                                                   :( Invalid Input...");
            getch();
            ViewRoutes();
        }
    }
    else if (ans1 == 2)
    {
        printf("                                                                   Your Destination:\n");
        printf("\n");
        printf("                                                                   1. Ahmedabad\n");
        printf("\n");
        printf("                                                                   2. Surat\n");
        printf("\n");
        printf("                                                                   3. Rajkot\n");
        printf("\n");
        printf("                                                                   4. Mumbai\n");
        printf("\n");
        printf("\n");
        printf("                                                                   Please select your Destination or press 0 to go back: ");
        scanf("%d", &ans2);
        if (ans2 == 1)
        {
            VadodraAhmedabad();
        }
        else if (ans2 == 2)
        {
            VadodraSurat();
        }
        else if (ans2 == 3)
        {
            VadodraRajkot();
        }
        else if (ans2 == 4)
        {
            VadodraMumbai();
        }
        else if (ans2 == 0)
        {
            MainMenu();
        }
        else
        {
            printf("                                                                   :( Invalid Input...");
            getch();
            ViewRoutes();
        }
    }
    else if (ans1 == 3)
    {
        printf("                                                                   Your Destination:\n");
        printf("\n");
        printf("                                                                   1. Ahmedabad\n");
        printf("\n");
        printf("                                                                   2. Vadodra\n");
        printf("\n");
        printf("                                                                   3. Rajkot\n");
        printf("\n");
        printf("                                                                   4. Mumbai\n");
        printf("\n");
        printf("\n");
        printf("                                                                   Please select your Destination or press 0 to go back: ");
        scanf("%d", &ans2);
        if (ans2 == 1)
        {
            SuratAhmedabad();
        }
        else if (ans2 == 2)
        {
            SuratVadodra();
        }
        else if (ans2 == 3)
        {
            SuratRajkot();
        }
        else if (ans2 == 4)
        {
            SuratMumbai();
        }
        else if (ans2 == 0)
        {
            MainMenu();
        }
        else
        {
            printf("                                                                   :( Invalid Input...");
            getch();
            ViewRoutes();
        }
    }
    else if (ans1 == 4)
    {
        printf("                                                                   Your Destination:\n");
        printf("\n");
        printf("                                                                   1. Ahmedabad\n");
        printf("\n");
        printf("                                                                   2. Vadodra\n");
        printf("\n");
        printf("                                                                   3. Surat\n");
        printf("\n");
        printf("                                                                   4. Mumbai\n");
        printf("\n");
        printf("\n");
        printf("                                                                   Please select your Destination or press 0 to go back: ");
        scanf("%d", &ans2);
        if (ans2 == 1)
        {
            RajkotAhmedabad();
        }
        else if (ans2 == 2)
        {
            RajkotVadodra();
        }
        else if (ans2 == 3)
        {
            RajkotSurat();
        }
        else if (ans2 == 4)
        {
            RajkotMumbai();
        }
        else if (ans2 == 0)
        {
            MainMenu();
        }
        else
        {
            printf("                                                                   :( Invalid Input...");
            getch();
            ViewRoutes();
        }
    }
    else if (ans1 == 5)
    {
        printf("                                                                   Your Destination:\n");
        printf("\n");
        printf("                                                                   1. Ahmedabad\n");
        printf("\n");
        printf("                                                                   2. Vadodra\n");
        printf("\n");
        printf("                                                                   3. Surat\n");
        printf("\n");
        printf("                                                                   4. Rajkot\n");
        printf("\n");
        printf("\n");
        printf("                                                                   Please select your Destination and 0 to go back: ");
        scanf("%d", &ans2);
        if (ans2 == 1)
        {
            MumbaiAhmedabad();
        }
        else if (ans2 == 2)
        {
            MumbaiVadodra();
        }
        else if (ans2 == 3)
        {
            MumbaiSurat();
        }
        else if (ans2 == 4)
        {
            MumbaiRajkot();
        }
        else if (ans2 == 0)
        {
            MainMenu();
        }
        else
        {
            printf("                                                                   :( Invalid Input...");
            getch();
            ViewRoutes();
        }
    }
    else if (ans1 == 0)
    {
        MainMenu();
    }
    else
    {
        printf("                                                                   :( Invalid Input...");
        getch();
        ViewRoutes();
    }
}

void AhmedabadVadodra()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    char uname[15];
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  To                   :        VADODARA\n");
    printf("\n");
    printf("                                                                  Duration             :        1 hr 40 min\n");
    printf("\n");
    printf("                                                                  Distance             :        111 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     09:00      10:40       2x2 Seater, Non-A/c          Rs 350\n");
    printf("                                                                     2       Thu     10:00      11:40       2x2 Volvo Seater, A/c        Rs 450\n");
    printf("                                                                     3       Sat     16:00      17:40       2x2 Luxury Coach, A/c        Rs 500\n");
    printf("                                                                     4       Mon     21:00      22:40       2x1 Volvo Sleeper, A/c       Rs 550\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 350;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Ahmedabad - Vadodra\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    AhmedabadVadodra();
                }
            }
            else
            {
                AhmedabadVadodra();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                           Enter a Valid Bus Code!");
            AhmedabadVadodra();
        }
    }
    else
    {
        printf("                                                                 Return to main menu: ");
        getch();
        ViewRoutes();
    }
}

void AhmedabadSurat()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    char uname[15];
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  To                   :        SURAT\n");
    printf("\n");
    printf("                                                                  Duration             :        5 hrs\n");
    printf("\n");
    printf("                                                                  Distance             :        567 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     09:00      14:00       2x2 Seater, Non-A/c          Rs 375\n");
    printf("                                                                     2       Wed     10:00      15:00       2x2 Volvo Seater, A/c        Rs 475\n");
    printf("                                                                     3       Fri     16:00      21:00       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Sun     19:00      24:00       2x1 Volvo Sleeper, A/c       Rs 600\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 375;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 475;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Ahmedabad - Surat\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    AhmedabadSurat();
                }
            }
            else
            {
                AhmedabadSurat();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            AhmedabadSurat();
        }
    }
    else
    {
        printf("                                                                 Return to main menu: ");
        getch();
        ViewRoutes();
    }
}

void AhmedabadRajkot()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  To                   :        RAJKOT\n");
    printf("\n");
    printf("                                                                  Duration             :        4 hr 30 min\n");
    printf("\n");
    printf("                                                                  Distance             :        215 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     09:00      13:30       2x2 Seater, Non-A/c          Rs 450\n");
    printf("                                                                     2       Wed     10:00      14:30       2x2 Volvo Seater, A/c        Rs 550\n");
    printf("                                                                     3       Fri     16:00      20:30       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Sun     19:00      23:30       2x1 Volvo Sleeper, A/c       Rs 650\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 650;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Ahmedabad - Rajkot\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    AhmedabadRajkot();
                }
            }
            else
            {
                AhmedabadRajkot();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            AhmedabadRajkot();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void AhmedabadMumbai()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  To                   :        MUMBAI\n");
    printf("\n");
    printf("                                                                  Duration             :        10 hrs \n");
    printf("\n");
    printf("                                                                  Distance             :        531 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     07:00      17:00       2x2 Seater, Non-A/c          Rs 700\n");
    printf("                                                                     2       Wed     07:30      17:30       2x2 Volvo Seater, A/c        Rs 800\n");
    printf("                                                                     3       Fri     08:00      18:00       2x2 Luxury Coach, A/c        Rs 900\n");
    printf("                                                                     4       Sun     19:00      05:00       2x1 Volvo Sleeper, A/c       Rs 1000\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 700;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 800;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 900;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 1000;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Ahmedabad - Mumbai\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    AhmedabadMumbai();
                }
            }
            else
            {
                AhmedabadMumbai();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            AhmedabadMumbai();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void VadodraAhmedabad()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        VADODARA\n");
    printf("\n");
    printf("                                                                  To                   :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  Duration             :        1 hr 40 min\n");
    printf("\n");
    printf("                                                                  Distance             :        111 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     09:00      10:40       2x2 Seater, Non-A/c          Rs 350\n");
    printf("                                                                     2       Wed     10:00      11:40       2x2 Volvo Seater, A/c        Rs 450\n");
    printf("                                                                     3       Fri     16:00      17:40       2x2 Luxury Coach, A/c        Rs 500\n");
    printf("                                                                     4       Sun     21:00      22:40       2x1 Volvo Sleeper, A/c       Rs 550\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 350;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Vadodra - Ahmedabad\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    VadodraAhmedabad();
                }
            }
            else
            {
                VadodraAhmedabad();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            VadodraAhmedabad();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void VadodraSurat()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        VADODARA\n");
    printf("\n");
    printf("                                                                  To                   :        SURAT\n");
    printf("\n");
    printf("                                                                  Duration             :        3 hr 15 min\n");
    printf("\n");
    printf("                                                                  Distance             :        152 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     06:00      09:15       2x2 Seater, Non-A/c          Rs 300\n");
    printf("                                                                     2       Wed     08:00      11:15       2x2 Volvo Seater, A/c        Rs 400\n");
    printf("                                                                     3       Fri     16:00      19:15       2x2 Luxury Coach, A/c        Rs 450\n");
    printf("                                                                     4       Sun     21:00      24:15       2x1 Volvo Sleeper, A/c       Rs 550\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 300;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 400;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Vadodra - Surat\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    VadodraSurat();
                }
            }
            else
            {
                VadodraSurat();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            VadodraSurat();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void VadodraRajkot()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        VADODARA\n");
    printf("\n");
    printf("                                                                  To                   :        RAJKOT\n");
    printf("\n");
    printf("                                                                  Duration             :        5 hr 45 min\n");
    printf("\n");
    printf("                                                                  Distance             :        288 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     12:00      17:45       2x2 Seater, Non-A/c          Rs 450\n");
    printf("                                                                     2       Thu     06:00      09:45       2x2 Volvo Seater, A/c        Rs 500\n");
    printf("                                                                     3       Sat     23:00      04:45       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Mon     24:00      05:45       2x1 Volvo Sleeper, A/c       Rs 600\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Vadodra - Rajkot\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    VadodraRajkot();
                }
            }
            else
            {
                VadodraRajkot();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            VadodraRajkot();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void VadodraMumbai()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        VADODARA\n");
    printf("\n");
    printf("                                                                  To                   :        MUMBAI\n");
    printf("\n");
    printf("                                                                  Duration             :        7 hr 40 min\n");
    printf("\n");
    printf("                                                                  Distance             :        414 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     06:00      01:40       2x2 Seater, Non-A/c          Rs 550\n");
    printf("                                                                     2       Wed     13:00      20:40       2x2 Volvo Seater, A/c        Rs 600\n");
    printf("                                                                     3       Fri     22:00      05:40       2x2 Luxury Coach, A/c        Rs 650\n");
    printf("                                                                     4       Sun     23:00      06:40       2x1 Volvo Sleeper, A/c       Rs 700\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 650;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 700;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Vadodra - Mumbai\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    VadodraMumbai();
                }
            }
            else
            {
                VadodraMumbai();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            VadodraMumbai();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void SuratAhmedabad()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        SURAT\n");
    printf("\n");
    printf("                                                                  To                   :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  Duration             :        5 hrs\n");
    printf("\n");
    printf("                                                                  Distance             :        567 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     09:00      14:00       2x2 Seater, Non-A/c          Rs 375\n");
    printf("                                                                     2       Thu     10:00      15:00       2x2 Volvo Seater, A/c        Rs 475\n");
    printf("                                                                     3       Sat     16:00      21:00       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Mon     19:00      24:00       2x1 Volvo Sleeper, A/c       Rs 600\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 375;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 475;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Surat - Ahmedabad\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    SuratAhmedabad();
                }
            }
            else
            {
                SuratAhmedabad();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            SuratAhmedabad();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void SuratVadodra()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        SURAT\n");
    printf("\n");
    printf("                                                                  To                   :        VADODARA\n");
    printf("\n");
    printf("                                                                  Duration             :        3 hr 15 min\n");
    printf("\n");
    printf("                                                                  Distance             :        152 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     06:00      09:15       2x2 Seater, Non-A/c          Rs 300\n");
    printf("                                                                     2       Thu     08:00      11:15       2x2 Volvo Seater, A/c        Rs 400\n");
    printf("                                                                     3       Sat     16:00      19:15       2x2 Luxury Coach, A/c        Rs 450\n");
    printf("                                                                     4       Mon     21:00      24:15       2x1 Volvo Sleeper, A/c       Rs 550\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 300;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 400;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Surat - Vadodra\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    SuratVadodra();
                }
            }
            else
            {
                SuratVadodra();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            SuratVadodra();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void SuratRajkot()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        SURAT\n");
    printf("\n");
    printf("                                                                  To                   :        RAJKOT\n");
    printf("\n");
    printf("                                                                  Duration             :        9 hrs\n");
    printf("\n");
    printf("                                                                  Distance             :        475 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     06:00      15:00       2x2 Seater, Non-A/c          Rs 500\n");
    printf("                                                                     2       Wed     08:00      17:00       2x2 Volvo Seater, A/c        Rs 600\n");
    printf("                                                                     3       Fri     22:00      07:00       2x2 Luxury Coach, A/c        Rs 700\n");
    printf("                                                                     4       Sun     20:00      05:00       2x1 Volvo Sleeper, A/c       Rs 850\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 700;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 850;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Surat - Rajkot\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    SuratRajkot();
                }
            }
            else
            {
                SuratRajkot();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            SuratRajkot();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void SuratMumbai()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        SURAT\n");
    printf("\n");
    printf("                                                                  To                   :        MUMBAI\n");
    printf("\n");
    printf("                                                                  Duration             :        5 hr 20 min\n");
    printf("\n");
    printf("                                                                  Distance             :        280 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     07:00      12:20       2x2 Seater, Non-A/c          Rs 400\n");
    printf("                                                                     2       Thu     14:00      19:20       2x2 Volvo Seater, A/c        Rs 500\n");
    printf("                                                                     3       Sat     01:00      06:20       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Mon     24:00      05:20       2x1 Volvo Sleeper, A/c       Rs 600\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 400;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Surat - Mumbai\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    SuratMumbai();
                }
            }
            else
            {
                SuratMumbai();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            SuratMumbai();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void RajkotAhmedabad()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        RAJKOT\n");
    printf("\n");
    printf("                                                                  To                   :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  Duration             :        4 hr 30 min\n");
    printf("\n");
    printf("                                                                  Distance             :        215 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     09:00      13:30       2x2 Seater, Non-A/c          Rs 450\n");
    printf("                                                                     2       Thu     10:00      14:30       2x2 Volvo Seater, A/c        Rs 550\n");
    printf("                                                                     3       Sat     16:00      20:30       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Mon     19:00      23:30       2x1 Volvo Sleeper, A/c       Rs 650\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 650;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Rajkot - Ahmedabad\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    RajkotAhmedabad();
                }
            }
            else
            {
                RajkotAhmedabad();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            RajkotAhmedabad();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void RajkotVadodra()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        RAJKOT\n");
    printf("\n");
    printf("                                                                  To                   :        VADODARA\n");
    printf("\n");
    printf("                                                                  Duration             :        5 hrs 45 min\n");
    printf("\n");
    printf("                                                                  Distance             :        288 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     12:00      17:45       2x2 Seater, Non-A/c          Rs 450\n");
    printf("                                                                     2       Wed     06:00      09:45       2x2 Volvo Seater, A/c        Rs 500\n");
    printf("                                                                     3       Fri     23:00      04:45       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Sun     24:00      05:45       2x1 Volvo Sleeper, A/c       Rs 600\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 450;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Rajkot - Vadodra\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    RajkotVadodra();
                }
            }
            else
            {
                RajkotVadodra();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            RajkotVadodra();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void RajkotSurat()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        RAJKOT\n");
    printf("\n");
    printf("                                                                  To                   :        SURAT\n");
    printf("\n");
    printf("                                                                  Duration             :        9 hrs\n");
    printf("\n");
    printf("                                                                  Distance             :        475 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     06:00      15:00       2x2 Seater, Non-A/c          Rs 500\n");
    printf("                                                                     2       Thu     08:00      17:00       2x2 Volvo Seater, A/c        Rs 600\n");
    printf("                                                                     3       Sat     22:00      07:00       2x2 Luxury Coach, A/c        Rs 700\n");
    printf("                                                                     4       Mon     20:00      05:00       2x1 Volvo Sleeper, A/c       Rs 850\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        printf("                                                                  Please select Bus Code: ");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 700;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 850;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Rajkot - Surat\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    RajkotSurat();
                }
            }
            else
            {
                RajkotSurat();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            RajkotSurat();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}
void RajkotMumbai()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        RAJKOT\n");
    printf("\n");
    printf("                                                                  To                   :        MUMBAI\n");
    printf("\n");
    printf("                                                                  Duration             :        13 hr 15 min\n");
    printf("\n");
    printf("                                                                  Distance             :        736 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     05:00      18:15       2x2 Seater, Non-A/c          Rs 800\n");
    printf("                                                                     2       Thu     06:00      19:15       2x2 Volvo Seater, A/c        Rs 850\n");
    printf("                                                                     3       Sat     22:00      11:15       2x2 Luxury Coach, A/c        Rs 900\n");
    printf("                                                                     4       Mon     24:00      01:30       2x1 Volvo Sleeper, A/c       Rs 1000\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 800;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 850;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 900;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 1000;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Rajkot - Mumbai\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    RajkotMumbai();
                }
            }
            else
            {
                RajkotMumbai();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            RajkotMumbai();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void MumbaiAhmedabad()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        MUMBAI\n");
    printf("\n");
    printf("                                                                  To                   :        AHMEDABAD\n");
    printf("\n");
    printf("                                                                  Duration             :        10 hrs \n");
    printf("\n");
    printf("                                                                  Distance             :        531 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     07:00      17:00       2x2 Seater, Non-A/c          Rs 700\n");
    printf("                                                                     2       Thu     07:30      17:30       2x2 Volvo Seater, A/c        Rs 800\n");
    printf("                                                                     3       Sat     08:00      18:00       2x2 Luxury Coach, A/c        Rs 900\n");
    printf("                                                                     4       Mon     19:00      05:00       2x1 Volvo Sleeper, A/c       Rs 1000\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 700;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 800;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 900;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 1000;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Mumbai - Ahmedabad\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    MumbaiAhmedabad();
                }
            }
            else
            {
                MumbaiAhmedabad();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            MumbaiAhmedabad();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void MumbaiVadodra()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        MUMBAI\n");
    printf("\n");
    printf("                                                                  To                   :        VADODARA\n");
    printf("\n");
    printf("                                                                  Duration             :        7 hr 40 min\n");
    printf("\n");
    printf("                                                                  Distance             :        414 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Tue     06:00      01:40       2x2 Seater, Non-A/c          Rs 550\n");
    printf("                                                                     2       Thu     13:00      20:40       2x2 Volvo Seater, A/c        Rs 600\n");
    printf("                                                                     3       Sat     22:00      05:40       2x2 Luxury Coach, A/c        Rs 650\n");
    printf("                                                                     4       Mon     23:00      06:40       2x1 Volvo Sleeper, A/c       Rs 700\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 650;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 700;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Mumbai - Vadodra\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    MumbaiVadodra();
                }
            }
            else
            {
                MumbaiVadodra();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            MumbaiVadodra();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void MumbaiSurat()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        MUMBAI\n");
    printf("\n");
    printf("                                                                  To                   :        SURAT\n");
    printf("\n");
    printf("                                                                  Duration             :        5 hr 20 min\n");
    printf("\n");
    printf("                                                                  Distance             :        280 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     07:00      12:20       2x2 Seater, Non-A/c          Rs 400\n");
    printf("                                                                     2       Wed     14:00      19:20       2x2 Volvo Seater, A/c        Rs 500\n");
    printf("                                                                     3       Fri     01:00      06:20       2x2 Luxury Coach, A/c        Rs 550\n");
    printf("                                                                     4       Sun     24:00      05:20       2x1 Volvo Sleeper, A/c       Rs 600\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 400;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 500;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 550;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 600;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Mumbai - Surat\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    MumbaiSurat();
                }
            }
            else
            {
                MumbaiSurat();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            MumbaiSurat();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void MumbaiRajkot()
{
    system("cls");
    int i, j, k, h, x;
    char ch, s;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                                               R O U T E  D E T A I L S\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  From                 :        MUMBAI\n");
    printf("\n");
    printf("                                                                  To                   :        RAJKOT\n");
    printf("\n");
    printf("                                                                  Duration             :        13 hr 15 min\n");
    printf("\n");
    printf("                                                                  Distance             :        736 km\n");
    printf("\n");
    printf("                                                                  Available Buses      :\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                   Bus Code  Day   Departure    Arrive            Bus Type              Ticket Cost \n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("                                                                     1       Mon     05:00      18:15       2x2 Seater, Non-A/c          Rs 800\n");
    printf("                                                                     2       Wed     06:00      19:15       2x2 Volvo Seater, A/c        Rs 850\n");
    printf("                                                                     3       Fri     22:00      11:15       2x2 Luxury Coach, A/c        Rs 900\n");
    printf("                                                                     4       Sun     24:00      01:15       2x1 Volvo Sleeper, A/c       Rs 1000\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                  1. Book Now\n");
    printf("\n");
    printf("                                                                  2. Main Menu\n");
    printf("\n");
    printf("                                                                  Please select any option: ");
    scanf("%d", &j);
    if (j == 1)
    {
        printf("\n");
        char uname[15];
        printf("\n                                                                  Please enter your name: ");
        fflush(stdin);
        gets(uname);
        printf("\n\n");
        printf("                                                                  Please select Bus Code: ");
        scanf("%d", &k);
        if (k == 1 || k == 2 || k == 3 || k == 4)
        {
            printf("\n");
            printf("                                                                  Are You Sure to book the bus with the Bus Code %d?  (Enter Y for yes and N for No) : ", k);
            scanf("\n%c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\n");
                printf("                                                                  Enter the number of Seats you want to book: ");
                scanf("%d", &h);
                printf("\n");
                if (k == 1)
                {
                    x = h * 800;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 2)
                {
                    x = h * 850;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 3)
                {
                    x = h * 900;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                if (k == 4)
                {
                    x = h * 1000;
                    printf("                                                                  Total Amount You need to Pay for %d persons: Rs %d", h, x);
                }
                printf("\n");
                printf("\n");
                printf("                                                                  Are You Sure to book the bus with your Total Amount %d and your Bus Code %d ?  (Enter Y for yes and N for No) : ", x, k);
                scanf("\n%c", &s);
                printf("\n");
                if (s == 'Y' || s == 'y')
                {
                    printf("\n");
                    printf("                                                                                    THANK YOU FOR BOOKING OUR TRAVELS!");
                    FILE *fptr;
                    fptr = fopen("travels.txt", "a");
                    if (fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr, "\n\n");
                    fprintf(fptr, "--> Name: %s\n", uname);
                    fprintf(fptr, "--> Route: Mumbai - Rajkot\n");
                    fprintf(fptr, "--> Bus Code: %d\n", k);
                    fprintf(fptr, "--> Number of seats Booked: %d\n", h);
                    fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", x);
                    fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
                    fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
                    fclose(fptr);
                    getch();
                    MainMenu();
                }
                else
                {
                    MumbaiRajkot();
                }
            }
            else
            {
                MumbaiRajkot();
            }
        }
        else
        {
            printf("\n");
            printf("                                                                                          Enter a Valid Bus Code!");
            getch();
            MumbaiRajkot();
        }
    }
    else
    {
        printf("                                                                 Return to main menu");
        getch();
        ViewRoutes();
    }
}

void ContactUs()
{
    system("cls");
    int i, choose;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("                                                                                                  C O N T A C T  U S\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                   You can email us:\n");
    printf("\n");
    printf("                                                                   1. Jainam Shah     -    jainam.s5@ahduni.edu.in\n");
    printf("\n");
    printf("                                                                   2. Kinal Kagathara -    kinal.k@ahduni.edu.in\n");
    printf("\n");
    printf("                                                                   3. Aryan Bhavsar   -    aryan.b@ahduni.edu.in\n");
    printf("\n");
    printf("\n");
    printf("                                                                   You can call us also:\n");
    printf("\n");
    printf("                                                                   1. Jainam Shah     -    982XXXX409\n");
    printf("\n");
    printf("                                                                   2. Kinal Kagathara -    799XXXX277\n");
    printf("\n");
    printf("                                                                   3. Aryan Bhavsar   -    762XXXX369\n");
    printf("\n");
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Please press any key to go back: ");
    getch();
    MainMenu();
}

void AboutUs()
{
    system("cls");
    int i, choose;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("                                                                                                  A B O U T  U S\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                   ==> We are a full-service travel agency having our presence in India.\n");
    printf("\n");
    printf("                                                                   ==> We strive to make travel simple, worry free and fun for our corporate\n");
    printf("                                                                       and leisure clients.\n");
    printf("\n");
    printf("                                                                   ==> We are commited to provide best services among with exceptional value for\n");
    printf("                                                                       money for our clients.\n");
    printf("\n");
    printf("                                                                   ==> We work as consultants for our client's upcoming travel plans.\n");
    printf("\n");
    printf("                                                                   ==> Guranted Lowest Prices.\n");
    printf("\n");
    printf("                                                                   ==> One-step solution for all your travel need.\n");
    printf("\n");
    printf("                                                                   ==> 24x7 Support\n");
    printf("\n");
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Please press any key to go back: ");
    getch();
    MainMenu();
}

void BookPackage()
{
    system("cls");
    int i, choose;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("                                                                                      B O O K  M Y  H O L I D A Y  P A C K A G E \n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Book Holiday Packages:\n");
    printf("\n");
    printf("                                                                   1. Jammu and Kashmir\n");
    printf("\n");
    printf("                                                                   2. Shimla - Manali\n");
    printf("\n");
    printf("                                                                   3. Mussorie - Nainital\n");
    printf("\n");
    printf("                                                                   4. Kerala\n");
    printf("\n");
    printf("                                                                   5. Goa - Mahabaleshwar\n");
    printf("\n");
    printf("                                                                  --------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("                                                                   Please select a tour package that you want to book and press 0 to go back: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        BookJammuKashmir();
        break;
    case 2:
        BookShimlaManali();
        break;
    case 3:
        BookMussorieNainital();
        break;
    case 4:
        BookKerala();
        break;
    case 5:
        BookGoa();
        break;
    case 0:
        MainMenu();
        break;
    default:
        printf("                                                                   :( Invalid Input...\n");
        getch();
        BookPackage();
        break;
    }
}

void BookJammuKashmir()
{
    system("cls");
    int i, x, age, a = 0, b = 0, c = 1, d = 1;
    char s;
    printf("\n");
    printf("                                                                                       B O O K  H O L I D A Y  P A C K A G E\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        JAMMU AND KASHMIR\n");
    printf("\n");
    printf("                                                                  Location             :        JAMMU, KASHMIR, SRINAGAR, PAHALGAM\n");
    printf("\n");
    printf("                                                                  Duration             :        6 Days 5 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        May 5 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Jammu\n");
    printf("                                                                                                (You will need to reach Jammu on 4 May 2021)\n");
    printf("\n");
    printf("                                                                   Tour cost           :        Per Person 12000 Rs, Per Person 9000 Rs for below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions        :        You need to book your ticket for reaching Jammu and\n");
    printf("                                                                                                returning from Jammu on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                                                   B O O K I N G S-");
    printf("\n");
    char uname[15];
    printf("\n                                                                  Please enter your name: ");
    fflush(stdin);
    gets(uname);
    printf("\n\n");
    printf("                                                                   Enter number of Persons taking benefit of this Tour: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 1; i <= x; i++)
    {
        printf("                                                                   Enter the Age of Person %d : ", i);
        scanf("%d", &age);
        printf("\n");
        if (age <= 0)
        {
            printf("                                                                   Enter a Valid Age!");
            getch();
            BookJammuKashmir();
            break;
        }
        else
        {
            if (age <= 7)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    c = a * 9000;
    d = b * 12000;
    printf("                                                                   Total Amount For people with the age Less than or equal to 7: Rs. %d ", c);
    printf("\n");
    printf("\n");
    printf("                                                                   Total Amount For people with the age Greater than 7: Rs. %d ", d);
    printf("\n");
    printf("\n");
    printf("                                                                   Your GRAND TOTAL is: Rs. %d", c + d);
    printf("\n");
    printf("\n");
    printf("                                                                   Are You Sure to book the the TOUR JAMMU AND KASHMIR with your Total Amount Rs. %d ? (Enter Y for yes and N for No) : ", c + d);
    scanf("\n%c", &s);
    printf("\n");
    if (s == 'Y' || s == 'y')
    {
        printf("\n");
        printf("                                                                                    THANK YOU FOR BOOKING OUR TOURS!");
        FILE *fptr;
        fptr = fopen("packages.txt", "a");
        if (fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr, "\n\n");
        fprintf(fptr, "--> Name: %s\n", uname);
        fprintf(fptr, "--> Package Name: Jammu - Kashmir\n");
        fprintf(fptr, "--> Duration: 6 days 5 nights\n");
        fprintf(fptr, "--> Starting Date: May 5 2021\n");
        fprintf(fptr, "--> Number of Persons: %d\n", x);
        fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", c + d);
        fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
        fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
        fclose(fptr);
        getch();
        MainMenu();
    }
    else
    {
        BookPackage();
    }
}

void BookShimlaManali()
{
    system("cls");
    int i, x, age, a = 0, b = 0, c = 1, d = 1;
    char s;
    printf("\n");
    printf("                                                                                         B O O K  H O L I D A Y  P A C K A G E\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        SHIMLA - MANALI\n");
    printf("\n");
    printf("                                                                  Location             :        SHIMLA, MANALI, DELHOUSIE, AMRITSAR\n");
    printf("\n");
    printf("                                                                  Duration             :        4 Days 3 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        May 11 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Shimla\n");
    printf("                                                                                                (You will need to reach Shimla on 10 May 2021)\n");
    printf("\n");
    printf("                                                                  Tour cost            :        Per Person 25000 Rs, Per Person 23500 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                  Instructions         :        You need to book your ticket for reaching Shimla and\n");
    printf("                                                                                                returning Chandigrah on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                                                 B O O K I N G S\n");
    printf("\n");
    char uname[15];
    printf("\n                                                                  Please enter your name: ");
    fflush(stdin);
    gets(uname);
    printf("\n\n");
    printf("                                                                   Enter number of Persons taking benefit of this Tour: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 1; i <= x; i++)
    {
        printf("                                                                   Enter the Age of Person %d : ", i);
        scanf("%d", &age);
        printf("\n");
        if (age <= 0)
        {
            printf("                                                                   Enter a Valid Age!");
            getch();
            BookShimlaManali();
            break;
        }
        else
        {
            if (age <= 7)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    c = a * 23500;
    d = b * 25000;
    printf("                                                                   Total Amount For people with the age Less than or equal to 7: Rs. %d ", c);
    printf("\n");
    printf("\n");
    printf("                                                                   Total Amount For people with the age Greater than 7: Rs. %d ", d);
    printf("\n");
    printf("\n");
    printf("                                                                   Your GRAND TOTAL is: Rs. %d", c + d);
    printf("\n");
    printf("\n");
    printf("                                                                   Are You Sure to book the the TOUR JAMMU AND KASHMIR with your Total Amount Rs. %d ? (Enter Y for yes and N for No) : ", c + d);
    scanf("\n%c", &s);
    printf("\n");
    if (s == 'Y' || s == 'y')
    {
        printf("\n");
        printf("                                                                                    THANK YOU FOR BOOKING OUR TOURS!");
        FILE *fptr;
        fptr = fopen("packages.txt", "a");
        if (fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr, "\n\n");
        fprintf(fptr, "--> Name: %s\n", uname);
        fprintf(fptr, "--> Package Name: Shimla - Manali\n");
        fprintf(fptr, "--> Duration: 4 days 3 nights\n");
        fprintf(fptr, "--> Starting Date: May 11 2021\n");
        fprintf(fptr, "--> Number of Persons: %d\n", x);
        fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", c + d);
        fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
        fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
        fclose(fptr);
        getch();
        MainMenu();
    }
    else
    {
        getch();
        BookPackage();
    }
}

void BookMussorieNainital()
{
    system("cls");
    int i, x, age, a = 0, b = 0, c = 1, d = 1;
    char s;
    printf("\n");
    printf("                                                                                        B O O K  H O L I D A Y  P A C K A G E\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        MUSSORIE - NAINITAL\n");
    printf("\n");
    printf("                                                                  Location             :        HARIDWAR, DEHRADUN, MUSSORIE, NAINITAL\n");
    printf("\n");
    printf("                                                                  Duration             :        5 Days 4 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        April 13 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Dehradun\n");
    printf("                                                                                                (You will need to reach Dehradun on 12 April 2021)\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 15000 Rs, Per Person 10000 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Dehradun and\n");
    printf("                                                                                                returning from Dehradun on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                                               B O O K I N G S\n");
    printf("\n");
    char uname[15];
    printf("\n                                                                  Please enter your name: ");
    fflush(stdin);
    gets(uname);
    printf("\n\n");
    printf("                                                                   Enter number of Persons taking benefit of this Tour: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 1; i <= x; i++)
    {
        printf("                                                                   Enter the Age of Person %d : ", i);
        scanf("%d", &age);
        printf("\n");
        if (age <= 0)
        {
            printf("                                                                   Enter a Valid Age!");
            getch();
            BookMussorieNainital();
            break;
        }
        else
        {
            if (age <= 7)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    c = a * 10000;
    d = b * 15000;
    printf("                                                                   Total Amount For people with the age Less than or equal to 7: Rs. %d ", c);
    printf("\n");
    printf("\n");
    printf("                                                                   Total Amount For people with the age Greater than 7: Rs. %d ", d);
    printf("\n");
    printf("\n");
    printf("                                                                   Your GRAND TOTAL is: Rs. %d", c + d);
    printf("\n");
    printf("\n");
    printf("                                                                   Are You Sure to book the the TOUR JAMMU AND KASHMIR with your Total Amount Rs. %d ? (Enter Y for yes and N for No) : ", c + d);
    scanf("\n%c", &s);
    printf("\n");
    if (s == 'Y' || s == 'y')
    {
        printf("\n");
        printf("                                                                                    THANK YOU FOR BOOKING OUR TOURS!");
        FILE *fptr;
        fptr = fopen("packages.txt", "a");
        if (fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr, "\n\n");
        fprintf(fptr, "--> Name: %s\n", uname);
        fprintf(fptr, "--> Package Name: Mussorie - Nainital\n");
        fprintf(fptr, "--> Duration: 5 days 4 nights\n");
        fprintf(fptr, "--> Starting Date: April 13 2021\n");
        fprintf(fptr, "--> Number of Persons: %d\n", x);
        fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", c + d);
        fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
        fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
        fclose(fptr);
        getch();
        MainMenu();
    }
    else
    {
        BookPackage();
    }
}

void BookKerala()
{
    system("cls");
    int i, x, age, a = 0, b = 0, c = 1, d = 1;
    char s;
    printf("\n");
    printf("                                                                                        B O O K  H O L I D A Y  P A C K A G E\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        KERALA\n");
    printf("\n");
    printf("                                                                  Location             :        ERNAKOLOM, MUNNR, THEKKADY, KOVALAM\n");
    printf("\n");
    printf("                                                                  Duration             :        5 Days 4 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        April 19 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Ernakolom\n");
    printf("                                                                                                (You will need to reach Ernakolom on 18 April 2021)\n");
    printf("\n");
    printf("                                                                   Drop Point           :       Trivendram Airport\\ Kochuveli Railway Station\n");
    printf("\n");
    printf("                                                                   Tour cost            :       Per Person 20000 Rs, Per Person 17000 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                   Instructions         :       You need to book your ticket for reaching Ernakolom and\n");
    printf("                                                                                                returning from Trivendram\\ Kochuveli on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                                                  B O O K I N G S\n");
    printf("\n");
    char uname[15];
    printf("\n                                                                  Please enter your name: ");
    fflush(stdin);
    gets(uname);
    printf("\n\n");
    printf("                                                                   Enter number of Persons taking benefit of this Tour: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 1; i <= x; i++)
    {
        printf("                                                                   Enter the Age of Person %d : ", i);
        scanf("%d", &age);
        printf("\n");
        if (age <= 0)
        {
            printf("                                                                   Enter a Valid Age!");
            getch();
            BookKerala();
            break;
        }
        else
        {
            if (age <= 7)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    c = a * 17000;
    d = b * 20000;
    printf("                                                                   Total Amount For people with the age Less than or equal to 7: Rs. %d ", c);
    printf("\n");
    printf("\n");
    printf("                                                                   Total Amount For people with the age Greater than 7: Rs. %d ", d);
    printf("\n");
    printf("\n");
    printf("                                                                   Your GRAND TOTAL is: Rs. %d", c + d);
    printf("\n");
    printf("\n");
    printf("                                                                   Are You Sure to book the the TOUR JAMMU AND KASHMIR with your Total Amount Rs. %d ? (Enter Y for yes and N for No) : ", c + d);
    scanf("\n%c", &s);
    printf("\n");
    if (s == 'Y' || s == 'y')
    {
        printf("\n");
        printf("                                                                                    THANK YOU FOR BOOKING OUR TOURS!");
        FILE *fptr;
        fptr = fopen("packages.txt", "a");
        if (fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr, "\n\n");
        fprintf(fptr, "--> Name: %s\n", uname);
        fprintf(fptr, "--> Package Name: Kerala\n");
        fprintf(fptr, "--> Duration: 5 days 4 nights\n");
        fprintf(fptr, "--> Starting Date: April 19 2021\n");
        fprintf(fptr, "--> Number of Persons: %d\n", x);
        fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", c + d);
        fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
        fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
        fclose(fptr);
        getch();
        MainMenu();
    }
    else
    {
        BookPackage();
    }
}

void BookGoa()
{
    system("cls");
    int i, x, age, a = 0, b = 0, c = 1, d = 1;
    char s;
    printf("\n");
    printf("                                                                                        B O O K  H O L I D A Y  P A C K A G E\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Welcome User...                                              Date: %s\n", __DATE__);
    printf("                                                                                                                               Time: %s\n", __TIME__);
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                  Package Name         :        GOA - MAHABALESHWAR\n");
    printf("\n");
    printf("                                                                  Location             :        GOA, MAHABALESHWAR, LONAWALA\n");
    printf("\n");
    printf("                                                                  Duration             :        4 Days 3 Nights\n");
    printf("\n");
    printf("                                                                  Starting Date        :        May 21 2021\n");
    printf("\n");
    printf("                                                                  Pickup Point         :        Panji\n");
    printf("                                                                                                (You will need to reach Panji on 21 May 2021)\n");
    printf("\n");
    printf("                                                                  Tour cost            :        Per Person 22000 Rs, Per Person 18000 Rs for Below 7\n");
    printf("                                                                                                years old child (including Breakfast, Lunch, Dinner)\n");
    printf("\n");
    printf("                                                                  Instructions         :        You need to book your ticket for reaching Panji and\n");
    printf("                                                                                                returning from Panji on your own.\n");
    printf("\n");
    printf("                                                                  ________________________________________________________________________________\n");
    printf("\n");
    printf("                                                                                                    B O O K I N G S\n");
    printf("\n");
    char uname[15];
    printf("\n                                                                  Please enter your name: ");
    fflush(stdin);
    gets(uname);
    printf("\n\n");
    printf("                                                                   Enter number of Persons taking benefit of this Tour: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 1; i <= x; i++)
    {
        printf("                                                                   Enter the Age of Person %d : ", i);
        scanf("%d", &age);
        printf("\n");
        if (age <= 0)
        {
            printf("                                                                   Enter a Valid Age!");
            getch();
            BookGoa();
            break;
        }
        else
        {
            if (age <= 7)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    c = a * 18000;
    d = b * 22000;
    printf("                                                                   Total Amount For people with the age Less than or equal to 7: Rs. %d ", c);
    printf("\n");
    printf("\n");
    printf("                                                                   Total Amount For people with the age Greater than 7: Rs. %d ", d);
    printf("\n");
    printf("\n");
    printf("                                                                   Your GRAND TOTAL is: Rs. %d", c + d);
    printf("\n");
    printf("\n");
    printf("                                                                   Are You Sure to book the the TOUR JAMMU AND KASHMIR with your Total Amount Rs. %d ? (Enter Y for yes and N for No) : ", c + d);
    scanf("\n%c", &s);
    printf("\n");
    if (s == 'Y' || s == 'y')
    {
        printf("\n");
        printf("                                                                                    THANK YOU FOR BOOKING OUR TOURS!");
        FILE *fptr;
        fptr = fopen("packages.txt", "a");
        if (fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr, "\n\n");
        fprintf(fptr, "--> Name: %s\n", uname);
        fprintf(fptr, "--> Package Name: Goa - Mahabaleshwar\n");
        fprintf(fptr, "--> Duration: 4 days 3 nights\n");
        fprintf(fptr, "--> Starting Date: May 21 2021\n");
        fprintf(fptr, "--> Number of Persons: %d\n", x);
        fprintf(fptr, "--> Total Amount to be paid: %d Rs.\n", c + d);
        fprintf(fptr, "--> Booking Date: %s\n", __DATE__);
        fprintf(fptr, "--> Booking Time: %s\n", __TIME__);
        fclose(fptr);
        getch();
        MainMenu();
    }
    else
    {
        BookPackage();
    }
}

void ViewBookings()
{
    system("cls");
    int i, ans;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("                                                                                   V I E W  Y O U R  B O O K I N G S\n");
    printf("\n");
    printf("                                                                  //");
    for (i = 1; i < 40; i++)
    {
        printf("//");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                                                   1. View Your Packages Bookings\n");
    printf("\n");
    printf("                                                                   2. View Your Travels Bookings\n");
    printf("\n");
    printf("                                                                   3. Book a new Package\n");
    printf("\n");
    printf("                                                                   4. Book a new travels\n");
    printf("\n");
    printf("                                                                   5. Main Menu\n");
    printf("\n");
    printf("                                                                  ---------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                   Please select any option: ");
    scanf("%d", &ans);
    switch (ans)
    {
    case 1:
        ViewPackageBookings();
        break;
    case 2:
        ViewTravelsBookings();
        break;
    case 3:
        BookPackage();
        break;
    case 4:
        ViewRoutes();
        break;
    case 5:
        MainMenu();
        break;
    default:
        printf("                                                                   :( Invalid Input...");
        getch();
        ViewBookings();
        break;
    }
}
void ViewTravelsBookings()
{
    system("cls");
    char ch;
    FILE *fptr;
    fptr = fopen("travels.txt", "r");
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n\n");
    printf(" Press any key to continue....");
    getch();
    ViewBookings();
}

void ViewPackageBookings()
{
    system("cls");
    char ch;
    FILE *fptr;
    fptr = fopen("packages.txt", "r");
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n\n");
    printf(" Press any key to continue....");
    getch();
    ViewBookings();
}

void ExitScreen()
{
    system("cls");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("	         _/_/_/_/_/  _/                              _/            \n");
    printf("	            _/      _/_/_/      _/_/_/    _/_/_/    _/  _/         \n");
    printf("	           _/      _/    _/  _/    _/    _/    _/  _/_/            \n");
    printf("	          _/      _/    _/  _/    _/    _/    _/  _/  _/           \n");
    printf("	         _/      _/    _/    _/_/_/__/ _/    _/  _/    _/          \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("		         _/     _/                                       \n");
    printf("		          _/  _/    _/_/    _/    _/                     \n");
    printf("		            _/    _/    _/  _/    _/                     \n");
    printf("		            _/    _/    _/  _/    _/                     \n");
    printf("		           _/      _/_/      _/_/_/                     \n\n");
    exit(0);
}

int main()
{
    WelcomeScreen();
    loop_fun();
    return 0;
}