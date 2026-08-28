#include <iostream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse_list(ListNode* head);

ListNode* build_list(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

std::vector<int> to_vector(ListNode* head) {
    std::vector<int> res;
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

void free_list(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

std::string format_vec(const std::vector<int>& v) {
    std::string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += std::to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    s += "]";
    return s;
}

struct TestCase {
    std::vector<int> input;
    std::vector<int> expected;
};

int main() {
    std::vector<TestCase> cases = {
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{1, 2}, {2, 1}},
        {{}, {}},
        {{7}, {7}},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        ListNode* head = build_list(tc.input);
        ListNode* reversed = reverse_list(head);
        std::vector<int> actual = to_vector(reversed);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  input=" << format_vec(tc.input)
                  << "  expected " << format_vec(tc.expected)
                  << "  got " << format_vec(actual) << "\n";
        free_list(reversed);
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
