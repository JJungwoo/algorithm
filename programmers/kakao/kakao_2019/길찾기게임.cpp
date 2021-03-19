/*
[programmers] 2019 KAKAO BLIND RECRUITMENT 길 찾기 게임
https://programmers.co.kr/learn/courses/30/lessons/42892
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _Node{
    int x, y, idx;
    struct _Node *left;
    struct _Node *right;
}node;
vector<node> tarr;
vector<int> list;
bool cmp(node a, node b) {
    if (a.y == b.y) return a.x < b.x;
    else return a.y > b.y;
}
void make_tree(node *root, node *child) {
    if (root->x > child->x) {
        if (root->left == NULL) {
            root->left = child;
        }
        else make_tree(root->left, child);
    } else {
        if (root->right == NULL) {
            root->right = child;
        }
        else make_tree(root->right, child);
    }
}
void preorder(node *root) {
    list.push_back(root->idx);
    if(root->left != NULL)
        preorder(root->left);
    if(root->right != NULL)
        preorder(root->right);
}
void postorder(node *root) {
    if(root->left != NULL)
        postorder(root->left);
    if(root->right != NULL)
        postorder(root->right);
    list.push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i=0;i<nodeinfo.size();i++)
        tarr.push_back({nodeinfo[i][0], nodeinfo[i][1], i+1, NULL, NULL});
    sort(begin(tarr), end(tarr), cmp);
    node *root = &tarr[0];
    for(int i=1;i<tarr.size();i++) {
        make_tree(root, &tarr[i]);
    }
    preorder(root);
    answer.push_back(list);
    list.clear();
    postorder(root);
    answer.push_back(list);

    return answer;
}
