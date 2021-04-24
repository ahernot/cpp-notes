#include <iostream>
#include <vector>


/*
g++ -std=c++11 linked_list_v2.cpp -o ll
./ll
*/

/*
TO DO:
- write class copy constructors (tough)
- make more functions compatible with vectors as inputs
*/



template <typename T>
class Node {
    
    protected:
        Node* _previous; // pointer to the previous node
        Node* _next; // pointer to the next node
        T _val; // node value

    public:
        // Class constructors
        Node(): _val(T()), _previous(nullptr), _next(nullptr) {};
        Node(const T& val): _val(val), _previous(nullptr), _next(nullptr) {};
        Node(const T& val, Node* previous): _val(val), _previous(previous), _next(nullptr) {}; // not very useful
        Node(const T& val, Node* previous, Node* next): _val(val), _previous(previous), _next(next) {};

        /*// Class copy constructor (doesn't work as would need to generate new addresses for the referenced objects...)
        Node (const Node& other) {
            this->_previous = other._previous;
            this->_next = other._next;
            this->_val = other._val;
        };*/

        void set_previous (Node* previous) {
            this->_previous = previous;
        };

        void set_next (Node* next) {
            this->_next = next;
        };


        Node* get_previous () {
            return this->_previous;
        };

        Node* get_next () {
            return this->_next;
        };

        T get_val () {
            return this->_val;
        };


        void print () {
            std::cout << this << " (val=" << this->_val << ")" << std::endl;
        };

        void print (const std::string desc) {
            std::cout << this << " (val=" << this->_val << ")" << desc << std::endl;
        };

        void print_detailed () {
            std::cout << this->_previous << " > " << this << " (" << this->_val << ") > " << this->_next << std::endl;
        };

};



template <typename T>
class LinkedList {

    protected:
        Node<T>* _front;
        Node<T>* _back;


        void regen_front() {
            // Go from _back to the furthest front it can find
            Node<T>* current = this->_back; // Set the current node as the last one

            while (current != nullptr) {

                this->_front = current;
                
                current = current->get_previous(); // Moving left
            };
        };


        void regen_back() {
            // Go from _front to the furthest back it can find
            Node<T>* current = this->_front; // Set the current node as the first one

            while (current != nullptr) {

                this->_back = current;
                
                current = current->get_next(); // Moving right
            };
        };


    public:
        // Class constructors
        LinkedList (): _front(nullptr), _back(nullptr) {};
        LinkedList (std::vector<T> vect): _front(nullptr), _back(nullptr) {
            this->add_back(vect); // Fill the linked list
        };

        /*// Class copy constructor (doesn't work)
        LinkedList (const LinkedList& other) {
            
            // Copy front node
            Node front_copy;
            front_copy = *(other._front); // copy the node
            this->_front = front_copy*;

            Node* current = (other._front)->get_next();
            // Copy all intermediary nodes (when correctly linked)
            while ((current != other._back) && (current != nullptr)) {

                Node copy;
                copy = *current; // copy the node

                // Move to next node
                current = current->get_next();
            };

        };*/

        // Class destructor
        ~LinkedList () {
            // Delete front until only nullptr left
            while (this->_front != nullptr) {
                this->remove_front();
            };
        };


        int print_from_front () {
            // Print failure if front is NULL
            if (this->_front == nullptr) { return 1; }

            // Print header
            std::cout << "linked list:" << std::endl;

            // Print front
            (this->_front)->print(" [FRONT]");
            //(this->_front)->print_detailed();

            // Initialise the current node (as the second value)
            Node<T>* current = (this->_front)->get_next();

            // Print body
            while ((current != this->_back) && (current != nullptr)) {
                
                // Print current node
                current->print();
                //current->print_detailed();

                // Move to next node
                current = current->get_next();
            };

            // Print back
            //(this->_back)->print_detailed();
            (this->_back)->print(" [BACK]");

            // Print success
            return 0;
        };


        void add_front (const T& val) {

            // Save previous front
            Node<T>* prev_front = this->_front;
            
            // Set _front to new front node
            this->_front = new Node<T> (val, nullptr, this->_front); // Create the Node object and link it to prev_front

            // Link previous front to _front
            if (prev_front != nullptr) {
                prev_front->set_previous(this->_front);
            };

            // Regenerate back if NULL
            if (this->_back == nullptr) {
                this->regen_back();
            };

        };


        void add_front (const std::vector<T> vect) {
            typename std::vector<T>::iterator it;
            for (it=vect.end(); it!=vect.begin(); it--) {
                this->add_front(*it);
            };
        };


        void add_back (const T& val) {

            // Save previous back
            Node<T>* prev_back = this->_back;
            
            // Set _back to new back node
            this->_back = new Node<T> (val, this->_back, nullptr);

            // Link previous back to _back
            if (prev_back != nullptr) {
                prev_back->set_next(this->_back);
            };

            // Regenerate back if NULL
            if (this->_front == nullptr) {
                this->regen_front();
            };

        };


        void add_back (const std::vector<T> vect) {
            typename std::vector<T>::iterator it;
            for (it=vect.begin(); it!=vect.end(); it++) {
                this->add_back(*it);
            };
        };


        void add_after (const T& val, Node<T>* pos) {

            if (pos == nullptr) {throw 1;};
            
            // Get next node
            Node<T>* pos_next = pos->get_next();

            // Create new node and link it
            Node<T>* pos_new = new Node<T> (val, pos, pos_next);

            // Point previous node to new node
            pos->set_next(pos_new);

            // Point next node to new node
            if (pos_next != nullptr) {
                pos_next->set_previous(pos_new);
            };

        };


