#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// ---> INTRODUCTION
/*  
  Coder: Ankit
  Date: 9-9-2025
  Project: Number system conveter
  Description: It is a simple tool which convert one base to another. 

*/

// ---> UI
void menu()
{
    cout << "\n <--------- NUMBER SYSTEM CONVETER ---------> \n \t    —–—–—–—–—–.—–—–—–—–—–—\n"
         << endl;
    cout << "      🙏WELCOME TO NUMBER SYSTEM CONVETER🙏\n      •••••••••••••••••••••••••••••••••••••\n"
         << endl;
    cout << " 1) CONVERTE \t\t 2) ROMAN CONVERSION \n 3) CONVERSION HISTORY   4) NUMBER SYSTEM INFO\n 5) EXIT\n"
         << endl;
    cout << " _—_—_—_—_—_—_—_—_—_—_ * _—_—_—_—_—_—_—_—_—_—_\n"
         << endl;
}

// ---> back Button
void back_button()
{
    char ch;
    do
    {
        cout << "  Do you want to back(y): ";
        cin >> ch;
    } while (tolower(ch) != 'y');
}

// ---> check number is valid or not
bool isnumvalid(string num, int base)
{
    string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < num.length(); i++)
    {
        int digit = table.find(toupper(num[i]));
        if (digit == string::npos || digit >= base)
            return false;
    }
    return true;
}

// ---> check roman number is valid or not
bool isromvalid(string num)
{
    string table = "IVXLCDM";
    for (int i = 0; i < num.length(); i++)
    {
        int digit = table.find(toupper(num[i]));
        if (digit == string::npos)
            return false;
    }
    return true;
}

// ---> Decimal to base
string decimal_to_base(long long decimal_num, int base)
{
    if (decimal_num == 0)
        return "0";
    string ans = "";
    char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // this loop find reminder and store in ans
    while (decimal_num > 0)
    {
        long long rem = decimal_num % base;
        ans = ch[rem] + ans;
        decimal_num /= base;
    }
    return ans;
}

// ---> Base to Decimal

long long base_to_decimal(string base_num, int base)
{
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long decimal = 0;
    int power = 0;

    // Traverse right to left
    for (int i = base_num.length() - 1; i >= 0; i--)
    {
        int digit = digits.find(base_num[i]); // index mil gaya
        decimal += digit * pow(base, power);
        power++;
    }

    return decimal;
}

// ---> Decimal to Roman
string decimal_to_roman(long long decimal_num)
{
    // roman number mapping
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    // conversion
    string result = "";
    for (auto &v : roman)
    {
        while (decimal_num >= v.first)
        {
            result += v.second;
            decimal_num -= v.first;
        }
    }
    return result;
}

// ---> Roman to Decimal

long long roman_to_decimal(string roman)
{
    vector<int> value(256, 0); // har ASCII char ke liye ek slot
    value['I'] = 1;
    value['V'] = 5;
    value['X'] = 10;
    value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;

    int decimal = 0;
    // conversion
    for (int i = 0; i < roman.length(); i++)
    {
        int curr = value[roman[i]];
        int next = (i + 1 < roman.length()) ? value[roman[i + 1]] : 0;

        if (curr < next)
        {
            decimal -= curr;
        }
        else
        {
            decimal += curr;
        }
    }
    return decimal;
}

