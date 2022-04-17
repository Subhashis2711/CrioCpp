#include "../crio/cpp/io/FastIO.hpp"
#include <bits/stdc++.h>
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"

using namespace std;


vector<int> mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = 0, p2 = 0;
    vector<int> res;

    while((p1 < m) && (p2 < n)){
        if(nums1[p1] <= nums2[p2]){
            res.push_back(nums1[p1++]);
        }else{
            res.push_back(nums2[p2++]);
        }
    }

    while(p1 < m){
        res.push_back(nums1[p1++]);
    }

    while(p2 < n){
        res.push_back(nums2[p2++]);
    }

    return res;
}

int main() {
    FastIO();
    int m, n;
    cin >> m >> n;
    vector<int> nums1, nums2;
    ReadMatrix<int>().OneDMatrix(m, nums1);
    ReadMatrix<int>().OneDMatrix(n, nums2);
    vector<int> result = mergeSortedArray(nums1, m, nums2, n);
    PrintMatrix<int>().OneDMatrix(result, " ");
    return 0;
}
