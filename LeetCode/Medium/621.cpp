//执行用时：140 ms, 在所有 C++ 提交中击败了67.40% 的用户
//内存消耗：34 MB, 在所有 C++ 提交中击败了42.32% 的用户
class Solution {
private:
    static int conv_Alpha2Int(char ch) { return ch - 'A'; }

    struct tasklist {
        int ntasks[26];
        char tasks[26];
        int size;

        void insert(char ch) {
            int ix = conv_Alpha2Int(ch);
            if (ntasks[ix] == 0) { ntasks[ix] = 1; tasks[size++] = ch; }
            else { ++ntasks[ix]; }
        }

        void sort() {
            std::sort(tasks, tasks + size,
                [this](char lhs, char rhs) -> bool {
                    return this->ntasks[conv_Alpha2Int(lhs)] > this->ntasks[conv_Alpha2Int(rhs)];
                });
        }

        int execute(int n) {
            int nexecute = std::min(n, size), ntimes = 0;
            for (int i = 0; i < size && ntimes < nexecute; ++ntimes, ++i) {
                int ix = conv_Alpha2Int(tasks[i]);
                ntasks[ix] = ntasks[ix] - 1;
                if (ntasks[ix] == 0) {
                    for (int j = i; j < size && j < 25; ++j) { tasks[j] = tasks[j + 1]; }
                    --size;
                    i = i - 1;
                }
            }
            sort();
            return nexecute;
        }

        bool contains(char ch) { return ntasks[conv_Alpha2Int(ch)] != 0; }

        void log() {
            std::cout << size << "\n";
            for (int i = 0; i < size; ++i) {
                std::cout << tasks[i] << " " << ntasks[conv_Alpha2Int(tasks[i])] << std::endl;
            }
        }

        tasklist() : size(0) { bzero(ntasks, sizeof(ntasks)); }
    };


public:
    int leastInterval(vector<char>& tasks, int n) {
        tasklist taskls;
        int execute_tiems = n + 1;
        int ret{ 0 };

        for (char ch : tasks) { taskls.insert(ch); }

        //taskls.sort();
        //taskls.log();

        while (taskls.size != 0) {
            int nexecute = taskls.execute(execute_tiems);
            //taskls.log();
            if (taskls.size == 0) { ret += nexecute; }
            else { ret += execute_tiems; }
        }

        return ret;
    }
};
