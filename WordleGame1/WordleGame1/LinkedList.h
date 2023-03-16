#include <iostream>
#include <memory>
#include <cstddef>



template<typename T>
class Node
{
    T val;
    shared_ptr<Node<T>> next = nullptr;
public:
    Node(T value)
    {
        val = value;
    }
    T get_val() const;
    void set_next(shared_ptr<Node<T>>);
    shared_ptr<Node<T>> get_next() const;
};

template<typename T>
T Node<T>::get_val() const
{
    return val;
}

template<typename T>
void Node<T>::set_next(shared_ptr<Node<T>> node)
{
    next = node;
}

template<typename T>
shared_ptr<Node<T>> Node<T>::get_next() const
{
    return next;
}

// Class for the Linked List
template<typename T>
class LinkedList
{
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    size_t size_var = 0;
public:
    LinkedList()
    {
    }
    void push(T);
    T pop();
    int search(T) const;
    void print() const;
    size_t size() const;
    T operator[](int index) {

        int i = 0;

        auto curr = head;
        while (curr && curr->get_next()) {
            curr = curr->get_next();
            if (i == index) return curr->get_val();
            i++;
        }
    }

    T get(int const& index)const {
        int i = 0;
        auto curr = head;
        while (curr && curr->get_next()) {
            curr = curr->get_next();
            if (i == index) return curr->get_val();
            i++;
        }
    }


    T getRandomElement() {
        auto p = head;
        srand(time(NULL));
        int randomIndex = rand() % size();
        return get(randomIndex);
    }
};




template<typename T>
void LinkedList<T>::push(T value)
{
    auto new_node = make_shared<Node<T>>(value);

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        auto curr = head;
        while (curr && curr->get_next()) {
            curr = curr->get_next();
        }

        curr->set_next(new_node);
    }
    size_var++;
}


template<typename T>
T LinkedList<T>::pop()
{
    T value = tail->get_val();
    auto node = head;
    shared_ptr<Node<T>> prev;

    while (node)
    {
        if (node->get_next() == nullptr)
        {

            tail = prev;
            tail->set_next(nullptr);

            break;
        }
        prev = node;
        node = node->get_next();
    }
    size_var--;
    return value;
}


template<typename T>
int LinkedList<T>::search(T value) const
{
    auto node = head;
    int index = 0;
    while (node)
    {
        if (node->get_val() == value)
        {
            return index;
        }
        node = node->get_next();
        index++;
    }
    return -1;
}


template<typename T>
void LinkedList<T>::print() const
{
    auto node = head;
    cout << "Printing List: \n";
    while (node)
    {
        cout << node->get_val() << "\t";
        node = node->get_next();
    }
    cout << "\n";
}


template<typename T>
size_t LinkedList<T>::size() const
{
    return size_var;
}
