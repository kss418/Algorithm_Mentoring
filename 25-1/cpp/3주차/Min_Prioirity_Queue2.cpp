#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};
priority_queue <int, vector<int>, cmp> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    pq.push(1);
    cout << pq.top() << "\n"; // 1
    pq.push(3);
    cout << pq.top() << "\n"; // 1
    pq.push(2);

    pq.pop(); // 1 제거
    cout << pq.top(); // 2

    return 0;
}

