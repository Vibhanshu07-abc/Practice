#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define size 50
#define V 11
#define V1 6

struct user {
    string name;
    string product;
    int quantity;
    double bill;
    user() {}
    user(string name, string product, int quantity, double bill) {
        this->name = name;
        this->product = product;
        this->quantity = quantity;
        this->bill = bill;
    }
};

struct deliveryUser {
    user nUser;
    string address;
    double deliveryCharges;
    int distanceDelivery;
    deliveryUser *next = NULL;

    deliveryUser(string name, string product, int quantity, double bill,
                 string address, double deliveryCharges, int distanceDelivery) {
        this->nUser = user(name, product, quantity, bill);
        this->address = address;
        this->deliveryCharges = deliveryCharges;
        this->distanceDelivery = distanceDelivery;
    }
};

struct Shop {
    string name;
    string *product;
    int *price;
    string address;
    deliveryUser *nextdeliveryUser;
};

Shop* shop = NULL;
string addressF;
int distArr[V];
int distanceP[V1];
int optionDelivery = -999;
int optionDelivery1 = -999;
deliveryUser *currentdeliveryUser = NULL;

// Take-Away BST / AVL
struct takeAway {
    string name;
    string product;
    int quantity;
    double bill;
    int orderId;
    takeAway *left;
    takeAway *right;

    takeAway(string name, string product, int quantity, double bill, int orderId) {
        this->name = name;
        this->product = product;
        this->quantity = quantity;
        this->bill = bill;
        this->orderId = orderId;
        this->left = NULL;
        this->right = NULL;
    }
};

takeAway *root = NULL;

void displayTA(takeAway *node) {
    cout << "\n----------------------------------\n";
    cout << "Name : " << node->name << "\n";
    cout << "Product : " << node->product << "\n";
    cout << "Quantity : " << node->quantity << "\n";
    cout << "Bill : " << node->bill << "\n";
    cout << "Order ID: " << node->orderId << "\n";
    cout << "-----------------------------------\n";
}

takeAway *displayTakeAway(takeAway *node) {
    if (node) {
        displayTakeAway(node->left);
        displayTA(node);
        displayTakeAway(node->right);
    }
    return node;
}

int isEmptyTA(takeAway *node) {
    return node == NULL;
}

int heightTA(takeAway* node) {
    if (node == NULL) return -1;
    int lh = heightTA(node->left);
    int rh = heightTA(node->right);
    return 1 + max(lh, rh);
}

int balanceFactor(takeAway *node) {
    if (!node) return 0;
    return heightTA(node->left) - heightTA(node->right);
}

takeAway *LLRotation(takeAway *node) {
    takeAway *x = node->left;
    takeAway *temp = x->right;
    x->right = node;
    node->left = temp;
    return x;
}

takeAway *RRRotation(takeAway *node) {
    takeAway *x = node->right;
    takeAway *temp = x->left;
    x->left = node;
    node->right = temp;
    return x;
}

takeAway *LRRotation(takeAway *node) {
    node->left = RRRotation(node->left);
    return LLRotation(node);
}

takeAway *RLRotation(takeAway *node) {
    node->right = LLRotation(node->right);
    return RRRotation(node);
}

takeAway *insertTA(string name, string product, int quantity,
                   double bill, int orderId, takeAway *node) {
    if (node == NULL) {
        return new takeAway(name, product, quantity, bill, orderId);
    }
    if (orderId < node->orderId) {
        node->left = insertTA(name, product, quantity, bill, orderId, node->left);
    } else if (orderId > node->orderId) {
        node->right = insertTA(name, product, quantity, bill, orderId, node->right);
    } else {
        cout << "Duplicate order ID not allowed\n";
        return node;
    }

    int bf = balanceFactor(node);
    if (bf == 2) {
        if (orderId < node->left->orderId)
            return LLRotation(node);
        else
            return LRRotation(node);
    } else if (bf == -2) {
        if (orderId > node->right->orderId)
            return RRRotation(node);
        else
            return RLRotation(node);
    }
    return node;
}

