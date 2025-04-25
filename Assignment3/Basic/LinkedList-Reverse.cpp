#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void insert_node(SinglyLinkedList* list,int node_data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(node_data);
    if (!list->head) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }

    list->tail = newNode;
}

void reverseLinkedList(SinglyLinkedList* list){
    SinglyLinkedListNode* cur = list->head;
    SinglyLinkedListNode* next = nullptr;
    SinglyLinkedListNode* pre = nullptr;
    while(cur){
        next = cur->next;   // Lưu node kế tiếp
        cur->next = pre;    // Đảo ngược liên kết
        pre = cur;          // Dời pre và cur
        cur = next;         // tới trước
    }
    list->tail = list->head;
    list->head = pre;
}

void printLinkedList(SinglyLinkedList* list){
    SinglyLinkedListNode* cur = list->head;
    while(cur){
        cout<< cur->data << ' ';
        cur = cur->next;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r"))
    {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}