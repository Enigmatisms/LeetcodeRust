#include <iostream>
#include <iomanip>

int main() {
    int num_dishes = 0;
    std::cin >> num_dishes;
    std::cin.get();
    double total_cost = 0, total_discount = 0;
    for (int i = 0; i < num_dishes; i++) {
        double dish_cost = 0, discount = 0;
        std::cin >> dish_cost >> discount;
        if (discount > dish_cost || discount <= 0) {
            std::cout << "error" << std::endl;
            return 0;
        }
        total_cost += dish_cost;
        total_discount += discount;
    }
    double threshold = 0, refund = 0;
    std::cin >> threshold >> refund;
    if (refund > threshold || refund <= 0) {
        std::cout << "error" << std::endl;
        return 0;
    }
    if (total_cost >= threshold) total_cost -= refund;
    double result = total_cost < total_discount ? total_cost : total_discount;
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    return 0;
}