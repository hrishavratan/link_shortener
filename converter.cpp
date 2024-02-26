#include <bits/stdc++.h>
using namespace std;

string convIDtoURL(int n)
{

    char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    string url;

    while (n > 0)
    {
        url.push_back(alphanum[n % 62]);
        n /= 62;
    }

    reverse(url.begin(), url.end());

    return url;
}

int convURLtoID(string link)
{
    int unique_id = 0;

    for (int i = 0; i < link.length(); i++)
    {

        if ('A' <= link[i] && link[i] <= 'Z')
        {
            unique_id = unique_id * 62 + link[i] - 'A';
        }
        
        else if ('a' <= link[i] && link[i] <= 'z')
        {
            unique_id = unique_id * 62 + link[i] - 'a' + 26;
        }
        
        else
        {
            unique_id = unique_id * 62 + link[i] - '0' + 52;
        }
        unique_id%=1000000007;
    }

    return unique_id;
}

int main()
{

    string url;
    cout<<"enter your url here : ";
    cin >> url;
    cout << "ID from URL is " << convURLtoID(url) << endl;
    int n = convURLtoID(url);
    string url2 = convIDtoURL(n);
    cout << "Generated short url using ID is " << url2 << endl;

    return 0;
}