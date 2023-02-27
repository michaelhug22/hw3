#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator())
		: m_(m), comp_(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){
		// delete the data vector
    data_.clear();
	}
  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item){
		data_.push_back(item);
		int index = data_.size() - 1;
		while(index > 0){
				int parentIndex = (index - 1)/ m_;
				if (comp_(data_[index], data_[parentIndex])){//swap if comparison is true
					std::swap(data_[index], data_[parentIndex]);
					index = parentIndex; // set new index after swap
				}
				else {
					break;
				}
		}
	}

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const{
		if(empty()){
			throw std::underflow_error("Empty Heap");//throw error if empty
		}
		return data_[0];// else return top element
	}

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
    void pop(){
	 	if (empty()){
	 		throw std::underflow_error("Empty Heap");// cant pop from heap if its empty
	 	}
	 	data_[0] = data_.back();//swap with first element then trickle down
	 	data_.pop_back();//remove what was the top element, now at the back
	 	int index = 0;// begin trickle down
	 	while (true) {
	 		int childIndex = m_ * index + 1;
	 		if (childIndex >= data_.size()){//exit loop if the childIndex is the last element
	 			break;
	 		}
	 		int smallestChildIndex = childIndex;
	 		for ( int j = 1; j < m_ && (childIndex + j) < data_.size(); j++) {// compare for each m ary child 
         if (comp_(data_[childIndex + j], data_[smallestChildIndex])) {
           smallestChildIndex = childIndex + j;
         }
     	}
	 		if (comp_(data_[smallestChildIndex], data_[index])){
	 			std::swap(data_[index], data_[smallestChildIndex]);
	 			index = smallestChildIndex;
	 		}
	 		else{
	 			break;
	 		}
	 	}
	}

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
		return data_.empty();
	}

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{
		return data_.size();
	}

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator comp_;
};

// Add implementation of member functions here

/*
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
	throw std::underflow_error("Empty Heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return data_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
	throw std::underflow_error("Empty Heap");
  }
		data_[0] = data_.back();//swap with first element then trickle down
		data_.pop_back();//remove what was the top element, now at the back
		int index = 0;// begin trickle down
		while (true) {
			int childIndex = m_ * index + 1;
			if (childIndex >= data_.size()){//exit loop if the childIndex is the last element
				break;
			}
			int smallestChildIndex = childIndex;
			for (int j = 1; j < m_ && (childIndex + j) < data_.size(); j++) {// compare for each m ary child 
        if (comp_(data_[childIndex + j], data_[smallestChildIndex])) {
          smallestChildIndex = childIndex + j;
        }
    	}
			if (comp_(data_[smallestChildIndex], data_[index])){
				std::swap(data_[index], data_[smallestChildIndex]);
				index = smallestChildIndex;
			}
			else{
				break;
			}
		}
}
*/
#endif

