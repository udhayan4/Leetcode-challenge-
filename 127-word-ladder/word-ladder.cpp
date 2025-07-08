class Solution {
public:

    int usingBFS(string &beginWord, string &endWord, vector<string> &wordList) {
        // each unique set, act like already visited
        unordered_set<string> st(wordList.begin(), wordList.end());

        // string, distance
        queue<pair<string, int>> q;
        
        // init.
        q.push({beginWord, 1});
        // erase from set if exists
        st.erase(beginWord);
        
        while(!q.empty()) {
            // access front
            auto frontNode = q.front();
            string frontString = frontNode.first;
            int frontDistance = frontNode.second;
            q.pop();

            // check if frontNode == endWord
            if (frontString == endWord) {
                return frontDistance;
            }

            // change each char from a -> z
            int n = frontString.size();
            for (int i = 0; i < n; i++) {
                char ogChar = frontString[i];
                // replace ith cahr
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    frontString[i] = ch;

                    // check new string is in set - valid string
                    if (st.find(frontString) != st.end()) {
                        q.push({frontString, frontDistance + 1});
                        // delete from set
                        st.erase(frontString);
                    }
                }

                // bt - convert to orginal state
                frontString[i] = ogChar;
            }
        }

        // not found
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 01 aproach using bfs
        return usingBFS(beginWord, endWord, wordList);
    }
};