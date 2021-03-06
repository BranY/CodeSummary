//
// Created by wuyan on 2016/7/17.
// Contact mail wyang@smail.nju.edu.cn
// http://www.blogs8.cn/posts/W4UAfIL
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
int N, M;
int need[502], value[502];
int dp[502][100002];
int dp1[100005];

void dfs1() {
    int i, j, k;
    for (i = 1; i <= N; i++)
        for (j = 0; j <= M; j++) {
            if (j < need[i])
                dp[i][j] = dp[i-1][j];
            int best = INT_MIN;
            for (k = 0; k <= j/need[i]; k++) {
                int tmp = max (dp[i][j], dp[i-1][j - need[i] * k] + value[i] * k);
                if (best < tmp)
                    best = tmp;
            }
            dp[i][j] = best;
        }
}
/**
 * dp(i, x)��ʾ�Ѿ�������ǰi����Ʒ�Ƿ�ѡȡ����ǰ�Ѿ�ѡȡ����Ʒ�����轱ȯ���ܺͲ�����xʱ���ܹ���ȡ����ߵ�ϲ��ֵ�ĺ�
 * dp[i][j] = max{ (dp[i-1][j - need[i] * k]) + value[i] * k } k ->[0, x/need[i]]
 * dp[i][x-need[i]] = max {(dp[i-1][j - need[i] * k]) + value[i] * k } k ->[1, x/need[i]]
 *
 * dp[i][j] = max{dp[i][j-need[i]] + value[i], dp[i-1][j]}
 * dp[i][j]��ʾǰi����Ʒѡ���ټ���������j,�ܻ�õ����ϲ��ֵ
 */
void dfs2() {
    int i, j;
    for (j = 0; j <= M; ++j) dp[0][j] = 0;
    for (i = 0; i <= N; ++i) dp[i][0] = 0;

    for (i = 1; i <= N; i++) {
        for (j = 0; j <= M; j++) {
            if (j >= need[i])
                dp[i][j] = max(dp[i-1][j], dp[i][j - need[i]] + value[i]);
            else
                dp[i][j] =dp[i-1][j];
        }
    }
}
/**
 * 0-1:
 * dp[i][j] = 0                                                     if i =0 or j = 0
 *            dp[i-1][j]                                            if j < need[i]
 *            max{dp[i-1][j], dp[i-1][j-need[i]] + value[i] }       if i > 0 && j >= need[i]
 *
 * optimize
 * i ->[1, N] j -> [M, need[i]]
 * dp1[j] = max { dp1[j], dp1[j - need[i]] + value }
 * 1 : ��Ҫ�� 2��Ҫһ�� 3��Ҫ���
 * dp(i, x)��ʾ�Ѿ�������ǰi����Ʒ�Ƿ�ѡȡ����ǰ�Ѿ�ѡȡ����Ʒ�����轱ȯ���ܺͲ�����xʱ���ܹ���ȡ����ߵ�ϲ��ֵ�ĺ�
 * dp[i][j] = max{ (dp[i-1][j - need[i] * k]) + value[i] * k } k ->[0, x/need[i]]
 * dp[i][x-need[i]] = max {(dp[i-1][j - need[i] * k]) + value[i] * k } k ->[1, x/need[i]]
 *
 * dp[i][j] = max{dp[i][j-need[i]] + value[i], dp[i-1][j]}
 * dp[i][j]��ʾǰi����Ʒѡ���ټ���������j,�ܻ�õ����ϲ��ֵ
 * dp[i][j] = 0                                                     if i =0 or j = 0
 *            dp[i-1][j]                                             if j < need[i]
 *            max{dp[i-1][j], dp[i][j-need[i]] + value[i] }          if i > 0 && j >= need[i]
 * optimize
 * i ->[1, N] j -> [need[i], M]
 * dp1[j] = max (dp1[j], dp1[j - need[i]] + value)
 */
void dfs3() {
    memset(dp1, 0, sizeof(dp1));
    for (int i = 1; i <= N; i++)
        for (int j = need[i]; j < M; j++)
            dp1[j] = max(dp1[j], dp1[j - need[i]] + value[i]);
}
int main() {
    while (cin >> N >> M) {
        int i, j;
        for (i = 1; i <= N; i++)
            cin >> need[i] >> value[i];
        /*dfs2();
        cout << dp[N][M] << endl;*/
        dfs3();
        cout << dp1[M - 1] << endl;
    }
    return 0;
}

