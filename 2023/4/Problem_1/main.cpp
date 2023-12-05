#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
constexpr
inline
T power(T n, T r)
{
   T rval{1};

   while (true)
   {
      if (r & 1)
         rval *= n;

      r >>= 1;

      if (!r)
         break;

      n *= n;
   }

   return rval;
}

int main()
{
   ifstream input_file("input.txt");

   if (! input_file)
   {
      cout << "input.txt is missing" << endl;

      return 1;
   }

   vector<unsigned int> all_values;
   const regex r1{"^(Card +[0-9]+: +)([0-9 ]+)( \\| )([0-9 ]+)$"};
   string one_line;

   while (getline(input_file, one_line))
   {
      smatch m1;

      if (! regex_match(one_line, m1, r1))
      {
         cout << "Bad input string: " << one_line << endl;

         return 1;
      }

      stringstream winning_numbers_ss{m1.str(2)};
      stringstream my_numbers_ss{m1.str(4)};

      set<unsigned int> winning_numbers;
      set<unsigned int> my_numbers;

      unsigned int one_number;

      while (winning_numbers_ss >> one_number)
      {
         auto rval{winning_numbers.insert(one_number)};

         if (! rval.second)
         {
            cout << "Duplicate number " << one_number << "!" << endl;

            return 1;
         }
      }

      while (my_numbers_ss >> one_number)
      {
         auto rval{my_numbers.insert(one_number)};

         if (! rval.second)
         {
            cout << "Duplicate number " << one_number << "!" << endl;

            return 1;
         }
      }

      set<unsigned int> intersection;

      set_intersection(
                         winning_numbers.cbegin(),
                         winning_numbers.cend(),
                         my_numbers.cbegin(),
                         my_numbers.cend(),
                         inserter(intersection, intersection.begin())
                      );

      unsigned int value{
                           intersection.size() == 0 ? 0 :
                           power<unsigned int>(2, intersection.size() - 1)
                        };

      all_values.push_back(value);
   }

   cout << accumulate(all_values.cbegin(), all_values.cend(), 0) << endl;
}
