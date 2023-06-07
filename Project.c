#include <stdio.h>
#include <string.h>

typedef struct
{
    char Name[50];
    char Date[20];
    char DOB[20];
    char Address[100];
    double voter_id;
} Death_Record;

int num_records = 0;
Death_Record D[1000];

void Admin_panel();
void Guest_panel();
void View_Record();
void Search_Record();
void Add_Record();
void Modify_Record();
void Delete_Record();
void Save_Records();
void Load_Records();

int main()
{
    Load_Records();

    char admin;
    printf("\n\t\t\tWelcome to our Graveyard Management System\n\n\n");
    printf("\t\tAre you an Admin? If you are an Admin, press 'y'. Otherwise, press 'n': ");
    scanf(" %c", &admin);
    if (admin == 'y')
    {
        printf("\n\n\t\t\tWelcome to Admin Panel\n\n\n");
        Admin_panel();
    }
    else if (admin == 'n')
    {
        Guest_panel();
    }
    else
    {
        printf("\t\tSorry! You pressed the wrong key\n\n");
    }

    return 0;
}

void Admin_panel()
{
    char name[20];
    char password[20];
    int a;
    char n[20] = "ravid";
    char p[20] = "ravid123";
    printf("\n\t\tEnter your Name: ");
    scanf("%s", &name);
    printf("\n");
    printf("\t\tEnter password: ");
    scanf("%s", &password);
    int r1 = strcmp(name,n);
    int p1 = strcmp(password,p);
    if ( r1==0 && p1==0)
    {
        printf("\n\t\tWelcome to Admin Panel\n\n");
        printf("\t\t1. View Death Records\n");
        printf("\t\t2. Search Death Records\n");
        printf("\t\t3. Add Death Record\n");
        printf("\t\t4. Modify Death Record\n");
        printf("\t\t5. Delete Death Record\n");
        printf("\t\tPlease enter the number of the desired operation: ");
        scanf("%d", &a);
        printf("\n");
        if (a == 1)
        {
            View_Record();
        }
        else if (a == 2)
        {
            Search_Record();
        }
        else if (a == 3)
        {
            Add_Record();
        }
        else if (a == 4)
        {
            Modify_Record();
        }
        else if (a == 5)
        {
            Delete_Record();
        }
        else
        {
            printf("\t\tSorry! You pressed the wrong key\n\n");
        }
    }
    else
    {
        printf("\t\tInvalid ID or password\n\n");
    }
}

void Guest_panel()
{
    int n;
    printf("\n\t\t\tWelcome to Guest Panel\n\n");
    printf("\t\t1. View Death Records\n");
    printf("\t\t2. Search Death Records\n");
    printf("\t\tPlease enter the number of the desired operation: ");
    scanf("%d", &n);
    printf("\n");
    if (n == 1)
    {
        View_Record();
    }
    else if (n == 2)
    {
        Search_Record();
    }
    else
    {
        printf("\t\tSorry! You pressed the wrong key\n\n");
    }
}

void View_Record()
{
    if (num_records == 0)
    {
        printf("\t\tNo Records to Display.\n");
        return;
    }
    printf("\n\t\t----------------------------------- Death Records --------------------------------------------\n\n");
    printf("%-20s %-20s %-20s %-25s %-20s\n", "Name", "Date of Death", "Date of Birth", "Address", "Voter ID Number");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_records; i++)
    {
        printf("%-20s %-20s %-20s %-25s %-20lf\n", D[i].Name, D[i].Date, D[i].DOB, D[i].Address, D[i].voter_id);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}

