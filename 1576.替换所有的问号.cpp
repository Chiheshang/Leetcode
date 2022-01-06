/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]!='?')continue;
            else{
                //cout<<i<<endl;
                for(char cur='a';cur<'z';cur++){
                    //cout<<cur<<endl;
                    if((i>0&&s[i-1]==cur)||(i<(s.size()-1)&&s[i+1]==cur)){
                        continue;
                    }
                    else{
                        s[i]=cur;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
// @lc code=end

