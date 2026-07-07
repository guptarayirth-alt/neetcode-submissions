class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rt;
        for(const string& str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            rt[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto &it : rt)
        {
             result.push_back(it.second);
        }
        
        return result;
    }
};