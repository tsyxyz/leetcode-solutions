#include <vector>
#include <string>
#include <map>

#include <gtest/gtest.h>

using namespace std;

class UnionFind {
public:
    UnionFind(const vector<vector<string>>& equations, const vector<double>& values) {
        map<string, int> paras;
        for (size_t i = 0; i < equations.size(); ++i) {
            for (size_t j = 0; j < equations[0].size(); ++j) {
                if (paras.find(equations[i][j]) == paras.end()) {
                    paras[equations[i][j]] = paras.size();
                }
            }
        }

        parent_.resize(paras.size());
        size_.resize(paras.size());
        weight_.resize(paras.size());

        for (size_t i = 0; i < equations.size(); ++i) {
            for (size_t j = 0; j < equations[0].size(); ++j) {
                const std::string& str = equations[i][j];
                parent_[paras[str]] = paras[str];
                size_[paras[str]] = 1;
                weight_[paras[str]] = 1;
                count_++;
            }
        }
    }

    void Unite(int x, int y, double x_y) {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x == root_y) {
            return;
        }

        if (size_[root_x] > size_[root_y]) {
            parent_[root_y] = root_x;
            size_[root_x] += size_[root_y];
            double w = 1.0 / x_y;
        } else {
            parent_[root_x] = root_y;
            size_[root_y] += size_[root_x];
            double w = x_y;
        }
        count_--;
    }

    bool Connected(int x, int y) {
        int root_x = Find(x);
        int root_y = Find(y);
        return root_x == root_y;
    }

    int Count() {
        return count_;
    }

private:
    int Find(int x) {
        while (parent_[x] != x) {
            weight_[x] = weight_[x] * weight_[parent_[x]];
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

private:
    vector<int> parent_;
    vector<int> size_;
    vector<double> weight_;
    int count_ = 0;
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        return vector<double>();
    }
};

TEST(TestEvaluateDivision, case01) {

}