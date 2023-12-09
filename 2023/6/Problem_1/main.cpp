#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
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

   // Get times
   string times_s;

   if (
         ! getline(input_file, times_s) ||
         times_s.size() < 6 ||
         times_s.substr(0, 5) != "Time:"
      )
   {
      cout << "Bad times!" << endl;

      return 1;
   }

   times_s = times_s.substr(5);

   unsigned int one_time;
   vector<unsigned int> times;
   stringstream times_ss{times_s};

   while (times_ss >> one_time)
      times.push_back(one_time);

   // Get distances
   string distances_s;

   if (
         ! getline(input_file, distances_s) ||
         distances_s.size() < 10 ||
         distances_s.substr(0, 9) != "Distance:"
      )
   {
      cout << "Bad distances!" << endl;

      return 1;
   }

   distances_s = distances_s.substr(9);

   unsigned int one_distance;
   vector<unsigned int> distances;
   stringstream distances_ss{distances_s};

   while (distances_ss >> one_distance)
      distances.push_back(one_distance);

   if (times.size() != distances.size())
   {
      cout << "Count of times and count of distances differ!" << endl;

      return 1;
   }

   vector<unsigned int> results;

   for (size_t i{0}; i < times.size(); ++i)
   {
      unsigned int count_of_ways_to_break_record{0};
      unsigned int total_time = times[i];
      unsigned int record_distance = distances[i];

      cout << "total_time = " << total_time << endl;
      cout << "record_distance = " << record_distance << endl;

      for (unsigned int button_time{1}; button_time < total_time; ++button_time)
      {
         unsigned int rate{button_time};
         unsigned int race_time{total_time - button_time};
         unsigned int distance{rate * race_time};

         if (distance > record_distance)
            ++count_of_ways_to_break_record;
      }

      results.push_back(count_of_ways_to_break_record);
      cout << count_of_ways_to_break_record << endl;
      cout << endl;
   }

   cout << accumulate(results.cbegin(), results.cend(), 1, multiplies<unsigned int>())
        << endl;
}
