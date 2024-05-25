#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

void password_strength(char passArray[], int SIZE)
{
    int upper_1 = 0;
    int lower_1 = 0;
    int symbols_1 = 0;
    int numbers_1 = 0;

    int comboBonus = 0;
    int lengthBonus = 2;

    int score = 0;

    int upperContribution = 3;
    int lowerContribution = 2;
    int numbersContribution = 4;
    int symbolsContribution = 4;
    int excessLength = strlen(passArray) - 7;

    for (int i = 0; i < strlen(passArray); i++)
    {

        if (passArray[i] >= 48 && passArray[i] <= 57)
        {
            numbers_1++;
        }
        if (passArray[i] >= 97 && passArray[i] <= 125)
        {
            lower_1++;
        }
        if (passArray[i] >= 65 && passArray[i] <= 90)
        {
            upper_1++;
        }
        if (passArray[i] >= 33 && passArray[i] <= 47)
        {
            symbols_1++;
        }
    }

    if ((upper_1 > 0) && (numbers_1 > 0) && (symbols_1 > 0) && (lower_1 > 0))
    {
        comboBonus = 30;
    }
    else if (((upper_1 > 0) && (numbers_1 > 0) && (symbols_1 > 0)))
    {
        comboBonus = 20;
    }
    else if (((upper_1 > 0) && (numbers_1 > 0) && (lower_1 > 0)))
    {
        comboBonus = 20;
    }
    else if (((upper_1 > 0) && (lower_1 > 0) && (symbols_1 > 0)))
    {
        comboBonus = 20;
    }
    else if ((lower_1 > 0) && (numbers_1) > 0 && (symbols_1 > 0))
    {
        comboBonus = 20;
    }
    else if ((upper_1 > 0 && numbers_1 > 0) || (upper_1 > 0 && symbols_1 > 0) || (numbers_1 > 0 && symbols_1 > 0) || (upper_1 > 0 && lower_1 > 0))
    {
        comboBonus = 10;
    }

    score = (excessLength * lengthBonus) + (numbers_1 * numbersContribution) + (symbols_1 * symbolsContribution) + (lower_1 * lowerContribution) + (upper_1 * upperContribution) + (comboBonus);

    if ((score >= 55) && (comboBonus > 20))
    {
        cout << "Strong";
    }
    else if ((score >= 40) && (comboBonus > 10) && (comboBonus <= 20))
    {
        cout << "Good";
    }
    else if (score >= 30)
    {
        cout << "Fair";
    }
    else if (score < 30)
    {
        cout << "Weak";
    }
};

