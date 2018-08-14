// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeConstructorTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }
  
  static void MultipleNodeConstructorTest(){
	Node* nodeHeap[10];
	for (int i = 0; i < 10; i++){
	  nodeHeap[i] = new Node(i + '0');
	  ASSERT_EQ(nodeHeap[i]->GetData(), i + '0');
	}

	for (int i = 0; i < 10; i++){
	  delete nodeHeap[i];
	}
  }

public:
  static void RunTest() {
	SingleNodeConstructorTest();
	MultipleNodeConstructorTest();
  }
};

class InsertNodeTestSuite
{
private:
  static void InsertPreviousNodeTest(){
	Node* entryNode = new Node('0');
	Node* appendedNode = entryNode->InsertPreviousNode('a');
	EXPECT_TRUE(appendedNode->GetData() == 'a');
	ASSERT_NE(appendedNode->GetNextNode(), (Node*)NULL);
	EXPECT_TRUE(appendedNode->GetNextNode()->GetData() == '0');

	delete entryNode;
	delete appendedNode;
  }

  static void InsertNextNodeTest(){
	  Node* entryNode = new Node('0');
	  Node* appendedNode = entryNode->InsertNextNode('a');
	  EXPECT_TRUE(appendedNode->GetData() == 'a');
	  ASSERT_NE(appendedNode->GetPreviousNode(), (Node*)NULL);
	  EXPECT_TRUE(appendedNode->GetPreviousNode()->GetData() == '0');

	  delete entryNode;
	  delete appendedNode;
  }

public:
  static void RunTest() {
	InsertPreviousNodeTest();
	InsertNextNodeTest();
    // add more..
  }
};

class EraseNodeTestSuite
{
private:
	static void ErasePreviousNodeTest(){
		Node* entryNode = new Node('0');
		Node* appendedNode1 = entryNode->InsertPreviousNode('a');
		Node* appendedNode2 = appendedNode1->InsertPreviousNode('b');
		
		EXPECT_TRUE(appendedNode1->GetData() == 'a');
		EXPECT_TRUE(appendedNode2->GetData() == 'b');

		entryNode->ErasePreviousNode();
		EXPECT_TRUE(entryNode->GetPreviousNode()->GetData() == 'b');


		delete entryNode;
		delete appendedNode2;
	}

	static void EraseNextNodeTest(){
		Node* entryNode = new Node('0');
		Node* appendedNode1 = entryNode->InsertNextNode('a');
		Node* appendedNode2 = appendedNode1->InsertNextNode('b');

		EXPECT_TRUE(appendedNode1->GetData() == 'a');
		EXPECT_TRUE(appendedNode2->GetData() == 'b');
		

		entryNode->EraseNextNode();
		EXPECT_TRUE(entryNode->GetNextNode()->GetData() == 'b');


		delete entryNode;
		delete appendedNode2;
	}

public:
	static void RunTest() {
		ErasePreviousNodeTest();
		EraseNextNodeTest();
		// add more..
	}
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  InsertNodeTestSuite::RunTest();
  EraseNodeTestSuite::RunTest();
  // add more..
}