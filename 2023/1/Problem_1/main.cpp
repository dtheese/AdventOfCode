#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
   ifstream input_file("input.txt");

   if (! input_file)
   {
      cout << "input.txt is missing" << endl;

      return 1;
   }

   vector<unsigned int> all_numbers;
   string one_line;

   while (getline(input_file, one_line))
   {
      string::size_type first_digit_index{one_line.find_first_of("0123456789")};
      string::size_type last_digit_index{one_line.find_last_of("0123456789")};

      if (first_digit_index == string::npos || last_digit_index == string::npos)
      {
         cout << "Digit not found!" << endl;

         return 1;
      }

      char first_digit{one_line[first_digit_index]};
      char last_digit{one_line[last_digit_index]};

      string one_number_s{first_digit};
      one_number_s += last_digit;

      all_numbers.push_back(stoul(one_number_s));
   }

   cout << accumulate(all_numbers.cbegin(), all_numbers.cend(), 0) << endl;
}
