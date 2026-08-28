#include <string>
#include <vector>
#include <set>
#include <algorithm>

// Track state with the string
struct Candidate {
    std::string val;
    bool end = false;
};

bool unique(const std::string & key) { // Ampersand passes insteads of copies variable
    std::set<char> my_set;
    for (int i=0; i<key.size(); i++) {
        my_set.insert(key[i]);
    }
    return my_set.size() == key.size();
}

int count(std::string key){

    std::vector<Candidate> candidates = {};
    for (int i=0; i<(int)key.size(); i++) { // cast size_t to int
        std::string k = key.substr(i, 1);
        for (auto & candidate: candidates) {
            if (candidate.end) {
                continue;
            }
            if (unique(candidate.val + k)) {
                candidate.val = candidate.val + k;
            }
            else {
                candidate.end = true;
            }
        }
        Candidate candidate;
        candidate.val = k;
        candidates.push_back(candidate);
    }
    std::vector<int> counts = {0};
    for (auto & candidate: candidates) {
        counts.push_back(candidate.val.size());
    }
    return *std::max_element(counts.begin(), counts.end());
}
