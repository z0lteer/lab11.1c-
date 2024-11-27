#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.1c++/lab11.1.c++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_findThirdDot)
        {

            string testFilename = "testFile.txt";
            ofstream testFile(testFilename);
            testFile << "������ �����.\n";
            testFile << "������ �����.\n";
            testFile << "�����. ��.\n";
            testFile.close();

            int lineIndex = 0, charIndex = 0;
            bool result = findThirdDot(testFilename, lineIndex, charIndex);


            Assert::IsTrue(result, L"����� ������ �� ��������.");
            Assert::AreEqual(3, lineIndex, L"������� ����� �����.");
            Assert::AreEqual(7, charIndex, L"������ ������� � �����.");
        }

        TEST_METHOD(Test_findThirdDot_NoDots)
        {

            string testFilename = "testFileNoDots.txt";
            ofstream testFile(testFilename);
            testFile << "���� ������ ���\n";
            testFile << "���� � ���\n";
            testFile << "�� ���� �����\n";
            testFile.close();

            int lineIndex = 0, charIndex = 0;
            bool result = findThirdDot(testFilename, lineIndex, charIndex);


            Assert::IsFalse(result, L"������� �� ��������� false, ���� ������ ����� �����.");
        }
    };
}