takeAway *minValueNode(takeAway *node) {
    takeAway *current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

takeAway *deleteTA(takeAway *node, int orderId) {
    if (node == NULL) return node;
    if (orderId < node->orderId) {
        node->left = deleteTA(node->left, orderId);
    } else if (orderId > node->orderId) {
        node->right = deleteTA(node->right, orderId);
    } else {
        if (node->left == NULL) {
            takeAway *t = node->right;
            delete node;
            return t;
        } else if (node->right == NULL) {
            takeAway *t = node->left;
            delete node;
            return t;
        } else {
            takeAway *succ = minValueNode(node->right);
            node->orderId = succ->orderId;
            node->product = succ->product;
            node->name = succ->name;
            node->quantity = succ->quantity;
            node->bill = succ->bill;
            node->right = deleteTA(node->right, succ->orderId);
        }
    }
    int bf = balanceFactor(node);
    if (bf > 1 && balanceFactor(node->left) >= 0) return LLRotation(node);
    if (bf > 1 && balanceFactor(node->left) < 0) return LRRotation(node);
    if (bf < -1 && balanceFactor(node->right) <= 0) return RRRotation(node);
    if (bf < -1 && balanceFactor(node->right) > 0) return RLRotation(node);
    return node;
}

void placeOrderHomeDeliveryCustomer(string name, string product, int quantity, double bill,
                                    string address, double deliveryCharges, int distanceDelivery) {
    currentdeliveryUser = new deliveryUser(name, product, quantity, bill, address, deliveryCharges, distanceDelivery);
    if (shop->nextdeliveryUser == NULL) {
        shop->nextdeliveryUser = currentdeliveryUser;
    } else {
        deliveryUser *t = shop->nextdeliveryUser;
        while (t->next != NULL) t = t->next;
        t->next = currentdeliveryUser;
    }
    cout << "\n***************Order Details***************\n";
    cout << "Customer Name : " << name << "\n";
    cout << "Order Product : " << product << "\n";
    cout << "Quantity : " << quantity << "\n";
    cout << "Total bill : " << bill << "\n";
    cout << "Address : " << address << "\n";
    cout << "Distance in km : " << distanceDelivery << "\n";
    cout << "Delivery charges : " << deliveryCharges << "\n";
}

void displayAllOrdersHomeDeliveryCustomers() {
    if (shop->nextdeliveryUser == NULL) {
        cout << "No home delivery orders yet.\n";
    } else {
        deliveryUser *t = shop->nextdeliveryUser;
        while (t) {
            cout << "-------------------------------------------\n";
            cout << "Home Delivery Customer: " << t->nUser.name << "\n";
            cout << "Product Name: " << t->nUser.product << "\n";
            cout << "Quantity: " << t->nUser.quantity << "\n";
            cout << "Delivery Distance: " << t->distanceDelivery << " km\n";
            cout << "Delivery Charges: " << t->deliveryCharges << "\n";
            cout << "Bill: " << t->nUser.bill << "\n";
            cout << "Delivery Address: " << t->address << "\n";
            cout << "-------------------------------------------\n";
            t = t->next;
        }
    }
}

int minDistance(int dist[], bool visited[]) {
    int m = INT_MAX, idx = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < m) {
            m = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int graph[V][V], int dist[], int src) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int c = 0; c < V - 1; c++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int minKey(int distP[], bool visitedP[]) {
    int m = INT_MAX, idx = -1;
    for (int i = 0; i < V1; i++) {
        if (!visitedP[i] && distP[i] < m) {
            m = distP[i];
            idx = i;
        }
    }
    return idx;
}

void printMST(int parent[], int graphP[V1][V1]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V1; i++) {
        cout << parent[i] << " - " << i << " \t" << graphP[i][ parent[i] ] << "\n";
    }
}

void prims(int graphP[V1][V1], int distP[]) {
    int parent[V1];
    bool visitedP[V1];
    for (int i = 0; i < V1; i++) {
        distP[i] = INT_MAX;
        visitedP[i] = false;
    }
    distP[0] = 0;
    parent[0] = -1;
    for (int c = 0; c < V1 - 1; c++) {
        int u = minKey(distP, visitedP);
        visitedP[u] = true;
        for (int v = 0; v < V1; v++) {
            if (!visitedP[v] && graphP[u][v] && graphP[u][v] < distP[v]) {
                parent[v] = u;
                distP[v] = graphP[u][v];
            }
        }
    }
    // optionally you can print MST
    // printMST(parent, graphP);
}

// Uttarakhand city / area names

string CityName[] = {
    "Warehouse",
    "Dehradun",
    "Haridwar",
    "Nainital",
    "Almora",
    "Rishikesh",
    "Kashipur",
    "Haldwani",
    "Khatima",
    "Kotdwar",
    "Pauri"
};

