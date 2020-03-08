/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1)
            return 1.0;
        if(target == 1)
            return 0;
        bool visited[n+1] =  {false};
        queue<pair<int,double>> q;
        int size, count;
        pair<int,double> tp;
        double prob = 1;
        bool found = false, noway = true;
        q.push({1,1.0});
        visited[1] = true;
        while(!q.empty())
        {
            size = q.size();
            t--;
            while(size--)
            {
                tp = q.front();
                q.pop();
                count = 0;
                for(auto& e : edges)
                {
                    if((e[0] == tp.first && !visited[e[1]]) || (e[1]==tp.first &&  !visited[e[0]]) )
                    {
                        if(e[1] == target || e[0] == target)
                            found = true;
                        count++;
                    }
                }
                for(auto& e : edges)
                {
                    if((e[0] == tp.first && !visited[e[1]]) || (e[1]==tp.first &&  !visited[e[0]]) )
                    {
                        if(!visited[e[1]])
                        {
                            q.push({e[1], tp.second/count});
                            visited[e[1]] = true;
                        }
                        else{
                            q.push({e[0], tp.second/count});
                            visited[e[0]] = true;
                        };

                        if(e[1] == target || e[0] == target)
                            prob = tp.second/count;
                    }
                }
                noway = true;
                if(found)
                {
                    for(auto& e : edges)
                    {
                        if(((e[0] == target && !visited[e[1]]))||(e[1]==target && !visited[e[0]]))
                        {
                            noway = false;
                            break;
                        }
                    }
                }
            }
            if(found)
            {
                if(t>=0)
                    return prob;
                else//还有路走
                {
                    return 0;
                }
            }
        }
        return prob;
    }
};



int main() {
    Solution s;

    vector<int> v = {1,6};
    vector<int> v1 = {5,6};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,1},{3,2}};//{4,2},{5,2},{6,5},{7,1},{8,3},{9,1},{10,1}};
    s.frogPosition(2,v2,1,2);
    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    return 0;
}