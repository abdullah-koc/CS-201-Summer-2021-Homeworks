#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;


int maxSubSum1(const int *arr, const int size);
int maxSubSum2(const int *arr, const int size);
int maxSubSum3(const int *arr, const int size);
int maxSumRec(const int *arr, int left, int right);
int maxSubSum4(const int *arr, const int size);
void createRandomArrays(int *&arr, const int size);


/**
 * Algorithm 1 - Cubic maximum contiguous subsequence sum algorithm
 */

int maxSubSum1(const int *arr, const int size) {
    int maxSum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int thisSum = 0;
            for (int k = i; k <= j; k++) {
                thisSum += arr[k];
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

/**
 * Algorithm 2 - Quadratic maximum contiguous subsequence sum algorithm
 */
int maxSubSum2(const int *arr, const int size) {
    int maxSum = 0;

    for (int i = 0; i < size; i++) {
        int thisSum = 0;
        for (int j = i; j < size; j++) {
            thisSum += arr[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

/**
 * Recursive maximum contiguous subsequence sum algorithm
 * Finds maximum sum in subarray
 * Does not attempt to maintain actual best sequence
 */

int maxSumRec(const int *arr, int left, int right) {
    if (left == right) {
        if (arr[left] > 0) {
            return arr[left];
        } else {
            return 0;
        }
    }
    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(arr, left, center);
    int maxRightSum = maxSumRec(arr, center + 1, right);

    int maxLeftBorderSum = 0;
    int leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += arr[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    int maxRightBorderSum = 0;
    int rightBorderSum = 0;
    for (int i = center + 1; i <= right; i++) {
        rightBorderSum += arr[i];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }
    return max(max(maxLeftSum, (maxLeftBorderSum + maxRightBorderSum)), maxRightSum);
}

/**
 * Driver function for recursive algorithm
 */
int maxSubSum3(const int *arr, int size) {
    return maxSumRec(arr, 0, size - 1);
}

/**
 * Linear-time maximum contiguous subsequence sum algorithm
 */
int maxSubSum4(const int *arr, const int size) {
    int maxSum = 0;
    int thisSum = 0;

    for (int i = 0; i < size; i++) {
        thisSum += arr[i];

        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

void createRandomArrays(int *&arr, const int size) {
    if (size <= 0) {
        arr = NULL;
        return;
    }
    arr = new int[size];
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        int randompositive = rand() % 14;
        int randomnegative = -rand() % 14;
        arr[i] = randompositive;
        if(i%3==0){
            arr[i] = randomnegative;
        }
    }
}

int main() {

    //Creating random array with given size
    int* arr;
    int size = 300000;
    createRandomArrays(arr,size);

    chrono::time_point< chrono::system_clock > startTime;
    chrono::duration< double, milli > elapsedTime;


    // Store the starting time
    startTime = chrono::system_clock::now();
    // Code block


    //for(int i = 0; i < 100000; i++){
        maxSubSum3(arr,size);
    //}

    // Compute the number of milliseconds that passed since the starting time
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;


    return 0;
}
