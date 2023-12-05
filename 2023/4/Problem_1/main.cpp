#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   ifstream input_file("input.txt");

   if (! input_file)
   {
      cout << "input.txt is missing" << endl;

      return 1;
   }

   string one_line;

   while (getline(input_file, one_line))
   {
      cout << one_line << endl;
   }
}