// ---> 1. Converte
void convert()
{
    cout << "      🙏WELCOME TO NUMBER SYSTEM CONVETER🙏\n      •••••••••••••••••••••••••••••••••••••\n"
         << endl;

    cout << "  # start conversion👍\n"
         << endl;
    char user;
    do
    { // store user input
        string number;
        int sourcebase, destinationbase;
        // ignore invalid base number (source base)
        while (true)
        {
            cout << "  Enter Source base(2 - 36): ";
            cin >> sourcebase;
            if (sourcebase >= 2 && sourcebase <= 36)
                break;
        }

        // get number from user and also check number is valid or not
        cin.ignore(); // clear buffer
        while (true)
        {
            cout << "  Enter number: ";

            getline(cin, number);
            if (isnumvalid(number, sourcebase) == false)
            {
                cout << "\n Invalid number for this base❗\n"
                     << endl;
            }
            else
            {
                break;
            }
        }

        // for (destination base)
        while (true)
        {
            cout << "  Enter Destination base(2 - 36): ";
            cin >> destinationbase;
            if (destinationbase >= 2 && destinationbase <= 36)
                break;
        }
        // transform string number in upper case, so we also handle hex
        transform(number.begin(), number.end(), number.begin(), ::toupper);
        // convert source base to decimal
        long long BaseToDecimal = base_to_decimal(number, sourcebase);
        // convert decimal to destination base
        string result = decimal_to_base(BaseToDecimal, destinationbase);
        // processing message
        cout << "\n   Converting... \n   Converting... \n   Converting... \n   Converted successfully 😎\n"
             << endl;
        // print result
        cout << "   " << number << "(" << sourcebase << ") = " << result << "(" << destinationbase << ")\n"
             << endl;
        // store conversion history in txt file
        ofstream write("/sdcard/Coding.cpp/PROJECT/number_system_conversion/conversion_history.txt", ios::app);
        //  cout<<write.is_open();
        write << "  " << number << "(" << sourcebase << ") = " << result << "(" << destinationbase << ")" << endl;
        write.close(); // file close
        // for reapeted conversion
        while (true)
        {
            cout << "  Do you want to convert again (y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }

    } while (tolower(user) != 'n');
    back_button();
}

// ---> 2. Roman Conversion
void roman_conversion()
{
    cout << "      🙏WELCOME TO NUMBER SYSTEM CONVETER🙏\n      •••••••••••••••••••••••••••••••••••••\n"
         << endl;

    cout << "  # start conversion👍\n"
         << endl;
    char user;
    do

    {
        // for Roman to other base and vice versa
        int choice;
        cout << "  What conversion type do you want:- \n  1.Roman to other base  2.Other base to Roman" << endl;
        while (true)
        {
            cout << "  Enter your choice: ";
            cin >> choice;
            if (choice == 1 || choice == 2)
                break;
        }

        // store user input
        string number;
        int sourcebase, destinationbase;
        // Roman to other base conversion
        if (choice == 1)
        {
            // get roman number from user and also check number is valid or not
            cin.ignore(); // clear buffer
            while (true)
            {
                cout << "  Enter Roman number: ";

                getline(cin, number);
                if (isromvalid(number) == false)
                {
                    cout << "\n Invalid number for this base❗\n"
                         << endl;
                }
                else
                {
                    break;
                }
            }
            // for (destination base)
            while (true)
            {
                cout << "  Enter Destination base(2 - 36): ";
                cin >> destinationbase;
                if (destinationbase >= 2 && destinationbase <= 36)
                    break;
            }
            // transform string number in upper case
            transform(number.begin(), number.end(), number.begin(), ::toupper);
            long long RomanToDecimal = roman_to_decimal(number);
            string result = decimal_to_base(RomanToDecimal, destinationbase);

            // processing message
            cout << "\n   Converting... \n   Converting... \n   Converting... \n   Converted successfully 😎\n"
                 << endl;
            // print result
            cout << "   " << number << "(Roman) = " << result << "(" << destinationbase << ")\n"
                 << endl;
            // store conversion history in txt file
            ofstream write("/sdcard/Coding.cpp/PROJECT/number_system_conversion/conversion_history.txt", ios::app);
            //  cout<<write.is_open();
            write << "  " << number << "(Roman) = " << result << "(" << destinationbase << ")" << endl;
            write.close(); // file close
        }
        else
        { // other base to Roman conversion

            // ignore invalid base number (source base)
            while (true)
            {
                cout << "  Enter Source base(2 - 36): ";
                cin >> sourcebase;
                if (sourcebase >= 2 && sourcebase <= 36)
                    break;
            }

            // get number from user and also check number is valid or not
            cin.ignore(); // clear buffer
            while (true)
            {
                cout << "  Enter number: ";

                getline(cin, number);
                if (isnumvalid(number, sourcebase) == false)
                {
                    cout << "\n Invalid number for this base❗\n"
                         << endl;
                }
                else
                {
                    break;
                }
            }
            // transform string number in upper case
            transform(number.begin(), number.end(), number.begin(), ::toupper);

            // convert source base to decimal
            long long BaseToDecimal = base_to_decimal(number, sourcebase);
            // converr decimal to roman
            string result = decimal_to_roman(BaseToDecimal);

            // processing message
            cout << "\n   Converting... \n   Converting... \n   Converting... \n   Converted successfully 😎\n"
                 << endl;
            // print result
            cout << "   " << number << "(" << sourcebase << ") = " << result << "(Roman)\n"
                 << endl;
            // store conversion history in txt file
            ofstream write("/sdcard/Coding.cpp/PROJECT/number_system_conversion/conversion_history.txt", ios::app);
            //  cout<<write.is_open();
            write << "  " << number << "(" << sourcebase << ") = " << result << "(Roman)" << endl;
            write.close(); //file close
        }

        // for reapeted conversion
        while (true)
        {
            cout << "  Do you want to convert again (y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }

    } while (tolower(user) != 'n');
    back_button();
}

// ---> 3. Conversion history
void conversion_history()
{
    cout << "     📖Conversion history📖 :-\n     ~~~~~~~~~~~~~~~~~~~~~~~\n"
         << endl;
    ifstream read("/sdcard/Coding.cpp/PROJECT/number_system_conversion/conversion_history.txt");
    if (read.peek() == ifstream::traits_type::eof())
    {
        cout << "               File is empty❗ " << endl;
    }
    else
    {
        string line;
        while (getline(read, line))
        {
            cout << "   " << line << endl;
        }
    }
    cout << endl;
    back_button();
}

// ---> 4. Number System Information
void number_system_info()
{
    cout << "\n <--------- NUMBER SYSTEM CONVETER ---------> \n \t    —–—–—–—–—–.—–—–—–—–—–—\n"
         << endl;
    cout << "      🙏WELCOME TO NUMBER SYSTEM CONVETER🙏\n      •••••••••••••••••••••••••••••••••••••\n"
         << endl;
    // about number system
    cout << "   NUMBER SYSTEM:- \n   ~~~~~~~~~~~~~~\n\n  There are (2 - 36) bases are available\n   for conversion."
         << endl;
    cout << "  Some important bases are:- \n"
         << endl;
    cout << "  1) Decimal Number System \n     Base= 10\n     Symbols= 0,1,2,3,4,5,6,7,8,9\n  2) Binary Number System \n     Base= 2\n     Symbols= 0,1\n  3) Octal Number System \n     Base= 8\n     Symbols= 0,1,2,3,4,5,6,7\n  4) Hexadecimal Number System \n     Base= 16\n     Symbols= 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F\n  5) Roman Number System \n     Base= no base\n     Symbols= I,V,X,L,C,D,M\n"
         << endl;

    // instructions about how to use this conversion tool
    cout << "  Instructions about how to use this tool:-\n  -----------------------------------------\n\n  1.Enter the source base number(2-36).\n  2.Then,Enter the number.\n  3.Enter the destination base number."
         << endl;
    cout << "\n  In case of Roman conversion,\n \n  1.First chose the conversation type. \n  2.Then enter the number according to\n    your conversion type. \n"
         << endl;

    // logic of conversion
    cout << "  Logic used for conversion:-\n  --------------------------\n\n  Here, we use a simple logic for conversion.\n  1.First,it convert the any base number\n    to decimal number. \n  2.Then,it convert the decimal number\n    to destination number. \n"
         << endl;
    // about this project
    cout << "  About this Project:-\n  -------------------\n\n  Coder: Ankit\n  Date: 9-9-2025\n  Project: Number system conveter\n  Description: It is a simple tool which\n \t convert one base to another by\n \t using simple logic.\n"
         << endl;

    cout << "\t\t❤THANKS FOR VISIT❤\n\t\t~~~~~~~~~~~~~~~~~~~~\n"
         << endl;
    back_button();
}

int main()
{
    int input;
    do
    {
        menu();
        // ignore wrong input
        while (true)
        {
            cout << "   INPUT: ";
            cin >> input;
            if (input >= 1 && input <= 5)
                break;
        }

        switch (input)
        {
        case 1:
            convert();
            break;
        case 2:
            roman_conversion();
            break;
        case 3:
            conversion_history();
            break;
        case 4:
            number_system_info();
            break;
        case 5:
            cout << "\n  Exiting... \n  Exiting... \n  Exiting... \n"
                 << endl;
            break;
        default:
            cout << "   Invalid input" << endl;
        }
    } while (input != 5);
    return 0;
}