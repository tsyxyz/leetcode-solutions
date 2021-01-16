#include <vector>

#include <gtest/gtest.h>

using namespace std;

class UF {
public:
    UF(int n) : count_(n), parent_(vector<int>(n)), size_(vector<int>(n)) {
        for (size_t i = 0; i < parent_.size(); ++i) {
            parent_[i] = i;
            size_[i] = 1;
        }
    }

    void Unite(int p, int q) {
        int root_p = Find(p);
        int root_q = Find(q);
        if (root_p == root_q) {
            return;
        }

        if (size_[root_p] > size_[root_q]) {
            parent_[root_q] = root_p;
            size_[root_p] += size_[root_q];
        } else {
            parent_[root_p] = root_q;
            size_[root_q] += size_[root_p];
        }
        count_--;
    }

    int Find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    bool Connected(int p, int q) {
        int root_p = Find(p);
        int root_q = Find(q);
        return root_p == root_q;
    }

    int Count() {
        return count_;
        return 0;
    }

private:
    int count_;
    vector<int> parent_;
    vector<int> size_;


};

TEST(TestUnionFind, case01) {

}