#include <iostream>
#include <string>
#include <vector>

using namespace std;



void krasivo(string rez, string ostalos,int porahovano, int nado)
{
   if(ostalos.empty() && nado == porahovano)
   { 
       cout << rez << endl;
   }
   else if(!ostalos.empty())
   {
       for (int i = 0; i < ostalos.length(); ++i)
       {
           //при спробі взяти підстроку з індексом що виходить за межі строки довжина ставиться 0 тому все добре
           krasivo(rez + '+' + ostalos.substr(0, i + 1), ostalos.substr(i + 1, ostalos.length() - i - 1), porahovano + stoi(ostalos.substr(0, i + 1)), nado);
           krasivo(rez + '-' + ostalos.substr(0, i + 1), ostalos.substr(i + 1, ostalos.length() - i - 1), porahovano - stoi(ostalos.substr(0, i + 1)), nado);
       }
   }
}


int main()
{
    vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
    string str="";
    for (int n : arr)
    {
        str += to_string(n);
    }
    int number;
    cin >> number;      //шуканий номер
    for (int i = 0; i < str.length() - 1; ++i)
        krasivo(str.substr(0, i + 1), str.substr(i + 1, str.length() - 1 - i), stoi(str.substr(0,i+1)), number);
    
}
