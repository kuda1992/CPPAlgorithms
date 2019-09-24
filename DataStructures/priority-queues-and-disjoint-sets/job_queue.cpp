#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"


class JobQueue {

private:

    struct Worker {
        int id;
        long next_free_time;

        Worker(int id) : id(id), next_free_time(0) {}

    };

    struct compare {

        bool operator()(const Worker &a, const Worker &b) {
            if (a.next_free_time == b.next_free_time) {
                return a.id > b.id;
            } else {
                return a.next_free_time > b.next_free_time;
            }
        }
    };

    int num_workers{};
    std::vector<int> jobs;

    std::vector<int> assigned_workers;
    std::vector<long long> start_times;

    void write_response() const {

        for (int i = 0; i < jobs.size(); i++) {
            std::cout << assigned_workers[i] << " " << start_times[i] << "\n";
        }
    }


    void read_data() {
        int m;

        std::cin >> num_workers >> m;

        jobs.resize(m);

        for (int i = 0; i < m; i++) {
            std::cin >> jobs[i];
        }
    }

    void assign_jobs_fast() {

        assigned_workers.resize(jobs.size());
        start_times.resize(jobs.size());

        // build a priority queue sorted by min time
        std::priority_queue<Worker, std::vector<Worker>, compare> priorityQueue;

        // push all new threads with an initial time of 0
        for (int i = 0; i < num_workers; i++)
            priorityQueue.push(Worker(i));

        // process each job by first free thread
        for (int i = 0; i < jobs.size(); i++) {
            Worker free_thread = priorityQueue.top();
            priorityQueue.pop();

            // record the jobs i assigned worked and start time
            assigned_workers[i] = free_thread.id;
            start_times[i] = free_thread.next_free_time;

            // update the next free time and offer back
            free_thread.next_free_time += jobs[i];
            priorityQueue.push(free_thread);
        }

    }

    void assign_jobs() {

        assigned_workers.resize(jobs.size());
        start_times.resize(jobs.size());

        std::vector<long long> next_free_time(num_workers, 0);

        for (int i = 0; i < jobs.size(); i++) {

            int duration = jobs[i];
            int next_worker = 0;

            for (int j = 0; j < num_workers; j++) {
                if (next_free_time[j] < next_free_time[next_worker])
                    next_worker = j;
            }

            assigned_workers[i] = next_worker;
            start_times[i] = next_free_time[next_worker];
            next_free_time[next_worker] += duration;

        }

    }

public:
    void solve() {

        read_data();
        assign_jobs_fast();
        write_response();
    }
};

/*
int main() {

    std::ios_base::sync_with_stdio(false);

    int *pInt;
    pInt = reinterpret_cast<int *>(45);

    std::cout << "the address of the int pointer is " << &pInt << "\n";
    std::cout << "the value stored is " << pInt;

    //JobQueue jobQueue;

    // jobQueue.solve();

    return 0;
}*/
