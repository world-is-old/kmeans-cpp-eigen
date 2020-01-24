#include <iostream>
#include <Eigen/Core>
#include <chrono>

#include "utils.h"
#include "KMeans.h"

using namespace Utils;
using namespace std;

int main() {

    cout << "reading data" << endl;
    auto begin = chrono::system_clock::now();

    Data data = readData("../data/data.csv", 2, 100000);

    cout << "data read time: " << ((std::chrono::duration<double>)(std::chrono::system_clock::now() - begin)).count() << endl;
    begin = chrono::system_clock::now();

    const MatrixXd centroids = KMeans::run(data, 2, 100);

    cout << "run time: " << ((std::chrono::duration<double>)(std::chrono::system_clock::now() - begin)).count() << endl;
    cout << centroids;

    return 0;
}
