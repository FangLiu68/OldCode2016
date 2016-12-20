#include "Header.h"


// remove elements
int test_removeElements(vector<int> input, int val){
    if(input.empty()){
        return -1;
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left <= right){
        if(input[left] == val){
            left++;
        }else if(input[right] != val){
            right--;
        }else{
            swap(input[left++], input[right--]);
        }
    }
    
    return left;
}

int main(){
    vector<int> input = {2, 3, 4, 2, 1, 2, 5};
    // 3, 4, 1, 5, 2, 2, 2,
    int val = 2;
    int res = test_removeElements(input, val);
    cout << res << endl;
    return 0;
}