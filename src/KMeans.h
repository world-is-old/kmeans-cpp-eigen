//
// Created by nikita on 09.01.2020.
//

#ifndef KMEANS_CPP_KMEANS_H
#define KMEANS_CPP_KMEANS_H


#include <Eigen/Core>
#include <vector>
#include "Data.h"

using namespace Eigen;

namespace KMeans {
    MatrixXd run(Data& data, int cluster_num, int max_iterations);
}


#endif //KMEANS_CPP_KMEANS_H
