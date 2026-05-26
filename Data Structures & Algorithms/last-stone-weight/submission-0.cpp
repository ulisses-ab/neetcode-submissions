class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto s : stones) {
            heap.push(s);
        }

        while (heap.size() > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();

            if (x == y) continue;

            heap.push(x-y);
        }

        return heap.empty() ? 0 : heap.top();
    }

    priority_queue<int> heap;
};
