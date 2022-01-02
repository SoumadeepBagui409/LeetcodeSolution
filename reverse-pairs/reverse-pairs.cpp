class Solution {
public:
	// void merge(vecto)
	vector<int> t;
	int ans = 0;
	void merge(vector<int> &nums, int start, int mid, int end) {
		t.resize(end - start + 1);
		int i = start, j = mid + 1;
		int k = 0;
		while (i <= mid && j <= end) {
			if (nums[i] < nums[j]) t[k++] = nums[i++];
			else t[k++] = nums[j++];
		}

		while ( i <= mid) t[k++] = nums[i++];
		while (j <= end) t[k++] = nums[j++];




		for (int i = start; i <= end; i++) nums[i] = t[i - start];
	}
	void mergeSort(vector<int> &nums, int start, int end) {
		if (start >= end) return;

		int mid = start + (end - start) / 2;
        
        mergeSort(nums, start, mid);
		mergeSort(nums, mid + 1, end);

		int j = mid + 1;
		for (int i = start; i <= mid; i++) {
			while (j <= end && (long)nums[i] > (long)2  * nums[j]) j++;
			ans += (j - mid - 1);
		}

		

		merge(nums, start, mid, end);

	}
	int reversePairs(vector<int>& nums) {
		ans = 0;
		mergeSort(nums, 0, nums.size() - 1);
        
        // for(int x : nums)cout << x << " ";
		return ans;
	}
};