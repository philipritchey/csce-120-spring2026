#include <cassert>
#include <print>
#include "linked_list.h"

void test_create_empty_list() {
    // When I create a list
    // Then the list should be empty
    LinkedList<int> list;
    assert(list.empty());
}

void test_add_value() {
    {
        // Given an empty list
        // When I add the value 7
        // Then the list should not be empty
        // And the front of the list should be 7
        // And the list should have 1 item
        LinkedList<int> list;
        list.add(7);
        assert(not list.empty());
        assert(list.front() == 7);
        list.remove();
        assert(list.empty());
    }

    {
        // Given an empty list
        // When I add the values 7, 6
        // Then the list should have 2 items: [6, 7]
        LinkedList<int> list;
        list.add(7);
        list.add(6);
        assert(list.front() == 6);
        list.remove();
        assert(not list.empty());
        assert(list.front() == 7);
        list.remove();
        assert(list.empty());
    }
}

void test_remove_values() {
    // Given the list [8, 6, 7, 5, 3, 0, 9]
    // When I remove 3 items
    // Then the list should contain 4 items: [5, 3, 0, 9]
    LinkedList<int> list;
    list.add(9);
    list.add(0);
    list.add(3);
    list.add(5);
    list.add(7);
    list.add(6);
    list.add(8);
    for (int i = 0; i < 3; i++) { list.remove(); }
    assert(not list.empty());
    assert(list.front() == 5);
    list.remove();
    assert(not list.empty());
    assert(list.front() == 3);
    list.remove();
    assert(not list.empty());
    assert(list.front() == 0);
    list.remove();
    assert(not list.empty());
    assert(list.front() == 9);
    list.remove();
    assert(list.empty());
}

void test_front_of_empty() {
    // Given an empty list
    // When I attempt to access the first element
    // Then an out_of_range exception should be thrown
    LinkedList<int> list;
    bool exception_thrown = false;
    try {
        list.front();
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
}

void test_remove_from_empty() {
    // Given an empty list
    // When I attempt to remove a value
    // Then an out_of_range exception should be thrown
    LinkedList<int> list;
    bool exception_thrown = false;
    try {
        list.remove();
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
}

int main() {
    test_create_empty_list();
    test_add_value();
    test_remove_values();
    test_front_of_empty();
    test_remove_from_empty();

    std::println("all tests passing");

    return 0;
}
