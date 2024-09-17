#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> allConstruct(string target, vector<string>& wordBank) {
    if (target == "") return {{}};

    vector<vector<string>> result;

    for (string word : wordBank) {
        if (target.find(word) == 0) { // If the word matches the prefix of the target
            string suffix = target.substr(word.length());
            vector<vector<string>> suffixWays = allConstruct(suffix, wordBank);
            for (vector<string>& way : suffixWays) {
                way.insert(way.begin(), word);
                result.push_back(way);
            }
        }
    }

    return result;
}

int main() {
    vector<string> wordBank1 = {"purp", "p", "ur", "le", "purpl"};
    vector<vector<string>> result1 = allConstruct("purple", wordBank1);
    for (auto& vec : result1) {
        cout << "[ ";
        for (auto& str : vec) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    cout << endl;

    vector<string> wordBank2 = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    vector<vector<string>> result2 = allConstruct("abcdef", wordBank2);
    for (auto& vec : result2) {
        cout << "[ ";
        for (auto& str : vec) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

