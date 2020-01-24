//
// Created by nikita on 09.01.2020.
//

#include "KMeans.h"
#include "Data.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

namespace KMeans {

    void assignClusters(const MatrixXd& centroids, const MatrixXd& points, vector<int>& assignments) {
        //return vector of indices that map points to centroids as centroid[point[index]]
        //for each point calculate the index of nearest centroid and store it to vector
        MatrixXd distances = MatrixXd(points.rows(), centroids.rows());
        for (auto i = 0; i < points.rows(); i ++) {
            Index minDist;
            VectorXd distVector = (centroids.rowwise() - points.row(i)).rowwise().squaredNorm();
            distVector.minCoeff(&minDist);
            assignments[i] = minDist;
        }
    }

//    find all indices of the specific value in vector
    vector<int> find(vector<int>& values, int value) {
        vector<int> result;
        for (int i = 0; i < values.size(); ++i) {
            if (values[i] == value) {
                result.push_back(i);
            }
        }
        return result;
    }

    MatrixXd run(Data& data, int cluster_num, int max_iterations) {
        MatrixXd centroids = MatrixXd(cluster_num, data.points.cols());
        for (int i = 0; i < cluster_num; i++) {
            centroids.row(i) = data.spawnCentroid();
        }

        //store assignments to avoid reallocations
        vector<int> assignments = vector<int>(data.points.rows());

        int iterations = 0;
        bool converged = false;

        while (!converged && iterations < max_iterations) {
            cout << "iteration " << iterations << std::endl;
            converged = true;

            assignClusters(centroids, data.points, assignments);
            for (int i = 0; i < centroids.rows(); ++i) {
                vector<int> cluster = find(assignments, i);

                if (cluster.empty()) {
                    converged = false;
                    centroids.row(i) = data.spawnCentroid();
                } else {
                    RowVectorXd newCentroid = data.points(cluster, all).colwise().mean();
                    bool moved = (centroids.row(i).array() - newCentroid.array()).matrix().norm() > 0.01;
                    converged &= !moved;
                    centroids.row(i) = newCentroid;
                }
            }

            iterations ++;
        }

        return centroids;
    }
}

