/*****************************
 * @file sort.h
 * @author Evelyn Routon
 * efr43s@MissouriState.edu
 * **************************/

#ifndef _SORT_H_
#define _SORT_H_
#include <cmath>
#include <stdexcept>
#include <iostream>
namespace my_algorithm{
	

/***********************
 * 
 * @brief Swap values of two elements
 * @tparam T value type
 * @param a First value
 * @param b Second value
 * 
 * *********************/

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}



/*********************************************
 * 
 * @brief Sort the range [first, last) into nondecreasing order
 * @tparam RandomAccessIterator Random Access Iterator
 * @tparam Compare Comparator function
 * @param first Initial position of sequence to be sorted
 * @param last Final position of sequence to be sorted
 * @param comp Binary function that accepts two elements in the range as
 *              arguments and returns a value convertable to bool. The value
 *              returned indicates whether the element passed as first argument
 *              is considered to go before the second in the ordering it
 *              defines.
 * 
 * Bubble Sort - EXAMPLE
 * 
 *********************************************/

template<class RandomAccessIterator, class Compare>
  void bubble_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    // Traverse from left to right for each ith largest element positioning
    for(RandomAccessIterator i = first; i != last; ++i)
	  // Compare each element with its right neighbor to bubble up ith largest element
      for(RandomAccessIterator j = first; j+1 != last; ++j)
        if(comp(*(j+1), *j)) // Compare j with its right neighbor 
          swap(*(j+1), *j);  // Swap if neighbor is smaller
  }
	



/*********************************************
 * @brief Implementation of insertion selection sort
 * @tparam RandomAccessIterator Random Access Iterator
 * @tparam Compare Comparator function
 * @param first Initial position of sequence to be sorted
 * @param last Final position of sequence to be sorted
 * @param comp Binary function that accepts two elements in the range as
 *             arguments and returns a value convertable to bool. The value
 *             returned indicates whether the element passed as first argument 
 *             is considered to go before the second in the ordering it defines
 * 
 * 
 * @brief -- for each code "section"
 *        OUTER LOOP iterates from second element to last and is incremented after 
 *        each iteration
 *        INNER LOOP iterates from current element - 1 to first element and is 
 *        decremented after each iteration
 *        IF executes if Comparator of neighbor elements returns true
 *        SWAP values of current and previous element swapped when if statement 
 *        executes
 * 
 * @details
 *    My implementation of insertion sort iterates through each element 
 *    comparing it to the next element and if comp(next element, element) 
 *    returns true. I swap the two's values :)
 *    @note information
 *    We are comparing (dereferenced) prev_element + 1 and prev_element 
 *    (instead of prev_element and curr_element) because, since there is a nested loop
 *    the index for prev_element will be a greater index than curr_element at times. 
 *    We are wanting to compare from our current element down through every previous 
 *    element to check if the two need to be swapped. Since curr_element only incremenets 
 *    AFTER our inner loop has finished execution, it is a constant value for each full 
 *    run of our inner loop meaning we need to compare prev_element with itself plus 
 *    one to check each 'neighbor' pair in our vector.
 *    This^ way creates 2 constantly changing values, since prev_element is decremented 
 *    after each iteration.
 * 
 *********************************************/

template<typename RandomAccessIterator, typename Comparator>
  void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Comparator comp){
    //compare current element with all lower/previous elements and swap if Comparator returns true
    for(RandomAccessIterator curr_element = first + 1; curr_element != last; ++curr_element){      
      for(RandomAccessIterator prev_element = curr_element - 1; prev_element >= first; --prev_element){       
        // @note : comparing previous element + 1 and previous element, ^see function header for more info.
        if(comp(*(prev_element+1),*prev_element) == 1){       
          swap(*prev_element, *(prev_element+1));
        }}
    }}




