#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e17;

struct SegmentTreeNode{
    ll minPrice, maxPrice, maxProfit;
    SegmentTreeNode(ll minPrice = INF, ll maxPrice = -INF, ll maxProfit = -1)
            : minPrice(minPrice), maxPrice(maxPrice), maxProfit(maxProfit){}
    static SegmentTreeNode merge(const SegmentTreeNode& left, const SegmentTreeNode& right){
        ll minPrice = min(left.minPrice, right.minPrice);
        ll maxPrice = max(left.maxPrice, right.maxPrice);
        ll crossProfit = right.maxPrice - left.minPrice;
        ll maxProfit = max({crossProfit, left.maxProfit, right.maxProfit});
        return SegmentTreeNode(minPrice, maxPrice, maxProfit);
    }
};

class SegmentTree{
    vector<SegmentTreeNode> tree;
    ll n;

    void build(const vector<ll>& prices, ll node, ll start, ll end){
        if(start == end){
            tree[node] = SegmentTreeNode(prices[start], prices[start], 0);
        }else{
            ll mid = (start + end) / 2;
            build(prices, 2 * node + 1, start, mid);
            build(prices, 2 * node + 2, mid + 1, end);
            tree[node] = SegmentTreeNode::merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    SegmentTreeNode query(ll node, ll start, ll end, ll l, ll r){
        if(r < start || l > end) return SegmentTreeNode(); // Return default node for invalid range
        if(l <= start && end <= r) return tree[node];      // Fully within range
        ll mid = (start + end) / 2;
        auto leftResult = query(2 * node + 1, start, mid, l, r);
        auto rightResult = query(2 * node + 2, mid + 1, end, l, r);
        return SegmentTreeNode::merge(leftResult, rightResult);
    }

public:
    SegmentTree(const vector<ll>& prices){
        n = prices.size();
        tree.assign(4 * n, SegmentTreeNode());
        build(prices, 0, 0, n - 1);
    }

    SegmentTreeNode query(ll l, ll r){
        if(l > r) return SegmentTreeNode(); // Handle invalid ranges
        return query(0, 0, n - 1, l, r);
    }
};

ll getPrice(ll v, ll d, ll day){
    ll k = day % 7;
    if(k <= 3){
        return v + k * d;
    }else{
        return v + (6 - k) * d;
    }
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> prices(n, vector<ll>(7));
    for(ll i = 0; i < n; i++){
        ll v, d;
        cin >> v >> d;
        for(ll day = 0; day < 7; day++){
            prices[i][day] = getPrice(v, d, day);
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll s, t;
        cin >> s >> t;
        s--;
        t--;
        if(s < t){
            // Eastward traversal
            vector<ll> dailyPrices;
            for(ll i = s; i <= t; i++){
                dailyPrices.push_back(prices[i][i - s]);
            }
            SegmentTree segTree(dailyPrices);
            auto result = segTree.query(0, dailyPrices.size() - 1);
            cout << result.maxProfit << endl;
        }else{
            // Westward traversal
            vector<ll> dailyPrices;
            for(ll i = s; i >= t; i--){
                dailyPrices.push_back(prices[i][s - i]);
            }
            SegmentTree segTree(dailyPrices);
            auto result = segTree.query(0, dailyPrices.size() - 1);
            cout << result.maxProfit << endl;
        }
    }
}
