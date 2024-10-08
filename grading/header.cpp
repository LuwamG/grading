#include "grading.hpp"
#include <iostream>
using namespace std;

int main() {
    int count = 0;

    input_scores(count);
    display_results(count);
    compare_results(count);

    return 0;
}
