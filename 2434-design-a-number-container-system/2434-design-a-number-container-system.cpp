class NumberContainers {
public:
    unordered_map<int, set<int>> map; // Stores {number -> set of indices}
    unordered_map<int, int> currMap;  // Stores {index -> number}

    NumberContainers() {}

    void change(int index, int number) {
        // If index already exists, remove it from its current number's set
        if (currMap.find(index) != currMap.end()) {
            int prevNumber = currMap[index];
            map[prevNumber].erase(index);

            // If no indices remain for this number, erase it from map
            if (map[prevNumber].empty()) {
                map.erase(prevNumber); // ✅ Remove the key value pair
            }
        }

        // Update mappings
        currMap[index] = number;
        map[number].insert(index);
    }

    int find(int number) {
        // If the number exists, return the smallest index
        if (map.find(number) != map.end() && !map[number].empty()) {
            return *map[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */