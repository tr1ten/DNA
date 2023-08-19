#include <iostream>
#include <string>
#include <vector>

int code(char x) {
    return x - 'a';
}

bool check(const std::string& x, const std::string& y) {
    int i = 0;
    for (char a : y) {
        if (i < x.length() && (x[i] == a || code(x[i]) == (code(a) + 1) % 26)) {
            i++;
        }
    }
    return i == x.length();
}

std::vector<std::string> solve(const std::vector<std::string>& old, const std::vector<std::string>& new_strings) {
    std::vector<std::string> ans;

    for (size_t i = 0; i < old.size() && i < new_strings.size(); i++) {
        if (check(old[i], new_strings[i])) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }
    return ans;
}

int main() {
    std::vector<std::string> old = { "bdbf","aee" };
    std::vector<std::string> new_strings = { "aaccbbee","aab"};

    std::vector<std::string> result = solve(old, new_strings);
    for (const std::string& res : result) {
        std::cout << res << std::endl;
    }

    return 0;
}
