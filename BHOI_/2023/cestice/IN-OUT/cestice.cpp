#include <iostream>
#include <string>
#include <deque>
#include <map>

bool otv(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool par(char a, char b)
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::string s;
    std::cin >> n >> m >> s;

    std::deque<int> q;
    std::map<int, bool> ch;
    int izm = 0;

    for(int i = 0; i < n; i++)
    {
        if(otv(s[i])) 
            q.push_back(i);
        else 
        {
            if(q.empty()) 
            {
                std::cout << "nemoguce" << std::endl;
                return 0;
            }

            int j = q.back();
            q.pop_back();

            if(!par(s[j], s[i])) 
            {
                bool flag = false;

                if(!ch[j]) 
                {
                    for(char a : {'(', '{', '['})
                    {
                        if(par(a, s[i])) 
                        {
                            s[j] = a;
                            ch[j] = true;
                            izm++;
                            flag = true;
                            break;
                        }
                    }
                }

                if(!flag && !ch[i]) 
                {
                    for(char b : {')', '}', ']'})
                    {
                        if(par(s[j], b)) 
                        {
                            s[i] = b;
                            ch[i] = true;
                            izm++;
                            flag = true;
                            break;
                        }
                    }
                }

                if(!flag) 
                {
                    std::cout << "nemoguce" << std::endl;
                    return 0;
                }
            }
        }
    }

    if(!q.empty() || izm != m) 
    {
        std::cout << "nemoguce" << std::endl;
        return 0;
    }

    std::cout << s << std::endl;
    return 0;
}
