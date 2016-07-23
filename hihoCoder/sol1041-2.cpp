//
// Created by wuyan on 2016/7/17.
// Contact mail wyang@smail.nju.edu.cn
//
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAX_N = 101;
vector<int> graAdj[MAX_N];//�ڽӱ�
int go[MAX_N];
int graMat[MAX_N][MAX_N];//����

bitset<MAX_N> hasChild[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; i++)
    {
        graAdj[i].clear();
        hasChild[i].reset();
    }
    memset(graMat, 0, sizeof(graMat));
}

void getChild(int u = 1, int par = -1)
{
    hasChild[u][u] = 1;	//�Լ����Լ��ĺ��ӣ����Լ�Ҳ�������Ӽ����С�
    for (int i = 0; i < (int)graAdj[u].size(); i++)
    {
        int v = graAdj[u][i];
        if (v == par) continue;//��ֹ��·�������߸��׽ڵ�
        getChild(v, u);
        hasChild[u] |= hasChild[v];//��������bitset�����ж�һ���ڵ��ж��ٺ���
    }
}

//����ȫ�ֱ���graMat��graAdj
bool eliminateAll(int go[], int &id, int m, int u = 1, int par = -1)
{
    if (id < m && go[id] == u) id++;
    if (id == m) return true;

    while (id < m)//�ؼ��㣬����ѭ�������ӽڵ�
    {
        int nexta = go[id];
        int curIndex = id;
        for (int i = 0; i < (int)graAdj[u].size(); i++)
        {
            int v = graAdj[u][i];
            if (v == par) continue;//�ų����ڵ㣬��ֹ��·

            if (hasChild[v][nexta] && graMat[u][v])
            {
                graMat[u][v] = 0;//�ؼ��㣺���ţ������ظ�����·��
                if (eliminateAll(go, id, m, v, u)) return true;
            }
        }
        //�ؼ��㣺��ֹ����ѭ����û�д𰸵�ʱ���˳�
        if (id == curIndex) break;//û���ҵ�һ����Ӧ�ĵ�a[id]��������һ��
    }
    return false;
}

int main()
{
    int T, n, a, b, m;
    while (cin >> T) {
        while (T--)
        {
            cin >> n;
            init(n);
            for (int i = 1; i < n; i++)
            {
                cin >> a >> b;
                graAdj[a].push_back(b);
                graAdj[b].push_back(a);
                graMat[a][b] = graMat[b][a] = 1;
            }

            cin >> m;
            for (int i = 0; i < m; i++)
            {
               cin >> go[i];
            }
            getChild();
            int id = 0;
            if (eliminateAll(go, id, m)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}