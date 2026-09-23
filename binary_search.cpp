#include <iostream>

using namespace std;



int binary_search(int arr[], int target, int low, int high){
  int mid;

  // first = low;
  // last = high;
  mid = (high + low) / 2;

  while (low <= high && arr[mid] != target)
  {
    if(arr[mid] < target){
      low = mid+1;
    }else{
      high = mid - 1;
    }
    mid = (high + low) / 2;
  }

  if(arr[mid] == target)
    return mid;

  return -1;
}

int main()
{
  int arrv[] = {2, 4, 5, 7, 8, 10, 34};
  int target = 8;

  int position = binary_search(arrv, target, 0, 6);
  if (position < 0)
  {
    cout << "Element " << target << " not found" << endl;
    return -1;
  }
  cout << target << " found at index " << position << endl;

  return 0;
}