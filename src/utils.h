//
// Created by nikita on 09.01.2020.
//

#ifndef KMEANS_CPP_UTILS_H
#define KMEANS_CPP_UTILS_H

#include <vector>
#include <sstream>
#include <fstream>
#include <Eigen/Core>
#include "Data.h"

using namespace Eigen;

namespace Utils {
    Data readData(const std::string &filepath, int vector_size, int limit) {
        std::ifstream inStream(filepath);
        std::string line;

        int lines = 0;
        std::vector<double> pointCoords;
        while (std::getline(inStream, line) && lines < limit) {
            lines++;
            std::istringstream iStrStream(line);
            double coord = 0.0;
            while (iStrStream >> coord) {
                pointCoords.push_back(coord);
            }
        }
        inStream.close();
        return Data(pointCoords, lines, vector_size);
    }
}
#endif //KMEANS_CPP_UTILS_H
