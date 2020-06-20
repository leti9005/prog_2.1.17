#include <iostream>
#include <fstream>

using namespace std;


const int MAX_SIZE = 2000;

struct Sentence {
public:
    char litera;
    char text[MAX_SIZE]{};
    int index = 0;
    char marker = '%';
    void addChar(const char &inputChar) {
        if (inputChar == '\n') {
            return;
        }

        this->text[this->index] = inputChar;
        this->index++;
    }


    bool isMarker(const char &inputChar) {
        return inputChar == this->marker;
    }

    int countOfWord()
    {
        char alfa; // буква
        int index = 0;
        int counter = 0;
        while (alfa != marker)
        {
            alfa = text[index];
            if(alfa == litera)
                if(text[index - 1] == ' ' || index == 0)counter++;

            index++;
        }
        return counter;
    }

    void printer (string nameOfFile, int counter)
    {
        ofstream out;
        out.open(nameOfFile, ios::app);
        if (out.is_open()) {
            out << "for letter " << litera << ", count = " << counter;
        }
        out.close();
    }
};


int main() {
    cout
            << "hello, this program can check how many word in this sentence have on first position have a certain letter\n"
               "if you want start you need write name of file, and on next line write letter\n";

    string input;
    string outName;
    Sentence line;
    cin >> input;
    cin >> outName;
    cin >> line.litera;
    ifstream inputFile(input);
    if (inputFile.is_open()) {
        char inputChar;

        while (inputFile >> noskipws >> inputChar) {
            line.addChar(inputChar);
        }

        line.addChar('%');
        inputFile.close();
    }
    int result = line.countOfWord();
    line.printer(outName,result);
}
