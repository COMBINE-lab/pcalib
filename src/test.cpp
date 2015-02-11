#include "PCA.hpp"
#include "Eigen/Dense"
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ifstream ifile(argv[1]);
    size_t nr, nc;
    ifile >> nr;
    ifile >> nc;
    size_t numEnt = nr * nc;
    std::vector<double> data(numEnt, 0.0);
    for (size_t i = 0; i < numEnt; ++i) {
        ifile >> data[i];
    }
    Eigen::Map<Eigen::MatrixXd> m(&data[0], nr, nc);
    std::cout << m << "\n";
    PCA p(m);
    std::cerr << "before decomp\n";
    p.performDecomposition();
    auto projected = p.projectedData(0.95);
    std::cerr << "projected = " << projected << "\n";
}
