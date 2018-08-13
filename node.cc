// Copyright 2018 <Author>

#include "node.h"


#ifndef NULL
#define NULL 0
#endif

Node::Node(char data) {
  prev = next = NULL;
  internal = data;
  return;
}

char Node::GetData() {
  return internal;
}

Node* Node::GetPreviousNode() {
  return (Node*)prev;
}

Node* Node::GetNextNode() {
  return (Node*)next;
}

Node* Node::InsertPreviousNode(char data) {
  Node* currNode = new Node(data);
  Node* prevNode = prev;
  Node* nextNode = (Node*)this;

  currNode->prev = prevNode;
  currNode->next = nextNode;

  if (prevNode != NULL)
	  prevNode->next = currNode;
  if (nextNode != NULL)
	  nextNode->prev = currNode;

  return currNode;
}

Node* Node::InsertNextNode(char data) {

  Node* currNode = new Node(data);
  Node* prevNode = (Node*)this;
  Node* nextNode = next;

  currNode->prev = prevNode;
  currNode->next = nextNode;

  if (prevNode != NULL)
    prevNode->next = currNode;

  if (nextNode != NULL)
    nextNode->prev = currNode;

  return currNode;
}

bool Node::ErasePreviousNode() {

  Node* currNode = prev;
  if (currNode == NULL) return false;

  Node* prevNode = currNode->prev;
  Node* nextNode = (Node*)this;

  if (prevNode != NULL) prevNode->next = nextNode;
  if (nextNode != NULL) nextNode->prev = prevNode;
  
  if (currNode != NULL)
    delete currNode;
  return true;
}

bool Node::EraseNextNode() {
  Node* currNode = next;
  if (currNode == NULL) return false;

  Node* prevNode = (Node*)this;
  Node* nextNode = currNode->next;

  if (prevNode != NULL)
    prevNode->next = nextNode;
  if (nextNode != NULL)
    nextNode->prev = prevNode;

  if(currNode != NULL)
    delete currNode;
  return true;
}
