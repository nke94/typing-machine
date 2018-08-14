// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
	ASSERT_EQ(tm.Print(0), std::string(""));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    // add more..
  }
};


class TmAddKeyTestSuite
{
private:
	static void typeNormalCharacter() {
		TypingMachine tm;
		tm.TypeKey('a');
		ASSERT_EQ(tm.Print('|'), std::string("a|"));
	}

	static void typeMaxCharacter() {
		TypingMachine tm;

		for (int i = 0; i < 100; i++)
			tm.TypeKey('a');
		
		ASSERT_EQ(tm.TypeKey('a'), 0);

	}

	static void typeabNormalCharacter() {
		TypingMachine tm;		
		ASSERT_EQ(tm.TypeKey(31), 0);
	}


public:
	static void RunTest() {
		typeNormalCharacter();
		typeMaxCharacter();
		typeabNormalCharacter();
		// add more..
	}
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmAddKeyTestSuite::RunTest();
  // add more..
}