#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    template<typename T>
    class BinaryTree {

    private:
    struct Node {
        T value;
        Node* right_son;
        Node* left_son;
        Node(const T& v, Node* l, Node* r)
                : value(v), right_son(r), left_son(l) {
        }
    };

    class iterator {
    private:
        Node* pointer_to_current_node;
    public:

        iterator(Node* ptr = nullptr)
                : pointer_to_current_node(ptr) {
        }

        // Note that the method is const as this operator does not
        // allow changing of the iterator.
        // Note that it returns T& as it allows to change what it points to.
        // A const_iterator class will return const T&
        // and the method will still be const
        T& operator*() const {
            //return *pointer_to_current_node;
            return pointer_to_current_node->value;
        }

        T* operator->() const {
            return &(pointer_to_current_node->value);
        }

        
        iterator& operator++() {
            //++pointer_to_current_node;
            pointer_to_current_node = pointer_to_current_node->right_son;
            return *this;
        }

        // i++;
        // Usually iterators are passed by value and not by const& as they are small.
        const iterator operator++(int) {
            iterator tmp= *this;
            pointer_to_current_node= pointer_to_current_node->left_son;
            return tmp;
        }

        bool operator==(const iterator& rhs) const {
            return pointer_to_current_node == rhs.pointer_to_current_node;
        }

        bool operator!=(const iterator& rhs) const {
            return pointer_to_current_node != rhs.pointer_to_current_node;
        }
    };  // END OF CLASS ITERATOR

        Node* root;
    public:
        BinaryTree(){}
        ~BinaryTree(){}
        BinaryTree<T>& add_root(T r)
        {
            //root->value = 6;
            return *this;
        }
        BinaryTree<T>& add_left(T e, T a)
        {
            return *this;
        }
        BinaryTree<T>& add_right(T e, T a)
        {
            return *this;
        }
        iterator begin()
        {
            return iterator(root);
        }
        iterator end()
        {
            return iterator(root);
        }

        iterator end_preorder()
        {
            return iterator(root);
        }
        iterator begin_preorder()
        {
            return iterator(root);
        }
        iterator end_inorder()
        {
            return iterator(root);
        }
        iterator begin_inorder()
        {
            return iterator(root);
        }
        iterator end_postorder()
        {
            return iterator(root);
        }
        iterator begin_postorder()
        {
            return iterator(root);
        }
        friend std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &bt)
        {
            //out << root->value << endl;
            out << "Hello" << endl;
            return out;
        }
    };
}