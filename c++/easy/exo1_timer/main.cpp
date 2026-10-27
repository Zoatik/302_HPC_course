#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    cout << "Hello World!" << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);

    cout << "Execution time : " << duration.count() << " microseconds" << endl;

    return 0;
}