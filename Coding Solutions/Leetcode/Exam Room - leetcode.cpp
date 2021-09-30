class ExamRoom {
public:
    set<int> seats;
    int N;
    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        if (seats.size() == 0) {
            seats.insert(0);
            return 0;
        }

        int prev = -1, maxD = 0, idx = 0;
        if (*seats.begin() != 0) {
            idx = 0;
            maxD = *seats.begin();
        }

        for (int x : seats) {
            int curr = x;
            if (prev != -1) {
                int d = (curr - prev) / 2;
                if (d > maxD) {
                    maxD = d;
                    idx = prev + maxD;
                }
            }
            prev = curr;
        }

        if (N - 1 - prev > maxD) {
            idx = N - 1;
        }
        seats.insert(idx);
        return idx;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */