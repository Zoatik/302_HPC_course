#include <iostream>
#include <fstream>
#include <chrono>
#include <string>


using namespace std;
using namespace std::chrono;

int main() {
    cout << "Enter you number : ";
    int number;
    cin >> number;
    
    string mult_out = "multiples.txt";
    string results_out = "results.txt";
    ofstream fout;

    // loop to calculate all mutliples with endl
    auto start = high_resolution_clock::now();
    fout.open(mult_out);
    for (uint i = 1; i <= 100000; i++){
        fout << i * number << endl;
    }
    fout.close();

    // determine execution time and print it
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);

    fout.open(results_out);
    fout << "Execution time (endl): " << duration.count() << " microseconds" << endl;
    fout << "Number chosen : " << number;

    // loop to calculate all mutliples with \n
    start = high_resolution_clock::now();
    fout.open(mult_out);
    for (uint i = 1; i <= 100000; i++){
        fout << i * number << "\n";
    }
    fout.close();
    
    // determine execution time and print it
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end-start);

    fout.open(results_out, ios::app);
    fout << "\nExecution time (\\n): " << duration.count() << " microseconds" << endl;
    fout << "Number chosen : " << number;


    return 0;
}