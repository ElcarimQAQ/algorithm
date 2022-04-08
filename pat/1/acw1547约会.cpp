#include <bits/stdc++.h>
using namespace std;

string Week[7] = { "Mon", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

bool checkWeek(char c)
{
    if (c >= 'A' && c <= 'G')
        return true;
    return false;
}

int checkHour(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'N')
        return 10 + c - 'A';
    return -1;
}

int main()
{
    int week = -1;
    int hour, mi;
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    int l = min(str1.size(), str2.size());
    for (int i = 0; i < l; i++) {
        if (str1[i] == str2[i] && checkWeek(str1[i]) && week == -1) {
            week = str1[i] - 'A';
            continue;
        }
        if (str1[i] == str2[i] && checkHour(str1[i]) != -1 && week != -1) {
            hour = checkHour(str1[i]);
            // cout<<str1[i]<< hour <<endl;
            break;
        }
    }

    l = min(str3.size(), str4.size());
    for (int i = 0; i < l; i++) {
        if (str3[i] == str4[i] && 'a' <= tolower(str3[i]) && tolower(str3[i]) <= 'z') {
            mi = i;
            break;
        }
    }
    cout << Week[week] << " ";
    printf("%02d:%02d", hour, mi);
    return 0;
}