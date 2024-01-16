#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct cc {
    int charcount[26];
    bool operator<(const cc& other) const {
        for (int i = 0; i < 26; i++) {
            if (charcount[i] != other.charcount[i]) {
                return charcount[i] < other.charcount[i];
            }
        }
        return false;
    }
} cc;

cc statcc(string word) {
    cc res;
    for (int i = 0; i < 26; i++) {
        res.charcount[i] = 0;
    }
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        res.charcount[index] += 1;
    }
    return res;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    map<cc, vector<string> > hash;
    vector<vector<string> > res;
    for (int i = 0; i < strs.size(); i++) {
        string word = strs[i];
        cc index = statcc(word);
        hash[index].push_back(word);
    }
    for (auto iter = hash.begin(); iter != hash.end(); iter++) {
        res.push_back(iter->second);
    }
    return res;
}

int main() {
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    vector<vector<string> > result = groupAnagrams(strs);

    for (const auto& group : result) {
        cout << "Anagram group: ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
