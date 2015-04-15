#include <utility>

bool pair_compare_less(const std::pair<int,
					   int>& firstElem, 
					   const std::pair<int, 
					   int>& secondElem) {
  return firstElem.second < secondElem.second;
}

bool pair_compare_greater(const std::pair<int, 
						int>& firstElem, 
						const std::pair<int, 
						int>& secondElem) {
  return firstElem.second > secondElem.second;
}
