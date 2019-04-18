#include <iostream>

struct S {
public:
    int i = 42;

    void print() const noexcept {
        std::cout << i << '\n';
    }
};

class C {
private:
    S s;
    int i = 10;

public:
    // default constructor
    C() {
        std::cout << "default constructed\n";
    }

    // copy constructor
    C(const C& other) :
        s(other.s),
        i(other.i) {
        std::cout << "copy constructed\n";
    }

    // move constructor
    C(C&& other) :
        s(std::move(other.s)),         // explicit move of a member of class type
        i(std::exchange(other.i, 0)) { // explicit move of a member of non-class type
        other.s.i = 0;
        other.i = 0;
        std::cout << "move constructed\n";
    }

    // copy assignment
    C& operator= (const C& other) {
        s = other.s;
        i = other.i;
        std::cout << "copy assigned\n";
        return *this;
    }

    // move assignment
    C& operator= (C&& other) {
        // 1. do not assign to own object
        if (this != &other) {
            // 2. free own resources if necessary, e.g. delete pointers
            // 3. move members
            s = std::move(other.s);
            i = std::move(other.i);
            // 4. release members of the other object.
            //    assign nullptr to pointer types, do not delete pointers of the other object.
            //    otherwise, the destructor of the other object tries to delete them again.
            other.s.i = 0;
            other.i = 0;
            std::cout << "move assigned\n";
        }
        else {
            std::cout << "move assignment to itself prevented\n";
        }
        return *this;
    }

    // destructor
    ~C() {
        std::cout << "destructed\n";
    }

    void assignToI(int new_i) {
        i = new_i;
    }

    void print() const {
        std::cout << "s.i: ";
        s.print();
        std::cout << "i: " << i << '\n';
    }
};

C rvo_succeeding() {
    C c;
    return c;
}

C rvo_failing(bool b) {
    C c1, c2;
    return b ? c1 : c2;
}

int main() {
    std::cout << "try this with different optimizations turned on or in Debug and Release mode.\nespecially the RVO features of the compiler.\n\n";

    {
        // construct
        std::cout << "# C c1, c2; #\n";
        C c1, c2;
        c1.print();
        c2.print();
        std::cout << '\n';

        // copy assign
        std::cout << "# c2 = c1; #\n";
        c2 = c1;
        c1.print();
        c2.print();
        std::cout << '\n';

        // move assign
        std::cout << "# c2 = std::move(c1); #\n";
        c2 = std::move(c1);
        c1.print();
        c2.print();
        std::cout << '\n';

        // move assign to itself
        std::cout << "# c2 = std::move(c2); #\n";
        c2 = std::move(c2);
        c2.print();
        std::cout << '\n';

        // copy construct
        std::cout << "# C c3(c2); #\n";
        C c3(c2);
        c2.print();
        c3.print();
        std::cout << '\n';

        // move construct
        std::cout << "# C c4(std::move(c3)); #\n";
        C c4(std::move(c3));
        c3.print();
        c4.print();
        std::cout << '\n';

        std::cout << "# leaving scope and cleaning up #\n";
    }
    std::cout << '\n';

    {
        // return value optimization success (RVO)
        std::cout << "# C c = rvo_succeeding(); #\n";
        C c = rvo_succeeding();
    }
    std::cout << '\n';

    {
        // return value optimization failed (RVO)
        std::cout << "# C c = rvo_failing(); #\n";
        C c = rvo_failing(true);
    }
    std::cout << '\n';

    return 0;
}
