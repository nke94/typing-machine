// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {

 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();

 public:
  Node* prev;
  Node* next;
  char internal;
};

#endif  // NODE_H_
