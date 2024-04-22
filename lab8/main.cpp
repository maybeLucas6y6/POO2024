#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct my_compare {
    bool operator()(const pair<string, unsigned>& A, const pair<string, unsigned>& B) const {
        if (A.second > B.second) {
            return false;
        }
        else if (A.second < B.second) {
            return true;
        }
        else {
            return A.first > B.first;
        }
    }
};

int main() {
    ifstream fin("data.txt");
    string phrase;
    getline(fin, phrase); 

    map<string, unsigned> fr;

    constexpr const char delim[] = " ,.?!";
    auto begin = phrase.find_first_not_of(delim);
    auto end = phrase.find_first_of(delim);

    while (begin != string::npos) {
        string word = phrase.substr(begin, end - begin);
        for (unsigned i = 0; i < word.size(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] -= ('A' - 'a');
            }
        }
        fr[word]++;

        begin = phrase.find_first_not_of(delim, end);
        end = phrase.find_first_of(delim, begin);
    }

    priority_queue<pair<string, unsigned>, vector<pair<string, unsigned>>, my_compare> pq;
    for (auto& e : fr) {
        pq.push(e);
    }

    while (!pq.empty()) {
        auto e = pq.top();
        pq.pop();
        cout << e.first << " " << e.second << "\n";
    }

    return 0;
}
