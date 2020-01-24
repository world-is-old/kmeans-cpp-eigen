//
// Created by nikita on 23.01.2020.
//

#include "Data.h"

Data::Data(std::vector<double> values, int rows, int columns) {
    points = MatrixXd(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            points(i, j) = values[i * columns + j];
        }
    }

    std::random_device rd; // obtain a random number from hardware
    eng = std::mt19937(rd()); // seed the generator
    distr = std::uniform_int_distribution<>(0, points.rows() - 1); // define the range
}

//init centroids with random points from data set
RowVectorXd Data::spawnCentroid() {
    return (RowVectorXd) points.row(distr(eng)).eval();
}
