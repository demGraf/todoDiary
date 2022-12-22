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
// 노드(num [left, right] 에 대하여 구간 [x,y] 까지의 합을 계산하여 반환한다. )
// x,y -> 구하고자 하는 범위, left, right -> 현재 노드의 범위
long long seg_sum(int num, int left, int right, int x, int y) {
	// 노드의 값이 완전히 포함되는 경우
	if (x <= left && right <= y) return seg[num];
	// 노드의 값이 전혀 포함되지 않는 경우
	else if (y < left || right < x) return 0;

	// 일부 곂치는 경우
	int mid = (left + right) / 2;
	long long left_seg = seg_sum(num * 2, left, mid, x, y);
	long long right_seg = seg_sum(num * 2 + 1, mid + 1, right, x, y);
	return left_seg + right_seg;
}
// 노드 ( num, [left, right] 에 대하여 [idx, idx] 의 값을 v 로 변경한다 )
long long seg_update(int num, int left, int right, int idx, int v) {
	// 수정해야하는 노드에 도착했을 때
	if (idx == left && idx == right) {
		seg[num] = v;
		return seg[num];
	}
	// 노드의 값이 전혀 포함되지 않는 경우
	else if (idx < left || right < idx) return seg[num];

	// 일부 곂치는 경우
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