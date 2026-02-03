# CPPAlgos-Lib

I built my own versions of standard C++ algorithms to learn how generic programming and iterators work.

## How it works

* **Non-Modifying Algorithms**: Includes functions like `find`, `count`, `accumulate`, and `search`. These look through data without changing it.
* **Modifying Algorithms**: Includes `reverse`, `remove`, `generate`, and `transform`. These change the order or values of the data in the container.
* **Templates**: Everything is written with templates so they work with different data types and standard containers like `std::vector`.

## Files included

* **myAlgos.h**: The main header with all the function declarations.
* **myAlgos.impl.h**: The actual implementation of the algorithm logic.

## Usage Example

```cpp
#include "myAlgos.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    int sum = my::accumulate(v.begin(), v.end(), 0);
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
