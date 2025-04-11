#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int MSSV;
    string name;
};

struct Node
{
    Student data;
    Node *next;
    Node *pre;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

Node *ArrayToSLL(Student *arr, int n)
{
    if (n == 0)
        return NULL;

    Node *head = new Node{arr[0], NULL};
    Node *curr = head;

    for (int i = 1; i < n; i++)
    {
        curr->next = new Node{arr[i], NULL};
        curr = curr->next;
    }
    return head;
}

Student *SLLToArray(Node *head, int &n)
{
    n = 0;
    Node *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }

    Student *arr = new Student[n];
    temp = head;
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    return arr;
}

LinkedList ArrayToSLLWithTail(Student *arr, int n)
{
    LinkedList list = {NULL, NULL};

    if (n == 0)
        return list;

    list.head = list.tail = new Node{arr[0], NULL};

    for (int i = 1; i < n; i++)
    {
        list.tail->next = new Node{arr[i], NULL};
        list.tail = list.tail->next;
    }
    return list;
}

Student *SLLWithTailToArray(LinkedList *list, int &n)
{
    n = 0;

    Node *head = list->head;
    Node *temp = head;
    while (temp)
    {
        n++;
        head = head->next;
    }

    Student *arr = new Student[n];
    temp = head;
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    return arr;
}
LinkedList ArrayToDLL(Student *arr, int n)
{
    LinkedList list = {NULL, NULL};

    if (n == 0)
        return list;

    list.head = list.tail = new Node{arr[0], NULL, NULL};

    for (int i = 1; i < n; i++)
    {
        list.tail->next = new Node{arr[i], NULL, list.tail};
        list.tail = list.tail->next;
    }
    return list;
}

LinkedList ArrayToCLL(Student *arr, int n)
{
    LinkedList list = {NULL, NULL};

    if (n == 0)
        return list;

    list.head = list.tail = new Node{arr[0], NULL};

    for (int i = 1; i < n; i++)
    {
        list.tail->next = new Node{arr[i], NULL};
        list.tail = list.tail->next;
    }
    list.tail->next = list.head;
    return list;
}

LinkedList ArrayToCDLL(Student *arr, int n)
{
    LinkedList list = {NULL, NULL};

    if (n == 0)
        return list;

    list.head = list.tail = new Node{arr[0], NULL, NULL};

    for (int i = 1; i < n; i++)
    {
        list.tail->next = new Node{arr[i], NULL, NULL};
        list.tail = list.tail->next;
    }
    list.tail->next = list.head;
    list.head->pre = list.tail;
    return list;
}

