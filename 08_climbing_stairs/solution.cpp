#include <vector>

int climb_stairs(int target_steps) {
    if (target_steps <= 1) {
        return 1;
    }

    int count_of_ones = 1;
    int count_of_twos = 0;

    for (int step = 2; step <= target_steps; step++) {
        int next_count_of_ones = count_of_ones + count_of_twos;
        int next_count_of_twos = count_of_ones;

        count_of_ones = next_count_of_ones;
        count_of_twos = next_count_of_twos;
    }

    return count_of_ones + count_of_twos;
}
