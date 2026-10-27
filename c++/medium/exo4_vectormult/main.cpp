#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]){
    if (argc < 2) return 1;

    unsigned* times = new unsigned[argc-1];
    
    for(uint j = 1; j < argc; j++){
        uint size;

        try{
            size = stoi(argv[j]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }

        float* vec1 = new float[size];
        float* vec2 = new float[size];

        float HI = 10000.0;
        float LO = -HI;
        srand (static_cast<unsigned> (time(0)));

        // Generate 2 vectors with random values
        for(uint i = 0; i < size; i++){

            float rand1 = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
            float rand2 = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));

            vec1[i] = rand1;
            vec2[i] = rand2;
        }

        auto start = high_resolution_clock::now();
        
        // Scalar multiplication of the two vectors
        float scalar_res = 0.0;
        for(uint i = 0; i < size; i++){
            scalar_res += vec1[i] * vec2[i];
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end-start);

        times[j-1] = static_cast<unsigned> (duration.count());

        delete [] vec1;
        delete [] vec2;
    }
    
    float* mults = new float[argc-2];

    cout << endl;
    for (int i = 0; i < argc-1; i++){
        cout << argv[i+1] << " elements : ";
        cout << times[i] << " microseconds" << endl;
        if (i < argc-2){
            mults[i] = times[i+1] / float(times[i]);
            cout << "factor : " << mults[i] << endl;
        }
    }



    delete [] times;
    delete [] mults;

    return 0;
}