#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n, target;
int num[N];

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i ++) cin >> num[i];
    sort(num, num + n, cmp);
	for (int i = 0; i < n; i ++) cout << num[i] << " ";
	cout << endl;

    int index = binarySearch(num, n, target);

	if (index == -1) puts("-1");
	else cout << index << endl;

    return 0;
}