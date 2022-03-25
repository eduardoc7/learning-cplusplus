# Learning C++
Here, I have my learning with C++, important algorithms and unit tests.
I use code to apply practical concepts and Doxygen style documentation to help with that.

## Introduction to the Language C++

- [Basic Language](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/basic-language)

---

## Oriented Object Programming Concepts

- [Introduction](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/Introduction.hpp)
- [Constants Member Functions](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningConstantMemberFunctions.hpp)
- [Constructors](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningConstructors.hpp)
- [Copy Constructors](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningCopyConstructors)
- [Static Members](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningStaticMembers.hpp)
- [Non-Static Data Members](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningNonStaticDataMemberInitialize.hpp)
- [Structures](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningStructures.hpp)
- [This-Pointer](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/LearningThisPointer.hpp)
- [Class Example](https://github.com/eduardoc7/learning-cplusplus/tree/main/src/course/OO-programing/Car.hpp)

---

## Applying C++ to algorithms

- [Binary Search](https://github.com/eduardoc7/learning-cplusplus/blob/main/src/algorithms/binarySearch.hpp)

---

## 🛠 Build
```bash
# Clone this repository
$ git clone git@github.com:eduardoc7/learning-cplusplus.git

# Install dependencies
$ sudo apt-get update && sudo apt-get install build-essential
$ sudo apt install cmake -y
$ sudo apt install clang clang-tidy clang-format ninja-build -y
$ sudo apt install libgtest-dev googletest -y

# Build with cmake command line
$ cd learning-cplusplus/
$ mkdir build && cd build
$ cmake ..
$ cmake --build . --config Debug --target all -j $(nproc) -- 
```
---

## ▶ Running tests
```bash
# Running test after compile
$ ctest -j 20 -C Debug -T test --output-on-failure

# Running tests from executable
$ ./build/bin/maintest_binary
```
---

## 📝 License

Copyright © 2022 [Eduardo Cordeiro](https://github.com/eduardoc7). <br />
This project is [MIT](https://github.com/eduardoc7/learning-cplusplus/blob/main/LICENSE) licensed.