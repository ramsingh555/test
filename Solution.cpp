#include <bits/stdc++.h>

                cout << "Case #" << test << ": " << "POSSIBLE"<< '\n';
                return;
            }
        }
        bool a = true;
        for(int i = 0;i < n / 2;i++)
        {
            if(str[i] != str[n - i - 1])
            {
                a = false;
                break;
            }
        }
        if(a)cout << "Case #" << test << ": " << "IMPOSSIBLE"<< '\n';
        else cout << "Case #" << test << ": " << "POSSIBLE"<< '\n';
        return;
    }
    rec(str,0,"",str5);
     if(str5[5].size() == 0)
        {
            cout << "Case #" << test << ": " << "IMPOSSIBLE" << '\n';
            return;
        }
    for(int i = 6; i < n;i++)
    {
        for(int k = 0;k < str5[i - 1].size();k++)
        {
            if(str[i] != '?')
            {
                string g = str5[i - 1][k] + str[i]; 
                if(check(g))
                {
                    str5[i].pb(g.substr(1));
                }
                
            }
            else{
                string e = str5[i - 1][k] + '0';
                string g = str5[i - 1][k] + '1';
                if(check(e))
                {
                    str5[i].pb(e.substr(1));
                }
                if(check(g))
                {
                    str5[i].pb(g.substr(1));
                    
                }
            }
        }
        if(str5[i].size() == 0)
        {
            cout << "Case #" << test << ": " << "IMPOSSIBLE" << '\n';
            return;
        }
       
    }
     cout << "Case #" << test << ": " << "POSSIBLE" << '\n';
    
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve(i + 1);
    }
}
