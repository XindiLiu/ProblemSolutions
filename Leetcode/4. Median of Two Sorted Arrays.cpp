class Solution {
public:
    int findkth(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() + nums2.size();
        int l = 0;
        int n1 = nums1.size();
        int r = min(n1, k);
        if (nums2.size() + 1 < k) {
            l = k - nums2.size() - 1;
        }
        int mid = (l + r) / 2;
        while (l != r) {
            if ((mid == k - 1 || nums1[mid] >= nums2[k - mid - 2]) && (mid + nums2.size() + 1 == k || nums1[mid] <= nums2[k - mid - 1])) {
                return nums1[mid];
            }
            else if (mid == k - 1 || nums1[mid] >= nums2[k - mid - 2]) { // move left
                r = mid;
                mid = (l + r) / 2;
            }
            else if (mid + nums2.size() + 1 == k || nums1[mid] <= nums2[k - mid - 1]) { // move right
                l = mid + 1;
                mid = (l + r) / 2;
            }
        }
        return findkth(nums2, nums1, k);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2) {

            return findkth(nums1, nums2, ceil(n / 2.0));
        }
        else {
            volatile double a = findkth(nums1, nums2, n / 2);
            volatile double b = findkth(nums1, nums2, n / 2 + 1);
            return (a + b) / 2.0;
        }
    }
};