/**************************************
 * 
 * @brief Your implementation of merging two sorted sequences  
 * @tparam RandomAccessIterator Random Access Iterator
 * @tparam Compare Comparator function
 * @param first Initial position of the first sequence to be merged
 * @param mid Initial position of the second sequence to be merged
 * @param last Final position of the second sequence to be merged
 * @param comp Binary function that accepts two elements in the range as
 *             arguments and returns a value convertable to bool. The value
 *             returned indicates whether the element passed as first argument
 *             is considered to go before the second in the ordering it
 *             defines.
 *
 * @brief -- for each code "section"
 *        1st LOOP iterates from first to mid && mid to last element (respectively)
 *        IF executes if Comparator for right, left halves returns true, copy right's value
 *        to the sorted vector. Increment right index.
 *        ELSE IF executes if Comparator for left, right halves returns true, copy left's
 *        value to the sorted vector. Increment left index.
 *        ELSE IF executes if left value equals right value, copy's both values to vector
 *        and increment's both indexes.
 *        2nd LOOP iterates through elements left in right half only if none left in right 
 *        half, copy's value to sorted vector. Increments left half index.
 *        3rd LOOP iterates through elements left in left half only if none right in left 
 *        half, copy's value to sorted vector. Increments right half index
 *        4th LOOP copy back values of elements from sorted vector to OUR vector
 * 
 * @details 
 *      My implementation of the merge function, which compares two values. 
 *      One value iterates from mid to last while the other iterates from first 
 *      to mid. Check statements used for different comparisons of the values, which are 
 *      copied to a now sorted vector. After initial loop ends execution, go into 
 *      either 'leftover' loop ONLY when the two merge halves are not the same length. 
 *      This loop proceeds to copy rest of 'leftover' value from sorted vector to change 
 *      values in current vector.  
 * 
 * *************************************/

template<typename RandomAccessIterator, typename Comparator>
void merge(RandomAccessIterator first, RandomAccessIterator mid, RandomAccessIterator last, Comparator comp){

  std::vector<typename RandomAccessIterator::value_type> merge_vector;
  RandomAccessIterator left = first, right = mid;
  merge_vector.reserve(distance(first,last));
//loop compares left half and right half of vector, & copy's correct value to vector
  while(right < last && left < mid){
    //right's value is inserted to sorted vector when Comparator right, left returns true
    if(comp(*right,*left)){
      merge_vector.push_back(*right++);
    }
    //left's value is inserted to sorted vector when Comparator left, right returns true
    else if(comp(*left,*right)){
      merge_vector.push_back(*left++);
    }
    //insert both left and right's value to sorted vector when they are the same value
    else if(*left == *right){
      merge_vector.push_back(*left++);
      merge_vector.push_back(*right++);
    }
  }
//loops push_back whatever values remain in either half, only one will ever execute
  while(right >= last && left < mid){
    merge_vector.push_back(*left++);
  }
  while(right < last && left >= mid){
    merge_vector.push_back(*right++);
  }

//copy's sorted vector back to our original vector
  RandomAccessIterator index = first;
  for(auto element : merge_vector){
    *index = element;
    index++;
  }
}




/******************************
 * 
 * @brief Your implementation of merging n/k sorted sequences of size k
 * @tparam RandomAccessIterator Random Access Iterator
 * @tparam Compare Comparator function
 * @param k Maximum size of each sorted sequence
 * @param first Initial position of first sequence to be merged
 * @param last Final position of last sequence to be merged
 * @param comp Binary function that accepts two elements in the range as
 *             arguments and returns a value convertable to bool. The value
 *             returned indicates whether the element passed as first argument
 *             is considered to go before the second in the ordering it
 *             defines.
 *
 * @brief -- for each code "section"
 *        IF executes if size is less than or equal to k, sorts sub-vector(first, last) using
 *        using insertion sort function. Returns.
 *        RECURSION 1: recurses through left half of sub-vector, creating sub-vector(first, midpoint)
 *        RECURSION 2: recurses through right half of sub-vector, creating sub-vector(midpoint, last)
 *        @note for RECURSION 1 --> midpoint is an iterator to element after last element
 *              for RECURSION 2 --> last is an iterator to element after last element
 *              ^^which is why midpoint is used as both 'last' element for left sub-vector and
 *                the 'first' element for right sub-vector instead of midpoint + 1 for
 *                right sub-vector
 *        MERGE FUNCTION : merges both left and right sorted sub-vectors into a single sorted
 *        vector 
 * 
 * @details
 *      My implementation of merging n/k function, which checks if the size of  
 *      sub-vector is greater than the maximum size of sub-sequences. When it's not
 *      sub-vector is sorted and returned. When it is, recursion on left and right
 *      half of sub-vector begins. After recursion the two sorted sub-vectors
 *      are merged into a singular sub-vector.
 * 
 * ****************************/

