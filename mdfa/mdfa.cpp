#include <iostream>
#include <map>
#include <set>

using namespace std;


class FinAutomata {
public:
    int statesCount = 0;
    int startState = 1;
    map<pair<int, char>, int> nextState;
    set<int> allowedStates;

    FinAutomata() {}
    FinAutomata(const FinAutomata& other) {
        statesCount = other.statesCount;
        startState = other.startState;
        nextState = other.nextState;
        allowedStates = other.allowedStates;
    }

    ~FinAutomata() {} 
    
    FinAutomata& operator=(const FinAutomata& other) {
        statesCount = other.statesCount;
        startState = other.startState;
        nextState = other.nextState;
        allowedStates = other.allowedStates;
        return *this;
    }

    void addState() {
        statesCount++;
    }

    void removeState(int state) {
        allowedStates.erase(state);
        for(map<pair<int, char>, int>::iterator it = nextState.begin(); it != nextState.end(); it++) {
            const int& key = (it->first).first;
            const int& value = it->second;
            if (key == state || value == state) nextState.erase(it);
        }
        if (statesCount != state) return;
        statesCount--;
        while (true) {
            for(map<pair<int, char>, int>::iterator it = nextState.begin(); it != nextState.end(); it++) {
                const int& key = (it->first).first;
                const int& value = it->second;
                if (key == statesCount || value == state) return;
            } 
            statesCount--;
        }
    }
    
    void addTransition(int firstState, char symbol, int secondState) {
        nextState.insert(make_pair(make_pair(firstState, symbol), secondState));
    }

    void removeTransition(int state, char symbol) {
        map<pair<int, char>, int>::iterator it = nextState.find(make_pair(state, symbol));
        if (it != nextState.end()) nextState.erase(it);
    }

    void modifyTransition(int state, char symbol, int newState) {
        map<pair<int, char>, int>::iterator it = nextState.find(make_pair(state, symbol));
        if (it != nextState.end()) it->second = newState;
    }

    void chStatus(int state, bool allow) {
        if (allow) allowedStates.insert(state);
        else allowedStates.erase(state);
    }

    void chStart(int newStart) {
        startState = newStart;
    }

    void renumerate(const map<int, int>& statesMap) {
        map<pair<int, char>, int> updatedMap;
        for (map<pair<int, char>, int>::iterator it = nextState.begin(); it != nextState.end(); it++) {
            int newKey = statesMap.at(it->first.first);
            int newValue = statesMap.at(it->second);
            updatedMap[make_pair(newKey, it->first.second)] = newValue;
        }
        nextState = move(updatedMap);
    }

    bool operator() (const string& s) {
        int state = startState;
        long unsigned int i = 0;
        while(s[i] != '\0') {
            state = nextState[make_pair(state, s[i])];
            i++;
        }
        return allowedStates.count(state);
    }

    void del() {
        set<int> possibleStates;
        possibleStates.insert(startState);
        while(true) {
            for(const auto i: possibleStates) {
                for(const auto j: nextState) {
                    set<int> newPossible = possibleStates;
                    if(j.first.first == i) newPossible.insert(j.second);
                }
            }
            if(newPossible == possibleStates) break;
            possibleStates = move(newPossible);
        }
        map<int, int> statesMap;
        int i = 0;
        int j = 0;
        for (int k = 1; k <= statesCount; k++) {
            if(possibleStates.count(k)) statesMap.insert(make_pair(k, ++i));
            else statesMap.insert(make_pair(k, ++j + possibleStates.size()));
        }
        renumerate(statesMap);
        if (j != 0) removeState(statesCount);
    }

    void optimize

    friend ostream& operator<< (ostream& os, const FinAutomata& dfa);
};

ostream& operator<< (ostream& os, const FinAutomata& dfa) {
    os << "States count: " << dfa.statesCount << "\n";
    os << "Start state: " << dfa.startState << "\n";
    os << "Allowed states:";
    for (auto it = dfa.allowedStates.begin(); it != dfa.allowedStates.end(); it++) {
        cout << " " << *it;
    }
    os << "\n";
    os << "States transitions map:\n";
    for (auto it = dfa.nextState.begin(); it != dfa.nextState.end(); it++) {
        cout << it->first.first << " " << it->first.second << " " << it->second << "\n";
    }
    return os;
}

int main() {
    FinAutomata a;
    for (int i = 0; i < 4; i++) {
        a.addState();
    }
    a.addTransition(1, '0', 2);
    a.addTransition(1, '1', 1);
    a.addTransition(2, '0', 3);
    a.addTransition(2, '1', 1);
    a.addTransition(3, '0', 4);
    a.addTransition(3, '1', 1);
    a.addTransition(4, '0', 4);
    a.addTransition(4, '1', 4);
    a.chStatus(4, true);
    cout << a;
    cout << a("000") << " " << a("100") << " " << a("0010") << " " << a("1010001");
    return 0;
}