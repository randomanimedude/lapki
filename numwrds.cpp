#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** args)
{
    string ver = "0.5";
    bool ask = true;
    string str = " ";     //строка для підрахунку слів
    bool c_is_used = false;
    bool f_is_used = false;
    string cf_error = "u can't use -c and -f at a same time dummy\n";

    for (int i = 0; i < argc; ++i)
    {
        if (_stricmp(args[i], "-f") == 0)
        {
            if (c_is_used)
            {
                cout << cf_error;
                return 0;
            }
            f_is_used = true;
            ask = false;
            ifstream file(args[i + 1]);
            string temp;
            if (file.is_open())     //якщо файл відкриито вдало, то зчитую його повністю построково, розділяючи пробілами
                while (file)
                {
                    getline(file, temp);
                    str += temp + ' ';
                    temp = "";
                }
        }

        if (_stricmp(args[i], "-v") == 0)
            cout << "Version: " << ver << endl;

        if (_stricmp(args[i], "-h") == 0)
            cout << "Zis program iz kauntin' namber of words. Taip yor sentans bilow or uz -c!" << endl << \
            "Uz -v tu si ze vershon of da program." << endl << "Uz -f <file> tu rid sentans from da fail." << endl;

        if (_stricmp(args[i], "-c") == 0)
        {
            if (f_is_used)
            {
                cout << cf_error;
                return 0;
            }
            c_is_used = true;
            ask = false;
            for (int j = i + 1; j < argc; ++j)
            {
                if (args[j][0] == '-')      //записує слова до першого аргумента що починається з '-',
                    break;                  //після чого використовується старий алгоритм підрахунку
                str += args[j] + (string)" ";
            }
        }
    }
    int cx = 0;     //лічильник слів
    if (ask)
    {
        cout << "string: ";
        getline(cin, str);

    }
    for (int i = 0; i < str.length() - 1; ++i)      //решта слів рахується по закінченню пропусків
        if (str[i] == ' ' && str[i + 1] != ' ')
            ++cx;
    cout << "result: " << cx << " words" << endl;
    system("pause");
}
//not so good as it could be but OK
//some configuration reading
//one more mid code block