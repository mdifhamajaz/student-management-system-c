#include <stdio.h>
#include <string.h>

typedef struct
{

    char name[34];
    int roll;
    float marks;
} student;

void printMenu();
int scanMenu();
void addStudent(student students[1000]);
void displayStudents(student students[1000]);
void searchStudent(student students[1000]);
void deleteStudent(student students[1000]);
void updateStudent(student students[1000]);
int count_of_std = 0;

int main()
{
    student students[1000];

    int choice;

    do
    {
        printMenu();
        choice = scanMenu();

        if (choice == 1)
        {
            if (count_of_std < 1000)
            {
                addStudent(students);
            }
            else
            {
                printf("Database is full, Can't add more students!\n");
            }
        }
        if (choice == 2)
        {
            displayStudents(students);
        }

        if (choice == 3)
        {
            searchStudent(students);
        }
        if (choice == 4)
        {
            deleteStudent(students);
        }
        if (choice == 5)
        {
            updateStudent(students);
        }

    } while (choice != 0);

    return 0;
}

void printMenu()
{

    printf("1: Add students\n");
    printf("2: Display students\n");
    printf("3: Search student\n");
    printf("4: Delete student\n");
    printf("5: Update student\n");
    printf("0: Exit\n");
}

int scanMenu()
{
    int choice;

    printf("Enter your choice serial no: ");
    scanf("%d", &choice);

    return choice;
}

void addStudent(student students[1000])
{

    char name[34];

    do
    {
        printf("Enter the name of student to add(Enter done if done adding): ");
        scanf(" %33s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }
        strcpy(students[count_of_std].name, name);
        int roll;
        do
        {
            int isDuplicate = 0;

            printf("Enter the roll no: ");
            scanf("%d", &roll);

            for (int i = 0; i < count_of_std; i++)
            {
                if (students[i].roll == roll)
                {
                    isDuplicate = 1;
                    printf("Roll already exists! Try again.\n");
                    break;
                }
            }

            if (!isDuplicate)
                break;

        } while (1);

        students[count_of_std].roll = roll;

        printf("Enter his marks(%%): ");
        scanf("%f", &(students[count_of_std].marks));

        count_of_std++;

        printf("Added %s\n", name);
    } while (strcmp(name, "done") != 0);
}

void displayStudents(student students[1000])
{
    char name[34];

    do
    {
        if (count_of_std != 0)
        {
            for (int i = 0; i < count_of_std; i++)
            {
                printf("%d: Name: %s\n", i + 1, students[i].name);
                printf("   Roll: %d\n", students[i].roll);
                printf("   Marks: %.2f %%\n", students[i].marks);
            }
        }
        else
        {
            printf("No students added yet!\n");
        }
        printf("\nEnter done to go to main menu: ");
        scanf(" %33s", name);
    } while (strcmp(name, "done") != 0);
}

void searchStudent(student students[1000])
{
    char name[34];
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;
        int index;
        printf("Enter the name of student you want to search(Enter done if done sarching): ");
        scanf(" %33s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i].name) == 0)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("Student is present in the database\n");
            printf("Name : %s\n", students[index].name);
            printf("Roll : %d\n", students[index].roll);
            printf("Marks: %.2f %%\n", students[index].marks);
        }
        else
        {
            printf("Student is not present in the database\n");
        }
    } while (strcmp(name, "done") != 0);
}
void deleteStudent(student students[1000])
{
    char name[34];
    char confirmation;
    int index = 0;
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;
        printf("Enter the name of student to delete(Enter done if done deleting): ");
        scanf(" %33s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i].name) == 0)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("Are you sure you want to permanently delete %s(y/n): ", name);
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {

                for (int i = index; i < count_of_std - 1; i++)
                {
                    students[i] = students[i + 1];
                }
                printf("%s deleted!\n\n", name);
                count_of_std--;
                break;
            }
            else
            {
                printf("Deletion cancelled\n");
            }
        }
        else
        {
            printf("Student is not present in the database\n");
        }

    } while (strcmp(name, "done") != 0);
}

void updateStudent(student students[1000])
{
    char name[34];
    char new_name[34];
    int new_roll;
    float new_marks;

    int index = 0;
    char confirmation;
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }
    do
    {
        int isFound = 0;

        printf("Enter the name of student you want to update(Enter done if done sarching): ");
        scanf(" %33s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i].name) == 0)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("Enter the new name: ");
            scanf(" %33s", new_name);

            do
            {
                int isDuplicate = 0;

                printf("Enter the new roll no: ");
                scanf("%d", &new_roll);

                for (int i = 0; i < count_of_std; i++)
                {
                    if (students[i].roll == new_roll && i != index)
                    {
                        isDuplicate = 1;
                        printf("Roll already exists! Try again.\n");
                        break;
                    }
                }

                if (!isDuplicate)
                    break;

            } while (1);

            printf("Enter the new marks(%%): ");
            scanf("%f", &new_marks);

            printf("\n----- Confirm Update -----\n");

            printf("OLD DATA:\n");
            printf("Name : %s\n", students[index].name);
            printf("Roll : %d\n", students[index].roll);
            printf("Marks: %.2f %%\n", students[index].marks);

            printf("\nNEW DATA:\n");
            printf("Name : %s\n", new_name);
            printf("Roll : %d\n", new_roll);
            printf("Marks: %.2f %%\n", new_marks);

            printf("\nConfirm update? (y/n): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {
                strcpy(students[index].name, new_name);
                students[index].roll = new_roll;
                students[index].marks = new_marks;
                printf("Update successful\n\n");
                break;
            }
            else
            {
                printf("Update operation cancelled!\n");
            }
        }
        else
        {
            printf("Student is not present in the database\n");
        }

    } while (strcmp(name, "done") != 0);
}