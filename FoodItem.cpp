#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

// Structure to store food item details
struct FoodItem {
    int itemId;              // Unique ID of the food item
    string name;             // Name of the food item
    double price;            // Price of the food item
    int calories;            // Calories of the food item
    vector<string> ingredients; // List of ingredients
};

// Function to find the price difference between the most expensive and the cheapest food item
double findPriceDifference(vector<FoodItem>& foodItems) {
    double maxPrice = INT_MIN; // Initialize max price to the smallest integer
    double minPrice = INT_MAX; // Initialize min price to the largest integer

    int i = 0;
    while (i < foodItems.size()) {
        if (foodItems[i].price > maxPrice) {
            maxPrice = foodItems[i].price; // Update max price
        }
        if (foodItems[i].price < minPrice) {
            minPrice = foodItems[i].price; // Update min price
        }
        i++;
    }

    return maxPrice - minPrice; // Return the difference
}

// Function to find the average calories of food items that cost more than $5
double findAverageCalories(vector<FoodItem>& foodItems) {
    double totalCalories = 0; // Sum of calories
    int count = 0;            // Count of food items with price > $5

    int i = 0;
    while (i < foodItems.size()) {
        if (foodItems[i].price > 5) {
            totalCalories += foodItems[i].calories; // Add calories
            count++; // Increment count
        }
        i++;
    }

    //return (count == 0) ? 0 : totalCalories / count; // Calculate average

    if (count == 0) {
    return 0; // No food items with price > 5, return 0
    }
else {
    return totalCalories / count; // Calculate average
}

}

int main() {
    // Vector of FoodItem structures
    vector<FoodItem> foodItems = {
        {1, "Burger", 8.99, 500, {"Bun", "Beef Patty", "Cheese", "Lettuce", "Tomato"}},
        {2, "Pizza", 12.50, 800, {"Dough", "Tomato Sauce", "Cheese", "Pepperoni"}},
        {3, "Salad", 4.99, 200, {"Lettuce", "Tomato", "Cucumber", "Olive Oil"}},
        {4, "Pasta", 7.75, 600, {"Pasta", "Tomato Sauce", "Parmesan Cheese"}},
        {5, "Sandwich", 6.50, 400, {"Bread", "Ham", "Cheese", "Lettuce"}},
        {6, "Sushi", 15.00, 300, {"Rice", "Nori", "Fish"}}
    };

    // Calculate price difference
    double priceDifference = findPriceDifference(foodItems);
    // Calculate average calories for food items priced > $5
    double averageCalories = findAverageCalories(foodItems);

    // Output results
    cout << "Price difference between the most expensive and the cheapest food item: $" << priceDifference << endl;
    cout << "Average calories of food items that cost more than $5: " << averageCalories << " calories" << endl;

    return 0;
}

