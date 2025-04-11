#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node *pre;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

void MangDongCoThuTu(int *&arr, int &n, char c, int pos)
{
    if (pos < 0 || pos > n)
        return;
    int *newArr = new int[n + 1];
    for (int i = 0; i < pos; i++)
        newArr[i] = arr[i];
    newArr[pos] = c;
    for (int i = pos + 1; i <= n; i++)
        newArr[i] = arr[i - 1];
    delete[] arr;
    arr = newArr;
    n++;
}

void XauCoTTKhongCTCuoi(Node *&head, char c, int pos)
{
    Node *newNode = new Node{c, NULL};
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *curr = head;
    for (int i = 0; curr && i < pos - 1; i++)
        curr = curr->next;
    if (curr)
    {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void XauCoTTCoCTCuoi(LinkedList &list, char c, int pos)
{
    Node *newNode = new Node{c, NULL};
    if (pos == 0)
    {
        newNode->next = list.head;
        list.head = newNode;
        if (!list.tail)
            list.tail = newNode;
        return;
    }
    Node *curr = list.head;
    for (int i = 0; curr && i < pos - 1; i++)
        curr = curr->next;
    if (curr)
    {
        newNode->next = curr->next;
        curr->next = newNode;
        if (!newNode->next)
            list.tail = newNode;
    }
}

void Xau_c1(LinkedList &list, char c, int pos)
{
    Node *newNode = new Node{c, NULL};
    Node *curr = list.head;
    for (int i = 0; curr && i < pos - 1; i++)
        curr = curr->next;
    if (pos == 0)
    {
        newNode->next = list.head;
        list.head = newNode;
    }
    else if (curr)
    {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void Xau_c2(LinkedList &list, char c, int pos)
{
    Node *newNode = new Node{c, NULL};
    if (pos == 0)
    {
        newNode->next = list.head;
        list.head = newNode;
        if (!list.tail)
            list.tail = newNode;
        return;
    }
    Node *curr = list.head;
    for (int i = 0; curr && i < pos - 1; i++)
        curr = curr->next;
    if (curr)
    {
        newNode->next = curr->next;
        curr->next = newNode;
        if (!newNode->next)
            list.tail = newNode;
    }
}

struct LinkedListSpecial
{
    Node *head;
    Node **tail;
};

void Xau_d(LinkedListSpecial &list, char c, int pos)
{
    Node *newNode = new Node{c, NULL};

    if (pos == 0)
    {
        newNode->next = list.head;
        list.head = newNode;
        if (!*list.tail)
            *list.tail = newNode;
        return;
    }
    
    Node *curr = list.head;
    for (int i = 0; curr && i < pos - 1; i++)
        curr = curr->next;

    if (curr)
    {
        newNode->next = curr->next;
        curr->next = newNode;
        if (!newNode->next)
            *list.tail = newNode;
    }
}
