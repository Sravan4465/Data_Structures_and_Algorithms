#include<bits/stdc++.h>
using namespace std;

class solution {
   public:
   vector<string> pretty_json(string& str) {
     auto r = 0;  
    vector<string> result(1, "");
    int brace = 1;
    for (auto i = 0; i < str.length(); ++i) {
        switch (str[i]) {
            // Space just ignore.
            case ' ':
                continue;

            case '{':
            case '[':
                // If first brace.
                if (brace == 1 && r == 0)  
                    result[r] += str[i];
                else {
                    // Make a new line and add adequate spaces and increment braces.
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                    result[r] += str[i];
                    ++brace;
                }
                result.push_back("");
                result[++r] += string(brace, '\t');
                break;

            case '}':
            case ']':
                // Make a new line and decrement braces.
                if (brace > 1) {
                    result.push_back("");
                    result[++r] += string(brace - 1, '\t');
                    result[r] += str[i];
                    --brace;
                } else {
                    result.push_back("");
                    result[++r] += str[i];
                    --brace;
                }
                break;

            case ',':
                result[r] += str[i];
                // Corner case check.
                if (str[i + 1] == '{' || str[i + 1] == '[')
                    continue;
                else {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                }
                break;

            case ':':
                result[r] += str[i];
                if (str[i + 1] == '{' || str[i + 1] == '[') {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                    result[r] += str[++i];
                    ++brace;
                    if (str[i + 1] != '{' && str[i + 1] != '[') {
                        result.push_back("");
                        result[++r] += string(brace, '\t');
                        result[r] += str[++i];
                    }
                }
                break;

            default:
                // For all other cases.
                result[r] += str[i];
                break;
        }
        
    }
    return result;
   }

};

int main() {

solution obj;

string str;
cin>>str;

vector<string> ans = obj.pretty_json(str);
for(auto it : ans) {
    cout<<it<<endl;
}

return 0;
}