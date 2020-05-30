#include <iostream>
#include <fstream>

using namespace std;

class Redaktor {
public:
    static int find(char del, string line, char letter) {
        int counter = 0;//for check a count of sumbols
        int result = 0;
        if (line[0] == letter)
            result++;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == del) {
              counter++;
                while (line[i + counter] == del) {
                        counter++;
                }
                if(line[i + counter] == letter)
                {
                    result++;
                    i+=counter;
                }
                    counter = 0;
            }
        }
        return result;
    }
};

int main() {
    string nameOfFile;
    char letter = ' ';
    cout
            << "hello, this program can check how many word in this sentence have on first position have a certain letter\n"
               "if you want start you need write name of file, and on next line write letter\n";
    cin >> nameOfFile;
    cin >> letter;
    string line;
    ifstream in;
    in.open(nameOfFile);
    if (in.is_open()) {
        getline(in, line);
        in.close();
        ofstream outf(nameOfFile, ios::app);
        outf << "\n" << "for letter " << letter << ", count = " << Redaktor::find(' ', line, letter);
        return 0;
    }
}
