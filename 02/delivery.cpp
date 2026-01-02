#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<pair<int, int>> &a, int l, int r) {
    if (l >= r)
        return;

    int pivot = a[(l + r) / 2].first;
    int i = l, j = r;

    while (i <= j) {
        while (a[i].first < pivot) {
            i++;
        }
        while (a[j].first > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, l, j);
    quickSort(a, i, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // sort house pos
    quickSort(v, 0, n - 1);

    int minLimit = 2 * v[0].first + v[0].second;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        int a = v[i].first;
        int t = v[i].second;

        if (2 * a < minLimit) {
            ans++;
            int limit = 2 * a + t;
            if (limit < minLimit)
                minLimit = limit;
        }
        else
            break;
    }

    cout << ans << "\n";
    return 0;
}
