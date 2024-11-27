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
            testFile << "Перший рядок.\n";
            testFile << "Другий рядок.\n";
            testFile << "Третій. ще.\n";
            testFile.close();

            int lineIndex = 0, charIndex = 0;
            bool result = findThirdDot(testFilename, lineIndex, charIndex);


            Assert::IsTrue(result, L"Третя крапка не знайдена.");
            Assert::AreEqual(3, lineIndex, L"Невірний номер рядка.");
            Assert::AreEqual(7, charIndex, L"Невірна позиція у рядку.");
        }

        TEST_METHOD(Test_findThirdDot_NoDots)
        {

            string testFilename = "testFileNoDots.txt";
            ofstream testFile(testFilename);
            testFile << "Немає крапок тут\n";
            testFile << "Немає і тут\n";
            testFile << "Ще один рядок\n";
            testFile.close();

            int lineIndex = 0, charIndex = 0;
            bool result = findThirdDot(testFilename, lineIndex, charIndex);


            Assert::IsFalse(result, L"Функція має повернути false, якщо крапок менше трьох.");
        }
    };
}