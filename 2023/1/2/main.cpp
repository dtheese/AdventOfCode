#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{
   const regex r_first{
                         "^.*?"
                         "("
                            "1|one|"
                            "2|two|"
                            "3|three|"
                            "4|four|"
                            "5|five|"
                            "6|six|"
                            "7|seven|"
                            "8|eight|"
                            "9|nine|"
                            "0|zero"
                         ")"
                         ".*$"
                      };

   const regex r_last{
                        "^.*"
                        "("
                           "1|one|"
                           "2|two|"
                           "3|three|"
                           "4|four|"
                           "5|five|"
                           "6|six|"
                           "7|seven|"
                           "8|eight|"
                           "9|nine|"
                           "0|zero"
                        ")"
                        ".*$"
                     };

   map<string, unsigned int> conversions{
                                           {"1", 1},
                                           {"2", 2},
                                           {"3", 3},
                                           {"4", 4},
                                           {"5", 5},
                                           {"6", 6},
                                           {"7", 7},
                                           {"8", 8},
                                           {"9", 9},
                                           {"0", 0},
                                           {"one", 1},
                                           {"two", 2},
                                           {"three", 3},
                                           {"four", 4},
                                           {"five", 5},
                                           {"six", 6},
                                           {"seven", 7},
                                           {"eight", 8},
                                           {"nine", 9},
                                           {"zero", 0}
                                        };

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
      smatch m_first;
      string s_first;

      smatch m_last;
      string s_last;

      if (regex_match(one_line, m_first, r_first))
         s_first = m_first.str(1);
      else
      {
         cout << "Bad input string: " << one_line << endl;

         return 1;
      }

      if (regex_match(one_line, m_last, r_last))
         s_last = m_last.str(1);
      else
      {
         cout << "Bad input string: " << one_line << endl;

         return 1;
      }

      unsigned int one_num{10 * conversions.at(s_first) + conversions.at(s_last)};
      all_numbers.push_back(one_num);

      cout << one_line << "   " << s_first << "   " << s_last << "   " << one_num << endl;
   }

   cout << accumulate(all_numbers.cbegin(), all_numbers.cend(), 0) << endl;
}
