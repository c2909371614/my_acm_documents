// ���⣺LCIS��O(N^3)
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (a[i] == b[j]) {
            for (int k = 0; k < j; k++)
                if (b[k] < a[i])
                    f[i][j] = max(f[i][j], f[i - 1][k] + 1);
        }
        else f[i][j] = f[i - 1][j];


// ���⣺LCIS��O(N^2)
for (int i = 1; i <= n; i++) {
    // val�Ǿ��߼���S(i,j)��f[i-1][k]�����ֵ
    int val = 0;
    // j=1ʱ��0������Ϊk��ȡֵ
    if (b[0] < a[i]) val = f[i - 1][0];
    for (int j = 1; j <= m; j++) {
        if (a[i] == b[j]) f[i][j] = val + 1;
        else f[i][j] = f[i - 1][j];
        // j��������Ϊj+1�����j�ܷ�����µľ��߼���
        if (b[j] < a[i]) val = max(val, f[i - 1][j]);
    }
}
