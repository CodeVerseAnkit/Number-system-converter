Number System Converter

A simple C++ tool that allows you to convert numbers between different bases (2–36) and Roman numerals.
It also keeps a conversion history and provides helpful information about number systems.


---

📌 Features

Convert numbers between bases 2 to 36

Convert Roman ↔ Decimal/Base

Maintain a conversion history in a text file

Validate user input for correct digits in a given base

User-friendly menu system

Information section explaining number systems



---

⚙️ How it Works

1. For any conversion (Binary, Octal, Hexadecimal, etc.), the program first converts the number to Decimal.


2. Then, the Decimal number is converted to the desired base or Roman numeral.




---

🛠️ Installation & Usage

1. Compile the program

g++ number_system_converter.cpp -o converter

2. Run the program

./converter

3. Menu Options

1) CONVERT → Convert from one base to another (2–36)

2) ROMAN CONVERSION → Convert Roman ↔ Other bases

3) CONVERSION HISTORY → View saved conversions

4) NUMBER SYSTEM INFO → Learn about different number systems

5) EXIT → Quit the program



---

📖 Example

Base Conversion

Enter Source base(2 - 36): 16  
Enter number: 1A  
Enter Destination base(2 - 36): 2  

Converting...  
Converted successfully 😎  

1A(16) = 11010(2)

Roman Conversion

Enter Roman number: XIV  
Enter Destination base(2 - 36): 10  

Converting...  
Converted successfully 😎  

XIV(Roman) = 14(10)

---
Example screenshot

https://github.com/CodeVerseAnkit/Number-system-converter/blob/main/Example.jpg

---

📂 Conversion History

All conversions are saved in a file:

note :- I use file handling to store history. You need to enter your directory path. 

Example entry:

1A(16) = 11010(2)
XIV(Roman) = 14(10)


---

ℹ️ Number Systems Covered

Binary (Base 2) → Digits: 0, 1

Octal (Base 8) → Digits: 0–7

Decimal (Base 10) → Digits: 0–9

Hexadecimal (Base 16) → Digits: 0–9, A–F

Up to Base 36 → Digits: 0–9, A–Z

Roman Numerals → I, V, X, L, C, D, M



---

👨‍💻 About the Project

Coder: Ankit

Date: 9-9-2025

Description: A simple yet powerful base converter with Roman numeral support, built in C++.

---

THANKS FOR VISIT ❤🙏❤

---
