#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace filesystem;

string directory = "D:\\Done\\";

int main()
{
    string temp_path;
    fstream file;
    fstream file2;
    string input;

    for (auto& p : directory_iterator(directory.c_str()))
    {
        temp_path = p.path().string();

        file.open(temp_path, fstream::in);
        file2.open("C:\\text.txt", fstream::trunc);

        if (file.is_open())
        {
            while (getline(file, input))
            {
                if (file.is_open())
                {
                    cout << input << endl;
                    file2 << input << endl;
                }
            }
        }

        file2.close();
    }
}
