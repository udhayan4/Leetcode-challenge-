class Solution {
private : 
   vector<vector<string>>ans;
   map<string,int>mpp;
   string begin ;
   void dfs(string word , vector<string>s){
     if(word == begin){
        reverse(s.begin(), s.end());
        ans.push_back(s);
        reverse(s.begin(), s.end());
        return;
     }
     int level = mpp[word];
     int sz = word.size();
     for(int i = 0 ; i<sz; i++){
        char original = word[i];
        for(char ch = 'a' ; ch<='z' ; ch++){
            word[i]= ch;
            if(mpp.find(word)!=mpp.end() && mpp[word] == level-1){
                s.push_back(word);
                dfs(word,s);
                s.pop_back();
            }
        }
        word[i]=original;
     }
   }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        begin = beginWord;
        int sz = beginWord.size();
        unordered_set<string>st(wordList.begin(), wordList.end());
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            if(word == endWord)break;
            int level = mpp[word];
            q.pop();
            for(int i = 0 ; i<sz ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    word[i]=ch;
                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = level+1;
                    }
                }
                word[i] = original;
            }
        }
        //got everything in the mapp
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>s;
            s.push_back(endWord);
            dfs(endWord , s);
        }
        return ans;
    }
};