// Problem Statement (abridged):
// Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.
//Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. 
//Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. 
//After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. 
//A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.
//Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.
//Design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., 
//each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.
// ============================================================================

#include <vector> //include is like c++ version of import for python and import from in JS
#include <algorithm> //min, max, sort etc...
#include <cmath> //math functions like pow and sqrt
#include <functional> //needed to pass functions
#include <array> //for making array containers
#include <mutex> //mutex and unique lock


using namespace std; //saves from writing std:: everwhere. So for python instead of writing math.sqrt() you just do sqrt() since you have "from math import *"

class DiningPhilosophers {
private:
    array<mutex, 5> forks; //5 forks protected by a mutex (mutual exclusion: stops from multiple threads from accessing same resource at same time)

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher, //defines wantToEat function
                    function<void()> pickLeftFork, //void is return type of function, doesnt return a value but performs an action
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left  = philosopher; //left fork index (0-4 philosophers)
        int right = (philosopher + 1) % 5; //right fork index and makes it wrap around (right fork is one clockwise) (% works as remainder after division) (3+1)%5=4%5, (4+1)%5=5%5 because of wrap-around

        int first  = min(left, right); // makes the lower indexed lock first
        int second = max(left, right);

        
        unique_lock<mutex> lk1(forks[first]); //locks both forks in order 
        unique_lock<mutex> lk2(forks[second]); //RAII: these unlock automaticly when lk1/2 are out of scope

        
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
        //locks auto release here
    }
};
