#include "Card.h"
#include <fstream>

Card::~Card()
{
}

void Card::generateNumsOfCard()
{
    for (int i = 0; i < 16; ++i) {
        _NumsOfCard[i] = rand() % 9 + 1;
    }
}

void Card::printNumsOfCard() const
{
    for (int i = 0; i < 16; ++i) {
        if (_NumsOfCard[0] != 0)
        {
            cout << _NumsOfCard[i];
        }
    }
    cout << endl;
}

void Card::reportsExpensesCategories()
{
}

bool Card::checkNumsOfCard(const int cardNumber[16]) const
{
    for (int i = 0; i < 16; ++i) {
        if (_NumsOfCard[i] != cardNumber[i]) {
            return false;
        }
    }
    return true;
}

const int* Card::getNumsOfCard() const {
    return _NumsOfCard;
}


double Card::getBalance() const
{
    return _balance;
}

void Card::logExpense(double amount, const string& date, const string& category, const string& userAccount)
{
    string filePath = "data/" + userAccount + ".txt";
    ofstream logFile(filePath, ios::app);
    if (logFile.is_open()) {
        logFile << "Amount: " << amount
            << ", Date: " << date
            << ", Category: " << category << endl;
        logFile.close();
    }
    else {
        cerr << "Unable to open log file for writing." << endl;
    }
}
