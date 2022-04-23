#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (not LinkedList::IsEmpty()) {
        Node* lst = nullptr;
        Node* ths = front_;
        Node* nxt = front_->next;

        while (ths != back_) {
          ths->next = lst;
          lst = ths;
          ths = nxt;
          nxt = ths->next;
        }
        ths->next = lst;
        Node* temple = front_;
        front_ = back_;
        back_ = temple;
      }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (not LinkedList::IsEmpty()) {
      LinkedList::reverse_recursive_helper(front_, nullptr);
    }
    Node* temple = front_;
    front_ = back_;
    back_ = temple;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr->next != nullptr) {
      LinkedList::reverse_recursive_helper(curr->next, curr);
    }
    curr->next = prev;
  }

}  // namespace assignment
