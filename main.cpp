#include <iostream>
#include <fstream>

using namespace std;
int main() {
    string nameOfFile;
    char letter;
    int counter = 0;
    cout << "hello, this program can check how many word in this sentence have on first position have a certain letter\n"
            "if you want start you need write name of file, and on next line write letter";
    cin >> nameOfFile;
    cin >> letter;
    string line;
    ifstream in;
    in.open(nameOfFile);
    if (in.is_open())
    {
        getline(in, line);
        string delim = " ";
        size_t pos = 0;
        size_t base_str_size = line.size();
        size_t delim_size = delim.size();
        string temp;
        int position = -1;
        if (pos >= 0)
            while (pos < base_str_size) {
            temp = temp.assign(line, pos, line.find(delim, pos) - pos);
                position = temp.find_first_of(letter);
                if(position == 0) counter++;
                pos += temp.size() + delim_size;
                position = -1;
        }
    }
    in.close();
    ofstream outf(nameOfFile,ios::app);
    outf << "\n" <<"for letter - " << letter << ", count = " << counter;
    return 0;
}

