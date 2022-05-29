//Ana Markoska INKI 858, zadaca 50 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <fstream>

using namespace std;

static const string sourceText = "INKI858 Ana, Ringin the bell, And nobody's coming to help";

//Dobivanjne na najgolem broj 

char getBiggestDigit(int value)
{
    char max = 0;
    while (value > 0)
    {
        int remains = value % 10;
        if (remains > max)
            max = remains;
        value /= 10;
    }

    return max;
}

int readNumberInRange(int min, int max) {
    int number = 0;
    bool isInputValid = false;
    do
    {
        cout << "Vnesete trocifren broj : ";
        cin >> number;
        isInputValid = number >= min and number <= max;
        if (isInputValid) {
            cout << "Brojot se procesira: " << number << "\n";
        }
        else {
            cout << "Gresen broj. Brojot mora da sodrzi 3 cifri!\n";
        }

    } while (!isInputValid);

    return number;
}


int main()
{
    // Vcituvanje na vneseniot broj 
    const int number = readNumberInRange(100, 999);

    // Dobivanje na najgolemata cifra od vneseniot broj
    const char max = getBiggestDigit(number);
    cout << "Najgolemata cifra od vneseniot broj e: " << max << endl;

    // Pretvoranje na stringot vo vektor zgolemuvajki go sekoj znak za nagolemata cifra
    vector<char> textVector;
    for (char const& c : sourceText) {
        char chInc = c + max;
        textVector.push_back(chInc);
    }

    // Sortiranje na vektorot
    sort(textVector.begin(), textVector.end());

    // Pecatenje na vektorot vo konzola i datoteka
    std::ofstream output_file("NumberOfIndex.Project3");

    for (const char& c : textVector) {
        cout << c;
        output_file << c;
    };
    cout << endl;
    output_file.close();
}