        void add_before (const T& val, Node<T>* pos) {

            if (pos == nullptr) {throw 1;};

            // Get previous node
            Node<T>* pos_previous = pos->get_previous();

            // Create new node and link it
            Node<T>* pos_new = new Node<T> (val, pos_previous, pos);

            // Point previous node to new node
            if (pos_previous != nullptr) {
                pos_previous->set_next(pos_new);
            };
            
            // Point next node to new node
            pos->set_next(pos_new);

        };


        int add_in_position (const T& val, const int& pos) {

            // Initialise pointer and counter
            Node<T>* current = this->_front;
            int current_pos = 0;

            // Run through nodes
            while ((current != this->_back) && (current != nullptr)) {
                
                // Add before once reached required position
                if (pos == current_pos) {
                    this->add_before(val, current);
                    return 0;
                };

                // Move to next node and increment counter
                current = current->get_next();
                current_pos ++;

            };

            // Process last item of list
            if (current != nullptr) {
                current = current->get_next(); // getting this->_back
                current_pos ++;

                if (pos == current_pos) {
                    this->add_before(val, current);
                    return 0;
                };

            };

            return 1; // failure

        };


        T remove(Node<T>* pos) {

            // Get previous and next
            Node<T>* pos_previous = pos->get_previous();
            Node<T>* pos_next = pos->get_next();

            // Get value to return
            T pos_val = pos->get_val();

            // Delete pos
            delete pos;

            // Modify previous's next if not NULL
            if (pos_previous != nullptr) {
                pos_previous->set_next(pos_next);
            };

            // Modify next's previous if not NULL
            if (pos_next != nullptr) {
                pos_next->set_next(pos_previous);
            };

            // Return deleted value
            return pos_val;

        };


        int remove_in_position (const int& pos) {

            // Initialise pointer and counter
            Node<T>* current = this->_front;
            int current_pos = 0;

            // Run through nodes
            while ((current != this->_back) && (current != nullptr)) {
                
                // Add before once reached required position
                if (pos == current_pos) {
                    this->remove(current);
                    return 0;
                };

                // Move to next node and increment counter
                current = current->get_next();
                current_pos ++;

            };

            // Process last item of list
            if (current != nullptr) {
                current = current->get_next(); // getting this->_back
                current_pos ++;

                if (pos == current_pos) {
                    this->remove(current);
                    return 0;
                };

            };

            return 1; // failure

        };


        T remove_front () {

            // Get second node
            Node<T>* next_front = (this->_front) -> get_next();
            // Get front value to return
            T front_val = (this->_front) -> get_val();

            // Delete _front
            delete this->_front;

            // Set _front to next_front
            this->_front = next_front;

            // Set _front's previous to NULL if _front exists
            if (this->_front != nullptr) {
                (this->_front)->set_previous(nullptr);
            };
            
            // Return previous front's value
            return front_val;

        };


        T remove_back () {

            // Get second-to-last node
            Node<T>* next_back = (this->_back) -> get_previous();
            // Get back value to return
            T back_val = (this->_back) -> get_val();

            // Delete _back
            delete this->_back; // Destroy the (this->_back) node

            // Set _back to next_back
            this->_back = next_back;

            // Set _back's next to NULL if _back exists
            if (this->_back != nullptr) {
                (this->_back)->set_next(nullptr); // Set the new back's next to NULL, only if there is a new back
            };

            // Return previous back's value
            return back_val; // Return the previous front's value

        };


        bool search (const T& val) { // search from start

            // Compare with last value
                if (val == (this->_back)->get_val()) {
                    return true; // Return true if match found
            };
            
            // Initialise pointer
            Node<T>* current = this->_front;

            // Run through nodes
            while ((current != this->_back) && (current != nullptr)) {
                
                // Get current value
                T current_val = current->get_val();
                
                // Compare with requested value
                if (val == current_val) {
                    return true; // Return true if match found
                };

                // Move to next node
                current = current->get_next();

            };

            // Return false if no match found
            return false;

        };


        Node<T>* get_front () { return this->_front; };

        Node<T>* get_back () { return this->_back; };

};






int main() {

    LinkedList<int> ll;
    ll.print_from_front(); std::cout << std::endl; // will be unable to print since the list is empty

    ll.add_back(2);
    ll.print_from_front(); std::cout << std::endl;

    ll.add_back(3);
    ll.print_from_front(); std::cout << std::endl;

    ll.add_front(1);
    ll.print_from_front(); std::cout << std::endl;

    ll.remove_back();
    ll.print_from_front(); std::cout << std::endl;

    ll.remove_front();
    ll.print_from_front(); std::cout << std::endl;


    std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;


    LinkedList<float> ll2;
    ll2.print_from_front(); std::cout << std::endl; // will be unable to print since the list is empty

    ll2.add_back(2.7);
    ll2.print_from_front(); std::cout << std::endl;

    ll2.add_back(3.1);
    ll2.print_from_front(); std::cout << std::endl;

    ll2.add_front(1.02);
    ll2.print_from_front(); std::cout << std::endl;

    ll2.remove_back();
    ll2.print_from_front(); std::cout << std::endl;

    ll2.remove_front();
    ll2.print_from_front(); std::cout << std::endl;


    return 0;
}