void Search_Record()
{
    if (num_records == 0)
    {
        printf("\n\t\tNo Records to search\n");
        return;
    }
    char search_name[100];
    printf("\n\t\tEnter name to search for: ");
    scanf(" %[^\n]s", search_name);
    int found = 0;
    printf("\n\t\t----------------------------------- Search Results ----------------------------------------------\n\n");
    printf("%-20s %-20s %-20s %-25s %-20s\n", "Name", "Date of Death", "Date of Birth", "Address", "Voter ID Number");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_records; i++)
    {
        if (strcmp(D[i].Name, search_name) == 0)
        {
            printf("%-20s %-20s %-20s %-25s %-20lf\n", D[i].Name, D[i].Date, D[i].DOB, D[i].Address, D[i].voter_id);
            found = 1;
        }
    }
    printf("---------------------------------------------------------------------------------------------------\n");
    if (!found)
    {
        printf("\n\t\tNo records found.\n");
    }
}

void Add_Record()
{
    if (num_records == 1000)
    {
        printf("\n\t\tError: Maximum number of records reached.\n");
        return;
    }
    Death_Record new_record;
    printf("\n\t\tEnter name: ");
    scanf(" %[^\n]s", new_record.Name);
    printf("\t\tEnter date of death (DD/MM/YYYY): ");
    scanf(" %[^\n]s", new_record.Date);
    printf("\t\tEnter date of birth (DD/MM/YYYY): ");
    scanf(" %[^\n]s", new_record.DOB);
    printf("\t\tEnter address: ");
    scanf(" %[^\n]s", new_record.Address);
    printf("\t\tEnter Voter ID: ");
    scanf("%lf", &new_record.voter_id);
    D[num_records++] = new_record;
    printf("\n\t\tRecord added successfully.\n");

    Save_Records();
}

void Modify_Record()
{
    if (num_records == 0)
    {
        printf("\n\t\tNo records to modify.\n");
        return;
    }
    char search_name[100];
    printf("\n\t\tEnter the name of the record you want to modify: ");
    scanf(" %[^\n]s", search_name);
    int found = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (strcmp(D[i].Name, search_name) == 0)
        {
            printf("\n\t\tEnter the new name: ");
            scanf(" %[^\n]s", D[i].Name);
            printf("\t\tEnter the new date of death (DD/MM/YYYY): ");
            scanf(" %[^\n]s", D[i].Date);
            printf("\t\tEnter the new date of birth (DD/MM/YYYY): ");
            scanf(" %[^\n]s", D[i].DOB);
            printf("\t\tEnter the new address: ");
            scanf(" %[^\n]s", D[i].Address);
            printf("\t\tEnter the new Voter ID: ");
            scanf("%lf", &D[i].voter_id);
            printf("\n\t\tRecord modified successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\n\t\tNo records found.\n");
    }

    Save_Records();
}

void Delete_Record()
{
    if (num_records == 0)
    {
        printf("\n\t\tNo records to delete.\n");
        return;
    }
    char search_name[100];
    printf("\n\t\tEnter the name of the record you want to delete: ");
    scanf(" %[^\n]s", search_name);
    int found = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (strcmp(D[i].Name, search_name) == 0)
        {
            for (int j = i; j < num_records - 1; j++)
            {
                D[j] = D[j + 1];
            }
            num_records--;
            printf("\n\t\tRecord deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\n\t\tNo records found.\n");
    }

    Save_Records();
}

void Save_Records()
{
    FILE *file = fopen("records.txt", "w");
    if (file == NULL)
    {
        printf("\n\t\tError opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num_records; i++)
    {
        fprintf(file, "%s;%s;%s;%s;%lf\n", D[i].Name, D[i].Date, D[i].DOB, D[i].Address, D[i].voter_id);
    }

    fclose(file);
    printf("\n\t\tRecords saved to file.\n");
}

void Load_Records()
{
    FILE *file = fopen("records.txt", "r");
    if (file == NULL)
    {
        printf("\n\t\tNo records file found. Starting with an empty database.\n");
        return;
    }

    num_records = 0;
    char line[200];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%[^;];%[^;];%[^;];%[^;];%lf\n", D[num_records].Name, D[num_records].Date, D[num_records].DOB, D[num_records].Address, &D[num_records].voter_id);
        num_records++;
    }

    fclose(file);
    printf("\n\t\tRecords loaded from file.\n");
}
