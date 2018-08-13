// Copyright 2018 <Author>

#include "typing_machine.h"

#define NULL_PTR	0
#define NULL_CHAR   0
#define HEAD_MARKER 1

TypingMachine::TypingMachine() {

  start = cursor = new Node(HEAD_MARKER);
  length = 0;
  return;
}

void TypingMachine::HomeKey() {
  cursor = start;
  return;
}

void TypingMachine::EndKey() {
  while (true){
	if (cursor->GetNextNode() == NULL_PTR)
	  break;
	cursor = cursor->GetNextNode();
  }
  return;
}

void TypingMachine::LeftKey() {
  if (cursor->GetData() != HEAD_MARKER)
    cursor = cursor->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
  if (cursor->GetNextNode() != NULL_PTR)
    cursor = cursor->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
  if ((key < 32) || (key > 126)) return false;
  if (length >= 100) return false;
  cursor = cursor->InsertNextNode(key);
  length++;
  return true;
}

bool TypingMachine::EraseKey() {

  if (cursor->GetData() == HEAD_MARKER)
    return false;
  cursor = cursor->GetPreviousNode();
  cursor->EraseNextNode();
  length--;
  return true;
}

std::string TypingMachine::Print(char separator) {

  std::string result;
  result.clear();
  
  Node* p = start;
  
  while (true){
	if (p->GetData() != HEAD_MARKER)
	  result += p->GetData();
	if ((p == cursor) && (separator != NULL_CHAR))
	  result += separator;

	if (p->GetNextNode() == NULL_PTR)
	  break;

	p = p->GetNextNode();
  }
  return result;
}
