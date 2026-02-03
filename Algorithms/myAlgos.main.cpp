#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "myAlgos.h"

int main() {
    // 1. Test my::accumulate with integers
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int sum = my::accumulate(nums.begin(), nums.end(), 0);
    assert(sum == 15);
    std::cout << "Test Accumulate: PASSED" << std::endl;

    // 2. Test my::find with strings
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    auto it = my::find(words.begin(), words.end(), "banana");
    assert(it != words.end() && *it == "banana");
    std::cout << "Test Find: PASSED" << std::endl;

    // 3. Test my::reverse
    std::vector<int> rev_me = {1, 2, 3};
    my::reverse(rev_me.begin(), rev_me.end());
    assert(rev_me[0] == 3 && rev_me[2] == 1);
    std::cout << "Test Reverse: PASSED" << std::endl;

    // 4. Test my::remove (the "Erase-Remove" idiom logic)
    std::vector<int> vals = {1, 2, 1, 3, 1};
    auto new_end = my::remove(vals.begin(), vals.end(), 1);
    // After remove, the elements from begin to new_end should be {2, 3}
    assert(std::distance(vals.begin(), new_end) == 2);
    std::cout << "Test Remove: PASSED" << std::endl;

    std::cout << "\nAll algorithms working perfectly!" << std::endl;

    return 0;
}