////////////////////////////////////////////////////////////////////////////////
/// @brief Example timing file. Add to this file the functions you want to time
////////////////////////////////////////////////////////////////////////////////

#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "sort.h"

using namespace std;
using namespace chrono;

/// @todo Modify timing.cpp to evaluate the various sorting algorithms on the
///       following input types:
///       - Random sequence
///       - Sorted sequence
///       - Reverse sorted sequence


/// @brief Generate random sequence and insetion_sort
/// @param k merge sort sub-problem size (not used)
/// @param sz Vector size
duration<double> insertion_sort_random_sequence_k(size_t sz, size_t k) {
  vector<int> v;
  for(size_t i = 0; i < sz; ++i)
    v.push_back(rand());
  // create a clock
  high_resolution_clock::time_point start = high_resolution_clock::now();
  my_algorithm::insertion_sort(v.begin(), v.end(), less<int>());
  // calculate time
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> diff = duration_cast<duration<double>>(stop - start);
  return diff;
}


duration<double> insertion_sort_sorted_sequence_k(size_t sz, size_t k) {
  vector<int> v;
//generate a sorted sequence where 1st element = 1, 2nd = 2, 3rd = 3 ... etc.
  for(size_t i = 0; i < sz; ++i){
    //using i+1 so our vector hold values 1,2,3,4,5,...,sz
    v.push_back(i);
  }
  // create a clock
  high_resolution_clock::time_point start = high_resolution_clock::now();
  my_algorithm::insertion_sort(v.begin(), v.end(), less<int>());
  // calculate time
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> diff = duration_cast<duration<double>>(stop - start);
  return diff;
}


duration<double> insertion_sort_reverse_sequence_k(size_t sz, size_t k) {
  vector<int> v;
//generate a reverse sorted sequence where 1st element = sz, 2nd = sz - 1, ... last = 1
  for(size_t i = sz; i > 0; --i){
    //using i so our vector hold values sz, sz-1, ... 1
    v.push_back(i);
  }
  // create a clock
  high_resolution_clock::time_point start = high_resolution_clock::now();
  my_algorithm::insertion_sort(v.begin(), v.end(), less<int>());
  // calculate time
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> diff = duration_cast<duration<double>>(stop - start);
  return diff;
}











/// @brief Generate random sequence and sort
/// @param k merge sort sub-problem size
/// @param sz vector size
duration<double> merge_sort_random_sequence_k(size_t sz, size_t k) {
  vector<int> v;
  for(size_t i = 0; i < sz; ++i)
    v.push_back(rand());
  // create a clock
  high_resolution_clock::time_point start = high_resolution_clock::now();
  my_algorithm::merge_sort(v.begin(), v.end(), less<int>(), k);
  // calculate time
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> diff = duration_cast<duration<double>>(stop - start);
  return diff;
}


duration<double> merge_sort_sorted_sequence_k(size_t sz, size_t k) {
  vector<int> v;
  //iteration from 0 to i and insert into vector
  for(size_t i = 0; i < sz; ++i)
    v.push_back(i);
  // create a clock
  high_resolution_clock::time_point start = high_resolution_clock::now();
  my_algorithm::merge_sort(v.begin(), v.end(), less<int>(), k);
  // calculate time
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> diff = duration_cast<duration<double>>(stop - start);
  return diff;
}


duration<double> merge_sort_reversed_sequence_k(size_t sz, size_t k) {
  vector<int> v;
  //iterate from size to 0 and insert into vector
  for(size_t i = sz; i > 0; --i)
    v.push_back(i);
  // create a clock
  high_resolution_clock::time_point start = high_resolution_clock::now();
  my_algorithm::merge_sort(v.begin(), v.end(), less<int>(), k);
  // calculate time
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> diff = duration_cast<duration<double>>(stop - start);
  return diff;
}






/// @brief Control timing of a single function
/// @tparam Func Function type
/// @param f Function taking a single size_t parameter
/// @param max_size Maximum size of test. For linear - 2^23 is good, for
///                 quadratic - 2^18 is probably good enough, but its up to you.
/// @param k Size of each sub-problem in merge sort
/// @param name Name of function for nice output
///
/// Essentially this function outputs timings for powers of 2 from 2 to
/// max_size. For each timing it repeats the test at least 10 times to ensure
/// a good average time.
template<typename Func>
void time_function(Func f, size_t max_size, size_t k, string name) {
  cout << "Function: " << name << endl;
  cout << setw(15) << "Size" << setw(15) << "Time(sec)" << endl;

  // Loop to control input size
  for(size_t i = 2; i < max_size; i*=2) {
    cout << setw(15) << i;
    duration<double> diff(0.0);
    // loop a specific number of times to make the clock tick
    size_t num_itr = max(size_t(10), max_size / i);
    for(size_t j = 0; j < num_itr; ++j)
      diff += f(i, k);

    cout << setw(15) << diff.count() / num_itr << endl;
  }
}

/// @brief Main function to time all your functions
int main() {
  time_function(insertion_sort_random_sequence_k, pow(2, 17), 1, "Insertion Sort Random Sequence");
  time_function(insertion_sort_sorted_sequence_k, pow(2,17), 1, "Insertion Sort Sorted Sequence");
  time_function(insertion_sort_reverse_sequence_k, pow(2,17), 1, "Insertion Sort Reversed Sorted Sequence");

  time_function(merge_sort_random_sequence_k, pow(2, 23), 1, "Merge Sort (traditional) Random Sequence");
  time_function(merge_sort_sorted_sequence_k, pow(2, 23), 1, "Merge Sort (traditional) Sorted Sequence");
  time_function(merge_sort_reversed_sequence_k, pow(2, 23), 1, "Merge Sort (traditional) Reversed Sequence");

  time_function(merge_sort_random_sequence_k, pow(2, 23), pow(2, 4), "Merge Sort Random Sequence 2^4 k");
  time_function(merge_sort_random_sequence_k, pow(2, 23), pow(2, 6), "Merge Sort Random Sequence 2^6 k");
  time_function(merge_sort_random_sequence_k, pow(2, 23), pow(2, 8), "Merge Sort Random Sequence 2^8 k");
  /// @TODO - Add more function calls based on the analyses requested for the report
}
