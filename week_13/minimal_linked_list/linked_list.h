#pragma once

/**
 * LinkedList
 *   - head: pointer to Item
 *   + (constructor)
 *   + empty() -> bool
 *   + add(value: T)
 *   + front() -> T
 *   + remove()
 */
template <typename T>
class LinkedList {
    /**
     * Item
     *   + value: T
     *   + next: pointer to Item
     *   + (constructor)
     */
    struct Item {
        T value;
        Item* next;

        explicit Item(T const& value, Item* next = nullptr)
        : value{value}
        , next{next} {}
    };

    Item* head;

 public:
        LinkedList() : head{nullptr} {}

        bool empty() const { return head == nullptr; }

        void add(T const& value) {
            head = new Item(value, head);
        }

        T front() const {
            if (empty()) {
                throw std::out_of_range("front: list is empty");
            }
            return head->value;
        }

        void remove() {
            if (empty()) {
                throw std::out_of_range("remove: list is empty");
            }
            Item* old_head = head;
            head = head->next;
            delete old_head;
        }
};
