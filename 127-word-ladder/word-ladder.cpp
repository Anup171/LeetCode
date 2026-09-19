class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found=false;
        for(string &word:wordList){
            if(word==endWord){
                found=true;
                break;
            }
        }
        if(!found) return 0;
        unordered_map<string,vector<string>>nei;
        wordList.push_back(beginWord);
        for(string &word:wordList){
            for(int j=0;j<word.size();j++){
                string pattern = word;
                pattern[j]='*';
                nei[pattern].push_back(word);
            }
        }
        unordered_set<string> visit;
        queue<string> q;
        q.push(beginWord);
        visit.insert(beginWord);
        int res=1;
        while(!q.empty()){
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return res;
                }
                for (int j = 0; j < word.size(); j++) {
                    string pattern = word;
                    pattern[j] = '*';
                    for (string& neiWord : nei[pattern]) {
                        if (visit.find(neiWord) == visit.end()) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};