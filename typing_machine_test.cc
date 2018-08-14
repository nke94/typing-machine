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


class TmNavigatorTestSuite
{
private:
	static void StepNavigation() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');

		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("ab|c"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|bc"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));

		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|bc"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("ab|c"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));

	}

	static void HotKeyNavigation() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');

		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));

		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}

public:
	static void RunTest() {
		StepNavigation();
		HotKeyNavigation();
		// add more..
	}
};

class TmEraseTestSuite
{
private:
	static void EraseKey() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');

		EXPECT_TRUE(tm.EraseKey() == true);
		EXPECT_TRUE(tm.EraseKey() == true);
		EXPECT_TRUE(tm.EraseKey() == true);
		EXPECT_TRUE(tm.EraseKey() == false);
	}
public:
  static void RunTest() {
	  EraseKey();
    // add more..
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmAddKeyTestSuite::RunTest();
  TmNavigatorTestSuite::RunTest();
  TmEraseTestSuite::RunTest();
  // add more..
}