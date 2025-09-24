// Problem Statement (abridged):
// Five philosophers sit at a round table with one fork between each pair.
// A philosopher can eat only when holding BOTH left and right forks.
// Implement synchronization so that:
//   • Forks are picked and put correctly.
//   • No deadlock occurs.
//   • Each “molecule” of actions for one meal is: pick 2 forks -> eat -> put 2 forks.
//
// -----------------------------------------------------------------------------
// Approach: Ordered Fork Locking (Deadlock-Free)
// ----------------------------------------------------------------------------
// Classic deadlock happens if each philosopher picks one fork and waits for the
// other. To avoid deadlock without extra threads/structures, we impose a global
// ordering on resources (forks) and always acquire them in that order.
//
// Implementation details:
//   • Let left = i, right = (i+1)%5.
//   • first = min(left, right), second = max(left, right).
//   • Lock fork[first], then fork[second]. This produces a strict global order
//     on fork acquisition, eliminating circular wait (no deadlock).
//   • After both are locked, call the provided callbacks in the correct semantic
//     order: pickLeft/pickRight -> eat -> putLeft/putRight.
//   • Locks are released automatically by RAII when the function returns.
//
// Notes on starvation:
//   • With mutexes, practical solutions accepted by LeetCode don’t strictly
//     *prove* starvation freedom, but the strict total order plus fair mutex
//     scheduling avoids deadlock and passes the judge.
//
// Time Complexity per call: O(1) synchronization.
// Space: O(1).
//
// ============================================================================

#include <vector> //include is like c++ version of import for python and import from in JS
#include <algorithm> //min, max, sort etc...
#include <cmath> //math functions like pow and sqrt
#include <functional> //needed to pass functions

using namespace std; //saves from writing std; everwhere. So for python instead of writing math.sqrt() you just do sqrt() since you have "from math import *"

class DiningPhilosophers {
private:
    array<mutex, 5> forks; //5 forks protected by a mutex (mutual exclusion: stops from multiple threads from accessing same resource at same time)

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left  = philosopher; //left fork index
        int right = (philosopher + 1) % 5; //right fork index and makes it wrap around

        int first  = min(left, right); // makes lock smaller index first?
        int second = max(left, right);

        
        unique_lock<mutex> lk1(forks[first]); //locks both forks in order (RAII does it automically)
        unique_lock<mutex> lk2(forks[second]); //as soon as they are created it locks the forks mutex

        
        if (first == left) { //here pick up both forks, eat and then put them down
            
            pickLeftFork(); //if left fork was locked first
            pickRightFork();
            eat();
            putRightFork();
            putLeftFork();
        } else {
            
            pickRightFork(); //if right fork was locked first
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
        }
        //locks release auto when lk1 and lk2 are out of scope
    }
};
