#include <string>
#include <vector>
#include <set>
#include <algorithm>

struct Candidate {
    std::string val;
    bool end = false;
};

bool unique(std::string key) {
    std::set<char> my_set;
    for (int i=0; i<key.size(); i++) {
        my_set.insert(key[i]);
    }
    return my_set.size() == key.size();
}

int count(std::string key){

    std::vector<Candidate> candidates = {};
    for (int i=0, s=key.size(); i<s; i++) {
        std::string k = key.substr(i, 1);
        for (int i=0; i<candidates.size(); i++) {
            Candidate & candidate = candidates[i];
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
