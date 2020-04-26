/**

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >db;
        for(auto it : strs)
        {
            string str = it;
            sort(str.begin(),str.end());
            db[str].push_back(it);
        }
        vector< vector<string> > res;
        for(auto it : db)
        {
            res.push_back(it.second);
        }
        return res;
    }
};