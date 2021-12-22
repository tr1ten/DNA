class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int temparr[m + n];
        int p1, p2;
        p1 = p2 = 0;
        while (p1 < m && p2 < n)
        {
            if (nums1[p1] < nums2[p2])
            {
                temparr[p1 + p2] = nums1[p1];
                p1++;
            }
            else
            {
                temparr[p1 + p2] = nums2[p2];
                p2++;
            }
        }
        while (p1 < m)
        {
            temparr[p1 + p2] = nums1[p1];
            p1++;
        }
        while (p2 < n)
        {
            temparr[p1 + p2] = nums2[p2];
            p2++;
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = temparr[i];
        }
    }
};