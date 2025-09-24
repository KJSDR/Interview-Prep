// Problem Statement:
// There are two kinds of threads: hydrogen and oxygen. Threads should pass a
// barrier in groups of three to form H2O (2 H + 1 O). Ensure that threads from
// one molecule bond (pass) before any from the next molecule do.
//
// -----------------------------------------------------------------------------
// Key Requirements:
// - Exactly 2 hydrogens and 1 oxygen pass together as a molecule.
// - Threads must wait until a complete molecule can be formed.
// - All threads of one molecule must pass before the next molecule starts.
//
// -----------------------------------------------------------------------------
// Approach: Counting Semaphores + Reusable Barrier (O(1) space/thread)
//
// We simulate permits with a simple counting semaphore (implemented via
// mutex + condition_variable since LeetCode C++ may not provide <semaphore>).
//
// Idea:
//   • Allow at most 2 H threads and 1 O thread to pass for the current molecule.
//     -> hSem initialized to 2, oSem initialized to 1
//   • After each thread prints (bonds), it calls finish():
//       - increment a shared counter 'cnt' protected by a mutex
//       - when cnt == 3 (i.e., 2H + 1O finished), reset cnt to 0 and
//         release permits for the next molecule: hSem.release(2), oSem.release(1)
//   • This ensures the next molecule cannot start until all 3 threads from the
//     current molecule have released (i.e., printed), satisfying the barrier.
//
// Correctness:
//   - Capacity gating (2 H + 1 O) via semaphores enforces proper composition.
//   - Barrier via cnt ensures that the next trio cannot begin until the current
//     trio has completely finished printing.
//
// -----------------------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

class H2O {
private:
    class Semaphore {
        int permits;
        mutex m;
        condition_variable cv;
    public:
        explicit Semaphore(int p) : permits(p) {}
        void acquire() {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [&]{ return permits > 0; });
            --permits;
        }
        void release(int k = 1) {
            unique_lock<mutex> lk(m);
            permits += k;
            cv.notify_all();
        }
    };

    Semaphore hSem{2};  
    Semaphore oSem{1};  

    mutex cnt_mtx;    
    int cnt = 0;  

    void finishOne() {
        unique_lock<mutex> lk(cnt_mtx);
        ++cnt;
        if (cnt == 3) {
           
            cnt = 0;
            hSem.release(2);
            oSem.release(1);
        }
        
    }

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        hSem.acquire();

        
        releaseHydrogen();

        finishOne();
    }

    void oxygen(function<void()> releaseOxygen) {
        oSem.acquire();

       
        releaseOxygen();

        finishOne();
    }
};
