#include <iostream>
#include <string>

using namespace std;

// Base interface 
class Cutie {
public:
    virtual string description() = 0;
    virtual int cuteness_rating() = 0;
    virtual ~Cutie() = default;
};

// Example classes implementing Cutie
class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }
    int cuteness_rating() override {
        return 10;
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A fluffy kitten with a soft purr";
    }
    int cuteness_rating() override {
        return 9;
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny monkey with big eyes and fluffy fur";
    }
    int cuteness_rating() override {
        return 8;
    }
};
class QueueTees {
private:
    static const int MAX_SIZE = 5; 
    Cutie* queue[MAX_SIZE];
    int front, end, count;

public:
    QueueTees() : front(0), end(0), count(0) {}

    void queued(Cutie& cutie) {
        if (count == MAX_SIZE) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        queue[end] = &cutie;
        end = (end + 1) % MAX_SIZE;
        count++;
        cout << "queued: " << cutie.description() << endl;
    }

    Cutie* dequeue() {
        if (count == 0) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return nullptr;
        }
        Cutie* removed = queue[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        cout << "removed: " << removed->description() << endl;
        return removed;
    }

    int size() {
        cout << "Current queue size: " << count << endl;
        return count;
    }
};
int main() {
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    QueueTees queue;

    queue.size();

    queue.queued(puppy);
    queue.queued(kitty);
    queue.queued(marmoset);

    queue.size();

    queue.dequeue(); // Puppy
    queue.dequeue(); // Kitty
    queue.dequeue(); // Pygmy Marmoset

    queue.size();

    return 0;
}