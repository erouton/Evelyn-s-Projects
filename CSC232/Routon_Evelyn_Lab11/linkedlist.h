// A class template for holding a linked list.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
class LinkedList{
private:
   // Declare a structure for the list
   struct ListNode{
      T value;
      struct ListNode *next;
   }; 

   ListNode *head;   // List head pointer

public:
   LinkedList()   // Constructor
      { head = nullptr; }
   ~LinkedList(){
      ListNode *nodeptr, *nextnode;
      nodeptr = head;
      while(nodeptr != nullptr){
         nextnode = nodeptr->next;
         delete nodeptr;
         nodeptr = nextnode;
      }
   } // Destructor

   void appendNode(T num){
      ListNode *newNode, *nodeptr;
      newNode = new ListNode;
      newNode->value = num;
      newNode->next = nullptr;

      if(!head){
         head = newNode;
      }else{
         nodeptr = head;
         while(nodeptr->next){
            nodeptr = nodeptr->next;
         }
         nodeptr->next = newNode;}}

   void insertNode(T num){
      ListNode *newNode, *nodeptr, *prevnode = nullptr;
      newNode = new ListNode;
      newNode->value = num;
      if(!head){
         head = newNode;
         newNode->next = nullptr;
      }else{
         nodeptr = head;
         while(nodeptr != nullptr && nodeptr->value < num){
            prevnode = nodeptr;
            nodeptr = nodeptr->next;
         }
         if(prevnode == nullptr){
            head = newNode;
            newNode->next = nodeptr;
         }else{
            prevnode->next = newNode;
            newNode->next = nodeptr;}}}

   void deleteNode(T num){
      ListNode *prevnode, *nodeptr;
      if(!head){
         return;
      }else{
         if(head->value == num){
            nodeptr = head->next;
            delete head;
            head = nodeptr;
         }else{
            nodeptr = head;
            while(nodeptr != nullptr && nodeptr->value != num){
               prevnode = nodeptr;
               nodeptr = nodeptr->next;}
            if(nodeptr){
               prevnode->next = nodeptr->next;
               delete nodeptr;}}}}

   int search(T x){
      ListNode *nodeptr;
      nodeptr = head;
      int sval = 0, total = 0;
      while(nodeptr){
         sval++;
         if(x == nodeptr->value){
            return sval;
         }else{
            total++;
         }
         nodeptr = nodeptr->next;
      }
      if(total == numNodes()){sval = -1;}
      return sval;
   }

   void print(){
      ListNode *nodeptr;
      nodeptr = head;
      while(nodeptr){
         cout << nodeptr->value << "  ";
         nodeptr = nodeptr->next;
         }cout<<endl;}

   void removeByPos(int val){
      ListNode *prevnode, *nodeptr;
      int count = 0;
      if(!head || val > numNodes()){
         return;
      }else{
         if(val == 0){
            nodeptr = head->next;
            delete head;
            head = nodeptr;
         }else{
            nodeptr = head;
            while(count != val){
               prevnode = nodeptr;
               nodeptr = nodeptr->next;
               count++;
            }if(nodeptr){
               prevnode->next = nodeptr->next;
               delete nodeptr;
            }
         }
      }
   }

   T getTotal(){
      ListNode *nodeptr;
      nodeptr = head;
      T total;
      while(nodeptr){
         total += nodeptr->value;
         nodeptr = nodeptr->next;}

      return total;}

   int numNodes(){
      ListNode *nodeptr;
      nodeptr = head;
      int total = 0;
      while(nodeptr){
         total++;
         nodeptr = nodeptr->next;}

      return total;}

   T getAverage(){return getTotal()/numNodes();}

   T getLargest(){
      ListNode *nodeptr;
      nodeptr = head;
      T largest;
      while(nodeptr){
         if(nodeptr->value > largest)
            largest = nodeptr->value;
         nodeptr = nodeptr->next;
      }
      return largest;}

   int getLargestPosition(){
      ListNode *nodeptr;
      nodeptr = head;
      int position = 0;
      while(nodeptr->value < getLargest()){
         position++;
         nodeptr = nodeptr->next;
      }
      return position;}

   T getSmallest(){
      ListNode *nodeptr, *prevnode;
      nodeptr = head;
      T smallest;
      smallest = nodeptr->value;
      while(nodeptr && nodeptr->next != nullptr){
         nodeptr = nodeptr->next;
         if(smallest > nodeptr->value)
            smallest = nodeptr->value;
      }

      return smallest;}

   int getSmallestPosition(){
      ListNode *nodeptr;
      nodeptr = head;
      int position = 0;
      while(getSmallest() < nodeptr->value){
         position++;
         nodeptr = nodeptr->next;}
      
      return position;}

 };

#endif