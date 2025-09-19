# Utility Library

`clsUtil` is a simple, header-only C++ utility class that provides a collection of helper methods for randomization, swapping, shuffling, key/word generation, text encryption, and array handling. It is designed to simplify common programming tasks and extend C++ functionality without requiring external dependencies.

## Features

- **Randomization**
  - Generate random numbers within a range
  - Generate random characters, words, and license-key–style strings
  - Fill arrays with random numbers, words, or keys
  - Shuffle arrays

- **Swapping**
  - Swap values of different types (`int`, `double`, `bool`, `string`, `clsDate`)

- **Encryption**
  - Simple text encryption and decryption using character shifting

- **Formatting**
  - Generate tabs for indentation

## How to Use

Simply include the `clsUtil.h` header file in your project.  
All methods are **static**, so you can call them directly without creating an object.

## Example

```cpp
#include <iostream>
#include "clsUtil.h"

int main()
{
    // Seed the random number generator
    clsUtil::Srand();

    // --- Random Numbers ---
    int num = clsUtil::RandomNumber(1, 100);
    std::cout << "Random number: " << num << std::endl;

    // --- Random Words ---
    std::string word = clsUtil::GenerateWord(clsUtil::enCharType::SmallLetter, 5);
    std::cout << "Random word: " << word << std::endl;

    // --- License Keys ---
    std::string key = clsUtil::GenerateKey(clsUtil::enCharType::CapitalLetter);
    std::cout << "Random key: " << key << std::endl;

    // Generate multiple keys
    clsUtil::GenerateKeys(3);

    // --- Array Operations ---
    int arr[10];
    clsUtil::FillArrayWithRandomNumbers(arr, 10, 1, 50);

    std::cout << "Array before shuffle: ";
    for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    clsUtil::ShuffleArray(arr, 10);

    std::cout << "Array after shuffle: ";
    for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    // --- Encryption ---
    std::string secret = "Hello";
    std::string encrypted = clsUtil::EncryptText(secret, 3);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = clsUtil::DecryptText(encrypted, 3);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