template<typename RandomAccessIterator, typename Comparator>
void merge_k(long int k, RandomAccessIterator first, RandomAccessIterator last, Comparator comp){
  long int size = distance(first, last);
//sort current vector recursion (implemented through insertion sort) and return when the size of
//    vector is less than or equal to k, which is the max-size of each sub-vector
  if(size <= k){
    insertion_sort(first, last, comp);
    return;
  }
  RandomAccessIterator midpoint = first + (floor(size/k));
//recursively split merge_k into 2 halves until the size is less than or equal to k
  merge_k(k, first, midpoint, comp);
  merge_k(k, midpoint, last, comp);
//merge function takes two sorted vectors and 'merges' into a single sorted vector
//takes each of the halves and merges these into a single sorted vector which is returned
//and will be merged with another sorted vector etc. etc.
  merge(first, midpoint, last, comp);
}




/***********************************
 * 
 * @brief Your implementation of merge sort
 * @tparam RandomAccessIterator Random Access Iterator
 * @tparam Compare Comparator function
 * @param first Initial position of sequence to be sorted
 * @param last Final position of sequence to be sorted
 * @param k  Each sub-sequence maximum size at lowest level
 * @param comp Binary function that accepts two elements in the range as
 *             arguments and returns a value convertable to bool. The value
 *             returned indicates whether the element passed as first argument
 *             is considered to go before the second in the ordering it
 *             defines.	
 * 
 * @brief -- for each code "section"
 *        IF executes if size is less than or equal to 1 (k), sends sub-vector to function call merge_k. Returns.
 *        RECURSION 1: recurses through left half of sub-vector, creating sub-vector(first, midpoint)
 *        RECURSION 2: recurses through right half of sub-vector, creating sub-vector(midpoint, last)
 *        @note for RECURSION 1 --> midpoint is an iterator to element after last element
 *              for RECURSION 2 --> last is an iterator to element after last element
 *              ^^which is why midpoint is used as both 'last' element for left sub-vector and
 *                the 'first' element for right sub-vector instead of midpoint + 1 for
 *                right sub-vector
 *        MERGE FUNCTION : merges both left and right sorted sub-vectors into a single sorted
 *        vector 
 * 
 * @details
 *      My implementation of the merge sort function, which checks if the size of  
 *      sub-vector is greater than the maximum size of sub-sequences, which is 1. When 
 *      it's not merge_k is called, and returns. When it is, recursion on left and right
 *      half of sub-vector begins. After recursion the two sorted sub-vectors
 *      are merged into a singular sub-vector.
 * 
 * ************************************/

template<typename RandomAccessIterator, typename Comparator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last, Comparator comp, long int k = 1){
  long int size = distance(first, last);
//send sub-vector recursion to function merge_k and return when size of vector is less than or equal to 1 (k)
//which is our max size for each sub vector
	if(size <= k){
    merge_k(k, first, last, comp);
    return;
  }
  else{
    RandomAccessIterator midpoint = first + (floor(size/2));
  //recursively split merge_sort into 2 halves until the size is less than or equal to 1 (k)
    merge_sort(first, midpoint, comp, k);
    merge_sort(midpoint, last, comp, k);
  //merge function takes two sorted vectors and 'merges' into a single sorted vector
  //takes each of the halves and merges into a single sorted vector which is returned
  //and will be merged with another sorted sub vector etc. etc.
    merge(first, midpoint, last, comp);
  }
}

}

#endif
