#include <iostream>
#include <string>

class Item {
protected:
    std::string name;
    double price;
    int quantity;

public:
    // Default / Parameterized Constructor
    Item(std::string n = "", double p = 0.0, int q = 0) 
        : name(n), price(p), quantity(q) {}

    // Virtual Destructor
    virtual ~Item() {}

    // Copy Constructor
    Item(const Item& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Item& operator=(const Item& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Function to calculate total item cost
    double calculateSum() const {
        return price * quantity;
    }

    // Display details
    virtual void display() const = 0;

    // Getters
    std::string getName() const { return name; }
};

// Fruit Class
class Fruit : public Item {
public:
    Fruit(std::string n = "", double p = 0.0, int q = 0) : Item(n, p, q) {}

    ~Fruit() override {}

    Fruit(const Fruit& other) : Item(other) {}

    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            Item::operator=(other);
        }
        return *this;
    }

    void display() const override {
        std::cout << "[Fruit]     " << name << " | Price: PHP " << price 
                  << " | Qty: x" << quantity 
                  << " | Total: PHP " << calculateSum() << "\n";
    }
};

// Vegetable Class
class Vegetable : public Item {
public:
    Vegetable(std::string n = "", double p = 0.0, int q = 0) : Item(n, p, q) {}

    ~Vegetable() override {}

    Vegetable(const Vegetable& other) : Item(other) {}

    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            Item::operator=(other);
        }
        return *this;
    }

    void display() const override {
        std::cout << "[Vegetable] " << name << " | Price: PHP " << price 
                  << " | Qty: x" << quantity 
                  << " | Total: PHP " << calculateSum() << "\n";
    }
};

// Problem 3: Function to calculate total sum of all objects in the list
double TotalSum(Item* GroceryList[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        if (GroceryList[i] != nullptr) {
            total += GroceryList[i]->calculateSum();
        }
    }
    return total;
}

// Helper function to display the entire list
void displayGroceryList(Item* GroceryList[], int size) {
    std::cout << "--------------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        if (GroceryList[i] != nullptr) {
            GroceryList[i]->display();
        }
    }
    std::cout << "--------------------------------------------------\n";
}

int main() {
    int size = 4;

    // Problem 2: Create dynamic instances and store pointers in GroceryList array
    Item** GroceryList = new Item*[size];

    GroceryList[0] = new Fruit("Apple", 10.0, 7);
    GroceryList[1] = new Fruit("Banana", 10.0, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60.0, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50.0, 10);

    std::cout << "=== Jenna's Initial Grocery List ===\n";
    displayGroceryList(GroceryList, size);

    // Problem 3: Calculate and display Total Sum
    std::cout << "Total Sum: PHP " << TotalSum(GroceryList, size) << "\n\n";

    // Problem 4: Delete Lettuce and de-allocate memory
    std::cout << "=== Removing 'Lettuce' from Grocery List... ===\n";
    for (int i = 0; i < size; ++i) {
        if (GroceryList[i] != nullptr && GroceryList[i]->getName() == "Lettuce") {
            delete GroceryList[i];      // Free allocated object
            GroceryList[i] = nullptr;   // Set pointer to nullptr
        }
    }

    std::cout << "Updated List:\n";
    displayGroceryList(GroceryList, size);

    // Recalculate total
    std::cout << "Updated Total Sum: PHP " << TotalSum(GroceryList, size) << "\n\n";

    // Clean up remaining allocated memory
    for (int i = 0; i < size; ++i) {
        delete GroceryList[i];
    }
    delete[] GroceryList;

    return 0;
}