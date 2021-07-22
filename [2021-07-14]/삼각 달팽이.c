#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)calloc(n * (n + 1) / 2, sizeof(int));
    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * (i + 1));
    }
    int w = 0, h = 0, num = 0;
    int max = n;
    int inner = 1;
    for (int i = 0; i < max; i++) {
        arr[w][h] = inner;
        inner++;
        w++;
    }
    max--;
    while (1) {
        if (max == 0)
            break;
        for (int i = 0; i < max; i++) {
            h++;
            arr[w][h] = inner;
            inner++;
        }
        max--;
        if (max == 0)
            break;
        for (int i = 0; i < max; i++) {
            w--;
            h--;
            arr[w][h] = inner;
            inner++;
        }
        max--;
        if (max == 0)
            break;
        for (int i = 0; i < max; i++) {
            w++;
            arr[w][h] = inner - 1;
            inner++;
        }
        max--;
    }
    int k = 0, s = 1;
    while (s < n + 1) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                answer[k] = arr[i][j];
                k++;
            }
        }
        s++;
    }
    return answer;
}

// 4 �Է½� ũ�Ⱑ 4�� �ﰢ���� �� �� ���������� �ݽð� �������� ������ ä��⸦ ������ ��,
// ù ����� ������ ����� ��� ������� ��ģ ���ο� �迭�� return
// 4 = [1,2,9,3,10,8,4,5,6,7]
// 2���� �迭�� �����Ҵ��Ͽ� �����ﰢ�� ����� �����, for������ ù ���� ä���,
// while�� ������ �� �� ��, �� �� �밢���� ä��� ������ ���α׷��� ��.
// while�� ������ if������ max���� 0�� �Ǹ� break�Ͽ� while���� ������������ ����