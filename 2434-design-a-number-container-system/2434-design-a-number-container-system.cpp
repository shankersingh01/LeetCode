class NumberContainers {
public:
    unordered_map<int, set<int>> map;
    unordered_map<int, int> currMap;

    NumberContainers() {}

    void change(int index, int number) {

        if (currMap.find(index) != currMap.end()) {
            map[currMap[index]].erase(index);
            if (map[currMap[index]].empty())
                map.erase(currMap[index]);
        }
        currMap[index] = number;
        map[number].insert(index);
    }

    int find(int number) {
        if (map.find(number) != map.end()) {
            return *map[number].begin();
        } else
            return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */