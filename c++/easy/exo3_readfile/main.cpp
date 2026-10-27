#include <iostream>
#include <fstream>
#include <chrono>
#include <string>


using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2){
        cerr << "The txt path is missing !" << endl;
        return 1;
    }
    string path = argv[1];

    cout << "The given path is : " << path << endl; 

    ifstream fin;

    try
    {
        fin.open(path);
        for (uint i = 0; i < 15; i++){
            int number;
            fin >> number;
            cout << number << endl;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}