int main()
{
    string passInput;
    string command3;
    char ch;
    int command;
    string saveInput = "";
    string passOne = "";
    int command2;
    int x = 0;

    string account_name[1000];
    string account_username[1000];
    string account_password[1000];
    cout << endl
         << endl;
    cout << "=============================================================\n";
    cout << "************************** OnePass **************************\n";
    cout << "=============================================================\n";
    cout << "Enter a password to open your OnePass account: ";
    ch = _getch();
    while (ch != 13)
    {
        if (ch == 8)
        {
            if (!passInput.empty())
            {
                passInput.pop_back();
                std::cout << "\b \b";
            }
        }
        else
        {
            passInput.push_back(ch);
            std::cout << "*";
        }
        ch = _getch();
    }
    cout << endl;
    cout << endl;

    cout << "==> Account created successfully!\n";

    cout << endl;

    do
    {
        cout << "======================================================\n";
        cout << "************************ Main ************************\n";
        cout << "======================================================\n";

        cout << "-> Press 1 to generate a password for an account\n";
        cout << "-> Press 2 to open password manager\n";
        cout << "-> Press 0 to end program (Disclaimer: All saved passwords will be lost upon ending program)\n";
        cin >> command;

        if (command == 1)
        {
            char characters[] = "abcdefghijklmnopqrstuvwxyz!'#$%&()0123456789!'#$%&()ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!'#$%&()";
            string password = "";
            string s = "";
            int length = 0;
            int rNum = 0;

            string upper, lower, numb, symbols;
            cout << "-> Do you want upper-case letters in your password?(y/n): ";
            cin >> upper;
            cout << "-> Do you want lower-case letters in your password?(y/n): ";
            cin >> lower;
            cout << "-> Do you want numbers in your password?(y/n): ";
            cin >> numb;
            cout << "-> Do you want symbols in your password?(y/n): ";
            cin >> symbols;

            cout << "-> Enter length: ";
            cin >> length;

            srand(time(0));

            for (int i = 0; password.length() <= length; i++)
            {
                rNum = rand() % 95;

                if (characters[rNum] >= 65 && characters[rNum] <= 90)
                {

                    if (upper != "n")
                    {
                        s = characters[rNum];
                        password = password + s;
                    }
                }
                else if (characters[rNum] >= 97 && characters[rNum] <= 122)
                {
                    if (lower != "n")
                    {
                        s = characters[rNum];
                        password = password + s;
                    }
                }
                else if ((characters[rNum] >= 48 && characters[rNum] <= 57))
                {
                    if (numb != "n")
                    {
                        s = characters[rNum];
                        password = password + s;
                    }
                }
                else if ((characters[rNum] >= 33 && characters[rNum] <= 41))
                {
                    if (symbols != "n")
                    {
                        s = characters[rNum];
                        password = password + s;
                    }
                }
            }
            cout << endl;
            cout << "Password: ";
            cout << password;
            cout << endl;
            cout << "Password Strength: ";

            char passArray[password.length()];

            for (int m = 0; m < password.length(); m++)
            {
                passArray[m] = password[m];
            }
            password_strength(passArray, password.length());

            cout << endl;
            cout << "Would you like to save this password?(y/n): ";
            cin >> command3;

            if (command3 == "y")
            {
                cout << "Account Name: ";
                cin >> account_name[x];

                cout << "Username: ";
                cin >> account_username[x];

                account_password[x] = password;
                cout << endl;
                cout << "==> Password for " << account_name[x] << " saved succesfully!\n";
                cout << endl;
                x++;
            }
            else if (command3 == "n")
            {
                cout << endl;
            }
        }

        if (command == 2)
        {
            cout << "==> Enter OnePass password: ";
            do
            {

                passOne = "";

                char ch2;
                ch2 = _getch();

                while (ch2 != 13)
                {
                    passOne.push_back(ch2);
                    cout << "*";
                    ch2 = _getch();
                }

                if (passOne == passInput)
                {
                    cout << endl;
                    cout << endl;
                    cout << "==> Acces Granted!\n";
                    cout << endl;
                    cout << "==========================================\n";
                    cout << "************ Password Manager ************\n";
                    cout << "==========================================\n";
                }
                else if (passOne != passInput)
                {
                    cout << "\n==> Incorrect Password! Please Try Again: ";
                }
            } while (passOne != passInput);
            do
            {
                cout << "-> Press 1 to save a new password\n";
                cout << "-> Press 2 to see previously saved passwords\n";
                cout << "-> Press 0 to return to main\n";
                cin >> command2;

                if (command2 == 1)
                {
                    cout << "Account Name: ";
                    cin >> account_name[x];
                    cout << "Username: ";
                    cin >> account_username[x];
                    cout << "Password: ";
                    cin >> account_password[x];
                    cout << endl;
                    cout << "==> Password for " << account_name[x] << " saved succesfully!\n";
                    cout << endl;
                    x++;
                }
                else if (command2 == 2)
                {
                    cout << endl;
                    cout << "Previously saved passwords:\n";

                    cout << "***************************\n";
                    for (int a = 0; a < x; a++)
                    {

                        cout << "Account Name: ";
                        cout << account_name[a];
                        cout << endl;
                        cout << "Username: ";
                        cout << account_username[a];
                        cout << endl;
                        cout << "Password: ";
                        cout << account_password[a];
                        cout << endl;
                        cout << "***************************\n";
                    }
                }
            } while (command2 != 0);
        }
    } while (command != 0);

    return 0;
}
