#include <bits/stdc++.h>
using namespace std;

int countFromLeft(int index, vector<int>& a){
    int count = 0, key = a[index];
    for(int i = index - 1; i >= 0; --i){
        if(a[i] >= key) ++count;
        else break;
    }
    return count;
}

int countFromRight(int index, vector<int>& a){
    int count = 0, key = a[index], size_ = a.size();
    for(int i = index + 1; i < size_; ++i){
        if(a[i] >= key) ++count;
        else break;
    }
    return count;
}

int valueAt(int index, vector<int>& a){
    if(a[index] == 0) return 0;
    return a[index]*(1 + countFromLeft(index, a) + countFromRight(index, a));
}

int maxValueAt(vector<int>& a){
    int result = 0, size_ = a.size(), tmp;
    for(int i = 0; i < size_; ++i){
        tmp = valueAt(i, a);
        if(result < tmp) result = tmp;
    }
    return result;
}

int main()
{
    int n, m, result = 0, tmp;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), height(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int curVal = 0;
            int curRow = i;
            while (curRow < n && a[curRow][j] != 0)
            {
               curVal += a[curRow][j];
               ++curRow;
            }
            height[i][j] = curVal;
        }
    }
    
    for(int i = 0; i < n; ++i){
       tmp = maxValueAt(height[i]);
       if(result < tmp) result = tmp;
    }
    cout << result;
}
