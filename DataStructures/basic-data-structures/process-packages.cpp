#include "iostream"
#include "vector"
#include "queue"


struct Request {

    int arrival_time;
    int process_time;

    Request(int arrival_time, int process_time) : arrival_time(arrival_time), process_time(process_time) {

    }
};


struct Response {

    bool dropped;
    int start_time;

    Response(bool _dropped, int _start_time) : dropped(_dropped), start_time(_start_time) {

    }
};


class Buffer {
private:
    int size_;
    std::queue<int> finish_time_;

public:
    explicit Buffer(int size) : size_(size), finish_time_() {

    }

    /**
     * Key Idea:
     * When each process i comes, decide:
     *     if it will be dropped or not?
     *     if enqueued, what is its start/finish time?
     * Pop all packets in buffer that have already finished;
     * If buffer is full, drop i and output -1;
     * Determine the start_time by queue:
     *     if queue is empty, process i as it arrives;
     *     else, enqueue i after last finish_time;
     *     (i.e. should wait in queue if not idle)
     *
     * @param request
     * @return
     */

    Response process(const Request &request) {
        // free buffer only when the process has finished
        while (!finish_time_.empty() && finish_time_.front() <= request.arrival_time) {

            // remove first request
            finish_time_.pop();
        }

        // if the buffer is full drop the response
        if (finish_time_.size() == size_) {
            return {true, -1};
        }

        // compute the start time and enqueue the finish tim
        int current_start_time = finish_time_.empty() ? request.arrival_time : finish_time_.back();

        finish_time_.push(current_start_time + request.process_time);
        return {false, current_start_time};
    }

};

std::vector<Request> read_requests() {
    std::vector<Request> requests;
    int count;

    std::cin >> count;

    for (int i = 0; i < count; i++) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;

        requests.push_back(Request(arrival_time, process_time));

    }

    return requests;
}

std::vector<Response> process_requests(std::vector<Request> &requests, Buffer *buffer) {
    std::vector<Response> responses;
    responses.reserve(requests.size());

    for (Request request : requests)
        responses.push_back(buffer->process(request));

    return responses;
}


void print_responses(std::vector<Response> &responses) {

    for (Response &response : responses)
        std::cout << (response.dropped ? -1 : response.start_time) << std::endl;
}

/*
int main() {
    int size;

    std::cin >> size;

    std::vector<Request> requests = read_requests();

    Buffer buffer(size);

    std::vector<Response> responses = process_requests(requests, &buffer);

    print_responses(responses);

    return 0;
}*/
