# Random Password Generator

This is a simple utility to generate random passwords with customizable options such as length and character types.
## Features
- Generate random passwords
- Customize password length
- Include/exclude uppercase letters, lowercase letters, digits, and special characters
- Command-line interface for easy usage
## Prerequisites
  - cmake (version 3.21 or higher)
  - C++ compiler (supporting C++17 or higher)
  - Git (for cloning the repository)

## Building the Project
To build the project, follow these steps:
1. **Clone the Repository:**
     ```sh
     git clone    
     ```
2. **Create Build Directory:**
       ```sh
       mkdir build
       cd build
       ```
3. **Run CMake:**
       ```sh
       cmake ..
       ```
4. **Build the Project:**
       ```sh
       make
       ```
5. **Test:**
Once built, you have several options to run the tests:
Option 1: Using ctest (recommended)

   - Run all tests
   ```sh
     ctest 
   ```

   - Run tests with verbose output
   ```shell
   ctest -V
   ```

Option 2: Run the test executable directly

 - Navigate to build directory and run the test executable
```shell
./run_tests
```

Option 3: Using cmake --build with test target

 - Build and run tests in one command
```shell
cmake --build . --target run_tests
./run_tests
```

## Usage
After building the project, you can run the password generator with the following command:
```sh
./password_generator [options]
```
### Options:
- `-n LENGTH`, `--length LENGTH`: Specify the length of the password (default is 15).
- `-U`, `--uppercase`: Include uppercase letters.
- `-l`, `--lowercase`: Include lowercase letters.         
- `-d`, `--digits`: Include digits.
- `-s`, `--special`: Include special characters.
- `-h`, `--help`: Display help information.
### Example:    
Generate a password with all character types and default length(15):
```sh
./password_generator
```

Generate a 16-character password with uppercase letters, lowercase letters, and digits:
```sh
./password_generator -l 16 -u -L -d
```

## License
This project is licensed under the [MIT](LICENSE) License. 

## Developed By
This project was developed by Yuri Moiseyenko, © YMC Software Inc. All rights reserved.