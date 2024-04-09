#include "Tree.hpp"

int main() {
    Tree<int> tree;
    auto root = tree.add_node(nullptr, 1);
    auto two = tree.add_node(root, 2);
    tree.add_node(two, 4);
    tree.add_node(two, 5);
    auto three = tree.add_node(root, 3);
    tree.add_node(three, 6);
    tree.add_node(three, 7);
    tree.print();
    std::cout << "Count: " << tree.count(root) << "\n";
    tree.delete_node(two);
    std::cout << "Count: " << tree.count(root) << "\n";
    auto find = tree.find_node(6, [](const int& a, const int& b){
        return a == b;
    });
    std::cout << "Find: " << reinterpret_cast<void*>(find) << "\n";
    auto eight = tree.insert_node(three, 0, 8);
    auto nine = tree.insert_node(three, 1, 9);
    auto ten = tree.insert_node(root, 0, 10);
    std::cout << "Count: " << tree.count(root) << "\n";
    auto sort_fn = [](const int& a, const int& b){
        return a < b;
    };
    tree.sort(three, sort_fn);
    tree.print();
}
