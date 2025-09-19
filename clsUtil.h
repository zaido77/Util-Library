#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
    enum enCharType { 
        SmallLetter = 1, CapitalLetter = 2, 
        Digit = 3, MixChars = 4, SpecialCharacter = 5 
    };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
        return rand() % (To - From + 1) + From;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == enCharType::MixChars)
            CharType = (enCharType)RandomNumber(1, 3);

        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
        default:
            return char(RandomNumber(65, 90));
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";

        for (short i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }

        return Word;
    }

    static string GenerateKey(enCharType CharType = enCharType::CapitalLetter)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType = enCharType::CapitalLetter)
    {
        for (short i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key[" << i << "] : " << GenerateKey(CharType) << "\n";
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (short i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
    {
        for (short i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (short i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (short i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(0, arrLength - 1)],
                arr[RandomNumber(0, arrLength - 1)]); // Random(1, arrLength) - 1
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (short i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(0, arrLength - 1)],
                arr[RandomNumber(0, arrLength - 1)]); // Random(1, arrLength) - 1
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (short i = 0; i < NumberOfTabs; i++)
            t += "\t";

        return t;
    }

    static string EncryptText(string Text, short EncryptionKey)
    {
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = char(int(Text[i]) + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = char(int(Text[i]) - EncryptionKey);
        }

        return Text;
    }

};