string DehradunAreas[] = {
    "Dehradun", "Rajpur Road", "Dalanwala", "Malsi", "Bhagwanpur", "Mussoorie Road"
};
string HaridwarAreas[] = {
    "Haridwar", "Jwalapur", "Shivalik Nagar", "BHEL Colony", "Mayur Vihar", "Laldwara"
};
string NainitalAreas[] = {
    "Nainital", "Mallital", "Tibetan Market", "Tallital", "Bhimtal", "Haldwani Road"
};
string AlmoraAreas[] = {
    "Almora", "Mall Road", "Binsar Road", "Kasardevi", "Ranikhet Road", "Bhimtal Road"
};
string RishikeshAreas[] = {
    "Rishikesh", "Laxman Jhula", "Muni Ki Reti", "Shivpuri", "Tapovan", "Byasi"
};
string KashipurAreas[] = {
    "Kashipur", "Gandhinagar", "Rampur Road", "Shivpuri", "Madanpur", "Dhaulachak"
};
// You can similarly define HaldwaniAreas[], KhatimaAreas[], KotdwarAreas[], PauriAreas[] etc.

// Graph of distances between cities (example values; you may adjust)
int graphCities[V][V] = {
    {0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {5, 0, 7, 0, 0, 0, 0, 3, 0, 0, 4},
    {0, 7, 0, 0, 0, 6, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 9},
    {0, 0, 0, 4, 0, 0, 5, 0, 0, 0, 0},
    {0, 0, 6, 0, 0, 0, 0, 8, 0, 0, 0},
    {0, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0},
    {0, 3, 0, 0, 0, 8, 0, 0, 0, 7, 0},
    {0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 10},
    {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0},
    {8, 4, 5, 9, 0, 0, 0, 0, 10, 0, 0}
};

// Example subgraph for Dehradun
int DehGraph[V1][V1] = {
    {0, 3, 4, 0, 0, 0},
    {3, 0, 2, 5, 0, 0},
    {4, 2, 0, 3, 2, 4},
    {0, 5, 3, 0, 0, 3},
    {0, 0, 2, 0, 0, 2},
    {0, 0, 4, 3, 2, 0}
};

// You will need to define subgraphs for Haridwar, Nainital, Almora, etc.

int cityMenu() {
    int opt;
    cout << "\nDelivery is available in the following cities:\n";
    cout << "-------------------------------------------\n";
    cout << " | CODE |   City               |\n";
    cout << "-------------------------------------------\n";
    cout << " |  1   |   Dehradun            |\n";
    cout << " |  2   |   Haridwar            |\n";
    cout << " |  3   |   Nainital             |\n";
    cout << " |  4   |   Almora              |\n";
    cout << " |  5   |   Rishikesh           |\n";
    cout << " |  6   |   Kashipur             |\n";
    cout << " |  7   |   Haldwani             |\n";
    cout << " |  8   |   Khatima              |\n";
    cout << " |  9   |   Kotdwar              |\n";
    cout << " | 10   |   Pauri                |\n";
    cout << "-------------------------------------------\n";
    cout << "Enter your option: ";
    cin >> opt;
    return opt;
}

int DehAreaMenu() {
    int opt;
    cout << "\nDelivery areas in Dehradun:\n";
    cout << "---------------------------------\n";
    cout << " | CODE |      Area             |\n";
    cout << "---------------------------------\n";
    cout << " |  1   |   Rajpur Road         |\n";
    cout << " |  2   |   Dalanwala            |\n";
    cout << " |  3   |   Malsi                 |\n";
    cout << " |  4   |   Bhagwanpur            |\n";
    cout << " |  5   |   Mussoorie Road        |\n";
    cout << "---------------------------------\n";
    cout << "Enter your option: ";
    cin >> opt;
    return opt;
}

// Similarly you should define HarAreaMenu(), NainAreaMenu(), etc.

int furtherArea(int cityOpt) {
    int opt = -1;
    switch(cityOpt) {
        case 1: {
            prims(DehGraph, distanceP);
            opt = DehAreaMenu();
            addressF = DehradunAreas[opt];
        } break;
        case 2: {
            // prims(HarGraph, distanceP);
            // opt = HarAreaMenu();
            // addressF = HaridwarAreas[opt];
        } break;
        case 3: {
            // prims(NainGraph, distanceP);
            // opt = NainAreaMenu();
            // addressF = NainitalAreas[opt];
        } break;
        case 4: {
            // prims(AlmGraph, distanceP);
            // opt = AlmAreaMenu();
            // addressF = AlmoraAreas[opt];
        } break;
        case 5: {
            // prims(RishGraph, distanceP);
            // opt = RishAreaMenu();
            // addressF = RishikeshAreas[opt];
        } break;
        case 6: {
            // prims(KashGraph, distanceP);
            // opt = KashAreaMenu();
            // addressF = KashipurAreas[opt];
        } break;
        // Add the rest similarly
        default:
            break;
    }
    return opt;
}

int main() {
    shop = new Shop;
    shop->name = "WareHouse Uttarakhand";
    shop->address = "1, Main Warehouse, Uttarakhand";

    shop->product = new string[11] {
        "", "Sony FX30", "Sony FR7", "Canon EOS 90D", "Nikon D6",
        "Panasonic Lumix G10", "Canon EOS 250D", "Sony Alpha 7",
        "Nikon D750", "Panasonic Lumix GH5", "Canon EOS 5D Mark"
    };
    shop->price = new int[11] {
        0, 45500, 175000, 289000, 155700, 75000, 210000,
        199999, 100000, 45000, 500000
    };
    shop->nextdeliveryUser = NULL;

    int choice;
    do {
        cout << "\n************************ " << shop->name << " ************************\n";
        cout << "Location : " << shop->address << "\n";
        cout << "\n*************** Operations ***************\n";
        cout << "1. Display products & prices\n";
        cout << "2. Place Take-Away order\n";
        cout << "3. Place Home Delivery order\n";
        cout << "4. Get / collect a Take-Away order\n";
        cout << "5. Display all delivery orders\n";
        cout << "6. Display all Take-Away orders\n";
        cout << "0. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name, product;
        int productNumber, quantity, orderId, distance;
        double bill;
        string address;

        switch (choice) {
            case 1: {
                cout << "\n--------------------------------------------------\n";
                cout << "ITEM NO | ITEM NAME                 | PRICE\n";
                cout << "--------------------------------------------------\n";
                for (int i = 1; i <= 10; i++) {
                    cout << setw(5) << i << " | "
                         << setw(25) << shop->product[i] << " | "
                         << shop->price[i] << "\n";
                }
                cout << "--------------------------------------------------\n";
            } break;

            case 2: {
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter product number: ";
                cin >> productNumber;
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter order ID (integer): ";
                cin >> orderId;
                bill = quantity * shop->price[productNumber];
                root = insertTA(name, shop->product[productNumber], quantity, bill, orderId, root);
                cout << "\nOrder placed successfully!\n";
                cout << "Total bill: " << bill << "\n";
                cout << "Collect from Warehouse.\n";
            } break;

            case 3: {
                dijkstra(graphCities, distArr, 0);
                do {
                    optionDelivery = cityMenu();
                } while (!(optionDelivery >= 1 && optionDelivery <= 10));

                if (optionDelivery == 1 /* or other with area menus */) {
                    do {
                        optionDelivery1 = furtherArea(optionDelivery);
                    } while (!(optionDelivery1 >= 1 && optionDelivery1 <= 5));
                    address = CityName[optionDelivery] + " " + addressF;
                    distance = distArr[optionDelivery] + distanceP[optionDelivery1];
                } else {
                    address = CityName[optionDelivery];
                    distance = distArr[optionDelivery];
                }

                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter product number: ";
                cin >> productNumber;
                cout << "Enter quantity: ";
                cin >> quantity;

                int chargePerKm = 20;
                int deliveryCharges = chargePerKm * distance;
                bill = quantity * shop->price[productNumber] + deliveryCharges;

                placeOrderHomeDeliveryCustomer(name, shop->product[productNumber],
                                               quantity, bill, address, deliveryCharges, distance);
            } break;

            case 4: {
                cout << "Enter Order ID to collect: ";
                cin >> orderId;
                takeAway *cust = nullptr;
                // search in BST
                // Implement a search function if needed
                // For simplicity, here let's try find then delete
                // You may implement searchTA similarly as insertion logic
                // For now:
                cust = nullptr;  // placeholder
                // If you implement searchTA, assign it

                if (cust == nullptr) {
                    cout << "No such take-away order.\n";
                } else {
                    root = deleteTA(root, orderId);
                    cout << "Order is ready for collection.\n";
                }
            } break;

            case 5:
                displayAllOrdersHomeDeliveryCustomers();
                break;

            case 6:
                displayTakeAway(root);
                break;

            case 0:
                cout << "Thank you for using the system.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
