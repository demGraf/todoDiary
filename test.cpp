#include <iostream>
#include <stack>
long long seg[4000001];
long long seg_init(int num, int left, int right) {
	if (left == right) {
		std::cin >> seg[num];
		return seg[num];
	}

	// left != right
	int mid = (left + right) / 2;
	long long left_seg = seg_init(num * 2, left, mid);
	long long right_seg = seg_init(num * 2 + 1, mid + 1, right);

	seg[num] = left_seg + right_seg;
	return seg[num];
}
// ���(num [left, right] �� ���Ͽ� ���� [x,y] ������ ���� ����Ͽ� ��ȯ�Ѵ�. )
// x,y -> ���ϰ��� �ϴ� ����, left, right -> ���� ����� ����
long long seg_sum(int num, int left, int right, int x, int y) {
	// ����� ���� ������ ���ԵǴ� ���
	if (x <= left && right <= y) return seg[num];
	// ����� ���� ���� ���Ե��� �ʴ� ���
	else if (y < left || right < x) return 0;

	// �Ϻ� ��ġ�� ���
	int mid = (left + right) / 2;
	long long left_seg = seg_sum(num * 2, left, mid, x, y);
	long long right_seg = seg_sum(num * 2 + 1, mid + 1, right, x, y);
	return left_seg + right_seg;
}
// ��� ( num, [left, right] �� ���Ͽ� [idx, idx] �� ���� v �� �����Ѵ� )
long long seg_update(int num, int left, int right, int idx, int v) {
	// �����ؾ��ϴ� ��忡 �������� ��
	if (idx == left && idx == right) {
		seg[num] = v;
		return seg[num];
	}
	// ����� ���� ���� ���Ե��� �ʴ� ���
	else if (idx < left || right < idx) return seg[num];

	// �Ϻ� ��ġ�� ���
	int mid = (left + right) / 2;
	long long left_seg = seg_update(num * 2, left, mid, idx, v);
	long long right_seg = seg_update(num * 2 + 1, mid + 1, right, idx, v);
	seg[num] = left_seg + right_seg;
	return seg[num];
}

int main() {
	int cnt = 0;
	int n, m, k;
	int a, b, c;
	scanf("%d %d %d", &n, &m, &k);
	seg_init(1, 1, n);


	return 0;
}
/*
#include <iostream>
#include <utility>
#include <stack>
#include <string>
using namespace std;
long long arr[4000000];
long long arrc[4000000];
int l, r;
long long seg_init(int num, int left, int right) {
	if (left == right) std::cin >> arr[num];
	else {
		int mid = (left + right) / 2;
		arr[num] = seg_init(num * 2, left, mid) + seg_init(num * 2 + 1, mid + 1, right);
	}
	return arr[num];
}
void seg_init_stack(int num, int left, int right) {
	int n, l, r;
	std::stack<pair<int, pair<int, int>>> s;
	s.push({ num, { left, right } });
	while (!s.empty()) {
		n = s.top().first;
		l = s.top().second.first;
		r = s.top().second.second;
		s.pop();

		int mid = (l + r) / 2;
		if (l == mid) std::cin >> arrc[n * 2];
		else s.push({ num * 2,{l,mid} });
		if (mid == r)std::cin >> arrc[n * 2 + 1];
		else s.push({ num * 2 + 1,{mid,r} });

	}
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	seg_init(1, 1, n);
	int bin = 1;
	for (int i = 1, t=1; i <= n * 3; i++,t++) {
		std::cout << arr[i] << ' ';
		if (t == bin) {
			std::cout << std::endl;
			bin *= 2;
			t = 0;
		}
	}
	return 0;
}
*/