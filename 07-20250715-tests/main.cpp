#include <vector>
#include <unordered_map>

float gini(std::vector<int> y) {
    if (y.empty()) return 0.0f;

    std::unordered_map<int, int> class_counts;
    for (int label : y) {
        class_counts[label]++;
    }

    float sum = 0.0f;
    int n = y.size();
    for (const auto& kv : class_counts) {
        float p = static_cast<float>(kv.second) / n;
        sum += p * p;
    }
    return 1 - sum;
}


class DecisionTree1D {
    // Best_split = argmax(Gain(split)) for all possible splits

    public:
        void fit (std::vector<float> X, std::vector<int> y) {  // todo: pass maxDepth
            // assume X is sorted
            // Fit the decision tree model (generate 2 subtrees)
            // todo: stop if maxDepth is reached
            int n_samples = X.size();


            for (float i = 0; i <= 1; i+=0.01f) {  // run 101 times

                int n_samples = X.size();
                std::vector<float> XLeft, XRight;
                std::vector<int> yLeft, yRight;

                for (size_t j = 0; j < n_samples; j++) {
                    if (X[j] <= i) {
                        XLeft.push_back(X[j]);
                        yLeft.push_back(y[j]);
                    } else {
                        XRight.push_back(X[j]);
                        yRight.push_back(y[j]);
                    }
                }

                // Compute Gini gain
                float gini_split = XLeft.size() / n_samples * gini(yLeft) + XRight.size() / n_samples * gini(yRight);
            }

            // TODO: take argmax of gini_split

        }
    

    private:
        int split_val;  // todo: split_axis?
        // todo: store values of y
};



// void main () {
//     // Your code here
// }
