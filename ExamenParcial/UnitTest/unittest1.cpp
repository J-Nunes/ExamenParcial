#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ExamenParcial/DoubleList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(DoubleListConstr)
		{
			DoubleList<int> double_list1;

			Assert::IsTrue(double_list1.count() == 0);
			Assert::IsFalse(double_list1.del(double_list1.getNode(0)) == true);
			Assert::IsNull(double_list1.getNode(3));
		}

		TEST_METHOD(DoubleListcount)
		{
			DoubleList<int> double_list1;

			double_list1.add(8);
			double_list1.add(18);

			Assert::IsTrue(double_list1.count() == 2);
			Assert::IsTrue(double_list1.del(double_list1.getNode(0)) == true);
			Assert::IsTrue(double_list1.delAll() == true);
		}

		TEST_METHOD(DoubleListGetNode)
		{
			DoubleList<int> double_list1;

			double_list1.add(10);

			Assert::IsTrue(double_list1.del(double_list1.getNode(0)) == true);
			Assert::IsTrue(double_list1.count() == 0);
		}

		TEST_METHOD(DoubleListdel)
		{
			DoubleList<int> double_list1;

			double_list1.add(28);

			Assert::IsTrue(double_list1.del(double_list1.getNode(0)) == true);
			Assert::IsTrue(double_list1.count() == 0);

			double_list1.add(-2);
			double_list1.add(9);
			double_list1.add(30);
			double_list1.add(-58);

			Assert::IsFalse(double_list1.del(double_list1.getNode(-1)) == true);
			Assert::IsTrue(double_list1.del(double_list1.getNode(3)) == true);
			Assert::IsTrue(double_list1.del(double_list1.getNode(2)) == true);

			Assert::IsTrue(double_list1.count() == 2);

			Assert::IsTrue(double_list1.del(double_list1.getNode(1)) == true);
			Assert::IsTrue(double_list1.del(double_list1.getNode(0)) == true);

			Assert::IsTrue(double_list1.count() == 0);

		}

		TEST_METHOD(DoubleListdelAll)
		{
			DoubleList<int> double_list1;

			double_list1.add(-12);
			double_list1.add(29);
			double_list1.add(-36);
			double_list1.add(4);

			Assert::IsTrue(double_list1.count() == 4);
			Assert::IsTrue(double_list1.delAll() == true);
			Assert::IsTrue(double_list1.count() == 0);
		}

	};

};