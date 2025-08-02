#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


void level_order_print(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    if(root)
        q.push(root);

    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();

        cout << p->val << " ";

        if(p->left)
            q.push(p->left);

        if(p->right)
            q.push(p->right);
    }
}


Node* convert_to_bst(int a[], int n, int l, int r)
{
    if(l > r)
        return NULL;

    int mid = (l+r)/2;
    Node* root = new Node(a[mid]);

    Node* leftroot = convert_to_bst(a, n, l, mid-1);
    Node* rightroot = convert_to_bst(a, n, mid+1, r);

    root->left = leftroot;
    root->right = rightroot;

    return root;

}


int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    Node* root = convert_to_bst(a, n, 0, n-1);

    level_order_print(root);
    

    return 0;
}