                                        /*                Menu Driven Program for Library Managment              */
//Team Members Group 8
/*
Khushi Suresh Muddi - 211IT032
Harsha S            - 211IT024
Chirag Rajput       - 211IT018
Achyut Agarwal      - 211IT003
Rishav Raja         - 211IT052
*/

//NOTE : Password for Librarian menu is 'librarian@123' (all small letters)


#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
struct qNode
{
    int data;
    struct qNode *next;
};
struct queue
{
    struct qNode *front, *rear;
};
// with the help of dynamic memory allocation we allocate space for the req number of nodes of the inner linked list
struct qNode *newNode(int k)
{
    struct qNode *temp = (struct qNode *)malloc(sizeof(struct qNode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
int isEmpty(struct queue *pq)
{
    if (pq->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int count = 0;
int size()
{
    int cntr = count;
    return count;
}
// we also allocate space for the outer node which is single and is intiated in the main function
struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add students to the queue
void enqueue(struct queue *pq, int k)
{
    struct qNode *nw = newNode(k);

    if (pq->rear == NULL)
    {
        pq->front = pq->rear = nw;
    }
    pq->rear->next = nw;
    pq->rear = nw;
    cout << "\n\t\tStudent with ID"<<k<<" successfully added to queue" << endl;
    count++;
}
// Function to remove students from the queue
void dequeue(struct queue *pq)
{
    if (isEmpty(pq))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct qNode *temp;
        temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
        cout << "Data successfully poped" << endl;
        count--;
    }
}
// Function to display the elements of the queue
void display_Info(struct qNode *p, struct queue *pq)
{
    cout << "The Elements of the queue are" << endl;
    int i = 0;
    while (i < count)
    {
        cout << pq->front->data << endl;
        pq->front = pq->front->next;
        i++;
    }
}
// student structure to store details of the student in the form of linked list
struct Student
{
public:
    int id;
    char name[100];
    int roll_no;
    int id_of_book_issued;
    struct Student *next;
};
// function to input the student details
void readInfo(struct Student *p)
{

    cout << "\t\tEnter the Student ID :";
    cin >> p->id;
    cout << "\t\tEnter the Student Name:";
    cin >> p->name;
    cout << "\t\tEnter the Student Roll no :";
    cin >> p->roll_no;
    p->id_of_book_issued = 0;
}
// function to allocate memory for the created student
struct Student *getNode()
{
    return (struct Student *)malloc(sizeof(struct Student));
}
struct Student *createStudent(struct Student *first)
{
    struct Student *nw = getNode();
    nw->next = NULL;
    struct Student *cur;
    cur = first;
    int flag = 0;
    readInfo(nw);
    if (first == NULL)
    {

        first = nw;
    }
    else
    {
        while (cur->next != NULL)
        {
            if (cur->id == nw->id)
            {
                flag = 1; // flag to check whether the id is repeated or not

                cout << "\t\tThe ID you entered is already allocated to another student" << endl;
                break;
            }
            cur = cur->next;
        }
        if (cur->id == nw->id)
        {
            // cout << "\t\tThe ID you entered is already allocated to another student" << endl;
            flag = 1;
        }
        if (flag != 1)
        {
            cur->next = nw;
        }
    }
    return first;
}
// Function to add books to student i.e when student borrows a book
int add_data(struct Student *first, int id_book, int id_student)
{
    int present =0;
    int flag = 0;
    struct Student *cur;
    cur = first;
    if (first == NULL)
    {
        cout << "\t\tConsider adding students" << endl;
    }

    for (cur = first; cur != NULL; cur = cur->next)
    {
        if (cur->id == id_student)
        {
            present=1;
            if (cur->id_of_book_issued == 0)
            {
                cur->id_of_book_issued = id_book;
            }
            else
            {
                flag = 1;
                cout << "\t\tA Book is already issued please return it first" << endl;
            }
        }

       
    }
   
    if(present=0){
        cout<<"Student ID not present";
    }
    return flag;
}
// Function to remove books from student i.e when student returns a book
void delete_data(struct Student *first, int id_book, int id_student)
{
    struct Student *cur;
    cur = first;
    for (cur = first; cur != NULL; cur = cur->next)
    {
        if (cur->id == id_student)
        {
            // cout<<"krigj";
            cur->id_of_book_issued = 0;
        }
    }
}
// Function to display information of all the students present if requested
void displayInfo(struct Student *first)
{
    struct Student *cur;
    for (cur = first; cur != NULL; cur = cur->next)
    {
        cout << "\t\tID of the student :" << cur->id << "\t\tName: " << cur->name << "\t\tID of book issued: " << cur->id_of_book_issued << endl;
    }
}
// Function to display information of a specific student based on the ID provided
void displayInfo_student(struct Student *first, int id_student)
{
    struct Student *cur;

    for (cur = first; cur != NULL; cur = cur->next)
    {
        if (cur->id == id_student)
        {
            // cout<<"hellooooooo";
            cout << "\n\t\tID of the student :" << cur->id << "\n\t\tName: " << cur->name << "\n\t\tRoll Number of the student : "<<cur->roll_no<<"\n\t\tID of book issued: " << cur->id_of_book_issued << endl;
        }
    }
}
// Book structure to manipulate information of the books present
struct Book
{
    struct Book *left, *right;
    int id;
    char name[100];
    char author[100];
    int prize;
};

void displayinfo12(struct Book *p)
{
    cout << "\t\tThe ID of the book is: " << p->id << "\t\tThe Name of the book is " << p->name << "\t\tThe Author of the book is: " << p->author << "\t\tThe Prize of the book is " << p->prize;
}

void readInfo_book(struct Book *p)
{
    cout << "\t\tEnter name of the book :\n\t\t";
    cin >> p->name;
    cout << "\t\tEnter author of the book :\n\t\t";
    cin >> p->author;
    cout << "\t\tEnter prize of book :\n\t\t";
    cin >> p->prize;
}
struct Book *get_Node()
{
    return (struct Book *)malloc(sizeof(struct Book));
}
struct Book *minValueNode(struct Book *p)
{
    struct Book *current = p;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
// Insert Books to the tree based on the ID
struct Book *insert(struct Book *root, int id)
{
    struct Book *nw = get_Node();
    nw->id = id;
    nw->left = NULL;
    nw->right = NULL;
    readInfo_book(nw);
    struct Book *par;
    if (root == NULL)
    {
        return nw;
    }
    par = root;
    while (1)
    {
        if (nw->id <= par->id)
        {
            if (par->left != NULL)
            {
                par = par->left;
            }
            else
            {
                par->left = nw;
                break;
            }
        }

        else
        {
            if (par->right != NULL)
            {
                par = par->right;
            }
            else
            {
                par->right = nw;
                break;
            }
        }
    }

    return root;
}
// inorder traversal to find and display the book
void inorder(struct Book *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        displayinfo12(root);
        cout << endl;
        inorder(root->right);
    }
}

struct Book *delete_node(struct Book *root, int id, int Stu_id)
{

    if (root == NULL)
    {
        struct queue *q = createQueue();
        struct qNode *data;
        char ch;
        cout << "\t\tBook already issued/not present" << endl;
        cout << "\t\tDo you wish to wait for the book?(y/n)" << endl;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            enqueue(q, Stu_id);
        }
        return root;
    }

    if (id < root->id)
    {
        // cout<<"hello"<<endl;

        root->left = delete_node(root->left, id, Stu_id);
    }

    else if (id > root->id)
    {
        root->right = delete_node(root->right, id, Stu_id);
    }

    else
    {
        if (root->left == NULL and root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL)
        {
            struct Book *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            // cout<<"hello"<<endl;
            struct Book *temp = root->left;
            free(root);
            return temp;
        }

        struct Book *temp = minValueNode(root->right);

        //  cout<<"helslo"<<endl;

        root->id = temp->id;
        root->right = delete_node(root->right, temp->id, Stu_id);
    }
    return root;
}

struct Student *first = NULL;
// Library Class for when the user enters the program, he has to option to choose between the student and librarian and if librarian is choosen then he has to enter a password to enter the librarian side
class Lib
{
public:
    struct Book *root = NULL;
    struct Book *cur;
    // student can only see the books and his information through the help of his ID
    void student()
    {

        int ans;
        int option;

        int i;
        while (1)
        {
            cout << "\t\tEnter an operation :\n\t\t1)Display all the books available \n\t\t2)Display my information\n\t\t3) Exit to main menu\n\t\t ";
            cin >> ans;
            switch (ans)
            {
            case 1:
            {
                inorder(root);
            }
            break;
            case 2:
            {
                int s_id;
                cout << "\t\tEnter your ID : \n\t\t";
                cin >> s_id;
                displayInfo_student(first, s_id);
            }
            break;
            case 3:
            {
                get();
                break;
            }
            default:
                cout << "\t\tInvalid choice. Please try again." << endl;
            }
        }
    };
    // Librarian part which includes adding books, issuing, returning, displaying, adding students, displaying them and then finally returning back to the main menu
    void librarian()
    {
        int ans;
        int option;
        int id_stu;
        struct queue *q = createQueue();
        struct qNode *data;
        int i;
        int total = 0;
        int count = 0;
        cout << "\n\t\t***** WELCOME LIBRARIAN *****\n";
        cout << "\n\t\t>>Please Choose One Option:\n";

        while (1)
        {
            cout << "\t\tEnter an operation :" << endl
                 << "\t\t1- Add more books \n\t\t2- Issue a book \n\t\t3-  Return a book \n\t\t4-  Display all book that are available for issuing \n\t\t5-  Add New student\n\t\t6-  Display all Students\n\t\t7-  Exit to main menu\n\t\t";
            cin >> ans;
            switch (ans)
            {
            case 1:
            {
                int n;
                cout << "\t\tHow many books would you like to add today? ";
                cin >> n;
                for (int i = 1 + total; i <= n + total; i++)
                {
                    root = insert(root, i); // the id for each book is required to be unique as it is considered as the main parameter for tree travesal and other comparing operations
                    count++;
                    cout << endl;
                }
                total = total + count;
            }
            break;
            case 2:
            {
                int id;
                cout << "\t\tEnter Book ID of the book to be issued: ";
                cin >> id;
                cout << "\t\tEnter the ID of the student that the book is being issued to :" << endl;
                cin >> id_stu;
                root = delete_node(root, id, id_stu);
                int flag = add_data(first, id, id_stu);
                //    cout<<flag;

                displayInfo_student(first, id_stu);
            }

            break;
            case 3:
            {
                int id;
                cout << "\t\tEnter Book ID of the book to be returned:\n\t\t";
                cin >> id;
                cout << "\t\tEnter the ID of the student that the book is being returned by :\n\t\t";
                cin >> id_stu;
                root = insert(root, id);
                delete_data(first, id, id_stu);
                displayInfo_student(first, id_stu);
            }
            break;

            case 4:
            {
                inorder(root);
            }
            break;
            case 5:
            {
                int sn;
                cout << "\n\n\t\tHow many student details do you want to enter?\n\t\t";
                cin >> sn; // the id for each student is required to be unique as it is considered as the main parameter for list travesal and other comparing operations
                for (int i = 0; i < sn; i++)
                {
                    cout << "\t\tEnter details of student " << i + 1 << " " << endl;
                    first = createStudent(first);
                }
                // displayInfo(first);
            }
            break;
            case 6:
            {
                displayInfo(first);
            }
            break;
            case 7:
            {
                cout << "\t\tExiting to main menu...." << endl;
                get();
            }
            break;
            default:
                cout << "\t\tInvalid choice. Please try again." << endl;
            }
        }
    }
    // to verify the password and proceed to librarian menu
    void pass()
    {
        int i = 0, val, rtry;
        char passw[30] = {"librarian@123"};
        char ch[30];
        cout << "\n\t\tEnter Password : ";
        cin >> ch;
        val = strcmp(ch, passw);
        if (val == 0)
        {
            cout << "\t\tLogged in....." << endl;
            librarian();
        }
        else
        {
            cout << "\t\tlogin failed...." << endl;
            cout << "\t\tEnter 1 to retry" << endl;
            cin >> rtry;
            if (rtry == 1)
            {
                pass();
            }
        }
    }
    void get()
    {
        int i;
        cout << "\n\t\t***** WELCOME TO E-LIBRARY *****\n";
        cout << "\n\t\t>>Please Choose Any Option To proceed \n";
        cout << "\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout << "\n\t\tEnter your choice : ";
        cin >> i;
        if (i == 1)
        {
            system("cls");
            student();
        }
        else if (i == 2)
        {
            pass();
        }
        else if (i == 3)
        {
            exit(0);
        }
        else
        {
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            get();
        }
    }
};
// main function starts here
int main()
{
    Lib obj;
    char ans;
    int option;
    obj.get();
}