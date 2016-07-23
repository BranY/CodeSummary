//
// Created by wuyan on 2016/7/16.
// Contact mail wyang@smail.nju.edu.cn
//
#include<iostream>
#include <winbase.h>

using namespace std;
const int MAX = 1000;
struct Node {
    int val;
    int addMark;
}segTree[MAX];
void build(int root, int arr[], int start, int end) {
    if (start == end)
        segTree[root].val = arr[start];
    else {
        int m = start + (end - start) / 2;
        build(root * 2 + 1, arr, start, m);
        build(root * 2 + 2, arr, m + 1, end);
        segTree[root].val = min(segTree[root * 2 + 1].val, segTree[root * 2 + 2].val);
    }
}
void pushDown(int root) {
    if (segTree[root].addMark != 0) {
        //�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���, ������ ��+=��
        segTree[root * 2 + 1].addMark += segTree[root].addMark;
        segTree[root * 2 + 2].addMark += segTree[root].addMark;
        segTree[root].addMark = 0;
    }
}
int query(int root, int start, int end, int qStart, int qEnd) {
    if (qStart > end || qEnd < start) return INFINITE;
    if(qStart <= start && qEnd >= end)
        return segTree[root].val;
    int m = start + (end - start) / 2;
    pushDown(root);
    return min(query(root * 2 +1, start, m, qStart, qEnd),
         query(root * 2 + 2, m + 1, end, qStart, qEnd));
}
/**
 * start-end :��ǰ����ʾ������
 * index: �����½ڵ���ԭʼ�����е��±�
 */
void updateOne(int root, int start, int end, int index, int val) {
    if (start == end) {
        if (index == start)
            segTree[root].val += val;
        return;
    }
    int m = start + (end - start) / 2;
    if (index <= m) updateOne(root * 2 + 1, start, m, index, val);
    else updateOne(root * 2 + 2, m + 1, end, index, val);
    segTree[root].val = min(segTree[root * 2 + 1].val, segTree[root * 2 + 2].val);
}
void update(int root, int start, int end, int uStart, int uEnd, int val) {
    if (uStart > end || uEnd < start)
        return;
    if (uStart <= start && uEnd >= end) {
        segTree[root].addMark += val;
        segTree[root].val += val;
        return ;
    }
    pushDown(root);
    int m = start + (end - start) / 2;
    update(root * 2 + 1, start, m, uStart, uEnd, val);
    update(root * 2 + 2, m + 1, end, uStart, uEnd, val);
    segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}
int main()
{
    return 0;
}
