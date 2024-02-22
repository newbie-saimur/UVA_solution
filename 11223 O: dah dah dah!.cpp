#include <bits/stdc++.h>
using namespace std;
#define int      long long
int _;
map<string, char> mp = {{".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'}, {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'}, {"--..", 'Z'}, {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {".----.", '\''}, {"-.-.--", '!'}, {"-..-.", '/'}, {"-.--.", '('}, {"-.--.-", ')'}, {".-...", '&'}, {"---...", ':'}, {"-.-.-.", ';'}, {"-...-", '='}, {".-.-.", '+'}, {"-....-", '-'}, {"..--.-", '_'}, {".-..-.", '\"'}, {".--.-.", '@'}};

void solve()
{
    string s; getline(cin, s);
    if (_ != 1) cout << '\n';
    cout << "Message #" << _ << '\n';
    string temp = "";
    bool f = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (temp != "") {
                cout << mp[temp];
                f = true;
            }
            if (f && i + 1 < s.size() && s[i + 1] == ' ') {
                cout << ' ';
                i++;
                bool flag = false;
                while (i + 1 < s.size() && s[i + 1] == ' ') {
                    flag = true;
                    i++;
                }
                if (flag) --i;
            }
            temp = "";
        }
        else temp.push_back(s[i]);
    }
    if (temp != "") cout << mp[temp] << "\n";
    else cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    cin >> test;
    cin.ignore();
    for (_ = 1; _ <= test; _++)
    {
        solve();
    }
    return 0;
}
