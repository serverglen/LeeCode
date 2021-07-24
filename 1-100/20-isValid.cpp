/** 
 * 20. 有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 示例 1：
 * 输入：s = "()"
 *输出：true
 *示例 2：
 *
 *输入：s = "()[]{}"
 *输出：true
 *示例 3：
 *
 *输入：s = "(]"
 *输出：false
 *示例 4：
 *
 *输入：s = "([)]"
 *输出：false
 *示例 5：

 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 
*/

class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> strmap = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };
        std::stack<char> stack;
        for (char& c : s) {
            if(strmap.find(c) != strmap.end()) {
                if (stack.empty() || stack.top() != strmap[c]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};