#include <iostream>

//求逆序数可以用分而治之的方法，即在归并排序的过程中计算每一个元素之前比它大的数字的个数
//在这个过程中首先通过递归将序列不停地细分，通过两两间计算逆序数，递归回调后对序列合并，计算合并后增加的逆序数
//通过不断累加每个元素的逆序数，最终求的整个序列的逆序数
//代码由c++编写，测试过程首先输入序列中元素的个数n，然后输入序列的各个元素即可计算逆序数

int  Count;

//归并排序合并部分
void Merge (int *a, int *b, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <=end) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            Count += j - k;
            b[k++] = a[j++];
        }

    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= end) {
        b[k++] = a[j++];
    }
    for (int i = start; i <= end; i++) {
        a[i] = b[i];
    }
}

//归并排序
void MergeSort (int *a, int *b, int start, int end) {
    if (start <end) {
        int  mid = (start + end) / 2;
        MergeSort(a, b, start, mid);    //前半部分排序
        MergeSort(a, b, mid + 1, end);    //后半部分排序
        Merge(a,b, start, mid, end);    //合并两部分内容
    }
}

int main() {
    int n, *a, *b;
    std::cin >> n;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    MergeSort(a, b, 0, n - 1);
    std::cout << Count << std::endl;
    delete a;
    delete b;
    return 0;

}