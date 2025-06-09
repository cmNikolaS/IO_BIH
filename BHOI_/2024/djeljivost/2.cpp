#include <iostream>
#include <string>
#include <string_view>

unsigned long long toDec(std::string_view X, int B)
{
    unsigned long long dec = 0;
    int in = 1;
    for(int i = X.size() - 1; i >= 0; i--)
    {
        char c = X.at(i);
        int n = 0;
        if(isdigit(c))
            n = int(c) - 48;
        else
        {
            if(c == 'A')
                n = 10;
            else if(c == 'B')
                n = 11;
            else if(c == 'C')
                n = 12;
            else if(c == 'D')
                n = 13;
            else if(c == 'E')
                n = 14;
            else if(c == 'F')
                n = 15;
        }
        dec += n * in;
        in *= B;
    }
    return dec;
}

int main()
{
    int N, B;
    std::string X;
    std::cin >> N;
    while(N--)
    {
        std::cin >> B >> X;
        unsigned long long decForm = toDec(X, B);
        if(decForm % (B-1) == 0)
            std::cout << "DA" << std::endl;
        else 
            std::cout << "NE" << std::endl;
    }
    return 0;
}