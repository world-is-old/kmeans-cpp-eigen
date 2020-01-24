//
// Created by nikita on 23.01.2020.
//

#ifndef KMEANS_CPP_DATA_H
#define KMEANS_CPP_DATA_H

#include <Eigen/Core>
#include <vector>
#include <random>

using namespace Eigen;
using namespace std;

class Data {
    std::mt19937 eng;
    std::uniform_int_distribution<> distr; // define the range

public:
    MatrixXd points;

    Data(std::vector<double> values, int rows, int columns);

    RowVectorXd spawnCentroid();
};


#endif //KMEANS_CPP_DATA_H
