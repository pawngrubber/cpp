#include <vector>

class VectorConsumer {
    private:
        const std::vector<int> & vec;
        int idx = 0;

    public:
        int val = 0;
        bool is_empty = false;

        VectorConsumer(const std::vector<int> & input_vec) : vec(input_vec) {
            if (vec.empty()) {
                is_empty = true;
            }
            else {
                val = vec[0];
            }
        }

        void consume() {
            idx++;
            if (idx < (int)vec.size()) {
                val = vec[idx];
            }
            else {
                is_empty = true;
            }
        }
};

std::vector<int> merge_sorted(
    const std::vector<int> & nums1, 
    const std::vector<int> & nums2
) {
    VectorConsumer consumer1(nums1);
    VectorConsumer consumer2(nums2);

    std::vector<int> output = {};

    while (true) {
        if (consumer1.is_empty && consumer2.is_empty) {
            break;
        }
        else if (consumer1.is_empty) {
            output.push_back(consumer2.val);
            consumer2.consume();
        }
        else if (consumer2.is_empty) {
            output.push_back(consumer1.val);
            consumer1.consume();
        }
        else {
            if (consumer1.val <= consumer2.val) {
                output.push_back(consumer1.val);
                consumer1.consume();
            }
            else {
                output.push_back(consumer2.val);
                consumer2.consume();
            }
        }
    }

    return output;
}
